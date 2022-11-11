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

#include "mdss_mdp.h"
#include "mdnie_lite_tuning_s3ve.h"
#include "mdnie_lite_tuning_data_s3ve.h"

#define MDNIE_LITE_TUN_DEBUG

#ifdef MDNIE_LITE_TUN_DEBUG
#define DPRINT(x...)	printk(KERN_ERR "[mdnie lite] " x)
#else
#define DPRINT(x...)
#endif

int play_speed_1_5;

struct mdnie_lite_tun_type mdnie_tun_state = {
	.mdnie_enable = false,
	.mdnie_bypass = BYPASS_DISABLE,
	.scenario = mDNIe_UI_MODE,
	.background = AUTO_MODE,
	.outdoor = OUTDOOR_OFF_MODE,
	.accessibility = ACCESSIBILITY_OFF,
};

const char scenario_name[MAX_mDNIe_MODE][16] = {
	"UI_MODE",
	"VIDEO_MODE",
	"VIDEO_WARM_MODE",
	"VIDEO_COLD_MODE",
	"CAMERA_MODE",
	"NAVI",
	"GALLERY_MODE",
	"VT_MODE",
	"BROWSER",
	"eBOOK",
	"EMAIL",
};

const char background_name[MAX_BACKGROUND_MODE][10] = {
	"DYNAMIC",
	"STANDARD",
	"NATURAL",
	"MOVIE",
	"AUTO",
	"READING",
};

const char outdoor_name[MAX_OUTDOOR_MODE][20] = {
	"OUTDOOR_OFF_MODE",
	"OUTDOOR_ON_MODE",
};

const char accessibility_name[ACCESSIBILITY_MAX][20] = {
	"ACCESSIBILITY_OFF",
	"NEGATIVE_MODE",
	"COLOR_BLIND_MODE",
	"SCREEN_CURTAIN_MODE",
	"GRAYSCALE_MODE",
	"GRAY_NEGATIVE_MODE",
};

static void mdss_set_tuning(uint32_t mdnie_cfg[])
{
	u32 copyback;
	int i;
	struct mdss_mdp_ctl *ctl;
	struct mdss_mdp_ctl *ctl_d = NULL;
	struct mdss_data_type *mdata;
	struct mdp_pcc_cfg_data pcc_cfg;
	struct mdp_pa_cfg_data pa_cfg;

	mdata = mdss_mdp_get_mdata();
	for (i = 0; i < mdata->nctl; i++) {
		ctl = mdata->ctl_off + i;
		if ((ctl->power_on) && (ctl->mfd) && (ctl->mfd->index == 0)) {
			ctl_d = ctl;
			break;
		}
	}

	if (!ctl_d) {
		DPRINT("%s:ctl_d is NULL ", __func__);
		return;
	}

	memset(&pcc_cfg, 0, sizeof(struct mdp_pcc_cfg_data));
	memset(&pa_cfg, 0, sizeof(struct mdp_pa_cfg_data));

	pcc_cfg.block = MDP_LOGICAL_BLOCK_DISP_0;
	pcc_cfg.ops = MDP_PP_OPS_WRITE | mdnie_cfg[0];
	pcc_cfg.r.c = mdnie_cfg[1];
	pcc_cfg.g.c = mdnie_cfg[2];
	pcc_cfg.b.c = mdnie_cfg[3];
	pcc_cfg.r.r = mdnie_cfg[4];
	pcc_cfg.r.g = mdnie_cfg[5];
	pcc_cfg.r.b = mdnie_cfg[6];
	pcc_cfg.g.r = mdnie_cfg[7];
	pcc_cfg.g.g = mdnie_cfg[8];
	pcc_cfg.g.b = mdnie_cfg[9];
	pcc_cfg.b.r = mdnie_cfg[10];
	pcc_cfg.b.g = mdnie_cfg[11];
	pcc_cfg.b.b = mdnie_cfg[12];

	pa_cfg.block = MDP_LOGICAL_BLOCK_DISP_0;
	pa_cfg.pa_data.flags = MDP_PP_OPS_WRITE | mdnie_cfg[13];
	pa_cfg.pa_data.hue_adj = mdnie_cfg[14];
	pa_cfg.pa_data.sat_adj = mdnie_cfg[15];
	pa_cfg.pa_data.val_adj = mdnie_cfg[16];
	pa_cfg.pa_data.cont_adj = mdnie_cfg[17];

	mdss_mdp_pcc_config(&pcc_cfg, &copyback);
	mdss_mdp_pa_config(&pa_cfg, &copyback);
}

void mDNIe_Set_Mode(void)
{
	uint32_t mdnie_cfg[18] = {0,};

	if (!mdnie_tun_state.mdnie_enable) {
		DPRINT("[ERROR] mDNIE engine is OFF.\n");
		return;
	}

	if (mdnie_tun_state.scenario < mDNIe_UI_MODE || mdnie_tun_state.scenario >= MAX_mDNIe_MODE) {
		DPRINT("[ERROR] wrong Scenario mode value : %d\n",
			mdnie_tun_state.scenario);
		return;
	}

	play_speed_1_5 = 0;

	if (mdnie_tun_state.mdnie_bypass == BYPASS_ENABLE)
		memcpy(mdnie_cfg, DEFAULT_MDNIE, sizeof(mdnie_cfg));
	else if (mdnie_tun_state.accessibility)
		memcpy(mdnie_cfg, blind_tunes[mdnie_tun_state.accessibility], sizeof(mdnie_cfg));
	else
		memcpy(mdnie_cfg,
		       mdnie_tunes[mdnie_tun_state.scenario][mdnie_tun_state.background][mdnie_tun_state.outdoor],
		       sizeof(mdnie_cfg));

	mdss_set_tuning(mdnie_cfg);

	DPRINT("mDNIe_Set_Mode end , MDNIE_BYPASS(%d), %s(%d), %s(%d), %s(%d), %s(%d)\n",
		mdnie_tun_state.mdnie_bypass,
		scenario_name[mdnie_tun_state.scenario], mdnie_tun_state.scenario,
		background_name[mdnie_tun_state.background], mdnie_tun_state.background,
		outdoor_name[mdnie_tun_state.outdoor], mdnie_tun_state.outdoor,
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

static ssize_t bypass_show(struct device *dev,
					 struct device_attribute *attr,
					 char *buf)
{
	DPRINT("Current MDNIE bypass : %s\n",
		mdnie_tun_state.mdnie_bypass ? "ENABLE" : "DISABLE");

	return snprintf(buf, 256, "Current MDNIE bypass : %s\n",
		mdnie_tun_state.mdnie_bypass ? "ENABLE" : "DISABLE");
}

static ssize_t bypass_store(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t size)
{
	int value;

	sscanf(buf, "%d", &value);

	if (value)
		mdnie_tun_state.mdnie_bypass = BYPASS_ENABLE;
	else
		mdnie_tun_state.mdnie_bypass = BYPASS_DISABLE;

	DPRINT("%s bypass : %s value : %d\n",
		__func__, mdnie_tun_state.mdnie_bypass ? "ENABLE" : "DISABLE", value);

	mDNIe_Set_Mode();

	return size;
}

static ssize_t mode_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	DPRINT("Current Background Mode : %s\n",
		background_name[mdnie_tun_state.background]);

	return snprintf(buf, 256, "Current Background Mode : %s\n",
		background_name[mdnie_tun_state.background]);
}

static ssize_t mode_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	int value;
	int backup;

	sscanf(buf, "%d", &value);

	if (value < DYNAMIC_MODE || value >= MAX_BACKGROUND_MODE) {
		DPRINT("[ERROR] wrong backgound mode value : %d\n",
			value);
		return size;
	}
	backup = mdnie_tun_state.background;
	if (mdnie_tun_state.background == value)
		return size;
	mdnie_tun_state.background = value;

	if (mdnie_tun_state.accessibility == NEGATIVE) {
		DPRINT("already negative mode(%d), do not set background(%d)\n",
			mdnie_tun_state.accessibility, mdnie_tun_state.background);
	} else {
		DPRINT(" %s : (%s) -> (%s)\n",
			__func__, background_name[backup], background_name[mdnie_tun_state.background]);

		mDNIe_Set_Mode();
	}

	return size;
}

static ssize_t scenario_show(struct device *dev,
					 struct device_attribute *attr,
					 char *buf)
{
	DPRINT("Current Scenario Mode : %s\n",
		scenario_name[mdnie_tun_state.scenario]);

	return snprintf(buf, 256, "Current Scenario Mode : %s\n",
		scenario_name[mdnie_tun_state.scenario]);
}

static ssize_t scenario_store(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t size)
{
	int value;
	int backup;

	sscanf(buf, "%d", &value);

	if (value < mDNIe_UI_MODE || value >= MAX_mDNIe_MODE) {
		DPRINT("[ERROR] wrong Scenario mode value : %d\n",
			value);
		return size;
	}

	backup = mdnie_tun_state.scenario;
	if (mdnie_tun_state.scenario == value)
		return size;
	mdnie_tun_state.scenario = value;

	if (mdnie_tun_state.accessibility == NEGATIVE) {
		DPRINT("already negative mode(%d), do not set mode(%d)\n",
			mdnie_tun_state.accessibility, mdnie_tun_state.scenario);
	} else {
		DPRINT(" %s : (%s) -> (%s)\n",
			__func__, scenario_name[backup], scenario_name[mdnie_tun_state.scenario]);
		mDNIe_Set_Mode();
	}
	return size;
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
	else if (cmd_value == GRAYSCALE) {
		if (mdnie_tun_state.accessibility == GRAYSCALE)
			return size;
		mdnie_tun_state.accessibility = GRAYSCALE;
	}
	else if (cmd_value == GRAYSCALE_NEGATIVE) {
		if (mdnie_tun_state.accessibility == GRAYSCALE_NEGATIVE)
			return size;
		mdnie_tun_state.accessibility = GRAYSCALE_NEGATIVE;
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

static ssize_t outdoor_show(struct device *dev,
					      struct device_attribute *attr,
					      char *buf)
{
	DPRINT("Current outdoor Mode : %s\n",
		outdoor_name[mdnie_tun_state.outdoor]);

	return snprintf(buf, 256, "Current outdoor Mode : %s\n",
		outdoor_name[mdnie_tun_state.outdoor]);
}

static ssize_t outdoor_store(struct device *dev,
					       struct device_attribute *attr,
					       const char *buf, size_t size)
{
	int value;
	int backup;

	sscanf(buf, "%d", &value);

	DPRINT("outdoor value = %d, scenario = %d\n",
		value, mdnie_tun_state.scenario);

	if (value < OUTDOOR_OFF_MODE || value >= MAX_OUTDOOR_MODE)
		DPRINT("[ERROR] : wrong outdoor mode value : %d\n", value);

	backup = mdnie_tun_state.outdoor;
	if (mdnie_tun_state.outdoor == value)
		return size;
	mdnie_tun_state.outdoor = value;

	if (mdnie_tun_state.accessibility == NEGATIVE) {
		DPRINT("already negative mode(%d), do not outdoor mode(%d)\n",
			mdnie_tun_state.accessibility, mdnie_tun_state.outdoor);
	} else {
		DPRINT(" %s : (%s) -> (%s)\n",
			__func__, outdoor_name[backup], outdoor_name[mdnie_tun_state.outdoor]);
		mDNIe_Set_Mode();
	}

	return size;
}

static DEVICE_ATTR(accessibility, 0664, accessibility_show, accessibility_store);
static DEVICE_ATTR(bypass, 0664, bypass_show, bypass_store);
static DEVICE_ATTR(mode, 0664, mode_show, mode_store);
static DEVICE_ATTR(outdoor, 0664, outdoor_show, outdoor_store);
static DEVICE_ATTR(playspeed, 0664, playspeed_show, playspeed_store);
static DEVICE_ATTR(scenario, 0664, scenario_show, scenario_store);

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
		(tune_mdnie_dev, &dev_attr_bypass) < 0)
		DPRINT("Failed to create device file(%s)!=n",
			dev_attr_bypass.attr.name);

	if (device_create_file
		(tune_mdnie_dev, &dev_attr_mode) < 0)
		pr_err("Failed to create device file(%s)!\n",
			dev_attr_mode.attr.name);

	if (device_create_file
		(tune_mdnie_dev, &dev_attr_outdoor) < 0)
		pr_err("Failed to create device file(%s)!\n",
	       dev_attr_outdoor.attr.name);

	if (device_create_file
		(tune_mdnie_dev, &dev_attr_playspeed) < 0)
		DPRINT("Failed to create device file(%s)!=n",
			dev_attr_playspeed.attr.name);

	if (device_create_file
	    (tune_mdnie_dev, &dev_attr_scenario) < 0)
		pr_err("Failed to create device file(%s)!\n",
	       dev_attr_scenario.attr.name);

	mdnie_tun_state.mdnie_enable = true;
	DPRINT("end!\n");
}
