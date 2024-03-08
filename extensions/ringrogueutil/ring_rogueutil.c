#include "ring.h"

#include "rogueutil/rogueutil.h"
RING_FUNC(ring_get_key_escape)
{
	RING_API_RETNUMBER(KEY_ESCAPE);
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
	RING_API_RETSTRING(getANSIColor(* (const int  *) RING_API_GETCPOINTER(1,"const int")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"int"));
}


RING_FUNC(ring_getANSIBgColor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETSTRING(getANSIBgColor(* (const int  *) RING_API_GETCPOINTER(1,"const int")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"int"));
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
	RING_API_REGISTER("get_key_escape",ring_get_key_escape);
}
