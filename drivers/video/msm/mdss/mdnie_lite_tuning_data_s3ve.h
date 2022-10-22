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

struct pcc_colors {
	uint32_t c, r, g, b;
};

struct pcc_color_cfg {
	uint32_t op;
	struct pcc_colors r, g, b;
};

struct pa_adj {
	uint32_t op, hue, sat, val, cont;
};

struct pcc_color_cfg NEGATIVE_MODE = {
	.op = MDP_PP_OPS_ENABLE,
	/* complementary colors ON */
	.r.c = 0x00007ff8,
	.g.c = 0x00007ff8,
	.b.c = 0x00007ff8,
	.r.r = 0xffff8000, // scr_Kr
	.g.g = 0xffff8000, // scr_Kg
	.b.b = 0xffff8000, // scr_Kb
};

struct pcc_color_cfg STANDARD_UI = {
	.op = MDP_PP_OPS_ENABLE,
	.r.c = 0x00000000,
	.g.c = 0x00000000,
	.b.c = 0x00000000,
	.r.r = 0x00008000, // scr_Wr
	.g.g = 0x00007C7C, // scr_Wg
	.b.b = 0x000077F7, // scr_Wb
};

struct pa_adj NATURAL_UI = {
	.op = MDP_PP_OPS_ENABLE,
	.hue = 0x00,
	.sat = 0xef,
	.val = 0xff,
	.cont = 0xff,
};

struct pcc_color_cfg DYNAMIC_UI = {
	.op = MDP_PP_OPS_ENABLE,
	.r.c = 0x00000000,
	.g.c = 0x00000000,
	.b.c = 0x00000000,
	.r.r = 0x00008787, // scr_Wr
	.g.g = 0x00008787, // scr_Wg
	.b.b = 0x00008787, // scr_Wb
};

struct pcc_color_cfg NORMAL_UI_1 = { // default data
	.op = MDP_PP_OPS_DISABLE,
	/* complementary colors OFF */
	.r.c = 0x00000000,
	.g.c = 0x00000000,
	.b.c = 0x00000000,
	.r.r = 0x00008000, // scr_Wr
	.g.g = 0x00008000, // scr_Wg
	.b.b = 0x00008000, // scr_Wb
};

struct pa_adj NORMAL_UI_2 = { // default data
	.op = MDP_PP_OPS_DISABLE,
	.hue = 0x00,
	.sat = 0xff,
	.val = 0xff,
	.cont = 0xff,
};

#endif /*_MDNIE_LITE_TUNING_DATA_S3VE_H_*/

