/* Copyright (c) 2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

#ifdef _WIN32
	#include "windows.h"
	#include "stdio.h"
#endif

RING_FUNC(ring_getmouseinfo)
{
#ifdef _WIN32

	INPUT_RECORD ir[128];
	HANDLE hStdInput  = NULL;
	HANDLE hStdOutput = NULL;

	DWORD nRead;      
	DWORD nEvents;                                          
  
	int lMouseEvent,nMouseX,nMouseY,nMouseB;
	List *pList;

	lMouseEvent = 0;

	pList = RING_API_NEWLIST ;

	hStdInput=GetStdHandle(STD_INPUT_HANDLE);
	hStdOutput=GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleMode(hStdInput,ENABLE_MOUSE_INPUT|ENABLE_EXTENDED_FLAGS);

	GetNumberOfConsoleInputEvents(hStdInput,&nEvents);

	if (nEvents > 0) {

		PeekConsoleInput(hStdInput,ir,128,&nRead);   
              
		for(size_t i=0;i<nRead;i++)                                
		{                                                          
			if (ir[i].EventType == MOUSE_EVENT)                                
			{                                                                  
				lMouseEvent = 1;                 
				nMouseX = ir[i].Event.MouseEvent.dwMousePosition.X + 1;
				nMouseY = ir[i].Event.MouseEvent.dwMousePosition.Y + 1;
				nMouseB = (int)ir[i].Event.MouseEvent.dwButtonState & 0x07 ;
			}
		}

	}

	ring_list_adddouble_gc(RING_API_STATE,pList,lMouseEvent);
	ring_list_adddouble_gc(RING_API_STATE,pList,nMouseX);
	ring_list_adddouble_gc(RING_API_STATE,pList,nMouseY);
	ring_list_adddouble_gc(RING_API_STATE,pList,nMouseB);

	RING_API_RETLIST(pList);

#endif
}