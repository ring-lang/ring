#include "ring.h"


/*
	RingFreeGLUT Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/


#include <GL/glut.h>

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
	ring_vm_funcregister("glclear",ring_glClear);
	ring_vm_funcregister("glcolor3f",ring_glColor3f);
	ring_vm_funcregister("glbegin",ring_glBegin);
	ring_vm_funcregister("glvertex3f",ring_glVertex3f);
	ring_vm_funcregister("glend",ring_glEnd);
	ring_vm_funcregister("glflush",ring_glFlush);
	ring_vm_funcregister("get_gl_color_buffer_bit",ring_get_gl_color_buffer_bit);
	ring_vm_funcregister("get_gl_polygon",ring_get_gl_polygon);
}
