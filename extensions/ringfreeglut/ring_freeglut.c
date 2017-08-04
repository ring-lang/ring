#include "ring.h"


/*
	RingFreeGLUT Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/


#include <GL/glut.h>

char cDisplayFunction[250];
char cReshapeFunction[250];
int nReshapeWidth ;
int nReshapeHeight ;
VM *pRingVMObject ;


RING_FUNC(ring_glutInit)
{
	VM *pVM ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	pVM = (VM *) pPointer ;
	glutInit( & pVM->pRingState->argc, pVM->pRingState->argv);
}

void displayFunction(void)
{
	ring_vm_runcode(pRingVMObject,cDisplayFunction) ;
}

RING_FUNC(ring_glutDisplayFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cDisplayFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutDisplayFunc(displayFunction);
	}
}

void reshapeFunction(int w, int h)
{
	nReshapeWidth = w;
	nReshapeHeight = h ;
	ring_vm_runcode(pRingVMObject,cReshapeFunction) ;
}

RING_FUNC(ring_glutReshapeFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cReshapeFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutReshapeFunc(reshapeFunction);
	}
}

RING_FUNC(ring_glutReshapeWidth)
{
	RING_API_RETNUMBER(nReshapeWidth);
}

RING_FUNC(ring_glutReshapeHeight)
{
	RING_API_RETNUMBER(nReshapeHeight);
}

RING_FUNC(ring_get_glut_single)
{
	RING_API_RETNUMBER(GLUT_SINGLE);
}

RING_FUNC(ring_get_glut_depth)
{
	RING_API_RETNUMBER(GLUT_DEPTH);
}

RING_FUNC(ring_get_glut_double)
{
	RING_API_RETNUMBER(GLUT_DOUBLE);
}

RING_FUNC(ring_get_glut_rgba)
{
	RING_API_RETNUMBER(GLUT_RGBA);
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

RING_FUNC(ring_get_gl_depth_buffer_bit)
{
	RING_API_RETNUMBER(GL_DEPTH_BUFFER_BIT);
}

RING_FUNC(ring_get_gl_polygon)
{
	RING_API_RETNUMBER(GL_POLYGON);
}

RING_FUNC(ring_get_gl_triangles)
{
	RING_API_RETNUMBER(GL_TRIANGLES);
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


RING_FUNC(ring_glutSwapBuffers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSwapBuffers();
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("glutinit",ring_glutInit);
	ring_vm_funcregister("glutdisplayfunc",ring_glutDisplayFunc);
	ring_vm_funcregister("glutreshapefunc",ring_glutReshapeFunc);
	ring_vm_funcregister("glutreshapewidth",ring_glutReshapeWidth);
	ring_vm_funcregister("glutreshapeheight",ring_glutReshapeHeight);
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
	ring_vm_funcregister("glutswapbuffers",ring_glutSwapBuffers);
	ring_vm_funcregister("get_glut_single",ring_get_glut_single);
	ring_vm_funcregister("get_glut_depth",ring_get_glut_depth);
	ring_vm_funcregister("get_glut_double",ring_get_glut_double);
	ring_vm_funcregister("get_glut_rgba",ring_get_glut_rgba);
	ring_vm_funcregister("get_gl_color_buffer_bit",ring_get_gl_color_buffer_bit);
	ring_vm_funcregister("get_gl_depth_buffer_bit",ring_get_gl_depth_buffer_bit);
	ring_vm_funcregister("get_gl_polygon",ring_get_gl_polygon);
	ring_vm_funcregister("get_gl_triangles",ring_get_gl_triangles);
}
