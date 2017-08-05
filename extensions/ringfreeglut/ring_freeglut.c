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

RING_FUNC(ring_get_glut_window_x)
{
	RING_API_RETNUMBER(GLUT_WINDOW_X);
}

RING_FUNC(ring_get_glut_window_y)
{
	RING_API_RETNUMBER(GLUT_WINDOW_Y);
}

RING_FUNC(ring_get_glut_window_width)
{
	RING_API_RETNUMBER(GLUT_WINDOW_WIDTH);
}

RING_FUNC(ring_get_glut_window_height)
{
	RING_API_RETNUMBER(GLUT_WINDOW_HEIGHT);
}

RING_FUNC(ring_get_glut_window_depth_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_DEPTH_SIZE);
}

RING_FUNC(ring_get_glut_window_red_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_RED_SIZE);
}

RING_FUNC(ring_get_glut_window_green_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_GREEN_SIZE);
}

RING_FUNC(ring_get_glut_window_blue_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_BLUE_SIZE);
}

RING_FUNC(ring_get_glut_window_alpha_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ALPHA_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_red_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_RED_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_green_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_GREEN_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_blue_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_BLUE_SIZE);
}

RING_FUNC(ring_get_glut_window_accum_alpha_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_ACCUM_ALPHA_SIZE);
}

RING_FUNC(ring_get_glut_window_doublebuffer)
{
	RING_API_RETNUMBER(GLUT_WINDOW_DOUBLEBUFFER);
}

RING_FUNC(ring_get_glut_window_rgba)
{
	RING_API_RETNUMBER(GLUT_WINDOW_RGBA);
}

RING_FUNC(ring_get_glut_window_parent)
{
	RING_API_RETNUMBER(GLUT_WINDOW_PARENT);
}

RING_FUNC(ring_get_glut_window_num_children)
{
	RING_API_RETNUMBER(GLUT_WINDOW_NUM_CHILDREN);
}

RING_FUNC(ring_get_glut_window_colormap_size)
{
	RING_API_RETNUMBER(GLUT_WINDOW_COLORMAP_SIZE);
}

RING_FUNC(ring_get_glut_window_num_samples)
{
	RING_API_RETNUMBER(GLUT_WINDOW_NUM_SAMPLES);
}

RING_FUNC(ring_get_glut_window_stereo)
{
	RING_API_RETNUMBER(GLUT_WINDOW_STEREO);
}

RING_FUNC(ring_get_glut_window_cursor)
{
	RING_API_RETNUMBER(GLUT_WINDOW_CURSOR);
}

RING_FUNC(ring_get_glut_window_format_id)
{
	RING_API_RETNUMBER(GLUT_WINDOW_FORMAT_ID);
}

RING_FUNC(ring_get_glut_screen_width)
{
	RING_API_RETNUMBER(GLUT_SCREEN_WIDTH);
}

RING_FUNC(ring_get_glut_screen_height)
{
	RING_API_RETNUMBER(GLUT_SCREEN_HEIGHT);
}

RING_FUNC(ring_get_glut_screen_width_mm)
{
	RING_API_RETNUMBER(GLUT_SCREEN_WIDTH_MM);
}

RING_FUNC(ring_get_glut_screen_height_mm)
{
	RING_API_RETNUMBER(GLUT_SCREEN_HEIGHT_MM);
}

RING_FUNC(ring_get_glut_menu_num_items)
{
	RING_API_RETNUMBER(GLUT_MENU_NUM_ITEMS);
}

RING_FUNC(ring_get_glut_display_mode_possible)
{
	RING_API_RETNUMBER(GLUT_DISPLAY_MODE_POSSIBLE);
}

RING_FUNC(ring_get_glut_init_window_x)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_X);
}

RING_FUNC(ring_get_glut_init_window_y)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_Y);
}

RING_FUNC(ring_get_glut_init_window_width)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_WIDTH);
}

RING_FUNC(ring_get_glut_init_window_height)
{
	RING_API_RETNUMBER(GLUT_INIT_WINDOW_HEIGHT);
}

RING_FUNC(ring_get_glut_init_display_mode)
{
	RING_API_RETNUMBER(GLUT_INIT_DISPLAY_MODE);
}

RING_FUNC(ring_get_glut_elapsed_time)
{
	RING_API_RETNUMBER(GLUT_ELAPSED_TIME);
}

RING_FUNC(ring_get_glut_game_mode_active)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_ACTIVE);
}

RING_FUNC(ring_get_glut_game_mode_display_changed)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_DISPLAY_CHANGED);
}

RING_FUNC(ring_get_glut_game_mode_possible)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_POSSIBLE);
}

RING_FUNC(ring_get_glut_game_mode_width)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_WIDTH);
}

RING_FUNC(ring_get_glut_game_mode_height)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_HEIGHT);
}

RING_FUNC(ring_get_glut_game_mode_pixel_depth)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_PIXEL_DEPTH);
}

RING_FUNC(ring_get_glut_game_mode_refresh_rate)
{
	RING_API_RETNUMBER(GLUT_GAME_MODE_REFRESH_RATE);
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


RING_FUNC(ring_glutMainLoop)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutMainLoop();
}


RING_FUNC(ring_glutSetWindowTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetWindowTitle((char *) RING_API_GETCPOINTER(1,"char"));
}


RING_FUNC(ring_glutSetIconTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSetIconTitle((char *) RING_API_GETCPOINTER(1,"char"));
}


RING_FUNC(ring_glutFullScreen)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutFullScreen();
}


RING_FUNC(ring_glutEstablishOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutEstablishOverlay();
}


RING_FUNC(ring_glutRemoveOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutRemoveOverlay();
}


RING_FUNC(ring_glutUseLayer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutUseLayer( (GLenum)  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutPostOverlayRedisplay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutPostOverlayRedisplay();
}


RING_FUNC(ring_glutPostWindowOverlayRedisplay)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutPostWindowOverlayRedisplay( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutShowOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutShowOverlay();
}


RING_FUNC(ring_glutHideOverlay)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutHideOverlay();
}


RING_FUNC(ring_glutGet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutGet( (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glutBitmapCharacter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutBitmapCharacter((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutBitmapWidth)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutBitmapWidth((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_glutBitmapLength)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutBitmapLength((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_glutStrokeCharacter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutStrokeCharacter((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glutStrokeWidth)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeWidth((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_glutStrokeWidthf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeWidthf((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_glutStrokeLength)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeLength((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_glutStrokeLengthf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glutStrokeLengthf((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_glutWireSphere)
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
	glutWireSphere( (double ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
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
	glutSolidSphere( (double ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glutWireTorus)
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
	glutWireTorus( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutSolidTorus)
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
	glutSolidTorus( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutWireCone)
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
	glutWireCone( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
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
	glutSolidCone( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glutWireCube)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWireCube( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutSolidCube)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidCube( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutWireTetrahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireTetrahedron();
}


RING_FUNC(ring_glutSolidTetrahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidTetrahedron();
}


RING_FUNC(ring_glutWireOctahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireOctahedron();
}


RING_FUNC(ring_glutSolidOctahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidOctahedron();
}


RING_FUNC(ring_glutWireDodecahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireDodecahedron();
}


RING_FUNC(ring_glutSolidDodecahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidDodecahedron();
}


RING_FUNC(ring_glutWireIcosahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutWireIcosahedron();
}


RING_FUNC(ring_glutSolidIcosahedron)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glutSolidIcosahedron();
}


RING_FUNC(ring_glutWireTeapot)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutWireTeapot( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glutSolidTeapot)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glutSolidTeapot( (double ) RING_API_GETNUMBER(1));
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

RING_FUNC(ring_get_gl_cw)
{
	RING_API_RETNUMBER(GL_CW);
}

RING_FUNC(ring_get_gl_ccw)
{
	RING_API_RETNUMBER(GL_CCW);
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


RING_FUNC(ring_glFrontFace)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glFrontFace( (int) RING_API_GETNUMBER(1));
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
	ring_vm_funcregister("glutinitwindowsize",ring_glutInitWindowSize);
	ring_vm_funcregister("glutinitwindowposition",ring_glutInitWindowPosition);
	ring_vm_funcregister("glutmainloop",ring_glutMainLoop);
	ring_vm_funcregister("glutsetwindowtitle",ring_glutSetWindowTitle);
	ring_vm_funcregister("glutseticontitle",ring_glutSetIconTitle);
	ring_vm_funcregister("glutfullscreen",ring_glutFullScreen);
	ring_vm_funcregister("glutestablishoverlay",ring_glutEstablishOverlay);
	ring_vm_funcregister("glutremoveoverlay",ring_glutRemoveOverlay);
	ring_vm_funcregister("glutuselayer",ring_glutUseLayer);
	ring_vm_funcregister("glutpostoverlayredisplay",ring_glutPostOverlayRedisplay);
	ring_vm_funcregister("glutpostwindowoverlayredisplay",ring_glutPostWindowOverlayRedisplay);
	ring_vm_funcregister("glutshowoverlay",ring_glutShowOverlay);
	ring_vm_funcregister("gluthideoverlay",ring_glutHideOverlay);
	ring_vm_funcregister("glutget",ring_glutGet);
	ring_vm_funcregister("glutbitmapcharacter",ring_glutBitmapCharacter);
	ring_vm_funcregister("glutbitmapwidth",ring_glutBitmapWidth);
	ring_vm_funcregister("glutbitmaplength",ring_glutBitmapLength);
	ring_vm_funcregister("glutstrokecharacter",ring_glutStrokeCharacter);
	ring_vm_funcregister("glutstrokewidth",ring_glutStrokeWidth);
	ring_vm_funcregister("glutstrokewidthf",ring_glutStrokeWidthf);
	ring_vm_funcregister("glutstrokelength",ring_glutStrokeLength);
	ring_vm_funcregister("glutstrokelengthf",ring_glutStrokeLengthf);
	ring_vm_funcregister("glutwiresphere",ring_glutWireSphere);
	ring_vm_funcregister("glutsolidsphere",ring_glutSolidSphere);
	ring_vm_funcregister("glutwiretorus",ring_glutWireTorus);
	ring_vm_funcregister("glutsolidtorus",ring_glutSolidTorus);
	ring_vm_funcregister("glutwirecone",ring_glutWireCone);
	ring_vm_funcregister("glutsolidcone",ring_glutSolidCone);
	ring_vm_funcregister("glutwirecube",ring_glutWireCube);
	ring_vm_funcregister("glutsolidcube",ring_glutSolidCube);
	ring_vm_funcregister("glutwiretetrahedron",ring_glutWireTetrahedron);
	ring_vm_funcregister("glutsolidtetrahedron",ring_glutSolidTetrahedron);
	ring_vm_funcregister("glutwireoctahedron",ring_glutWireOctahedron);
	ring_vm_funcregister("glutsolidoctahedron",ring_glutSolidOctahedron);
	ring_vm_funcregister("glutwiredodecahedron",ring_glutWireDodecahedron);
	ring_vm_funcregister("glutsoliddodecahedron",ring_glutSolidDodecahedron);
	ring_vm_funcregister("glutwireicosahedron",ring_glutWireIcosahedron);
	ring_vm_funcregister("glutsolidicosahedron",ring_glutSolidIcosahedron);
	ring_vm_funcregister("glutwireteapot",ring_glutWireTeapot);
	ring_vm_funcregister("glutsolidteapot",ring_glutSolidTeapot);
	ring_vm_funcregister("glutinitdisplaymode",ring_glutInitDisplayMode);
	ring_vm_funcregister("glutcreatewindow",ring_glutCreateWindow);
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
	ring_vm_funcregister("glfrontface",ring_glFrontFace);
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
	ring_vm_funcregister("get_glut_window_x",ring_get_glut_window_x);
	ring_vm_funcregister("get_glut_window_y",ring_get_glut_window_y);
	ring_vm_funcregister("get_glut_window_width",ring_get_glut_window_width);
	ring_vm_funcregister("get_glut_window_height",ring_get_glut_window_height);
	ring_vm_funcregister("get_glut_window_depth_size",ring_get_glut_window_depth_size);
	ring_vm_funcregister("get_glut_window_red_size",ring_get_glut_window_red_size);
	ring_vm_funcregister("get_glut_window_green_size",ring_get_glut_window_green_size);
	ring_vm_funcregister("get_glut_window_blue_size",ring_get_glut_window_blue_size);
	ring_vm_funcregister("get_glut_window_alpha_size",ring_get_glut_window_alpha_size);
	ring_vm_funcregister("get_glut_window_accum_red_size",ring_get_glut_window_accum_red_size);
	ring_vm_funcregister("get_glut_window_accum_green_size",ring_get_glut_window_accum_green_size);
	ring_vm_funcregister("get_glut_window_accum_blue_size",ring_get_glut_window_accum_blue_size);
	ring_vm_funcregister("get_glut_window_accum_alpha_size",ring_get_glut_window_accum_alpha_size);
	ring_vm_funcregister("get_glut_window_doublebuffer",ring_get_glut_window_doublebuffer);
	ring_vm_funcregister("get_glut_window_rgba",ring_get_glut_window_rgba);
	ring_vm_funcregister("get_glut_window_parent",ring_get_glut_window_parent);
	ring_vm_funcregister("get_glut_window_num_children",ring_get_glut_window_num_children);
	ring_vm_funcregister("get_glut_window_colormap_size",ring_get_glut_window_colormap_size);
	ring_vm_funcregister("get_glut_window_num_samples",ring_get_glut_window_num_samples);
	ring_vm_funcregister("get_glut_window_stereo",ring_get_glut_window_stereo);
	ring_vm_funcregister("get_glut_window_cursor",ring_get_glut_window_cursor);
	ring_vm_funcregister("get_glut_window_format_id",ring_get_glut_window_format_id);
	ring_vm_funcregister("get_glut_screen_width",ring_get_glut_screen_width);
	ring_vm_funcregister("get_glut_screen_height",ring_get_glut_screen_height);
	ring_vm_funcregister("get_glut_screen_width_mm",ring_get_glut_screen_width_mm);
	ring_vm_funcregister("get_glut_screen_height_mm",ring_get_glut_screen_height_mm);
	ring_vm_funcregister("get_glut_menu_num_items",ring_get_glut_menu_num_items);
	ring_vm_funcregister("get_glut_display_mode_possible",ring_get_glut_display_mode_possible);
	ring_vm_funcregister("get_glut_init_window_x",ring_get_glut_init_window_x);
	ring_vm_funcregister("get_glut_init_window_y",ring_get_glut_init_window_y);
	ring_vm_funcregister("get_glut_init_window_width",ring_get_glut_init_window_width);
	ring_vm_funcregister("get_glut_init_window_height",ring_get_glut_init_window_height);
	ring_vm_funcregister("get_glut_init_display_mode",ring_get_glut_init_display_mode);
	ring_vm_funcregister("get_glut_elapsed_time",ring_get_glut_elapsed_time);
	ring_vm_funcregister("get_glut_game_mode_active",ring_get_glut_game_mode_active);
	ring_vm_funcregister("get_glut_game_mode_display_changed",ring_get_glut_game_mode_display_changed);
	ring_vm_funcregister("get_glut_game_mode_possible",ring_get_glut_game_mode_possible);
	ring_vm_funcregister("get_glut_game_mode_width",ring_get_glut_game_mode_width);
	ring_vm_funcregister("get_glut_game_mode_height",ring_get_glut_game_mode_height);
	ring_vm_funcregister("get_glut_game_mode_pixel_depth",ring_get_glut_game_mode_pixel_depth);
	ring_vm_funcregister("get_glut_game_mode_refresh_rate",ring_get_glut_game_mode_refresh_rate);
	ring_vm_funcregister("get_gl_color_buffer_bit",ring_get_gl_color_buffer_bit);
	ring_vm_funcregister("get_gl_depth_buffer_bit",ring_get_gl_depth_buffer_bit);
	ring_vm_funcregister("get_gl_polygon",ring_get_gl_polygon);
	ring_vm_funcregister("get_gl_triangles",ring_get_gl_triangles);
	ring_vm_funcregister("get_gl_projection",ring_get_gl_projection);
	ring_vm_funcregister("get_gl_modelview",ring_get_gl_modelview);
	ring_vm_funcregister("get_gl_quads",ring_get_gl_quads);
	ring_vm_funcregister("get_gl_depth_test",ring_get_gl_depth_test);
	ring_vm_funcregister("get_gl_cw",ring_get_gl_cw);
	ring_vm_funcregister("get_gl_ccw",ring_get_gl_ccw);
}
