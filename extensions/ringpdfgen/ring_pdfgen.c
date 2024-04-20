#include "ring.h"

#include "lib/pdfgen.h"
#include "lib/pdfgen.c"

RING_FUNC(ring_pdf_create)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pdf_create( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2),(struct pdf_info *) RING_API_GETCPOINTER(3,"struct pdf_info")),"struct pdf_doc");
}


RING_FUNC(ring_pdf_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pdf_destroy((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"));
}


RING_FUNC(ring_pdf_get_err)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETSTRING(pdf_get_err((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_pdf_clear_err)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pdf_clear_err((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"));
}

RING_LIBINIT
{
	RING_API_REGISTER("pdf_create",ring_pdf_create);
	RING_API_REGISTER("pdf_destroy",ring_pdf_destroy);
	RING_API_REGISTER("pdf_get_err",ring_pdf_get_err);
	RING_API_REGISTER("pdf_clear_err",ring_pdf_clear_err);
}
