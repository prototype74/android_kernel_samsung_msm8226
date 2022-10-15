/* Copyright (c) 2009-2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include <linux/module.h>
#include <linux/err.h>
#include <linux/device.h>

#include "mdnie_lite_tuning_s3ve.h"
#include "mdss_mdp.h"

#define MDNIE_LITE_TUN_DEBUG

#ifdef MDNIE_LITE_TUN_DEBUG
#define DPRINT(x...)	printk(KERN_ERR "[mdnie lite] " x)
#else
#define DPRINT(x...)
#endif

int play_speed_1_5;

struct mdnie_lite_tun_type mdnie_tun_state = {
	.mdnie_enable = false,
	.accessibility = ACCESSIBILITY_OFF,
};

const char accessibility_name[ACCESSIBILITY_MAX][20] = {
	"ACCESSIBILITY_OFF",
	"NEGATIVE_MODE",
	"COLOR_BLIND_MODE",
	"SCREEN_CURTAIN_MODE",
};

static struct mdp_pcc_cfg_data pcc_reverse = {
	.block = MDP_LOGICAL_BLOCK_DISP_0,
	.ops = MDP_PP_OPS_WRITE | MDP_PP_OPS_ENABLE,
	.r = { 0x00007ff8, 0xffff8000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	.g = { 0x00007ff8, 0x00000000, 0xffff8000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	.b = { 0x00007ff8, 0x00000000, 0x00000000, 0xffff8000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
};

static struct mdp_pcc_cfg_data pcc_normal = {
	.block = MDP_LOGICAL_BLOCK_DISP_0,
	.ops = MDP_PP_OPS_WRITE | MDP_PP_OPS_DISABLE,
	.r = { 0x00000000, 0x00008000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	.g = { 0x00000000, 0x00000000, 0x00008000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	.b = { 0x00000000, 0x00000000, 0x00000000, 0x00008000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
};

static void mdss_negative_color(int is_negative_on)
{
	u32 copyback;
	int i;
	struct mdss_mdp_ctl *ctl;
	struct mdss_mdp_ctl *ctl_d = NULL;
	struct mdss_data_type *mdata;

	mdata = mdss_mdp_get_mdata();
	for (i = 0; i < mdata->nctl; i++) {
		ctl = mdata->ctl_off + i;
		if ((ctl->power_on) && (ctl->mfd) && (ctl->mfd->index == 0)) {
			ctl_d = ctl;
			break;
		}
	}
	if (ctl_d) {
		if (is_negative_on)
			mdss_mdp_pcc_config(&pcc_reverse, &copyback);
		else
			mdss_mdp_pcc_config(&pcc_normal, &copyback);
	} else {
		DPRINT("%s:ctl_d is NULL ", __func__);
	}
}

void mDNIe_Set_Mode(void)
{
	if (!mdnie_tun_state.mdnie_enable) {
		DPRINT("[ERROR] mDNIE engine is OFF.\n");
		return;
	}

	play_speed_1_5 = 0;

	switch (mdnie_tun_state.accessibility) {
		case NEGATIVE:
			mdss_negative_color(1);
			break;
		case COLOR_BLIND:
		case SCREEN_CURTAIN:
		case ACCESSIBILITY_OFF:
			mdss_negative_color(0);
		default:
			break;
	}

	DPRINT("mDNIe_Set_Mode end , %s(%d)\n",
		accessibility_name[mdnie_tun_state.accessibility], mdnie_tun_state.accessibility);
}

void is_play_speed_1_5(int enable)
{
	play_speed_1_5 = enable;
}

void is_negative_on(void)
{
	DPRINT("is negative Mode On = %d\n", mdnie_tun_state.accessibility);

	mDNIe_Set_Mode();
}

static ssize_t accessibility_show(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	DPRINT("Current accessibility Mode : %s\n",
		accessibility_name[mdnie_tun_state.accessibility]);

	return snprintf(buf, 256, "Current accessibility Mode : %s\n",
		accessibility_name[mdnie_tun_state.accessibility]);
}

static ssize_t accessibility_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t size)
{
	int cmd_value;
	int backup;

	sscanf(buf, "%d", &cmd_value);

	backup = mdnie_tun_state.accessibility;

	if (cmd_value == NEGATIVE) {
		if (mdnie_tun_state.accessibility == NEGATIVE)
			return size;
		mdnie_tun_state.accessibility = NEGATIVE;
	}
	else if (cmd_value == COLOR_BLIND) {
		if (mdnie_tun_state.accessibility == COLOR_BLIND)
			return size;
		mdnie_tun_state.accessibility = COLOR_BLIND;
	}
	else if (cmd_value == SCREEN_CURTAIN) {
		if (mdnie_tun_state.accessibility == SCREEN_CURTAIN)
			return size;
		mdnie_tun_state.accessibility = SCREEN_CURTAIN;
	}
	else if (cmd_value == ACCESSIBILITY_OFF) {
		if (mdnie_tun_state.accessibility == ACCESSIBILITY_OFF)
			return size;
		mdnie_tun_state.accessibility = ACCESSIBILITY_OFF;
	} else
		DPRINT("%s ACCESSIBILITY_MAX", __func__);

	DPRINT(" %s : (%s) -> (%s)\n",
			__func__, accessibility_name[backup], accessibility_name[mdnie_tun_state.accessibility]);

	mDNIe_Set_Mode();

	DPRINT("%s cmd_value : %d size : %d", __func__, cmd_value, size);

	return size;
}

static ssize_t negative_show(struct device *dev,
					      struct device_attribute *attr,
					      char *buf)
{
	return snprintf(buf, 256, "Current negative Value : %s\n",
		(mdnie_tun_state.accessibility == 1) ? "Enabled" : "Disabled");
}

static ssize_t negative_store(struct device *dev,
					       struct device_attribute *attr,
					       const char *buf, size_t size)
{
	int value;

	sscanf(buf, "%d", &value);

	DPRINT("negative_store, input value = %d\n", value);
	if (mdnie_tun_state.accessibility == value)
		return size;
	mdnie_tun_state.accessibility = value;

	mDNIe_Set_Mode();

	return size;
}

static ssize_t playspeed_show(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	DPRINT("called %s\n", __func__);
	return snprintf(buf, 256, "%d\n", play_speed_1_5);
}

static ssize_t playspeed_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t size)
{
	int value;
	sscanf(buf, "%d", &value);

	DPRINT("[Play Speed Set] play speed value = %d\n", value);

	is_play_speed_1_5(value);
	return size;
}

static DEVICE_ATTR(accessibility, 0664, accessibility_show, accessibility_store);
static DEVICE_ATTR(negative, 0664, negative_show, negative_store);
static DEVICE_ATTR(playspeed, 0664, playspeed_show, playspeed_store);

static struct class *mdnie_class;
struct device *tune_mdnie_dev;

void init_mdnie_class(void)
{
	if (mdnie_tun_state.mdnie_enable) {
		DPRINT("%s : mdnie already enabled...\n",__func__);
		return;
	}

	DPRINT("start!\n");

	mdnie_class = class_create(THIS_MODULE, "mdnie");
	if (IS_ERR(mdnie_class)) {
		DPRINT("Failed to create mdnie class!\n");
		return;
	}

	tune_mdnie_dev = device_create(mdnie_class, NULL, 0, NULL, "mdnie");
	if (IS_ERR(tune_mdnie_dev))
		DPRINT("Failed to create mdnie device!\n");

	if (device_create_file
		(tune_mdnie_dev, &dev_attr_accessibility) < 0)
		DPRINT("Failed to create device file(%s)!=n",
			dev_attr_accessibility.attr.name);

	if (device_create_file
		(tune_mdnie_dev, &dev_attr_negative) < 0)
		DPRINT("Failed to create device file(%s)!\n",
			dev_attr_negative.attr.name);

	if (device_create_file
		(tune_mdnie_dev, &dev_attr_playspeed) < 0)
		DPRINT("Failed to create device file(%s)!=n",
			dev_attr_playspeed.attr.name);

	mdnie_tun_state.mdnie_enable = true;
	DPRINT("end!\n");
}
