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


RING_FUNC(ring_glBlendColor)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	glBlendColor(* (GLclampf  *) RING_API_GETCPOINTER(1,"GLclampf"),* (GLclampf  *) RING_API_GETCPOINTER(2,"GLclampf"),* (GLclampf  *) RING_API_GETCPOINTER(3,"GLclampf"),* (GLclampf  *) RING_API_GETCPOINTER(4,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		free(RING_API_GETCPOINTER(4,"GLclampf"));
}


RING_FUNC(ring_glBlendEquation)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBlendEquation( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glBlendEquationSeparate)
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
	glBlendEquationSeparate( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glBlendFunc)
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
	glBlendFunc( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glBlendFuncSeparate)
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
	glBlendFuncSeparate( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glBufferData)
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
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBufferData( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizeiptr ) RING_API_GETNUMBER(2),(GLvoid *) RING_API_GETCPOINTER(3,"GLvoid"), (GLenum )  (int) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glBufferSubData)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBufferSubData( (GLenum )  (int) RING_API_GETNUMBER(1), (GLintptr ) RING_API_GETNUMBER(2), (GLsizeiptr ) RING_API_GETNUMBER(3),(GLvoid *) RING_API_GETCPOINTER(4,"GLvoid"));
}


RING_FUNC(ring_glCallList)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCallList( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glCallLists)
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
	glCallLists( (GLsizei )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLvoid *) RING_API_GETCPOINTER(3,"GLvoid"));
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
	glClear( (GLbitfield )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glClearAccum)
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
	glClearAccum( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glClearColor)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	glClearColor(* (GLclampf  *) RING_API_GETCPOINTER(1,"GLclampf"),* (GLclampf  *) RING_API_GETCPOINTER(2,"GLclampf"),* (GLclampf  *) RING_API_GETCPOINTER(3,"GLclampf"),* (GLclampf  *) RING_API_GETCPOINTER(4,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLclampf"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		free(RING_API_GETCPOINTER(4,"GLclampf"));
}


RING_FUNC(ring_glClearDepth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	glClearDepth(* (GLclampd  *) RING_API_GETCPOINTER(1,"GLclampd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLclampd"));
}


RING_FUNC(ring_glClearIndex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glClearIndex( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glClearStencil)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glClearStencil( (GLint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glClientActiveTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glClientActiveTexture( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glClipPlane)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glClipPlane( (GLenum )  (int) RING_API_GETNUMBER(1),(GLdouble *) RING_API_GETCPOINTER(2,"GLdouble"));
}


RING_FUNC(ring_glColor3b)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	glColor3b(* (GLbyte  *) RING_API_GETCPOINTER(1,"GLbyte"),* (GLbyte  *) RING_API_GETCPOINTER(2,"GLbyte"),* (GLbyte  *) RING_API_GETCPOINTER(3,"GLbyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLbyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLbyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLbyte"));
}


RING_FUNC(ring_glColor3s)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	glColor3s(* (GLshort  *) RING_API_GETCPOINTER(1,"GLshort"),* (GLshort  *) RING_API_GETCPOINTER(2,"GLshort"),* (GLshort  *) RING_API_GETCPOINTER(3,"GLshort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLshort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLshort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLshort"));
}


RING_FUNC(ring_glColor3i)
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
	glColor3i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
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
	glColor3f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glColor3d)
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
	glColor3d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glColor3ub)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	glColor3ub(* (GLubyte  *) RING_API_GETCPOINTER(1,"GLubyte"),* (GLubyte  *) RING_API_GETCPOINTER(2,"GLubyte"),* (GLubyte  *) RING_API_GETCPOINTER(3,"GLubyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLubyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLubyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLubyte"));
}


RING_FUNC(ring_glColor3us)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	glColor3us(* (GLushort  *) RING_API_GETCPOINTER(1,"GLushort"),* (GLushort  *) RING_API_GETCPOINTER(2,"GLushort"),* (GLushort  *) RING_API_GETCPOINTER(3,"GLushort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLushort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLushort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLushort"));
}


RING_FUNC(ring_glColor3ui)
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
	glColor3ui( (GLuint ) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2), (GLuint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glColor4b)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	glColor4b(* (GLbyte  *) RING_API_GETCPOINTER(1,"GLbyte"),* (GLbyte  *) RING_API_GETCPOINTER(2,"GLbyte"),* (GLbyte  *) RING_API_GETCPOINTER(3,"GLbyte"),* (GLbyte  *) RING_API_GETCPOINTER(4,"GLbyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLbyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLbyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLbyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		free(RING_API_GETCPOINTER(4,"GLbyte"));
}


RING_FUNC(ring_glColor4s)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	glColor4s(* (GLshort  *) RING_API_GETCPOINTER(1,"GLshort"),* (GLshort  *) RING_API_GETCPOINTER(2,"GLshort"),* (GLshort  *) RING_API_GETCPOINTER(3,"GLshort"),* (GLshort  *) RING_API_GETCPOINTER(4,"GLshort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLshort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLshort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLshort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		free(RING_API_GETCPOINTER(4,"GLshort"));
}


RING_FUNC(ring_glColor4i)
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
	glColor4i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor4f)
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
	glColor4f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor4d)
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
	glColor4d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor4ub)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	glColor4ub(* (GLubyte  *) RING_API_GETCPOINTER(1,"GLubyte"),* (GLubyte  *) RING_API_GETCPOINTER(2,"GLubyte"),* (GLubyte  *) RING_API_GETCPOINTER(3,"GLubyte"),* (GLubyte  *) RING_API_GETCPOINTER(4,"GLubyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLubyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLubyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLubyte"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		free(RING_API_GETCPOINTER(4,"GLubyte"));
}


RING_FUNC(ring_glColor4us)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	glColor4us(* (GLushort  *) RING_API_GETCPOINTER(1,"GLushort"),* (GLushort  *) RING_API_GETCPOINTER(2,"GLushort"),* (GLushort  *) RING_API_GETCPOINTER(3,"GLushort"),* (GLushort  *) RING_API_GETCPOINTER(4,"GLushort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLushort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLushort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"GLushort"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		free(RING_API_GETCPOINTER(4,"GLushort"));
}


RING_FUNC(ring_glColor4ui)
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
	glColor4ui( (GLuint ) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2), (GLuint ) RING_API_GETNUMBER(3), (GLuint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor3bv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3bv((GLbyte *) RING_API_GETCPOINTER(1,"GLbyte"));
}


RING_FUNC(ring_glColor3sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glColor3iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glColor3fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glColor3dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glColor3ubv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3ubv((GLubyte *) RING_API_GETCPOINTER(1,"GLubyte"));
}


RING_FUNC(ring_glColor3usv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3usv((GLushort *) RING_API_GETCPOINTER(1,"GLushort"));
}


RING_FUNC(ring_glColor3uiv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3uiv((GLuint *) RING_API_GETCPOINTER(1,"GLuint"));
}


RING_FUNC(ring_glColor4bv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4bv((GLbyte *) RING_API_GETCPOINTER(1,"GLbyte"));
}


RING_FUNC(ring_glColor4sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glColor4iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glColor4fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glColor4dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glColor4ubv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4ubv((GLubyte *) RING_API_GETCPOINTER(1,"GLubyte"));
}


RING_FUNC(ring_glColor4usv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4usv((GLushort *) RING_API_GETCPOINTER(1,"GLushort"));
}


RING_FUNC(ring_glColor4uiv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4uiv((GLuint *) RING_API_GETCPOINTER(1,"GLuint"));
}


RING_FUNC(ring_glColorMask)
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
	glColorMask( (GLboolean ) RING_API_GETNUMBER(1), (GLboolean ) RING_API_GETNUMBER(2), (GLboolean ) RING_API_GETNUMBER(3), (GLboolean ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColorMaterial)
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
	glColorMaterial( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glColorPointer)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColorPointer( (GLint ) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3),(GLvoid *) RING_API_GETCPOINTER(4,"GLvoid"));
}


RING_FUNC(ring_glColorSubTable)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	if ( ! RING_API_ISPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColorSubTable( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5),(GLvoid *) RING_API_GETCPOINTER(6,"GLvoid"));
}


RING_FUNC(ring_glColorTable)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	if ( ! RING_API_ISPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColorTable( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5),(GLvoid *) RING_API_GETCPOINTER(6,"GLvoid"));
}


RING_FUNC(ring_glColorTableParameterfv)
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
	glColorTableParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glColorTableParameteriv)
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
	glColorTableParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glCompileShader)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCompileShader( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glCompressedTexImage1D)
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
	glCompressedTexImage1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6),(GLvoid *) RING_API_GETCPOINTER(7,"GLvoid"));
}


RING_FUNC(ring_glCompressedTexImage2D)
{
	if ( RING_API_PARACOUNT != 8 ) {
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
	if ( ! RING_API_ISPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCompressedTexImage2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5), (GLint ) RING_API_GETNUMBER(6), (GLsizei )  (int) RING_API_GETNUMBER(7),(GLvoid *) RING_API_GETCPOINTER(8,"GLvoid"));
}


RING_FUNC(ring_glCompressedTexImage3D)
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
	if ( ! RING_API_ISPOINTER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCompressedTexImage3D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6), (GLint ) RING_API_GETNUMBER(7), (GLsizei )  (int) RING_API_GETNUMBER(8),(GLvoid *) RING_API_GETCPOINTER(9,"GLvoid"));
}


RING_FUNC(ring_glCompressedTexSubImage1D)
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
	glCompressedTexSubImage1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6),(GLvoid *) RING_API_GETCPOINTER(7,"GLvoid"));
}


RING_FUNC(ring_glCompressedTexSubImage2D)
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
	if ( ! RING_API_ISPOINTER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCompressedTexSubImage2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6), (GLenum )  (int) RING_API_GETNUMBER(7), (GLsizei )  (int) RING_API_GETNUMBER(8),(GLvoid *) RING_API_GETCPOINTER(9,"GLvoid"));
}


RING_FUNC(ring_glCompressedTexSubImage3D)
{
	if ( RING_API_PARACOUNT != 11 ) {
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
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(11) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCompressedTexSubImage3D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6), (GLsizei )  (int) RING_API_GETNUMBER(7), (GLsizei )  (int) RING_API_GETNUMBER(8), (GLenum )  (int) RING_API_GETNUMBER(9), (GLsizei )  (int) RING_API_GETNUMBER(10),(GLvoid *) RING_API_GETCPOINTER(11,"GLvoid"));
}


RING_FUNC(ring_glConvolutionFilter1D)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	if ( ! RING_API_ISPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glConvolutionFilter1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5),(GLvoid *) RING_API_GETCPOINTER(6,"GLvoid"));
}


RING_FUNC(ring_glConvolutionFilter2D)
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
	glConvolutionFilter2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5), (GLenum )  (int) RING_API_GETNUMBER(6),(GLvoid *) RING_API_GETCPOINTER(7,"GLvoid"));
}


RING_FUNC(ring_glConvolutionParameterf)
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
	glConvolutionParameterf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glConvolutionParameteri)
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
	glConvolutionParameteri( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glConvolutionParameterfv)
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
	glConvolutionParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glConvolutionParameteriv)
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
	glConvolutionParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glCopyColorSubTable)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	glCopyColorSubTable( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_glCopyColorTable)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	glCopyColorTable( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_glCopyConvolutionFilter1D)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	glCopyConvolutionFilter1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_glCopyConvolutionFilter2D)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	glCopyConvolutionFilter2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_glCopyPixels)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	glCopyPixels( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_glCopyTexImage1D)
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
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCopyTexImage1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6), (GLint ) RING_API_GETNUMBER(7));
}


RING_FUNC(ring_glCopyTexImage2D)
{
	if ( RING_API_PARACOUNT != 8 ) {
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
	glCopyTexImage2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6), (GLsizei )  (int) RING_API_GETNUMBER(7), (GLint ) RING_API_GETNUMBER(8));
}


RING_FUNC(ring_glCopyTexSubImage1D)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	glCopyTexSubImage1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_glCopyTexSubImage2D)
{
	if ( RING_API_PARACOUNT != 8 ) {
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
	glCopyTexSubImage2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLint ) RING_API_GETNUMBER(6), (GLsizei )  (int) RING_API_GETNUMBER(7), (GLsizei )  (int) RING_API_GETNUMBER(8));
}


RING_FUNC(ring_glCopyTexSubImage3D)
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
	glCopyTexSubImage3D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLint ) RING_API_GETNUMBER(6), (GLint ) RING_API_GETNUMBER(7), (GLsizei )  (int) RING_API_GETNUMBER(8), (GLsizei )  (int) RING_API_GETNUMBER(9));
}


RING_FUNC(ring_glCreateProgram)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glCreateProgram());
}


RING_FUNC(ring_glCreateShader)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glCreateShader( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glCullFace)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCullFace( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDeleteBuffers)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glDeleteBuffers( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glDeleteLists)
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
	glDeleteLists( (GLuint ) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glDeleteProgram)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDeleteProgram( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDeleteQueries)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glDeleteQueries( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glDeleteShader)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDeleteShader( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDeleteTextures)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glDeleteTextures( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glDepthFunc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDepthFunc( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDepthMask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDepthMask( (GLboolean ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDepthRange)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	glDepthRange(* (GLclampd  *) RING_API_GETCPOINTER(1,"GLclampd"),* (GLclampd  *) RING_API_GETCPOINTER(2,"GLclampd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"GLclampd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"GLclampd"));
}


RING_FUNC(ring_glDetachShader)
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
	glDetachShader( (GLuint ) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2));
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
	glEnable( (GLenum  )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glEnableClientState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEnableClientState( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glEnableVertexAttribArray)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEnableVertexAttribArray( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDisableVertexAttribArray)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDisableVertexAttribArray( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDrawArrays)
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
	glDrawArrays( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glDrawBuffer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDrawBuffer( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDrawBuffers)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glDrawBuffers( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLenum *) RING_API_GETCPOINTER(2,"GLenum"));
}


RING_FUNC(ring_glDrawElements)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDrawElements( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3),(GLvoid *) RING_API_GETCPOINTER(4,"GLvoid"));
}


RING_FUNC(ring_glDrawPixels)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDrawPixels( (GLsizei )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4),(GLvoid *) RING_API_GETCPOINTER(5,"GLvoid"));
}


RING_FUNC(ring_glDrawRangeElements)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	if ( ! RING_API_ISPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDrawRangeElements( (GLenum )  (int) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2), (GLuint ) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5),(GLvoid *) RING_API_GETCPOINTER(6,"GLvoid"));
}


RING_FUNC(ring_glEdgeFlag)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEdgeFlag( (GLboolean ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glEdgeFlagPointer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glEdgeFlagPointer( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLvoid *) RING_API_GETCPOINTER(2,"GLvoid"));
}


RING_FUNC(ring_glEnd)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glEnd();
}


RING_FUNC(ring_glEndList)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glEndList();
}


RING_FUNC(ring_glEndQuery)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEndQuery( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glEvalCoord1f)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEvalCoord1f( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glEvalCoord1d)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEvalCoord1d( (GLdouble ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glEvalCoord2f)
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
	glEvalCoord2f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glEvalCoord2d)
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
	glEvalCoord2d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glEvalMesh1)
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
	glEvalMesh1( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glEvalPoint1)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEvalPoint1( (GLint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glEvalPoint2)
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
	glEvalPoint2( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glFeedbackBuffer)
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
	glFeedbackBuffer( (GLsizei )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glFinish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glFinish();
}


RING_FUNC(ring_glFlush)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glFlush();
}


RING_FUNC(ring_glFogf)
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
	glFogf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glFogi)
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
	glFogi( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glFogfv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glFogfv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLfloat *) RING_API_GETCPOINTER(2,"GLfloat"));
}


RING_FUNC(ring_glFogiv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glFogiv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLint *) RING_API_GETCPOINTER(2,"GLint"));
}


RING_FUNC(ring_glFogCoordd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glFogCoordd( (GLdouble ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glFogCoordf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glFogCoordf( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glFogCoorddv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glFogCoorddv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glFogCoordfv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glFogCoordfv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glFogCoordPointer)
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
	glFogCoordPointer( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(GLvoid *) RING_API_GETCPOINTER(3,"GLvoid"));
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
	glFrontFace( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glFrustum)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	glFrustum( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4), (GLdouble ) RING_API_GETNUMBER(5), (GLdouble ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_glGenBuffers)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGenBuffers( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glGenLists)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glGenLists( (GLsizei )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glGenQueries)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGenQueries( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glGenTextures)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGenTextures( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glGetBooleanv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGetBooleanv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLboolean *) RING_API_GETCPOINTER(2,"GLboolean"));
}


RING_FUNC(ring_glGetDoublev)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGetDoublev( (GLenum )  (int) RING_API_GETNUMBER(1),(GLdouble *) RING_API_GETCPOINTER(2,"GLdouble"));
}


RING_FUNC(ring_glGetFloatv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGetFloatv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLfloat *) RING_API_GETCPOINTER(2,"GLfloat"));
}


RING_FUNC(ring_glGetIntegerv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGetIntegerv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLint *) RING_API_GETCPOINTER(2,"GLint"));
}


RING_FUNC(ring_glGetActiveAttrib)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetActiveAttrib( (GLuint ) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3),(GLsizei *) RING_API_GETCPOINTER(4,"GLsizei"),(GLint *) RING_API_GETCPOINTER(5,"GLint"),(GLenum *) RING_API_GETCPOINTER(6,"GLenum"),(GLchar *) RING_API_GETCPOINTER(7,"GLchar"));
}


RING_FUNC(ring_glGetActiveUniform)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetActiveUniform( (GLuint ) RING_API_GETNUMBER(1), (GLuint ) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3),(GLsizei *) RING_API_GETCPOINTER(4,"GLsizei"),(GLint *) RING_API_GETCPOINTER(5,"GLint"),(GLenum *) RING_API_GETCPOINTER(6,"GLenum"),(GLchar *) RING_API_GETCPOINTER(7,"GLchar"));
}


RING_FUNC(ring_glGetAttachedShaders)
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
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetAttachedShaders( (GLuint ) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(GLsizei *) RING_API_GETCPOINTER(3,"GLsizei"),(GLuint *) RING_API_GETCPOINTER(4,"GLuint"));
}


RING_FUNC(ring_glGetAttribLocation)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(glGetAttribLocation( (GLuint ) RING_API_GETNUMBER(1),(GLchar *) RING_API_GETCPOINTER(2,"GLchar")));
}


RING_FUNC(ring_glGetBufferParameteriv)
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
	glGetBufferParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetBufferPointerv)
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
	glGetBufferPointerv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLvoid **) RING_API_GETCPOINTER2POINTER(3,"GLvoid"));
}


RING_FUNC(ring_glGetBufferSubData)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetBufferSubData( (GLenum )  (int) RING_API_GETNUMBER(1), (GLintptr ) RING_API_GETNUMBER(2), (GLsizeiptr ) RING_API_GETNUMBER(3),(GLvoid *) RING_API_GETCPOINTER(4,"GLvoid"));
}


RING_FUNC(ring_glGetClipPlane)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	glGetClipPlane( (GLenum )  (int) RING_API_GETNUMBER(1),(GLdouble *) RING_API_GETCPOINTER(2,"GLdouble"));
}


RING_FUNC(ring_glGetColorTable)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetColorTable( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3),(GLvoid *) RING_API_GETCPOINTER(4,"GLvoid"));
}


RING_FUNC(ring_glGetColorTableParameterfv)
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
	glGetColorTableParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetColorTableParameteriv)
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
	glGetColorTableParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetCompressedTexImage)
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
	glGetCompressedTexImage( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2),(GLvoid *) RING_API_GETCPOINTER(3,"GLvoid"));
}


RING_FUNC(ring_glGetConvolutionFilter)
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
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetConvolutionFilter( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3),(GLvoid *) RING_API_GETCPOINTER(4,"GLvoid"));
}


RING_FUNC(ring_glGetConvolutionParameterfv)
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
	glGetConvolutionParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetConvolutionParameteriv)
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
	glGetConvolutionParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetError)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glGetError());
}


RING_FUNC(ring_glGetHistogram)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetHistogram( (GLenum )  (int) RING_API_GETNUMBER(1), (GLboolean ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4),(GLvoid *) RING_API_GETCPOINTER(5,"GLvoid"));
}


RING_FUNC(ring_glGetHistogramParameterfv)
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
	glGetHistogramParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetHistogramParameteriv)
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
	glGetHistogramParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetLightfv)
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
	glGetLightfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetLightiv)
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
	glGetLightiv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetMapdv)
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
	glGetMapdv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLdouble *) RING_API_GETCPOINTER(3,"GLdouble"));
}


RING_FUNC(ring_glGetMapfv)
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
	glGetMapfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetMapiv)
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
	glGetMapiv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetMaterialfv)
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
	glGetMaterialfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetMaterialiv)
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
	glGetMaterialiv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetMinmax)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetMinmax( (GLenum )  (int) RING_API_GETNUMBER(1), (GLboolean ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4),(GLvoid *) RING_API_GETCPOINTER(5,"GLvoid"));
}


RING_FUNC(ring_glGetMinmaxParameterfv)
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
	glGetMinmaxParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetMinmaxParameteriv)
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
	glGetMinmaxParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
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
	ring_vm_funcregister("glblendcolor",ring_glBlendColor);
	ring_vm_funcregister("glblendequation",ring_glBlendEquation);
	ring_vm_funcregister("glblendequationseparate",ring_glBlendEquationSeparate);
	ring_vm_funcregister("glblendfunc",ring_glBlendFunc);
	ring_vm_funcregister("glblendfuncseparate",ring_glBlendFuncSeparate);
	ring_vm_funcregister("glbufferdata",ring_glBufferData);
	ring_vm_funcregister("glbuffersubdata",ring_glBufferSubData);
	ring_vm_funcregister("glcalllist",ring_glCallList);
	ring_vm_funcregister("glcalllists",ring_glCallLists);
	ring_vm_funcregister("glclear",ring_glClear);
	ring_vm_funcregister("glclearaccum",ring_glClearAccum);
	ring_vm_funcregister("glclearcolor",ring_glClearColor);
	ring_vm_funcregister("glcleardepth",ring_glClearDepth);
	ring_vm_funcregister("glclearindex",ring_glClearIndex);
	ring_vm_funcregister("glclearstencil",ring_glClearStencil);
	ring_vm_funcregister("glclientactivetexture",ring_glClientActiveTexture);
	ring_vm_funcregister("glclipplane",ring_glClipPlane);
	ring_vm_funcregister("glcolor3b",ring_glColor3b);
	ring_vm_funcregister("glcolor3s",ring_glColor3s);
	ring_vm_funcregister("glcolor3i",ring_glColor3i);
	ring_vm_funcregister("glcolor3f",ring_glColor3f);
	ring_vm_funcregister("glcolor3d",ring_glColor3d);
	ring_vm_funcregister("glcolor3ub",ring_glColor3ub);
	ring_vm_funcregister("glcolor3us",ring_glColor3us);
	ring_vm_funcregister("glcolor3ui",ring_glColor3ui);
	ring_vm_funcregister("glcolor4b",ring_glColor4b);
	ring_vm_funcregister("glcolor4s",ring_glColor4s);
	ring_vm_funcregister("glcolor4i",ring_glColor4i);
	ring_vm_funcregister("glcolor4f",ring_glColor4f);
	ring_vm_funcregister("glcolor4d",ring_glColor4d);
	ring_vm_funcregister("glcolor4ub",ring_glColor4ub);
	ring_vm_funcregister("glcolor4us",ring_glColor4us);
	ring_vm_funcregister("glcolor4ui",ring_glColor4ui);
	ring_vm_funcregister("glcolor3bv",ring_glColor3bv);
	ring_vm_funcregister("glcolor3sv",ring_glColor3sv);
	ring_vm_funcregister("glcolor3iv",ring_glColor3iv);
	ring_vm_funcregister("glcolor3fv",ring_glColor3fv);
	ring_vm_funcregister("glcolor3dv",ring_glColor3dv);
	ring_vm_funcregister("glcolor3ubv",ring_glColor3ubv);
	ring_vm_funcregister("glcolor3usv",ring_glColor3usv);
	ring_vm_funcregister("glcolor3uiv",ring_glColor3uiv);
	ring_vm_funcregister("glcolor4bv",ring_glColor4bv);
	ring_vm_funcregister("glcolor4sv",ring_glColor4sv);
	ring_vm_funcregister("glcolor4iv",ring_glColor4iv);
	ring_vm_funcregister("glcolor4fv",ring_glColor4fv);
	ring_vm_funcregister("glcolor4dv",ring_glColor4dv);
	ring_vm_funcregister("glcolor4ubv",ring_glColor4ubv);
	ring_vm_funcregister("glcolor4usv",ring_glColor4usv);
	ring_vm_funcregister("glcolor4uiv",ring_glColor4uiv);
	ring_vm_funcregister("glcolormask",ring_glColorMask);
	ring_vm_funcregister("glcolormaterial",ring_glColorMaterial);
	ring_vm_funcregister("glcolorpointer",ring_glColorPointer);
	ring_vm_funcregister("glcolorsubtable",ring_glColorSubTable);
	ring_vm_funcregister("glcolortable",ring_glColorTable);
	ring_vm_funcregister("glcolortableparameterfv",ring_glColorTableParameterfv);
	ring_vm_funcregister("glcolortableparameteriv",ring_glColorTableParameteriv);
	ring_vm_funcregister("glcompileshader",ring_glCompileShader);
	ring_vm_funcregister("glcompressedteximage1d",ring_glCompressedTexImage1D);
	ring_vm_funcregister("glcompressedteximage2d",ring_glCompressedTexImage2D);
	ring_vm_funcregister("glcompressedteximage3d",ring_glCompressedTexImage3D);
	ring_vm_funcregister("glcompressedtexsubimage1d",ring_glCompressedTexSubImage1D);
	ring_vm_funcregister("glcompressedtexsubimage2d",ring_glCompressedTexSubImage2D);
	ring_vm_funcregister("glcompressedtexsubimage3d",ring_glCompressedTexSubImage3D);
	ring_vm_funcregister("glconvolutionfilter1d",ring_glConvolutionFilter1D);
	ring_vm_funcregister("glconvolutionfilter2d",ring_glConvolutionFilter2D);
	ring_vm_funcregister("glconvolutionparameterf",ring_glConvolutionParameterf);
	ring_vm_funcregister("glconvolutionparameteri",ring_glConvolutionParameteri);
	ring_vm_funcregister("glconvolutionparameterfv",ring_glConvolutionParameterfv);
	ring_vm_funcregister("glconvolutionparameteriv",ring_glConvolutionParameteriv);
	ring_vm_funcregister("glcopycolorsubtable",ring_glCopyColorSubTable);
	ring_vm_funcregister("glcopycolortable",ring_glCopyColorTable);
	ring_vm_funcregister("glcopyconvolutionfilter1d",ring_glCopyConvolutionFilter1D);
	ring_vm_funcregister("glcopyconvolutionfilter2d",ring_glCopyConvolutionFilter2D);
	ring_vm_funcregister("glcopypixels",ring_glCopyPixels);
	ring_vm_funcregister("glcopyteximage1d",ring_glCopyTexImage1D);
	ring_vm_funcregister("glcopyteximage2d",ring_glCopyTexImage2D);
	ring_vm_funcregister("glcopytexsubimage1d",ring_glCopyTexSubImage1D);
	ring_vm_funcregister("glcopytexsubimage2d",ring_glCopyTexSubImage2D);
	ring_vm_funcregister("glcopytexsubimage3d",ring_glCopyTexSubImage3D);
	ring_vm_funcregister("glcreateprogram",ring_glCreateProgram);
	ring_vm_funcregister("glcreateshader",ring_glCreateShader);
	ring_vm_funcregister("glcullface",ring_glCullFace);
	ring_vm_funcregister("gldeletebuffers",ring_glDeleteBuffers);
	ring_vm_funcregister("gldeletelists",ring_glDeleteLists);
	ring_vm_funcregister("gldeleteprogram",ring_glDeleteProgram);
	ring_vm_funcregister("gldeletequeries",ring_glDeleteQueries);
	ring_vm_funcregister("gldeleteshader",ring_glDeleteShader);
	ring_vm_funcregister("gldeletetextures",ring_glDeleteTextures);
	ring_vm_funcregister("gldepthfunc",ring_glDepthFunc);
	ring_vm_funcregister("gldepthmask",ring_glDepthMask);
	ring_vm_funcregister("gldepthrange",ring_glDepthRange);
	ring_vm_funcregister("gldetachshader",ring_glDetachShader);
	ring_vm_funcregister("glenable",ring_glEnable);
	ring_vm_funcregister("glenableclientstate",ring_glEnableClientState);
	ring_vm_funcregister("glenablevertexattribarray",ring_glEnableVertexAttribArray);
	ring_vm_funcregister("gldisablevertexattribarray",ring_glDisableVertexAttribArray);
	ring_vm_funcregister("gldrawarrays",ring_glDrawArrays);
	ring_vm_funcregister("gldrawbuffer",ring_glDrawBuffer);
	ring_vm_funcregister("gldrawbuffers",ring_glDrawBuffers);
	ring_vm_funcregister("gldrawelements",ring_glDrawElements);
	ring_vm_funcregister("gldrawpixels",ring_glDrawPixels);
	ring_vm_funcregister("gldrawrangeelements",ring_glDrawRangeElements);
	ring_vm_funcregister("gledgeflag",ring_glEdgeFlag);
	ring_vm_funcregister("gledgeflagpointer",ring_glEdgeFlagPointer);
	ring_vm_funcregister("glend",ring_glEnd);
	ring_vm_funcregister("glendlist",ring_glEndList);
	ring_vm_funcregister("glendquery",ring_glEndQuery);
	ring_vm_funcregister("glevalcoord1f",ring_glEvalCoord1f);
	ring_vm_funcregister("glevalcoord1d",ring_glEvalCoord1d);
	ring_vm_funcregister("glevalcoord2f",ring_glEvalCoord2f);
	ring_vm_funcregister("glevalcoord2d",ring_glEvalCoord2d);
	ring_vm_funcregister("glevalmesh1",ring_glEvalMesh1);
	ring_vm_funcregister("glevalpoint1",ring_glEvalPoint1);
	ring_vm_funcregister("glevalpoint2",ring_glEvalPoint2);
	ring_vm_funcregister("glfeedbackbuffer",ring_glFeedbackBuffer);
	ring_vm_funcregister("glfinish",ring_glFinish);
	ring_vm_funcregister("glflush",ring_glFlush);
	ring_vm_funcregister("glfogf",ring_glFogf);
	ring_vm_funcregister("glfogi",ring_glFogi);
	ring_vm_funcregister("glfogfv",ring_glFogfv);
	ring_vm_funcregister("glfogiv",ring_glFogiv);
	ring_vm_funcregister("glfogcoordd",ring_glFogCoordd);
	ring_vm_funcregister("glfogcoordf",ring_glFogCoordf);
	ring_vm_funcregister("glfogcoorddv",ring_glFogCoorddv);
	ring_vm_funcregister("glfogcoordfv",ring_glFogCoordfv);
	ring_vm_funcregister("glfogcoordpointer",ring_glFogCoordPointer);
	ring_vm_funcregister("glfrontface",ring_glFrontFace);
	ring_vm_funcregister("glfrustum",ring_glFrustum);
	ring_vm_funcregister("glgenbuffers",ring_glGenBuffers);
	ring_vm_funcregister("glgenlists",ring_glGenLists);
	ring_vm_funcregister("glgenqueries",ring_glGenQueries);
	ring_vm_funcregister("glgentextures",ring_glGenTextures);
	ring_vm_funcregister("glgetbooleanv",ring_glGetBooleanv);
	ring_vm_funcregister("glgetdoublev",ring_glGetDoublev);
	ring_vm_funcregister("glgetfloatv",ring_glGetFloatv);
	ring_vm_funcregister("glgetintegerv",ring_glGetIntegerv);
	ring_vm_funcregister("glgetactiveattrib",ring_glGetActiveAttrib);
	ring_vm_funcregister("glgetactiveuniform",ring_glGetActiveUniform);
	ring_vm_funcregister("glgetattachedshaders",ring_glGetAttachedShaders);
	ring_vm_funcregister("glgetattriblocation",ring_glGetAttribLocation);
	ring_vm_funcregister("glgetbufferparameteriv",ring_glGetBufferParameteriv);
	ring_vm_funcregister("glgetbufferpointerv",ring_glGetBufferPointerv);
	ring_vm_funcregister("glgetbuffersubdata",ring_glGetBufferSubData);
	ring_vm_funcregister("glgetclipplane",ring_glGetClipPlane);
	ring_vm_funcregister("glgetcolortable",ring_glGetColorTable);
	ring_vm_funcregister("glgetcolortableparameterfv",ring_glGetColorTableParameterfv);
	ring_vm_funcregister("glgetcolortableparameteriv",ring_glGetColorTableParameteriv);
	ring_vm_funcregister("glgetcompressedteximage",ring_glGetCompressedTexImage);
	ring_vm_funcregister("glgetconvolutionfilter",ring_glGetConvolutionFilter);
	ring_vm_funcregister("glgetconvolutionparameterfv",ring_glGetConvolutionParameterfv);
	ring_vm_funcregister("glgetconvolutionparameteriv",ring_glGetConvolutionParameteriv);
	ring_vm_funcregister("glgeterror",ring_glGetError);
	ring_vm_funcregister("glgethistogram",ring_glGetHistogram);
	ring_vm_funcregister("glgethistogramparameterfv",ring_glGetHistogramParameterfv);
	ring_vm_funcregister("glgethistogramparameteriv",ring_glGetHistogramParameteriv);
	ring_vm_funcregister("glgetlightfv",ring_glGetLightfv);
	ring_vm_funcregister("glgetlightiv",ring_glGetLightiv);
	ring_vm_funcregister("glgetmapdv",ring_glGetMapdv);
	ring_vm_funcregister("glgetmapfv",ring_glGetMapfv);
	ring_vm_funcregister("glgetmapiv",ring_glGetMapiv);
	ring_vm_funcregister("glgetmaterialfv",ring_glGetMaterialfv);
	ring_vm_funcregister("glgetmaterialiv",ring_glGetMaterialiv);
	ring_vm_funcregister("glgetminmax",ring_glGetMinmax);
	ring_vm_funcregister("glgetminmaxparameterfv",ring_glGetMinmaxParameterfv);
	ring_vm_funcregister("glgetminmaxparameteriv",ring_glGetMinmaxParameteriv);
}
