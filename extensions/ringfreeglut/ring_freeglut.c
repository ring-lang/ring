#include "ring.h"


/*
	RingFreeGLUT Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/


#include <GL/glut.h>

char cDisplayFunction[250];

RING_FUNC(ring_get_glut_single)
{
	RING_API_RETNUMBER(GLUT_SINGLE);
}


RING_FUNC(ring_glutInit)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutInit(RING_API_GETINTPOINTER(1),(char **) RING_API_GETCPOINTER2POINTER(2,"char"));
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_glutInitDisplayMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutInitDisplayMode( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutInitWindowSize)
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
	glutInitWindowSize( (int) RING_API_GETNUMBER(1), (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutInitWindowPosition)
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
	glutInitWindowPosition( (int) RING_API_GETNUMBER(1), (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutCreateWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutCreateWindow(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glutMainLoop)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutMainLoop();
}

RING_FUNC(ring_get_gl_color_buffer_bit)
{
	RING_API_RETNUMBER(GL_COLOR_BUFFER_BIT);
}

RING_FUNC(ring_get_gl_polygon)
{
	RING_API_RETNUMBER(GL_POLYGON);
}


RING_FUNC(ring_glClear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glClear( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glColor3f)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3f( (float) RING_API_GETNUMBER(1), (float) RING_API_GETNUMBER(2), (float) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glBegin)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBegin( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glVertex3f)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex3f( (float) RING_API_GETNUMBER(1), (float) RING_API_GETNUMBER(2), (float) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glEnd)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glEnd();
}


RING_FUNC(ring_glFlush)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glFlush();
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("glutinit",ring_glutInit);
	ring_vm_funcregister("glutinitdisplaymode",ring_glutInitDisplayMode);
	ring_vm_funcregister("glutinitwindowsize",ring_glutInitWindowSize);
	ring_vm_funcregister("glutinitwindowposition",ring_glutInitWindowPosition);
	ring_vm_funcregister("glutcreatewindow",ring_glutCreateWindow);
	ring_vm_funcregister("glutmainloop",ring_glutMainLoop);
	ring_vm_funcregister("glclear",ring_glClear);
	ring_vm_funcregister("glcolor3f",ring_glColor3f);
	ring_vm_funcregister("glbegin",ring_glBegin);
	ring_vm_funcregister("glvertex3f",ring_glVertex3f);
	ring_vm_funcregister("glend",ring_glEnd);
	ring_vm_funcregister("glflush",ring_glFlush);
	ring_vm_funcregister("get_glut_single",ring_get_glut_single);
	ring_vm_funcregister("get_gl_color_buffer_bit",ring_get_gl_color_buffer_bit);
	ring_vm_funcregister("get_gl_polygon",ring_get_gl_polygon);
}
