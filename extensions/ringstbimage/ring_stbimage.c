#include "ring.h"

/* Copyright (c) 2020 Mahmoud Fayed <msfclipper@yahoo.com> */

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
RING_FUNC(ring_get_stbi_default)
{
	RING_API_RETNUMBER(STBI_default);
}

RING_FUNC(ring_get_stbi_grey)
{
	RING_API_RETNUMBER(STBI_grey);
}

RING_FUNC(ring_get_stbi_grey_alpha)
{
	RING_API_RETNUMBER(STBI_grey_alpha);
}

RING_FUNC(ring_get_stbi_rgb)
{
	RING_API_RETNUMBER(STBI_rgb);
}

RING_FUNC(ring_get_stbi_rgb_alpha)
{
	RING_API_RETNUMBER(STBI_rgb_alpha);
}

RING_FUNC(ring_stbi_load_from_memory)
{
	unsigned char *pData;
	int *p1, *p2, *p3 ;
	if ( RING_API_PARACOUNT != 6 ) {
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	p1 = RING_API_GETINTPOINTER(3);
	p2 = RING_API_GETINTPOINTER(4);
	p3 = RING_API_GETINTPOINTER(5);
	pData = stbi_load_from_memory(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),p1,p2,p3, (int ) RING_API_GETNUMBER(6));
	if ( pData == NULL ) {
		RING_API_RETSTRING("") ;
		return ;
	}
	RING_API_RETSTRING2(pData, (*p1) * (*p2) * (*p3));
	stbi_image_free(pData);
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
}

RING_FUNC(ring_stbi_load)
{
	unsigned char *pData;
	int *p1, *p2, *p3 ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	p1 = RING_API_GETINTPOINTER(2);
	p2 = RING_API_GETINTPOINTER(3);
	p3 = RING_API_GETINTPOINTER(4);
	pData = stbi_load(RING_API_GETSTRING(1),p1,p2,p3, (int ) RING_API_GETNUMBER(5));
	if ( pData == NULL ) {
		RING_API_RETSTRING("") ;
		return ;
	}
	RING_API_RETSTRING2(pData, (*p1) * (*p2) * (*p3));
	stbi_image_free(pData);
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}

RING_FUNC(ring_stbi_load_from_file)
{
	unsigned char *pData;
	int *p1, *p2, *p3 ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	p1 = RING_API_GETINTPOINTER(2);
	p2 = RING_API_GETINTPOINTER(3);
	p3 = RING_API_GETINTPOINTER(4);
	pData = stbi_load_from_file((FILE *) RING_API_GETCPOINTER(1,"FILE"),p1,p2,p3, (int ) RING_API_GETNUMBER(5)) ;
	RING_API_RETSTRING2(pData, (*p1) * (*p2) * (*p3));
	stbi_image_free(pData);
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}

RING_FUNC(ring_stbi_bytes2list)
{
	unsigned char *pData;
	List *pList, *pSubList;
	int nIndex,nPoint,nChannel,nPointsCount,nChannelDiff,nDivide;
	VM *pVM;
	if ( RING_API_PARACOUNT < 4 ) {
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
	pData  = (unsigned char *) RING_API_GETCHARPOINTER(1);
	nIndex = 0;
	nPoint = 1;
	nPointsCount = RING_API_GETNUMBER(3)*RING_API_GETNUMBER(2);
	nChannel = (int) RING_API_GETNUMBER(4);
	nChannelDiff = 0;
	if (nChannel > 3)
		nChannelDiff = nChannel - 3;
	nDivide = 0;
	if (RING_API_PARACOUNT > 4)
		if (RING_API_ISNUMBER(5))
			nDivide = (int) RING_API_GETNUMBER(5) ;
	pList = RING_API_NEWLISTUSINGBLOCKS2D(nPointsCount,6);
	pVM = (VM *) pPointer;
	for (int y=1 ; y <= ((int) RING_API_GETNUMBER(3)) ; y++ ) {
		for (int x=1 ; x <= ((int) RING_API_GETNUMBER(2)) ; x++ ) {
			pSubList = ring_list_getlist(pList,nPoint++);
			ring_list_setdouble_gc(pVM->pRingState,pSubList,1,(double) x);
			ring_list_setdouble_gc(pVM->pRingState,pSubList,2,(double) y);
			if (nDivide == 0) {
				ring_list_setdouble_gc(pVM->pRingState,pSubList,3,(double) pData[nIndex++]);
				ring_list_setdouble_gc(pVM->pRingState,pSubList,4,(double) pData[nIndex++]);						ring_list_setdouble_gc(pVM->pRingState,pSubList,5,(double) pData[nIndex++]);
			} else {
				ring_list_setdouble_gc(pVM->pRingState,pSubList,3,( (double) pData[nIndex++] ) / nDivide);
				ring_list_setdouble_gc(pVM->pRingState,pSubList,4,( (double) pData[nIndex++] ) / nDivide);				ring_list_setdouble_gc(pVM->pRingState,pSubList,5,( (double) pData[nIndex++] ) / nDivide);
			}
			ring_list_setdouble_gc(pVM->pRingState,pSubList,6,(double) 1.0);
			nIndex += nChannelDiff;	
		}
	}
	RING_API_RETLIST(pList);
}


RING_FUNC(ring_stbi_load_16_from_memory)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stbi_load_16_from_memory(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5), (int ) RING_API_GETNUMBER(6)),"stbi_us");
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
}


RING_FUNC(ring_stbi_load_16)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stbi_load_16(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4), (int ) RING_API_GETNUMBER(5)),"stbi_us");
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_load_from_file_16)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stbi_load_from_file_16((FILE *) RING_API_GETCPOINTER(1,"FILE"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4), (int ) RING_API_GETNUMBER(5)),"stbi_us");
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_loadf_from_memory)
{
	if ( RING_API_PARACOUNT != 6 ) {
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stbi_loadf_from_memory(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5), (int ) RING_API_GETNUMBER(6)),"float");
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
}


RING_FUNC(ring_stbi_loadf)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stbi_loadf(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4), (int ) RING_API_GETNUMBER(5)),"float");
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_loadf_from_file)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stbi_loadf_from_file((FILE *) RING_API_GETCPOINTER(1,"FILE"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4), (int ) RING_API_GETNUMBER(5)),"float");
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_hdr_to_ldr_gamma)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_hdr_to_ldr_gamma( (float ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_hdr_to_ldr_scale)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_hdr_to_ldr_scale( (float ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_ldr_to_hdr_gamma)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_ldr_to_hdr_gamma( (float ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_ldr_to_hdr_scale)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_ldr_to_hdr_scale( (float ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_is_hdr_from_memory)
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
	RING_API_RETNUMBER(stbi_is_hdr_from_memory(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_stbi_is_hdr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stbi_is_hdr(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_stbi_is_hdr_from_file)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stbi_is_hdr_from_file((FILE *) RING_API_GETCPOINTER(1,"FILE")));
}


RING_FUNC(ring_stbi_failure_reason)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(stbi_failure_reason());
}


RING_FUNC(ring_stbi_info_from_memory)
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stbi_info_from_memory(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5)));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
}


RING_FUNC(ring_stbi_is_16_bit_from_memory)
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
	RING_API_RETNUMBER(stbi_is_16_bit_from_memory(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_stbi_info)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stbi_info(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_info_from_file)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stbi_info_from_file((FILE *) RING_API_GETCPOINTER(1,"FILE"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_is_16_bit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stbi_is_16_bit(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_stbi_is_16_bit_from_file)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stbi_is_16_bit_from_file((FILE *) RING_API_GETCPOINTER(1,"FILE")));
}


RING_FUNC(ring_stbi_set_unpremultiply_on_load)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_set_unpremultiply_on_load( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_convert_iphone_png_to_rgb)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_convert_iphone_png_to_rgb( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_set_flip_vertically_on_load)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_set_flip_vertically_on_load( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_set_flip_vertically_on_load_thread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stbi_set_flip_vertically_on_load_thread( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_stbi_zlib_decode_malloc_guesssize)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(stbi_zlib_decode_malloc_guesssize(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_zlib_decode_malloc_guesssize_headerflag)
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(stbi_zlib_decode_malloc_guesssize_headerflag(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETINTPOINTER(4), (int ) RING_API_GETNUMBER(5)));
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_stbi_zlib_decode_malloc)
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
	RING_API_RETSTRING(stbi_zlib_decode_malloc(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_stbi_zlib_decode_buffer)
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
	RING_API_RETNUMBER(stbi_zlib_decode_buffer(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_stbi_zlib_decode_noheader_malloc)
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
	RING_API_RETSTRING(stbi_zlib_decode_noheader_malloc(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_stbi_zlib_decode_noheader_buffer)
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
	RING_API_RETNUMBER(stbi_zlib_decode_noheader_buffer(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4)));
}

RING_LIBINIT
{
	RING_API_REGISTER("stbi_load_from_memory",ring_stbi_load_from_memory);
	RING_API_REGISTER("stbi_load",ring_stbi_load);
	RING_API_REGISTER("stbi_load_from_file",ring_stbi_load_from_file);
	RING_API_REGISTER("stbi_bytes2list",ring_stbi_bytes2list);
	RING_API_REGISTER("stbi_load_16_from_memory",ring_stbi_load_16_from_memory);
	RING_API_REGISTER("stbi_load_16",ring_stbi_load_16);
	RING_API_REGISTER("stbi_load_from_file_16",ring_stbi_load_from_file_16);
	RING_API_REGISTER("stbi_loadf_from_memory",ring_stbi_loadf_from_memory);
	RING_API_REGISTER("stbi_loadf",ring_stbi_loadf);
	RING_API_REGISTER("stbi_loadf_from_file",ring_stbi_loadf_from_file);
	RING_API_REGISTER("stbi_hdr_to_ldr_gamma",ring_stbi_hdr_to_ldr_gamma);
	RING_API_REGISTER("stbi_hdr_to_ldr_scale",ring_stbi_hdr_to_ldr_scale);
	RING_API_REGISTER("stbi_ldr_to_hdr_gamma",ring_stbi_ldr_to_hdr_gamma);
	RING_API_REGISTER("stbi_ldr_to_hdr_scale",ring_stbi_ldr_to_hdr_scale);
	RING_API_REGISTER("stbi_is_hdr_from_memory",ring_stbi_is_hdr_from_memory);
	RING_API_REGISTER("stbi_is_hdr",ring_stbi_is_hdr);
	RING_API_REGISTER("stbi_is_hdr_from_file",ring_stbi_is_hdr_from_file);
	RING_API_REGISTER("stbi_failure_reason",ring_stbi_failure_reason);
	RING_API_REGISTER("stbi_info_from_memory",ring_stbi_info_from_memory);
	RING_API_REGISTER("stbi_is_16_bit_from_memory",ring_stbi_is_16_bit_from_memory);
	RING_API_REGISTER("stbi_info",ring_stbi_info);
	RING_API_REGISTER("stbi_info_from_file",ring_stbi_info_from_file);
	RING_API_REGISTER("stbi_is_16_bit",ring_stbi_is_16_bit);
	RING_API_REGISTER("stbi_is_16_bit_from_file",ring_stbi_is_16_bit_from_file);
	RING_API_REGISTER("stbi_set_unpremultiply_on_load",ring_stbi_set_unpremultiply_on_load);
	RING_API_REGISTER("stbi_convert_iphone_png_to_rgb",ring_stbi_convert_iphone_png_to_rgb);
	RING_API_REGISTER("stbi_set_flip_vertically_on_load",ring_stbi_set_flip_vertically_on_load);
	RING_API_REGISTER("stbi_set_flip_vertically_on_load_thread",ring_stbi_set_flip_vertically_on_load_thread);
	RING_API_REGISTER("stbi_zlib_decode_malloc_guesssize",ring_stbi_zlib_decode_malloc_guesssize);
	RING_API_REGISTER("stbi_zlib_decode_malloc_guesssize_headerflag",ring_stbi_zlib_decode_malloc_guesssize_headerflag);
	RING_API_REGISTER("stbi_zlib_decode_malloc",ring_stbi_zlib_decode_malloc);
	RING_API_REGISTER("stbi_zlib_decode_buffer",ring_stbi_zlib_decode_buffer);
	RING_API_REGISTER("stbi_zlib_decode_noheader_malloc",ring_stbi_zlib_decode_noheader_malloc);
	RING_API_REGISTER("stbi_zlib_decode_noheader_buffer",ring_stbi_zlib_decode_noheader_buffer);
	RING_API_REGISTER("get_stbi_default",ring_get_stbi_default);
	RING_API_REGISTER("get_stbi_grey",ring_get_stbi_grey);
	RING_API_REGISTER("get_stbi_grey_alpha",ring_get_stbi_grey_alpha);
	RING_API_REGISTER("get_stbi_rgb",ring_get_stbi_rgb);
	RING_API_REGISTER("get_stbi_rgb_alpha",ring_get_stbi_rgb_alpha);
}
