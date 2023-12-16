/* Copyright (c) 2019-2020 Mahmoud Fayed <msfclipper@yahoo.com> */

#define RING_EXTENSION	// Don't call : windows.h (Avoid conflict with raylib.h)
#include <ring.h>

#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui/raygui.h"
#include "raymath/raymath.h"

RING_FUNC(ring_raylib_new_vector2)
{
	Vector2 *pMyPointer ;
	pMyPointer = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Vector2");
}

RING_FUNC(ring_raylib_new_managed_vector2)
{
	Vector2 *pMyPointer ;
	pMyPointer = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Vector2",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_vector2)
{
	Vector2 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Vector2*) RING_API_GETCPOINTER(1,"Vector2");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_vector2_x)
{
	Vector2 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector2");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_raylib_set_vector2_x)
{
	Vector2 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector2");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vector2_y)
{
	Vector2 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector2");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_raylib_set_vector2_y)
{
	Vector2 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector2");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_vector3)
{
	Vector3 *pMyPointer ;
	pMyPointer = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Vector3");
}

RING_FUNC(ring_raylib_new_managed_vector3)
{
	Vector3 *pMyPointer ;
	pMyPointer = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Vector3",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_vector3)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Vector3*) RING_API_GETCPOINTER(1,"Vector3");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_vector3_x)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_raylib_set_vector3_x)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vector3_y)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_raylib_set_vector3_y)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vector3_z)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	RING_API_RETNUMBER(pMyPointer->z);
}

RING_FUNC(ring_raylib_set_vector3_z)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	pMyPointer->z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_vector4)
{
	Vector4 *pMyPointer ;
	pMyPointer = (Vector4 *) RING_API_MALLOC(sizeof(Vector4)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Vector4");
}

RING_FUNC(ring_raylib_new_managed_vector4)
{
	Vector4 *pMyPointer ;
	pMyPointer = (Vector4 *) RING_API_MALLOC(sizeof(Vector4)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Vector4",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_vector4)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Vector4*) RING_API_GETCPOINTER(1,"Vector4");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_vector4_x)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_raylib_set_vector4_x)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vector4_y)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_raylib_set_vector4_y)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vector4_z)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	RING_API_RETNUMBER(pMyPointer->z);
}

RING_FUNC(ring_raylib_set_vector4_z)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	pMyPointer->z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vector4_w)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	RING_API_RETNUMBER(pMyPointer->w);
}

RING_FUNC(ring_raylib_set_vector4_w)
{
	Vector4 *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	pMyPointer->w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_quaternion)
{
	Quaternion *pMyPointer ;
	pMyPointer = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Quaternion");
}

RING_FUNC(ring_raylib_new_managed_quaternion)
{
	Quaternion *pMyPointer ;
	pMyPointer = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Quaternion",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_quaternion)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Quaternion*) RING_API_GETCPOINTER(1,"Quaternion");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_quaternion_x)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_raylib_set_quaternion_x)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_quaternion_y)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_raylib_set_quaternion_y)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_quaternion_z)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	RING_API_RETNUMBER(pMyPointer->z);
}

RING_FUNC(ring_raylib_set_quaternion_z)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	pMyPointer->z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_quaternion_w)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	RING_API_RETNUMBER(pMyPointer->w);
}

RING_FUNC(ring_raylib_set_quaternion_w)
{
	Quaternion *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	pMyPointer->w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_matrix)
{
	Matrix *pMyPointer ;
	pMyPointer = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Matrix");
}

RING_FUNC(ring_raylib_new_managed_matrix)
{
	Matrix *pMyPointer ;
	pMyPointer = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Matrix",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_matrix)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Matrix*) RING_API_GETCPOINTER(1,"Matrix");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_matrix_m0)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m0);
}

RING_FUNC(ring_raylib_set_matrix_m0)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m0 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m1)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m1);
}

RING_FUNC(ring_raylib_set_matrix_m1)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m1 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m2)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m2);
}

RING_FUNC(ring_raylib_set_matrix_m2)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m2 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m3)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m3);
}

RING_FUNC(ring_raylib_set_matrix_m3)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m3 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m4)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m4);
}

RING_FUNC(ring_raylib_set_matrix_m4)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m4 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m5)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m5);
}

RING_FUNC(ring_raylib_set_matrix_m5)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m5 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m6)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m6);
}

RING_FUNC(ring_raylib_set_matrix_m6)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m6 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m7)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m7);
}

RING_FUNC(ring_raylib_set_matrix_m7)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m7 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m8)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m8);
}

RING_FUNC(ring_raylib_set_matrix_m8)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m8 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m9)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m9);
}

RING_FUNC(ring_raylib_set_matrix_m9)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m9 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m10)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m10);
}

RING_FUNC(ring_raylib_set_matrix_m10)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m10 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m11)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m11);
}

RING_FUNC(ring_raylib_set_matrix_m11)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m11 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m12)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m12);
}

RING_FUNC(ring_raylib_set_matrix_m12)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m12 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m13)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m13);
}

RING_FUNC(ring_raylib_set_matrix_m13)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m13 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m14)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m14);
}

RING_FUNC(ring_raylib_set_matrix_m14)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m14 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_matrix_m15)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	RING_API_RETNUMBER(pMyPointer->m15);
}

RING_FUNC(ring_raylib_set_matrix_m15)
{
	Matrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	pMyPointer->m15 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_color)
{
	Color *pMyPointer ;
	pMyPointer = (Color *) RING_API_MALLOC(sizeof(Color)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Color");
}

RING_FUNC(ring_raylib_new_managed_color)
{
	Color *pMyPointer ;
	pMyPointer = (Color *) RING_API_MALLOC(sizeof(Color)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Color",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_color)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Color*) RING_API_GETCPOINTER(1,"Color");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_color_r)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	RING_API_RETNUMBER(pMyPointer->r);
}

RING_FUNC(ring_raylib_set_color_r)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	pMyPointer->r = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_color_g)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	RING_API_RETNUMBER(pMyPointer->g);
}

RING_FUNC(ring_raylib_set_color_g)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	pMyPointer->g = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_color_b)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	RING_API_RETNUMBER(pMyPointer->b);
}

RING_FUNC(ring_raylib_set_color_b)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	pMyPointer->b = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_color_a)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	RING_API_RETNUMBER(pMyPointer->a);
}

RING_FUNC(ring_raylib_set_color_a)
{
	Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	pMyPointer->a = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_rectangle)
{
	Rectangle *pMyPointer ;
	pMyPointer = (Rectangle *) RING_API_MALLOC(sizeof(Rectangle)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Rectangle");
}

RING_FUNC(ring_raylib_new_managed_rectangle)
{
	Rectangle *pMyPointer ;
	pMyPointer = (Rectangle *) RING_API_MALLOC(sizeof(Rectangle)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Rectangle",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_rectangle)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Rectangle*) RING_API_GETCPOINTER(1,"Rectangle");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_rectangle_x)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_raylib_set_rectangle_x)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rectangle_y)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_raylib_set_rectangle_y)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rectangle_width)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	RING_API_RETNUMBER(pMyPointer->width);
}

RING_FUNC(ring_raylib_set_rectangle_width)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	pMyPointer->width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rectangle_height)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	RING_API_RETNUMBER(pMyPointer->height);
}

RING_FUNC(ring_raylib_set_rectangle_height)
{
	Rectangle *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	pMyPointer->height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_image)
{
	Image *pMyPointer ;
	pMyPointer = (Image *) RING_API_MALLOC(sizeof(Image)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Image");
}

RING_FUNC(ring_raylib_new_managed_image)
{
	Image *pMyPointer ;
	pMyPointer = (Image *) RING_API_MALLOC(sizeof(Image)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Image",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_image)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Image*) RING_API_GETCPOINTER(1,"Image");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_image_data)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	RING_API_RETCPOINTER(pMyPointer->data,"void");
}

RING_FUNC(ring_raylib_set_image_data)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	pMyPointer->data = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_raylib_get_image_width)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	RING_API_RETNUMBER(pMyPointer->width);
}

RING_FUNC(ring_raylib_set_image_width)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	pMyPointer->width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_image_height)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	RING_API_RETNUMBER(pMyPointer->height);
}

RING_FUNC(ring_raylib_set_image_height)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	pMyPointer->height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_image_mipmaps)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	RING_API_RETNUMBER(pMyPointer->mipmaps);
}

RING_FUNC(ring_raylib_set_image_mipmaps)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	pMyPointer->mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_image_format)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	RING_API_RETNUMBER(pMyPointer->format);
}

RING_FUNC(ring_raylib_set_image_format)
{
	Image *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	pMyPointer->format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_texture2d)
{
	Texture2D *pMyPointer ;
	pMyPointer = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Texture2D");
}

RING_FUNC(ring_raylib_new_managed_texture2d)
{
	Texture2D *pMyPointer ;
	pMyPointer = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Texture2D",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_texture2d)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Texture2D*) RING_API_GETCPOINTER(1,"Texture2D");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_texture2d_id)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	RING_API_RETNUMBER(pMyPointer->id);
}

RING_FUNC(ring_raylib_set_texture2d_id)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	pMyPointer->id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture2d_width)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	RING_API_RETNUMBER(pMyPointer->width);
}

RING_FUNC(ring_raylib_set_texture2d_width)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	pMyPointer->width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture2d_height)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	RING_API_RETNUMBER(pMyPointer->height);
}

RING_FUNC(ring_raylib_set_texture2d_height)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	pMyPointer->height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture2d_mipmaps)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	RING_API_RETNUMBER(pMyPointer->mipmaps);
}

RING_FUNC(ring_raylib_set_texture2d_mipmaps)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	pMyPointer->mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture2d_format)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	RING_API_RETNUMBER(pMyPointer->format);
}

RING_FUNC(ring_raylib_set_texture2d_format)
{
	Texture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	pMyPointer->format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_texture)
{
	Texture *pMyPointer ;
	pMyPointer = (Texture *) RING_API_MALLOC(sizeof(Texture)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Texture");
}

RING_FUNC(ring_raylib_new_managed_texture)
{
	Texture *pMyPointer ;
	pMyPointer = (Texture *) RING_API_MALLOC(sizeof(Texture)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Texture",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_texture)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Texture*) RING_API_GETCPOINTER(1,"Texture");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_texture_id)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	RING_API_RETNUMBER(pMyPointer->id);
}

RING_FUNC(ring_raylib_set_texture_id)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	pMyPointer->id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture_width)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	RING_API_RETNUMBER(pMyPointer->width);
}

RING_FUNC(ring_raylib_set_texture_width)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	pMyPointer->width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture_height)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	RING_API_RETNUMBER(pMyPointer->height);
}

RING_FUNC(ring_raylib_set_texture_height)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	pMyPointer->height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture_mipmaps)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	RING_API_RETNUMBER(pMyPointer->mipmaps);
}

RING_FUNC(ring_raylib_set_texture_mipmaps)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	pMyPointer->mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_texture_format)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	RING_API_RETNUMBER(pMyPointer->format);
}

RING_FUNC(ring_raylib_set_texture_format)
{
	Texture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	pMyPointer->format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_rendertexture2d)
{
	RenderTexture2D *pMyPointer ;
	pMyPointer = (RenderTexture2D *) RING_API_MALLOC(sizeof(RenderTexture2D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"RenderTexture2D");
}

RING_FUNC(ring_raylib_new_managed_rendertexture2d)
{
	RenderTexture2D *pMyPointer ;
	pMyPointer = (RenderTexture2D *) RING_API_MALLOC(sizeof(RenderTexture2D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"RenderTexture2D",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_rendertexture2d)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (RenderTexture2D*) RING_API_GETCPOINTER(1,"RenderTexture2D");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_rendertexture2d_id)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->id);
}

RING_FUNC(ring_raylib_set_rendertexture2d_id)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_texture_id)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->texture.id);
}

RING_FUNC(ring_raylib_set_rendertexture2d_texture_id)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->texture.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_texture_width)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->texture.width);
}

RING_FUNC(ring_raylib_set_rendertexture2d_texture_width)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->texture.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_texture_height)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->texture.height);
}

RING_FUNC(ring_raylib_set_rendertexture2d_texture_height)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->texture.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_texture_mipmaps)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->texture.mipmaps);
}

RING_FUNC(ring_raylib_set_rendertexture2d_texture_mipmaps)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->texture.mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_texture_format)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->texture.format);
}

RING_FUNC(ring_raylib_set_rendertexture2d_texture_format)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->texture.format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_depth_id)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->depth.id);
}

RING_FUNC(ring_raylib_set_rendertexture2d_depth_id)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->depth.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_depth_width)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->depth.width);
}

RING_FUNC(ring_raylib_set_rendertexture2d_depth_width)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->depth.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_depth_height)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->depth.height);
}

RING_FUNC(ring_raylib_set_rendertexture2d_depth_height)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->depth.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_depth_mipmaps)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->depth.mipmaps);
}

RING_FUNC(ring_raylib_set_rendertexture2d_depth_mipmaps)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->depth.mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_depth_format)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->depth.format);
}

RING_FUNC(ring_raylib_set_rendertexture2d_depth_format)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->depth.format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture2d_depthTexture)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	RING_API_RETNUMBER(pMyPointer->depthTexture);
}

RING_FUNC(ring_raylib_set_rendertexture2d_depthTexture)
{
	RenderTexture2D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	pMyPointer->depthTexture = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_rendertexture)
{
	RenderTexture *pMyPointer ;
	pMyPointer = (RenderTexture *) RING_API_MALLOC(sizeof(RenderTexture)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"RenderTexture");
}

RING_FUNC(ring_raylib_new_managed_rendertexture)
{
	RenderTexture *pMyPointer ;
	pMyPointer = (RenderTexture *) RING_API_MALLOC(sizeof(RenderTexture)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"RenderTexture",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_rendertexture)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (RenderTexture*) RING_API_GETCPOINTER(1,"RenderTexture");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_rendertexture_id)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->id);
}

RING_FUNC(ring_raylib_set_rendertexture_id)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_texture_id)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->texture.id);
}

RING_FUNC(ring_raylib_set_rendertexture_texture_id)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->texture.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_texture_width)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->texture.width);
}

RING_FUNC(ring_raylib_set_rendertexture_texture_width)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->texture.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_texture_height)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->texture.height);
}

RING_FUNC(ring_raylib_set_rendertexture_texture_height)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->texture.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_texture_mipmaps)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->texture.mipmaps);
}

RING_FUNC(ring_raylib_set_rendertexture_texture_mipmaps)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->texture.mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_texture_format)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->texture.format);
}

RING_FUNC(ring_raylib_set_rendertexture_texture_format)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->texture.format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_depth_id)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->depth.id);
}

RING_FUNC(ring_raylib_set_rendertexture_depth_id)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->depth.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_depth_width)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->depth.width);
}

RING_FUNC(ring_raylib_set_rendertexture_depth_width)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->depth.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_depth_height)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->depth.height);
}

RING_FUNC(ring_raylib_set_rendertexture_depth_height)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->depth.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_depth_mipmaps)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->depth.mipmaps);
}

RING_FUNC(ring_raylib_set_rendertexture_depth_mipmaps)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->depth.mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_depth_format)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->depth.format);
}

RING_FUNC(ring_raylib_set_rendertexture_depth_format)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->depth.format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rendertexture_depthTexture)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	RING_API_RETNUMBER(pMyPointer->depthTexture);
}

RING_FUNC(ring_raylib_set_rendertexture_depthTexture)
{
	RenderTexture *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	pMyPointer->depthTexture = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_npatchinfo)
{
	NPatchInfo *pMyPointer ;
	pMyPointer = (NPatchInfo *) RING_API_MALLOC(sizeof(NPatchInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"NPatchInfo");
}

RING_FUNC(ring_raylib_new_managed_npatchinfo)
{
	NPatchInfo *pMyPointer ;
	pMyPointer = (NPatchInfo *) RING_API_MALLOC(sizeof(NPatchInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"NPatchInfo",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_npatchinfo)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (NPatchInfo*) RING_API_GETCPOINTER(1,"NPatchInfo");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_npatchinfo_sourceRec_x)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->sourceRec.x);
}

RING_FUNC(ring_raylib_set_npatchinfo_sourceRec_x)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->sourceRec.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_sourceRec_y)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->sourceRec.y);
}

RING_FUNC(ring_raylib_set_npatchinfo_sourceRec_y)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->sourceRec.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_sourceRec_width)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->sourceRec.width);
}

RING_FUNC(ring_raylib_set_npatchinfo_sourceRec_width)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->sourceRec.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_sourceRec_height)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->sourceRec.height);
}

RING_FUNC(ring_raylib_set_npatchinfo_sourceRec_height)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->sourceRec.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_left)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->left);
}

RING_FUNC(ring_raylib_set_npatchinfo_left)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->left = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_top)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->top);
}

RING_FUNC(ring_raylib_set_npatchinfo_top)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->top = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_right)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->right);
}

RING_FUNC(ring_raylib_set_npatchinfo_right)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->right = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_bottom)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->bottom);
}

RING_FUNC(ring_raylib_set_npatchinfo_bottom)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->bottom = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_npatchinfo_type)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_raylib_set_npatchinfo_type)
{
	NPatchInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_charinfo)
{
	CharInfo *pMyPointer ;
	pMyPointer = (CharInfo *) RING_API_MALLOC(sizeof(CharInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"CharInfo");
}

RING_FUNC(ring_raylib_new_managed_charinfo)
{
	CharInfo *pMyPointer ;
	pMyPointer = (CharInfo *) RING_API_MALLOC(sizeof(CharInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"CharInfo",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_charinfo)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (CharInfo*) RING_API_GETCPOINTER(1,"CharInfo");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_charinfo_value)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->value);
}

RING_FUNC(ring_raylib_set_charinfo_value)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->value = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_rec_x)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->rec.x);
}

RING_FUNC(ring_raylib_set_charinfo_rec_x)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->rec.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_rec_y)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->rec.y);
}

RING_FUNC(ring_raylib_set_charinfo_rec_y)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->rec.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_rec_width)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->rec.width);
}

RING_FUNC(ring_raylib_set_charinfo_rec_width)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->rec.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_rec_height)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->rec.height);
}

RING_FUNC(ring_raylib_set_charinfo_rec_height)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->rec.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_offsetX)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->offsetX);
}

RING_FUNC(ring_raylib_set_charinfo_offsetX)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->offsetX = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_offsetY)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->offsetY);
}

RING_FUNC(ring_raylib_set_charinfo_offsetY)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->offsetY = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_advanceX)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETNUMBER(pMyPointer->advanceX);
}

RING_FUNC(ring_raylib_set_charinfo_advanceX)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->advanceX = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_charinfo_data)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	RING_API_RETCPOINTER(pMyPointer->data,"unsigned char");
}

RING_FUNC(ring_raylib_set_charinfo_data)
{
	CharInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	pMyPointer->data = (unsigned char *) RING_API_GETCPOINTER(2,"unsigned char");
}

RING_FUNC(ring_raylib_new_font)
{
	Font *pMyPointer ;
	pMyPointer = (Font *) RING_API_MALLOC(sizeof(Font)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Font");
}

RING_FUNC(ring_raylib_new_managed_font)
{
	Font *pMyPointer ;
	pMyPointer = (Font *) RING_API_MALLOC(sizeof(Font)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Font",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_font)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Font*) RING_API_GETCPOINTER(1,"Font");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_font_texture_id)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETNUMBER(pMyPointer->texture.id);
}

RING_FUNC(ring_raylib_set_font_texture_id)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->texture.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_font_texture_width)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETNUMBER(pMyPointer->texture.width);
}

RING_FUNC(ring_raylib_set_font_texture_width)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->texture.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_font_texture_height)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETNUMBER(pMyPointer->texture.height);
}

RING_FUNC(ring_raylib_set_font_texture_height)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->texture.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_font_texture_mipmaps)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETNUMBER(pMyPointer->texture.mipmaps);
}

RING_FUNC(ring_raylib_set_font_texture_mipmaps)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->texture.mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_font_texture_format)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETNUMBER(pMyPointer->texture.format);
}

RING_FUNC(ring_raylib_set_font_texture_format)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->texture.format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_font_baseSize)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETNUMBER(pMyPointer->baseSize);
}

RING_FUNC(ring_raylib_set_font_baseSize)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->baseSize = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_font_charsCount)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETNUMBER(pMyPointer->charsCount);
}

RING_FUNC(ring_raylib_set_font_charsCount)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->charsCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_font_chars)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	RING_API_RETCPOINTER(pMyPointer->chars,"CharInfo");
}

RING_FUNC(ring_raylib_set_font_chars)
{
	Font *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	pMyPointer->chars = (CharInfo *) RING_API_GETCPOINTER(2,"CharInfo");
}

RING_FUNC(ring_raylib_new_spritefont)
{
	SpriteFont *pMyPointer ;
	pMyPointer = (SpriteFont *) RING_API_MALLOC(sizeof(SpriteFont)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SpriteFont");
}

RING_FUNC(ring_raylib_new_managed_spritefont)
{
	SpriteFont *pMyPointer ;
	pMyPointer = (SpriteFont *) RING_API_MALLOC(sizeof(SpriteFont)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SpriteFont",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_spritefont)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SpriteFont*) RING_API_GETCPOINTER(1,"SpriteFont");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_spritefont_texture_id)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETNUMBER(pMyPointer->texture.id);
}

RING_FUNC(ring_raylib_set_spritefont_texture_id)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->texture.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_spritefont_texture_width)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETNUMBER(pMyPointer->texture.width);
}

RING_FUNC(ring_raylib_set_spritefont_texture_width)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->texture.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_spritefont_texture_height)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETNUMBER(pMyPointer->texture.height);
}

RING_FUNC(ring_raylib_set_spritefont_texture_height)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->texture.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_spritefont_texture_mipmaps)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETNUMBER(pMyPointer->texture.mipmaps);
}

RING_FUNC(ring_raylib_set_spritefont_texture_mipmaps)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->texture.mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_spritefont_texture_format)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETNUMBER(pMyPointer->texture.format);
}

RING_FUNC(ring_raylib_set_spritefont_texture_format)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->texture.format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_spritefont_baseSize)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETNUMBER(pMyPointer->baseSize);
}

RING_FUNC(ring_raylib_set_spritefont_baseSize)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->baseSize = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_spritefont_charsCount)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETNUMBER(pMyPointer->charsCount);
}

RING_FUNC(ring_raylib_set_spritefont_charsCount)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->charsCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_spritefont_chars)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	RING_API_RETCPOINTER(pMyPointer->chars,"CharInfo");
}

RING_FUNC(ring_raylib_set_spritefont_chars)
{
	SpriteFont *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	pMyPointer->chars = (CharInfo *) RING_API_GETCPOINTER(2,"CharInfo");
}

RING_FUNC(ring_raylib_new_camera3d)
{
	Camera3D *pMyPointer ;
	pMyPointer = (Camera3D *) RING_API_MALLOC(sizeof(Camera3D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Camera3D");
}

RING_FUNC(ring_raylib_new_managed_camera3d)
{
	Camera3D *pMyPointer ;
	pMyPointer = (Camera3D *) RING_API_MALLOC(sizeof(Camera3D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Camera3D",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_camera3d)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Camera3D*) RING_API_GETCPOINTER(1,"Camera3D");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_camera3d_position_x)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->position.x);
}

RING_FUNC(ring_raylib_set_camera3d_position_x)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->position.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_position_y)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->position.y);
}

RING_FUNC(ring_raylib_set_camera3d_position_y)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->position.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_position_z)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->position.z);
}

RING_FUNC(ring_raylib_set_camera3d_position_z)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->position.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_target_x)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->target.x);
}

RING_FUNC(ring_raylib_set_camera3d_target_x)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->target.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_target_y)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->target.y);
}

RING_FUNC(ring_raylib_set_camera3d_target_y)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->target.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_target_z)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->target.z);
}

RING_FUNC(ring_raylib_set_camera3d_target_z)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->target.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_up_x)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->up.x);
}

RING_FUNC(ring_raylib_set_camera3d_up_x)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->up.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_up_y)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->up.y);
}

RING_FUNC(ring_raylib_set_camera3d_up_y)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->up.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_up_z)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->up.z);
}

RING_FUNC(ring_raylib_set_camera3d_up_z)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->up.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_fovy)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->fovy);
}

RING_FUNC(ring_raylib_set_camera3d_fovy)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->fovy = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_camera3d_type)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_raylib_set_camera3d_type)
{
	Camera3D *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_mesh)
{
	Mesh *pMyPointer ;
	pMyPointer = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Mesh");
}

RING_FUNC(ring_raylib_new_managed_mesh)
{
	Mesh *pMyPointer ;
	pMyPointer = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Mesh",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_mesh)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Mesh*) RING_API_GETCPOINTER(1,"Mesh");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_mesh_vertexCount)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETNUMBER(pMyPointer->vertexCount);
}

RING_FUNC(ring_raylib_set_mesh_vertexCount)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->vertexCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_mesh_triangleCount)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETNUMBER(pMyPointer->triangleCount);
}

RING_FUNC(ring_raylib_set_mesh_triangleCount)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->triangleCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_mesh_vertices)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->vertices,"float");
}

RING_FUNC(ring_raylib_set_mesh_vertices)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->vertices = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_texcoords)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->texcoords,"float");
}

RING_FUNC(ring_raylib_set_mesh_texcoords)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->texcoords = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_texcoords2)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->texcoords2,"float");
}

RING_FUNC(ring_raylib_set_mesh_texcoords2)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->texcoords2 = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_normals)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->normals,"float");
}

RING_FUNC(ring_raylib_set_mesh_normals)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->normals = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_tangents)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->tangents,"float");
}

RING_FUNC(ring_raylib_set_mesh_tangents)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->tangents = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_colors)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->colors,"unsigned char");
}

RING_FUNC(ring_raylib_set_mesh_colors)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->colors = (unsigned char *) RING_API_GETCPOINTER(2,"unsigned char");
}

RING_FUNC(ring_raylib_get_mesh_indices)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->indices,"unsigned short");
}

RING_FUNC(ring_raylib_set_mesh_indices)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->indices = (unsigned short *) RING_API_GETCPOINTER(2,"unsigned short");
}

RING_FUNC(ring_raylib_get_mesh_animVertices)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->animVertices,"float");
}

RING_FUNC(ring_raylib_set_mesh_animVertices)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->animVertices = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_animNormals)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->animNormals,"float");
}

RING_FUNC(ring_raylib_set_mesh_animNormals)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->animNormals = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_boneIds)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->boneIds,"int");
}

RING_FUNC(ring_raylib_set_mesh_boneIds)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->boneIds = (int *) RING_API_GETCPOINTER(2,"int");
}

RING_FUNC(ring_raylib_get_mesh_boneWeights)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETCPOINTER(pMyPointer->boneWeights,"float");
}

RING_FUNC(ring_raylib_set_mesh_boneWeights)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->boneWeights = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_get_mesh_vaoId)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	RING_API_RETNUMBER(pMyPointer->vaoId);
}

RING_FUNC(ring_raylib_set_mesh_vaoId)
{
	Mesh *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	pMyPointer->vaoId = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_shader)
{
	Shader *pMyPointer ;
	pMyPointer = (Shader *) RING_API_MALLOC(sizeof(Shader)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Shader");
}

RING_FUNC(ring_raylib_new_managed_shader)
{
	Shader *pMyPointer ;
	pMyPointer = (Shader *) RING_API_MALLOC(sizeof(Shader)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Shader",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_shader)
{
	Shader *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Shader*) RING_API_GETCPOINTER(1,"Shader");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_shader_id)
{
	Shader *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Shader");
	RING_API_RETNUMBER(pMyPointer->id);
}

RING_FUNC(ring_raylib_set_shader_id)
{
	Shader *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Shader");
	pMyPointer->id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_materialmap)
{
	MaterialMap *pMyPointer ;
	pMyPointer = (MaterialMap *) RING_API_MALLOC(sizeof(MaterialMap)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"MaterialMap");
}

RING_FUNC(ring_raylib_new_managed_materialmap)
{
	MaterialMap *pMyPointer ;
	pMyPointer = (MaterialMap *) RING_API_MALLOC(sizeof(MaterialMap)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"MaterialMap",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_materialmap)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (MaterialMap*) RING_API_GETCPOINTER(1,"MaterialMap");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_materialmap_texture_id)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	RING_API_RETNUMBER(pMyPointer->texture.id);
}

RING_FUNC(ring_raylib_set_materialmap_texture_id)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	pMyPointer->texture.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_materialmap_texture_width)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	RING_API_RETNUMBER(pMyPointer->texture.width);
}

RING_FUNC(ring_raylib_set_materialmap_texture_width)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	pMyPointer->texture.width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_materialmap_texture_height)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	RING_API_RETNUMBER(pMyPointer->texture.height);
}

RING_FUNC(ring_raylib_set_materialmap_texture_height)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	pMyPointer->texture.height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_materialmap_texture_mipmaps)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	RING_API_RETNUMBER(pMyPointer->texture.mipmaps);
}

RING_FUNC(ring_raylib_set_materialmap_texture_mipmaps)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	pMyPointer->texture.mipmaps = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_materialmap_texture_format)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	RING_API_RETNUMBER(pMyPointer->texture.format);
}

RING_FUNC(ring_raylib_set_materialmap_texture_format)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	pMyPointer->texture.format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_materialmap_value)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	RING_API_RETNUMBER(pMyPointer->value);
}

RING_FUNC(ring_raylib_set_materialmap_value)
{
	MaterialMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	pMyPointer->value = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_material)
{
	Material *pMyPointer ;
	pMyPointer = (Material *) RING_API_MALLOC(sizeof(Material)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Material");
}

RING_FUNC(ring_raylib_new_managed_material)
{
	Material *pMyPointer ;
	pMyPointer = (Material *) RING_API_MALLOC(sizeof(Material)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Material",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_material)
{
	Material *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Material*) RING_API_GETCPOINTER(1,"Material");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_material_shader_id)
{
	Material *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Material");
	RING_API_RETNUMBER(pMyPointer->shader.id);
}

RING_FUNC(ring_raylib_set_material_shader_id)
{
	Material *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Material");
	pMyPointer->shader.id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_material_params)
{
	Material *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Material");
	RING_API_RETCPOINTER(pMyPointer->params,"float");
}

RING_FUNC(ring_raylib_set_material_params)
{
	Material *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Material");
	pMyPointer->params = (float *) RING_API_GETCPOINTER(2,"float");
}

RING_FUNC(ring_raylib_new_transform)
{
	Transform *pMyPointer ;
	pMyPointer = (Transform *) RING_API_MALLOC(sizeof(Transform)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Transform");
}

RING_FUNC(ring_raylib_new_managed_transform)
{
	Transform *pMyPointer ;
	pMyPointer = (Transform *) RING_API_MALLOC(sizeof(Transform)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Transform",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_transform)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Transform*) RING_API_GETCPOINTER(1,"Transform");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_transform_translation_x)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->translation.x);
}

RING_FUNC(ring_raylib_set_transform_translation_x)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->translation.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_translation_y)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->translation.y);
}

RING_FUNC(ring_raylib_set_transform_translation_y)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->translation.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_translation_z)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->translation.z);
}

RING_FUNC(ring_raylib_set_transform_translation_z)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->translation.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_rotation_x)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->rotation.x);
}

RING_FUNC(ring_raylib_set_transform_rotation_x)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->rotation.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_rotation_y)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->rotation.y);
}

RING_FUNC(ring_raylib_set_transform_rotation_y)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->rotation.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_rotation_z)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->rotation.z);
}

RING_FUNC(ring_raylib_set_transform_rotation_z)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->rotation.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_rotation_w)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->rotation.w);
}

RING_FUNC(ring_raylib_set_transform_rotation_w)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->rotation.w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_scale_x)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->scale.x);
}

RING_FUNC(ring_raylib_set_transform_scale_x)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->scale.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_scale_y)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->scale.y);
}

RING_FUNC(ring_raylib_set_transform_scale_y)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->scale.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_transform_scale_z)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	RING_API_RETNUMBER(pMyPointer->scale.z);
}

RING_FUNC(ring_raylib_set_transform_scale_z)
{
	Transform *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	pMyPointer->scale.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_boneinfo)
{
	BoneInfo *pMyPointer ;
	pMyPointer = (BoneInfo *) RING_API_MALLOC(sizeof(BoneInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"BoneInfo");
}

RING_FUNC(ring_raylib_new_managed_boneinfo)
{
	BoneInfo *pMyPointer ;
	pMyPointer = (BoneInfo *) RING_API_MALLOC(sizeof(BoneInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"BoneInfo",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_boneinfo)
{
	BoneInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (BoneInfo*) RING_API_GETCPOINTER(1,"BoneInfo");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_boneinfo_parent)
{
	BoneInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoneInfo");
	RING_API_RETNUMBER(pMyPointer->parent);
}

RING_FUNC(ring_raylib_set_boneinfo_parent)
{
	BoneInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoneInfo");
	pMyPointer->parent = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_model)
{
	Model *pMyPointer ;
	pMyPointer = (Model *) RING_API_MALLOC(sizeof(Model)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Model");
}

RING_FUNC(ring_raylib_new_managed_model)
{
	Model *pMyPointer ;
	pMyPointer = (Model *) RING_API_MALLOC(sizeof(Model)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Model",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_model)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Model*) RING_API_GETCPOINTER(1,"Model");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_model_transform_m0)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m0);
}

RING_FUNC(ring_raylib_set_model_transform_m0)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m0 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m1)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m1);
}

RING_FUNC(ring_raylib_set_model_transform_m1)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m1 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m2)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m2);
}

RING_FUNC(ring_raylib_set_model_transform_m2)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m2 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m3)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m3);
}

RING_FUNC(ring_raylib_set_model_transform_m3)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m3 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m4)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m4);
}

RING_FUNC(ring_raylib_set_model_transform_m4)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m4 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m5)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m5);
}

RING_FUNC(ring_raylib_set_model_transform_m5)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m5 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m6)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m6);
}

RING_FUNC(ring_raylib_set_model_transform_m6)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m6 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m7)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m7);
}

RING_FUNC(ring_raylib_set_model_transform_m7)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m7 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m8)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m8);
}

RING_FUNC(ring_raylib_set_model_transform_m8)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m8 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m9)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m9);
}

RING_FUNC(ring_raylib_set_model_transform_m9)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m9 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m10)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m10);
}

RING_FUNC(ring_raylib_set_model_transform_m10)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m10 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m11)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m11);
}

RING_FUNC(ring_raylib_set_model_transform_m11)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m11 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m12)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m12);
}

RING_FUNC(ring_raylib_set_model_transform_m12)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m12 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m13)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m13);
}

RING_FUNC(ring_raylib_set_model_transform_m13)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m13 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m14)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m14);
}

RING_FUNC(ring_raylib_set_model_transform_m14)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m14 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_transform_m15)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->transform.m15);
}

RING_FUNC(ring_raylib_set_model_transform_m15)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->transform.m15 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_meshCount)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->meshCount);
}

RING_FUNC(ring_raylib_set_model_meshCount)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->meshCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_meshes)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETCPOINTER(pMyPointer->meshes,"Mesh");
}

RING_FUNC(ring_raylib_set_model_meshes)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->meshes = (Mesh *) RING_API_GETCPOINTER(2,"Mesh");
}

RING_FUNC(ring_raylib_get_model_materialCount)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->materialCount);
}

RING_FUNC(ring_raylib_set_model_materialCount)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->materialCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_materials)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETCPOINTER(pMyPointer->materials,"Material");
}

RING_FUNC(ring_raylib_set_model_materials)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->materials = (Material *) RING_API_GETCPOINTER(2,"Material");
}

RING_FUNC(ring_raylib_get_model_meshMaterial)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETCPOINTER(pMyPointer->meshMaterial,"int");
}

RING_FUNC(ring_raylib_set_model_meshMaterial)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->meshMaterial = (int *) RING_API_GETCPOINTER(2,"int");
}

RING_FUNC(ring_raylib_get_model_boneCount)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETNUMBER(pMyPointer->boneCount);
}

RING_FUNC(ring_raylib_set_model_boneCount)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->boneCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_model_bones)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETCPOINTER(pMyPointer->bones,"BoneInfo");
}

RING_FUNC(ring_raylib_set_model_bones)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->bones = (BoneInfo *) RING_API_GETCPOINTER(2,"BoneInfo");
}

RING_FUNC(ring_raylib_get_model_bindPose)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	RING_API_RETCPOINTER(pMyPointer->bindPose,"Transform");
}

RING_FUNC(ring_raylib_set_model_bindPose)
{
	Model *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	pMyPointer->bindPose = (Transform *) RING_API_GETCPOINTER(2,"Transform");
}

RING_FUNC(ring_raylib_new_modelanimation)
{
	ModelAnimation *pMyPointer ;
	pMyPointer = (ModelAnimation *) RING_API_MALLOC(sizeof(ModelAnimation)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"ModelAnimation");
}

RING_FUNC(ring_raylib_new_managed_modelanimation)
{
	ModelAnimation *pMyPointer ;
	pMyPointer = (ModelAnimation *) RING_API_MALLOC(sizeof(ModelAnimation)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"ModelAnimation",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_modelanimation)
{
	ModelAnimation *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (ModelAnimation*) RING_API_GETCPOINTER(1,"ModelAnimation");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_modelanimation_boneCount)
{
	ModelAnimation *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ModelAnimation");
	RING_API_RETNUMBER(pMyPointer->boneCount);
}

RING_FUNC(ring_raylib_set_modelanimation_boneCount)
{
	ModelAnimation *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ModelAnimation");
	pMyPointer->boneCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_modelanimation_bones)
{
	ModelAnimation *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ModelAnimation");
	RING_API_RETCPOINTER(pMyPointer->bones,"BoneInfo");
}

RING_FUNC(ring_raylib_set_modelanimation_bones)
{
	ModelAnimation *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ModelAnimation");
	pMyPointer->bones = (BoneInfo *) RING_API_GETCPOINTER(2,"BoneInfo");
}

RING_FUNC(ring_raylib_get_modelanimation_frameCount)
{
	ModelAnimation *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ModelAnimation");
	RING_API_RETNUMBER(pMyPointer->frameCount);
}

RING_FUNC(ring_raylib_set_modelanimation_frameCount)
{
	ModelAnimation *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ModelAnimation");
	pMyPointer->frameCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_ray)
{
	Ray *pMyPointer ;
	pMyPointer = (Ray *) RING_API_MALLOC(sizeof(Ray)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Ray");
}

RING_FUNC(ring_raylib_new_managed_ray)
{
	Ray *pMyPointer ;
	pMyPointer = (Ray *) RING_API_MALLOC(sizeof(Ray)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Ray",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_ray)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Ray*) RING_API_GETCPOINTER(1,"Ray");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_ray_position_x)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	RING_API_RETNUMBER(pMyPointer->position.x);
}

RING_FUNC(ring_raylib_set_ray_position_x)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	pMyPointer->position.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_ray_position_y)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	RING_API_RETNUMBER(pMyPointer->position.y);
}

RING_FUNC(ring_raylib_set_ray_position_y)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	pMyPointer->position.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_ray_position_z)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	RING_API_RETNUMBER(pMyPointer->position.z);
}

RING_FUNC(ring_raylib_set_ray_position_z)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	pMyPointer->position.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_ray_direction_x)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	RING_API_RETNUMBER(pMyPointer->direction.x);
}

RING_FUNC(ring_raylib_set_ray_direction_x)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	pMyPointer->direction.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_ray_direction_y)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	RING_API_RETNUMBER(pMyPointer->direction.y);
}

RING_FUNC(ring_raylib_set_ray_direction_y)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	pMyPointer->direction.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_ray_direction_z)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	RING_API_RETNUMBER(pMyPointer->direction.z);
}

RING_FUNC(ring_raylib_set_ray_direction_z)
{
	Ray *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	pMyPointer->direction.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_rayhitinfo)
{
	RayHitInfo *pMyPointer ;
	pMyPointer = (RayHitInfo *) RING_API_MALLOC(sizeof(RayHitInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"RayHitInfo");
}

RING_FUNC(ring_raylib_new_managed_rayhitinfo)
{
	RayHitInfo *pMyPointer ;
	pMyPointer = (RayHitInfo *) RING_API_MALLOC(sizeof(RayHitInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"RayHitInfo",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_rayhitinfo)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (RayHitInfo*) RING_API_GETCPOINTER(1,"RayHitInfo");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_rayhitinfo_hit)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->hit);
}

RING_FUNC(ring_raylib_set_rayhitinfo_hit)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->hit = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rayhitinfo_distance)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->distance);
}

RING_FUNC(ring_raylib_set_rayhitinfo_distance)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->distance = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rayhitinfo_position_x)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->position.x);
}

RING_FUNC(ring_raylib_set_rayhitinfo_position_x)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->position.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rayhitinfo_position_y)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->position.y);
}

RING_FUNC(ring_raylib_set_rayhitinfo_position_y)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->position.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rayhitinfo_position_z)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->position.z);
}

RING_FUNC(ring_raylib_set_rayhitinfo_position_z)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->position.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rayhitinfo_normal_x)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->normal.x);
}

RING_FUNC(ring_raylib_set_rayhitinfo_normal_x)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->normal.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rayhitinfo_normal_y)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->normal.y);
}

RING_FUNC(ring_raylib_set_rayhitinfo_normal_y)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->normal.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_rayhitinfo_normal_z)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	RING_API_RETNUMBER(pMyPointer->normal.z);
}

RING_FUNC(ring_raylib_set_rayhitinfo_normal_z)
{
	RayHitInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	pMyPointer->normal.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_boundingbox)
{
	BoundingBox *pMyPointer ;
	pMyPointer = (BoundingBox *) RING_API_MALLOC(sizeof(BoundingBox)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"BoundingBox");
}

RING_FUNC(ring_raylib_new_managed_boundingbox)
{
	BoundingBox *pMyPointer ;
	pMyPointer = (BoundingBox *) RING_API_MALLOC(sizeof(BoundingBox)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"BoundingBox",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_boundingbox)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (BoundingBox*) RING_API_GETCPOINTER(1,"BoundingBox");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_boundingbox_min_x)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	RING_API_RETNUMBER(pMyPointer->min.x);
}

RING_FUNC(ring_raylib_set_boundingbox_min_x)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	pMyPointer->min.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_boundingbox_min_y)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	RING_API_RETNUMBER(pMyPointer->min.y);
}

RING_FUNC(ring_raylib_set_boundingbox_min_y)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	pMyPointer->min.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_boundingbox_min_z)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	RING_API_RETNUMBER(pMyPointer->min.z);
}

RING_FUNC(ring_raylib_set_boundingbox_min_z)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	pMyPointer->min.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_boundingbox_max_x)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	RING_API_RETNUMBER(pMyPointer->max.x);
}

RING_FUNC(ring_raylib_set_boundingbox_max_x)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	pMyPointer->max.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_boundingbox_max_y)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	RING_API_RETNUMBER(pMyPointer->max.y);
}

RING_FUNC(ring_raylib_set_boundingbox_max_y)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	pMyPointer->max.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_boundingbox_max_z)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	RING_API_RETNUMBER(pMyPointer->max.z);
}

RING_FUNC(ring_raylib_set_boundingbox_max_z)
{
	BoundingBox *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	pMyPointer->max.z = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_wave)
{
	Wave *pMyPointer ;
	pMyPointer = (Wave *) RING_API_MALLOC(sizeof(Wave)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Wave");
}

RING_FUNC(ring_raylib_new_managed_wave)
{
	Wave *pMyPointer ;
	pMyPointer = (Wave *) RING_API_MALLOC(sizeof(Wave)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Wave",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_wave)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Wave*) RING_API_GETCPOINTER(1,"Wave");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_wave_sampleCount)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	RING_API_RETNUMBER(pMyPointer->sampleCount);
}

RING_FUNC(ring_raylib_set_wave_sampleCount)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	pMyPointer->sampleCount = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_wave_sampleRate)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	RING_API_RETNUMBER(pMyPointer->sampleRate);
}

RING_FUNC(ring_raylib_set_wave_sampleRate)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	pMyPointer->sampleRate = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_wave_sampleSize)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	RING_API_RETNUMBER(pMyPointer->sampleSize);
}

RING_FUNC(ring_raylib_set_wave_sampleSize)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	pMyPointer->sampleSize = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_wave_channels)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	RING_API_RETNUMBER(pMyPointer->channels);
}

RING_FUNC(ring_raylib_set_wave_channels)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	pMyPointer->channels = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_wave_data)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	RING_API_RETCPOINTER(pMyPointer->data,"void");
}

RING_FUNC(ring_raylib_set_wave_data)
{
	Wave *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	pMyPointer->data = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_raylib_new_sound)
{
	Sound *pMyPointer ;
	pMyPointer = (Sound *) RING_API_MALLOC(sizeof(Sound)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Sound");
}

RING_FUNC(ring_raylib_new_managed_sound)
{
	Sound *pMyPointer ;
	pMyPointer = (Sound *) RING_API_MALLOC(sizeof(Sound)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Sound",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_sound)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Sound*) RING_API_GETCPOINTER(1,"Sound");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_sound_audioBuffer)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	RING_API_RETCPOINTER(pMyPointer->audioBuffer,"void");
}

RING_FUNC(ring_raylib_set_sound_audioBuffer)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	pMyPointer->audioBuffer = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_raylib_get_sound_source)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	RING_API_RETNUMBER(pMyPointer->source);
}

RING_FUNC(ring_raylib_set_sound_source)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	pMyPointer->source = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_sound_buffer)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	RING_API_RETNUMBER(pMyPointer->buffer);
}

RING_FUNC(ring_raylib_set_sound_buffer)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	pMyPointer->buffer = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_sound_format)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	RING_API_RETNUMBER(pMyPointer->format);
}

RING_FUNC(ring_raylib_set_sound_format)
{
	Sound *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	pMyPointer->format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_audiostream)
{
	AudioStream *pMyPointer ;
	pMyPointer = (AudioStream *) RING_API_MALLOC(sizeof(AudioStream)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"AudioStream");
}

RING_FUNC(ring_raylib_new_managed_audiostream)
{
	AudioStream *pMyPointer ;
	pMyPointer = (AudioStream *) RING_API_MALLOC(sizeof(AudioStream)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"AudioStream",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_audiostream)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (AudioStream*) RING_API_GETCPOINTER(1,"AudioStream");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_audiostream_sampleRate)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	RING_API_RETNUMBER(pMyPointer->sampleRate);
}

RING_FUNC(ring_raylib_set_audiostream_sampleRate)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	pMyPointer->sampleRate = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_audiostream_sampleSize)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	RING_API_RETNUMBER(pMyPointer->sampleSize);
}

RING_FUNC(ring_raylib_set_audiostream_sampleSize)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	pMyPointer->sampleSize = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_audiostream_channels)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	RING_API_RETNUMBER(pMyPointer->channels);
}

RING_FUNC(ring_raylib_set_audiostream_channels)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	pMyPointer->channels = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_audiostream_audioBuffer)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	RING_API_RETCPOINTER(pMyPointer->audioBuffer,"void");
}

RING_FUNC(ring_raylib_set_audiostream_audioBuffer)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	pMyPointer->audioBuffer = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_raylib_get_audiostream_format)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	RING_API_RETNUMBER(pMyPointer->format);
}

RING_FUNC(ring_raylib_set_audiostream_format)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	pMyPointer->format = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_audiostream_source)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	RING_API_RETNUMBER(pMyPointer->source);
}

RING_FUNC(ring_raylib_set_audiostream_source)
{
	AudioStream *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	pMyPointer->source = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_new_vrdeviceinfo)
{
	VrDeviceInfo *pMyPointer ;
	pMyPointer = (VrDeviceInfo *) RING_API_MALLOC(sizeof(VrDeviceInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"VrDeviceInfo");
}

RING_FUNC(ring_raylib_new_managed_vrdeviceinfo)
{
	VrDeviceInfo *pMyPointer ;
	pMyPointer = (VrDeviceInfo *) RING_API_MALLOC(sizeof(VrDeviceInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"VrDeviceInfo",RING_API_FREEFUNC);
}

RING_FUNC(ring_raylib_destroy_vrdeviceinfo)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (VrDeviceInfo*) RING_API_GETCPOINTER(1,"VrDeviceInfo");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_hResolution)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->hResolution);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_hResolution)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->hResolution = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_vResolution)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->vResolution);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_vResolution)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->vResolution = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_hScreenSize)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->hScreenSize);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_hScreenSize)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->hScreenSize = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_vScreenSize)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->vScreenSize);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_vScreenSize)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->vScreenSize = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_vScreenCenter)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->vScreenCenter);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_vScreenCenter)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->vScreenCenter = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_eyeToScreenDistance)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->eyeToScreenDistance);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_eyeToScreenDistance)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->eyeToScreenDistance = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_lensSeparationDistance)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->lensSeparationDistance);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_lensSeparationDistance)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->lensSeparationDistance = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_raylib_get_vrdeviceinfo_interpupillaryDistance)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	RING_API_RETNUMBER(pMyPointer->interpupillaryDistance);
}

RING_FUNC(ring_raylib_set_vrdeviceinfo_interpupillaryDistance)
{
	VrDeviceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	pMyPointer->interpupillaryDistance = RING_API_GETNUMBER(2);
}


RING_FUNC(ring_InitWindow)
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
	InitWindow( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_WindowShouldClose)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(WindowShouldClose());
}


RING_FUNC(ring_CloseWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	CloseWindow();
}


RING_FUNC(ring_IsWindowReady)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowReady());
}


RING_FUNC(ring_IsWindowMinimized)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowMinimized());
}


RING_FUNC(ring_IsWindowResized)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowResized());
}


RING_FUNC(ring_IsWindowHidden)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowHidden());
}


RING_FUNC(ring_ToggleFullscreen)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ToggleFullscreen();
}


RING_FUNC(ring_UnhideWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	UnhideWindow();
}


RING_FUNC(ring_HideWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	HideWindow();
}


RING_FUNC(ring_SetWindowIcon_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetWindowIcon(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_SetWindowTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetWindowTitle(RING_API_GETSTRING(1));
}


RING_FUNC(ring_SetWindowPosition)
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
	SetWindowPosition( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetWindowMonitor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetWindowMonitor( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetWindowMinSize)
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
	SetWindowMinSize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetWindowSize)
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
	SetWindowSize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_GetWindowHandle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(GetWindowHandle(),"void");
}


RING_FUNC(ring_GetScreenWidth)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetScreenWidth());
}


RING_FUNC(ring_GetScreenHeight)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetScreenHeight());
}


RING_FUNC(ring_GetMonitorCount)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorCount());
}


RING_FUNC(ring_GetMonitorWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorWidth( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorHeight( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorPhysicalWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorPhysicalWidth( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorPhysicalHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorPhysicalHeight( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetMonitorName( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetClipboardText)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(GetClipboardText());
}


RING_FUNC(ring_SetClipboardText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetClipboardText(RING_API_GETSTRING(1));
}


RING_FUNC(ring_ShowCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ShowCursor();
}


RING_FUNC(ring_HideCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	HideCursor();
}


RING_FUNC(ring_IsCursorHidden)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsCursorHidden());
}


RING_FUNC(ring_EnableCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EnableCursor();
}


RING_FUNC(ring_DisableCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	DisableCursor();
}


RING_FUNC(ring_ClearBackground_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ClearBackground(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Color"));
}


RING_FUNC(ring_BeginDrawing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	BeginDrawing();
}


RING_FUNC(ring_EndDrawing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndDrawing();
}


RING_FUNC(ring_BeginMode2D_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	BeginMode2D(* (Camera2D  *) RING_API_GETCPOINTER(1,"Camera2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Camera2D"));
}


RING_FUNC(ring_EndMode2D)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndMode2D();
}


RING_FUNC(ring_BeginMode3D_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	BeginMode3D(* (Camera3D  *) RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Camera3D"));
}


RING_FUNC(ring_EndMode3D)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndMode3D();
}


RING_FUNC(ring_BeginTextureMode_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	BeginTextureMode(* (RenderTexture2D  *) RING_API_GETCPOINTER(1,"RenderTexture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"RenderTexture2D"));
}


RING_FUNC(ring_EndTextureMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndTextureMode();
}


RING_FUNC(ring_GetMouseRay_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Ray *pValue ; 
		pValue = (Ray *) RING_API_MALLOC(sizeof(Ray)) ;
		*pValue = GetMouseRay(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Camera3D  *) RING_API_GETCPOINTER(2,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Camera3D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Ray",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetWorldToScreen_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = GetWorldToScreen(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Camera3D  *) RING_API_GETCPOINTER(2,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Camera3D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetCameraMatrix_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = GetCameraMatrix(* (Camera3D  *) RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Camera3D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SetTargetFPS)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTargetFPS( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_GetFPS)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetFPS());
}


RING_FUNC(ring_GetFrameTime)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetFrameTime());
}


RING_FUNC(ring_GetTime)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTime());
}


RING_FUNC(ring_ColorToInt_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(ColorToInt(* (Color  *) RING_API_GETCPOINTER(1,"Color")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Color"));
}


RING_FUNC(ring_ColorNormalize_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector4 *pValue ; 
		pValue = (Vector4 *) RING_API_MALLOC(sizeof(Vector4)) ;
		*pValue = ColorNormalize(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector4",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_ColorToHSV_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = ColorToHSV(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_ColorFromHSV_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Color *pValue ; 
		pValue = (Color *) RING_API_MALLOC(sizeof(Color)) ;
		*pValue = ColorFromHSV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetColor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Color *pValue ; 
		pValue = (Color *) RING_API_MALLOC(sizeof(Color)) ;
		*pValue = GetColor( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Fade_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Color *pValue ; 
		pValue = (Color *) RING_API_MALLOC(sizeof(Color)) ;
		*pValue = Fade(* (Color  *) RING_API_GETCPOINTER(1,"Color"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SetConfigFlags)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetConfigFlags( (unsigned char ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetTraceLogLevel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTraceLogLevel( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetTraceLogExit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTraceLogExit( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetTraceLogCallback)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetTraceLogCallback(* (TraceLogCallback  *) RING_API_GETCPOINTER(1,"TraceLogCallback"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"TraceLogCallback"));
}


RING_FUNC(ring_TraceLog)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TraceLog( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_TakeScreenshot)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TakeScreenshot(RING_API_GETSTRING(1));
}


RING_FUNC(ring_GetRandomValue)
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
	RING_API_RETNUMBER(GetRandomValue( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_FileExists)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(FileExists(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_IsFileExtension)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsFileExtension(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_GetExtension)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetExtension(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetFileName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetFileName(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetFileNameWithoutExt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetFileNameWithoutExt(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetDirectoryPath)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetDirectoryPath(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetWorkingDirectory)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(GetWorkingDirectory());
}


RING_FUNC(ring_GetDirectoryFiles)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(GetDirectoryFiles(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2)),"char");
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_ClearDirectoryFiles)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ClearDirectoryFiles();
}


RING_FUNC(ring_ChangeDirectory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(ChangeDirectory(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_IsFileDropped)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsFileDropped());
}


RING_FUNC(ring_GetDroppedFiles)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(GetDroppedFiles(RING_API_GETINTPOINTER(1)),"char");
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_ClearDroppedFiles)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ClearDroppedFiles();
}


RING_FUNC(ring_GetFileModTime)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		long *pValue ; 
		pValue = (long *) RING_API_MALLOC(sizeof(long)) ;
		*pValue = GetFileModTime(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"long",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_StorageSaveValue)
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
	StorageSaveValue( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_StorageLoadValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(StorageLoadValue( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_OpenURL)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	OpenURL(RING_API_GETSTRING(1));
}


RING_FUNC(ring_IsKeyPressed_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyPressed( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsKeyDown_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyDown( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsKeyReleased_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyReleased( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsKeyUp_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyUp( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetKeyPressed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetKeyPressed());
}


RING_FUNC(ring_SetExitKey_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetExitKey( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_IsGamepadAvailable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsGamepadAvailable( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsGamepadName)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsGamepadName( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_GetGamepadName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetGamepadName( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsGamepadButtonPressed)
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
	RING_API_RETNUMBER(IsGamepadButtonPressed( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsGamepadButtonDown)
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
	RING_API_RETNUMBER(IsGamepadButtonDown( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsGamepadButtonReleased)
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
	RING_API_RETNUMBER(IsGamepadButtonReleased( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsGamepadButtonUp)
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
	RING_API_RETNUMBER(IsGamepadButtonUp( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_GetGamepadButtonPressed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGamepadButtonPressed());
}


RING_FUNC(ring_GetGamepadAxisCount)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetGamepadAxisCount( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetGamepadAxisMovement)
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
	RING_API_RETNUMBER(GetGamepadAxisMovement( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsMouseButtonPressed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonPressed( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsMouseButtonDown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonDown( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsMouseButtonReleased)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonReleased( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsMouseButtonUp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonUp( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMouseX)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMouseX());
}


RING_FUNC(ring_GetMouseY)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMouseY());
}


RING_FUNC(ring_GetMousePosition_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = GetMousePosition();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SetMousePosition)
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
	SetMousePosition( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetMouseOffset)
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
	SetMouseOffset( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetMouseScale)
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
	SetMouseScale( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_GetMouseWheelMove)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMouseWheelMove());
}


RING_FUNC(ring_GetTouchX)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTouchX());
}


RING_FUNC(ring_GetTouchY)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTouchY());
}


RING_FUNC(ring_GetTouchPosition_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = GetTouchPosition( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SetGesturesEnabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetGesturesEnabled( (unsigned int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_IsGestureDetected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsGestureDetected( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetGestureDetected)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGestureDetected());
}


RING_FUNC(ring_GetTouchPointsCount)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTouchPointsCount());
}


RING_FUNC(ring_GetGestureHoldDuration)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGestureHoldDuration());
}


RING_FUNC(ring_GetGestureDragVector_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = GetGestureDragVector();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetGestureDragAngle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGestureDragAngle());
}


RING_FUNC(ring_GetGesturePinchVector_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = GetGesturePinchVector();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetGesturePinchAngle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGesturePinchAngle());
}


RING_FUNC(ring_SetCameraMode_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraMode(* (Camera3D  *) RING_API_GETCPOINTER(1,"Camera3D"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Camera3D"));
}


RING_FUNC(ring_UpdateCamera_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateCamera((Camera3D *) RING_API_GETCPOINTER(1,"Camera3D"));
}


RING_FUNC(ring_SetCameraPanControl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraPanControl( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetCameraAltControl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraAltControl( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetCameraSmoothZoomControl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraSmoothZoomControl( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetCameraMoveControls)
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
	SetCameraMoveControls( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_DrawPixel_2)
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
	DrawPixel( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawPixelV_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawPixelV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_DrawLine_2)
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
	DrawLine( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawLineV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawLineV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawLineEx_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawLineEx(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawLineBezier_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawLineBezier(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawLineStrip_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawLineStrip((Vector2 *) RING_API_GETCPOINTER(1,"Vector2"), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawCircle_2)
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
	DrawCircle( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawCircleSector_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCircleSector(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawCircleSectorLines_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCircleSectorLines(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawCircleGradient_2)
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
	DrawCircleGradient( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCircleV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawCircleV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawCircleLines_2)
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
	DrawCircleLines( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawRing_2)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawRing(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"Color"));
}


RING_FUNC(ring_DrawRingLines_2)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawRingLines(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"Color"));
}


RING_FUNC(ring_DrawRectangle_2)
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
	DrawRectangle( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawRectangleV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawRectangleV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawRectangleRec_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawRectangleRec(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_DrawRectanglePro_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawRectanglePro(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawRectangleGradientV_2)
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
	DrawRectangleGradientV( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawRectangleGradientH_2)
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
	DrawRectangleGradientH( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawRectangleGradientEx_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	DrawRectangleGradientEx(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"),* (Color  *) RING_API_GETCPOINTER(3,"Color"),* (Color  *) RING_API_GETCPOINTER(4,"Color"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawRectangleLines_2)
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
	DrawRectangleLines( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawRectangleLinesEx_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawRectangleLinesEx(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawRectangleRounded_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	DrawRectangleRounded(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawRectangleRoundedLines_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawRectangleRoundedLines(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawTriangle_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTriangle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTriangleLines_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTriangleLines(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTriangleFan_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawTriangleFan((Vector2 *) RING_API_GETCPOINTER(1,"Vector2"), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawPoly_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawPoly(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_SetShapesTexture_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	SetShapesTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_CheckCollisionRecs_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionRecs(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_CheckCollisionCircles_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionCircles(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"), (float ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector2"));
}


RING_FUNC(ring_CheckCollisionCircleRec_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionCircleRec(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
}


RING_FUNC(ring_GetCollisionRec_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Rectangle *pValue ; 
		pValue = (Rectangle *) RING_API_MALLOC(sizeof(Rectangle)) ;
		*pValue = GetCollisionRec(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Rectangle",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_CheckCollisionPointRec_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionPointRec(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_CheckCollisionPointCircle_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionPointCircle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_CheckCollisionPointTriangle_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionPointTriangle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(4,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Vector2"));
}


RING_FUNC(ring_LoadImage_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = LoadImage(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadImageEx_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = LoadImageEx((Color *) RING_API_GETCPOINTER(1,"Color"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadImagePro_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = LoadImagePro((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadImageRaw_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = LoadImageRaw(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_ExportImage_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ExportImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ExportImageAsCode_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ExportImageAsCode(* (Image  *) RING_API_GETCPOINTER(1,"Image"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_LoadTexture_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
		*pValue = LoadTexture(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadTextureFromImage_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
		*pValue = LoadTextureFromImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadTextureCubemap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TextureCubemap *pValue ; 
		pValue = (TextureCubemap *) RING_API_MALLOC(sizeof(TextureCubemap)) ;
		*pValue = LoadTextureCubemap(* (Image  *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TextureCubemap",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadRenderTexture_2)
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
	{
		RenderTexture2D *pValue ; 
		pValue = (RenderTexture2D *) RING_API_MALLOC(sizeof(RenderTexture2D)) ;
		*pValue = LoadRenderTexture( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"RenderTexture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UnloadImage_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_UnloadTexture_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_UnloadRenderTexture_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadRenderTexture(* (RenderTexture2D  *) RING_API_GETCPOINTER(1,"RenderTexture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"RenderTexture2D"));
}


RING_FUNC(ring_GetImageData_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(GetImageData(* (Image  *) RING_API_GETCPOINTER(1,"Image")),"Color");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_GetImageDataNormalized_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(GetImageDataNormalized(* (Image  *) RING_API_GETCPOINTER(1,"Image")),"Vector4");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_GetPixelDataSize)
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
	RING_API_RETNUMBER(GetPixelDataSize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_GetTextureData_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GetTextureData(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetScreenData_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GetScreenData();
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UpdateTexture_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_ImageCopy_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = ImageCopy(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_ImageToPOT_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageToPOT((Image *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_ImageFormat_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageFormat((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ImageAlphaMask_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageAlphaMask((Image *) RING_API_GETCPOINTER(1,"Image"),* (Image  *) RING_API_GETCPOINTER(2,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_ImageAlphaClear_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageAlphaClear((Image *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_ImageAlphaCrop_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageAlphaCrop((Image *) RING_API_GETCPOINTER(1,"Image"), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ImageAlphaPremultiply_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageAlphaPremultiply((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageCrop_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageCrop((Image *) RING_API_GETCPOINTER(1,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_ImageResize_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	ImageResize((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_ImageResizeNN_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	ImageResizeNN((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_ImageResizeCanvas_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	ImageResizeCanvas((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_ImageMipmaps_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageMipmaps((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageDither_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	ImageDither((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ImageExtractPalette_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETCPOINTER(ImageExtractPalette(* (Image  *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3)),"Color");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_ImageText_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = ImageText(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_ImageTextEx_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = ImageTextEx(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_ImageDraw_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageDraw((Image *) RING_API_GETCPOINTER(1,"Image"),* (Image  *) RING_API_GETCPOINTER(2,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(4,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Rectangle"));
}


RING_FUNC(ring_ImageDrawRectangle_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageDrawRectangle((Image *) RING_API_GETCPOINTER(1,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_ImageDrawRectangleLines_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageDrawRectangleLines((Image *) RING_API_GETCPOINTER(1,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"), (int ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_ImageDrawText_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageDrawText((Image *) RING_API_GETCPOINTER(1,"Image"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_ImageDrawTextEx_2)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
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
	ImageDrawTextEx((Image *) RING_API_GETCPOINTER(1,"Image"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Font  *) RING_API_GETCPOINTER(3,"Font"),RING_API_GETSTRING(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"Color"));
}


RING_FUNC(ring_ImageFlipVertical_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageFlipVertical((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageFlipHorizontal_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageFlipHorizontal((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageRotateCW_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageRotateCW((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageRotateCCW_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageRotateCCW((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageColorTint_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageColorTint((Image *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_ImageColorInvert_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageColorInvert((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageColorGrayscale_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageColorGrayscale((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageColorContrast_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageColorContrast((Image *) RING_API_GETCPOINTER(1,"Image"), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ImageColorBrightness_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageColorBrightness((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ImageColorReplace_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageColorReplace((Image *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_GenImageColor_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageColor( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenImageGradientV_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageGradientV( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenImageGradientH_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageGradientH( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenImageGradientRadial_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageGradientRadial( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenImageChecked_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageChecked( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenImageWhiteNoise_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageWhiteNoise( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenImagePerlinNoise_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImagePerlinNoise( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenImageCellular_2)
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageCellular( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenTextureMipmaps_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GenTextureMipmaps((Texture2D *) RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_SetTextureFilter_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTextureFilter(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_SetTextureWrap_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTextureWrap(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_DrawTexture_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	DrawTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTextureV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawTextureV(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawTextureEx_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawTextureEx(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawTextureRec_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTextureRec(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTextureQuad_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	DrawTextureQuad(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Rectangle  *) RING_API_GETCPOINTER(4,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawTexturePro_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawTexturePro(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"),* (Vector2  *) RING_API_GETCPOINTER(4,"Vector2"), (float ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawTextureNPatch_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawTextureNPatch(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (NPatchInfo  *) RING_API_GETCPOINTER(2,"NPatchInfo"),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"),* (Vector2  *) RING_API_GETCPOINTER(4,"Vector2"), (float ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"NPatchInfo"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_GetFontDefault_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Font *pValue ; 
		pValue = (Font *) RING_API_MALLOC(sizeof(Font)) ;
		*pValue = GetFontDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadFont_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Font *pValue ; 
		pValue = (Font *) RING_API_MALLOC(sizeof(Font)) ;
		*pValue = LoadFont(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadFontEx_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Font *pValue ; 
		pValue = (Font *) RING_API_MALLOC(sizeof(Font)) ;
		*pValue = LoadFontEx(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",RING_API_FREEFUNC);
	}
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_LoadFontFromImage_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Font *pValue ; 
		pValue = (Font *) RING_API_MALLOC(sizeof(Font)) ;
		*pValue = LoadFontFromImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadFontData_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(LoadFontData(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)),"CharInfo");
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_GenImageFontAtlas_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	{
		Image *pValue ; 
		pValue = (Image *) RING_API_MALLOC(sizeof(Image)) ;
		*pValue = GenImageFontAtlas((CharInfo *) RING_API_GETCPOINTER(1,"CharInfo"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UnloadFont_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadFont(* (Font  *) RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
}


RING_FUNC(ring_DrawFPS)
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
	DrawFPS( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_DrawText)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
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
	DrawText(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawTextEx_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	DrawTextEx(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawTextRec_2)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	DrawTextRec(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (bool ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"Color"));
}


RING_FUNC(ring_DrawTextRecEx_2)
{
	if ( RING_API_PARACOUNT != 11 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawTextRecEx(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (bool ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"), (int ) RING_API_GETNUMBER(8), (int ) RING_API_GETNUMBER(9),* (Color  *) RING_API_GETCPOINTER(10,"Color"),* (Color  *) RING_API_GETCPOINTER(11,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(10))
		RING_API_FREE(RING_API_GETCPOINTER(10,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(11))
		RING_API_FREE(RING_API_GETCPOINTER(11,"Color"));
}


RING_FUNC(ring_MeasureText)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(MeasureText(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_MeasureTextEx_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = MeasureTextEx(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetGlyphIndex_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetGlyphIndex(* (Font  *) RING_API_GETCPOINTER(1,"Font"), (int ) RING_API_GETNUMBER(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
}


RING_FUNC(ring_GetNextCodepoint)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetNextCodepoint(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_TextIsEqual)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TextIsEqual(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_TextLength)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TextLength(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_TextCountCodepoints)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TextCountCodepoints(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_TextFormat)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TextFormat(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_TextSubtext)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
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
	RING_API_RETSTRING(TextSubtext(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TextReplace)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TextReplace(RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_TextInsert)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TextInsert(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TextJoin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETSTRING(TextJoin((char **) RING_API_GETCPOINTER2POINTER(1,"char"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_TextSplit)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
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
	RING_API_RETCPOINTER(TextSplit(RING_API_GETSTRING(1), (char ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3)),"char");
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_TextAppend)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TextAppend(RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_TextFindIndex)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TextFindIndex(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_TextToUpper)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TextToUpper(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_TextToLower)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TextToLower(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_TextToPascal)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TextToPascal(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_TextToInteger)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TextToInteger(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_DrawLine3D_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawLine3D(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawCircle3D_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawCircle3D(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCube_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCube(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCubeV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawCubeV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawCubeWires_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCubeWires(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCubeWiresV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawCubeWiresV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawCubeTexture_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCubeTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawSphere_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawSphere(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawSphereEx_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawSphereEx(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawSphereWires_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawSphereWires(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCylinder_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCylinder(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawCylinderWires_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCylinderWires(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawPlane_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawPlane(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawRay_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawRay(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_DrawGrid)
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
	DrawGrid( (int ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_DrawGizmo_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	DrawGizmo(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
}


RING_FUNC(ring_LoadModel_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Model *pValue ; 
		pValue = (Model *) RING_API_MALLOC(sizeof(Model)) ;
		*pValue = LoadModel(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Model",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadModelFromMesh_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Model *pValue ; 
		pValue = (Model *) RING_API_MALLOC(sizeof(Model)) ;
		*pValue = LoadModelFromMesh(* (Mesh  *) RING_API_GETCPOINTER(1,"Mesh"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Mesh"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Model",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UnloadModel_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadModel(* (Model  *) RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Model"));
}


RING_FUNC(ring_LoadMeshes_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(LoadMeshes(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2)),"Mesh");
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_ExportMesh_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ExportMesh(* (Mesh  *) RING_API_GETCPOINTER(1,"Mesh"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Mesh"));
}


RING_FUNC(ring_UnloadMesh_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UnloadMesh((Mesh *) RING_API_GETCPOINTER(1,"Mesh"));
}


RING_FUNC(ring_LoadMaterials_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(LoadMaterials(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2)),"Material");
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_LoadMaterialDefault_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Material *pValue ; 
		pValue = (Material *) RING_API_MALLOC(sizeof(Material)) ;
		*pValue = LoadMaterialDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Material",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UnloadMaterial_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadMaterial(* (Material  *) RING_API_GETCPOINTER(1,"Material"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Material"));
}


RING_FUNC(ring_SetMaterialTexture_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetMaterialTexture((Material *) RING_API_GETCPOINTER(1,"Material"), (int ) RING_API_GETNUMBER(2),* (Texture2D  *) RING_API_GETCPOINTER(3,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Texture2D"));
}


RING_FUNC(ring_SetModelMeshMaterial_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	SetModelMeshMaterial((Model *) RING_API_GETCPOINTER(1,"Model"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_LoadModelAnimations_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(LoadModelAnimations(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2)),"ModelAnimation");
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_UpdateModelAnimation_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateModelAnimation(* (Model  *) RING_API_GETCPOINTER(1,"Model"),* (ModelAnimation  *) RING_API_GETCPOINTER(2,"ModelAnimation"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ModelAnimation"));
}


RING_FUNC(ring_UnloadModelAnimation_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadModelAnimation(* (ModelAnimation  *) RING_API_GETCPOINTER(1,"ModelAnimation"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ModelAnimation"));
}


RING_FUNC(ring_IsModelAnimationValid_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(IsModelAnimationValid(* (Model  *) RING_API_GETCPOINTER(1,"Model"),* (ModelAnimation  *) RING_API_GETCPOINTER(2,"ModelAnimation")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ModelAnimation"));
}


RING_FUNC(ring_GenMeshPoly_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshPoly( (int ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshPlane_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshPlane( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshCube_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshCube( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshSphere_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshSphere( (float ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshHemiSphere_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshHemiSphere( (float ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshCylinder_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshCylinder( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshTorus_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshTorus( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshKnot_2)
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
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshKnot( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshHeightmap_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshHeightmap(* (Image  *) RING_API_GETCPOINTER(1,"Image"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenMeshCubicmap_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Mesh *pValue ; 
		pValue = (Mesh *) RING_API_MALLOC(sizeof(Mesh)) ;
		*pValue = GenMeshCubicmap(* (Image  *) RING_API_GETCPOINTER(1,"Image"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MeshBoundingBox_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		BoundingBox *pValue ; 
		pValue = (BoundingBox *) RING_API_MALLOC(sizeof(BoundingBox)) ;
		*pValue = MeshBoundingBox(* (Mesh  *) RING_API_GETCPOINTER(1,"Mesh"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Mesh"));
		RING_API_RETMANAGEDCPOINTER(pValue,"BoundingBox",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MeshTangents_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	MeshTangents((Mesh *) RING_API_GETCPOINTER(1,"Mesh"));
}


RING_FUNC(ring_MeshBinormals_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	MeshBinormals((Mesh *) RING_API_GETCPOINTER(1,"Mesh"));
}


RING_FUNC(ring_DrawModel_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawModel(* (Model  *) RING_API_GETCPOINTER(1,"Model"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawModelEx_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawModelEx(* (Model  *) RING_API_GETCPOINTER(1,"Model"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"), (float ) RING_API_GETNUMBER(4),* (Vector3  *) RING_API_GETCPOINTER(5,"Vector3"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawModelWires_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawModelWires(* (Model  *) RING_API_GETCPOINTER(1,"Model"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawModelWiresEx_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawModelWiresEx(* (Model  *) RING_API_GETCPOINTER(1,"Model"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"), (float ) RING_API_GETNUMBER(4),* (Vector3  *) RING_API_GETCPOINTER(5,"Vector3"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawBoundingBox_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawBoundingBox(* (BoundingBox  *) RING_API_GETCPOINTER(1,"BoundingBox"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"BoundingBox"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_DrawBillboard_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawBillboard(* (Camera3D  *) RING_API_GETCPOINTER(1,"Camera3D"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawBillboardRec_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawBillboardRec(* (Camera3D  *) RING_API_GETCPOINTER(1,"Camera3D"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"),* (Vector3  *) RING_API_GETCPOINTER(4,"Vector3"), (float ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_CheckCollisionSpheres_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionSpheres(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"), (float ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
}


RING_FUNC(ring_CheckCollisionBoxes_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionBoxes(* (BoundingBox  *) RING_API_GETCPOINTER(1,"BoundingBox"),* (BoundingBox  *) RING_API_GETCPOINTER(2,"BoundingBox")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"BoundingBox"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"BoundingBox"));
}


RING_FUNC(ring_CheckCollisionBoxSphere_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionBoxSphere(* (BoundingBox  *) RING_API_GETCPOINTER(1,"BoundingBox"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"BoundingBox"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_CheckCollisionRaySphere_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionRaySphere(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_CheckCollisionRaySphereEx_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionRaySphereEx(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3),(Vector3 *) RING_API_GETCPOINTER(4,"Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_CheckCollisionRayBox_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionRayBox(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (BoundingBox  *) RING_API_GETCPOINTER(2,"BoundingBox")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"BoundingBox"));
}


RING_FUNC(ring_GetCollisionRayModel_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		RayHitInfo *pValue ; 
		pValue = (RayHitInfo *) RING_API_MALLOC(sizeof(RayHitInfo)) ;
		*pValue = GetCollisionRayModel(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),(Model *) RING_API_GETCPOINTER(2,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Ray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"RayHitInfo",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetCollisionRayTriangle_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	{
		RayHitInfo *pValue ; 
		pValue = (RayHitInfo *) RING_API_MALLOC(sizeof(RayHitInfo)) ;
		*pValue = GetCollisionRayTriangle(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(4,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"RayHitInfo",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetCollisionRayGround_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		RayHitInfo *pValue ; 
		pValue = (RayHitInfo *) RING_API_MALLOC(sizeof(RayHitInfo)) ;
		*pValue = GetCollisionRayGround(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Ray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"RayHitInfo",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(LoadText(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_LoadShader_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Shader *pValue ; 
		pValue = (Shader *) RING_API_MALLOC(sizeof(Shader)) ;
		*pValue = LoadShader(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Shader",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadShaderCode_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Shader *pValue ; 
		pValue = (Shader *) RING_API_MALLOC(sizeof(Shader)) ;
		*pValue = LoadShaderCode(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Shader",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UnloadShader_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadShader(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
}


RING_FUNC(ring_GetShaderDefault_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Shader *pValue ; 
		pValue = (Shader *) RING_API_MALLOC(sizeof(Shader)) ;
		*pValue = GetShaderDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Shader",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetTextureDefault_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
		*pValue = GetTextureDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GetShaderLocation_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetShaderLocation(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"),RING_API_GETSTRING(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
}


RING_FUNC(ring_SetShaderValue_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetShaderValue(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"), (int ) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"), (int ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
}


RING_FUNC(ring_SetShaderValueV_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	SetShaderValueV(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"), (int ) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
}


RING_FUNC(ring_SetShaderValueMatrix_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetShaderValueMatrix(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"), (int ) RING_API_GETNUMBER(2),* (Matrix  *) RING_API_GETCPOINTER(3,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Matrix"));
}


RING_FUNC(ring_SetShaderValueTexture_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetShaderValueTexture(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"), (int ) RING_API_GETNUMBER(2),* (Texture2D  *) RING_API_GETCPOINTER(3,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Texture2D"));
}


RING_FUNC(ring_SetMatrixProjection_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetMatrixProjection(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_SetMatrixModelview_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetMatrixModelview(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_GetMatrixModelview_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = GetMatrixModelview();
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenTextureCubemap_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
		*pValue = GenTextureCubemap(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenTextureIrradiance_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
		*pValue = GenTextureIrradiance(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenTexturePrefilter_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
		*pValue = GenTexturePrefilter(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GenTextureBRDF_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) RING_API_MALLOC(sizeof(Texture2D)) ;
		*pValue = GenTextureBRDF(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_BeginShaderMode_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	BeginShaderMode(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Shader"));
}


RING_FUNC(ring_EndShaderMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndShaderMode();
}


RING_FUNC(ring_BeginBlendMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	BeginBlendMode( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_EndBlendMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndBlendMode();
}


RING_FUNC(ring_BeginScissorMode)
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
	BeginScissorMode( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_EndScissorMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndScissorMode();
}


RING_FUNC(ring_InitVrSimulator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	InitVrSimulator();
}


RING_FUNC(ring_CloseVrSimulator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	CloseVrSimulator();
}


RING_FUNC(ring_UpdateVrTracking_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateVrTracking((Camera3D *) RING_API_GETCPOINTER(1,"Camera3D"));
}


RING_FUNC(ring_SetVrConfiguration_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	SetVrConfiguration(* (VrDeviceInfo  *) RING_API_GETCPOINTER(1,"VrDeviceInfo"),* (Shader  *) RING_API_GETCPOINTER(2,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"VrDeviceInfo"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Shader"));
}


RING_FUNC(ring_IsVrSimulatorReady)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsVrSimulatorReady());
}


RING_FUNC(ring_ToggleVrMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ToggleVrMode();
}


RING_FUNC(ring_BeginVrDrawing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	BeginVrDrawing();
}


RING_FUNC(ring_EndVrDrawing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndVrDrawing();
}


RING_FUNC(ring_InitAudioDevice)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	InitAudioDevice();
}


RING_FUNC(ring_CloseAudioDevice)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	CloseAudioDevice();
}


RING_FUNC(ring_IsAudioDeviceReady)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsAudioDeviceReady());
}


RING_FUNC(ring_SetMasterVolume)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetMasterVolume( (float ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_LoadWave_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Wave *pValue ; 
		pValue = (Wave *) RING_API_MALLOC(sizeof(Wave)) ;
		*pValue = LoadWave(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Wave",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadWaveEx_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	{
		Wave *pValue ; 
		pValue = (Wave *) RING_API_MALLOC(sizeof(Wave)) ;
		*pValue = LoadWaveEx((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Wave",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Sound *pValue ; 
		pValue = (Sound *) RING_API_MALLOC(sizeof(Sound)) ;
		*pValue = LoadSound(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Sound",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_LoadSoundFromWave_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Sound *pValue ; 
		pValue = (Sound *) RING_API_MALLOC(sizeof(Sound)) ;
		*pValue = LoadSoundFromWave(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Wave"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Sound",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UpdateSound_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"),(void *) RING_API_GETCPOINTER(2,"void"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_UnloadWave_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadWave(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Wave"));
}


RING_FUNC(ring_UnloadSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_ExportWave_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ExportWave(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Wave"));
}


RING_FUNC(ring_ExportWaveAsCode_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ExportWaveAsCode(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Wave"));
}


RING_FUNC(ring_PlaySound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PlaySound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_PauseSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PauseSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_ResumeSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ResumeSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_StopSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	StopSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_IsSoundPlaying_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsSoundPlaying(* (Sound  *) RING_API_GETCPOINTER(1,"Sound")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_SetSoundVolume_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetSoundVolume(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_SetSoundPitch_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetSoundPitch(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_WaveFormat_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	WaveFormat((Wave *) RING_API_GETCPOINTER(1,"Wave"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_WaveCopy_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Wave *pValue ; 
		pValue = (Wave *) RING_API_MALLOC(sizeof(Wave)) ;
		*pValue = WaveCopy(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Wave"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Wave",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_WaveCrop_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	WaveCrop((Wave *) RING_API_GETCPOINTER(1,"Wave"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_GetWaveData_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(GetWaveData(* (Wave  *) RING_API_GETCPOINTER(1,"Wave")),"float");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Wave"));
}


RING_FUNC(ring_LoadMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Music *pValue ; 
		pValue = (Music *) RING_API_MALLOC(sizeof(Music)) ;
		*pValue = LoadMusicStream(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Music",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UnloadMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_PlayMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PlayMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_UpdateMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UpdateMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_StopMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	StopMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_PauseMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PauseMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_ResumeMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ResumeMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_IsMusicPlaying_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsMusicPlaying(* (Music  *) RING_API_GETCPOINTER(1,"Music")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_SetMusicVolume_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetMusicVolume(* (Music  *) RING_API_GETCPOINTER(1,"Music"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_SetMusicPitch_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetMusicPitch(* (Music  *) RING_API_GETCPOINTER(1,"Music"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_SetMusicLoopCount_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetMusicLoopCount(* (Music  *) RING_API_GETCPOINTER(1,"Music"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_GetMusicTimeLength_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(GetMusicTimeLength(* (Music  *) RING_API_GETCPOINTER(1,"Music")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_GetMusicTimePlayed_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(GetMusicTimePlayed(* (Music  *) RING_API_GETCPOINTER(1,"Music")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_InitAudioStream_2)
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
	{
		AudioStream *pValue ; 
		pValue = (AudioStream *) RING_API_MALLOC(sizeof(AudioStream)) ;
		*pValue = InitAudioStream( (unsigned int ) RING_API_GETNUMBER(1), (unsigned int ) RING_API_GETNUMBER(2), (unsigned int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"AudioStream",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_UpdateAudioStream_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"),(void *) RING_API_GETCPOINTER(2,"void"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_CloseAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	CloseAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_IsAudioBufferProcessed_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsAudioBufferProcessed(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_PlayAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PlayAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_PauseAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PauseAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_ResumeAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ResumeAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_IsAudioStreamPlaying_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsAudioStreamPlaying(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_StopAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	StopAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_SetAudioStreamVolume_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetAudioStreamVolume(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_SetAudioStreamPitch_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetAudioStreamPitch(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_GuiEnable)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	GuiEnable();
}


RING_FUNC(ring_GuiDisable)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	GuiDisable();
}


RING_FUNC(ring_GuiLock)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	GuiLock();
}


RING_FUNC(ring_GuiUnlock)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	GuiUnlock();
}


RING_FUNC(ring_GuiState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiState( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_GuiFont)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	GuiFont(* (Font  *) RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Font"));
}


RING_FUNC(ring_GuiFade)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiFade( (float ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_GuiSetStyle)
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
	GuiSetStyle( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_GuiGetStyle)
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
	RING_API_RETNUMBER(GuiGetStyle( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_GuiWindowBox_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiWindowBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiGroupBox_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiGroupBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiLine_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiLine(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiPanel_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	GuiPanel(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiScrollPanel_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Rectangle *pValue ; 
		pValue = (Rectangle *) RING_API_MALLOC(sizeof(Rectangle)) ;
		*pValue = GuiScrollPanel(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"),(Vector2 *) RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Rectangle"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Rectangle",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GuiLabel_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiLabel(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiButton_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiButton(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiLabelButton_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiLabelButton(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiImageButton_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(GuiImageButton(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Texture2D"));
}


RING_FUNC(ring_GuiImageButtonEx_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiImageButtonEx(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"),RING_API_GETSTRING(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Rectangle"));
}


RING_FUNC(ring_GuiToggle_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiToggle(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (bool ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiToggleGroup_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiToggleGroup(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiCheckBox_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiCheckBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (bool ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiComboBox_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiComboBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiDropdownBox_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiDropdownBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2),RING_API_GETINTPOINTER(3), (bool ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_GuiSpinner_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETNUMBER(GuiSpinner(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETINTPOINTER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_GuiValueBox_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETNUMBER(GuiValueBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETINTPOINTER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_GuiTextBox_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETNUMBER(GuiTextBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiTextBoxMulti_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETNUMBER(GuiTextBoxMulti(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiSlider_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETNUMBER(GuiSlider(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (bool ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiSliderBar_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETNUMBER(GuiSliderBar(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (bool ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiProgressBar_2)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETNUMBER(GuiProgressBar(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (bool ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiStatusBar_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiStatusBar(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiDummyRec_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiDummyRec(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiScrollBar_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	RING_API_RETNUMBER(GuiScrollBar(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiGrid_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = GuiGrid(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GuiListView_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiListView(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4), (bool ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_GuiListViewEx_2)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiListViewEx(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (int ) RING_API_GETNUMBER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5),RING_API_GETINTPOINTER(6),RING_API_GETINTPOINTER(7), (bool ) RING_API_GETNUMBER(8)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
	RING_API_ACCEPTINTVALUE(6) ;
	RING_API_ACCEPTINTVALUE(7) ;
}


RING_FUNC(ring_GuiMessageBox_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiMessageBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiTextInputBox_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GuiTextInputBox(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiColorPicker_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Color *pValue ; 
		pValue = (Color *) RING_API_MALLOC(sizeof(Color)) ;
		*pValue = GuiColorPicker(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_GuiLoadStyle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiLoadStyle(RING_API_GETSTRING(1));
}


RING_FUNC(ring_GuiLoadStyleProps)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GuiLoadStyleProps(RING_API_GETINTPOINTER(1), (int ) RING_API_GETNUMBER(2));
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_GuiLoadStyleDefault)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	GuiLoadStyleDefault();
}


RING_FUNC(ring_GuiUpdateStyleComplete)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	GuiUpdateStyleComplete();
}


RING_FUNC(ring_GuiIconText)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GuiIconText( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_Clamp)
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
	RING_API_RETNUMBER(Clamp( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Lerp)
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
	RING_API_RETNUMBER(Lerp( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Normalize)
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
	RING_API_RETNUMBER(Normalize( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Remap)
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
	RING_API_RETNUMBER(Remap( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_Vector2Zero_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Zero();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2One_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2One();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Add_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Add(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2AddValue_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2AddValue(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Subtract_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Subtract(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2SubtractValue_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2SubtractValue(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Length_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2Length(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
}


RING_FUNC(ring_Vector2LengthSqr_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2LengthSqr(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
}


RING_FUNC(ring_Vector2DotProduct_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2DotProduct(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_Vector2Distance_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2Distance(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_Vector2Angle_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2Angle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_Vector2Scale_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Scale(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Multiply_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Multiply(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Negate_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Negate(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Divide_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Divide(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Normalize_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Normalize(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Lerp_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Lerp(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2Rotate_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2Rotate(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector2MoveTowards_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) RING_API_MALLOC(sizeof(Vector2)) ;
		*pValue = Vector2MoveTowards(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Zero_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Zero();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3One_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3One();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Add_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Add(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3AddValue_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3AddValue(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Subtract_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Subtract(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3SubtractValue_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3SubtractValue(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Scale_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Scale(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Multiply_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Multiply(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3CrossProduct_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3CrossProduct(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Perpendicular_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Perpendicular(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Length_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector3Length(* (const Vector3  *) RING_API_GETCPOINTER(1,"const Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
}


RING_FUNC(ring_Vector3LengthSqr_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector3LengthSqr(* (const Vector3  *) RING_API_GETCPOINTER(1,"const Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
}


RING_FUNC(ring_Vector3DotProduct_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector3DotProduct(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_Vector3Distance_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector3Distance(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_Vector3Negate_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Negate(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Divide_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Divide(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Normalize_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Normalize(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3OrthoNormalize_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	Vector3OrthoNormalize((Vector3 *) RING_API_GETCPOINTER(1,"Vector3"),(Vector3 *) RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_Vector3Transform_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Transform(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3RotateByQuaternion_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3RotateByQuaternion(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Lerp_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Lerp(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Reflect_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Reflect(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Min_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Min(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Max_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Max(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3Barycenter_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = Vector3Barycenter(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(4,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Vector3ToFloatV_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		float3 *pValue ; 
		pValue = (float3 *) RING_API_MALLOC(sizeof(float3)) ;
		*pValue = Vector3ToFloatV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"float3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixDeterminant_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(MatrixDeterminant(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_MatrixTrace_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(MatrixTrace(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_MatrixTranspose_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixTranspose(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixInvert_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixInvert(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixNormalize_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixNormalize(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixIdentity_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixIdentity();
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixAdd_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixAdd(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixSubtract_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixSubtract(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixTranslate_2)
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
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixTranslate( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixRotate_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixRotate(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixRotateXYZ_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixRotateXYZ(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixRotateX_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixRotateX( (float ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixRotateY_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixRotateY( (float ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixRotateZ_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixRotateZ( (float ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixScale_2)
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
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixScale( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixMultiply_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixMultiply(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixFrustum_2)
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
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixFrustum( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5), (double ) RING_API_GETNUMBER(6));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixPerspective_2)
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
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixPerspective( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixOrtho_2)
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
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixOrtho( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5), (double ) RING_API_GETNUMBER(6));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixLookAt_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = MatrixLookAt(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_MatrixToFloatV_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		float16 *pValue ; 
		pValue = (float16 *) RING_API_MALLOC(sizeof(float16)) ;
		*pValue = MatrixToFloatV(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"float16",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionAdd_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionAdd(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionAddValue_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionAddValue(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionSubtract_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionSubtract(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionSubtractValue_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionSubtractValue(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionIdentity_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionIdentity();
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionLength_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(QuaternionLength(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
}


RING_FUNC(ring_QuaternionNormalize_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionNormalize(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionInvert_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionInvert(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionMultiply_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionMultiply(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionScale_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionScale(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionDivide_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionDivide(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionLerp_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionLerp(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionNlerp_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionNlerp(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionSlerp_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionSlerp(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionFromVector3ToVector3_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionFromVector3ToVector3(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionFromMatrix_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionFromMatrix(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionToMatrix_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) RING_API_MALLOC(sizeof(Matrix)) ;
		*pValue = QuaternionToMatrix(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionFromAxisAngle_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionFromAxisAngle(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionToAxisAngle_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QuaternionToAxisAngle(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),(Vector3 *) RING_API_GETCPOINTER(2,"Vector3"),(float *) RING_API_GETCPOINTER(3,"float"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
}


RING_FUNC(ring_QuaternionFromEuler_2)
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
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionFromEuler( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionToEuler_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) RING_API_MALLOC(sizeof(Vector3)) ;
		*pValue = QuaternionToEuler(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QuaternionTransform_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) RING_API_MALLOC(sizeof(Quaternion)) ;
		*pValue = QuaternionTransform(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",RING_API_FREEFUNC);
	}
}

RING_FUNC(ring_setmodelmaterialtexture_2) {
	Model *model;
	int nMaterial,nMap;
	Texture2D *texture;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	model = RING_API_GETCPOINTER(1,"Model");
	nMaterial = (int) RING_API_GETNUMBER(2);
	nMap = (int) RING_API_GETNUMBER(3);
	texture = RING_API_GETCPOINTER(4,"Texture2D");
	model->materials[nMaterial].maps[nMap].texture = *texture ;
}

RING_FUNC(ring_setmodelmaterialshader_2) {
	Model *model;
	int nMaterial;
	Shader *shader;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	model = RING_API_GETCPOINTER(1,"Model");
	nMaterial = (int) RING_API_GETNUMBER(2);
	shader = RING_API_GETCPOINTER(3,"Shader");
	model->materials[nMaterial].shader = *shader ;
}

RING_FUNC(ring_getimagepixelr_2) {
	Color *data;
	int y,x,width;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	data = RING_API_GETCPOINTER(1,"Color");
	y = (int) RING_API_GETNUMBER(2);
	x = (int) RING_API_GETNUMBER(3);
	width = (int) RING_API_GETNUMBER(4);
	RING_API_RETNUMBER( (double) data[y*width + x].r ) ;
}

RING_FUNC(ring_getimagepixelg_2) {
	Color *data;
	int y,x,width;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	data = RING_API_GETCPOINTER(1,"Color");
	y = (int) RING_API_GETNUMBER(2);
	x = (int) RING_API_GETNUMBER(3);
	width = (int) RING_API_GETNUMBER(4);
	RING_API_RETNUMBER( (double) data[y*width + x].g ) ;
}

RING_FUNC(ring_getimagepixelb_2) {
	Color *data;
	int y,x,width;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	data = RING_API_GETCPOINTER(1,"Color");
	y = (int) RING_API_GETNUMBER(2);
	x = (int) RING_API_GETNUMBER(3);
	width = (int) RING_API_GETNUMBER(4);
	RING_API_RETNUMBER( (double) data[y*width + x].b ) ;
}

RING_FUNC(ring_getimagepixela_2) {
	Color *data;
	int y,x,width;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	data = RING_API_GETCPOINTER(1,"Color");
	y = (int) RING_API_GETNUMBER(2);
	x = (int) RING_API_GETNUMBER(3);
	width = (int) RING_API_GETNUMBER(4);
	RING_API_RETNUMBER( (double) data[y*width + x].a ) ;
}


RING_FUNC(ring_vec3set)
{
	Vector3 *pMyPointer ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	pMyPointer->x = RING_API_GETNUMBER(2);
	pMyPointer->y = RING_API_GETNUMBER(3);
	pMyPointer->z = RING_API_GETNUMBER(4);
}
RING_LIBINIT
{
	RING_API_REGISTER("initwindow",ring_InitWindow);
	RING_API_REGISTER("windowshouldclose",ring_WindowShouldClose);
	RING_API_REGISTER("closewindow",ring_CloseWindow);
	RING_API_REGISTER("iswindowready",ring_IsWindowReady);
	RING_API_REGISTER("iswindowminimized",ring_IsWindowMinimized);
	RING_API_REGISTER("iswindowresized",ring_IsWindowResized);
	RING_API_REGISTER("iswindowhidden",ring_IsWindowHidden);
	RING_API_REGISTER("togglefullscreen",ring_ToggleFullscreen);
	RING_API_REGISTER("unhidewindow",ring_UnhideWindow);
	RING_API_REGISTER("hidewindow",ring_HideWindow);
	RING_API_REGISTER("setwindowicon_2",ring_SetWindowIcon_2);
	RING_API_REGISTER("setwindowtitle",ring_SetWindowTitle);
	RING_API_REGISTER("setwindowposition",ring_SetWindowPosition);
	RING_API_REGISTER("setwindowmonitor",ring_SetWindowMonitor);
	RING_API_REGISTER("setwindowminsize",ring_SetWindowMinSize);
	RING_API_REGISTER("setwindowsize",ring_SetWindowSize);
	RING_API_REGISTER("getwindowhandle",ring_GetWindowHandle);
	RING_API_REGISTER("getscreenwidth",ring_GetScreenWidth);
	RING_API_REGISTER("getscreenheight",ring_GetScreenHeight);
	RING_API_REGISTER("getmonitorcount",ring_GetMonitorCount);
	RING_API_REGISTER("getmonitorwidth",ring_GetMonitorWidth);
	RING_API_REGISTER("getmonitorheight",ring_GetMonitorHeight);
	RING_API_REGISTER("getmonitorphysicalwidth",ring_GetMonitorPhysicalWidth);
	RING_API_REGISTER("getmonitorphysicalheight",ring_GetMonitorPhysicalHeight);
	RING_API_REGISTER("getmonitorname",ring_GetMonitorName);
	RING_API_REGISTER("getclipboardtext",ring_GetClipboardText);
	RING_API_REGISTER("setclipboardtext",ring_SetClipboardText);
	RING_API_REGISTER("showcursor",ring_ShowCursor);
	RING_API_REGISTER("hidecursor",ring_HideCursor);
	RING_API_REGISTER("iscursorhidden",ring_IsCursorHidden);
	RING_API_REGISTER("enablecursor",ring_EnableCursor);
	RING_API_REGISTER("disablecursor",ring_DisableCursor);
	RING_API_REGISTER("clearbackground_2",ring_ClearBackground_2);
	RING_API_REGISTER("begindrawing",ring_BeginDrawing);
	RING_API_REGISTER("enddrawing",ring_EndDrawing);
	RING_API_REGISTER("beginmode2d_2",ring_BeginMode2D_2);
	RING_API_REGISTER("endmode2d",ring_EndMode2D);
	RING_API_REGISTER("beginmode3d_2",ring_BeginMode3D_2);
	RING_API_REGISTER("endmode3d",ring_EndMode3D);
	RING_API_REGISTER("begintexturemode_2",ring_BeginTextureMode_2);
	RING_API_REGISTER("endtexturemode",ring_EndTextureMode);
	RING_API_REGISTER("getmouseray_2",ring_GetMouseRay_2);
	RING_API_REGISTER("getworldtoscreen_2",ring_GetWorldToScreen_2);
	RING_API_REGISTER("getcameramatrix_2",ring_GetCameraMatrix_2);
	RING_API_REGISTER("settargetfps",ring_SetTargetFPS);
	RING_API_REGISTER("getfps",ring_GetFPS);
	RING_API_REGISTER("getframetime",ring_GetFrameTime);
	RING_API_REGISTER("gettime",ring_GetTime);
	RING_API_REGISTER("colortoint_2",ring_ColorToInt_2);
	RING_API_REGISTER("colornormalize_2",ring_ColorNormalize_2);
	RING_API_REGISTER("colortohsv_2",ring_ColorToHSV_2);
	RING_API_REGISTER("colorfromhsv_2",ring_ColorFromHSV_2);
	RING_API_REGISTER("getcolor",ring_GetColor);
	RING_API_REGISTER("fade_2",ring_Fade_2);
	RING_API_REGISTER("setconfigflags",ring_SetConfigFlags);
	RING_API_REGISTER("settraceloglevel",ring_SetTraceLogLevel);
	RING_API_REGISTER("settracelogexit",ring_SetTraceLogExit);
	RING_API_REGISTER("settracelogcallback",ring_SetTraceLogCallback);
	RING_API_REGISTER("tracelog",ring_TraceLog);
	RING_API_REGISTER("takescreenshot",ring_TakeScreenshot);
	RING_API_REGISTER("getrandomvalue",ring_GetRandomValue);
	RING_API_REGISTER("fileexists",ring_FileExists);
	RING_API_REGISTER("isfileextension",ring_IsFileExtension);
	RING_API_REGISTER("getextension",ring_GetExtension);
	RING_API_REGISTER("getfilename",ring_GetFileName);
	RING_API_REGISTER("getfilenamewithoutext",ring_GetFileNameWithoutExt);
	RING_API_REGISTER("getdirectorypath",ring_GetDirectoryPath);
	RING_API_REGISTER("getworkingdirectory",ring_GetWorkingDirectory);
	RING_API_REGISTER("getdirectoryfiles",ring_GetDirectoryFiles);
	RING_API_REGISTER("cleardirectoryfiles",ring_ClearDirectoryFiles);
	RING_API_REGISTER("changedirectory",ring_ChangeDirectory);
	RING_API_REGISTER("isfiledropped",ring_IsFileDropped);
	RING_API_REGISTER("getdroppedfiles",ring_GetDroppedFiles);
	RING_API_REGISTER("cleardroppedfiles",ring_ClearDroppedFiles);
	RING_API_REGISTER("getfilemodtime",ring_GetFileModTime);
	RING_API_REGISTER("storagesavevalue",ring_StorageSaveValue);
	RING_API_REGISTER("storageloadvalue",ring_StorageLoadValue);
	RING_API_REGISTER("openurl",ring_OpenURL);
	RING_API_REGISTER("iskeypressed_2",ring_IsKeyPressed_2);
	RING_API_REGISTER("iskeydown_2",ring_IsKeyDown_2);
	RING_API_REGISTER("iskeyreleased_2",ring_IsKeyReleased_2);
	RING_API_REGISTER("iskeyup_2",ring_IsKeyUp_2);
	RING_API_REGISTER("getkeypressed",ring_GetKeyPressed);
	RING_API_REGISTER("setexitkey_2",ring_SetExitKey_2);
	RING_API_REGISTER("isgamepadavailable",ring_IsGamepadAvailable);
	RING_API_REGISTER("isgamepadname",ring_IsGamepadName);
	RING_API_REGISTER("getgamepadname",ring_GetGamepadName);
	RING_API_REGISTER("isgamepadbuttonpressed",ring_IsGamepadButtonPressed);
	RING_API_REGISTER("isgamepadbuttondown",ring_IsGamepadButtonDown);
	RING_API_REGISTER("isgamepadbuttonreleased",ring_IsGamepadButtonReleased);
	RING_API_REGISTER("isgamepadbuttonup",ring_IsGamepadButtonUp);
	RING_API_REGISTER("getgamepadbuttonpressed",ring_GetGamepadButtonPressed);
	RING_API_REGISTER("getgamepadaxiscount",ring_GetGamepadAxisCount);
	RING_API_REGISTER("getgamepadaxismovement",ring_GetGamepadAxisMovement);
	RING_API_REGISTER("ismousebuttonpressed",ring_IsMouseButtonPressed);
	RING_API_REGISTER("ismousebuttondown",ring_IsMouseButtonDown);
	RING_API_REGISTER("ismousebuttonreleased",ring_IsMouseButtonReleased);
	RING_API_REGISTER("ismousebuttonup",ring_IsMouseButtonUp);
	RING_API_REGISTER("getmousex",ring_GetMouseX);
	RING_API_REGISTER("getmousey",ring_GetMouseY);
	RING_API_REGISTER("getmouseposition_2",ring_GetMousePosition_2);
	RING_API_REGISTER("setmouseposition",ring_SetMousePosition);
	RING_API_REGISTER("setmouseoffset",ring_SetMouseOffset);
	RING_API_REGISTER("setmousescale",ring_SetMouseScale);
	RING_API_REGISTER("getmousewheelmove",ring_GetMouseWheelMove);
	RING_API_REGISTER("gettouchx",ring_GetTouchX);
	RING_API_REGISTER("gettouchy",ring_GetTouchY);
	RING_API_REGISTER("gettouchposition_2",ring_GetTouchPosition_2);
	RING_API_REGISTER("setgesturesenabled",ring_SetGesturesEnabled);
	RING_API_REGISTER("isgesturedetected",ring_IsGestureDetected);
	RING_API_REGISTER("getgesturedetected",ring_GetGestureDetected);
	RING_API_REGISTER("gettouchpointscount",ring_GetTouchPointsCount);
	RING_API_REGISTER("getgestureholdduration",ring_GetGestureHoldDuration);
	RING_API_REGISTER("getgesturedragvector_2",ring_GetGestureDragVector_2);
	RING_API_REGISTER("getgesturedragangle",ring_GetGestureDragAngle);
	RING_API_REGISTER("getgesturepinchvector_2",ring_GetGesturePinchVector_2);
	RING_API_REGISTER("getgesturepinchangle",ring_GetGesturePinchAngle);
	RING_API_REGISTER("setcameramode_2",ring_SetCameraMode_2);
	RING_API_REGISTER("updatecamera_2",ring_UpdateCamera_2);
	RING_API_REGISTER("setcamerapancontrol",ring_SetCameraPanControl);
	RING_API_REGISTER("setcameraaltcontrol",ring_SetCameraAltControl);
	RING_API_REGISTER("setcamerasmoothzoomcontrol",ring_SetCameraSmoothZoomControl);
	RING_API_REGISTER("setcameramovecontrols",ring_SetCameraMoveControls);
	RING_API_REGISTER("drawpixel_2",ring_DrawPixel_2);
	RING_API_REGISTER("drawpixelv_2",ring_DrawPixelV_2);
	RING_API_REGISTER("drawline_2",ring_DrawLine_2);
	RING_API_REGISTER("drawlinev_2",ring_DrawLineV_2);
	RING_API_REGISTER("drawlineex_2",ring_DrawLineEx_2);
	RING_API_REGISTER("drawlinebezier_2",ring_DrawLineBezier_2);
	RING_API_REGISTER("drawlinestrip_2",ring_DrawLineStrip_2);
	RING_API_REGISTER("drawcircle_2",ring_DrawCircle_2);
	RING_API_REGISTER("drawcirclesector_2",ring_DrawCircleSector_2);
	RING_API_REGISTER("drawcirclesectorlines_2",ring_DrawCircleSectorLines_2);
	RING_API_REGISTER("drawcirclegradient_2",ring_DrawCircleGradient_2);
	RING_API_REGISTER("drawcirclev_2",ring_DrawCircleV_2);
	RING_API_REGISTER("drawcirclelines_2",ring_DrawCircleLines_2);
	RING_API_REGISTER("drawring_2",ring_DrawRing_2);
	RING_API_REGISTER("drawringlines_2",ring_DrawRingLines_2);
	RING_API_REGISTER("drawrectangle_2",ring_DrawRectangle_2);
	RING_API_REGISTER("drawrectanglev_2",ring_DrawRectangleV_2);
	RING_API_REGISTER("drawrectanglerec_2",ring_DrawRectangleRec_2);
	RING_API_REGISTER("drawrectanglepro_2",ring_DrawRectanglePro_2);
	RING_API_REGISTER("drawrectanglegradientv_2",ring_DrawRectangleGradientV_2);
	RING_API_REGISTER("drawrectanglegradienth_2",ring_DrawRectangleGradientH_2);
	RING_API_REGISTER("drawrectanglegradientex_2",ring_DrawRectangleGradientEx_2);
	RING_API_REGISTER("drawrectanglelines_2",ring_DrawRectangleLines_2);
	RING_API_REGISTER("drawrectanglelinesex_2",ring_DrawRectangleLinesEx_2);
	RING_API_REGISTER("drawrectanglerounded_2",ring_DrawRectangleRounded_2);
	RING_API_REGISTER("drawrectangleroundedlines_2",ring_DrawRectangleRoundedLines_2);
	RING_API_REGISTER("drawtriangle_2",ring_DrawTriangle_2);
	RING_API_REGISTER("drawtrianglelines_2",ring_DrawTriangleLines_2);
	RING_API_REGISTER("drawtrianglefan_2",ring_DrawTriangleFan_2);
	RING_API_REGISTER("drawpoly_2",ring_DrawPoly_2);
	RING_API_REGISTER("setshapestexture_2",ring_SetShapesTexture_2);
	RING_API_REGISTER("checkcollisionrecs_2",ring_CheckCollisionRecs_2);
	RING_API_REGISTER("checkcollisioncircles_2",ring_CheckCollisionCircles_2);
	RING_API_REGISTER("checkcollisioncirclerec_2",ring_CheckCollisionCircleRec_2);
	RING_API_REGISTER("getcollisionrec_2",ring_GetCollisionRec_2);
	RING_API_REGISTER("checkcollisionpointrec_2",ring_CheckCollisionPointRec_2);
	RING_API_REGISTER("checkcollisionpointcircle_2",ring_CheckCollisionPointCircle_2);
	RING_API_REGISTER("checkcollisionpointtriangle_2",ring_CheckCollisionPointTriangle_2);
	RING_API_REGISTER("loadimage_2",ring_LoadImage_2);
	RING_API_REGISTER("loadimageex_2",ring_LoadImageEx_2);
	RING_API_REGISTER("loadimagepro_2",ring_LoadImagePro_2);
	RING_API_REGISTER("loadimageraw_2",ring_LoadImageRaw_2);
	RING_API_REGISTER("exportimage_2",ring_ExportImage_2);
	RING_API_REGISTER("exportimageascode_2",ring_ExportImageAsCode_2);
	RING_API_REGISTER("loadtexture_2",ring_LoadTexture_2);
	RING_API_REGISTER("loadtexturefromimage_2",ring_LoadTextureFromImage_2);
	RING_API_REGISTER("loadtexturecubemap",ring_LoadTextureCubemap);
	RING_API_REGISTER("loadrendertexture_2",ring_LoadRenderTexture_2);
	RING_API_REGISTER("unloadimage_2",ring_UnloadImage_2);
	RING_API_REGISTER("unloadtexture_2",ring_UnloadTexture_2);
	RING_API_REGISTER("unloadrendertexture_2",ring_UnloadRenderTexture_2);
	RING_API_REGISTER("getimagedata_2",ring_GetImageData_2);
	RING_API_REGISTER("getimagedatanormalized_2",ring_GetImageDataNormalized_2);
	RING_API_REGISTER("getpixeldatasize",ring_GetPixelDataSize);
	RING_API_REGISTER("gettexturedata_2",ring_GetTextureData_2);
	RING_API_REGISTER("getscreendata_2",ring_GetScreenData_2);
	RING_API_REGISTER("updatetexture_2",ring_UpdateTexture_2);
	RING_API_REGISTER("imagecopy_2",ring_ImageCopy_2);
	RING_API_REGISTER("imagetopot_2",ring_ImageToPOT_2);
	RING_API_REGISTER("imageformat_2",ring_ImageFormat_2);
	RING_API_REGISTER("imagealphamask_2",ring_ImageAlphaMask_2);
	RING_API_REGISTER("imagealphaclear_2",ring_ImageAlphaClear_2);
	RING_API_REGISTER("imagealphacrop_2",ring_ImageAlphaCrop_2);
	RING_API_REGISTER("imagealphapremultiply_2",ring_ImageAlphaPremultiply_2);
	RING_API_REGISTER("imagecrop_2",ring_ImageCrop_2);
	RING_API_REGISTER("imageresize_2",ring_ImageResize_2);
	RING_API_REGISTER("imageresizenn_2",ring_ImageResizeNN_2);
	RING_API_REGISTER("imageresizecanvas_2",ring_ImageResizeCanvas_2);
	RING_API_REGISTER("imagemipmaps_2",ring_ImageMipmaps_2);
	RING_API_REGISTER("imagedither_2",ring_ImageDither_2);
	RING_API_REGISTER("imageextractpalette_2",ring_ImageExtractPalette_2);
	RING_API_REGISTER("imagetext_2",ring_ImageText_2);
	RING_API_REGISTER("imagetextex_2",ring_ImageTextEx_2);
	RING_API_REGISTER("imagedraw_2",ring_ImageDraw_2);
	RING_API_REGISTER("imagedrawrectangle_2",ring_ImageDrawRectangle_2);
	RING_API_REGISTER("imagedrawrectanglelines_2",ring_ImageDrawRectangleLines_2);
	RING_API_REGISTER("imagedrawtext_2",ring_ImageDrawText_2);
	RING_API_REGISTER("imagedrawtextex_2",ring_ImageDrawTextEx_2);
	RING_API_REGISTER("imageflipvertical_2",ring_ImageFlipVertical_2);
	RING_API_REGISTER("imagefliphorizontal_2",ring_ImageFlipHorizontal_2);
	RING_API_REGISTER("imagerotatecw_2",ring_ImageRotateCW_2);
	RING_API_REGISTER("imagerotateccw_2",ring_ImageRotateCCW_2);
	RING_API_REGISTER("imagecolortint_2",ring_ImageColorTint_2);
	RING_API_REGISTER("imagecolorinvert_2",ring_ImageColorInvert_2);
	RING_API_REGISTER("imagecolorgrayscale_2",ring_ImageColorGrayscale_2);
	RING_API_REGISTER("imagecolorcontrast_2",ring_ImageColorContrast_2);
	RING_API_REGISTER("imagecolorbrightness_2",ring_ImageColorBrightness_2);
	RING_API_REGISTER("imagecolorreplace_2",ring_ImageColorReplace_2);
	RING_API_REGISTER("genimagecolor_2",ring_GenImageColor_2);
	RING_API_REGISTER("genimagegradientv_2",ring_GenImageGradientV_2);
	RING_API_REGISTER("genimagegradienth_2",ring_GenImageGradientH_2);
	RING_API_REGISTER("genimagegradientradial_2",ring_GenImageGradientRadial_2);
	RING_API_REGISTER("genimagechecked_2",ring_GenImageChecked_2);
	RING_API_REGISTER("genimagewhitenoise_2",ring_GenImageWhiteNoise_2);
	RING_API_REGISTER("genimageperlinnoise_2",ring_GenImagePerlinNoise_2);
	RING_API_REGISTER("genimagecellular_2",ring_GenImageCellular_2);
	RING_API_REGISTER("gentexturemipmaps_2",ring_GenTextureMipmaps_2);
	RING_API_REGISTER("settexturefilter_2",ring_SetTextureFilter_2);
	RING_API_REGISTER("settexturewrap_2",ring_SetTextureWrap_2);
	RING_API_REGISTER("drawtexture_2",ring_DrawTexture_2);
	RING_API_REGISTER("drawtexturev_2",ring_DrawTextureV_2);
	RING_API_REGISTER("drawtextureex_2",ring_DrawTextureEx_2);
	RING_API_REGISTER("drawtexturerec_2",ring_DrawTextureRec_2);
	RING_API_REGISTER("drawtexturequad_2",ring_DrawTextureQuad_2);
	RING_API_REGISTER("drawtexturepro_2",ring_DrawTexturePro_2);
	RING_API_REGISTER("drawtexturenpatch_2",ring_DrawTextureNPatch_2);
	RING_API_REGISTER("getfontdefault_2",ring_GetFontDefault_2);
	RING_API_REGISTER("loadfont_2",ring_LoadFont_2);
	RING_API_REGISTER("loadfontex_2",ring_LoadFontEx_2);
	RING_API_REGISTER("loadfontfromimage_2",ring_LoadFontFromImage_2);
	RING_API_REGISTER("loadfontdata_2",ring_LoadFontData_2);
	RING_API_REGISTER("genimagefontatlas_2",ring_GenImageFontAtlas_2);
	RING_API_REGISTER("unloadfont_2",ring_UnloadFont_2);
	RING_API_REGISTER("drawfps",ring_DrawFPS);
	RING_API_REGISTER("drawtext",ring_DrawText);
	RING_API_REGISTER("drawtextex_2",ring_DrawTextEx_2);
	RING_API_REGISTER("drawtextrec_2",ring_DrawTextRec_2);
	RING_API_REGISTER("drawtextrecex_2",ring_DrawTextRecEx_2);
	RING_API_REGISTER("measuretext",ring_MeasureText);
	RING_API_REGISTER("measuretextex_2",ring_MeasureTextEx_2);
	RING_API_REGISTER("getglyphindex_2",ring_GetGlyphIndex_2);
	RING_API_REGISTER("getnextcodepoint",ring_GetNextCodepoint);
	RING_API_REGISTER("textisequal",ring_TextIsEqual);
	RING_API_REGISTER("textlength",ring_TextLength);
	RING_API_REGISTER("textcountcodepoints",ring_TextCountCodepoints);
	RING_API_REGISTER("textformat",ring_TextFormat);
	RING_API_REGISTER("textsubtext",ring_TextSubtext);
	RING_API_REGISTER("textreplace",ring_TextReplace);
	RING_API_REGISTER("textinsert",ring_TextInsert);
	RING_API_REGISTER("textjoin",ring_TextJoin);
	RING_API_REGISTER("textsplit",ring_TextSplit);
	RING_API_REGISTER("textappend",ring_TextAppend);
	RING_API_REGISTER("textfindindex",ring_TextFindIndex);
	RING_API_REGISTER("texttoupper",ring_TextToUpper);
	RING_API_REGISTER("texttolower",ring_TextToLower);
	RING_API_REGISTER("texttopascal",ring_TextToPascal);
	RING_API_REGISTER("texttointeger",ring_TextToInteger);
	RING_API_REGISTER("drawline3d_2",ring_DrawLine3D_2);
	RING_API_REGISTER("drawcircle3d_2",ring_DrawCircle3D_2);
	RING_API_REGISTER("drawcube_2",ring_DrawCube_2);
	RING_API_REGISTER("drawcubev_2",ring_DrawCubeV_2);
	RING_API_REGISTER("drawcubewires_2",ring_DrawCubeWires_2);
	RING_API_REGISTER("drawcubewiresv_2",ring_DrawCubeWiresV_2);
	RING_API_REGISTER("drawcubetexture_2",ring_DrawCubeTexture_2);
	RING_API_REGISTER("drawsphere_2",ring_DrawSphere_2);
	RING_API_REGISTER("drawsphereex_2",ring_DrawSphereEx_2);
	RING_API_REGISTER("drawspherewires_2",ring_DrawSphereWires_2);
	RING_API_REGISTER("drawcylinder_2",ring_DrawCylinder_2);
	RING_API_REGISTER("drawcylinderwires_2",ring_DrawCylinderWires_2);
	RING_API_REGISTER("drawplane_2",ring_DrawPlane_2);
	RING_API_REGISTER("drawray_2",ring_DrawRay_2);
	RING_API_REGISTER("drawgrid",ring_DrawGrid);
	RING_API_REGISTER("drawgizmo_2",ring_DrawGizmo_2);
	RING_API_REGISTER("loadmodel_2",ring_LoadModel_2);
	RING_API_REGISTER("loadmodelfrommesh_2",ring_LoadModelFromMesh_2);
	RING_API_REGISTER("unloadmodel_2",ring_UnloadModel_2);
	RING_API_REGISTER("loadmeshes_2",ring_LoadMeshes_2);
	RING_API_REGISTER("exportmesh_2",ring_ExportMesh_2);
	RING_API_REGISTER("unloadmesh_2",ring_UnloadMesh_2);
	RING_API_REGISTER("loadmaterials_2",ring_LoadMaterials_2);
	RING_API_REGISTER("loadmaterialdefault_2",ring_LoadMaterialDefault_2);
	RING_API_REGISTER("unloadmaterial_2",ring_UnloadMaterial_2);
	RING_API_REGISTER("setmaterialtexture_2",ring_SetMaterialTexture_2);
	RING_API_REGISTER("setmodelmeshmaterial_2",ring_SetModelMeshMaterial_2);
	RING_API_REGISTER("loadmodelanimations_2",ring_LoadModelAnimations_2);
	RING_API_REGISTER("updatemodelanimation_2",ring_UpdateModelAnimation_2);
	RING_API_REGISTER("unloadmodelanimation_2",ring_UnloadModelAnimation_2);
	RING_API_REGISTER("ismodelanimationvalid_2",ring_IsModelAnimationValid_2);
	RING_API_REGISTER("genmeshpoly_2",ring_GenMeshPoly_2);
	RING_API_REGISTER("genmeshplane_2",ring_GenMeshPlane_2);
	RING_API_REGISTER("genmeshcube_2",ring_GenMeshCube_2);
	RING_API_REGISTER("genmeshsphere_2",ring_GenMeshSphere_2);
	RING_API_REGISTER("genmeshhemisphere_2",ring_GenMeshHemiSphere_2);
	RING_API_REGISTER("genmeshcylinder_2",ring_GenMeshCylinder_2);
	RING_API_REGISTER("genmeshtorus_2",ring_GenMeshTorus_2);
	RING_API_REGISTER("genmeshknot_2",ring_GenMeshKnot_2);
	RING_API_REGISTER("genmeshheightmap_2",ring_GenMeshHeightmap_2);
	RING_API_REGISTER("genmeshcubicmap_2",ring_GenMeshCubicmap_2);
	RING_API_REGISTER("meshboundingbox_2",ring_MeshBoundingBox_2);
	RING_API_REGISTER("meshtangents_2",ring_MeshTangents_2);
	RING_API_REGISTER("meshbinormals_2",ring_MeshBinormals_2);
	RING_API_REGISTER("drawmodel_2",ring_DrawModel_2);
	RING_API_REGISTER("drawmodelex_2",ring_DrawModelEx_2);
	RING_API_REGISTER("drawmodelwires_2",ring_DrawModelWires_2);
	RING_API_REGISTER("drawmodelwiresex_2",ring_DrawModelWiresEx_2);
	RING_API_REGISTER("drawboundingbox_2",ring_DrawBoundingBox_2);
	RING_API_REGISTER("drawbillboard_2",ring_DrawBillboard_2);
	RING_API_REGISTER("drawbillboardrec_2",ring_DrawBillboardRec_2);
	RING_API_REGISTER("checkcollisionspheres_2",ring_CheckCollisionSpheres_2);
	RING_API_REGISTER("checkcollisionboxes_2",ring_CheckCollisionBoxes_2);
	RING_API_REGISTER("checkcollisionboxsphere_2",ring_CheckCollisionBoxSphere_2);
	RING_API_REGISTER("checkcollisionraysphere_2",ring_CheckCollisionRaySphere_2);
	RING_API_REGISTER("checkcollisionraysphereex_2",ring_CheckCollisionRaySphereEx_2);
	RING_API_REGISTER("checkcollisionraybox_2",ring_CheckCollisionRayBox_2);
	RING_API_REGISTER("getcollisionraymodel_2",ring_GetCollisionRayModel_2);
	RING_API_REGISTER("getcollisionraytriangle_2",ring_GetCollisionRayTriangle_2);
	RING_API_REGISTER("getcollisionrayground_2",ring_GetCollisionRayGround_2);
	RING_API_REGISTER("loadtext",ring_LoadText);
	RING_API_REGISTER("loadshader_2",ring_LoadShader_2);
	RING_API_REGISTER("loadshadercode_2",ring_LoadShaderCode_2);
	RING_API_REGISTER("unloadshader_2",ring_UnloadShader_2);
	RING_API_REGISTER("getshaderdefault_2",ring_GetShaderDefault_2);
	RING_API_REGISTER("gettexturedefault_2",ring_GetTextureDefault_2);
	RING_API_REGISTER("getshaderlocation_2",ring_GetShaderLocation_2);
	RING_API_REGISTER("setshadervalue_2",ring_SetShaderValue_2);
	RING_API_REGISTER("setshadervaluev_2",ring_SetShaderValueV_2);
	RING_API_REGISTER("setshadervaluematrix_2",ring_SetShaderValueMatrix_2);
	RING_API_REGISTER("setshadervaluetexture_2",ring_SetShaderValueTexture_2);
	RING_API_REGISTER("setmatrixprojection_2",ring_SetMatrixProjection_2);
	RING_API_REGISTER("setmatrixmodelview_2",ring_SetMatrixModelview_2);
	RING_API_REGISTER("getmatrixmodelview_2",ring_GetMatrixModelview_2);
	RING_API_REGISTER("gentexturecubemap_2",ring_GenTextureCubemap_2);
	RING_API_REGISTER("gentextureirradiance_2",ring_GenTextureIrradiance_2);
	RING_API_REGISTER("gentextureprefilter_2",ring_GenTexturePrefilter_2);
	RING_API_REGISTER("gentexturebrdf_2",ring_GenTextureBRDF_2);
	RING_API_REGISTER("beginshadermode_2",ring_BeginShaderMode_2);
	RING_API_REGISTER("endshadermode",ring_EndShaderMode);
	RING_API_REGISTER("beginblendmode",ring_BeginBlendMode);
	RING_API_REGISTER("endblendmode",ring_EndBlendMode);
	RING_API_REGISTER("beginscissormode",ring_BeginScissorMode);
	RING_API_REGISTER("endscissormode",ring_EndScissorMode);
	RING_API_REGISTER("initvrsimulator",ring_InitVrSimulator);
	RING_API_REGISTER("closevrsimulator",ring_CloseVrSimulator);
	RING_API_REGISTER("updatevrtracking_2",ring_UpdateVrTracking_2);
	RING_API_REGISTER("setvrconfiguration_2",ring_SetVrConfiguration_2);
	RING_API_REGISTER("isvrsimulatorready",ring_IsVrSimulatorReady);
	RING_API_REGISTER("togglevrmode",ring_ToggleVrMode);
	RING_API_REGISTER("beginvrdrawing",ring_BeginVrDrawing);
	RING_API_REGISTER("endvrdrawing",ring_EndVrDrawing);
	RING_API_REGISTER("initaudiodevice",ring_InitAudioDevice);
	RING_API_REGISTER("closeaudiodevice",ring_CloseAudioDevice);
	RING_API_REGISTER("isaudiodeviceready",ring_IsAudioDeviceReady);
	RING_API_REGISTER("setmastervolume",ring_SetMasterVolume);
	RING_API_REGISTER("loadwave_2",ring_LoadWave_2);
	RING_API_REGISTER("loadwaveex_2",ring_LoadWaveEx_2);
	RING_API_REGISTER("loadsound_2",ring_LoadSound_2);
	RING_API_REGISTER("loadsoundfromwave_2",ring_LoadSoundFromWave_2);
	RING_API_REGISTER("updatesound_2",ring_UpdateSound_2);
	RING_API_REGISTER("unloadwave_2",ring_UnloadWave_2);
	RING_API_REGISTER("unloadsound_2",ring_UnloadSound_2);
	RING_API_REGISTER("exportwave_2",ring_ExportWave_2);
	RING_API_REGISTER("exportwaveascode_2",ring_ExportWaveAsCode_2);
	RING_API_REGISTER("playsound_2",ring_PlaySound_2);
	RING_API_REGISTER("pausesound_2",ring_PauseSound_2);
	RING_API_REGISTER("resumesound_2",ring_ResumeSound_2);
	RING_API_REGISTER("stopsound_2",ring_StopSound_2);
	RING_API_REGISTER("issoundplaying_2",ring_IsSoundPlaying_2);
	RING_API_REGISTER("setsoundvolume_2",ring_SetSoundVolume_2);
	RING_API_REGISTER("setsoundpitch_2",ring_SetSoundPitch_2);
	RING_API_REGISTER("waveformat_2",ring_WaveFormat_2);
	RING_API_REGISTER("wavecopy_2",ring_WaveCopy_2);
	RING_API_REGISTER("wavecrop_2",ring_WaveCrop_2);
	RING_API_REGISTER("getwavedata_2",ring_GetWaveData_2);
	RING_API_REGISTER("loadmusicstream_2",ring_LoadMusicStream_2);
	RING_API_REGISTER("unloadmusicstream_2",ring_UnloadMusicStream_2);
	RING_API_REGISTER("playmusicstream_2",ring_PlayMusicStream_2);
	RING_API_REGISTER("updatemusicstream_2",ring_UpdateMusicStream_2);
	RING_API_REGISTER("stopmusicstream_2",ring_StopMusicStream_2);
	RING_API_REGISTER("pausemusicstream_2",ring_PauseMusicStream_2);
	RING_API_REGISTER("resumemusicstream_2",ring_ResumeMusicStream_2);
	RING_API_REGISTER("ismusicplaying_2",ring_IsMusicPlaying_2);
	RING_API_REGISTER("setmusicvolume_2",ring_SetMusicVolume_2);
	RING_API_REGISTER("setmusicpitch_2",ring_SetMusicPitch_2);
	RING_API_REGISTER("setmusicloopcount_2",ring_SetMusicLoopCount_2);
	RING_API_REGISTER("getmusictimelength_2",ring_GetMusicTimeLength_2);
	RING_API_REGISTER("getmusictimeplayed_2",ring_GetMusicTimePlayed_2);
	RING_API_REGISTER("initaudiostream_2",ring_InitAudioStream_2);
	RING_API_REGISTER("updateaudiostream_2",ring_UpdateAudioStream_2);
	RING_API_REGISTER("closeaudiostream_2",ring_CloseAudioStream_2);
	RING_API_REGISTER("isaudiobufferprocessed_2",ring_IsAudioBufferProcessed_2);
	RING_API_REGISTER("playaudiostream_2",ring_PlayAudioStream_2);
	RING_API_REGISTER("pauseaudiostream_2",ring_PauseAudioStream_2);
	RING_API_REGISTER("resumeaudiostream_2",ring_ResumeAudioStream_2);
	RING_API_REGISTER("isaudiostreamplaying_2",ring_IsAudioStreamPlaying_2);
	RING_API_REGISTER("stopaudiostream_2",ring_StopAudioStream_2);
	RING_API_REGISTER("setaudiostreamvolume_2",ring_SetAudioStreamVolume_2);
	RING_API_REGISTER("setaudiostreampitch_2",ring_SetAudioStreamPitch_2);
	RING_API_REGISTER("guienable",ring_GuiEnable);
	RING_API_REGISTER("guidisable",ring_GuiDisable);
	RING_API_REGISTER("guilock",ring_GuiLock);
	RING_API_REGISTER("guiunlock",ring_GuiUnlock);
	RING_API_REGISTER("guistate",ring_GuiState);
	RING_API_REGISTER("guifont",ring_GuiFont);
	RING_API_REGISTER("guifade",ring_GuiFade);
	RING_API_REGISTER("guisetstyle",ring_GuiSetStyle);
	RING_API_REGISTER("guigetstyle",ring_GuiGetStyle);
	RING_API_REGISTER("guiwindowbox_2",ring_GuiWindowBox_2);
	RING_API_REGISTER("guigroupbox_2",ring_GuiGroupBox_2);
	RING_API_REGISTER("guiline_2",ring_GuiLine_2);
	RING_API_REGISTER("guipanel_2",ring_GuiPanel_2);
	RING_API_REGISTER("guiscrollpanel_2",ring_GuiScrollPanel_2);
	RING_API_REGISTER("guilabel_2",ring_GuiLabel_2);
	RING_API_REGISTER("guibutton_2",ring_GuiButton_2);
	RING_API_REGISTER("guilabelbutton_2",ring_GuiLabelButton_2);
	RING_API_REGISTER("guiimagebutton_2",ring_GuiImageButton_2);
	RING_API_REGISTER("guiimagebuttonex_2",ring_GuiImageButtonEx_2);
	RING_API_REGISTER("guitoggle_2",ring_GuiToggle_2);
	RING_API_REGISTER("guitogglegroup_2",ring_GuiToggleGroup_2);
	RING_API_REGISTER("guicheckbox_2",ring_GuiCheckBox_2);
	RING_API_REGISTER("guicombobox_2",ring_GuiComboBox_2);
	RING_API_REGISTER("guidropdownbox_2",ring_GuiDropdownBox_2);
	RING_API_REGISTER("guispinner_2",ring_GuiSpinner_2);
	RING_API_REGISTER("guivaluebox_2",ring_GuiValueBox_2);
	RING_API_REGISTER("guitextbox_2",ring_GuiTextBox_2);
	RING_API_REGISTER("guitextboxmulti_2",ring_GuiTextBoxMulti_2);
	RING_API_REGISTER("guislider_2",ring_GuiSlider_2);
	RING_API_REGISTER("guisliderbar_2",ring_GuiSliderBar_2);
	RING_API_REGISTER("guiprogressbar_2",ring_GuiProgressBar_2);
	RING_API_REGISTER("guistatusbar_2",ring_GuiStatusBar_2);
	RING_API_REGISTER("guidummyrec_2",ring_GuiDummyRec_2);
	RING_API_REGISTER("guiscrollbar_2",ring_GuiScrollBar_2);
	RING_API_REGISTER("guigrid_2",ring_GuiGrid_2);
	RING_API_REGISTER("guilistview_2",ring_GuiListView_2);
	RING_API_REGISTER("guilistviewex_2",ring_GuiListViewEx_2);
	RING_API_REGISTER("guimessagebox_2",ring_GuiMessageBox_2);
	RING_API_REGISTER("guitextinputbox_2",ring_GuiTextInputBox_2);
	RING_API_REGISTER("guicolorpicker_2",ring_GuiColorPicker_2);
	RING_API_REGISTER("guiloadstyle",ring_GuiLoadStyle);
	RING_API_REGISTER("guiloadstyleprops",ring_GuiLoadStyleProps);
	RING_API_REGISTER("guiloadstyledefault",ring_GuiLoadStyleDefault);
	RING_API_REGISTER("guiupdatestylecomplete",ring_GuiUpdateStyleComplete);
	RING_API_REGISTER("guiicontext",ring_GuiIconText);
	RING_API_REGISTER("clamp",ring_Clamp);
	RING_API_REGISTER("lerp",ring_Lerp);
	RING_API_REGISTER("normalize",ring_Normalize);
	RING_API_REGISTER("remap",ring_Remap);
	RING_API_REGISTER("vector2zero_2",ring_Vector2Zero_2);
	RING_API_REGISTER("vector2one_2",ring_Vector2One_2);
	RING_API_REGISTER("vector2add_2",ring_Vector2Add_2);
	RING_API_REGISTER("vector2addvalue_2",ring_Vector2AddValue_2);
	RING_API_REGISTER("vector2subtract_2",ring_Vector2Subtract_2);
	RING_API_REGISTER("vector2subtractvalue_2",ring_Vector2SubtractValue_2);
	RING_API_REGISTER("vector2length_2",ring_Vector2Length_2);
	RING_API_REGISTER("vector2lengthsqr_2",ring_Vector2LengthSqr_2);
	RING_API_REGISTER("vector2dotproduct_2",ring_Vector2DotProduct_2);
	RING_API_REGISTER("vector2distance_2",ring_Vector2Distance_2);
	RING_API_REGISTER("vector2angle_2",ring_Vector2Angle_2);
	RING_API_REGISTER("vector2scale_2",ring_Vector2Scale_2);
	RING_API_REGISTER("vector2multiply_2",ring_Vector2Multiply_2);
	RING_API_REGISTER("vector2negate_2",ring_Vector2Negate_2);
	RING_API_REGISTER("vector2divide_2",ring_Vector2Divide_2);
	RING_API_REGISTER("vector2normalize_2",ring_Vector2Normalize_2);
	RING_API_REGISTER("vector2lerp_2",ring_Vector2Lerp_2);
	RING_API_REGISTER("vector2rotate_2",ring_Vector2Rotate_2);
	RING_API_REGISTER("vector2movetowards_2",ring_Vector2MoveTowards_2);
	RING_API_REGISTER("vector3zero_2",ring_Vector3Zero_2);
	RING_API_REGISTER("vector3one_2",ring_Vector3One_2);
	RING_API_REGISTER("vector3add_2",ring_Vector3Add_2);
	RING_API_REGISTER("vector3addvalue_2",ring_Vector3AddValue_2);
	RING_API_REGISTER("vector3subtract_2",ring_Vector3Subtract_2);
	RING_API_REGISTER("vector3subtractvalue_2",ring_Vector3SubtractValue_2);
	RING_API_REGISTER("vector3scale_2",ring_Vector3Scale_2);
	RING_API_REGISTER("vector3multiply_2",ring_Vector3Multiply_2);
	RING_API_REGISTER("vector3crossproduct_2",ring_Vector3CrossProduct_2);
	RING_API_REGISTER("vector3perpendicular_2",ring_Vector3Perpendicular_2);
	RING_API_REGISTER("vector3length_2",ring_Vector3Length_2);
	RING_API_REGISTER("vector3lengthsqr_2",ring_Vector3LengthSqr_2);
	RING_API_REGISTER("vector3dotproduct_2",ring_Vector3DotProduct_2);
	RING_API_REGISTER("vector3distance_2",ring_Vector3Distance_2);
	RING_API_REGISTER("vector3negate_2",ring_Vector3Negate_2);
	RING_API_REGISTER("vector3divide_2",ring_Vector3Divide_2);
	RING_API_REGISTER("vector3normalize_2",ring_Vector3Normalize_2);
	RING_API_REGISTER("vector3orthonormalize_2",ring_Vector3OrthoNormalize_2);
	RING_API_REGISTER("vector3transform_2",ring_Vector3Transform_2);
	RING_API_REGISTER("vector3rotatebyquaternion_2",ring_Vector3RotateByQuaternion_2);
	RING_API_REGISTER("vector3lerp_2",ring_Vector3Lerp_2);
	RING_API_REGISTER("vector3reflect_2",ring_Vector3Reflect_2);
	RING_API_REGISTER("vector3min_2",ring_Vector3Min_2);
	RING_API_REGISTER("vector3max_2",ring_Vector3Max_2);
	RING_API_REGISTER("vector3barycenter_2",ring_Vector3Barycenter_2);
	RING_API_REGISTER("vector3tofloatv_2",ring_Vector3ToFloatV_2);
	RING_API_REGISTER("matrixdeterminant_2",ring_MatrixDeterminant_2);
	RING_API_REGISTER("matrixtrace_2",ring_MatrixTrace_2);
	RING_API_REGISTER("matrixtranspose_2",ring_MatrixTranspose_2);
	RING_API_REGISTER("matrixinvert_2",ring_MatrixInvert_2);
	RING_API_REGISTER("matrixnormalize_2",ring_MatrixNormalize_2);
	RING_API_REGISTER("matrixidentity_2",ring_MatrixIdentity_2);
	RING_API_REGISTER("matrixadd_2",ring_MatrixAdd_2);
	RING_API_REGISTER("matrixsubtract_2",ring_MatrixSubtract_2);
	RING_API_REGISTER("matrixtranslate_2",ring_MatrixTranslate_2);
	RING_API_REGISTER("matrixrotate_2",ring_MatrixRotate_2);
	RING_API_REGISTER("matrixrotatexyz_2",ring_MatrixRotateXYZ_2);
	RING_API_REGISTER("matrixrotatex_2",ring_MatrixRotateX_2);
	RING_API_REGISTER("matrixrotatey_2",ring_MatrixRotateY_2);
	RING_API_REGISTER("matrixrotatez_2",ring_MatrixRotateZ_2);
	RING_API_REGISTER("matrixscale_2",ring_MatrixScale_2);
	RING_API_REGISTER("matrixmultiply_2",ring_MatrixMultiply_2);
	RING_API_REGISTER("matrixfrustum_2",ring_MatrixFrustum_2);
	RING_API_REGISTER("matrixperspective_2",ring_MatrixPerspective_2);
	RING_API_REGISTER("matrixortho_2",ring_MatrixOrtho_2);
	RING_API_REGISTER("matrixlookat_2",ring_MatrixLookAt_2);
	RING_API_REGISTER("matrixtofloatv_2",ring_MatrixToFloatV_2);
	RING_API_REGISTER("quaternionadd_2",ring_QuaternionAdd_2);
	RING_API_REGISTER("quaternionaddvalue_2",ring_QuaternionAddValue_2);
	RING_API_REGISTER("quaternionsubtract_2",ring_QuaternionSubtract_2);
	RING_API_REGISTER("quaternionsubtractvalue_2",ring_QuaternionSubtractValue_2);
	RING_API_REGISTER("quaternionidentity_2",ring_QuaternionIdentity_2);
	RING_API_REGISTER("quaternionlength_2",ring_QuaternionLength_2);
	RING_API_REGISTER("quaternionnormalize_2",ring_QuaternionNormalize_2);
	RING_API_REGISTER("quaternioninvert_2",ring_QuaternionInvert_2);
	RING_API_REGISTER("quaternionmultiply_2",ring_QuaternionMultiply_2);
	RING_API_REGISTER("quaternionscale_2",ring_QuaternionScale_2);
	RING_API_REGISTER("quaterniondivide_2",ring_QuaternionDivide_2);
	RING_API_REGISTER("quaternionlerp_2",ring_QuaternionLerp_2);
	RING_API_REGISTER("quaternionnlerp_2",ring_QuaternionNlerp_2);
	RING_API_REGISTER("quaternionslerp_2",ring_QuaternionSlerp_2);
	RING_API_REGISTER("quaternionfromvector3tovector3_2",ring_QuaternionFromVector3ToVector3_2);
	RING_API_REGISTER("quaternionfrommatrix_2",ring_QuaternionFromMatrix_2);
	RING_API_REGISTER("quaterniontomatrix_2",ring_QuaternionToMatrix_2);
	RING_API_REGISTER("quaternionfromaxisangle_2",ring_QuaternionFromAxisAngle_2);
	RING_API_REGISTER("quaterniontoaxisangle_2",ring_QuaternionToAxisAngle_2);
	RING_API_REGISTER("quaternionfromeuler_2",ring_QuaternionFromEuler_2);
	RING_API_REGISTER("quaterniontoeuler_2",ring_QuaternionToEuler_2);
	RING_API_REGISTER("quaterniontransform_2",ring_QuaternionTransform_2);
	RING_API_REGISTER("setmodelmaterialtexture_2",ring_setmodelmaterialtexture_2);
	RING_API_REGISTER("setmodelmaterialshader_2",ring_setmodelmaterialshader_2);
	RING_API_REGISTER("getimagepixelr_2",ring_getimagepixelr_2);
	RING_API_REGISTER("getimagepixelg_2",ring_getimagepixelg_2);
	RING_API_REGISTER("getimagepixelb_2",ring_getimagepixelb_2);
	RING_API_REGISTER("getimagepixela_2",ring_getimagepixela_2);
	RING_API_REGISTER("vec3set",ring_vec3set);
	RING_API_REGISTER("raylib_new_vector2",ring_raylib_new_vector2);
	RING_API_REGISTER("raylib_new_managed_vector2",ring_raylib_new_managed_vector2);
	RING_API_REGISTER("raylib_destroy_vector2",ring_raylib_destroy_vector2);
	RING_API_REGISTER("raylib_get_vector2_x",ring_raylib_get_vector2_x);
	RING_API_REGISTER("raylib_set_vector2_x",ring_raylib_set_vector2_x);
	RING_API_REGISTER("raylib_get_vector2_y",ring_raylib_get_vector2_y);
	RING_API_REGISTER("raylib_set_vector2_y",ring_raylib_set_vector2_y);
	RING_API_REGISTER("raylib_new_vector3",ring_raylib_new_vector3);
	RING_API_REGISTER("raylib_new_managed_vector3",ring_raylib_new_managed_vector3);
	RING_API_REGISTER("raylib_destroy_vector3",ring_raylib_destroy_vector3);
	RING_API_REGISTER("raylib_get_vector3_x",ring_raylib_get_vector3_x);
	RING_API_REGISTER("raylib_set_vector3_x",ring_raylib_set_vector3_x);
	RING_API_REGISTER("raylib_get_vector3_y",ring_raylib_get_vector3_y);
	RING_API_REGISTER("raylib_set_vector3_y",ring_raylib_set_vector3_y);
	RING_API_REGISTER("raylib_get_vector3_z",ring_raylib_get_vector3_z);
	RING_API_REGISTER("raylib_set_vector3_z",ring_raylib_set_vector3_z);
	RING_API_REGISTER("raylib_new_vector4",ring_raylib_new_vector4);
	RING_API_REGISTER("raylib_new_managed_vector4",ring_raylib_new_managed_vector4);
	RING_API_REGISTER("raylib_destroy_vector4",ring_raylib_destroy_vector4);
	RING_API_REGISTER("raylib_get_vector4_x",ring_raylib_get_vector4_x);
	RING_API_REGISTER("raylib_set_vector4_x",ring_raylib_set_vector4_x);
	RING_API_REGISTER("raylib_get_vector4_y",ring_raylib_get_vector4_y);
	RING_API_REGISTER("raylib_set_vector4_y",ring_raylib_set_vector4_y);
	RING_API_REGISTER("raylib_get_vector4_z",ring_raylib_get_vector4_z);
	RING_API_REGISTER("raylib_set_vector4_z",ring_raylib_set_vector4_z);
	RING_API_REGISTER("raylib_get_vector4_w",ring_raylib_get_vector4_w);
	RING_API_REGISTER("raylib_set_vector4_w",ring_raylib_set_vector4_w);
	RING_API_REGISTER("raylib_new_quaternion",ring_raylib_new_quaternion);
	RING_API_REGISTER("raylib_new_managed_quaternion",ring_raylib_new_managed_quaternion);
	RING_API_REGISTER("raylib_destroy_quaternion",ring_raylib_destroy_quaternion);
	RING_API_REGISTER("raylib_get_quaternion_x",ring_raylib_get_quaternion_x);
	RING_API_REGISTER("raylib_set_quaternion_x",ring_raylib_set_quaternion_x);
	RING_API_REGISTER("raylib_get_quaternion_y",ring_raylib_get_quaternion_y);
	RING_API_REGISTER("raylib_set_quaternion_y",ring_raylib_set_quaternion_y);
	RING_API_REGISTER("raylib_get_quaternion_z",ring_raylib_get_quaternion_z);
	RING_API_REGISTER("raylib_set_quaternion_z",ring_raylib_set_quaternion_z);
	RING_API_REGISTER("raylib_get_quaternion_w",ring_raylib_get_quaternion_w);
	RING_API_REGISTER("raylib_set_quaternion_w",ring_raylib_set_quaternion_w);
	RING_API_REGISTER("raylib_new_matrix",ring_raylib_new_matrix);
	RING_API_REGISTER("raylib_new_managed_matrix",ring_raylib_new_managed_matrix);
	RING_API_REGISTER("raylib_destroy_matrix",ring_raylib_destroy_matrix);
	RING_API_REGISTER("raylib_get_matrix_m0",ring_raylib_get_matrix_m0);
	RING_API_REGISTER("raylib_set_matrix_m0",ring_raylib_set_matrix_m0);
	RING_API_REGISTER("raylib_get_matrix_m1",ring_raylib_get_matrix_m1);
	RING_API_REGISTER("raylib_set_matrix_m1",ring_raylib_set_matrix_m1);
	RING_API_REGISTER("raylib_get_matrix_m2",ring_raylib_get_matrix_m2);
	RING_API_REGISTER("raylib_set_matrix_m2",ring_raylib_set_matrix_m2);
	RING_API_REGISTER("raylib_get_matrix_m3",ring_raylib_get_matrix_m3);
	RING_API_REGISTER("raylib_set_matrix_m3",ring_raylib_set_matrix_m3);
	RING_API_REGISTER("raylib_get_matrix_m4",ring_raylib_get_matrix_m4);
	RING_API_REGISTER("raylib_set_matrix_m4",ring_raylib_set_matrix_m4);
	RING_API_REGISTER("raylib_get_matrix_m5",ring_raylib_get_matrix_m5);
	RING_API_REGISTER("raylib_set_matrix_m5",ring_raylib_set_matrix_m5);
	RING_API_REGISTER("raylib_get_matrix_m6",ring_raylib_get_matrix_m6);
	RING_API_REGISTER("raylib_set_matrix_m6",ring_raylib_set_matrix_m6);
	RING_API_REGISTER("raylib_get_matrix_m7",ring_raylib_get_matrix_m7);
	RING_API_REGISTER("raylib_set_matrix_m7",ring_raylib_set_matrix_m7);
	RING_API_REGISTER("raylib_get_matrix_m8",ring_raylib_get_matrix_m8);
	RING_API_REGISTER("raylib_set_matrix_m8",ring_raylib_set_matrix_m8);
	RING_API_REGISTER("raylib_get_matrix_m9",ring_raylib_get_matrix_m9);
	RING_API_REGISTER("raylib_set_matrix_m9",ring_raylib_set_matrix_m9);
	RING_API_REGISTER("raylib_get_matrix_m10",ring_raylib_get_matrix_m10);
	RING_API_REGISTER("raylib_set_matrix_m10",ring_raylib_set_matrix_m10);
	RING_API_REGISTER("raylib_get_matrix_m11",ring_raylib_get_matrix_m11);
	RING_API_REGISTER("raylib_set_matrix_m11",ring_raylib_set_matrix_m11);
	RING_API_REGISTER("raylib_get_matrix_m12",ring_raylib_get_matrix_m12);
	RING_API_REGISTER("raylib_set_matrix_m12",ring_raylib_set_matrix_m12);
	RING_API_REGISTER("raylib_get_matrix_m13",ring_raylib_get_matrix_m13);
	RING_API_REGISTER("raylib_set_matrix_m13",ring_raylib_set_matrix_m13);
	RING_API_REGISTER("raylib_get_matrix_m14",ring_raylib_get_matrix_m14);
	RING_API_REGISTER("raylib_set_matrix_m14",ring_raylib_set_matrix_m14);
	RING_API_REGISTER("raylib_get_matrix_m15",ring_raylib_get_matrix_m15);
	RING_API_REGISTER("raylib_set_matrix_m15",ring_raylib_set_matrix_m15);
	RING_API_REGISTER("raylib_new_color",ring_raylib_new_color);
	RING_API_REGISTER("raylib_new_managed_color",ring_raylib_new_managed_color);
	RING_API_REGISTER("raylib_destroy_color",ring_raylib_destroy_color);
	RING_API_REGISTER("raylib_get_color_r",ring_raylib_get_color_r);
	RING_API_REGISTER("raylib_set_color_r",ring_raylib_set_color_r);
	RING_API_REGISTER("raylib_get_color_g",ring_raylib_get_color_g);
	RING_API_REGISTER("raylib_set_color_g",ring_raylib_set_color_g);
	RING_API_REGISTER("raylib_get_color_b",ring_raylib_get_color_b);
	RING_API_REGISTER("raylib_set_color_b",ring_raylib_set_color_b);
	RING_API_REGISTER("raylib_get_color_a",ring_raylib_get_color_a);
	RING_API_REGISTER("raylib_set_color_a",ring_raylib_set_color_a);
	RING_API_REGISTER("raylib_new_rectangle",ring_raylib_new_rectangle);
	RING_API_REGISTER("raylib_new_managed_rectangle",ring_raylib_new_managed_rectangle);
	RING_API_REGISTER("raylib_destroy_rectangle",ring_raylib_destroy_rectangle);
	RING_API_REGISTER("raylib_get_rectangle_x",ring_raylib_get_rectangle_x);
	RING_API_REGISTER("raylib_set_rectangle_x",ring_raylib_set_rectangle_x);
	RING_API_REGISTER("raylib_get_rectangle_y",ring_raylib_get_rectangle_y);
	RING_API_REGISTER("raylib_set_rectangle_y",ring_raylib_set_rectangle_y);
	RING_API_REGISTER("raylib_get_rectangle_width",ring_raylib_get_rectangle_width);
	RING_API_REGISTER("raylib_set_rectangle_width",ring_raylib_set_rectangle_width);
	RING_API_REGISTER("raylib_get_rectangle_height",ring_raylib_get_rectangle_height);
	RING_API_REGISTER("raylib_set_rectangle_height",ring_raylib_set_rectangle_height);
	RING_API_REGISTER("raylib_new_image",ring_raylib_new_image);
	RING_API_REGISTER("raylib_new_managed_image",ring_raylib_new_managed_image);
	RING_API_REGISTER("raylib_destroy_image",ring_raylib_destroy_image);
	RING_API_REGISTER("raylib_get_image_data",ring_raylib_get_image_data);
	RING_API_REGISTER("raylib_set_image_data",ring_raylib_set_image_data);
	RING_API_REGISTER("raylib_get_image_width",ring_raylib_get_image_width);
	RING_API_REGISTER("raylib_set_image_width",ring_raylib_set_image_width);
	RING_API_REGISTER("raylib_get_image_height",ring_raylib_get_image_height);
	RING_API_REGISTER("raylib_set_image_height",ring_raylib_set_image_height);
	RING_API_REGISTER("raylib_get_image_mipmaps",ring_raylib_get_image_mipmaps);
	RING_API_REGISTER("raylib_set_image_mipmaps",ring_raylib_set_image_mipmaps);
	RING_API_REGISTER("raylib_get_image_format",ring_raylib_get_image_format);
	RING_API_REGISTER("raylib_set_image_format",ring_raylib_set_image_format);
	RING_API_REGISTER("raylib_new_texture2d",ring_raylib_new_texture2d);
	RING_API_REGISTER("raylib_new_managed_texture2d",ring_raylib_new_managed_texture2d);
	RING_API_REGISTER("raylib_destroy_texture2d",ring_raylib_destroy_texture2d);
	RING_API_REGISTER("raylib_get_texture2d_id",ring_raylib_get_texture2d_id);
	RING_API_REGISTER("raylib_set_texture2d_id",ring_raylib_set_texture2d_id);
	RING_API_REGISTER("raylib_get_texture2d_width",ring_raylib_get_texture2d_width);
	RING_API_REGISTER("raylib_set_texture2d_width",ring_raylib_set_texture2d_width);
	RING_API_REGISTER("raylib_get_texture2d_height",ring_raylib_get_texture2d_height);
	RING_API_REGISTER("raylib_set_texture2d_height",ring_raylib_set_texture2d_height);
	RING_API_REGISTER("raylib_get_texture2d_mipmaps",ring_raylib_get_texture2d_mipmaps);
	RING_API_REGISTER("raylib_set_texture2d_mipmaps",ring_raylib_set_texture2d_mipmaps);
	RING_API_REGISTER("raylib_get_texture2d_format",ring_raylib_get_texture2d_format);
	RING_API_REGISTER("raylib_set_texture2d_format",ring_raylib_set_texture2d_format);
	RING_API_REGISTER("raylib_new_texture",ring_raylib_new_texture);
	RING_API_REGISTER("raylib_new_managed_texture",ring_raylib_new_managed_texture);
	RING_API_REGISTER("raylib_destroy_texture",ring_raylib_destroy_texture);
	RING_API_REGISTER("raylib_get_texture_id",ring_raylib_get_texture_id);
	RING_API_REGISTER("raylib_set_texture_id",ring_raylib_set_texture_id);
	RING_API_REGISTER("raylib_get_texture_width",ring_raylib_get_texture_width);
	RING_API_REGISTER("raylib_set_texture_width",ring_raylib_set_texture_width);
	RING_API_REGISTER("raylib_get_texture_height",ring_raylib_get_texture_height);
	RING_API_REGISTER("raylib_set_texture_height",ring_raylib_set_texture_height);
	RING_API_REGISTER("raylib_get_texture_mipmaps",ring_raylib_get_texture_mipmaps);
	RING_API_REGISTER("raylib_set_texture_mipmaps",ring_raylib_set_texture_mipmaps);
	RING_API_REGISTER("raylib_get_texture_format",ring_raylib_get_texture_format);
	RING_API_REGISTER("raylib_set_texture_format",ring_raylib_set_texture_format);
	RING_API_REGISTER("raylib_new_rendertexture2d",ring_raylib_new_rendertexture2d);
	RING_API_REGISTER("raylib_new_managed_rendertexture2d",ring_raylib_new_managed_rendertexture2d);
	RING_API_REGISTER("raylib_destroy_rendertexture2d",ring_raylib_destroy_rendertexture2d);
	RING_API_REGISTER("raylib_get_rendertexture2d_id",ring_raylib_get_rendertexture2d_id);
	RING_API_REGISTER("raylib_set_rendertexture2d_id",ring_raylib_set_rendertexture2d_id);
	RING_API_REGISTER("raylib_get_rendertexture2d_texture_id",ring_raylib_get_rendertexture2d_texture_id);
	RING_API_REGISTER("raylib_set_rendertexture2d_texture_id",ring_raylib_set_rendertexture2d_texture_id);
	RING_API_REGISTER("raylib_get_rendertexture2d_texture_width",ring_raylib_get_rendertexture2d_texture_width);
	RING_API_REGISTER("raylib_set_rendertexture2d_texture_width",ring_raylib_set_rendertexture2d_texture_width);
	RING_API_REGISTER("raylib_get_rendertexture2d_texture_height",ring_raylib_get_rendertexture2d_texture_height);
	RING_API_REGISTER("raylib_set_rendertexture2d_texture_height",ring_raylib_set_rendertexture2d_texture_height);
	RING_API_REGISTER("raylib_get_rendertexture2d_texture_mipmaps",ring_raylib_get_rendertexture2d_texture_mipmaps);
	RING_API_REGISTER("raylib_set_rendertexture2d_texture_mipmaps",ring_raylib_set_rendertexture2d_texture_mipmaps);
	RING_API_REGISTER("raylib_get_rendertexture2d_texture_format",ring_raylib_get_rendertexture2d_texture_format);
	RING_API_REGISTER("raylib_set_rendertexture2d_texture_format",ring_raylib_set_rendertexture2d_texture_format);
	RING_API_REGISTER("raylib_get_rendertexture2d_depth_id",ring_raylib_get_rendertexture2d_depth_id);
	RING_API_REGISTER("raylib_set_rendertexture2d_depth_id",ring_raylib_set_rendertexture2d_depth_id);
	RING_API_REGISTER("raylib_get_rendertexture2d_depth_width",ring_raylib_get_rendertexture2d_depth_width);
	RING_API_REGISTER("raylib_set_rendertexture2d_depth_width",ring_raylib_set_rendertexture2d_depth_width);
	RING_API_REGISTER("raylib_get_rendertexture2d_depth_height",ring_raylib_get_rendertexture2d_depth_height);
	RING_API_REGISTER("raylib_set_rendertexture2d_depth_height",ring_raylib_set_rendertexture2d_depth_height);
	RING_API_REGISTER("raylib_get_rendertexture2d_depth_mipmaps",ring_raylib_get_rendertexture2d_depth_mipmaps);
	RING_API_REGISTER("raylib_set_rendertexture2d_depth_mipmaps",ring_raylib_set_rendertexture2d_depth_mipmaps);
	RING_API_REGISTER("raylib_get_rendertexture2d_depth_format",ring_raylib_get_rendertexture2d_depth_format);
	RING_API_REGISTER("raylib_set_rendertexture2d_depth_format",ring_raylib_set_rendertexture2d_depth_format);
	RING_API_REGISTER("raylib_get_rendertexture2d_depthtexture",ring_raylib_get_rendertexture2d_depthTexture);
	RING_API_REGISTER("raylib_set_rendertexture2d_depthtexture",ring_raylib_set_rendertexture2d_depthTexture);
	RING_API_REGISTER("raylib_new_rendertexture",ring_raylib_new_rendertexture);
	RING_API_REGISTER("raylib_new_managed_rendertexture",ring_raylib_new_managed_rendertexture);
	RING_API_REGISTER("raylib_destroy_rendertexture",ring_raylib_destroy_rendertexture);
	RING_API_REGISTER("raylib_get_rendertexture_id",ring_raylib_get_rendertexture_id);
	RING_API_REGISTER("raylib_set_rendertexture_id",ring_raylib_set_rendertexture_id);
	RING_API_REGISTER("raylib_get_rendertexture_texture_id",ring_raylib_get_rendertexture_texture_id);
	RING_API_REGISTER("raylib_set_rendertexture_texture_id",ring_raylib_set_rendertexture_texture_id);
	RING_API_REGISTER("raylib_get_rendertexture_texture_width",ring_raylib_get_rendertexture_texture_width);
	RING_API_REGISTER("raylib_set_rendertexture_texture_width",ring_raylib_set_rendertexture_texture_width);
	RING_API_REGISTER("raylib_get_rendertexture_texture_height",ring_raylib_get_rendertexture_texture_height);
	RING_API_REGISTER("raylib_set_rendertexture_texture_height",ring_raylib_set_rendertexture_texture_height);
	RING_API_REGISTER("raylib_get_rendertexture_texture_mipmaps",ring_raylib_get_rendertexture_texture_mipmaps);
	RING_API_REGISTER("raylib_set_rendertexture_texture_mipmaps",ring_raylib_set_rendertexture_texture_mipmaps);
	RING_API_REGISTER("raylib_get_rendertexture_texture_format",ring_raylib_get_rendertexture_texture_format);
	RING_API_REGISTER("raylib_set_rendertexture_texture_format",ring_raylib_set_rendertexture_texture_format);
	RING_API_REGISTER("raylib_get_rendertexture_depth_id",ring_raylib_get_rendertexture_depth_id);
	RING_API_REGISTER("raylib_set_rendertexture_depth_id",ring_raylib_set_rendertexture_depth_id);
	RING_API_REGISTER("raylib_get_rendertexture_depth_width",ring_raylib_get_rendertexture_depth_width);
	RING_API_REGISTER("raylib_set_rendertexture_depth_width",ring_raylib_set_rendertexture_depth_width);
	RING_API_REGISTER("raylib_get_rendertexture_depth_height",ring_raylib_get_rendertexture_depth_height);
	RING_API_REGISTER("raylib_set_rendertexture_depth_height",ring_raylib_set_rendertexture_depth_height);
	RING_API_REGISTER("raylib_get_rendertexture_depth_mipmaps",ring_raylib_get_rendertexture_depth_mipmaps);
	RING_API_REGISTER("raylib_set_rendertexture_depth_mipmaps",ring_raylib_set_rendertexture_depth_mipmaps);
	RING_API_REGISTER("raylib_get_rendertexture_depth_format",ring_raylib_get_rendertexture_depth_format);
	RING_API_REGISTER("raylib_set_rendertexture_depth_format",ring_raylib_set_rendertexture_depth_format);
	RING_API_REGISTER("raylib_get_rendertexture_depthtexture",ring_raylib_get_rendertexture_depthTexture);
	RING_API_REGISTER("raylib_set_rendertexture_depthtexture",ring_raylib_set_rendertexture_depthTexture);
	RING_API_REGISTER("raylib_new_npatchinfo",ring_raylib_new_npatchinfo);
	RING_API_REGISTER("raylib_new_managed_npatchinfo",ring_raylib_new_managed_npatchinfo);
	RING_API_REGISTER("raylib_destroy_npatchinfo",ring_raylib_destroy_npatchinfo);
	RING_API_REGISTER("raylib_get_npatchinfo_sourcerec_x",ring_raylib_get_npatchinfo_sourceRec_x);
	RING_API_REGISTER("raylib_set_npatchinfo_sourcerec_x",ring_raylib_set_npatchinfo_sourceRec_x);
	RING_API_REGISTER("raylib_get_npatchinfo_sourcerec_y",ring_raylib_get_npatchinfo_sourceRec_y);
	RING_API_REGISTER("raylib_set_npatchinfo_sourcerec_y",ring_raylib_set_npatchinfo_sourceRec_y);
	RING_API_REGISTER("raylib_get_npatchinfo_sourcerec_width",ring_raylib_get_npatchinfo_sourceRec_width);
	RING_API_REGISTER("raylib_set_npatchinfo_sourcerec_width",ring_raylib_set_npatchinfo_sourceRec_width);
	RING_API_REGISTER("raylib_get_npatchinfo_sourcerec_height",ring_raylib_get_npatchinfo_sourceRec_height);
	RING_API_REGISTER("raylib_set_npatchinfo_sourcerec_height",ring_raylib_set_npatchinfo_sourceRec_height);
	RING_API_REGISTER("raylib_get_npatchinfo_left",ring_raylib_get_npatchinfo_left);
	RING_API_REGISTER("raylib_set_npatchinfo_left",ring_raylib_set_npatchinfo_left);
	RING_API_REGISTER("raylib_get_npatchinfo_top",ring_raylib_get_npatchinfo_top);
	RING_API_REGISTER("raylib_set_npatchinfo_top",ring_raylib_set_npatchinfo_top);
	RING_API_REGISTER("raylib_get_npatchinfo_right",ring_raylib_get_npatchinfo_right);
	RING_API_REGISTER("raylib_set_npatchinfo_right",ring_raylib_set_npatchinfo_right);
	RING_API_REGISTER("raylib_get_npatchinfo_bottom",ring_raylib_get_npatchinfo_bottom);
	RING_API_REGISTER("raylib_set_npatchinfo_bottom",ring_raylib_set_npatchinfo_bottom);
	RING_API_REGISTER("raylib_get_npatchinfo_type",ring_raylib_get_npatchinfo_type);
	RING_API_REGISTER("raylib_set_npatchinfo_type",ring_raylib_set_npatchinfo_type);
	RING_API_REGISTER("raylib_new_charinfo",ring_raylib_new_charinfo);
	RING_API_REGISTER("raylib_new_managed_charinfo",ring_raylib_new_managed_charinfo);
	RING_API_REGISTER("raylib_destroy_charinfo",ring_raylib_destroy_charinfo);
	RING_API_REGISTER("raylib_get_charinfo_value",ring_raylib_get_charinfo_value);
	RING_API_REGISTER("raylib_set_charinfo_value",ring_raylib_set_charinfo_value);
	RING_API_REGISTER("raylib_get_charinfo_rec_x",ring_raylib_get_charinfo_rec_x);
	RING_API_REGISTER("raylib_set_charinfo_rec_x",ring_raylib_set_charinfo_rec_x);
	RING_API_REGISTER("raylib_get_charinfo_rec_y",ring_raylib_get_charinfo_rec_y);
	RING_API_REGISTER("raylib_set_charinfo_rec_y",ring_raylib_set_charinfo_rec_y);
	RING_API_REGISTER("raylib_get_charinfo_rec_width",ring_raylib_get_charinfo_rec_width);
	RING_API_REGISTER("raylib_set_charinfo_rec_width",ring_raylib_set_charinfo_rec_width);
	RING_API_REGISTER("raylib_get_charinfo_rec_height",ring_raylib_get_charinfo_rec_height);
	RING_API_REGISTER("raylib_set_charinfo_rec_height",ring_raylib_set_charinfo_rec_height);
	RING_API_REGISTER("raylib_get_charinfo_offsetx",ring_raylib_get_charinfo_offsetX);
	RING_API_REGISTER("raylib_set_charinfo_offsetx",ring_raylib_set_charinfo_offsetX);
	RING_API_REGISTER("raylib_get_charinfo_offsety",ring_raylib_get_charinfo_offsetY);
	RING_API_REGISTER("raylib_set_charinfo_offsety",ring_raylib_set_charinfo_offsetY);
	RING_API_REGISTER("raylib_get_charinfo_advancex",ring_raylib_get_charinfo_advanceX);
	RING_API_REGISTER("raylib_set_charinfo_advancex",ring_raylib_set_charinfo_advanceX);
	RING_API_REGISTER("raylib_get_charinfo_data",ring_raylib_get_charinfo_data);
	RING_API_REGISTER("raylib_set_charinfo_data",ring_raylib_set_charinfo_data);
	RING_API_REGISTER("raylib_new_font",ring_raylib_new_font);
	RING_API_REGISTER("raylib_new_managed_font",ring_raylib_new_managed_font);
	RING_API_REGISTER("raylib_destroy_font",ring_raylib_destroy_font);
	RING_API_REGISTER("raylib_get_font_texture_id",ring_raylib_get_font_texture_id);
	RING_API_REGISTER("raylib_set_font_texture_id",ring_raylib_set_font_texture_id);
	RING_API_REGISTER("raylib_get_font_texture_width",ring_raylib_get_font_texture_width);
	RING_API_REGISTER("raylib_set_font_texture_width",ring_raylib_set_font_texture_width);
	RING_API_REGISTER("raylib_get_font_texture_height",ring_raylib_get_font_texture_height);
	RING_API_REGISTER("raylib_set_font_texture_height",ring_raylib_set_font_texture_height);
	RING_API_REGISTER("raylib_get_font_texture_mipmaps",ring_raylib_get_font_texture_mipmaps);
	RING_API_REGISTER("raylib_set_font_texture_mipmaps",ring_raylib_set_font_texture_mipmaps);
	RING_API_REGISTER("raylib_get_font_texture_format",ring_raylib_get_font_texture_format);
	RING_API_REGISTER("raylib_set_font_texture_format",ring_raylib_set_font_texture_format);
	RING_API_REGISTER("raylib_get_font_basesize",ring_raylib_get_font_baseSize);
	RING_API_REGISTER("raylib_set_font_basesize",ring_raylib_set_font_baseSize);
	RING_API_REGISTER("raylib_get_font_charscount",ring_raylib_get_font_charsCount);
	RING_API_REGISTER("raylib_set_font_charscount",ring_raylib_set_font_charsCount);
	RING_API_REGISTER("raylib_get_font_chars",ring_raylib_get_font_chars);
	RING_API_REGISTER("raylib_set_font_chars",ring_raylib_set_font_chars);
	RING_API_REGISTER("raylib_new_spritefont",ring_raylib_new_spritefont);
	RING_API_REGISTER("raylib_new_managed_spritefont",ring_raylib_new_managed_spritefont);
	RING_API_REGISTER("raylib_destroy_spritefont",ring_raylib_destroy_spritefont);
	RING_API_REGISTER("raylib_get_spritefont_texture_id",ring_raylib_get_spritefont_texture_id);
	RING_API_REGISTER("raylib_set_spritefont_texture_id",ring_raylib_set_spritefont_texture_id);
	RING_API_REGISTER("raylib_get_spritefont_texture_width",ring_raylib_get_spritefont_texture_width);
	RING_API_REGISTER("raylib_set_spritefont_texture_width",ring_raylib_set_spritefont_texture_width);
	RING_API_REGISTER("raylib_get_spritefont_texture_height",ring_raylib_get_spritefont_texture_height);
	RING_API_REGISTER("raylib_set_spritefont_texture_height",ring_raylib_set_spritefont_texture_height);
	RING_API_REGISTER("raylib_get_spritefont_texture_mipmaps",ring_raylib_get_spritefont_texture_mipmaps);
	RING_API_REGISTER("raylib_set_spritefont_texture_mipmaps",ring_raylib_set_spritefont_texture_mipmaps);
	RING_API_REGISTER("raylib_get_spritefont_texture_format",ring_raylib_get_spritefont_texture_format);
	RING_API_REGISTER("raylib_set_spritefont_texture_format",ring_raylib_set_spritefont_texture_format);
	RING_API_REGISTER("raylib_get_spritefont_basesize",ring_raylib_get_spritefont_baseSize);
	RING_API_REGISTER("raylib_set_spritefont_basesize",ring_raylib_set_spritefont_baseSize);
	RING_API_REGISTER("raylib_get_spritefont_charscount",ring_raylib_get_spritefont_charsCount);
	RING_API_REGISTER("raylib_set_spritefont_charscount",ring_raylib_set_spritefont_charsCount);
	RING_API_REGISTER("raylib_get_spritefont_chars",ring_raylib_get_spritefont_chars);
	RING_API_REGISTER("raylib_set_spritefont_chars",ring_raylib_set_spritefont_chars);
	RING_API_REGISTER("raylib_new_camera3d",ring_raylib_new_camera3d);
	RING_API_REGISTER("raylib_new_managed_camera3d",ring_raylib_new_managed_camera3d);
	RING_API_REGISTER("raylib_destroy_camera3d",ring_raylib_destroy_camera3d);
	RING_API_REGISTER("raylib_get_camera3d_position_x",ring_raylib_get_camera3d_position_x);
	RING_API_REGISTER("raylib_set_camera3d_position_x",ring_raylib_set_camera3d_position_x);
	RING_API_REGISTER("raylib_get_camera3d_position_y",ring_raylib_get_camera3d_position_y);
	RING_API_REGISTER("raylib_set_camera3d_position_y",ring_raylib_set_camera3d_position_y);
	RING_API_REGISTER("raylib_get_camera3d_position_z",ring_raylib_get_camera3d_position_z);
	RING_API_REGISTER("raylib_set_camera3d_position_z",ring_raylib_set_camera3d_position_z);
	RING_API_REGISTER("raylib_get_camera3d_target_x",ring_raylib_get_camera3d_target_x);
	RING_API_REGISTER("raylib_set_camera3d_target_x",ring_raylib_set_camera3d_target_x);
	RING_API_REGISTER("raylib_get_camera3d_target_y",ring_raylib_get_camera3d_target_y);
	RING_API_REGISTER("raylib_set_camera3d_target_y",ring_raylib_set_camera3d_target_y);
	RING_API_REGISTER("raylib_get_camera3d_target_z",ring_raylib_get_camera3d_target_z);
	RING_API_REGISTER("raylib_set_camera3d_target_z",ring_raylib_set_camera3d_target_z);
	RING_API_REGISTER("raylib_get_camera3d_up_x",ring_raylib_get_camera3d_up_x);
	RING_API_REGISTER("raylib_set_camera3d_up_x",ring_raylib_set_camera3d_up_x);
	RING_API_REGISTER("raylib_get_camera3d_up_y",ring_raylib_get_camera3d_up_y);
	RING_API_REGISTER("raylib_set_camera3d_up_y",ring_raylib_set_camera3d_up_y);
	RING_API_REGISTER("raylib_get_camera3d_up_z",ring_raylib_get_camera3d_up_z);
	RING_API_REGISTER("raylib_set_camera3d_up_z",ring_raylib_set_camera3d_up_z);
	RING_API_REGISTER("raylib_get_camera3d_fovy",ring_raylib_get_camera3d_fovy);
	RING_API_REGISTER("raylib_set_camera3d_fovy",ring_raylib_set_camera3d_fovy);
	RING_API_REGISTER("raylib_get_camera3d_type",ring_raylib_get_camera3d_type);
	RING_API_REGISTER("raylib_set_camera3d_type",ring_raylib_set_camera3d_type);
	RING_API_REGISTER("raylib_new_mesh",ring_raylib_new_mesh);
	RING_API_REGISTER("raylib_new_managed_mesh",ring_raylib_new_managed_mesh);
	RING_API_REGISTER("raylib_destroy_mesh",ring_raylib_destroy_mesh);
	RING_API_REGISTER("raylib_get_mesh_vertexcount",ring_raylib_get_mesh_vertexCount);
	RING_API_REGISTER("raylib_set_mesh_vertexcount",ring_raylib_set_mesh_vertexCount);
	RING_API_REGISTER("raylib_get_mesh_trianglecount",ring_raylib_get_mesh_triangleCount);
	RING_API_REGISTER("raylib_set_mesh_trianglecount",ring_raylib_set_mesh_triangleCount);
	RING_API_REGISTER("raylib_get_mesh_vertices",ring_raylib_get_mesh_vertices);
	RING_API_REGISTER("raylib_set_mesh_vertices",ring_raylib_set_mesh_vertices);
	RING_API_REGISTER("raylib_get_mesh_texcoords",ring_raylib_get_mesh_texcoords);
	RING_API_REGISTER("raylib_set_mesh_texcoords",ring_raylib_set_mesh_texcoords);
	RING_API_REGISTER("raylib_get_mesh_texcoords2",ring_raylib_get_mesh_texcoords2);
	RING_API_REGISTER("raylib_set_mesh_texcoords2",ring_raylib_set_mesh_texcoords2);
	RING_API_REGISTER("raylib_get_mesh_normals",ring_raylib_get_mesh_normals);
	RING_API_REGISTER("raylib_set_mesh_normals",ring_raylib_set_mesh_normals);
	RING_API_REGISTER("raylib_get_mesh_tangents",ring_raylib_get_mesh_tangents);
	RING_API_REGISTER("raylib_set_mesh_tangents",ring_raylib_set_mesh_tangents);
	RING_API_REGISTER("raylib_get_mesh_colors",ring_raylib_get_mesh_colors);
	RING_API_REGISTER("raylib_set_mesh_colors",ring_raylib_set_mesh_colors);
	RING_API_REGISTER("raylib_get_mesh_indices",ring_raylib_get_mesh_indices);
	RING_API_REGISTER("raylib_set_mesh_indices",ring_raylib_set_mesh_indices);
	RING_API_REGISTER("raylib_get_mesh_animvertices",ring_raylib_get_mesh_animVertices);
	RING_API_REGISTER("raylib_set_mesh_animvertices",ring_raylib_set_mesh_animVertices);
	RING_API_REGISTER("raylib_get_mesh_animnormals",ring_raylib_get_mesh_animNormals);
	RING_API_REGISTER("raylib_set_mesh_animnormals",ring_raylib_set_mesh_animNormals);
	RING_API_REGISTER("raylib_get_mesh_boneids",ring_raylib_get_mesh_boneIds);
	RING_API_REGISTER("raylib_set_mesh_boneids",ring_raylib_set_mesh_boneIds);
	RING_API_REGISTER("raylib_get_mesh_boneweights",ring_raylib_get_mesh_boneWeights);
	RING_API_REGISTER("raylib_set_mesh_boneweights",ring_raylib_set_mesh_boneWeights);
	RING_API_REGISTER("raylib_get_mesh_vaoid",ring_raylib_get_mesh_vaoId);
	RING_API_REGISTER("raylib_set_mesh_vaoid",ring_raylib_set_mesh_vaoId);
	RING_API_REGISTER("raylib_new_shader",ring_raylib_new_shader);
	RING_API_REGISTER("raylib_new_managed_shader",ring_raylib_new_managed_shader);
	RING_API_REGISTER("raylib_destroy_shader",ring_raylib_destroy_shader);
	RING_API_REGISTER("raylib_get_shader_id",ring_raylib_get_shader_id);
	RING_API_REGISTER("raylib_set_shader_id",ring_raylib_set_shader_id);
	RING_API_REGISTER("raylib_new_materialmap",ring_raylib_new_materialmap);
	RING_API_REGISTER("raylib_new_managed_materialmap",ring_raylib_new_managed_materialmap);
	RING_API_REGISTER("raylib_destroy_materialmap",ring_raylib_destroy_materialmap);
	RING_API_REGISTER("raylib_get_materialmap_texture_id",ring_raylib_get_materialmap_texture_id);
	RING_API_REGISTER("raylib_set_materialmap_texture_id",ring_raylib_set_materialmap_texture_id);
	RING_API_REGISTER("raylib_get_materialmap_texture_width",ring_raylib_get_materialmap_texture_width);
	RING_API_REGISTER("raylib_set_materialmap_texture_width",ring_raylib_set_materialmap_texture_width);
	RING_API_REGISTER("raylib_get_materialmap_texture_height",ring_raylib_get_materialmap_texture_height);
	RING_API_REGISTER("raylib_set_materialmap_texture_height",ring_raylib_set_materialmap_texture_height);
	RING_API_REGISTER("raylib_get_materialmap_texture_mipmaps",ring_raylib_get_materialmap_texture_mipmaps);
	RING_API_REGISTER("raylib_set_materialmap_texture_mipmaps",ring_raylib_set_materialmap_texture_mipmaps);
	RING_API_REGISTER("raylib_get_materialmap_texture_format",ring_raylib_get_materialmap_texture_format);
	RING_API_REGISTER("raylib_set_materialmap_texture_format",ring_raylib_set_materialmap_texture_format);
	RING_API_REGISTER("raylib_get_materialmap_value",ring_raylib_get_materialmap_value);
	RING_API_REGISTER("raylib_set_materialmap_value",ring_raylib_set_materialmap_value);
	RING_API_REGISTER("raylib_new_material",ring_raylib_new_material);
	RING_API_REGISTER("raylib_new_managed_material",ring_raylib_new_managed_material);
	RING_API_REGISTER("raylib_destroy_material",ring_raylib_destroy_material);
	RING_API_REGISTER("raylib_get_material_shader_id",ring_raylib_get_material_shader_id);
	RING_API_REGISTER("raylib_set_material_shader_id",ring_raylib_set_material_shader_id);
	RING_API_REGISTER("raylib_get_material_params",ring_raylib_get_material_params);
	RING_API_REGISTER("raylib_set_material_params",ring_raylib_set_material_params);
	RING_API_REGISTER("raylib_new_transform",ring_raylib_new_transform);
	RING_API_REGISTER("raylib_new_managed_transform",ring_raylib_new_managed_transform);
	RING_API_REGISTER("raylib_destroy_transform",ring_raylib_destroy_transform);
	RING_API_REGISTER("raylib_get_transform_translation_x",ring_raylib_get_transform_translation_x);
	RING_API_REGISTER("raylib_set_transform_translation_x",ring_raylib_set_transform_translation_x);
	RING_API_REGISTER("raylib_get_transform_translation_y",ring_raylib_get_transform_translation_y);
	RING_API_REGISTER("raylib_set_transform_translation_y",ring_raylib_set_transform_translation_y);
	RING_API_REGISTER("raylib_get_transform_translation_z",ring_raylib_get_transform_translation_z);
	RING_API_REGISTER("raylib_set_transform_translation_z",ring_raylib_set_transform_translation_z);
	RING_API_REGISTER("raylib_get_transform_rotation_x",ring_raylib_get_transform_rotation_x);
	RING_API_REGISTER("raylib_set_transform_rotation_x",ring_raylib_set_transform_rotation_x);
	RING_API_REGISTER("raylib_get_transform_rotation_y",ring_raylib_get_transform_rotation_y);
	RING_API_REGISTER("raylib_set_transform_rotation_y",ring_raylib_set_transform_rotation_y);
	RING_API_REGISTER("raylib_get_transform_rotation_z",ring_raylib_get_transform_rotation_z);
	RING_API_REGISTER("raylib_set_transform_rotation_z",ring_raylib_set_transform_rotation_z);
	RING_API_REGISTER("raylib_get_transform_rotation_w",ring_raylib_get_transform_rotation_w);
	RING_API_REGISTER("raylib_set_transform_rotation_w",ring_raylib_set_transform_rotation_w);
	RING_API_REGISTER("raylib_get_transform_scale_x",ring_raylib_get_transform_scale_x);
	RING_API_REGISTER("raylib_set_transform_scale_x",ring_raylib_set_transform_scale_x);
	RING_API_REGISTER("raylib_get_transform_scale_y",ring_raylib_get_transform_scale_y);
	RING_API_REGISTER("raylib_set_transform_scale_y",ring_raylib_set_transform_scale_y);
	RING_API_REGISTER("raylib_get_transform_scale_z",ring_raylib_get_transform_scale_z);
	RING_API_REGISTER("raylib_set_transform_scale_z",ring_raylib_set_transform_scale_z);
	RING_API_REGISTER("raylib_new_boneinfo",ring_raylib_new_boneinfo);
	RING_API_REGISTER("raylib_new_managed_boneinfo",ring_raylib_new_managed_boneinfo);
	RING_API_REGISTER("raylib_destroy_boneinfo",ring_raylib_destroy_boneinfo);
	RING_API_REGISTER("raylib_get_boneinfo_parent",ring_raylib_get_boneinfo_parent);
	RING_API_REGISTER("raylib_set_boneinfo_parent",ring_raylib_set_boneinfo_parent);
	RING_API_REGISTER("raylib_new_model",ring_raylib_new_model);
	RING_API_REGISTER("raylib_new_managed_model",ring_raylib_new_managed_model);
	RING_API_REGISTER("raylib_destroy_model",ring_raylib_destroy_model);
	RING_API_REGISTER("raylib_get_model_transform_m0",ring_raylib_get_model_transform_m0);
	RING_API_REGISTER("raylib_set_model_transform_m0",ring_raylib_set_model_transform_m0);
	RING_API_REGISTER("raylib_get_model_transform_m1",ring_raylib_get_model_transform_m1);
	RING_API_REGISTER("raylib_set_model_transform_m1",ring_raylib_set_model_transform_m1);
	RING_API_REGISTER("raylib_get_model_transform_m2",ring_raylib_get_model_transform_m2);
	RING_API_REGISTER("raylib_set_model_transform_m2",ring_raylib_set_model_transform_m2);
	RING_API_REGISTER("raylib_get_model_transform_m3",ring_raylib_get_model_transform_m3);
	RING_API_REGISTER("raylib_set_model_transform_m3",ring_raylib_set_model_transform_m3);
	RING_API_REGISTER("raylib_get_model_transform_m4",ring_raylib_get_model_transform_m4);
	RING_API_REGISTER("raylib_set_model_transform_m4",ring_raylib_set_model_transform_m4);
	RING_API_REGISTER("raylib_get_model_transform_m5",ring_raylib_get_model_transform_m5);
	RING_API_REGISTER("raylib_set_model_transform_m5",ring_raylib_set_model_transform_m5);
	RING_API_REGISTER("raylib_get_model_transform_m6",ring_raylib_get_model_transform_m6);
	RING_API_REGISTER("raylib_set_model_transform_m6",ring_raylib_set_model_transform_m6);
	RING_API_REGISTER("raylib_get_model_transform_m7",ring_raylib_get_model_transform_m7);
	RING_API_REGISTER("raylib_set_model_transform_m7",ring_raylib_set_model_transform_m7);
	RING_API_REGISTER("raylib_get_model_transform_m8",ring_raylib_get_model_transform_m8);
	RING_API_REGISTER("raylib_set_model_transform_m8",ring_raylib_set_model_transform_m8);
	RING_API_REGISTER("raylib_get_model_transform_m9",ring_raylib_get_model_transform_m9);
	RING_API_REGISTER("raylib_set_model_transform_m9",ring_raylib_set_model_transform_m9);
	RING_API_REGISTER("raylib_get_model_transform_m10",ring_raylib_get_model_transform_m10);
	RING_API_REGISTER("raylib_set_model_transform_m10",ring_raylib_set_model_transform_m10);
	RING_API_REGISTER("raylib_get_model_transform_m11",ring_raylib_get_model_transform_m11);
	RING_API_REGISTER("raylib_set_model_transform_m11",ring_raylib_set_model_transform_m11);
	RING_API_REGISTER("raylib_get_model_transform_m12",ring_raylib_get_model_transform_m12);
	RING_API_REGISTER("raylib_set_model_transform_m12",ring_raylib_set_model_transform_m12);
	RING_API_REGISTER("raylib_get_model_transform_m13",ring_raylib_get_model_transform_m13);
	RING_API_REGISTER("raylib_set_model_transform_m13",ring_raylib_set_model_transform_m13);
	RING_API_REGISTER("raylib_get_model_transform_m14",ring_raylib_get_model_transform_m14);
	RING_API_REGISTER("raylib_set_model_transform_m14",ring_raylib_set_model_transform_m14);
	RING_API_REGISTER("raylib_get_model_transform_m15",ring_raylib_get_model_transform_m15);
	RING_API_REGISTER("raylib_set_model_transform_m15",ring_raylib_set_model_transform_m15);
	RING_API_REGISTER("raylib_get_model_meshcount",ring_raylib_get_model_meshCount);
	RING_API_REGISTER("raylib_set_model_meshcount",ring_raylib_set_model_meshCount);
	RING_API_REGISTER("raylib_get_model_meshes",ring_raylib_get_model_meshes);
	RING_API_REGISTER("raylib_set_model_meshes",ring_raylib_set_model_meshes);
	RING_API_REGISTER("raylib_get_model_materialcount",ring_raylib_get_model_materialCount);
	RING_API_REGISTER("raylib_set_model_materialcount",ring_raylib_set_model_materialCount);
	RING_API_REGISTER("raylib_get_model_materials",ring_raylib_get_model_materials);
	RING_API_REGISTER("raylib_set_model_materials",ring_raylib_set_model_materials);
	RING_API_REGISTER("raylib_get_model_meshmaterial",ring_raylib_get_model_meshMaterial);
	RING_API_REGISTER("raylib_set_model_meshmaterial",ring_raylib_set_model_meshMaterial);
	RING_API_REGISTER("raylib_get_model_bonecount",ring_raylib_get_model_boneCount);
	RING_API_REGISTER("raylib_set_model_bonecount",ring_raylib_set_model_boneCount);
	RING_API_REGISTER("raylib_get_model_bones",ring_raylib_get_model_bones);
	RING_API_REGISTER("raylib_set_model_bones",ring_raylib_set_model_bones);
	RING_API_REGISTER("raylib_get_model_bindpose",ring_raylib_get_model_bindPose);
	RING_API_REGISTER("raylib_set_model_bindpose",ring_raylib_set_model_bindPose);
	RING_API_REGISTER("raylib_new_modelanimation",ring_raylib_new_modelanimation);
	RING_API_REGISTER("raylib_new_managed_modelanimation",ring_raylib_new_managed_modelanimation);
	RING_API_REGISTER("raylib_destroy_modelanimation",ring_raylib_destroy_modelanimation);
	RING_API_REGISTER("raylib_get_modelanimation_bonecount",ring_raylib_get_modelanimation_boneCount);
	RING_API_REGISTER("raylib_set_modelanimation_bonecount",ring_raylib_set_modelanimation_boneCount);
	RING_API_REGISTER("raylib_get_modelanimation_bones",ring_raylib_get_modelanimation_bones);
	RING_API_REGISTER("raylib_set_modelanimation_bones",ring_raylib_set_modelanimation_bones);
	RING_API_REGISTER("raylib_get_modelanimation_framecount",ring_raylib_get_modelanimation_frameCount);
	RING_API_REGISTER("raylib_set_modelanimation_framecount",ring_raylib_set_modelanimation_frameCount);
	RING_API_REGISTER("raylib_new_ray",ring_raylib_new_ray);
	RING_API_REGISTER("raylib_new_managed_ray",ring_raylib_new_managed_ray);
	RING_API_REGISTER("raylib_destroy_ray",ring_raylib_destroy_ray);
	RING_API_REGISTER("raylib_get_ray_position_x",ring_raylib_get_ray_position_x);
	RING_API_REGISTER("raylib_set_ray_position_x",ring_raylib_set_ray_position_x);
	RING_API_REGISTER("raylib_get_ray_position_y",ring_raylib_get_ray_position_y);
	RING_API_REGISTER("raylib_set_ray_position_y",ring_raylib_set_ray_position_y);
	RING_API_REGISTER("raylib_get_ray_position_z",ring_raylib_get_ray_position_z);
	RING_API_REGISTER("raylib_set_ray_position_z",ring_raylib_set_ray_position_z);
	RING_API_REGISTER("raylib_get_ray_direction_x",ring_raylib_get_ray_direction_x);
	RING_API_REGISTER("raylib_set_ray_direction_x",ring_raylib_set_ray_direction_x);
	RING_API_REGISTER("raylib_get_ray_direction_y",ring_raylib_get_ray_direction_y);
	RING_API_REGISTER("raylib_set_ray_direction_y",ring_raylib_set_ray_direction_y);
	RING_API_REGISTER("raylib_get_ray_direction_z",ring_raylib_get_ray_direction_z);
	RING_API_REGISTER("raylib_set_ray_direction_z",ring_raylib_set_ray_direction_z);
	RING_API_REGISTER("raylib_new_rayhitinfo",ring_raylib_new_rayhitinfo);
	RING_API_REGISTER("raylib_new_managed_rayhitinfo",ring_raylib_new_managed_rayhitinfo);
	RING_API_REGISTER("raylib_destroy_rayhitinfo",ring_raylib_destroy_rayhitinfo);
	RING_API_REGISTER("raylib_get_rayhitinfo_hit",ring_raylib_get_rayhitinfo_hit);
	RING_API_REGISTER("raylib_set_rayhitinfo_hit",ring_raylib_set_rayhitinfo_hit);
	RING_API_REGISTER("raylib_get_rayhitinfo_distance",ring_raylib_get_rayhitinfo_distance);
	RING_API_REGISTER("raylib_set_rayhitinfo_distance",ring_raylib_set_rayhitinfo_distance);
	RING_API_REGISTER("raylib_get_rayhitinfo_position_x",ring_raylib_get_rayhitinfo_position_x);
	RING_API_REGISTER("raylib_set_rayhitinfo_position_x",ring_raylib_set_rayhitinfo_position_x);
	RING_API_REGISTER("raylib_get_rayhitinfo_position_y",ring_raylib_get_rayhitinfo_position_y);
	RING_API_REGISTER("raylib_set_rayhitinfo_position_y",ring_raylib_set_rayhitinfo_position_y);
	RING_API_REGISTER("raylib_get_rayhitinfo_position_z",ring_raylib_get_rayhitinfo_position_z);
	RING_API_REGISTER("raylib_set_rayhitinfo_position_z",ring_raylib_set_rayhitinfo_position_z);
	RING_API_REGISTER("raylib_get_rayhitinfo_normal_x",ring_raylib_get_rayhitinfo_normal_x);
	RING_API_REGISTER("raylib_set_rayhitinfo_normal_x",ring_raylib_set_rayhitinfo_normal_x);
	RING_API_REGISTER("raylib_get_rayhitinfo_normal_y",ring_raylib_get_rayhitinfo_normal_y);
	RING_API_REGISTER("raylib_set_rayhitinfo_normal_y",ring_raylib_set_rayhitinfo_normal_y);
	RING_API_REGISTER("raylib_get_rayhitinfo_normal_z",ring_raylib_get_rayhitinfo_normal_z);
	RING_API_REGISTER("raylib_set_rayhitinfo_normal_z",ring_raylib_set_rayhitinfo_normal_z);
	RING_API_REGISTER("raylib_new_boundingbox",ring_raylib_new_boundingbox);
	RING_API_REGISTER("raylib_new_managed_boundingbox",ring_raylib_new_managed_boundingbox);
	RING_API_REGISTER("raylib_destroy_boundingbox",ring_raylib_destroy_boundingbox);
	RING_API_REGISTER("raylib_get_boundingbox_min_x",ring_raylib_get_boundingbox_min_x);
	RING_API_REGISTER("raylib_set_boundingbox_min_x",ring_raylib_set_boundingbox_min_x);
	RING_API_REGISTER("raylib_get_boundingbox_min_y",ring_raylib_get_boundingbox_min_y);
	RING_API_REGISTER("raylib_set_boundingbox_min_y",ring_raylib_set_boundingbox_min_y);
	RING_API_REGISTER("raylib_get_boundingbox_min_z",ring_raylib_get_boundingbox_min_z);
	RING_API_REGISTER("raylib_set_boundingbox_min_z",ring_raylib_set_boundingbox_min_z);
	RING_API_REGISTER("raylib_get_boundingbox_max_x",ring_raylib_get_boundingbox_max_x);
	RING_API_REGISTER("raylib_set_boundingbox_max_x",ring_raylib_set_boundingbox_max_x);
	RING_API_REGISTER("raylib_get_boundingbox_max_y",ring_raylib_get_boundingbox_max_y);
	RING_API_REGISTER("raylib_set_boundingbox_max_y",ring_raylib_set_boundingbox_max_y);
	RING_API_REGISTER("raylib_get_boundingbox_max_z",ring_raylib_get_boundingbox_max_z);
	RING_API_REGISTER("raylib_set_boundingbox_max_z",ring_raylib_set_boundingbox_max_z);
	RING_API_REGISTER("raylib_new_wave",ring_raylib_new_wave);
	RING_API_REGISTER("raylib_new_managed_wave",ring_raylib_new_managed_wave);
	RING_API_REGISTER("raylib_destroy_wave",ring_raylib_destroy_wave);
	RING_API_REGISTER("raylib_get_wave_samplecount",ring_raylib_get_wave_sampleCount);
	RING_API_REGISTER("raylib_set_wave_samplecount",ring_raylib_set_wave_sampleCount);
	RING_API_REGISTER("raylib_get_wave_samplerate",ring_raylib_get_wave_sampleRate);
	RING_API_REGISTER("raylib_set_wave_samplerate",ring_raylib_set_wave_sampleRate);
	RING_API_REGISTER("raylib_get_wave_samplesize",ring_raylib_get_wave_sampleSize);
	RING_API_REGISTER("raylib_set_wave_samplesize",ring_raylib_set_wave_sampleSize);
	RING_API_REGISTER("raylib_get_wave_channels",ring_raylib_get_wave_channels);
	RING_API_REGISTER("raylib_set_wave_channels",ring_raylib_set_wave_channels);
	RING_API_REGISTER("raylib_get_wave_data",ring_raylib_get_wave_data);
	RING_API_REGISTER("raylib_set_wave_data",ring_raylib_set_wave_data);
	RING_API_REGISTER("raylib_new_sound",ring_raylib_new_sound);
	RING_API_REGISTER("raylib_new_managed_sound",ring_raylib_new_managed_sound);
	RING_API_REGISTER("raylib_destroy_sound",ring_raylib_destroy_sound);
	RING_API_REGISTER("raylib_get_sound_audiobuffer",ring_raylib_get_sound_audioBuffer);
	RING_API_REGISTER("raylib_set_sound_audiobuffer",ring_raylib_set_sound_audioBuffer);
	RING_API_REGISTER("raylib_get_sound_source",ring_raylib_get_sound_source);
	RING_API_REGISTER("raylib_set_sound_source",ring_raylib_set_sound_source);
	RING_API_REGISTER("raylib_get_sound_buffer",ring_raylib_get_sound_buffer);
	RING_API_REGISTER("raylib_set_sound_buffer",ring_raylib_set_sound_buffer);
	RING_API_REGISTER("raylib_get_sound_format",ring_raylib_get_sound_format);
	RING_API_REGISTER("raylib_set_sound_format",ring_raylib_set_sound_format);
	RING_API_REGISTER("raylib_new_audiostream",ring_raylib_new_audiostream);
	RING_API_REGISTER("raylib_new_managed_audiostream",ring_raylib_new_managed_audiostream);
	RING_API_REGISTER("raylib_destroy_audiostream",ring_raylib_destroy_audiostream);
	RING_API_REGISTER("raylib_get_audiostream_samplerate",ring_raylib_get_audiostream_sampleRate);
	RING_API_REGISTER("raylib_set_audiostream_samplerate",ring_raylib_set_audiostream_sampleRate);
	RING_API_REGISTER("raylib_get_audiostream_samplesize",ring_raylib_get_audiostream_sampleSize);
	RING_API_REGISTER("raylib_set_audiostream_samplesize",ring_raylib_set_audiostream_sampleSize);
	RING_API_REGISTER("raylib_get_audiostream_channels",ring_raylib_get_audiostream_channels);
	RING_API_REGISTER("raylib_set_audiostream_channels",ring_raylib_set_audiostream_channels);
	RING_API_REGISTER("raylib_get_audiostream_audiobuffer",ring_raylib_get_audiostream_audioBuffer);
	RING_API_REGISTER("raylib_set_audiostream_audiobuffer",ring_raylib_set_audiostream_audioBuffer);
	RING_API_REGISTER("raylib_get_audiostream_format",ring_raylib_get_audiostream_format);
	RING_API_REGISTER("raylib_set_audiostream_format",ring_raylib_set_audiostream_format);
	RING_API_REGISTER("raylib_get_audiostream_source",ring_raylib_get_audiostream_source);
	RING_API_REGISTER("raylib_set_audiostream_source",ring_raylib_set_audiostream_source);
	RING_API_REGISTER("raylib_new_vrdeviceinfo",ring_raylib_new_vrdeviceinfo);
	RING_API_REGISTER("raylib_new_managed_vrdeviceinfo",ring_raylib_new_managed_vrdeviceinfo);
	RING_API_REGISTER("raylib_destroy_vrdeviceinfo",ring_raylib_destroy_vrdeviceinfo);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_hresolution",ring_raylib_get_vrdeviceinfo_hResolution);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_hresolution",ring_raylib_set_vrdeviceinfo_hResolution);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_vresolution",ring_raylib_get_vrdeviceinfo_vResolution);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_vresolution",ring_raylib_set_vrdeviceinfo_vResolution);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_hscreensize",ring_raylib_get_vrdeviceinfo_hScreenSize);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_hscreensize",ring_raylib_set_vrdeviceinfo_hScreenSize);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_vscreensize",ring_raylib_get_vrdeviceinfo_vScreenSize);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_vscreensize",ring_raylib_set_vrdeviceinfo_vScreenSize);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_vscreencenter",ring_raylib_get_vrdeviceinfo_vScreenCenter);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_vscreencenter",ring_raylib_set_vrdeviceinfo_vScreenCenter);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_eyetoscreendistance",ring_raylib_get_vrdeviceinfo_eyeToScreenDistance);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_eyetoscreendistance",ring_raylib_set_vrdeviceinfo_eyeToScreenDistance);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_lensseparationdistance",ring_raylib_get_vrdeviceinfo_lensSeparationDistance);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_lensseparationdistance",ring_raylib_set_vrdeviceinfo_lensSeparationDistance);
	RING_API_REGISTER("raylib_get_vrdeviceinfo_interpupillarydistance",ring_raylib_get_vrdeviceinfo_interpupillaryDistance);
	RING_API_REGISTER("raylib_set_vrdeviceinfo_interpupillarydistance",ring_raylib_set_vrdeviceinfo_interpupillaryDistance);
	RING_API_REGISTER("vec2",ring_raylib_new_managed_vector2);
	RING_API_REGISTER("vec2getx",ring_raylib_get_vector2_x);
	RING_API_REGISTER("vec2setx",ring_raylib_set_vector2_x);
	RING_API_REGISTER("vec2gety",ring_raylib_get_vector2_y);
	RING_API_REGISTER("vec2sety",ring_raylib_set_vector2_y);
	RING_API_REGISTER("vec3",ring_raylib_new_managed_vector3);
	RING_API_REGISTER("vec3getx",ring_raylib_get_vector3_x);
	RING_API_REGISTER("vec3setx",ring_raylib_set_vector3_x);
	RING_API_REGISTER("vec3gety",ring_raylib_get_vector3_y);
	RING_API_REGISTER("vec3sety",ring_raylib_set_vector3_y);
	RING_API_REGISTER("vec3getz",ring_raylib_get_vector3_z);
	RING_API_REGISTER("vec3setz",ring_raylib_set_vector3_z);
	RING_API_REGISTER("vec4",ring_raylib_new_managed_vector4);
	RING_API_REGISTER("vec4getx",ring_raylib_get_vector4_x);
	RING_API_REGISTER("vec4setx",ring_raylib_set_vector4_x);
	RING_API_REGISTER("vec4gety",ring_raylib_get_vector4_y);
	RING_API_REGISTER("vec4sety",ring_raylib_set_vector4_y);
	RING_API_REGISTER("vec4getz",ring_raylib_get_vector4_z);
	RING_API_REGISTER("vec4setz",ring_raylib_set_vector4_z);
	RING_API_REGISTER("vec4getw",ring_raylib_get_vector4_w);
	RING_API_REGISTER("vec4setw",ring_raylib_set_vector4_w);
	RING_API_REGISTER("getcamera3dposx",ring_raylib_get_camera3d_position_x);
	RING_API_REGISTER("setcamera3dposx",ring_raylib_set_camera3d_position_x);
	RING_API_REGISTER("getcamera3dposy",ring_raylib_get_camera3d_position_y);
	RING_API_REGISTER("setcamera3dposy",ring_raylib_set_camera3d_position_y);
	RING_API_REGISTER("getcamera3dposz",ring_raylib_get_camera3d_position_z);
	RING_API_REGISTER("setcamera3dposz",ring_raylib_set_camera3d_position_z);
	RING_API_REGISTER("getcamera3dtarx",ring_raylib_get_camera3d_target_x);
	RING_API_REGISTER("setcamera3dtarx",ring_raylib_set_camera3d_target_x);
	RING_API_REGISTER("getcamera3dtary",ring_raylib_get_camera3d_target_y);
	RING_API_REGISTER("setcamera3dtary",ring_raylib_set_camera3d_target_y);
	RING_API_REGISTER("getcamera3dtarz",ring_raylib_get_camera3d_target_z);
	RING_API_REGISTER("setcamera3dtarz",ring_raylib_set_camera3d_target_z);
	RING_API_REGISTER("getcamera3dupx",ring_raylib_get_camera3d_up_x);
	RING_API_REGISTER("setcamera3dupx",ring_raylib_set_camera3d_up_x);
	RING_API_REGISTER("getcamera3dupy",ring_raylib_get_camera3d_up_y);
	RING_API_REGISTER("setcamera3dupy",ring_raylib_set_camera3d_up_y);
	RING_API_REGISTER("getcamera3dupz",ring_raylib_get_camera3d_up_z);
	RING_API_REGISTER("setcamera3dupz",ring_raylib_set_camera3d_up_z);
	RING_API_REGISTER("getcamera3fovy",ring_raylib_get_camera3d_fovy);
	RING_API_REGISTER("setcamera3fovy",ring_raylib_set_camera3d_fovy);
	RING_API_REGISTER("getcamera3type",ring_raylib_get_camera3d_type);
	RING_API_REGISTER("setcamera3type",ring_raylib_set_camera3d_type);
}
