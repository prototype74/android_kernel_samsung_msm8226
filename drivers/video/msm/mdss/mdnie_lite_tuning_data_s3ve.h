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

#ifndef _MDNIE_LITE_TUNING_DATA_S3VE_H_
#define _MDNIE_LITE_TUNING_DATA_S3VE_H_

static uint32_t DEFAULT_MDNIE[] = {
	MDP_PP_OPS_DISABLE, //pcc_en
	0x00000000, //rc
	0x00000000, //gc
	0x00000000, //bc
	0x00008000, //rr
	0x00000000, //rg
	0x00000000, //rb
	0x00000000, //gr
	0x00008000, //gg
	0x00000000, //gb
	0x00000000, //br
	0x00000000, //bg
	0x00008000, //bb
	MDP_PP_OPS_DISABLE, //pa_en
	0x00, //hue
	0xff, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t NEGATIVE_MDNIE[] = {
	MDP_PP_OPS_ENABLE, //pcc_en
	0x00007ff8, //rc
	0x00007ff8, //gc
	0x00007ff8, //bc
	0xffff8000, //rr
	0x00000000, //rg
	0x00000000, //rb
	0x00000000, //gr
	0xffff8000, //gg
	0x00000000, //gb
	0x00000000, //br
	0x00000000, //bg
	0xffff8000, //bb
	MDP_PP_OPS_DISABLE, //pa_en
	0x00, //hue
	0xff, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t GRAYSCALE_MDNIE[] = {
	MDP_PP_OPS_ENABLE, //pcc_en
	0x00000000, //rc
	0x00000000, //gc
	0x00000000, //bc
	0x00002626, //rr
	0x00004B4B, //rg
	0x00000E8F, //rb
	0x00002626, //gr
	0x00004B4B, //gg
	0x00000E8F, //gb
	0x00002626, //br
	0x00004B4B, //bg
	0x00000E8F, //bb
	MDP_PP_OPS_DISABLE, //pa_en
	0x00, //hue
	0xff, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t GRAYSCALE_NEAGTIVE_MDNIE[] = {
	MDP_PP_OPS_ENABLE, //pcc_en
	0x00007ff8, //rc
	0x00007ff8, //gc
	0x00007ff8, //bc
	0xffffD9D9, //rr
	0xffffB4B4, //rg
	0xffffF170, //rb
	0xffffD9D9, //gr
	0xffffB4B4, //gg
	0xffffF170, //gb
	0xffffD9D9, //br
	0xffffB4B4, //bg
	0xffffF170, //bb
	MDP_PP_OPS_DISABLE, //pa_en
	0x00, //hue
	0xff, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t DYNAMIC_MDNIE[] = {
	MDP_PP_OPS_DISABLE, //pcc_en
	0x00000000, //rc
	0x00000000, //gc
	0x00000000, //bc
	0x00008000, //rr
	0x00000000, //rg
	0x00000000, //rb
	0x00000000, //gr
	0x00008000, //gg
	0x00000000, //gb
	0x00000000, //br
	0x00000000, //bg
	0x00008000, //bb
	MDP_PP_OPS_ENABLE, //pa_en
	0x00, //hue
	0x104, //sat
	0x102, //val
	0x108, //cont
};

static uint32_t STANDARD_MDNIE[] = {
	MDP_PP_OPS_ENABLE, //pcc_en
	0x00000000, //rc
	0x00000000, //gc
	0x00000000, //bc
	0x00007CFC, //rr
	0x00000168, //rg
	0x0000021C, //rb
	0x00000747, //gr
	0x00006DEE, //gg
	0x00000747, //gb
	0x00000484, //br
	0x00000303, //bg
	0x00007070, //bb
	MDP_PP_OPS_DISABLE, //pa_en
	0x00, //hue
	0xff, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t NATURAL_MDNIE[] = {
	MDP_PP_OPS_ENABLE, //pcc_en
	0x00000000, //rc
	0x00000000, //gc
	0x00000000, //bc
	0x00006C6D, //rr
	0x00000A0A, //rg
	0x00000989, //rb
	0x00000606, //gr
	0x00007373, //gg
	0x00000303, //gb
	0x000004D1, //br
	0x00000337, //bg
	0x00006FEF, //bb
	MDP_PP_OPS_ENABLE, //pa_en
	0x00, //hue
	0xf2, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t GALLERY_AUTO_MDNIE[] = {
	MDP_PP_OPS_ENABLE, //pcc_en
	0x00000000, //rc
	0x00000000, //gc
	0x00000000, //bc
	0x00007070, //rr
	0x000007C8, //rg
	0x000007C8, //rb
	0x00000000, //gr
	0x00008000, //gg
	0x00000000, //gb
	0x00000000, //br
	0x00000000, //bg
	0x00008000, //bb
	MDP_PP_OPS_DISABLE, //pa_en
	0x00, //hue
	0xff, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t EBOOK_AUTO_MDNIE[] = {
	MDP_PP_OPS_ENABLE, //pcc_en
	0x00000000, //rc
	0x00000000, //gc
	0x00000000, //bc
	0x00008000, //rr
	0x00000000, //rg
	0x00000000, //rb
	0x00000000, //gr
	0x00007A7A, //gg
	0x00000000, //gb
	0x00000000, //br
	0x00000000, //bg
	0x00007272, //bb
	MDP_PP_OPS_DISABLE, //pa_en
	0x00, //hue
	0xff, //sat
	0xff, //val
	0xff, //cont
};

static uint32_t *blind_tunes[ACCESSIBILITY_MAX] = {
/*
	ACCESSIBILITY_OFF,
	NEGATIVE,
	COLOR_BLIND,
	SCREEN_CURTAIN,
	GRAYSCALE,
	GRAYSCALE_NEGATIVE,
*/
	DEFAULT_MDNIE,
	NEGATIVE_MDNIE,
	DEFAULT_MDNIE,
	DEFAULT_MDNIE,
	GRAYSCALE_MDNIE,
	GRAYSCALE_NEAGTIVE_MDNIE,
};

static uint32_t *mdnie_tunes[MAX_mDNIe_MODE][MAX_BACKGROUND_MODE][MAX_OUTDOOR_MODE] = {
	/*
		DYNAMIC_MODE,
		STANDARD_MODE,
		NATURAL_MODE,
		MOVIE_MODE,
		AUTO_MODE,
		READING_MODE,
	*/
	// UI_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// VIDEO_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// VIDEO_WARM_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// VIDEO_COLD_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// CAMERA_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{GALLERY_AUTO_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// NAVI_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// GALLERY_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{GALLERY_AUTO_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// VT_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// BROWSER_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// eBOOK_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
	// EMAIL_APP
	{
		{DYNAMIC_MDNIE, DEFAULT_MDNIE},
		{STANDARD_MDNIE, DEFAULT_MDNIE},
		{NATURAL_MDNIE, DEFAULT_MDNIE},
		{DEFAULT_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
		{EBOOK_AUTO_MDNIE, DEFAULT_MDNIE},
	},
};

#endif /*_MDNIE_LITE_TUNING_DATA_S3VE_H_*/

