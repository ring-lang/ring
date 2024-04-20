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


RING_FUNC(ring_pdf_set_font)
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
	RING_API_RETNUMBER(pdf_set_font((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_pdf_get_font_text_width)
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_get_font_text_width((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (float ) RING_API_GETNUMBER(4),(float *) RING_API_GETCPOINTER(5,"float")));
}


RING_FUNC(ring_pdf_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_height((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc")));
}


RING_FUNC(ring_pdf_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_width((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc")));
}


RING_FUNC(ring_pdf_page_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_page_height((struct pdf_object *) RING_API_GETCPOINTER(1,"struct pdf_object")));
}


RING_FUNC(ring_pdf_page_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_page_width((struct pdf_object *) RING_API_GETCPOINTER(1,"struct pdf_object")));
}


RING_FUNC(ring_pdf_append_page)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pdf_append_page((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc")),"struct pdf_object");
}


RING_FUNC(ring_pdf_get_page)
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
	RING_API_RETCPOINTER(pdf_get_page((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"), (int ) RING_API_GETNUMBER(2)),"struct pdf_object");
}


RING_FUNC(ring_pdf_page_set_size)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_page_set_size((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_pdf_save)
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
	RING_API_RETNUMBER(pdf_save((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_pdf_save_file)
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
	RING_API_RETNUMBER(pdf_save_file((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(FILE *) RING_API_GETCPOINTER(2,"FILE")));
}


RING_FUNC(ring_pdf_add_text)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_text((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"),RING_API_GETSTRING(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (uint32_t ) RING_API_GETNUMBER(7)));
}


RING_FUNC(ring_pdf_add_text_rotate)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETNUMBER(pdf_add_text_rotate((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"),RING_API_GETSTRING(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (uint32_t ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_pdf_add_text_wrap)
{
	if ( RING_API_PARACOUNT != 11 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(11) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_text_wrap((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"),RING_API_GETSTRING(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (uint32_t ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (int ) RING_API_GETNUMBER(10),(float *) RING_API_GETCPOINTER(11,"float")));
}

RING_LIBINIT
{
	RING_API_REGISTER("pdf_create",ring_pdf_create);
	RING_API_REGISTER("pdf_destroy",ring_pdf_destroy);
	RING_API_REGISTER("pdf_get_err",ring_pdf_get_err);
	RING_API_REGISTER("pdf_clear_err",ring_pdf_clear_err);
	RING_API_REGISTER("pdf_set_font",ring_pdf_set_font);
	RING_API_REGISTER("pdf_get_font_text_width",ring_pdf_get_font_text_width);
	RING_API_REGISTER("pdf_height",ring_pdf_height);
	RING_API_REGISTER("pdf_width",ring_pdf_width);
	RING_API_REGISTER("pdf_page_height",ring_pdf_page_height);
	RING_API_REGISTER("pdf_page_width",ring_pdf_page_width);
	RING_API_REGISTER("pdf_append_page",ring_pdf_append_page);
	RING_API_REGISTER("pdf_get_page",ring_pdf_get_page);
	RING_API_REGISTER("pdf_page_set_size",ring_pdf_page_set_size);
	RING_API_REGISTER("pdf_save",ring_pdf_save);
	RING_API_REGISTER("pdf_save_file",ring_pdf_save_file);
	RING_API_REGISTER("pdf_add_text",ring_pdf_add_text);
	RING_API_REGISTER("pdf_add_text_rotate",ring_pdf_add_text_rotate);
	RING_API_REGISTER("pdf_add_text_wrap",ring_pdf_add_text_wrap);
}
