#include "ring.h"


/*
	OpenGL 2.1 Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/


#include <GL/glew.h>
#include <GL/glut.h>


RING_FUNC(ring_glAccum)
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
	glAccum( (GLenum )  (int) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glActiveTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glActiveTexture( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glAlphaFunc)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glAlphaFunc( (GLenum )  (int) RING_API_GETNUMBER(1),* (GLclampf  *) RING_API_GETCPOINTER(2,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLclampf"));
}


RING_FUNC(ring_glAreTexturesResident)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glAreTexturesResident( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"),(GLboolean *) RING_API_GETCPOINTER(3,"GLboolean")));
}


RING_FUNC(ring_glArrayElement)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glArrayElement( (GLint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glAttachShader)
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
	glAttachShader( (GLuint ) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2));
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
	glBegin( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glBeginQuery)
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
	glBeginQuery( (GLenum )  (int) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glBindAttribLocation)
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
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBindAttribLocation( (GLuint ) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2),(GLchar *) RING_API_GETCPOINTER(3,"GLchar"));
}


RING_FUNC(ring_glBindBuffer)
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
	glBindBuffer( (GLenum )  (int) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glBindTexture)
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
	glBindTexture( (GLenum )  (int) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glBitmap)
{
	if ( RING_API_PARACOUNT != 7 ) {
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
	if ( ! RING_API_ISPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBitmap( (GLsizei )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4), (GLfloat ) RING_API_GETNUMBER(5), (GLfloat ) RING_API_GETNUMBER(6),(GLubyte *) RING_API_GETCPOINTER(7,"GLubyte"));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("glaccum",ring_glAccum);
	ring_vm_funcregister("glactivetexture",ring_glActiveTexture);
	ring_vm_funcregister("glalphafunc",ring_glAlphaFunc);
	ring_vm_funcregister("glaretexturesresident",ring_glAreTexturesResident);
	ring_vm_funcregister("glarrayelement",ring_glArrayElement);
	ring_vm_funcregister("glattachshader",ring_glAttachShader);
	ring_vm_funcregister("glbegin",ring_glBegin);
	ring_vm_funcregister("glbeginquery",ring_glBeginQuery);
	ring_vm_funcregister("glbindattriblocation",ring_glBindAttribLocation);
	ring_vm_funcregister("glbindbuffer",ring_glBindBuffer);
	ring_vm_funcregister("glbindtexture",ring_glBindTexture);
	ring_vm_funcregister("glbitmap",ring_glBitmap);
}
