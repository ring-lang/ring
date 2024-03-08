#include "ring.h"

#include "rogueutil/rogueutil.h"
RING_FUNC(ring_get_black)
{
	RING_API_RETNUMBER(BLACK);
}

RING_FUNC(ring_get_blue)
{
	RING_API_RETNUMBER(BLUE);
}

RING_FUNC(ring_get_green)
{
	RING_API_RETNUMBER(GREEN);
}

RING_FUNC(ring_get_cyan)
{
	RING_API_RETNUMBER(CYAN);
}

RING_FUNC(ring_get_red)
{
	RING_API_RETNUMBER(RED);
}

RING_FUNC(ring_get_magenta)
{
	RING_API_RETNUMBER(MAGENTA);
}

RING_FUNC(ring_get_brown)
{
	RING_API_RETNUMBER(BROWN);
}

RING_FUNC(ring_get_grey)
{
	RING_API_RETNUMBER(GREY);
}

RING_FUNC(ring_get_darkgrey)
{
	RING_API_RETNUMBER(DARKGREY);
}

RING_FUNC(ring_get_lightblue)
{
	RING_API_RETNUMBER(LIGHTBLUE);
}

RING_FUNC(ring_get_lightgreen)
{
	RING_API_RETNUMBER(LIGHTGREEN);
}

RING_FUNC(ring_get_lightcyan)
{
	RING_API_RETNUMBER(LIGHTCYAN);
}

RING_FUNC(ring_get_lightred)
{
	RING_API_RETNUMBER(LIGHTRED);
}

RING_FUNC(ring_get_lightmagenta)
{
	RING_API_RETNUMBER(LIGHTMAGENTA);
}

RING_FUNC(ring_get_yellow)
{
	RING_API_RETNUMBER(YELLOW);
}

RING_FUNC(ring_get_white)
{
	RING_API_RETNUMBER(WHITE);
}

RING_FUNC(ring_get_key_escape)
{
	RING_API_RETNUMBER(KEY_ESCAPE);
}

RING_FUNC(ring_get_key_enter)
{
	RING_API_RETNUMBER(KEY_ENTER);
}

RING_FUNC(ring_get_key_space)
{
	RING_API_RETNUMBER(KEY_SPACE);
}

RING_FUNC(ring_get_key_insert)
{
	RING_API_RETNUMBER(KEY_INSERT);
}

RING_FUNC(ring_get_key_home)
{
	RING_API_RETNUMBER(KEY_HOME);
}

RING_FUNC(ring_get_key_pgup)
{
	RING_API_RETNUMBER(KEY_PGUP);
}

RING_FUNC(ring_get_key_delete)
{
	RING_API_RETNUMBER(KEY_DELETE);
}

RING_FUNC(ring_get_key_end)
{
	RING_API_RETNUMBER(KEY_END);
}

RING_FUNC(ring_get_key_pgdown)
{
	RING_API_RETNUMBER(KEY_PGDOWN);
}

RING_FUNC(ring_get_key_up)
{
	RING_API_RETNUMBER(KEY_UP);
}

RING_FUNC(ring_get_key_down)
{
	RING_API_RETNUMBER(KEY_DOWN);
}

RING_FUNC(ring_get_key_left)
{
	RING_API_RETNUMBER(KEY_LEFT);
}

RING_FUNC(ring_get_key_right)
{
	RING_API_RETNUMBER(KEY_RIGHT);
}

RING_FUNC(ring_get_key_f1)
{
	RING_API_RETNUMBER(KEY_F1);
}

RING_FUNC(ring_get_key_f2)
{
	RING_API_RETNUMBER(KEY_F2);
}

RING_FUNC(ring_get_key_f3)
{
	RING_API_RETNUMBER(KEY_F3);
}

RING_FUNC(ring_get_key_f4)
{
	RING_API_RETNUMBER(KEY_F4);
}

RING_FUNC(ring_get_key_f5)
{
	RING_API_RETNUMBER(KEY_F5);
}

RING_FUNC(ring_get_key_f6)
{
	RING_API_RETNUMBER(KEY_F6);
}

RING_FUNC(ring_get_key_f7)
{
	RING_API_RETNUMBER(KEY_F7);
}

RING_FUNC(ring_get_key_f8)
{
	RING_API_RETNUMBER(KEY_F8);
}

RING_FUNC(ring_get_key_f9)
{
	RING_API_RETNUMBER(KEY_F9);
}

RING_FUNC(ring_get_key_f10)
{
	RING_API_RETNUMBER(KEY_F10);
}

RING_FUNC(ring_get_key_f11)
{
	RING_API_RETNUMBER(KEY_F11);
}

RING_FUNC(ring_get_key_f12)
{
	RING_API_RETNUMBER(KEY_F12);
}

RING_FUNC(ring_get_key_numdel)
{
	RING_API_RETNUMBER(KEY_NUMDEL);
}

RING_FUNC(ring_get_key_numpad0)
{
	RING_API_RETNUMBER(KEY_NUMPAD0);
}

RING_FUNC(ring_get_key_numpad1)
{
	RING_API_RETNUMBER(KEY_NUMPAD1);
}

RING_FUNC(ring_get_key_numpad2)
{
	RING_API_RETNUMBER(KEY_NUMPAD2);
}

RING_FUNC(ring_get_key_numpad3)
{
	RING_API_RETNUMBER(KEY_NUMPAD3);
}

RING_FUNC(ring_get_key_numpad4)
{
	RING_API_RETNUMBER(KEY_NUMPAD4);
}

RING_FUNC(ring_get_key_numpad5)
{
	RING_API_RETNUMBER(KEY_NUMPAD5);
}

RING_FUNC(ring_get_key_numpad6)
{
	RING_API_RETNUMBER(KEY_NUMPAD6);
}

RING_FUNC(ring_get_key_numpad7)
{
	RING_API_RETNUMBER(KEY_NUMPAD7);
}

RING_FUNC(ring_get_key_numpad8)
{
	RING_API_RETNUMBER(KEY_NUMPAD8);
}

RING_FUNC(ring_get_key_numpad9)
{
	RING_API_RETNUMBER(KEY_NUMPAD9);
}


RING_FUNC(ring_locate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	locate( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_getch)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(getch());
}


RING_FUNC(ring_kbhit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(kbhit());
}


RING_FUNC(ring_gotoxy)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gotoxy( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_getkey)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(getkey());
}


RING_FUNC(ring_nb_getch)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(nb_getch());
}


RING_FUNC(ring_getANSIColor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(getANSIColor( (const int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_getANSIBgColor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(getANSIBgColor( (const int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_setColor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	setColor( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_setBackgroundColor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	setBackgroundColor( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_saveDefaultColor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(saveDefaultColor());
}


RING_FUNC(ring_resetColor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	resetColor();
}


RING_FUNC(ring_cls)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	cls();
}


RING_FUNC(ring_setString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	setString(RING_API_GETSTRING(1));
}


RING_FUNC(ring_setChar)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	setChar( (char ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_setCursorVisibility)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	setCursorVisibility( (char ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_hidecursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	hidecursor();
}


RING_FUNC(ring_showcursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	showcursor();
}


RING_FUNC(ring_msleep)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	msleep(* (unsigned int  *) RING_API_GETCPOINTER(1,"unsigned int"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"unsigned int"));
}


RING_FUNC(ring_trows)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(trows());
}


RING_FUNC(ring_tcols)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(tcols());
}


RING_FUNC(ring_anykey)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	anykey(RING_API_GETSTRING(1));
}


RING_FUNC(ring_setConsoleTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	setConsoleTitle(RING_API_GETSTRING(1));
}


RING_FUNC(ring_getUsername)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(getUsername());
}


RING_FUNC(ring_printXY)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	printXY( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}

RING_LIBINIT
{
	RING_API_REGISTER("locate",ring_locate);
	RING_API_REGISTER("getch",ring_getch);
	RING_API_REGISTER("kbhit",ring_kbhit);
	RING_API_REGISTER("gotoxy",ring_gotoxy);
	RING_API_REGISTER("getkey",ring_getkey);
	RING_API_REGISTER("nb_getch",ring_nb_getch);
	RING_API_REGISTER("getansicolor",ring_getANSIColor);
	RING_API_REGISTER("getansibgcolor",ring_getANSIBgColor);
	RING_API_REGISTER("setcolor",ring_setColor);
	RING_API_REGISTER("setbackgroundcolor",ring_setBackgroundColor);
	RING_API_REGISTER("savedefaultcolor",ring_saveDefaultColor);
	RING_API_REGISTER("resetcolor",ring_resetColor);
	RING_API_REGISTER("cls",ring_cls);
	RING_API_REGISTER("setstring",ring_setString);
	RING_API_REGISTER("setchar",ring_setChar);
	RING_API_REGISTER("setcursorvisibility",ring_setCursorVisibility);
	RING_API_REGISTER("hidecursor",ring_hidecursor);
	RING_API_REGISTER("showcursor",ring_showcursor);
	RING_API_REGISTER("msleep",ring_msleep);
	RING_API_REGISTER("trows",ring_trows);
	RING_API_REGISTER("tcols",ring_tcols);
	RING_API_REGISTER("anykey",ring_anykey);
	RING_API_REGISTER("setconsoletitle",ring_setConsoleTitle);
	RING_API_REGISTER("getusername",ring_getUsername);
	RING_API_REGISTER("printxy",ring_printXY);
	RING_API_REGISTER("get_black",ring_get_black);
	RING_API_REGISTER("get_blue",ring_get_blue);
	RING_API_REGISTER("get_green",ring_get_green);
	RING_API_REGISTER("get_cyan",ring_get_cyan);
	RING_API_REGISTER("get_red",ring_get_red);
	RING_API_REGISTER("get_magenta",ring_get_magenta);
	RING_API_REGISTER("get_brown",ring_get_brown);
	RING_API_REGISTER("get_grey",ring_get_grey);
	RING_API_REGISTER("get_darkgrey",ring_get_darkgrey);
	RING_API_REGISTER("get_lightblue",ring_get_lightblue);
	RING_API_REGISTER("get_lightgreen",ring_get_lightgreen);
	RING_API_REGISTER("get_lightcyan",ring_get_lightcyan);
	RING_API_REGISTER("get_lightred",ring_get_lightred);
	RING_API_REGISTER("get_lightmagenta",ring_get_lightmagenta);
	RING_API_REGISTER("get_yellow",ring_get_yellow);
	RING_API_REGISTER("get_white",ring_get_white);
	RING_API_REGISTER("get_key_escape",ring_get_key_escape);
	RING_API_REGISTER("get_key_enter",ring_get_key_enter);
	RING_API_REGISTER("get_key_space",ring_get_key_space);
	RING_API_REGISTER("get_key_insert",ring_get_key_insert);
	RING_API_REGISTER("get_key_home",ring_get_key_home);
	RING_API_REGISTER("get_key_pgup",ring_get_key_pgup);
	RING_API_REGISTER("get_key_delete",ring_get_key_delete);
	RING_API_REGISTER("get_key_end",ring_get_key_end);
	RING_API_REGISTER("get_key_pgdown",ring_get_key_pgdown);
	RING_API_REGISTER("get_key_up",ring_get_key_up);
	RING_API_REGISTER("get_key_down",ring_get_key_down);
	RING_API_REGISTER("get_key_left",ring_get_key_left);
	RING_API_REGISTER("get_key_right",ring_get_key_right);
	RING_API_REGISTER("get_key_f1",ring_get_key_f1);
	RING_API_REGISTER("get_key_f2",ring_get_key_f2);
	RING_API_REGISTER("get_key_f3",ring_get_key_f3);
	RING_API_REGISTER("get_key_f4",ring_get_key_f4);
	RING_API_REGISTER("get_key_f5",ring_get_key_f5);
	RING_API_REGISTER("get_key_f6",ring_get_key_f6);
	RING_API_REGISTER("get_key_f7",ring_get_key_f7);
	RING_API_REGISTER("get_key_f8",ring_get_key_f8);
	RING_API_REGISTER("get_key_f9",ring_get_key_f9);
	RING_API_REGISTER("get_key_f10",ring_get_key_f10);
	RING_API_REGISTER("get_key_f11",ring_get_key_f11);
	RING_API_REGISTER("get_key_f12",ring_get_key_f12);
	RING_API_REGISTER("get_key_numdel",ring_get_key_numdel);
	RING_API_REGISTER("get_key_numpad0",ring_get_key_numpad0);
	RING_API_REGISTER("get_key_numpad1",ring_get_key_numpad1);
	RING_API_REGISTER("get_key_numpad2",ring_get_key_numpad2);
	RING_API_REGISTER("get_key_numpad3",ring_get_key_numpad3);
	RING_API_REGISTER("get_key_numpad4",ring_get_key_numpad4);
	RING_API_REGISTER("get_key_numpad5",ring_get_key_numpad5);
	RING_API_REGISTER("get_key_numpad6",ring_get_key_numpad6);
	RING_API_REGISTER("get_key_numpad7",ring_get_key_numpad7);
	RING_API_REGISTER("get_key_numpad8",ring_get_key_numpad8);
	RING_API_REGISTER("get_key_numpad9",ring_get_key_numpad9);
}
