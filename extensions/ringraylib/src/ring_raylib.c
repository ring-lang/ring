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
	pMyPointer = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
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
	pMyPointer = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Vector2",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Vector2");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
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
	pMyPointer = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Vector3",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Vector3");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Vector4 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector4)) ;
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
	pMyPointer = (Vector4 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector4)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Vector4",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Vector4");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
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
	pMyPointer = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Quaternion",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Quaternion");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
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
	pMyPointer = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Matrix",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Matrix");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
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
	pMyPointer = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Color",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Color");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Rectangle *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Rectangle)) ;
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
	pMyPointer = (Rectangle *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Rectangle)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Rectangle",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Rectangle");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
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
	pMyPointer = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Image",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Image");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
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
	pMyPointer = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Texture2D",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Texture2D");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Texture *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture)) ;
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
	pMyPointer = (Texture *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Texture",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Texture");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (RenderTexture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RenderTexture2D)) ;
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
	pMyPointer = (RenderTexture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RenderTexture2D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"RenderTexture2D",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture2D");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (RenderTexture *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RenderTexture)) ;
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
	pMyPointer = (RenderTexture *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RenderTexture)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"RenderTexture",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"RenderTexture");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (NPatchInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(NPatchInfo)) ;
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
	pMyPointer = (NPatchInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(NPatchInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"NPatchInfo",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"NPatchInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (CharInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(CharInfo)) ;
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
	pMyPointer = (CharInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(CharInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"CharInfo",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"CharInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Font *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Font)) ;
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
	pMyPointer = (Font *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Font)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Font",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Font");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (SpriteFont *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SpriteFont)) ;
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
	pMyPointer = (SpriteFont *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SpriteFont)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SpriteFont",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"SpriteFont");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Camera3D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Camera3D)) ;
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
	pMyPointer = (Camera3D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Camera3D)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Camera3D",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Camera3D");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
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
	pMyPointer = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Mesh",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Mesh");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Shader *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Shader)) ;
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
	pMyPointer = (Shader *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Shader)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Shader",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Shader");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (MaterialMap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(MaterialMap)) ;
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
	pMyPointer = (MaterialMap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(MaterialMap)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"MaterialMap",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"MaterialMap");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Material *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Material)) ;
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
	pMyPointer = (Material *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Material)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Material",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Material");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Transform *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Transform)) ;
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
	pMyPointer = (Transform *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Transform)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Transform",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Transform");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (BoneInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(BoneInfo)) ;
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
	pMyPointer = (BoneInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(BoneInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"BoneInfo",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"BoneInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Model *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Model)) ;
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
	pMyPointer = (Model *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Model)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Model",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Model");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (ModelAnimation *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(ModelAnimation)) ;
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
	pMyPointer = (ModelAnimation *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(ModelAnimation)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"ModelAnimation",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"ModelAnimation");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Ray *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Ray)) ;
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
	pMyPointer = (Ray *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Ray)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Ray",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Ray");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (RayHitInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RayHitInfo)) ;
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
	pMyPointer = (RayHitInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RayHitInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"RayHitInfo",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"RayHitInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (BoundingBox *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(BoundingBox)) ;
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
	pMyPointer = (BoundingBox *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(BoundingBox)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"BoundingBox",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"BoundingBox");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Wave *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Wave)) ;
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
	pMyPointer = (Wave *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Wave)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Wave",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Wave");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (Sound *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Sound)) ;
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
	pMyPointer = (Sound *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Sound)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Sound",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"Sound");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (AudioStream *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(AudioStream)) ;
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
	pMyPointer = (AudioStream *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(AudioStream)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"AudioStream",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"AudioStream");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	pMyPointer = (VrDeviceInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(VrDeviceInfo)) ;
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
	pMyPointer = (VrDeviceInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(VrDeviceInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"VrDeviceInfo",ring_state_free);
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
	pMyPointer = RING_API_GETCPOINTER(1,"VrDeviceInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera2D"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera3D"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"RenderTexture2D"));
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
		pValue = (Ray *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Ray)) ;
		*pValue = GetMouseRay(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Camera3D  *) RING_API_GETCPOINTER(2,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Camera3D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Ray",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetWorldToScreen(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Camera3D  *) RING_API_GETCPOINTER(2,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Camera3D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = GetCameraMatrix(* (Camera3D  *) RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera3D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
}


RING_FUNC(ring_ColorNormalize_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector4 *pValue ; 
		pValue = (Vector4 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector4)) ;
		*pValue = ColorNormalize(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector4",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = ColorToHSV(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
		*pValue = ColorFromHSV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",ring_state_free);
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
		pValue = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
		*pValue = GetColor( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",ring_state_free);
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
		pValue = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
		*pValue = Fade(* (Color  *) RING_API_GETCPOINTER(1,"Color"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TraceLogCallback"));
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
		pValue = (long *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(long)) ;
		*pValue = GetFileModTime(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"long",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetMousePosition();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetTouchPosition( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetGestureDragVector();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetGesturePinchVector();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera3D"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawPixelV_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawPixelV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawLineV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawLineV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawRectangleV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawRectangleV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawRectangleRec_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawRectangleRec(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawRectangleGradientEx_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	DrawRectangleGradientEx(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"),* (Color  *) RING_API_GETCPOINTER(3,"Color"),* (Color  *) RING_API_GETCPOINTER(4,"Color"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawTriangle_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTriangle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTriangleLines_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTriangleLines(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_SetShapesTexture_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	SetShapesTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_CheckCollisionRecs_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionRecs(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
}


RING_FUNC(ring_GetCollisionRec_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Rectangle *pValue ; 
		pValue = (Rectangle *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Rectangle)) ;
		*pValue = GetCollisionRec(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Rectangle",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_CheckCollisionPointTriangle_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionPointTriangle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(4,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Vector2"));
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImage(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImageEx((Color *) RING_API_GETCPOINTER(1,"Color"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImagePro((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImageRaw(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
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
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = LoadTexture(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
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
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = LoadTextureFromImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
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
		pValue = (TextureCubemap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TextureCubemap)) ;
		*pValue = LoadTextureCubemap(* (Image  *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TextureCubemap",ring_state_free);
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
		pValue = (RenderTexture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RenderTexture2D)) ;
		*pValue = LoadRenderTexture( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"RenderTexture2D",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_UnloadTexture_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_UnloadRenderTexture_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadRenderTexture(* (RenderTexture2D  *) RING_API_GETCPOINTER(1,"RenderTexture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"RenderTexture2D"));
}


RING_FUNC(ring_GetImageData_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(GetImageData(* (Image  *) RING_API_GETCPOINTER(1,"Image")),"Color");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_GetImageDataNormalized_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(GetImageDataNormalized(* (Image  *) RING_API_GETCPOINTER(1,"Image")),"Vector4");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GetTextureData(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GetScreenData();
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_ImageCopy_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = ImageCopy(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Image"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = ImageText(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = ImageTextEx(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageColor( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageGradientV( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageGradientH( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageGradientRadial( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageChecked( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageWhiteNoise( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImagePerlinNoise( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageCellular( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTextureV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawTextureV(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawTextureRec_2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTextureRec(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTextureQuad_2)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	DrawTextureQuad(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Rectangle  *) RING_API_GETCPOINTER(4,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"NPatchInfo"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_GetFontDefault_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Font *pValue ; 
		pValue = (Font *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Font)) ;
		*pValue = GetFontDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",ring_state_free);
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
		pValue = (Font *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Font)) ;
		*pValue = LoadFont(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",ring_state_free);
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
		pValue = (Font *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Font)) ;
		*pValue = LoadFontEx(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",ring_state_free);
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
		pValue = (Font *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Font)) ;
		*pValue = LoadFontFromImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Font",ring_state_free);
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
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GenImageFontAtlas((CharInfo *) RING_API_GETCPOINTER(1,"CharInfo"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(10))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(10,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(11))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(11,"Color"));
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = MeasureTextEx(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCubeV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawCubeV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCubeWiresV_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawCubeWiresV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawPlane_2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawPlane(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawRay_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawRay(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
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
		pValue = (Model *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Model)) ;
		*pValue = LoadModel(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Model",ring_state_free);
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
		pValue = (Model *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Model)) ;
		*pValue = LoadModelFromMesh(* (Mesh  *) RING_API_GETCPOINTER(1,"Mesh"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Mesh"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Model",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Model"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Mesh"));
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
		pValue = (Material *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Material)) ;
		*pValue = LoadMaterialDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Material",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Material"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Texture2D"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"ModelAnimation"));
}


RING_FUNC(ring_UnloadModelAnimation_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadModelAnimation(* (ModelAnimation  *) RING_API_GETCPOINTER(1,"ModelAnimation"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"ModelAnimation"));
}


RING_FUNC(ring_IsModelAnimationValid_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(IsModelAnimationValid(* (Model  *) RING_API_GETCPOINTER(1,"Model"),* (ModelAnimation  *) RING_API_GETCPOINTER(2,"ModelAnimation")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"ModelAnimation"));
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshPoly( (int ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshPlane( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshCube( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshSphere( (float ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshHemiSphere( (float ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshCylinder( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshTorus( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshKnot( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshHeightmap(* (Image  *) RING_API_GETCPOINTER(1,"Image"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (Mesh *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Mesh)) ;
		*pValue = GenMeshCubicmap(* (Image  *) RING_API_GETCPOINTER(1,"Image"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mesh",ring_state_free);
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
		pValue = (BoundingBox *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(BoundingBox)) ;
		*pValue = MeshBoundingBox(* (Mesh  *) RING_API_GETCPOINTER(1,"Mesh"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Mesh"));
		RING_API_RETMANAGEDCPOINTER(pValue,"BoundingBox",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawBoundingBox_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawBoundingBox(* (BoundingBox  *) RING_API_GETCPOINTER(1,"BoundingBox"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"BoundingBox"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
}


RING_FUNC(ring_CheckCollisionBoxes_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionBoxes(* (BoundingBox  *) RING_API_GETCPOINTER(1,"BoundingBox"),* (BoundingBox  *) RING_API_GETCPOINTER(2,"BoundingBox")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"BoundingBox"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"BoundingBox"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"BoundingBox"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_CheckCollisionRayBox_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionRayBox(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (BoundingBox  *) RING_API_GETCPOINTER(2,"BoundingBox")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"BoundingBox"));
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
		pValue = (RayHitInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RayHitInfo)) ;
		*pValue = GetCollisionRayModel(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),(Model *) RING_API_GETCPOINTER(2,"Model"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Ray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"RayHitInfo",ring_state_free);
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
		pValue = (RayHitInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RayHitInfo)) ;
		*pValue = GetCollisionRayTriangle(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(4,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Ray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"RayHitInfo",ring_state_free);
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
		pValue = (RayHitInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RayHitInfo)) ;
		*pValue = GetCollisionRayGround(* (Ray  *) RING_API_GETCPOINTER(1,"Ray"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Ray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"RayHitInfo",ring_state_free);
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
		pValue = (Shader *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Shader)) ;
		*pValue = LoadShader(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Shader",ring_state_free);
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
		pValue = (Shader *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Shader)) ;
		*pValue = LoadShaderCode(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Shader",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
}


RING_FUNC(ring_GetShaderDefault_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Shader *pValue ; 
		pValue = (Shader *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Shader)) ;
		*pValue = GetShaderDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Shader",ring_state_free);
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
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = GetTextureDefault();
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Matrix"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Texture2D"));
}


RING_FUNC(ring_SetMatrixProjection_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetMatrixProjection(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_SetMatrixModelview_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetMatrixModelview(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_GetMatrixModelview_2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = GetMatrixModelview();
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = GenTextureCubemap(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
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
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = GenTextureIrradiance(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
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
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = GenTexturePrefilter(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
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
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = GenTextureBRDF(* (Shader  *) RING_API_GETCPOINTER(1,"Shader"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Shader"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"VrDeviceInfo"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Shader"));
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
		pValue = (Wave *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Wave)) ;
		*pValue = LoadWave(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Wave",ring_state_free);
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
		pValue = (Wave *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Wave)) ;
		*pValue = LoadWaveEx((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Wave",ring_state_free);
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
		pValue = (Sound *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Sound)) ;
		*pValue = LoadSound(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Sound",ring_state_free);
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
		pValue = (Sound *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Sound)) ;
		*pValue = LoadSoundFromWave(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Wave"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Sound",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_UnloadWave_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadWave(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Wave"));
}


RING_FUNC(ring_UnloadSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Wave"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Wave"));
}


RING_FUNC(ring_PlaySound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PlaySound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_PauseSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PauseSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_ResumeSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ResumeSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_StopSound_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	StopSound(* (Sound  *) RING_API_GETCPOINTER(1,"Sound"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
}


RING_FUNC(ring_IsSoundPlaying_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsSoundPlaying(* (Sound  *) RING_API_GETCPOINTER(1,"Sound")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Sound"));
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
		pValue = (Wave *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Wave)) ;
		*pValue = WaveCopy(* (Wave  *) RING_API_GETCPOINTER(1,"Wave"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Wave"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Wave",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Wave"));
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
		pValue = (Music *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Music)) ;
		*pValue = LoadMusicStream(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Music",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_PlayMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PlayMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_UpdateMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UpdateMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_StopMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	StopMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_PauseMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PauseMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_ResumeMusicStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ResumeMusicStream(* (Music  *) RING_API_GETCPOINTER(1,"Music"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_IsMusicPlaying_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsMusicPlaying(* (Music  *) RING_API_GETCPOINTER(1,"Music")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_GetMusicTimeLength_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(GetMusicTimeLength(* (Music  *) RING_API_GETCPOINTER(1,"Music")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
}


RING_FUNC(ring_GetMusicTimePlayed_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(GetMusicTimePlayed(* (Music  *) RING_API_GETCPOINTER(1,"Music")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Music"));
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
		pValue = (AudioStream *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(AudioStream)) ;
		*pValue = InitAudioStream( (unsigned int ) RING_API_GETNUMBER(1), (unsigned int ) RING_API_GETNUMBER(2), (unsigned int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"AudioStream",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_CloseAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	CloseAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_IsAudioBufferProcessed_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsAudioBufferProcessed(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_PlayAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PlayAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_PauseAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	PauseAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_ResumeAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ResumeAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_IsAudioStreamPlaying_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(IsAudioStreamPlaying(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
}


RING_FUNC(ring_StopAudioStream_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	StopAudioStream(* (AudioStream  *) RING_API_GETCPOINTER(1,"AudioStream"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"AudioStream"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiPanel_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	GuiPanel(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		pValue = (Rectangle *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Rectangle)) ;
		*pValue = GuiScrollPanel(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"),(Vector2 *) RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Rectangle",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiImageButton_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(GuiImageButton(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Texture2D  *) RING_API_GETCPOINTER(2,"Texture2D")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Texture2D"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GuiGrid(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
}


RING_FUNC(ring_GuiColorPicker_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Color *pValue ; 
		pValue = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
		*pValue = GuiColorPicker(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Zero();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2One();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Add(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2AddValue(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Subtract(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2SubtractValue(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
}


RING_FUNC(ring_Vector2LengthSqr_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2LengthSqr(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
}


RING_FUNC(ring_Vector2DotProduct_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2DotProduct(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_Vector2Distance_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2Distance(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_Vector2Angle_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector2Angle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Scale(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Multiply(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Negate(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Divide(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Normalize(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Lerp(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2Rotate(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = Vector2MoveTowards(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Zero();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3One();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Add(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3AddValue(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Subtract(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3SubtractValue(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Scale(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Multiply(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3CrossProduct(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Perpendicular(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
}


RING_FUNC(ring_Vector3LengthSqr_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector3LengthSqr(* (const Vector3  *) RING_API_GETCPOINTER(1,"const Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
}


RING_FUNC(ring_Vector3DotProduct_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector3DotProduct(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_Vector3Distance_2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(Vector3Distance(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
}


RING_FUNC(ring_Vector3Negate_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Negate(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Divide(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Normalize(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Transform(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3RotateByQuaternion(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Lerp(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Reflect(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Min(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Max(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = Vector3Barycenter(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(4,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (float3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(float3)) ;
		*pValue = Vector3ToFloatV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"float3",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_MatrixTrace_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(MatrixTrace(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
}


RING_FUNC(ring_MatrixTranspose_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixTranspose(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixInvert(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixNormalize(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixIdentity();
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixAdd(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixSubtract(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixTranslate( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixRotate(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixRotateXYZ(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixRotateX( (float ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixRotateY( (float ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixRotateZ( (float ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixScale( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixMultiply(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixFrustum( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5), (double ) RING_API_GETNUMBER(6));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixPerspective( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixOrtho( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5), (double ) RING_API_GETNUMBER(6));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = MatrixLookAt(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(3,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (float16 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(float16)) ;
		*pValue = MatrixToFloatV(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"float16",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionAdd(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionAddValue(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionSubtract(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionSubtractValue(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionIdentity();
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
}


RING_FUNC(ring_QuaternionNormalize_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Quaternion *pValue ; 
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionNormalize(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionInvert(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionMultiply(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionScale(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionDivide(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionLerp(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionNlerp(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionSlerp(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Quaternion  *) RING_API_GETCPOINTER(2,"Quaternion"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionFromVector3ToVector3(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Vector3  *) RING_API_GETCPOINTER(2,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionFromMatrix(* (Matrix  *) RING_API_GETCPOINTER(1,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = QuaternionToMatrix(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionFromAxisAngle(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionFromEuler( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = QuaternionToEuler(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
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
		pValue = (Quaternion *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Quaternion)) ;
		*pValue = QuaternionTransform(* (Quaternion  *) RING_API_GETCPOINTER(1,"Quaternion"),* (Matrix  *) RING_API_GETCPOINTER(2,"Matrix"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Quaternion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Matrix"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Quaternion",ring_state_free);
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


RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("initwindow",ring_InitWindow);
	ring_vm_funcregister("windowshouldclose",ring_WindowShouldClose);
	ring_vm_funcregister("closewindow",ring_CloseWindow);
	ring_vm_funcregister("iswindowready",ring_IsWindowReady);
	ring_vm_funcregister("iswindowminimized",ring_IsWindowMinimized);
	ring_vm_funcregister("iswindowresized",ring_IsWindowResized);
	ring_vm_funcregister("iswindowhidden",ring_IsWindowHidden);
	ring_vm_funcregister("togglefullscreen",ring_ToggleFullscreen);
	ring_vm_funcregister("unhidewindow",ring_UnhideWindow);
	ring_vm_funcregister("hidewindow",ring_HideWindow);
	ring_vm_funcregister("setwindowicon_2",ring_SetWindowIcon_2);
	ring_vm_funcregister("setwindowtitle",ring_SetWindowTitle);
	ring_vm_funcregister("setwindowposition",ring_SetWindowPosition);
	ring_vm_funcregister("setwindowmonitor",ring_SetWindowMonitor);
	ring_vm_funcregister("setwindowminsize",ring_SetWindowMinSize);
	ring_vm_funcregister("setwindowsize",ring_SetWindowSize);
	ring_vm_funcregister("getwindowhandle",ring_GetWindowHandle);
	ring_vm_funcregister("getscreenwidth",ring_GetScreenWidth);
	ring_vm_funcregister("getscreenheight",ring_GetScreenHeight);
	ring_vm_funcregister("getmonitorcount",ring_GetMonitorCount);
	ring_vm_funcregister("getmonitorwidth",ring_GetMonitorWidth);
	ring_vm_funcregister("getmonitorheight",ring_GetMonitorHeight);
	ring_vm_funcregister("getmonitorphysicalwidth",ring_GetMonitorPhysicalWidth);
	ring_vm_funcregister("getmonitorphysicalheight",ring_GetMonitorPhysicalHeight);
	ring_vm_funcregister("getmonitorname",ring_GetMonitorName);
	ring_vm_funcregister("getclipboardtext",ring_GetClipboardText);
	ring_vm_funcregister("setclipboardtext",ring_SetClipboardText);
	ring_vm_funcregister("showcursor",ring_ShowCursor);
	ring_vm_funcregister("hidecursor",ring_HideCursor);
	ring_vm_funcregister("iscursorhidden",ring_IsCursorHidden);
	ring_vm_funcregister("enablecursor",ring_EnableCursor);
	ring_vm_funcregister("disablecursor",ring_DisableCursor);
	ring_vm_funcregister("clearbackground_2",ring_ClearBackground_2);
	ring_vm_funcregister("begindrawing",ring_BeginDrawing);
	ring_vm_funcregister("enddrawing",ring_EndDrawing);
	ring_vm_funcregister("beginmode2d_2",ring_BeginMode2D_2);
	ring_vm_funcregister("endmode2d",ring_EndMode2D);
	ring_vm_funcregister("beginmode3d_2",ring_BeginMode3D_2);
	ring_vm_funcregister("endmode3d",ring_EndMode3D);
	ring_vm_funcregister("begintexturemode_2",ring_BeginTextureMode_2);
	ring_vm_funcregister("endtexturemode",ring_EndTextureMode);
	ring_vm_funcregister("getmouseray_2",ring_GetMouseRay_2);
	ring_vm_funcregister("getworldtoscreen_2",ring_GetWorldToScreen_2);
	ring_vm_funcregister("getcameramatrix_2",ring_GetCameraMatrix_2);
	ring_vm_funcregister("settargetfps",ring_SetTargetFPS);
	ring_vm_funcregister("getfps",ring_GetFPS);
	ring_vm_funcregister("getframetime",ring_GetFrameTime);
	ring_vm_funcregister("gettime",ring_GetTime);
	ring_vm_funcregister("colortoint_2",ring_ColorToInt_2);
	ring_vm_funcregister("colornormalize_2",ring_ColorNormalize_2);
	ring_vm_funcregister("colortohsv_2",ring_ColorToHSV_2);
	ring_vm_funcregister("colorfromhsv_2",ring_ColorFromHSV_2);
	ring_vm_funcregister("getcolor",ring_GetColor);
	ring_vm_funcregister("fade_2",ring_Fade_2);
	ring_vm_funcregister("setconfigflags",ring_SetConfigFlags);
	ring_vm_funcregister("settraceloglevel",ring_SetTraceLogLevel);
	ring_vm_funcregister("settracelogexit",ring_SetTraceLogExit);
	ring_vm_funcregister("settracelogcallback",ring_SetTraceLogCallback);
	ring_vm_funcregister("tracelog",ring_TraceLog);
	ring_vm_funcregister("takescreenshot",ring_TakeScreenshot);
	ring_vm_funcregister("getrandomvalue",ring_GetRandomValue);
	ring_vm_funcregister("fileexists",ring_FileExists);
	ring_vm_funcregister("isfileextension",ring_IsFileExtension);
	ring_vm_funcregister("getextension",ring_GetExtension);
	ring_vm_funcregister("getfilename",ring_GetFileName);
	ring_vm_funcregister("getfilenamewithoutext",ring_GetFileNameWithoutExt);
	ring_vm_funcregister("getdirectorypath",ring_GetDirectoryPath);
	ring_vm_funcregister("getworkingdirectory",ring_GetWorkingDirectory);
	ring_vm_funcregister("getdirectoryfiles",ring_GetDirectoryFiles);
	ring_vm_funcregister("cleardirectoryfiles",ring_ClearDirectoryFiles);
	ring_vm_funcregister("changedirectory",ring_ChangeDirectory);
	ring_vm_funcregister("isfiledropped",ring_IsFileDropped);
	ring_vm_funcregister("getdroppedfiles",ring_GetDroppedFiles);
	ring_vm_funcregister("cleardroppedfiles",ring_ClearDroppedFiles);
	ring_vm_funcregister("getfilemodtime",ring_GetFileModTime);
	ring_vm_funcregister("storagesavevalue",ring_StorageSaveValue);
	ring_vm_funcregister("storageloadvalue",ring_StorageLoadValue);
	ring_vm_funcregister("openurl",ring_OpenURL);
	ring_vm_funcregister("iskeypressed_2",ring_IsKeyPressed_2);
	ring_vm_funcregister("iskeydown_2",ring_IsKeyDown_2);
	ring_vm_funcregister("iskeyreleased_2",ring_IsKeyReleased_2);
	ring_vm_funcregister("iskeyup_2",ring_IsKeyUp_2);
	ring_vm_funcregister("getkeypressed",ring_GetKeyPressed);
	ring_vm_funcregister("setexitkey_2",ring_SetExitKey_2);
	ring_vm_funcregister("isgamepadavailable",ring_IsGamepadAvailable);
	ring_vm_funcregister("isgamepadname",ring_IsGamepadName);
	ring_vm_funcregister("getgamepadname",ring_GetGamepadName);
	ring_vm_funcregister("isgamepadbuttonpressed",ring_IsGamepadButtonPressed);
	ring_vm_funcregister("isgamepadbuttondown",ring_IsGamepadButtonDown);
	ring_vm_funcregister("isgamepadbuttonreleased",ring_IsGamepadButtonReleased);
	ring_vm_funcregister("isgamepadbuttonup",ring_IsGamepadButtonUp);
	ring_vm_funcregister("getgamepadbuttonpressed",ring_GetGamepadButtonPressed);
	ring_vm_funcregister("getgamepadaxiscount",ring_GetGamepadAxisCount);
	ring_vm_funcregister("getgamepadaxismovement",ring_GetGamepadAxisMovement);
	ring_vm_funcregister("ismousebuttonpressed",ring_IsMouseButtonPressed);
	ring_vm_funcregister("ismousebuttondown",ring_IsMouseButtonDown);
	ring_vm_funcregister("ismousebuttonreleased",ring_IsMouseButtonReleased);
	ring_vm_funcregister("ismousebuttonup",ring_IsMouseButtonUp);
	ring_vm_funcregister("getmousex",ring_GetMouseX);
	ring_vm_funcregister("getmousey",ring_GetMouseY);
	ring_vm_funcregister("getmouseposition_2",ring_GetMousePosition_2);
	ring_vm_funcregister("setmouseposition",ring_SetMousePosition);
	ring_vm_funcregister("setmouseoffset",ring_SetMouseOffset);
	ring_vm_funcregister("setmousescale",ring_SetMouseScale);
	ring_vm_funcregister("getmousewheelmove",ring_GetMouseWheelMove);
	ring_vm_funcregister("gettouchx",ring_GetTouchX);
	ring_vm_funcregister("gettouchy",ring_GetTouchY);
	ring_vm_funcregister("gettouchposition_2",ring_GetTouchPosition_2);
	ring_vm_funcregister("setgesturesenabled",ring_SetGesturesEnabled);
	ring_vm_funcregister("isgesturedetected",ring_IsGestureDetected);
	ring_vm_funcregister("getgesturedetected",ring_GetGestureDetected);
	ring_vm_funcregister("gettouchpointscount",ring_GetTouchPointsCount);
	ring_vm_funcregister("getgestureholdduration",ring_GetGestureHoldDuration);
	ring_vm_funcregister("getgesturedragvector_2",ring_GetGestureDragVector_2);
	ring_vm_funcregister("getgesturedragangle",ring_GetGestureDragAngle);
	ring_vm_funcregister("getgesturepinchvector_2",ring_GetGesturePinchVector_2);
	ring_vm_funcregister("getgesturepinchangle",ring_GetGesturePinchAngle);
	ring_vm_funcregister("setcameramode_2",ring_SetCameraMode_2);
	ring_vm_funcregister("updatecamera_2",ring_UpdateCamera_2);
	ring_vm_funcregister("setcamerapancontrol",ring_SetCameraPanControl);
	ring_vm_funcregister("setcameraaltcontrol",ring_SetCameraAltControl);
	ring_vm_funcregister("setcamerasmoothzoomcontrol",ring_SetCameraSmoothZoomControl);
	ring_vm_funcregister("setcameramovecontrols",ring_SetCameraMoveControls);
	ring_vm_funcregister("drawpixel_2",ring_DrawPixel_2);
	ring_vm_funcregister("drawpixelv_2",ring_DrawPixelV_2);
	ring_vm_funcregister("drawline_2",ring_DrawLine_2);
	ring_vm_funcregister("drawlinev_2",ring_DrawLineV_2);
	ring_vm_funcregister("drawlineex_2",ring_DrawLineEx_2);
	ring_vm_funcregister("drawlinebezier_2",ring_DrawLineBezier_2);
	ring_vm_funcregister("drawlinestrip_2",ring_DrawLineStrip_2);
	ring_vm_funcregister("drawcircle_2",ring_DrawCircle_2);
	ring_vm_funcregister("drawcirclesector_2",ring_DrawCircleSector_2);
	ring_vm_funcregister("drawcirclesectorlines_2",ring_DrawCircleSectorLines_2);
	ring_vm_funcregister("drawcirclegradient_2",ring_DrawCircleGradient_2);
	ring_vm_funcregister("drawcirclev_2",ring_DrawCircleV_2);
	ring_vm_funcregister("drawcirclelines_2",ring_DrawCircleLines_2);
	ring_vm_funcregister("drawring_2",ring_DrawRing_2);
	ring_vm_funcregister("drawringlines_2",ring_DrawRingLines_2);
	ring_vm_funcregister("drawrectangle_2",ring_DrawRectangle_2);
	ring_vm_funcregister("drawrectanglev_2",ring_DrawRectangleV_2);
	ring_vm_funcregister("drawrectanglerec_2",ring_DrawRectangleRec_2);
	ring_vm_funcregister("drawrectanglepro_2",ring_DrawRectanglePro_2);
	ring_vm_funcregister("drawrectanglegradientv_2",ring_DrawRectangleGradientV_2);
	ring_vm_funcregister("drawrectanglegradienth_2",ring_DrawRectangleGradientH_2);
	ring_vm_funcregister("drawrectanglegradientex_2",ring_DrawRectangleGradientEx_2);
	ring_vm_funcregister("drawrectanglelines_2",ring_DrawRectangleLines_2);
	ring_vm_funcregister("drawrectanglelinesex_2",ring_DrawRectangleLinesEx_2);
	ring_vm_funcregister("drawrectanglerounded_2",ring_DrawRectangleRounded_2);
	ring_vm_funcregister("drawrectangleroundedlines_2",ring_DrawRectangleRoundedLines_2);
	ring_vm_funcregister("drawtriangle_2",ring_DrawTriangle_2);
	ring_vm_funcregister("drawtrianglelines_2",ring_DrawTriangleLines_2);
	ring_vm_funcregister("drawtrianglefan_2",ring_DrawTriangleFan_2);
	ring_vm_funcregister("drawpoly_2",ring_DrawPoly_2);
	ring_vm_funcregister("setshapestexture_2",ring_SetShapesTexture_2);
	ring_vm_funcregister("checkcollisionrecs_2",ring_CheckCollisionRecs_2);
	ring_vm_funcregister("checkcollisioncircles_2",ring_CheckCollisionCircles_2);
	ring_vm_funcregister("checkcollisioncirclerec_2",ring_CheckCollisionCircleRec_2);
	ring_vm_funcregister("getcollisionrec_2",ring_GetCollisionRec_2);
	ring_vm_funcregister("checkcollisionpointrec_2",ring_CheckCollisionPointRec_2);
	ring_vm_funcregister("checkcollisionpointcircle_2",ring_CheckCollisionPointCircle_2);
	ring_vm_funcregister("checkcollisionpointtriangle_2",ring_CheckCollisionPointTriangle_2);
	ring_vm_funcregister("loadimage_2",ring_LoadImage_2);
	ring_vm_funcregister("loadimageex_2",ring_LoadImageEx_2);
	ring_vm_funcregister("loadimagepro_2",ring_LoadImagePro_2);
	ring_vm_funcregister("loadimageraw_2",ring_LoadImageRaw_2);
	ring_vm_funcregister("exportimage_2",ring_ExportImage_2);
	ring_vm_funcregister("exportimageascode_2",ring_ExportImageAsCode_2);
	ring_vm_funcregister("loadtexture_2",ring_LoadTexture_2);
	ring_vm_funcregister("loadtexturefromimage_2",ring_LoadTextureFromImage_2);
	ring_vm_funcregister("loadtexturecubemap",ring_LoadTextureCubemap);
	ring_vm_funcregister("loadrendertexture_2",ring_LoadRenderTexture_2);
	ring_vm_funcregister("unloadimage_2",ring_UnloadImage_2);
	ring_vm_funcregister("unloadtexture_2",ring_UnloadTexture_2);
	ring_vm_funcregister("unloadrendertexture_2",ring_UnloadRenderTexture_2);
	ring_vm_funcregister("getimagedata_2",ring_GetImageData_2);
	ring_vm_funcregister("getimagedatanormalized_2",ring_GetImageDataNormalized_2);
	ring_vm_funcregister("getpixeldatasize",ring_GetPixelDataSize);
	ring_vm_funcregister("gettexturedata_2",ring_GetTextureData_2);
	ring_vm_funcregister("getscreendata_2",ring_GetScreenData_2);
	ring_vm_funcregister("updatetexture_2",ring_UpdateTexture_2);
	ring_vm_funcregister("imagecopy_2",ring_ImageCopy_2);
	ring_vm_funcregister("imagetopot_2",ring_ImageToPOT_2);
	ring_vm_funcregister("imageformat_2",ring_ImageFormat_2);
	ring_vm_funcregister("imagealphamask_2",ring_ImageAlphaMask_2);
	ring_vm_funcregister("imagealphaclear_2",ring_ImageAlphaClear_2);
	ring_vm_funcregister("imagealphacrop_2",ring_ImageAlphaCrop_2);
	ring_vm_funcregister("imagealphapremultiply_2",ring_ImageAlphaPremultiply_2);
	ring_vm_funcregister("imagecrop_2",ring_ImageCrop_2);
	ring_vm_funcregister("imageresize_2",ring_ImageResize_2);
	ring_vm_funcregister("imageresizenn_2",ring_ImageResizeNN_2);
	ring_vm_funcregister("imageresizecanvas_2",ring_ImageResizeCanvas_2);
	ring_vm_funcregister("imagemipmaps_2",ring_ImageMipmaps_2);
	ring_vm_funcregister("imagedither_2",ring_ImageDither_2);
	ring_vm_funcregister("imageextractpalette_2",ring_ImageExtractPalette_2);
	ring_vm_funcregister("imagetext_2",ring_ImageText_2);
	ring_vm_funcregister("imagetextex_2",ring_ImageTextEx_2);
	ring_vm_funcregister("imagedraw_2",ring_ImageDraw_2);
	ring_vm_funcregister("imagedrawrectangle_2",ring_ImageDrawRectangle_2);
	ring_vm_funcregister("imagedrawrectanglelines_2",ring_ImageDrawRectangleLines_2);
	ring_vm_funcregister("imagedrawtext_2",ring_ImageDrawText_2);
	ring_vm_funcregister("imagedrawtextex_2",ring_ImageDrawTextEx_2);
	ring_vm_funcregister("imageflipvertical_2",ring_ImageFlipVertical_2);
	ring_vm_funcregister("imagefliphorizontal_2",ring_ImageFlipHorizontal_2);
	ring_vm_funcregister("imagerotatecw_2",ring_ImageRotateCW_2);
	ring_vm_funcregister("imagerotateccw_2",ring_ImageRotateCCW_2);
	ring_vm_funcregister("imagecolortint_2",ring_ImageColorTint_2);
	ring_vm_funcregister("imagecolorinvert_2",ring_ImageColorInvert_2);
	ring_vm_funcregister("imagecolorgrayscale_2",ring_ImageColorGrayscale_2);
	ring_vm_funcregister("imagecolorcontrast_2",ring_ImageColorContrast_2);
	ring_vm_funcregister("imagecolorbrightness_2",ring_ImageColorBrightness_2);
	ring_vm_funcregister("imagecolorreplace_2",ring_ImageColorReplace_2);
	ring_vm_funcregister("genimagecolor_2",ring_GenImageColor_2);
	ring_vm_funcregister("genimagegradientv_2",ring_GenImageGradientV_2);
	ring_vm_funcregister("genimagegradienth_2",ring_GenImageGradientH_2);
	ring_vm_funcregister("genimagegradientradial_2",ring_GenImageGradientRadial_2);
	ring_vm_funcregister("genimagechecked_2",ring_GenImageChecked_2);
	ring_vm_funcregister("genimagewhitenoise_2",ring_GenImageWhiteNoise_2);
	ring_vm_funcregister("genimageperlinnoise_2",ring_GenImagePerlinNoise_2);
	ring_vm_funcregister("genimagecellular_2",ring_GenImageCellular_2);
	ring_vm_funcregister("gentexturemipmaps_2",ring_GenTextureMipmaps_2);
	ring_vm_funcregister("settexturefilter_2",ring_SetTextureFilter_2);
	ring_vm_funcregister("settexturewrap_2",ring_SetTextureWrap_2);
	ring_vm_funcregister("drawtexture_2",ring_DrawTexture_2);
	ring_vm_funcregister("drawtexturev_2",ring_DrawTextureV_2);
	ring_vm_funcregister("drawtextureex_2",ring_DrawTextureEx_2);
	ring_vm_funcregister("drawtexturerec_2",ring_DrawTextureRec_2);
	ring_vm_funcregister("drawtexturequad_2",ring_DrawTextureQuad_2);
	ring_vm_funcregister("drawtexturepro_2",ring_DrawTexturePro_2);
	ring_vm_funcregister("drawtexturenpatch_2",ring_DrawTextureNPatch_2);
	ring_vm_funcregister("getfontdefault_2",ring_GetFontDefault_2);
	ring_vm_funcregister("loadfont_2",ring_LoadFont_2);
	ring_vm_funcregister("loadfontex_2",ring_LoadFontEx_2);
	ring_vm_funcregister("loadfontfromimage_2",ring_LoadFontFromImage_2);
	ring_vm_funcregister("loadfontdata_2",ring_LoadFontData_2);
	ring_vm_funcregister("genimagefontatlas_2",ring_GenImageFontAtlas_2);
	ring_vm_funcregister("unloadfont_2",ring_UnloadFont_2);
	ring_vm_funcregister("drawfps",ring_DrawFPS);
	ring_vm_funcregister("drawtext",ring_DrawText);
	ring_vm_funcregister("drawtextex_2",ring_DrawTextEx_2);
	ring_vm_funcregister("drawtextrec_2",ring_DrawTextRec_2);
	ring_vm_funcregister("drawtextrecex_2",ring_DrawTextRecEx_2);
	ring_vm_funcregister("measuretext",ring_MeasureText);
	ring_vm_funcregister("measuretextex_2",ring_MeasureTextEx_2);
	ring_vm_funcregister("getglyphindex_2",ring_GetGlyphIndex_2);
	ring_vm_funcregister("getnextcodepoint",ring_GetNextCodepoint);
	ring_vm_funcregister("textisequal",ring_TextIsEqual);
	ring_vm_funcregister("textlength",ring_TextLength);
	ring_vm_funcregister("textcountcodepoints",ring_TextCountCodepoints);
	ring_vm_funcregister("textformat",ring_TextFormat);
	ring_vm_funcregister("textsubtext",ring_TextSubtext);
	ring_vm_funcregister("textreplace",ring_TextReplace);
	ring_vm_funcregister("textinsert",ring_TextInsert);
	ring_vm_funcregister("textjoin",ring_TextJoin);
	ring_vm_funcregister("textsplit",ring_TextSplit);
	ring_vm_funcregister("textappend",ring_TextAppend);
	ring_vm_funcregister("textfindindex",ring_TextFindIndex);
	ring_vm_funcregister("texttoupper",ring_TextToUpper);
	ring_vm_funcregister("texttolower",ring_TextToLower);
	ring_vm_funcregister("texttopascal",ring_TextToPascal);
	ring_vm_funcregister("texttointeger",ring_TextToInteger);
	ring_vm_funcregister("drawline3d_2",ring_DrawLine3D_2);
	ring_vm_funcregister("drawcircle3d_2",ring_DrawCircle3D_2);
	ring_vm_funcregister("drawcube_2",ring_DrawCube_2);
	ring_vm_funcregister("drawcubev_2",ring_DrawCubeV_2);
	ring_vm_funcregister("drawcubewires_2",ring_DrawCubeWires_2);
	ring_vm_funcregister("drawcubewiresv_2",ring_DrawCubeWiresV_2);
	ring_vm_funcregister("drawcubetexture_2",ring_DrawCubeTexture_2);
	ring_vm_funcregister("drawsphere_2",ring_DrawSphere_2);
	ring_vm_funcregister("drawsphereex_2",ring_DrawSphereEx_2);
	ring_vm_funcregister("drawspherewires_2",ring_DrawSphereWires_2);
	ring_vm_funcregister("drawcylinder_2",ring_DrawCylinder_2);
	ring_vm_funcregister("drawcylinderwires_2",ring_DrawCylinderWires_2);
	ring_vm_funcregister("drawplane_2",ring_DrawPlane_2);
	ring_vm_funcregister("drawray_2",ring_DrawRay_2);
	ring_vm_funcregister("drawgrid",ring_DrawGrid);
	ring_vm_funcregister("drawgizmo_2",ring_DrawGizmo_2);
	ring_vm_funcregister("loadmodel_2",ring_LoadModel_2);
	ring_vm_funcregister("loadmodelfrommesh_2",ring_LoadModelFromMesh_2);
	ring_vm_funcregister("unloadmodel_2",ring_UnloadModel_2);
	ring_vm_funcregister("loadmeshes_2",ring_LoadMeshes_2);
	ring_vm_funcregister("exportmesh_2",ring_ExportMesh_2);
	ring_vm_funcregister("unloadmesh_2",ring_UnloadMesh_2);
	ring_vm_funcregister("loadmaterials_2",ring_LoadMaterials_2);
	ring_vm_funcregister("loadmaterialdefault_2",ring_LoadMaterialDefault_2);
	ring_vm_funcregister("unloadmaterial_2",ring_UnloadMaterial_2);
	ring_vm_funcregister("setmaterialtexture_2",ring_SetMaterialTexture_2);
	ring_vm_funcregister("setmodelmeshmaterial_2",ring_SetModelMeshMaterial_2);
	ring_vm_funcregister("loadmodelanimations_2",ring_LoadModelAnimations_2);
	ring_vm_funcregister("updatemodelanimation_2",ring_UpdateModelAnimation_2);
	ring_vm_funcregister("unloadmodelanimation_2",ring_UnloadModelAnimation_2);
	ring_vm_funcregister("ismodelanimationvalid_2",ring_IsModelAnimationValid_2);
	ring_vm_funcregister("genmeshpoly_2",ring_GenMeshPoly_2);
	ring_vm_funcregister("genmeshplane_2",ring_GenMeshPlane_2);
	ring_vm_funcregister("genmeshcube_2",ring_GenMeshCube_2);
	ring_vm_funcregister("genmeshsphere_2",ring_GenMeshSphere_2);
	ring_vm_funcregister("genmeshhemisphere_2",ring_GenMeshHemiSphere_2);
	ring_vm_funcregister("genmeshcylinder_2",ring_GenMeshCylinder_2);
	ring_vm_funcregister("genmeshtorus_2",ring_GenMeshTorus_2);
	ring_vm_funcregister("genmeshknot_2",ring_GenMeshKnot_2);
	ring_vm_funcregister("genmeshheightmap_2",ring_GenMeshHeightmap_2);
	ring_vm_funcregister("genmeshcubicmap_2",ring_GenMeshCubicmap_2);
	ring_vm_funcregister("meshboundingbox_2",ring_MeshBoundingBox_2);
	ring_vm_funcregister("meshtangents_2",ring_MeshTangents_2);
	ring_vm_funcregister("meshbinormals_2",ring_MeshBinormals_2);
	ring_vm_funcregister("drawmodel_2",ring_DrawModel_2);
	ring_vm_funcregister("drawmodelex_2",ring_DrawModelEx_2);
	ring_vm_funcregister("drawmodelwires_2",ring_DrawModelWires_2);
	ring_vm_funcregister("drawmodelwiresex_2",ring_DrawModelWiresEx_2);
	ring_vm_funcregister("drawboundingbox_2",ring_DrawBoundingBox_2);
	ring_vm_funcregister("drawbillboard_2",ring_DrawBillboard_2);
	ring_vm_funcregister("drawbillboardrec_2",ring_DrawBillboardRec_2);
	ring_vm_funcregister("checkcollisionspheres_2",ring_CheckCollisionSpheres_2);
	ring_vm_funcregister("checkcollisionboxes_2",ring_CheckCollisionBoxes_2);
	ring_vm_funcregister("checkcollisionboxsphere_2",ring_CheckCollisionBoxSphere_2);
	ring_vm_funcregister("checkcollisionraysphere_2",ring_CheckCollisionRaySphere_2);
	ring_vm_funcregister("checkcollisionraysphereex_2",ring_CheckCollisionRaySphereEx_2);
	ring_vm_funcregister("checkcollisionraybox_2",ring_CheckCollisionRayBox_2);
	ring_vm_funcregister("getcollisionraymodel_2",ring_GetCollisionRayModel_2);
	ring_vm_funcregister("getcollisionraytriangle_2",ring_GetCollisionRayTriangle_2);
	ring_vm_funcregister("getcollisionrayground_2",ring_GetCollisionRayGround_2);
	ring_vm_funcregister("loadtext",ring_LoadText);
	ring_vm_funcregister("loadshader_2",ring_LoadShader_2);
	ring_vm_funcregister("loadshadercode_2",ring_LoadShaderCode_2);
	ring_vm_funcregister("unloadshader_2",ring_UnloadShader_2);
	ring_vm_funcregister("getshaderdefault_2",ring_GetShaderDefault_2);
	ring_vm_funcregister("gettexturedefault_2",ring_GetTextureDefault_2);
	ring_vm_funcregister("getshaderlocation_2",ring_GetShaderLocation_2);
	ring_vm_funcregister("setshadervalue_2",ring_SetShaderValue_2);
	ring_vm_funcregister("setshadervaluev_2",ring_SetShaderValueV_2);
	ring_vm_funcregister("setshadervaluematrix_2",ring_SetShaderValueMatrix_2);
	ring_vm_funcregister("setshadervaluetexture_2",ring_SetShaderValueTexture_2);
	ring_vm_funcregister("setmatrixprojection_2",ring_SetMatrixProjection_2);
	ring_vm_funcregister("setmatrixmodelview_2",ring_SetMatrixModelview_2);
	ring_vm_funcregister("getmatrixmodelview_2",ring_GetMatrixModelview_2);
	ring_vm_funcregister("gentexturecubemap_2",ring_GenTextureCubemap_2);
	ring_vm_funcregister("gentextureirradiance_2",ring_GenTextureIrradiance_2);
	ring_vm_funcregister("gentextureprefilter_2",ring_GenTexturePrefilter_2);
	ring_vm_funcregister("gentexturebrdf_2",ring_GenTextureBRDF_2);
	ring_vm_funcregister("beginshadermode_2",ring_BeginShaderMode_2);
	ring_vm_funcregister("endshadermode",ring_EndShaderMode);
	ring_vm_funcregister("beginblendmode",ring_BeginBlendMode);
	ring_vm_funcregister("endblendmode",ring_EndBlendMode);
	ring_vm_funcregister("beginscissormode",ring_BeginScissorMode);
	ring_vm_funcregister("endscissormode",ring_EndScissorMode);
	ring_vm_funcregister("initvrsimulator",ring_InitVrSimulator);
	ring_vm_funcregister("closevrsimulator",ring_CloseVrSimulator);
	ring_vm_funcregister("updatevrtracking_2",ring_UpdateVrTracking_2);
	ring_vm_funcregister("setvrconfiguration_2",ring_SetVrConfiguration_2);
	ring_vm_funcregister("isvrsimulatorready",ring_IsVrSimulatorReady);
	ring_vm_funcregister("togglevrmode",ring_ToggleVrMode);
	ring_vm_funcregister("beginvrdrawing",ring_BeginVrDrawing);
	ring_vm_funcregister("endvrdrawing",ring_EndVrDrawing);
	ring_vm_funcregister("initaudiodevice",ring_InitAudioDevice);
	ring_vm_funcregister("closeaudiodevice",ring_CloseAudioDevice);
	ring_vm_funcregister("isaudiodeviceready",ring_IsAudioDeviceReady);
	ring_vm_funcregister("setmastervolume",ring_SetMasterVolume);
	ring_vm_funcregister("loadwave_2",ring_LoadWave_2);
	ring_vm_funcregister("loadwaveex_2",ring_LoadWaveEx_2);
	ring_vm_funcregister("loadsound_2",ring_LoadSound_2);
	ring_vm_funcregister("loadsoundfromwave_2",ring_LoadSoundFromWave_2);
	ring_vm_funcregister("updatesound_2",ring_UpdateSound_2);
	ring_vm_funcregister("unloadwave_2",ring_UnloadWave_2);
	ring_vm_funcregister("unloadsound_2",ring_UnloadSound_2);
	ring_vm_funcregister("exportwave_2",ring_ExportWave_2);
	ring_vm_funcregister("exportwaveascode_2",ring_ExportWaveAsCode_2);
	ring_vm_funcregister("playsound_2",ring_PlaySound_2);
	ring_vm_funcregister("pausesound_2",ring_PauseSound_2);
	ring_vm_funcregister("resumesound_2",ring_ResumeSound_2);
	ring_vm_funcregister("stopsound_2",ring_StopSound_2);
	ring_vm_funcregister("issoundplaying_2",ring_IsSoundPlaying_2);
	ring_vm_funcregister("setsoundvolume_2",ring_SetSoundVolume_2);
	ring_vm_funcregister("setsoundpitch_2",ring_SetSoundPitch_2);
	ring_vm_funcregister("waveformat_2",ring_WaveFormat_2);
	ring_vm_funcregister("wavecopy_2",ring_WaveCopy_2);
	ring_vm_funcregister("wavecrop_2",ring_WaveCrop_2);
	ring_vm_funcregister("getwavedata_2",ring_GetWaveData_2);
	ring_vm_funcregister("loadmusicstream_2",ring_LoadMusicStream_2);
	ring_vm_funcregister("unloadmusicstream_2",ring_UnloadMusicStream_2);
	ring_vm_funcregister("playmusicstream_2",ring_PlayMusicStream_2);
	ring_vm_funcregister("updatemusicstream_2",ring_UpdateMusicStream_2);
	ring_vm_funcregister("stopmusicstream_2",ring_StopMusicStream_2);
	ring_vm_funcregister("pausemusicstream_2",ring_PauseMusicStream_2);
	ring_vm_funcregister("resumemusicstream_2",ring_ResumeMusicStream_2);
	ring_vm_funcregister("ismusicplaying_2",ring_IsMusicPlaying_2);
	ring_vm_funcregister("setmusicvolume_2",ring_SetMusicVolume_2);
	ring_vm_funcregister("setmusicpitch_2",ring_SetMusicPitch_2);
	ring_vm_funcregister("setmusicloopcount_2",ring_SetMusicLoopCount_2);
	ring_vm_funcregister("getmusictimelength_2",ring_GetMusicTimeLength_2);
	ring_vm_funcregister("getmusictimeplayed_2",ring_GetMusicTimePlayed_2);
	ring_vm_funcregister("initaudiostream_2",ring_InitAudioStream_2);
	ring_vm_funcregister("updateaudiostream_2",ring_UpdateAudioStream_2);
	ring_vm_funcregister("closeaudiostream_2",ring_CloseAudioStream_2);
	ring_vm_funcregister("isaudiobufferprocessed_2",ring_IsAudioBufferProcessed_2);
	ring_vm_funcregister("playaudiostream_2",ring_PlayAudioStream_2);
	ring_vm_funcregister("pauseaudiostream_2",ring_PauseAudioStream_2);
	ring_vm_funcregister("resumeaudiostream_2",ring_ResumeAudioStream_2);
	ring_vm_funcregister("isaudiostreamplaying_2",ring_IsAudioStreamPlaying_2);
	ring_vm_funcregister("stopaudiostream_2",ring_StopAudioStream_2);
	ring_vm_funcregister("setaudiostreamvolume_2",ring_SetAudioStreamVolume_2);
	ring_vm_funcregister("setaudiostreampitch_2",ring_SetAudioStreamPitch_2);
	ring_vm_funcregister("guienable",ring_GuiEnable);
	ring_vm_funcregister("guidisable",ring_GuiDisable);
	ring_vm_funcregister("guilock",ring_GuiLock);
	ring_vm_funcregister("guiunlock",ring_GuiUnlock);
	ring_vm_funcregister("guistate",ring_GuiState);
	ring_vm_funcregister("guifont",ring_GuiFont);
	ring_vm_funcregister("guifade",ring_GuiFade);
	ring_vm_funcregister("guisetstyle",ring_GuiSetStyle);
	ring_vm_funcregister("guigetstyle",ring_GuiGetStyle);
	ring_vm_funcregister("guiwindowbox_2",ring_GuiWindowBox_2);
	ring_vm_funcregister("guigroupbox_2",ring_GuiGroupBox_2);
	ring_vm_funcregister("guiline_2",ring_GuiLine_2);
	ring_vm_funcregister("guipanel_2",ring_GuiPanel_2);
	ring_vm_funcregister("guiscrollpanel_2",ring_GuiScrollPanel_2);
	ring_vm_funcregister("guilabel_2",ring_GuiLabel_2);
	ring_vm_funcregister("guibutton_2",ring_GuiButton_2);
	ring_vm_funcregister("guilabelbutton_2",ring_GuiLabelButton_2);
	ring_vm_funcregister("guiimagebutton_2",ring_GuiImageButton_2);
	ring_vm_funcregister("guiimagebuttonex_2",ring_GuiImageButtonEx_2);
	ring_vm_funcregister("guitoggle_2",ring_GuiToggle_2);
	ring_vm_funcregister("guitogglegroup_2",ring_GuiToggleGroup_2);
	ring_vm_funcregister("guicheckbox_2",ring_GuiCheckBox_2);
	ring_vm_funcregister("guicombobox_2",ring_GuiComboBox_2);
	ring_vm_funcregister("guidropdownbox_2",ring_GuiDropdownBox_2);
	ring_vm_funcregister("guispinner_2",ring_GuiSpinner_2);
	ring_vm_funcregister("guivaluebox_2",ring_GuiValueBox_2);
	ring_vm_funcregister("guitextbox_2",ring_GuiTextBox_2);
	ring_vm_funcregister("guitextboxmulti_2",ring_GuiTextBoxMulti_2);
	ring_vm_funcregister("guislider_2",ring_GuiSlider_2);
	ring_vm_funcregister("guisliderbar_2",ring_GuiSliderBar_2);
	ring_vm_funcregister("guiprogressbar_2",ring_GuiProgressBar_2);
	ring_vm_funcregister("guistatusbar_2",ring_GuiStatusBar_2);
	ring_vm_funcregister("guidummyrec_2",ring_GuiDummyRec_2);
	ring_vm_funcregister("guiscrollbar_2",ring_GuiScrollBar_2);
	ring_vm_funcregister("guigrid_2",ring_GuiGrid_2);
	ring_vm_funcregister("guilistview_2",ring_GuiListView_2);
	ring_vm_funcregister("guilistviewex_2",ring_GuiListViewEx_2);
	ring_vm_funcregister("guimessagebox_2",ring_GuiMessageBox_2);
	ring_vm_funcregister("guitextinputbox_2",ring_GuiTextInputBox_2);
	ring_vm_funcregister("guicolorpicker_2",ring_GuiColorPicker_2);
	ring_vm_funcregister("guiloadstyle",ring_GuiLoadStyle);
	ring_vm_funcregister("guiloadstyleprops",ring_GuiLoadStyleProps);
	ring_vm_funcregister("guiloadstyledefault",ring_GuiLoadStyleDefault);
	ring_vm_funcregister("guiupdatestylecomplete",ring_GuiUpdateStyleComplete);
	ring_vm_funcregister("guiicontext",ring_GuiIconText);
	ring_vm_funcregister("clamp",ring_Clamp);
	ring_vm_funcregister("lerp",ring_Lerp);
	ring_vm_funcregister("normalize",ring_Normalize);
	ring_vm_funcregister("remap",ring_Remap);
	ring_vm_funcregister("vector2zero_2",ring_Vector2Zero_2);
	ring_vm_funcregister("vector2one_2",ring_Vector2One_2);
	ring_vm_funcregister("vector2add_2",ring_Vector2Add_2);
	ring_vm_funcregister("vector2addvalue_2",ring_Vector2AddValue_2);
	ring_vm_funcregister("vector2subtract_2",ring_Vector2Subtract_2);
	ring_vm_funcregister("vector2subtractvalue_2",ring_Vector2SubtractValue_2);
	ring_vm_funcregister("vector2length_2",ring_Vector2Length_2);
	ring_vm_funcregister("vector2lengthsqr_2",ring_Vector2LengthSqr_2);
	ring_vm_funcregister("vector2dotproduct_2",ring_Vector2DotProduct_2);
	ring_vm_funcregister("vector2distance_2",ring_Vector2Distance_2);
	ring_vm_funcregister("vector2angle_2",ring_Vector2Angle_2);
	ring_vm_funcregister("vector2scale_2",ring_Vector2Scale_2);
	ring_vm_funcregister("vector2multiply_2",ring_Vector2Multiply_2);
	ring_vm_funcregister("vector2negate_2",ring_Vector2Negate_2);
	ring_vm_funcregister("vector2divide_2",ring_Vector2Divide_2);
	ring_vm_funcregister("vector2normalize_2",ring_Vector2Normalize_2);
	ring_vm_funcregister("vector2lerp_2",ring_Vector2Lerp_2);
	ring_vm_funcregister("vector2rotate_2",ring_Vector2Rotate_2);
	ring_vm_funcregister("vector2movetowards_2",ring_Vector2MoveTowards_2);
	ring_vm_funcregister("vector3zero_2",ring_Vector3Zero_2);
	ring_vm_funcregister("vector3one_2",ring_Vector3One_2);
	ring_vm_funcregister("vector3add_2",ring_Vector3Add_2);
	ring_vm_funcregister("vector3addvalue_2",ring_Vector3AddValue_2);
	ring_vm_funcregister("vector3subtract_2",ring_Vector3Subtract_2);
	ring_vm_funcregister("vector3subtractvalue_2",ring_Vector3SubtractValue_2);
	ring_vm_funcregister("vector3scale_2",ring_Vector3Scale_2);
	ring_vm_funcregister("vector3multiply_2",ring_Vector3Multiply_2);
	ring_vm_funcregister("vector3crossproduct_2",ring_Vector3CrossProduct_2);
	ring_vm_funcregister("vector3perpendicular_2",ring_Vector3Perpendicular_2);
	ring_vm_funcregister("vector3length_2",ring_Vector3Length_2);
	ring_vm_funcregister("vector3lengthsqr_2",ring_Vector3LengthSqr_2);
	ring_vm_funcregister("vector3dotproduct_2",ring_Vector3DotProduct_2);
	ring_vm_funcregister("vector3distance_2",ring_Vector3Distance_2);
	ring_vm_funcregister("vector3negate_2",ring_Vector3Negate_2);
	ring_vm_funcregister("vector3divide_2",ring_Vector3Divide_2);
	ring_vm_funcregister("vector3normalize_2",ring_Vector3Normalize_2);
	ring_vm_funcregister("vector3orthonormalize_2",ring_Vector3OrthoNormalize_2);
	ring_vm_funcregister("vector3transform_2",ring_Vector3Transform_2);
	ring_vm_funcregister("vector3rotatebyquaternion_2",ring_Vector3RotateByQuaternion_2);
	ring_vm_funcregister("vector3lerp_2",ring_Vector3Lerp_2);
	ring_vm_funcregister("vector3reflect_2",ring_Vector3Reflect_2);
	ring_vm_funcregister("vector3min_2",ring_Vector3Min_2);
	ring_vm_funcregister("vector3max_2",ring_Vector3Max_2);
	ring_vm_funcregister("vector3barycenter_2",ring_Vector3Barycenter_2);
	ring_vm_funcregister("vector3tofloatv_2",ring_Vector3ToFloatV_2);
	ring_vm_funcregister("matrixdeterminant_2",ring_MatrixDeterminant_2);
	ring_vm_funcregister("matrixtrace_2",ring_MatrixTrace_2);
	ring_vm_funcregister("matrixtranspose_2",ring_MatrixTranspose_2);
	ring_vm_funcregister("matrixinvert_2",ring_MatrixInvert_2);
	ring_vm_funcregister("matrixnormalize_2",ring_MatrixNormalize_2);
	ring_vm_funcregister("matrixidentity_2",ring_MatrixIdentity_2);
	ring_vm_funcregister("matrixadd_2",ring_MatrixAdd_2);
	ring_vm_funcregister("matrixsubtract_2",ring_MatrixSubtract_2);
	ring_vm_funcregister("matrixtranslate_2",ring_MatrixTranslate_2);
	ring_vm_funcregister("matrixrotate_2",ring_MatrixRotate_2);
	ring_vm_funcregister("matrixrotatexyz_2",ring_MatrixRotateXYZ_2);
	ring_vm_funcregister("matrixrotatex_2",ring_MatrixRotateX_2);
	ring_vm_funcregister("matrixrotatey_2",ring_MatrixRotateY_2);
	ring_vm_funcregister("matrixrotatez_2",ring_MatrixRotateZ_2);
	ring_vm_funcregister("matrixscale_2",ring_MatrixScale_2);
	ring_vm_funcregister("matrixmultiply_2",ring_MatrixMultiply_2);
	ring_vm_funcregister("matrixfrustum_2",ring_MatrixFrustum_2);
	ring_vm_funcregister("matrixperspective_2",ring_MatrixPerspective_2);
	ring_vm_funcregister("matrixortho_2",ring_MatrixOrtho_2);
	ring_vm_funcregister("matrixlookat_2",ring_MatrixLookAt_2);
	ring_vm_funcregister("matrixtofloatv_2",ring_MatrixToFloatV_2);
	ring_vm_funcregister("quaternionadd_2",ring_QuaternionAdd_2);
	ring_vm_funcregister("quaternionaddvalue_2",ring_QuaternionAddValue_2);
	ring_vm_funcregister("quaternionsubtract_2",ring_QuaternionSubtract_2);
	ring_vm_funcregister("quaternionsubtractvalue_2",ring_QuaternionSubtractValue_2);
	ring_vm_funcregister("quaternionidentity_2",ring_QuaternionIdentity_2);
	ring_vm_funcregister("quaternionlength_2",ring_QuaternionLength_2);
	ring_vm_funcregister("quaternionnormalize_2",ring_QuaternionNormalize_2);
	ring_vm_funcregister("quaternioninvert_2",ring_QuaternionInvert_2);
	ring_vm_funcregister("quaternionmultiply_2",ring_QuaternionMultiply_2);
	ring_vm_funcregister("quaternionscale_2",ring_QuaternionScale_2);
	ring_vm_funcregister("quaterniondivide_2",ring_QuaternionDivide_2);
	ring_vm_funcregister("quaternionlerp_2",ring_QuaternionLerp_2);
	ring_vm_funcregister("quaternionnlerp_2",ring_QuaternionNlerp_2);
	ring_vm_funcregister("quaternionslerp_2",ring_QuaternionSlerp_2);
	ring_vm_funcregister("quaternionfromvector3tovector3_2",ring_QuaternionFromVector3ToVector3_2);
	ring_vm_funcregister("quaternionfrommatrix_2",ring_QuaternionFromMatrix_2);
	ring_vm_funcregister("quaterniontomatrix_2",ring_QuaternionToMatrix_2);
	ring_vm_funcregister("quaternionfromaxisangle_2",ring_QuaternionFromAxisAngle_2);
	ring_vm_funcregister("quaterniontoaxisangle_2",ring_QuaternionToAxisAngle_2);
	ring_vm_funcregister("quaternionfromeuler_2",ring_QuaternionFromEuler_2);
	ring_vm_funcregister("quaterniontoeuler_2",ring_QuaternionToEuler_2);
	ring_vm_funcregister("quaterniontransform_2",ring_QuaternionTransform_2);
	ring_vm_funcregister("setmodelmaterialtexture_2",ring_setmodelmaterialtexture_2);
	ring_vm_funcregister("getimagepixelr_2",ring_getimagepixelr_2);
	ring_vm_funcregister("getimagepixelg_2",ring_getimagepixelg_2);
	ring_vm_funcregister("getimagepixelb_2",ring_getimagepixelb_2);
	ring_vm_funcregister("getimagepixela_2",ring_getimagepixela_2);
	ring_vm_funcregister("raylib_new_vector2",ring_raylib_new_vector2);
	ring_vm_funcregister("raylib_new_managed_vector2",ring_raylib_new_managed_vector2);
	ring_vm_funcregister("raylib_destroy_vector2",ring_raylib_destroy_vector2);
	ring_vm_funcregister("raylib_get_vector2_x",ring_raylib_get_vector2_x);
	ring_vm_funcregister("raylib_set_vector2_x",ring_raylib_set_vector2_x);
	ring_vm_funcregister("raylib_get_vector2_y",ring_raylib_get_vector2_y);
	ring_vm_funcregister("raylib_set_vector2_y",ring_raylib_set_vector2_y);
	ring_vm_funcregister("raylib_new_vector3",ring_raylib_new_vector3);
	ring_vm_funcregister("raylib_new_managed_vector3",ring_raylib_new_managed_vector3);
	ring_vm_funcregister("raylib_destroy_vector3",ring_raylib_destroy_vector3);
	ring_vm_funcregister("raylib_get_vector3_x",ring_raylib_get_vector3_x);
	ring_vm_funcregister("raylib_set_vector3_x",ring_raylib_set_vector3_x);
	ring_vm_funcregister("raylib_get_vector3_y",ring_raylib_get_vector3_y);
	ring_vm_funcregister("raylib_set_vector3_y",ring_raylib_set_vector3_y);
	ring_vm_funcregister("raylib_get_vector3_z",ring_raylib_get_vector3_z);
	ring_vm_funcregister("raylib_set_vector3_z",ring_raylib_set_vector3_z);
	ring_vm_funcregister("raylib_new_vector4",ring_raylib_new_vector4);
	ring_vm_funcregister("raylib_new_managed_vector4",ring_raylib_new_managed_vector4);
	ring_vm_funcregister("raylib_destroy_vector4",ring_raylib_destroy_vector4);
	ring_vm_funcregister("raylib_get_vector4_x",ring_raylib_get_vector4_x);
	ring_vm_funcregister("raylib_set_vector4_x",ring_raylib_set_vector4_x);
	ring_vm_funcregister("raylib_get_vector4_y",ring_raylib_get_vector4_y);
	ring_vm_funcregister("raylib_set_vector4_y",ring_raylib_set_vector4_y);
	ring_vm_funcregister("raylib_get_vector4_z",ring_raylib_get_vector4_z);
	ring_vm_funcregister("raylib_set_vector4_z",ring_raylib_set_vector4_z);
	ring_vm_funcregister("raylib_get_vector4_w",ring_raylib_get_vector4_w);
	ring_vm_funcregister("raylib_set_vector4_w",ring_raylib_set_vector4_w);
	ring_vm_funcregister("raylib_new_quaternion",ring_raylib_new_quaternion);
	ring_vm_funcregister("raylib_new_managed_quaternion",ring_raylib_new_managed_quaternion);
	ring_vm_funcregister("raylib_destroy_quaternion",ring_raylib_destroy_quaternion);
	ring_vm_funcregister("raylib_get_quaternion_x",ring_raylib_get_quaternion_x);
	ring_vm_funcregister("raylib_set_quaternion_x",ring_raylib_set_quaternion_x);
	ring_vm_funcregister("raylib_get_quaternion_y",ring_raylib_get_quaternion_y);
	ring_vm_funcregister("raylib_set_quaternion_y",ring_raylib_set_quaternion_y);
	ring_vm_funcregister("raylib_get_quaternion_z",ring_raylib_get_quaternion_z);
	ring_vm_funcregister("raylib_set_quaternion_z",ring_raylib_set_quaternion_z);
	ring_vm_funcregister("raylib_get_quaternion_w",ring_raylib_get_quaternion_w);
	ring_vm_funcregister("raylib_set_quaternion_w",ring_raylib_set_quaternion_w);
	ring_vm_funcregister("raylib_new_matrix",ring_raylib_new_matrix);
	ring_vm_funcregister("raylib_new_managed_matrix",ring_raylib_new_managed_matrix);
	ring_vm_funcregister("raylib_destroy_matrix",ring_raylib_destroy_matrix);
	ring_vm_funcregister("raylib_get_matrix_m0",ring_raylib_get_matrix_m0);
	ring_vm_funcregister("raylib_set_matrix_m0",ring_raylib_set_matrix_m0);
	ring_vm_funcregister("raylib_get_matrix_m1",ring_raylib_get_matrix_m1);
	ring_vm_funcregister("raylib_set_matrix_m1",ring_raylib_set_matrix_m1);
	ring_vm_funcregister("raylib_get_matrix_m2",ring_raylib_get_matrix_m2);
	ring_vm_funcregister("raylib_set_matrix_m2",ring_raylib_set_matrix_m2);
	ring_vm_funcregister("raylib_get_matrix_m3",ring_raylib_get_matrix_m3);
	ring_vm_funcregister("raylib_set_matrix_m3",ring_raylib_set_matrix_m3);
	ring_vm_funcregister("raylib_get_matrix_m4",ring_raylib_get_matrix_m4);
	ring_vm_funcregister("raylib_set_matrix_m4",ring_raylib_set_matrix_m4);
	ring_vm_funcregister("raylib_get_matrix_m5",ring_raylib_get_matrix_m5);
	ring_vm_funcregister("raylib_set_matrix_m5",ring_raylib_set_matrix_m5);
	ring_vm_funcregister("raylib_get_matrix_m6",ring_raylib_get_matrix_m6);
	ring_vm_funcregister("raylib_set_matrix_m6",ring_raylib_set_matrix_m6);
	ring_vm_funcregister("raylib_get_matrix_m7",ring_raylib_get_matrix_m7);
	ring_vm_funcregister("raylib_set_matrix_m7",ring_raylib_set_matrix_m7);
	ring_vm_funcregister("raylib_get_matrix_m8",ring_raylib_get_matrix_m8);
	ring_vm_funcregister("raylib_set_matrix_m8",ring_raylib_set_matrix_m8);
	ring_vm_funcregister("raylib_get_matrix_m9",ring_raylib_get_matrix_m9);
	ring_vm_funcregister("raylib_set_matrix_m9",ring_raylib_set_matrix_m9);
	ring_vm_funcregister("raylib_get_matrix_m10",ring_raylib_get_matrix_m10);
	ring_vm_funcregister("raylib_set_matrix_m10",ring_raylib_set_matrix_m10);
	ring_vm_funcregister("raylib_get_matrix_m11",ring_raylib_get_matrix_m11);
	ring_vm_funcregister("raylib_set_matrix_m11",ring_raylib_set_matrix_m11);
	ring_vm_funcregister("raylib_get_matrix_m12",ring_raylib_get_matrix_m12);
	ring_vm_funcregister("raylib_set_matrix_m12",ring_raylib_set_matrix_m12);
	ring_vm_funcregister("raylib_get_matrix_m13",ring_raylib_get_matrix_m13);
	ring_vm_funcregister("raylib_set_matrix_m13",ring_raylib_set_matrix_m13);
	ring_vm_funcregister("raylib_get_matrix_m14",ring_raylib_get_matrix_m14);
	ring_vm_funcregister("raylib_set_matrix_m14",ring_raylib_set_matrix_m14);
	ring_vm_funcregister("raylib_get_matrix_m15",ring_raylib_get_matrix_m15);
	ring_vm_funcregister("raylib_set_matrix_m15",ring_raylib_set_matrix_m15);
	ring_vm_funcregister("raylib_new_color",ring_raylib_new_color);
	ring_vm_funcregister("raylib_new_managed_color",ring_raylib_new_managed_color);
	ring_vm_funcregister("raylib_destroy_color",ring_raylib_destroy_color);
	ring_vm_funcregister("raylib_get_color_r",ring_raylib_get_color_r);
	ring_vm_funcregister("raylib_set_color_r",ring_raylib_set_color_r);
	ring_vm_funcregister("raylib_get_color_g",ring_raylib_get_color_g);
	ring_vm_funcregister("raylib_set_color_g",ring_raylib_set_color_g);
	ring_vm_funcregister("raylib_get_color_b",ring_raylib_get_color_b);
	ring_vm_funcregister("raylib_set_color_b",ring_raylib_set_color_b);
	ring_vm_funcregister("raylib_get_color_a",ring_raylib_get_color_a);
	ring_vm_funcregister("raylib_set_color_a",ring_raylib_set_color_a);
	ring_vm_funcregister("raylib_new_rectangle",ring_raylib_new_rectangle);
	ring_vm_funcregister("raylib_new_managed_rectangle",ring_raylib_new_managed_rectangle);
	ring_vm_funcregister("raylib_destroy_rectangle",ring_raylib_destroy_rectangle);
	ring_vm_funcregister("raylib_get_rectangle_x",ring_raylib_get_rectangle_x);
	ring_vm_funcregister("raylib_set_rectangle_x",ring_raylib_set_rectangle_x);
	ring_vm_funcregister("raylib_get_rectangle_y",ring_raylib_get_rectangle_y);
	ring_vm_funcregister("raylib_set_rectangle_y",ring_raylib_set_rectangle_y);
	ring_vm_funcregister("raylib_get_rectangle_width",ring_raylib_get_rectangle_width);
	ring_vm_funcregister("raylib_set_rectangle_width",ring_raylib_set_rectangle_width);
	ring_vm_funcregister("raylib_get_rectangle_height",ring_raylib_get_rectangle_height);
	ring_vm_funcregister("raylib_set_rectangle_height",ring_raylib_set_rectangle_height);
	ring_vm_funcregister("raylib_new_image",ring_raylib_new_image);
	ring_vm_funcregister("raylib_new_managed_image",ring_raylib_new_managed_image);
	ring_vm_funcregister("raylib_destroy_image",ring_raylib_destroy_image);
	ring_vm_funcregister("raylib_get_image_data",ring_raylib_get_image_data);
	ring_vm_funcregister("raylib_set_image_data",ring_raylib_set_image_data);
	ring_vm_funcregister("raylib_get_image_width",ring_raylib_get_image_width);
	ring_vm_funcregister("raylib_set_image_width",ring_raylib_set_image_width);
	ring_vm_funcregister("raylib_get_image_height",ring_raylib_get_image_height);
	ring_vm_funcregister("raylib_set_image_height",ring_raylib_set_image_height);
	ring_vm_funcregister("raylib_get_image_mipmaps",ring_raylib_get_image_mipmaps);
	ring_vm_funcregister("raylib_set_image_mipmaps",ring_raylib_set_image_mipmaps);
	ring_vm_funcregister("raylib_get_image_format",ring_raylib_get_image_format);
	ring_vm_funcregister("raylib_set_image_format",ring_raylib_set_image_format);
	ring_vm_funcregister("raylib_new_texture2d",ring_raylib_new_texture2d);
	ring_vm_funcregister("raylib_new_managed_texture2d",ring_raylib_new_managed_texture2d);
	ring_vm_funcregister("raylib_destroy_texture2d",ring_raylib_destroy_texture2d);
	ring_vm_funcregister("raylib_get_texture2d_id",ring_raylib_get_texture2d_id);
	ring_vm_funcregister("raylib_set_texture2d_id",ring_raylib_set_texture2d_id);
	ring_vm_funcregister("raylib_get_texture2d_width",ring_raylib_get_texture2d_width);
	ring_vm_funcregister("raylib_set_texture2d_width",ring_raylib_set_texture2d_width);
	ring_vm_funcregister("raylib_get_texture2d_height",ring_raylib_get_texture2d_height);
	ring_vm_funcregister("raylib_set_texture2d_height",ring_raylib_set_texture2d_height);
	ring_vm_funcregister("raylib_get_texture2d_mipmaps",ring_raylib_get_texture2d_mipmaps);
	ring_vm_funcregister("raylib_set_texture2d_mipmaps",ring_raylib_set_texture2d_mipmaps);
	ring_vm_funcregister("raylib_get_texture2d_format",ring_raylib_get_texture2d_format);
	ring_vm_funcregister("raylib_set_texture2d_format",ring_raylib_set_texture2d_format);
	ring_vm_funcregister("raylib_new_texture",ring_raylib_new_texture);
	ring_vm_funcregister("raylib_new_managed_texture",ring_raylib_new_managed_texture);
	ring_vm_funcregister("raylib_destroy_texture",ring_raylib_destroy_texture);
	ring_vm_funcregister("raylib_get_texture_id",ring_raylib_get_texture_id);
	ring_vm_funcregister("raylib_set_texture_id",ring_raylib_set_texture_id);
	ring_vm_funcregister("raylib_get_texture_width",ring_raylib_get_texture_width);
	ring_vm_funcregister("raylib_set_texture_width",ring_raylib_set_texture_width);
	ring_vm_funcregister("raylib_get_texture_height",ring_raylib_get_texture_height);
	ring_vm_funcregister("raylib_set_texture_height",ring_raylib_set_texture_height);
	ring_vm_funcregister("raylib_get_texture_mipmaps",ring_raylib_get_texture_mipmaps);
	ring_vm_funcregister("raylib_set_texture_mipmaps",ring_raylib_set_texture_mipmaps);
	ring_vm_funcregister("raylib_get_texture_format",ring_raylib_get_texture_format);
	ring_vm_funcregister("raylib_set_texture_format",ring_raylib_set_texture_format);
	ring_vm_funcregister("raylib_new_rendertexture2d",ring_raylib_new_rendertexture2d);
	ring_vm_funcregister("raylib_new_managed_rendertexture2d",ring_raylib_new_managed_rendertexture2d);
	ring_vm_funcregister("raylib_destroy_rendertexture2d",ring_raylib_destroy_rendertexture2d);
	ring_vm_funcregister("raylib_get_rendertexture2d_id",ring_raylib_get_rendertexture2d_id);
	ring_vm_funcregister("raylib_set_rendertexture2d_id",ring_raylib_set_rendertexture2d_id);
	ring_vm_funcregister("raylib_get_rendertexture2d_texture_id",ring_raylib_get_rendertexture2d_texture_id);
	ring_vm_funcregister("raylib_set_rendertexture2d_texture_id",ring_raylib_set_rendertexture2d_texture_id);
	ring_vm_funcregister("raylib_get_rendertexture2d_texture_width",ring_raylib_get_rendertexture2d_texture_width);
	ring_vm_funcregister("raylib_set_rendertexture2d_texture_width",ring_raylib_set_rendertexture2d_texture_width);
	ring_vm_funcregister("raylib_get_rendertexture2d_texture_height",ring_raylib_get_rendertexture2d_texture_height);
	ring_vm_funcregister("raylib_set_rendertexture2d_texture_height",ring_raylib_set_rendertexture2d_texture_height);
	ring_vm_funcregister("raylib_get_rendertexture2d_texture_mipmaps",ring_raylib_get_rendertexture2d_texture_mipmaps);
	ring_vm_funcregister("raylib_set_rendertexture2d_texture_mipmaps",ring_raylib_set_rendertexture2d_texture_mipmaps);
	ring_vm_funcregister("raylib_get_rendertexture2d_texture_format",ring_raylib_get_rendertexture2d_texture_format);
	ring_vm_funcregister("raylib_set_rendertexture2d_texture_format",ring_raylib_set_rendertexture2d_texture_format);
	ring_vm_funcregister("raylib_get_rendertexture2d_depth_id",ring_raylib_get_rendertexture2d_depth_id);
	ring_vm_funcregister("raylib_set_rendertexture2d_depth_id",ring_raylib_set_rendertexture2d_depth_id);
	ring_vm_funcregister("raylib_get_rendertexture2d_depth_width",ring_raylib_get_rendertexture2d_depth_width);
	ring_vm_funcregister("raylib_set_rendertexture2d_depth_width",ring_raylib_set_rendertexture2d_depth_width);
	ring_vm_funcregister("raylib_get_rendertexture2d_depth_height",ring_raylib_get_rendertexture2d_depth_height);
	ring_vm_funcregister("raylib_set_rendertexture2d_depth_height",ring_raylib_set_rendertexture2d_depth_height);
	ring_vm_funcregister("raylib_get_rendertexture2d_depth_mipmaps",ring_raylib_get_rendertexture2d_depth_mipmaps);
	ring_vm_funcregister("raylib_set_rendertexture2d_depth_mipmaps",ring_raylib_set_rendertexture2d_depth_mipmaps);
	ring_vm_funcregister("raylib_get_rendertexture2d_depth_format",ring_raylib_get_rendertexture2d_depth_format);
	ring_vm_funcregister("raylib_set_rendertexture2d_depth_format",ring_raylib_set_rendertexture2d_depth_format);
	ring_vm_funcregister("raylib_get_rendertexture2d_depthtexture",ring_raylib_get_rendertexture2d_depthTexture);
	ring_vm_funcregister("raylib_set_rendertexture2d_depthtexture",ring_raylib_set_rendertexture2d_depthTexture);
	ring_vm_funcregister("raylib_new_rendertexture",ring_raylib_new_rendertexture);
	ring_vm_funcregister("raylib_new_managed_rendertexture",ring_raylib_new_managed_rendertexture);
	ring_vm_funcregister("raylib_destroy_rendertexture",ring_raylib_destroy_rendertexture);
	ring_vm_funcregister("raylib_get_rendertexture_id",ring_raylib_get_rendertexture_id);
	ring_vm_funcregister("raylib_set_rendertexture_id",ring_raylib_set_rendertexture_id);
	ring_vm_funcregister("raylib_get_rendertexture_texture_id",ring_raylib_get_rendertexture_texture_id);
	ring_vm_funcregister("raylib_set_rendertexture_texture_id",ring_raylib_set_rendertexture_texture_id);
	ring_vm_funcregister("raylib_get_rendertexture_texture_width",ring_raylib_get_rendertexture_texture_width);
	ring_vm_funcregister("raylib_set_rendertexture_texture_width",ring_raylib_set_rendertexture_texture_width);
	ring_vm_funcregister("raylib_get_rendertexture_texture_height",ring_raylib_get_rendertexture_texture_height);
	ring_vm_funcregister("raylib_set_rendertexture_texture_height",ring_raylib_set_rendertexture_texture_height);
	ring_vm_funcregister("raylib_get_rendertexture_texture_mipmaps",ring_raylib_get_rendertexture_texture_mipmaps);
	ring_vm_funcregister("raylib_set_rendertexture_texture_mipmaps",ring_raylib_set_rendertexture_texture_mipmaps);
	ring_vm_funcregister("raylib_get_rendertexture_texture_format",ring_raylib_get_rendertexture_texture_format);
	ring_vm_funcregister("raylib_set_rendertexture_texture_format",ring_raylib_set_rendertexture_texture_format);
	ring_vm_funcregister("raylib_get_rendertexture_depth_id",ring_raylib_get_rendertexture_depth_id);
	ring_vm_funcregister("raylib_set_rendertexture_depth_id",ring_raylib_set_rendertexture_depth_id);
	ring_vm_funcregister("raylib_get_rendertexture_depth_width",ring_raylib_get_rendertexture_depth_width);
	ring_vm_funcregister("raylib_set_rendertexture_depth_width",ring_raylib_set_rendertexture_depth_width);
	ring_vm_funcregister("raylib_get_rendertexture_depth_height",ring_raylib_get_rendertexture_depth_height);
	ring_vm_funcregister("raylib_set_rendertexture_depth_height",ring_raylib_set_rendertexture_depth_height);
	ring_vm_funcregister("raylib_get_rendertexture_depth_mipmaps",ring_raylib_get_rendertexture_depth_mipmaps);
	ring_vm_funcregister("raylib_set_rendertexture_depth_mipmaps",ring_raylib_set_rendertexture_depth_mipmaps);
	ring_vm_funcregister("raylib_get_rendertexture_depth_format",ring_raylib_get_rendertexture_depth_format);
	ring_vm_funcregister("raylib_set_rendertexture_depth_format",ring_raylib_set_rendertexture_depth_format);
	ring_vm_funcregister("raylib_get_rendertexture_depthtexture",ring_raylib_get_rendertexture_depthTexture);
	ring_vm_funcregister("raylib_set_rendertexture_depthtexture",ring_raylib_set_rendertexture_depthTexture);
	ring_vm_funcregister("raylib_new_npatchinfo",ring_raylib_new_npatchinfo);
	ring_vm_funcregister("raylib_new_managed_npatchinfo",ring_raylib_new_managed_npatchinfo);
	ring_vm_funcregister("raylib_destroy_npatchinfo",ring_raylib_destroy_npatchinfo);
	ring_vm_funcregister("raylib_get_npatchinfo_sourcerec_x",ring_raylib_get_npatchinfo_sourceRec_x);
	ring_vm_funcregister("raylib_set_npatchinfo_sourcerec_x",ring_raylib_set_npatchinfo_sourceRec_x);
	ring_vm_funcregister("raylib_get_npatchinfo_sourcerec_y",ring_raylib_get_npatchinfo_sourceRec_y);
	ring_vm_funcregister("raylib_set_npatchinfo_sourcerec_y",ring_raylib_set_npatchinfo_sourceRec_y);
	ring_vm_funcregister("raylib_get_npatchinfo_sourcerec_width",ring_raylib_get_npatchinfo_sourceRec_width);
	ring_vm_funcregister("raylib_set_npatchinfo_sourcerec_width",ring_raylib_set_npatchinfo_sourceRec_width);
	ring_vm_funcregister("raylib_get_npatchinfo_sourcerec_height",ring_raylib_get_npatchinfo_sourceRec_height);
	ring_vm_funcregister("raylib_set_npatchinfo_sourcerec_height",ring_raylib_set_npatchinfo_sourceRec_height);
	ring_vm_funcregister("raylib_get_npatchinfo_left",ring_raylib_get_npatchinfo_left);
	ring_vm_funcregister("raylib_set_npatchinfo_left",ring_raylib_set_npatchinfo_left);
	ring_vm_funcregister("raylib_get_npatchinfo_top",ring_raylib_get_npatchinfo_top);
	ring_vm_funcregister("raylib_set_npatchinfo_top",ring_raylib_set_npatchinfo_top);
	ring_vm_funcregister("raylib_get_npatchinfo_right",ring_raylib_get_npatchinfo_right);
	ring_vm_funcregister("raylib_set_npatchinfo_right",ring_raylib_set_npatchinfo_right);
	ring_vm_funcregister("raylib_get_npatchinfo_bottom",ring_raylib_get_npatchinfo_bottom);
	ring_vm_funcregister("raylib_set_npatchinfo_bottom",ring_raylib_set_npatchinfo_bottom);
	ring_vm_funcregister("raylib_get_npatchinfo_type",ring_raylib_get_npatchinfo_type);
	ring_vm_funcregister("raylib_set_npatchinfo_type",ring_raylib_set_npatchinfo_type);
	ring_vm_funcregister("raylib_new_charinfo",ring_raylib_new_charinfo);
	ring_vm_funcregister("raylib_new_managed_charinfo",ring_raylib_new_managed_charinfo);
	ring_vm_funcregister("raylib_destroy_charinfo",ring_raylib_destroy_charinfo);
	ring_vm_funcregister("raylib_get_charinfo_value",ring_raylib_get_charinfo_value);
	ring_vm_funcregister("raylib_set_charinfo_value",ring_raylib_set_charinfo_value);
	ring_vm_funcregister("raylib_get_charinfo_rec_x",ring_raylib_get_charinfo_rec_x);
	ring_vm_funcregister("raylib_set_charinfo_rec_x",ring_raylib_set_charinfo_rec_x);
	ring_vm_funcregister("raylib_get_charinfo_rec_y",ring_raylib_get_charinfo_rec_y);
	ring_vm_funcregister("raylib_set_charinfo_rec_y",ring_raylib_set_charinfo_rec_y);
	ring_vm_funcregister("raylib_get_charinfo_rec_width",ring_raylib_get_charinfo_rec_width);
	ring_vm_funcregister("raylib_set_charinfo_rec_width",ring_raylib_set_charinfo_rec_width);
	ring_vm_funcregister("raylib_get_charinfo_rec_height",ring_raylib_get_charinfo_rec_height);
	ring_vm_funcregister("raylib_set_charinfo_rec_height",ring_raylib_set_charinfo_rec_height);
	ring_vm_funcregister("raylib_get_charinfo_offsetx",ring_raylib_get_charinfo_offsetX);
	ring_vm_funcregister("raylib_set_charinfo_offsetx",ring_raylib_set_charinfo_offsetX);
	ring_vm_funcregister("raylib_get_charinfo_offsety",ring_raylib_get_charinfo_offsetY);
	ring_vm_funcregister("raylib_set_charinfo_offsety",ring_raylib_set_charinfo_offsetY);
	ring_vm_funcregister("raylib_get_charinfo_advancex",ring_raylib_get_charinfo_advanceX);
	ring_vm_funcregister("raylib_set_charinfo_advancex",ring_raylib_set_charinfo_advanceX);
	ring_vm_funcregister("raylib_get_charinfo_data",ring_raylib_get_charinfo_data);
	ring_vm_funcregister("raylib_set_charinfo_data",ring_raylib_set_charinfo_data);
	ring_vm_funcregister("raylib_new_font",ring_raylib_new_font);
	ring_vm_funcregister("raylib_new_managed_font",ring_raylib_new_managed_font);
	ring_vm_funcregister("raylib_destroy_font",ring_raylib_destroy_font);
	ring_vm_funcregister("raylib_get_font_texture_id",ring_raylib_get_font_texture_id);
	ring_vm_funcregister("raylib_set_font_texture_id",ring_raylib_set_font_texture_id);
	ring_vm_funcregister("raylib_get_font_texture_width",ring_raylib_get_font_texture_width);
	ring_vm_funcregister("raylib_set_font_texture_width",ring_raylib_set_font_texture_width);
	ring_vm_funcregister("raylib_get_font_texture_height",ring_raylib_get_font_texture_height);
	ring_vm_funcregister("raylib_set_font_texture_height",ring_raylib_set_font_texture_height);
	ring_vm_funcregister("raylib_get_font_texture_mipmaps",ring_raylib_get_font_texture_mipmaps);
	ring_vm_funcregister("raylib_set_font_texture_mipmaps",ring_raylib_set_font_texture_mipmaps);
	ring_vm_funcregister("raylib_get_font_texture_format",ring_raylib_get_font_texture_format);
	ring_vm_funcregister("raylib_set_font_texture_format",ring_raylib_set_font_texture_format);
	ring_vm_funcregister("raylib_get_font_basesize",ring_raylib_get_font_baseSize);
	ring_vm_funcregister("raylib_set_font_basesize",ring_raylib_set_font_baseSize);
	ring_vm_funcregister("raylib_get_font_charscount",ring_raylib_get_font_charsCount);
	ring_vm_funcregister("raylib_set_font_charscount",ring_raylib_set_font_charsCount);
	ring_vm_funcregister("raylib_get_font_chars",ring_raylib_get_font_chars);
	ring_vm_funcregister("raylib_set_font_chars",ring_raylib_set_font_chars);
	ring_vm_funcregister("raylib_new_spritefont",ring_raylib_new_spritefont);
	ring_vm_funcregister("raylib_new_managed_spritefont",ring_raylib_new_managed_spritefont);
	ring_vm_funcregister("raylib_destroy_spritefont",ring_raylib_destroy_spritefont);
	ring_vm_funcregister("raylib_get_spritefont_texture_id",ring_raylib_get_spritefont_texture_id);
	ring_vm_funcregister("raylib_set_spritefont_texture_id",ring_raylib_set_spritefont_texture_id);
	ring_vm_funcregister("raylib_get_spritefont_texture_width",ring_raylib_get_spritefont_texture_width);
	ring_vm_funcregister("raylib_set_spritefont_texture_width",ring_raylib_set_spritefont_texture_width);
	ring_vm_funcregister("raylib_get_spritefont_texture_height",ring_raylib_get_spritefont_texture_height);
	ring_vm_funcregister("raylib_set_spritefont_texture_height",ring_raylib_set_spritefont_texture_height);
	ring_vm_funcregister("raylib_get_spritefont_texture_mipmaps",ring_raylib_get_spritefont_texture_mipmaps);
	ring_vm_funcregister("raylib_set_spritefont_texture_mipmaps",ring_raylib_set_spritefont_texture_mipmaps);
	ring_vm_funcregister("raylib_get_spritefont_texture_format",ring_raylib_get_spritefont_texture_format);
	ring_vm_funcregister("raylib_set_spritefont_texture_format",ring_raylib_set_spritefont_texture_format);
	ring_vm_funcregister("raylib_get_spritefont_basesize",ring_raylib_get_spritefont_baseSize);
	ring_vm_funcregister("raylib_set_spritefont_basesize",ring_raylib_set_spritefont_baseSize);
	ring_vm_funcregister("raylib_get_spritefont_charscount",ring_raylib_get_spritefont_charsCount);
	ring_vm_funcregister("raylib_set_spritefont_charscount",ring_raylib_set_spritefont_charsCount);
	ring_vm_funcregister("raylib_get_spritefont_chars",ring_raylib_get_spritefont_chars);
	ring_vm_funcregister("raylib_set_spritefont_chars",ring_raylib_set_spritefont_chars);
	ring_vm_funcregister("raylib_new_camera3d",ring_raylib_new_camera3d);
	ring_vm_funcregister("raylib_new_managed_camera3d",ring_raylib_new_managed_camera3d);
	ring_vm_funcregister("raylib_destroy_camera3d",ring_raylib_destroy_camera3d);
	ring_vm_funcregister("raylib_get_camera3d_position_x",ring_raylib_get_camera3d_position_x);
	ring_vm_funcregister("raylib_set_camera3d_position_x",ring_raylib_set_camera3d_position_x);
	ring_vm_funcregister("raylib_get_camera3d_position_y",ring_raylib_get_camera3d_position_y);
	ring_vm_funcregister("raylib_set_camera3d_position_y",ring_raylib_set_camera3d_position_y);
	ring_vm_funcregister("raylib_get_camera3d_position_z",ring_raylib_get_camera3d_position_z);
	ring_vm_funcregister("raylib_set_camera3d_position_z",ring_raylib_set_camera3d_position_z);
	ring_vm_funcregister("raylib_get_camera3d_target_x",ring_raylib_get_camera3d_target_x);
	ring_vm_funcregister("raylib_set_camera3d_target_x",ring_raylib_set_camera3d_target_x);
	ring_vm_funcregister("raylib_get_camera3d_target_y",ring_raylib_get_camera3d_target_y);
	ring_vm_funcregister("raylib_set_camera3d_target_y",ring_raylib_set_camera3d_target_y);
	ring_vm_funcregister("raylib_get_camera3d_target_z",ring_raylib_get_camera3d_target_z);
	ring_vm_funcregister("raylib_set_camera3d_target_z",ring_raylib_set_camera3d_target_z);
	ring_vm_funcregister("raylib_get_camera3d_up_x",ring_raylib_get_camera3d_up_x);
	ring_vm_funcregister("raylib_set_camera3d_up_x",ring_raylib_set_camera3d_up_x);
	ring_vm_funcregister("raylib_get_camera3d_up_y",ring_raylib_get_camera3d_up_y);
	ring_vm_funcregister("raylib_set_camera3d_up_y",ring_raylib_set_camera3d_up_y);
	ring_vm_funcregister("raylib_get_camera3d_up_z",ring_raylib_get_camera3d_up_z);
	ring_vm_funcregister("raylib_set_camera3d_up_z",ring_raylib_set_camera3d_up_z);
	ring_vm_funcregister("raylib_get_camera3d_fovy",ring_raylib_get_camera3d_fovy);
	ring_vm_funcregister("raylib_set_camera3d_fovy",ring_raylib_set_camera3d_fovy);
	ring_vm_funcregister("raylib_get_camera3d_type",ring_raylib_get_camera3d_type);
	ring_vm_funcregister("raylib_set_camera3d_type",ring_raylib_set_camera3d_type);
	ring_vm_funcregister("raylib_new_mesh",ring_raylib_new_mesh);
	ring_vm_funcregister("raylib_new_managed_mesh",ring_raylib_new_managed_mesh);
	ring_vm_funcregister("raylib_destroy_mesh",ring_raylib_destroy_mesh);
	ring_vm_funcregister("raylib_get_mesh_vertexcount",ring_raylib_get_mesh_vertexCount);
	ring_vm_funcregister("raylib_set_mesh_vertexcount",ring_raylib_set_mesh_vertexCount);
	ring_vm_funcregister("raylib_get_mesh_trianglecount",ring_raylib_get_mesh_triangleCount);
	ring_vm_funcregister("raylib_set_mesh_trianglecount",ring_raylib_set_mesh_triangleCount);
	ring_vm_funcregister("raylib_get_mesh_vertices",ring_raylib_get_mesh_vertices);
	ring_vm_funcregister("raylib_set_mesh_vertices",ring_raylib_set_mesh_vertices);
	ring_vm_funcregister("raylib_get_mesh_texcoords",ring_raylib_get_mesh_texcoords);
	ring_vm_funcregister("raylib_set_mesh_texcoords",ring_raylib_set_mesh_texcoords);
	ring_vm_funcregister("raylib_get_mesh_texcoords2",ring_raylib_get_mesh_texcoords2);
	ring_vm_funcregister("raylib_set_mesh_texcoords2",ring_raylib_set_mesh_texcoords2);
	ring_vm_funcregister("raylib_get_mesh_normals",ring_raylib_get_mesh_normals);
	ring_vm_funcregister("raylib_set_mesh_normals",ring_raylib_set_mesh_normals);
	ring_vm_funcregister("raylib_get_mesh_tangents",ring_raylib_get_mesh_tangents);
	ring_vm_funcregister("raylib_set_mesh_tangents",ring_raylib_set_mesh_tangents);
	ring_vm_funcregister("raylib_get_mesh_colors",ring_raylib_get_mesh_colors);
	ring_vm_funcregister("raylib_set_mesh_colors",ring_raylib_set_mesh_colors);
	ring_vm_funcregister("raylib_get_mesh_indices",ring_raylib_get_mesh_indices);
	ring_vm_funcregister("raylib_set_mesh_indices",ring_raylib_set_mesh_indices);
	ring_vm_funcregister("raylib_get_mesh_animvertices",ring_raylib_get_mesh_animVertices);
	ring_vm_funcregister("raylib_set_mesh_animvertices",ring_raylib_set_mesh_animVertices);
	ring_vm_funcregister("raylib_get_mesh_animnormals",ring_raylib_get_mesh_animNormals);
	ring_vm_funcregister("raylib_set_mesh_animnormals",ring_raylib_set_mesh_animNormals);
	ring_vm_funcregister("raylib_get_mesh_boneids",ring_raylib_get_mesh_boneIds);
	ring_vm_funcregister("raylib_set_mesh_boneids",ring_raylib_set_mesh_boneIds);
	ring_vm_funcregister("raylib_get_mesh_boneweights",ring_raylib_get_mesh_boneWeights);
	ring_vm_funcregister("raylib_set_mesh_boneweights",ring_raylib_set_mesh_boneWeights);
	ring_vm_funcregister("raylib_get_mesh_vaoid",ring_raylib_get_mesh_vaoId);
	ring_vm_funcregister("raylib_set_mesh_vaoid",ring_raylib_set_mesh_vaoId);
	ring_vm_funcregister("raylib_new_shader",ring_raylib_new_shader);
	ring_vm_funcregister("raylib_new_managed_shader",ring_raylib_new_managed_shader);
	ring_vm_funcregister("raylib_destroy_shader",ring_raylib_destroy_shader);
	ring_vm_funcregister("raylib_get_shader_id",ring_raylib_get_shader_id);
	ring_vm_funcregister("raylib_set_shader_id",ring_raylib_set_shader_id);
	ring_vm_funcregister("raylib_new_materialmap",ring_raylib_new_materialmap);
	ring_vm_funcregister("raylib_new_managed_materialmap",ring_raylib_new_managed_materialmap);
	ring_vm_funcregister("raylib_destroy_materialmap",ring_raylib_destroy_materialmap);
	ring_vm_funcregister("raylib_get_materialmap_texture_id",ring_raylib_get_materialmap_texture_id);
	ring_vm_funcregister("raylib_set_materialmap_texture_id",ring_raylib_set_materialmap_texture_id);
	ring_vm_funcregister("raylib_get_materialmap_texture_width",ring_raylib_get_materialmap_texture_width);
	ring_vm_funcregister("raylib_set_materialmap_texture_width",ring_raylib_set_materialmap_texture_width);
	ring_vm_funcregister("raylib_get_materialmap_texture_height",ring_raylib_get_materialmap_texture_height);
	ring_vm_funcregister("raylib_set_materialmap_texture_height",ring_raylib_set_materialmap_texture_height);
	ring_vm_funcregister("raylib_get_materialmap_texture_mipmaps",ring_raylib_get_materialmap_texture_mipmaps);
	ring_vm_funcregister("raylib_set_materialmap_texture_mipmaps",ring_raylib_set_materialmap_texture_mipmaps);
	ring_vm_funcregister("raylib_get_materialmap_texture_format",ring_raylib_get_materialmap_texture_format);
	ring_vm_funcregister("raylib_set_materialmap_texture_format",ring_raylib_set_materialmap_texture_format);
	ring_vm_funcregister("raylib_get_materialmap_value",ring_raylib_get_materialmap_value);
	ring_vm_funcregister("raylib_set_materialmap_value",ring_raylib_set_materialmap_value);
	ring_vm_funcregister("raylib_new_material",ring_raylib_new_material);
	ring_vm_funcregister("raylib_new_managed_material",ring_raylib_new_managed_material);
	ring_vm_funcregister("raylib_destroy_material",ring_raylib_destroy_material);
	ring_vm_funcregister("raylib_get_material_shader_id",ring_raylib_get_material_shader_id);
	ring_vm_funcregister("raylib_set_material_shader_id",ring_raylib_set_material_shader_id);
	ring_vm_funcregister("raylib_get_material_params",ring_raylib_get_material_params);
	ring_vm_funcregister("raylib_set_material_params",ring_raylib_set_material_params);
	ring_vm_funcregister("raylib_new_transform",ring_raylib_new_transform);
	ring_vm_funcregister("raylib_new_managed_transform",ring_raylib_new_managed_transform);
	ring_vm_funcregister("raylib_destroy_transform",ring_raylib_destroy_transform);
	ring_vm_funcregister("raylib_get_transform_translation_x",ring_raylib_get_transform_translation_x);
	ring_vm_funcregister("raylib_set_transform_translation_x",ring_raylib_set_transform_translation_x);
	ring_vm_funcregister("raylib_get_transform_translation_y",ring_raylib_get_transform_translation_y);
	ring_vm_funcregister("raylib_set_transform_translation_y",ring_raylib_set_transform_translation_y);
	ring_vm_funcregister("raylib_get_transform_translation_z",ring_raylib_get_transform_translation_z);
	ring_vm_funcregister("raylib_set_transform_translation_z",ring_raylib_set_transform_translation_z);
	ring_vm_funcregister("raylib_get_transform_rotation_x",ring_raylib_get_transform_rotation_x);
	ring_vm_funcregister("raylib_set_transform_rotation_x",ring_raylib_set_transform_rotation_x);
	ring_vm_funcregister("raylib_get_transform_rotation_y",ring_raylib_get_transform_rotation_y);
	ring_vm_funcregister("raylib_set_transform_rotation_y",ring_raylib_set_transform_rotation_y);
	ring_vm_funcregister("raylib_get_transform_rotation_z",ring_raylib_get_transform_rotation_z);
	ring_vm_funcregister("raylib_set_transform_rotation_z",ring_raylib_set_transform_rotation_z);
	ring_vm_funcregister("raylib_get_transform_rotation_w",ring_raylib_get_transform_rotation_w);
	ring_vm_funcregister("raylib_set_transform_rotation_w",ring_raylib_set_transform_rotation_w);
	ring_vm_funcregister("raylib_get_transform_scale_x",ring_raylib_get_transform_scale_x);
	ring_vm_funcregister("raylib_set_transform_scale_x",ring_raylib_set_transform_scale_x);
	ring_vm_funcregister("raylib_get_transform_scale_y",ring_raylib_get_transform_scale_y);
	ring_vm_funcregister("raylib_set_transform_scale_y",ring_raylib_set_transform_scale_y);
	ring_vm_funcregister("raylib_get_transform_scale_z",ring_raylib_get_transform_scale_z);
	ring_vm_funcregister("raylib_set_transform_scale_z",ring_raylib_set_transform_scale_z);
	ring_vm_funcregister("raylib_new_boneinfo",ring_raylib_new_boneinfo);
	ring_vm_funcregister("raylib_new_managed_boneinfo",ring_raylib_new_managed_boneinfo);
	ring_vm_funcregister("raylib_destroy_boneinfo",ring_raylib_destroy_boneinfo);
	ring_vm_funcregister("raylib_get_boneinfo_parent",ring_raylib_get_boneinfo_parent);
	ring_vm_funcregister("raylib_set_boneinfo_parent",ring_raylib_set_boneinfo_parent);
	ring_vm_funcregister("raylib_new_model",ring_raylib_new_model);
	ring_vm_funcregister("raylib_new_managed_model",ring_raylib_new_managed_model);
	ring_vm_funcregister("raylib_destroy_model",ring_raylib_destroy_model);
	ring_vm_funcregister("raylib_get_model_transform_m0",ring_raylib_get_model_transform_m0);
	ring_vm_funcregister("raylib_set_model_transform_m0",ring_raylib_set_model_transform_m0);
	ring_vm_funcregister("raylib_get_model_transform_m1",ring_raylib_get_model_transform_m1);
	ring_vm_funcregister("raylib_set_model_transform_m1",ring_raylib_set_model_transform_m1);
	ring_vm_funcregister("raylib_get_model_transform_m2",ring_raylib_get_model_transform_m2);
	ring_vm_funcregister("raylib_set_model_transform_m2",ring_raylib_set_model_transform_m2);
	ring_vm_funcregister("raylib_get_model_transform_m3",ring_raylib_get_model_transform_m3);
	ring_vm_funcregister("raylib_set_model_transform_m3",ring_raylib_set_model_transform_m3);
	ring_vm_funcregister("raylib_get_model_transform_m4",ring_raylib_get_model_transform_m4);
	ring_vm_funcregister("raylib_set_model_transform_m4",ring_raylib_set_model_transform_m4);
	ring_vm_funcregister("raylib_get_model_transform_m5",ring_raylib_get_model_transform_m5);
	ring_vm_funcregister("raylib_set_model_transform_m5",ring_raylib_set_model_transform_m5);
	ring_vm_funcregister("raylib_get_model_transform_m6",ring_raylib_get_model_transform_m6);
	ring_vm_funcregister("raylib_set_model_transform_m6",ring_raylib_set_model_transform_m6);
	ring_vm_funcregister("raylib_get_model_transform_m7",ring_raylib_get_model_transform_m7);
	ring_vm_funcregister("raylib_set_model_transform_m7",ring_raylib_set_model_transform_m7);
	ring_vm_funcregister("raylib_get_model_transform_m8",ring_raylib_get_model_transform_m8);
	ring_vm_funcregister("raylib_set_model_transform_m8",ring_raylib_set_model_transform_m8);
	ring_vm_funcregister("raylib_get_model_transform_m9",ring_raylib_get_model_transform_m9);
	ring_vm_funcregister("raylib_set_model_transform_m9",ring_raylib_set_model_transform_m9);
	ring_vm_funcregister("raylib_get_model_transform_m10",ring_raylib_get_model_transform_m10);
	ring_vm_funcregister("raylib_set_model_transform_m10",ring_raylib_set_model_transform_m10);
	ring_vm_funcregister("raylib_get_model_transform_m11",ring_raylib_get_model_transform_m11);
	ring_vm_funcregister("raylib_set_model_transform_m11",ring_raylib_set_model_transform_m11);
	ring_vm_funcregister("raylib_get_model_transform_m12",ring_raylib_get_model_transform_m12);
	ring_vm_funcregister("raylib_set_model_transform_m12",ring_raylib_set_model_transform_m12);
	ring_vm_funcregister("raylib_get_model_transform_m13",ring_raylib_get_model_transform_m13);
	ring_vm_funcregister("raylib_set_model_transform_m13",ring_raylib_set_model_transform_m13);
	ring_vm_funcregister("raylib_get_model_transform_m14",ring_raylib_get_model_transform_m14);
	ring_vm_funcregister("raylib_set_model_transform_m14",ring_raylib_set_model_transform_m14);
	ring_vm_funcregister("raylib_get_model_transform_m15",ring_raylib_get_model_transform_m15);
	ring_vm_funcregister("raylib_set_model_transform_m15",ring_raylib_set_model_transform_m15);
	ring_vm_funcregister("raylib_get_model_meshcount",ring_raylib_get_model_meshCount);
	ring_vm_funcregister("raylib_set_model_meshcount",ring_raylib_set_model_meshCount);
	ring_vm_funcregister("raylib_get_model_meshes",ring_raylib_get_model_meshes);
	ring_vm_funcregister("raylib_set_model_meshes",ring_raylib_set_model_meshes);
	ring_vm_funcregister("raylib_get_model_materialcount",ring_raylib_get_model_materialCount);
	ring_vm_funcregister("raylib_set_model_materialcount",ring_raylib_set_model_materialCount);
	ring_vm_funcregister("raylib_get_model_materials",ring_raylib_get_model_materials);
	ring_vm_funcregister("raylib_set_model_materials",ring_raylib_set_model_materials);
	ring_vm_funcregister("raylib_get_model_meshmaterial",ring_raylib_get_model_meshMaterial);
	ring_vm_funcregister("raylib_set_model_meshmaterial",ring_raylib_set_model_meshMaterial);
	ring_vm_funcregister("raylib_get_model_bonecount",ring_raylib_get_model_boneCount);
	ring_vm_funcregister("raylib_set_model_bonecount",ring_raylib_set_model_boneCount);
	ring_vm_funcregister("raylib_get_model_bones",ring_raylib_get_model_bones);
	ring_vm_funcregister("raylib_set_model_bones",ring_raylib_set_model_bones);
	ring_vm_funcregister("raylib_get_model_bindpose",ring_raylib_get_model_bindPose);
	ring_vm_funcregister("raylib_set_model_bindpose",ring_raylib_set_model_bindPose);
	ring_vm_funcregister("raylib_new_modelanimation",ring_raylib_new_modelanimation);
	ring_vm_funcregister("raylib_new_managed_modelanimation",ring_raylib_new_managed_modelanimation);
	ring_vm_funcregister("raylib_destroy_modelanimation",ring_raylib_destroy_modelanimation);
	ring_vm_funcregister("raylib_get_modelanimation_bonecount",ring_raylib_get_modelanimation_boneCount);
	ring_vm_funcregister("raylib_set_modelanimation_bonecount",ring_raylib_set_modelanimation_boneCount);
	ring_vm_funcregister("raylib_get_modelanimation_bones",ring_raylib_get_modelanimation_bones);
	ring_vm_funcregister("raylib_set_modelanimation_bones",ring_raylib_set_modelanimation_bones);
	ring_vm_funcregister("raylib_get_modelanimation_framecount",ring_raylib_get_modelanimation_frameCount);
	ring_vm_funcregister("raylib_set_modelanimation_framecount",ring_raylib_set_modelanimation_frameCount);
	ring_vm_funcregister("raylib_new_ray",ring_raylib_new_ray);
	ring_vm_funcregister("raylib_new_managed_ray",ring_raylib_new_managed_ray);
	ring_vm_funcregister("raylib_destroy_ray",ring_raylib_destroy_ray);
	ring_vm_funcregister("raylib_get_ray_position_x",ring_raylib_get_ray_position_x);
	ring_vm_funcregister("raylib_set_ray_position_x",ring_raylib_set_ray_position_x);
	ring_vm_funcregister("raylib_get_ray_position_y",ring_raylib_get_ray_position_y);
	ring_vm_funcregister("raylib_set_ray_position_y",ring_raylib_set_ray_position_y);
	ring_vm_funcregister("raylib_get_ray_position_z",ring_raylib_get_ray_position_z);
	ring_vm_funcregister("raylib_set_ray_position_z",ring_raylib_set_ray_position_z);
	ring_vm_funcregister("raylib_get_ray_direction_x",ring_raylib_get_ray_direction_x);
	ring_vm_funcregister("raylib_set_ray_direction_x",ring_raylib_set_ray_direction_x);
	ring_vm_funcregister("raylib_get_ray_direction_y",ring_raylib_get_ray_direction_y);
	ring_vm_funcregister("raylib_set_ray_direction_y",ring_raylib_set_ray_direction_y);
	ring_vm_funcregister("raylib_get_ray_direction_z",ring_raylib_get_ray_direction_z);
	ring_vm_funcregister("raylib_set_ray_direction_z",ring_raylib_set_ray_direction_z);
	ring_vm_funcregister("raylib_new_rayhitinfo",ring_raylib_new_rayhitinfo);
	ring_vm_funcregister("raylib_new_managed_rayhitinfo",ring_raylib_new_managed_rayhitinfo);
	ring_vm_funcregister("raylib_destroy_rayhitinfo",ring_raylib_destroy_rayhitinfo);
	ring_vm_funcregister("raylib_get_rayhitinfo_hit",ring_raylib_get_rayhitinfo_hit);
	ring_vm_funcregister("raylib_set_rayhitinfo_hit",ring_raylib_set_rayhitinfo_hit);
	ring_vm_funcregister("raylib_get_rayhitinfo_distance",ring_raylib_get_rayhitinfo_distance);
	ring_vm_funcregister("raylib_set_rayhitinfo_distance",ring_raylib_set_rayhitinfo_distance);
	ring_vm_funcregister("raylib_get_rayhitinfo_position_x",ring_raylib_get_rayhitinfo_position_x);
	ring_vm_funcregister("raylib_set_rayhitinfo_position_x",ring_raylib_set_rayhitinfo_position_x);
	ring_vm_funcregister("raylib_get_rayhitinfo_position_y",ring_raylib_get_rayhitinfo_position_y);
	ring_vm_funcregister("raylib_set_rayhitinfo_position_y",ring_raylib_set_rayhitinfo_position_y);
	ring_vm_funcregister("raylib_get_rayhitinfo_position_z",ring_raylib_get_rayhitinfo_position_z);
	ring_vm_funcregister("raylib_set_rayhitinfo_position_z",ring_raylib_set_rayhitinfo_position_z);
	ring_vm_funcregister("raylib_get_rayhitinfo_normal_x",ring_raylib_get_rayhitinfo_normal_x);
	ring_vm_funcregister("raylib_set_rayhitinfo_normal_x",ring_raylib_set_rayhitinfo_normal_x);
	ring_vm_funcregister("raylib_get_rayhitinfo_normal_y",ring_raylib_get_rayhitinfo_normal_y);
	ring_vm_funcregister("raylib_set_rayhitinfo_normal_y",ring_raylib_set_rayhitinfo_normal_y);
	ring_vm_funcregister("raylib_get_rayhitinfo_normal_z",ring_raylib_get_rayhitinfo_normal_z);
	ring_vm_funcregister("raylib_set_rayhitinfo_normal_z",ring_raylib_set_rayhitinfo_normal_z);
	ring_vm_funcregister("raylib_new_boundingbox",ring_raylib_new_boundingbox);
	ring_vm_funcregister("raylib_new_managed_boundingbox",ring_raylib_new_managed_boundingbox);
	ring_vm_funcregister("raylib_destroy_boundingbox",ring_raylib_destroy_boundingbox);
	ring_vm_funcregister("raylib_get_boundingbox_min_x",ring_raylib_get_boundingbox_min_x);
	ring_vm_funcregister("raylib_set_boundingbox_min_x",ring_raylib_set_boundingbox_min_x);
	ring_vm_funcregister("raylib_get_boundingbox_min_y",ring_raylib_get_boundingbox_min_y);
	ring_vm_funcregister("raylib_set_boundingbox_min_y",ring_raylib_set_boundingbox_min_y);
	ring_vm_funcregister("raylib_get_boundingbox_min_z",ring_raylib_get_boundingbox_min_z);
	ring_vm_funcregister("raylib_set_boundingbox_min_z",ring_raylib_set_boundingbox_min_z);
	ring_vm_funcregister("raylib_get_boundingbox_max_x",ring_raylib_get_boundingbox_max_x);
	ring_vm_funcregister("raylib_set_boundingbox_max_x",ring_raylib_set_boundingbox_max_x);
	ring_vm_funcregister("raylib_get_boundingbox_max_y",ring_raylib_get_boundingbox_max_y);
	ring_vm_funcregister("raylib_set_boundingbox_max_y",ring_raylib_set_boundingbox_max_y);
	ring_vm_funcregister("raylib_get_boundingbox_max_z",ring_raylib_get_boundingbox_max_z);
	ring_vm_funcregister("raylib_set_boundingbox_max_z",ring_raylib_set_boundingbox_max_z);
	ring_vm_funcregister("raylib_new_wave",ring_raylib_new_wave);
	ring_vm_funcregister("raylib_new_managed_wave",ring_raylib_new_managed_wave);
	ring_vm_funcregister("raylib_destroy_wave",ring_raylib_destroy_wave);
	ring_vm_funcregister("raylib_get_wave_samplecount",ring_raylib_get_wave_sampleCount);
	ring_vm_funcregister("raylib_set_wave_samplecount",ring_raylib_set_wave_sampleCount);
	ring_vm_funcregister("raylib_get_wave_samplerate",ring_raylib_get_wave_sampleRate);
	ring_vm_funcregister("raylib_set_wave_samplerate",ring_raylib_set_wave_sampleRate);
	ring_vm_funcregister("raylib_get_wave_samplesize",ring_raylib_get_wave_sampleSize);
	ring_vm_funcregister("raylib_set_wave_samplesize",ring_raylib_set_wave_sampleSize);
	ring_vm_funcregister("raylib_get_wave_channels",ring_raylib_get_wave_channels);
	ring_vm_funcregister("raylib_set_wave_channels",ring_raylib_set_wave_channels);
	ring_vm_funcregister("raylib_get_wave_data",ring_raylib_get_wave_data);
	ring_vm_funcregister("raylib_set_wave_data",ring_raylib_set_wave_data);
	ring_vm_funcregister("raylib_new_sound",ring_raylib_new_sound);
	ring_vm_funcregister("raylib_new_managed_sound",ring_raylib_new_managed_sound);
	ring_vm_funcregister("raylib_destroy_sound",ring_raylib_destroy_sound);
	ring_vm_funcregister("raylib_get_sound_audiobuffer",ring_raylib_get_sound_audioBuffer);
	ring_vm_funcregister("raylib_set_sound_audiobuffer",ring_raylib_set_sound_audioBuffer);
	ring_vm_funcregister("raylib_get_sound_source",ring_raylib_get_sound_source);
	ring_vm_funcregister("raylib_set_sound_source",ring_raylib_set_sound_source);
	ring_vm_funcregister("raylib_get_sound_buffer",ring_raylib_get_sound_buffer);
	ring_vm_funcregister("raylib_set_sound_buffer",ring_raylib_set_sound_buffer);
	ring_vm_funcregister("raylib_get_sound_format",ring_raylib_get_sound_format);
	ring_vm_funcregister("raylib_set_sound_format",ring_raylib_set_sound_format);
	ring_vm_funcregister("raylib_new_audiostream",ring_raylib_new_audiostream);
	ring_vm_funcregister("raylib_new_managed_audiostream",ring_raylib_new_managed_audiostream);
	ring_vm_funcregister("raylib_destroy_audiostream",ring_raylib_destroy_audiostream);
	ring_vm_funcregister("raylib_get_audiostream_samplerate",ring_raylib_get_audiostream_sampleRate);
	ring_vm_funcregister("raylib_set_audiostream_samplerate",ring_raylib_set_audiostream_sampleRate);
	ring_vm_funcregister("raylib_get_audiostream_samplesize",ring_raylib_get_audiostream_sampleSize);
	ring_vm_funcregister("raylib_set_audiostream_samplesize",ring_raylib_set_audiostream_sampleSize);
	ring_vm_funcregister("raylib_get_audiostream_channels",ring_raylib_get_audiostream_channels);
	ring_vm_funcregister("raylib_set_audiostream_channels",ring_raylib_set_audiostream_channels);
	ring_vm_funcregister("raylib_get_audiostream_audiobuffer",ring_raylib_get_audiostream_audioBuffer);
	ring_vm_funcregister("raylib_set_audiostream_audiobuffer",ring_raylib_set_audiostream_audioBuffer);
	ring_vm_funcregister("raylib_get_audiostream_format",ring_raylib_get_audiostream_format);
	ring_vm_funcregister("raylib_set_audiostream_format",ring_raylib_set_audiostream_format);
	ring_vm_funcregister("raylib_get_audiostream_source",ring_raylib_get_audiostream_source);
	ring_vm_funcregister("raylib_set_audiostream_source",ring_raylib_set_audiostream_source);
	ring_vm_funcregister("raylib_new_vrdeviceinfo",ring_raylib_new_vrdeviceinfo);
	ring_vm_funcregister("raylib_new_managed_vrdeviceinfo",ring_raylib_new_managed_vrdeviceinfo);
	ring_vm_funcregister("raylib_destroy_vrdeviceinfo",ring_raylib_destroy_vrdeviceinfo);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_hresolution",ring_raylib_get_vrdeviceinfo_hResolution);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_hresolution",ring_raylib_set_vrdeviceinfo_hResolution);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_vresolution",ring_raylib_get_vrdeviceinfo_vResolution);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_vresolution",ring_raylib_set_vrdeviceinfo_vResolution);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_hscreensize",ring_raylib_get_vrdeviceinfo_hScreenSize);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_hscreensize",ring_raylib_set_vrdeviceinfo_hScreenSize);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_vscreensize",ring_raylib_get_vrdeviceinfo_vScreenSize);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_vscreensize",ring_raylib_set_vrdeviceinfo_vScreenSize);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_vscreencenter",ring_raylib_get_vrdeviceinfo_vScreenCenter);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_vscreencenter",ring_raylib_set_vrdeviceinfo_vScreenCenter);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_eyetoscreendistance",ring_raylib_get_vrdeviceinfo_eyeToScreenDistance);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_eyetoscreendistance",ring_raylib_set_vrdeviceinfo_eyeToScreenDistance);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_lensseparationdistance",ring_raylib_get_vrdeviceinfo_lensSeparationDistance);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_lensseparationdistance",ring_raylib_set_vrdeviceinfo_lensSeparationDistance);
	ring_vm_funcregister("raylib_get_vrdeviceinfo_interpupillarydistance",ring_raylib_get_vrdeviceinfo_interpupillaryDistance);
	ring_vm_funcregister("raylib_set_vrdeviceinfo_interpupillarydistance",ring_raylib_set_vrdeviceinfo_interpupillaryDistance);
}
