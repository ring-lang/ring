#include "ring.h"

#include "lib/pdfgen.h"
#include "lib/pdfgen.c"
RING_FUNC(ring_get_image_png)
{
	RING_API_RETNUMBER(IMAGE_PNG);
}

RING_FUNC(ring_get_image_jpg)
{
	RING_API_RETNUMBER(IMAGE_JPG);
}

RING_FUNC(ring_get_image_ppm)
{
	RING_API_RETNUMBER(IMAGE_PPM);
}

RING_FUNC(ring_get_image_bmp)
{
	RING_API_RETNUMBER(IMAGE_BMP);
}

RING_FUNC(ring_get_image_unknown)
{
	RING_API_RETNUMBER(IMAGE_UNKNOWN);
}

RING_FUNC(ring_get_png_color_greyscale)
{
	RING_API_RETNUMBER(PNG_COLOR_GREYSCALE);
}

RING_FUNC(ring_get_png_color_rgb)
{
	RING_API_RETNUMBER(PNG_COLOR_RGB);
}

RING_FUNC(ring_get_png_color_indexed)
{
	RING_API_RETNUMBER(PNG_COLOR_INDEXED);
}

RING_FUNC(ring_get_png_color_greyscale_a)
{
	RING_API_RETNUMBER(PNG_COLOR_GREYSCALE_A);
}

RING_FUNC(ring_get_png_color_rgba)
{
	RING_API_RETNUMBER(PNG_COLOR_RGBA);
}

RING_FUNC(ring_get_png_color_invalid)
{
	RING_API_RETNUMBER(PNG_COLOR_INVALID);
}

RING_FUNC(ring_get_ppm_binary_color_rgb)
{
	RING_API_RETNUMBER(PPM_BINARY_COLOR_RGB);
}

RING_FUNC(ring_get_ppm_binary_color_gray)
{
	RING_API_RETNUMBER(PPM_BINARY_COLOR_GRAY);
}

RING_FUNC(ring_get_pdf_letter_width)
{
	RING_API_RETNUMBER(PDF_LETTER_WIDTH);
}

RING_FUNC(ring_get_pdf_letter_height)
{
	RING_API_RETNUMBER(PDF_LETTER_HEIGHT);
}

RING_FUNC(ring_get_pdf_a4_width)
{
	RING_API_RETNUMBER(PDF_A4_WIDTH);
}

RING_FUNC(ring_get_pdf_a4_height)
{
	RING_API_RETNUMBER(PDF_A4_HEIGHT);
}

RING_FUNC(ring_get_pdf_a3_width)
{
	RING_API_RETNUMBER(PDF_A3_WIDTH);
}

RING_FUNC(ring_get_pdf_a3_height)
{
	RING_API_RETNUMBER(PDF_A3_HEIGHT);
}

RING_FUNC(ring_get_pdf_red)
{
	RING_API_RETNUMBER(PDF_RED);
}

RING_FUNC(ring_get_pdf_green)
{
	RING_API_RETNUMBER(PDF_GREEN);
}

RING_FUNC(ring_get_pdf_blue)
{
	RING_API_RETNUMBER(PDF_BLUE);
}

RING_FUNC(ring_get_pdf_black)
{
	RING_API_RETNUMBER(PDF_BLACK);
}

RING_FUNC(ring_get_pdf_white)
{
	RING_API_RETNUMBER(PDF_WHITE);
}

RING_FUNC(ring_get_pdf_transparent)
{
	RING_API_RETNUMBER(PDF_TRANSPARENT);
}

RING_FUNC(ring_get_pdf_align_left)
{
	RING_API_RETNUMBER(PDF_ALIGN_LEFT);
}

RING_FUNC(ring_get_pdf_align_right)
{
	RING_API_RETNUMBER(PDF_ALIGN_RIGHT);
}

RING_FUNC(ring_get_pdf_align_center)
{
	RING_API_RETNUMBER(PDF_ALIGN_CENTER);
}

RING_FUNC(ring_get_pdf_align_justify)
{
	RING_API_RETNUMBER(PDF_ALIGN_JUSTIFY);
}

RING_FUNC(ring_get_pdf_align_justify_all)
{
	RING_API_RETNUMBER(PDF_ALIGN_JUSTIFY_ALL);
}

RING_FUNC(ring_get_pdf_align_no_write)
{
	RING_API_RETNUMBER(PDF_ALIGN_NO_WRITE);
}


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


RING_FUNC(ring_pdf_add_line)
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
	RING_API_RETNUMBER(pdf_add_line((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (uint32_t ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_pdf_add_cubic_bezier)
{
	if ( RING_API_PARACOUNT != 12 ) {
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
	if ( ! RING_API_ISNUMBER(11) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(12) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_cubic_bezier((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (float ) RING_API_GETNUMBER(10), (float ) RING_API_GETNUMBER(11), (uint32_t ) RING_API_GETNUMBER(12)));
}


RING_FUNC(ring_pdf_add_quadratic_bezier)
{
	if ( RING_API_PARACOUNT != 10 ) {
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
	RING_API_RETNUMBER(pdf_add_quadratic_bezier((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (uint32_t ) RING_API_GETNUMBER(10)));
}


RING_FUNC(ring_pdf_add_custom_path)
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_custom_path((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"),(struct pdf_path_operation *) RING_API_GETCPOINTER(3,"struct pdf_path_operation"), (int ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (uint32_t ) RING_API_GETNUMBER(6), (uint32_t ) RING_API_GETNUMBER(7)));
}


RING_FUNC(ring_pdf_add_ellipse)
{
	if ( RING_API_PARACOUNT != 9 ) {
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
	RING_API_RETNUMBER(pdf_add_ellipse((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (uint32_t ) RING_API_GETNUMBER(8), (uint32_t ) RING_API_GETNUMBER(9)));
}


RING_FUNC(ring_pdf_add_circle)
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
	RING_API_RETNUMBER(pdf_add_circle((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (uint32_t ) RING_API_GETNUMBER(7), (uint32_t ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_pdf_add_rectangle)
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
	RING_API_RETNUMBER(pdf_add_rectangle((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (uint32_t ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_pdf_add_filled_rectangle)
{
	if ( RING_API_PARACOUNT != 9 ) {
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
	RING_API_RETNUMBER(pdf_add_filled_rectangle((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (uint32_t ) RING_API_GETNUMBER(8), (uint32_t ) RING_API_GETNUMBER(9)));
}


RING_FUNC(ring_pdf_add_bookmark)
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_bookmark((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)));
}


RING_FUNC(ring_pdf_add_link)
{
	if ( RING_API_PARACOUNT != 9 ) {
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
	if ( ! RING_API_ISCPOINTER(7) ) {
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
	RING_API_RETNUMBER(pdf_add_link((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),(struct pdf_object *) RING_API_GETCPOINTER(7,"struct pdf_object"), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9)));
}


RING_FUNC(ring_pdf_add_barcode)
{
	if ( RING_API_PARACOUNT != 9 ) {
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
	if ( ! RING_API_ISSTRING(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_barcode((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (int ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7),RING_API_GETSTRING(8), (uint32_t ) RING_API_GETNUMBER(9)));
}


RING_FUNC(ring_pdf_add_image_data)
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
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_image_data((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),(uint8_t *) RING_API_GETCPOINTER(7,"uint8_t"), (size_t ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_pdf_add_rgb24)
{
	if ( RING_API_PARACOUNT != 9 ) {
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
	if ( ! RING_API_ISCPOINTER(7) ) {
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
	RING_API_RETNUMBER(pdf_add_rgb24((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),(uint8_t *) RING_API_GETCPOINTER(7,"uint8_t"), (uint32_t ) RING_API_GETNUMBER(8), (uint32_t ) RING_API_GETNUMBER(9)));
}


RING_FUNC(ring_pdf_add_grayscale8)
{
	if ( RING_API_PARACOUNT != 9 ) {
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
	if ( ! RING_API_ISCPOINTER(7) ) {
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
	RING_API_RETNUMBER(pdf_add_grayscale8((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),(uint8_t *) RING_API_GETCPOINTER(7,"uint8_t"), (uint32_t ) RING_API_GETNUMBER(8), (uint32_t ) RING_API_GETNUMBER(9)));
}


RING_FUNC(ring_pdf_add_image_file)
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
	if ( ! RING_API_ISSTRING(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pdf_add_image_file((struct pdf_doc *) RING_API_GETCPOINTER(1,"struct pdf_doc"),(struct pdf_object *) RING_API_GETCPOINTER(2,"struct pdf_object"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),RING_API_GETSTRING(7)));
}


RING_FUNC(ring_pdf_parse_image_header)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	RING_API_RETNUMBER(pdf_parse_image_header((struct pdf_img_info *) RING_API_GETCPOINTER(1,"struct pdf_img_info"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"), (size_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (size_t ) RING_API_GETNUMBER(5)));
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
	RING_API_REGISTER("pdf_add_line",ring_pdf_add_line);
	RING_API_REGISTER("pdf_add_cubic_bezier",ring_pdf_add_cubic_bezier);
	RING_API_REGISTER("pdf_add_quadratic_bezier",ring_pdf_add_quadratic_bezier);
	RING_API_REGISTER("pdf_add_custom_path",ring_pdf_add_custom_path);
	RING_API_REGISTER("pdf_add_ellipse",ring_pdf_add_ellipse);
	RING_API_REGISTER("pdf_add_circle",ring_pdf_add_circle);
	RING_API_REGISTER("pdf_add_rectangle",ring_pdf_add_rectangle);
	RING_API_REGISTER("pdf_add_filled_rectangle",ring_pdf_add_filled_rectangle);
	RING_API_REGISTER("pdf_add_bookmark",ring_pdf_add_bookmark);
	RING_API_REGISTER("pdf_add_link",ring_pdf_add_link);
	RING_API_REGISTER("pdf_add_barcode",ring_pdf_add_barcode);
	RING_API_REGISTER("pdf_add_image_data",ring_pdf_add_image_data);
	RING_API_REGISTER("pdf_add_rgb24",ring_pdf_add_rgb24);
	RING_API_REGISTER("pdf_add_grayscale8",ring_pdf_add_grayscale8);
	RING_API_REGISTER("pdf_add_image_file",ring_pdf_add_image_file);
	RING_API_REGISTER("pdf_parse_image_header",ring_pdf_parse_image_header);
	RING_API_REGISTER("get_image_png",ring_get_image_png);
	RING_API_REGISTER("get_image_jpg",ring_get_image_jpg);
	RING_API_REGISTER("get_image_ppm",ring_get_image_ppm);
	RING_API_REGISTER("get_image_bmp",ring_get_image_bmp);
	RING_API_REGISTER("get_image_unknown",ring_get_image_unknown);
	RING_API_REGISTER("get_png_color_greyscale",ring_get_png_color_greyscale);
	RING_API_REGISTER("get_png_color_rgb",ring_get_png_color_rgb);
	RING_API_REGISTER("get_png_color_indexed",ring_get_png_color_indexed);
	RING_API_REGISTER("get_png_color_greyscale_a",ring_get_png_color_greyscale_a);
	RING_API_REGISTER("get_png_color_rgba",ring_get_png_color_rgba);
	RING_API_REGISTER("get_png_color_invalid",ring_get_png_color_invalid);
	RING_API_REGISTER("get_ppm_binary_color_rgb",ring_get_ppm_binary_color_rgb);
	RING_API_REGISTER("get_ppm_binary_color_gray",ring_get_ppm_binary_color_gray);
	RING_API_REGISTER("get_pdf_letter_width",ring_get_pdf_letter_width);
	RING_API_REGISTER("get_pdf_letter_height",ring_get_pdf_letter_height);
	RING_API_REGISTER("get_pdf_a4_width",ring_get_pdf_a4_width);
	RING_API_REGISTER("get_pdf_a4_height",ring_get_pdf_a4_height);
	RING_API_REGISTER("get_pdf_a3_width",ring_get_pdf_a3_width);
	RING_API_REGISTER("get_pdf_a3_height",ring_get_pdf_a3_height);
	RING_API_REGISTER("get_pdf_red",ring_get_pdf_red);
	RING_API_REGISTER("get_pdf_green",ring_get_pdf_green);
	RING_API_REGISTER("get_pdf_blue",ring_get_pdf_blue);
	RING_API_REGISTER("get_pdf_black",ring_get_pdf_black);
	RING_API_REGISTER("get_pdf_white",ring_get_pdf_white);
	RING_API_REGISTER("get_pdf_transparent",ring_get_pdf_transparent);
	RING_API_REGISTER("get_pdf_align_left",ring_get_pdf_align_left);
	RING_API_REGISTER("get_pdf_align_right",ring_get_pdf_align_right);
	RING_API_REGISTER("get_pdf_align_center",ring_get_pdf_align_center);
	RING_API_REGISTER("get_pdf_align_justify",ring_get_pdf_align_justify);
	RING_API_REGISTER("get_pdf_align_justify_all",ring_get_pdf_align_justify_all);
	RING_API_REGISTER("get_pdf_align_no_write",ring_get_pdf_align_no_write);
}
