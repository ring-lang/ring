#include "ring.h"

/*
**  Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/

#include "console-colors.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "console-colors.c"

void cc_print(int color,const char *string)
{
	cc_fprintf(color,stdout,string);
}

RING_FUNC(ring_get_cc_fg_none)
{
	RING_API_RETNUMBER(CC_FG_NONE);
}

RING_FUNC(ring_get_cc_fg_black)
{
	RING_API_RETNUMBER(CC_FG_BLACK);
}

RING_FUNC(ring_get_cc_fg_dark_red)
{
	RING_API_RETNUMBER(CC_FG_DARK_RED);
}

RING_FUNC(ring_get_cc_fg_dark_green)
{
	RING_API_RETNUMBER(CC_FG_DARK_GREEN);
}

RING_FUNC(ring_get_cc_fg_dark_yellow)
{
	RING_API_RETNUMBER(CC_FG_DARK_YELLOW);
}

RING_FUNC(ring_get_cc_fg_dark_blue)
{
	RING_API_RETNUMBER(CC_FG_DARK_BLUE);
}

RING_FUNC(ring_get_cc_fg_dark_magenta)
{
	RING_API_RETNUMBER(CC_FG_DARK_MAGENTA);
}

RING_FUNC(ring_get_cc_fg_dark_cyan)
{
	RING_API_RETNUMBER(CC_FG_DARK_CYAN);
}

RING_FUNC(ring_get_cc_fg_gray)
{
	RING_API_RETNUMBER(CC_FG_GRAY);
}

RING_FUNC(ring_get_cc_fg_dark_gray)
{
	RING_API_RETNUMBER(CC_FG_DARK_GRAY);
}

RING_FUNC(ring_get_cc_fg_red)
{
	RING_API_RETNUMBER(CC_FG_RED);
}

RING_FUNC(ring_get_cc_fg_green)
{
	RING_API_RETNUMBER(CC_FG_GREEN);
}

RING_FUNC(ring_get_cc_fg_yellow)
{
	RING_API_RETNUMBER(CC_FG_YELLOW);
}

RING_FUNC(ring_get_cc_fg_blue)
{
	RING_API_RETNUMBER(CC_FG_BLUE);
}

RING_FUNC(ring_get_cc_fg_magenta)
{
	RING_API_RETNUMBER(CC_FG_MAGENTA);
}

RING_FUNC(ring_get_cc_fg_cyan)
{
	RING_API_RETNUMBER(CC_FG_CYAN);
}

RING_FUNC(ring_get_cc_fg_white)
{
	RING_API_RETNUMBER(CC_FG_WHITE);
}

RING_FUNC(ring_get_cc_bg_none)
{
	RING_API_RETNUMBER(CC_BG_NONE);
}

RING_FUNC(ring_get_cc_bg_black)
{
	RING_API_RETNUMBER(CC_BG_BLACK);
}

RING_FUNC(ring_get_cc_bg_dark_red)
{
	RING_API_RETNUMBER(CC_BG_DARK_RED);
}

RING_FUNC(ring_get_cc_bg_dark_green)
{
	RING_API_RETNUMBER(CC_BG_DARK_GREEN);
}

RING_FUNC(ring_get_cc_bg_dark_yellow)
{
	RING_API_RETNUMBER(CC_BG_DARK_YELLOW);
}

RING_FUNC(ring_get_cc_bg_dark_blue)
{
	RING_API_RETNUMBER(CC_BG_DARK_BLUE);
}

RING_FUNC(ring_get_cc_bg_dark_magenta)
{
	RING_API_RETNUMBER(CC_BG_DARK_MAGENTA);
}

RING_FUNC(ring_get_cc_bg_dark_cyan)
{
	RING_API_RETNUMBER(CC_BG_DARK_CYAN);
}

RING_FUNC(ring_get_cc_bg_gray)
{
	RING_API_RETNUMBER(CC_BG_GRAY);
}

RING_FUNC(ring_get_cc_bg_dark_gray)
{
	RING_API_RETNUMBER(CC_BG_DARK_GRAY);
}

RING_FUNC(ring_get_cc_bg_red)
{
	RING_API_RETNUMBER(CC_BG_RED);
}

RING_FUNC(ring_get_cc_bg_green)
{
	RING_API_RETNUMBER(CC_BG_GREEN);
}

RING_FUNC(ring_get_cc_bg_yellow)
{
	RING_API_RETNUMBER(CC_BG_YELLOW);
}

RING_FUNC(ring_get_cc_bg_blue)
{
	RING_API_RETNUMBER(CC_BG_BLUE);
}

RING_FUNC(ring_get_cc_bg_magenta)
{
	RING_API_RETNUMBER(CC_BG_MAGENTA);
}

RING_FUNC(ring_get_cc_bg_cyan)
{
	RING_API_RETNUMBER(CC_BG_CYAN);
}

RING_FUNC(ring_get_cc_bg_white)
{
	RING_API_RETNUMBER(CC_BG_WHITE);
}


RING_FUNC(ring_cc_print)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cc_print( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
}

RING_API void ringlib_init(RingState *pRingState)
{
	RING_API_REGISTER("cc_print",ring_cc_print);
	RING_API_REGISTER("get_cc_fg_none",ring_get_cc_fg_none);
	RING_API_REGISTER("get_cc_fg_black",ring_get_cc_fg_black);
	RING_API_REGISTER("get_cc_fg_dark_red",ring_get_cc_fg_dark_red);
	RING_API_REGISTER("get_cc_fg_dark_green",ring_get_cc_fg_dark_green);
	RING_API_REGISTER("get_cc_fg_dark_yellow",ring_get_cc_fg_dark_yellow);
	RING_API_REGISTER("get_cc_fg_dark_blue",ring_get_cc_fg_dark_blue);
	RING_API_REGISTER("get_cc_fg_dark_magenta",ring_get_cc_fg_dark_magenta);
	RING_API_REGISTER("get_cc_fg_dark_cyan",ring_get_cc_fg_dark_cyan);
	RING_API_REGISTER("get_cc_fg_gray",ring_get_cc_fg_gray);
	RING_API_REGISTER("get_cc_fg_dark_gray",ring_get_cc_fg_dark_gray);
	RING_API_REGISTER("get_cc_fg_red",ring_get_cc_fg_red);
	RING_API_REGISTER("get_cc_fg_green",ring_get_cc_fg_green);
	RING_API_REGISTER("get_cc_fg_yellow",ring_get_cc_fg_yellow);
	RING_API_REGISTER("get_cc_fg_blue",ring_get_cc_fg_blue);
	RING_API_REGISTER("get_cc_fg_magenta",ring_get_cc_fg_magenta);
	RING_API_REGISTER("get_cc_fg_cyan",ring_get_cc_fg_cyan);
	RING_API_REGISTER("get_cc_fg_white",ring_get_cc_fg_white);
	RING_API_REGISTER("get_cc_bg_none",ring_get_cc_bg_none);
	RING_API_REGISTER("get_cc_bg_black",ring_get_cc_bg_black);
	RING_API_REGISTER("get_cc_bg_dark_red",ring_get_cc_bg_dark_red);
	RING_API_REGISTER("get_cc_bg_dark_green",ring_get_cc_bg_dark_green);
	RING_API_REGISTER("get_cc_bg_dark_yellow",ring_get_cc_bg_dark_yellow);
	RING_API_REGISTER("get_cc_bg_dark_blue",ring_get_cc_bg_dark_blue);
	RING_API_REGISTER("get_cc_bg_dark_magenta",ring_get_cc_bg_dark_magenta);
	RING_API_REGISTER("get_cc_bg_dark_cyan",ring_get_cc_bg_dark_cyan);
	RING_API_REGISTER("get_cc_bg_gray",ring_get_cc_bg_gray);
	RING_API_REGISTER("get_cc_bg_dark_gray",ring_get_cc_bg_dark_gray);
	RING_API_REGISTER("get_cc_bg_red",ring_get_cc_bg_red);
	RING_API_REGISTER("get_cc_bg_green",ring_get_cc_bg_green);
	RING_API_REGISTER("get_cc_bg_yellow",ring_get_cc_bg_yellow);
	RING_API_REGISTER("get_cc_bg_blue",ring_get_cc_bg_blue);
	RING_API_REGISTER("get_cc_bg_magenta",ring_get_cc_bg_magenta);
	RING_API_REGISTER("get_cc_bg_cyan",ring_get_cc_bg_cyan);
	RING_API_REGISTER("get_cc_bg_white",ring_get_cc_bg_white);
}
