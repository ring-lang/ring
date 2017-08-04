#include "ring.h"


/*
	RingFreeGLUT Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/


#include <GL/glut.h>


VM *pRingVMObject ;
char cDisplayFunction[250];
char cReshapeFunction[250];
int nReshapeWidth ;
int nReshapeHeight ;
char cIdleFunction[250];
char cKeyboardFunction[250];
char cSpecialFunction[250];
int nGLUTEventKey ;
int nGLUTEventX ;
int nGLUTEventY ;


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

void IdleFunction(void)
{
	ring_vm_runcode(pRingVMObject,cIdleFunction) ;
}

RING_FUNC(ring_glutIdleFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cIdleFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutIdleFunc(IdleFunction);
	}
}

void KeyboardFunction(unsigned char key, int x, int y)
{
	nGLUTEventKey = (int) key ;
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_runcode(pRingVMObject,cKeyboardFunction) ;
}

RING_FUNC(ring_glutKeyboardFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cKeyboardFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutKeyboardFunc(KeyboardFunction);
	}
}

void SpecialFunction(int key, int x, int y)
{
	nGLUTEventKey = key ;
	nGLUTEventX = x ;
	nGLUTEventY = y ;
	ring_vm_runcode(pRingVMObject,cSpecialFunction) ;
}

RING_FUNC(ring_glutSpecialFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		strcpy(cSpecialFunction, RING_API_GETSTRING(1) ) ;
		pRingVMObject = (VM *) pPointer ;
		glutSpecialFunc(SpecialFunction);
	}
}

RING_FUNC(ring_glutEventKey) {
	RING_API_RETNUMBER(nGLUTEventKey);
}

RING_FUNC(ring_glutEventX) {
	RING_API_RETNUMBER(nGLUTEventX);
}

RING_FUNC(ring_glutEventY) {
	RING_API_RETNUMBER(nGLUTEventY);
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

RING_FUNC(ring_get_glut_key_f1)
{
	RING_API_RETNUMBER(GLUT_KEY_F1);
}

RING_FUNC(ring_get_glut_key_f2)
{
	RING_API_RETNUMBER(GLUT_KEY_F2);
}

RING_FUNC(ring_get_glut_key_f3)
{
	RING_API_RETNUMBER(GLUT_KEY_F3);
}

RING_FUNC(ring_get_glut_key_left)
{
	RING_API_RETNUMBER(GLUT_KEY_LEFT);
}

RING_FUNC(ring_get_glut_key_right)
{
	RING_API_RETNUMBER(GLUT_KEY_RIGHT);
}

RING_FUNC(ring_get_glut_key_up)
{
	RING_API_RETNUMBER(GLUT_KEY_UP);
}

RING_FUNC(ring_get_glut_key_down)
{
	RING_API_RETNUMBER(GLUT_KEY_DOWN);
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


RING_FUNC(ring_glutSolidSphere)
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
	glutSolidSphere( (double) RING_API_GETNUMBER(1), (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glutSolidCone)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidCone( (double) RING_API_GETNUMBER(1), (double) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3), (int) RING_API_GETNUMBER(4));
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

RING_FUNC(ring_get_gl_projection)
{
	RING_API_RETNUMBER(GL_PROJECTION);
}

RING_FUNC(ring_get_gl_modelview)
{
	RING_API_RETNUMBER(GL_MODELVIEW);
}

RING_FUNC(ring_get_gl_quads)
{
	RING_API_RETNUMBER(GL_QUADS);
}

RING_FUNC(ring_get_gl_depth_test)
{
	RING_API_RETNUMBER(GL_DEPTH_TEST);
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
	glClear( (GLbitfield)  (int) RING_API_GETNUMBER(1));
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


RING_FUNC(ring_glMatrixMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glMatrixMode( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glLoadIdentity)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glLoadIdentity();
}


RING_FUNC(ring_glViewport)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glViewport( (int) RING_API_GETNUMBER(1), (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3), (int) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_gluPerspective)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gluPerspective( (int) RING_API_GETNUMBER(1), (float) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3), (int) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_gluLookAt)
{
	if ( RING_API_PARACOUNT != 9 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gluLookAt( (float) RING_API_GETNUMBER(1), (float) RING_API_GETNUMBER(2), (float) RING_API_GETNUMBER(3), (float) RING_API_GETNUMBER(4), (float) RING_API_GETNUMBER(5), (float) RING_API_GETNUMBER(6), (float) RING_API_GETNUMBER(7), (float) RING_API_GETNUMBER(8), (float) RING_API_GETNUMBER(9));
}


RING_FUNC(ring_glRotatef)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRotatef( (float) RING_API_GETNUMBER(1), (float) RING_API_GETNUMBER(2), (float) RING_API_GETNUMBER(3), (float) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glTranslatef)
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
	glTranslatef( (float) RING_API_GETNUMBER(1), (float) RING_API_GETNUMBER(2), (float) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glPushMatrix)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glPushMatrix();
}


RING_FUNC(ring_glPopMatrix)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glPopMatrix();
}


RING_FUNC(ring_glEnable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEnable( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDisable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDisable( (int) RING_API_GETNUMBER(1));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("glutinit",ring_glutInit);
	ring_vm_funcregister("glutdisplayfunc",ring_glutDisplayFunc);
	ring_vm_funcregister("glutreshapefunc",ring_glutReshapeFunc);
	ring_vm_funcregister("glutreshapewidth",ring_glutReshapeWidth);
	ring_vm_funcregister("glutreshapeheight",ring_glutReshapeHeight);
	ring_vm_funcregister("glutidlefunc",ring_glutIdleFunc);
	ring_vm_funcregister("glutkeyboardfunc",ring_glutKeyboardFunc);
	ring_vm_funcregister("glutspecialfunc",ring_glutSpecialFunc);
	ring_vm_funcregister("gluteventkey",ring_glutEventKey);
	ring_vm_funcregister("gluteventx",ring_glutEventX);
	ring_vm_funcregister("gluteventy",ring_glutEventY);
	ring_vm_funcregister("glutinitdisplaymode",ring_glutInitDisplayMode);
	ring_vm_funcregister("glutinitwindowsize",ring_glutInitWindowSize);
	ring_vm_funcregister("glutinitwindowposition",ring_glutInitWindowPosition);
	ring_vm_funcregister("glutcreatewindow",ring_glutCreateWindow);
	ring_vm_funcregister("glutmainloop",ring_glutMainLoop);
	ring_vm_funcregister("glutsolidsphere",ring_glutSolidSphere);
	ring_vm_funcregister("glutsolidcone",ring_glutSolidCone);
	ring_vm_funcregister("glclear",ring_glClear);
	ring_vm_funcregister("glcolor3f",ring_glColor3f);
	ring_vm_funcregister("glbegin",ring_glBegin);
	ring_vm_funcregister("glvertex3f",ring_glVertex3f);
	ring_vm_funcregister("glend",ring_glEnd);
	ring_vm_funcregister("glflush",ring_glFlush);
	ring_vm_funcregister("glutswapbuffers",ring_glutSwapBuffers);
	ring_vm_funcregister("glmatrixmode",ring_glMatrixMode);
	ring_vm_funcregister("glloadidentity",ring_glLoadIdentity);
	ring_vm_funcregister("glviewport",ring_glViewport);
	ring_vm_funcregister("gluperspective",ring_gluPerspective);
	ring_vm_funcregister("glulookat",ring_gluLookAt);
	ring_vm_funcregister("glrotatef",ring_glRotatef);
	ring_vm_funcregister("gltranslatef",ring_glTranslatef);
	ring_vm_funcregister("glpushmatrix",ring_glPushMatrix);
	ring_vm_funcregister("glpopmatrix",ring_glPopMatrix);
	ring_vm_funcregister("glenable",ring_glEnable);
	ring_vm_funcregister("gldisable",ring_glDisable);
	ring_vm_funcregister("get_glut_single",ring_get_glut_single);
	ring_vm_funcregister("get_glut_depth",ring_get_glut_depth);
	ring_vm_funcregister("get_glut_double",ring_get_glut_double);
	ring_vm_funcregister("get_glut_rgba",ring_get_glut_rgba);
	ring_vm_funcregister("get_glut_key_f1",ring_get_glut_key_f1);
	ring_vm_funcregister("get_glut_key_f2",ring_get_glut_key_f2);
	ring_vm_funcregister("get_glut_key_f3",ring_get_glut_key_f3);
	ring_vm_funcregister("get_glut_key_left",ring_get_glut_key_left);
	ring_vm_funcregister("get_glut_key_right",ring_get_glut_key_right);
	ring_vm_funcregister("get_glut_key_up",ring_get_glut_key_up);
	ring_vm_funcregister("get_glut_key_down",ring_get_glut_key_down);
	ring_vm_funcregister("get_gl_color_buffer_bit",ring_get_gl_color_buffer_bit);
	ring_vm_funcregister("get_gl_depth_buffer_bit",ring_get_gl_depth_buffer_bit);
	ring_vm_funcregister("get_gl_polygon",ring_get_gl_polygon);
	ring_vm_funcregister("get_gl_triangles",ring_get_gl_triangles);
	ring_vm_funcregister("get_gl_projection",ring_get_gl_projection);
	ring_vm_funcregister("get_gl_modelview",ring_get_gl_modelview);
	ring_vm_funcregister("get_gl_quads",ring_get_gl_quads);
	ring_vm_funcregister("get_gl_depth_test",ring_get_gl_depth_test);
}
