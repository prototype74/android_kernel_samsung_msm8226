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

struct pcc_color_cfg {
	uint32_t op;
	uint32_t rc, gc, bc, rr, rg, rb, gr, gg, gb, br, bg, bb;
};

struct pa_adj {
	uint32_t op, hue, sat, val, cont;
};

struct tunes {
	struct pcc_color_cfg pcc;
	struct pa_adj pa;
};

struct tunes blind_tunes[ACCESSIBILITY_MAX] = {
/*
	ACCESSIBILITY_OFF,
	NEGATIVE,
	COLOR_BLIND,
	SCREEN_CURTAIN,
*/
	{
		{
			MDP_PP_OPS_DISABLE,
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
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
	{
		{
			MDP_PP_OPS_ENABLE,
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
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
	{
		{
			MDP_PP_OPS_DISABLE,
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
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
	{
		{
			MDP_PP_OPS_DISABLE,
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
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
};

struct tunes mdnie_tunes[MAX_BACKGROUND_MODE] = {
/*
	DYNAMIC_MODE,
	STANDARD_MODE,
	NATURAL_MODE,
	MOVIE_MODE,
	AUTO_MODE,
*/
	{
		{
			MDP_PP_OPS_ENABLE,
			0x00000000, //rc
			0x00000000, //gc
			0x00000000, //bc
			0x00008787, //rr
			0x00000000, //rg
			0x00000000, //rb
			0x00000000, //gr
			0x00008787, //gg
			0x00000000, //gb
			0x00000000, //br
			0x00000000, //bg
			0x00008787, //bb
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
	{
		{
			MDP_PP_OPS_ENABLE,
			0x00000000, //rc
			0x00000000, //gc
			0x00000000, //bc
			0x00008000, //rr
			0x00000000, //rg
			0x00000000, //rb
			0x00000000, //gr
			0x00007C7C, //gg
			0x00000000, //gb
			0x00000000, //br
			0x00000000, //bg
			0x000077F7, //bb
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
	{
		{
			MDP_PP_OPS_ENABLE,
			0x00000000, //rc
			0x00000000, //gc
			0x00000000, //bc
			0x00008000, //rr
			0x00000000, //rg
			0x00000000, //rb
			0x00000000, //gr
			0x00007C7C, //gg
			0x00000000, //gb
			0x00000000, //br
			0x00000000, //bg
			0x000077F7, //bb
		},
		{
			MDP_PP_OPS_ENABLE,
			0x00,
			0xef,
			0xff,
			0xff,
		}
	},
	{
		{
			MDP_PP_OPS_DISABLE,
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
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
	{
		{
			MDP_PP_OPS_DISABLE,
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
		},
		{
			MDP_PP_OPS_DISABLE,
			0x00,
			0xff,
			0xff,
			0xff,
		}
	},
};

#endif /*_MDNIE_LITE_TUNING_DATA_S3VE_H_*/

