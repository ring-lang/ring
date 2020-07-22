/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	SetCurrentDirectory("tools\\ringnotepad");
	ShellExecuteA(NULL, "open", "..\\..\\bin\\ringw.exe", "rnote.ring", NULL, 1);
	return 0;
}
