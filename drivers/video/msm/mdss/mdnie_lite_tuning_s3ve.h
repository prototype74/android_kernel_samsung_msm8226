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

#ifndef _MDNIE_LITE_TUNING_S3VE_H_
#define _MDNIE_LITE_TUNING_S3VE_H_

enum SCENARIO {
	mDNIe_UI_MODE,
	mDNIe_VIDEO_MODE,
	mDNIe_VIDEO_WARM_MODE,
	mDNIe_VIDEO_COLD_MODE,
	mDNIe_CAMERA_MODE,
	mDNIe_NAVI,
	mDNIe_GALLERY,
	mDNIe_VT_MODE,
	mDNIe_BROWSER_MODE,
	mDNIe_eBOOK_MODE,
	mDNIe_EMAIL_MODE,
	MAX_mDNIe_MODE,
};

enum BACKGROUND {
	DYNAMIC_MODE = 0,
	STANDARD_MODE,
	NATURAL_MODE,
	MOVIE_MODE,
	AUTO_MODE,
	MAX_BACKGROUND_MODE,
};

enum ACCESSIBILITY {
    ACCESSIBILITY_OFF = 0,
	NEGATIVE,
	COLOR_BLIND,
	SCREEN_CURTAIN,
	GRAYSCALE,
	GRAYSCALE_NEGATIVE,
	ACCESSIBILITY_MAX,
};

struct mdnie_lite_tun_type {
	bool mdnie_enable;
	enum SCENARIO scenario;
	enum BACKGROUND background;
	enum ACCESSIBILITY accessibility;
};

void init_mdnie_class(void);
void is_negative_on(void);
void mDNIe_Set_Mode(void);

#endif /*_MDNIE_LITE_TUNING_S3VE_H_*/
