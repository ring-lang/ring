#include "ring.h"


/*
	OpenGL 1.1 Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/


#include <GL/glew.h>
#include <GL/glut.h>

RING_FUNC(ring_get_gl_zero)
{
	RING_API_RETNUMBER(GL_ZERO);
}

RING_FUNC(ring_get_gl_false)
{
	RING_API_RETNUMBER(GL_FALSE);
}

RING_FUNC(ring_get_gl_logic_op)
{
	RING_API_RETNUMBER(GL_LOGIC_OP);
}

RING_FUNC(ring_get_gl_none)
{
	RING_API_RETNUMBER(GL_NONE);
}

RING_FUNC(ring_get_gl_texture_components)
{
	RING_API_RETNUMBER(GL_TEXTURE_COMPONENTS);
}

RING_FUNC(ring_get_gl_no_error)
{
	RING_API_RETNUMBER(GL_NO_ERROR);
}

RING_FUNC(ring_get_gl_points)
{
	RING_API_RETNUMBER(GL_POINTS);
}

RING_FUNC(ring_get_gl_current_bit)
{
	RING_API_RETNUMBER(GL_CURRENT_BIT);
}

RING_FUNC(ring_get_gl_true)
{
	RING_API_RETNUMBER(GL_TRUE);
}

RING_FUNC(ring_get_gl_one)
{
	RING_API_RETNUMBER(GL_ONE);
}

RING_FUNC(ring_get_gl_client_pixel_store_bit)
{
	RING_API_RETNUMBER(GL_CLIENT_PIXEL_STORE_BIT);
}

RING_FUNC(ring_get_gl_lines)
{
	RING_API_RETNUMBER(GL_LINES);
}

RING_FUNC(ring_get_gl_line_loop)
{
	RING_API_RETNUMBER(GL_LINE_LOOP);
}

RING_FUNC(ring_get_gl_point_bit)
{
	RING_API_RETNUMBER(GL_POINT_BIT);
}

RING_FUNC(ring_get_gl_client_vertex_array_bit)
{
	RING_API_RETNUMBER(GL_CLIENT_VERTEX_ARRAY_BIT);
}

RING_FUNC(ring_get_gl_line_strip)
{
	RING_API_RETNUMBER(GL_LINE_STRIP);
}

RING_FUNC(ring_get_gl_line_bit)
{
	RING_API_RETNUMBER(GL_LINE_BIT);
}

RING_FUNC(ring_get_gl_triangles)
{
	RING_API_RETNUMBER(GL_TRIANGLES);
}

RING_FUNC(ring_get_gl_triangle_strip)
{
	RING_API_RETNUMBER(GL_TRIANGLE_STRIP);
}

RING_FUNC(ring_get_gl_triangle_fan)
{
	RING_API_RETNUMBER(GL_TRIANGLE_FAN);
}

RING_FUNC(ring_get_gl_quads)
{
	RING_API_RETNUMBER(GL_QUADS);
}

RING_FUNC(ring_get_gl_quad_strip)
{
	RING_API_RETNUMBER(GL_QUAD_STRIP);
}

RING_FUNC(ring_get_gl_polygon_bit)
{
	RING_API_RETNUMBER(GL_POLYGON_BIT);
}

RING_FUNC(ring_get_gl_polygon)
{
	RING_API_RETNUMBER(GL_POLYGON);
}

RING_FUNC(ring_get_gl_polygon_stipple_bit)
{
	RING_API_RETNUMBER(GL_POLYGON_STIPPLE_BIT);
}

RING_FUNC(ring_get_gl_pixel_mode_bit)
{
	RING_API_RETNUMBER(GL_PIXEL_MODE_BIT);
}

RING_FUNC(ring_get_gl_lighting_bit)
{
	RING_API_RETNUMBER(GL_LIGHTING_BIT);
}

RING_FUNC(ring_get_gl_fog_bit)
{
	RING_API_RETNUMBER(GL_FOG_BIT);
}

RING_FUNC(ring_get_gl_depth_buffer_bit)
{
	RING_API_RETNUMBER(GL_DEPTH_BUFFER_BIT);
}

RING_FUNC(ring_get_gl_accum)
{
	RING_API_RETNUMBER(GL_ACCUM);
}

RING_FUNC(ring_get_gl_load)
{
	RING_API_RETNUMBER(GL_LOAD);
}

RING_FUNC(ring_get_gl_return)
{
	RING_API_RETNUMBER(GL_RETURN);
}

RING_FUNC(ring_get_gl_mult)
{
	RING_API_RETNUMBER(GL_MULT);
}

RING_FUNC(ring_get_gl_add)
{
	RING_API_RETNUMBER(GL_ADD);
}

RING_FUNC(ring_get_gl_never)
{
	RING_API_RETNUMBER(GL_NEVER);
}

RING_FUNC(ring_get_gl_accum_buffer_bit)
{
	RING_API_RETNUMBER(GL_ACCUM_BUFFER_BIT);
}

RING_FUNC(ring_get_gl_less)
{
	RING_API_RETNUMBER(GL_LESS);
}

RING_FUNC(ring_get_gl_equal)
{
	RING_API_RETNUMBER(GL_EQUAL);
}

RING_FUNC(ring_get_gl_lequal)
{
	RING_API_RETNUMBER(GL_LEQUAL);
}

RING_FUNC(ring_get_gl_greater)
{
	RING_API_RETNUMBER(GL_GREATER);
}

RING_FUNC(ring_get_gl_notequal)
{
	RING_API_RETNUMBER(GL_NOTEQUAL);
}

RING_FUNC(ring_get_gl_gequal)
{
	RING_API_RETNUMBER(GL_GEQUAL);
}

RING_FUNC(ring_get_gl_always)
{
	RING_API_RETNUMBER(GL_ALWAYS);
}

RING_FUNC(ring_get_gl_src_color)
{
	RING_API_RETNUMBER(GL_SRC_COLOR);
}

RING_FUNC(ring_get_gl_one_minus_src_color)
{
	RING_API_RETNUMBER(GL_ONE_MINUS_SRC_COLOR);
}

RING_FUNC(ring_get_gl_src_alpha)
{
	RING_API_RETNUMBER(GL_SRC_ALPHA);
}

RING_FUNC(ring_get_gl_one_minus_src_alpha)
{
	RING_API_RETNUMBER(GL_ONE_MINUS_SRC_ALPHA);
}

RING_FUNC(ring_get_gl_dst_alpha)
{
	RING_API_RETNUMBER(GL_DST_ALPHA);
}

RING_FUNC(ring_get_gl_one_minus_dst_alpha)
{
	RING_API_RETNUMBER(GL_ONE_MINUS_DST_ALPHA);
}

RING_FUNC(ring_get_gl_dst_color)
{
	RING_API_RETNUMBER(GL_DST_COLOR);
}

RING_FUNC(ring_get_gl_one_minus_dst_color)
{
	RING_API_RETNUMBER(GL_ONE_MINUS_DST_COLOR);
}

RING_FUNC(ring_get_gl_src_alpha_saturate)
{
	RING_API_RETNUMBER(GL_SRC_ALPHA_SATURATE);
}

RING_FUNC(ring_get_gl_stencil_buffer_bit)
{
	RING_API_RETNUMBER(GL_STENCIL_BUFFER_BIT);
}

RING_FUNC(ring_get_gl_front_left)
{
	RING_API_RETNUMBER(GL_FRONT_LEFT);
}

RING_FUNC(ring_get_gl_front_right)
{
	RING_API_RETNUMBER(GL_FRONT_RIGHT);
}

RING_FUNC(ring_get_gl_back_left)
{
	RING_API_RETNUMBER(GL_BACK_LEFT);
}

RING_FUNC(ring_get_gl_back_right)
{
	RING_API_RETNUMBER(GL_BACK_RIGHT);
}

RING_FUNC(ring_get_gl_front)
{
	RING_API_RETNUMBER(GL_FRONT);
}

RING_FUNC(ring_get_gl_back)
{
	RING_API_RETNUMBER(GL_BACK);
}

RING_FUNC(ring_get_gl_left)
{
	RING_API_RETNUMBER(GL_LEFT);
}

RING_FUNC(ring_get_gl_right)
{
	RING_API_RETNUMBER(GL_RIGHT);
}

RING_FUNC(ring_get_gl_front_and_back)
{
	RING_API_RETNUMBER(GL_FRONT_AND_BACK);
}

RING_FUNC(ring_get_gl_aux0)
{
	RING_API_RETNUMBER(GL_AUX0);
}

RING_FUNC(ring_get_gl_aux1)
{
	RING_API_RETNUMBER(GL_AUX1);
}

RING_FUNC(ring_get_gl_aux2)
{
	RING_API_RETNUMBER(GL_AUX2);
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("get_gl_zero",ring_get_gl_zero);
	ring_vm_funcregister("get_gl_false",ring_get_gl_false);
	ring_vm_funcregister("get_gl_logic_op",ring_get_gl_logic_op);
	ring_vm_funcregister("get_gl_none",ring_get_gl_none);
	ring_vm_funcregister("get_gl_texture_components",ring_get_gl_texture_components);
	ring_vm_funcregister("get_gl_no_error",ring_get_gl_no_error);
	ring_vm_funcregister("get_gl_points",ring_get_gl_points);
	ring_vm_funcregister("get_gl_current_bit",ring_get_gl_current_bit);
	ring_vm_funcregister("get_gl_true",ring_get_gl_true);
	ring_vm_funcregister("get_gl_one",ring_get_gl_one);
	ring_vm_funcregister("get_gl_client_pixel_store_bit",ring_get_gl_client_pixel_store_bit);
	ring_vm_funcregister("get_gl_lines",ring_get_gl_lines);
	ring_vm_funcregister("get_gl_line_loop",ring_get_gl_line_loop);
	ring_vm_funcregister("get_gl_point_bit",ring_get_gl_point_bit);
	ring_vm_funcregister("get_gl_client_vertex_array_bit",ring_get_gl_client_vertex_array_bit);
	ring_vm_funcregister("get_gl_line_strip",ring_get_gl_line_strip);
	ring_vm_funcregister("get_gl_line_bit",ring_get_gl_line_bit);
	ring_vm_funcregister("get_gl_triangles",ring_get_gl_triangles);
	ring_vm_funcregister("get_gl_triangle_strip",ring_get_gl_triangle_strip);
	ring_vm_funcregister("get_gl_triangle_fan",ring_get_gl_triangle_fan);
	ring_vm_funcregister("get_gl_quads",ring_get_gl_quads);
	ring_vm_funcregister("get_gl_quad_strip",ring_get_gl_quad_strip);
	ring_vm_funcregister("get_gl_polygon_bit",ring_get_gl_polygon_bit);
	ring_vm_funcregister("get_gl_polygon",ring_get_gl_polygon);
	ring_vm_funcregister("get_gl_polygon_stipple_bit",ring_get_gl_polygon_stipple_bit);
	ring_vm_funcregister("get_gl_pixel_mode_bit",ring_get_gl_pixel_mode_bit);
	ring_vm_funcregister("get_gl_lighting_bit",ring_get_gl_lighting_bit);
	ring_vm_funcregister("get_gl_fog_bit",ring_get_gl_fog_bit);
	ring_vm_funcregister("get_gl_depth_buffer_bit",ring_get_gl_depth_buffer_bit);
	ring_vm_funcregister("get_gl_accum",ring_get_gl_accum);
	ring_vm_funcregister("get_gl_load",ring_get_gl_load);
	ring_vm_funcregister("get_gl_return",ring_get_gl_return);
	ring_vm_funcregister("get_gl_mult",ring_get_gl_mult);
	ring_vm_funcregister("get_gl_add",ring_get_gl_add);
	ring_vm_funcregister("get_gl_never",ring_get_gl_never);
	ring_vm_funcregister("get_gl_accum_buffer_bit",ring_get_gl_accum_buffer_bit);
	ring_vm_funcregister("get_gl_less",ring_get_gl_less);
	ring_vm_funcregister("get_gl_equal",ring_get_gl_equal);
	ring_vm_funcregister("get_gl_lequal",ring_get_gl_lequal);
	ring_vm_funcregister("get_gl_greater",ring_get_gl_greater);
	ring_vm_funcregister("get_gl_notequal",ring_get_gl_notequal);
	ring_vm_funcregister("get_gl_gequal",ring_get_gl_gequal);
	ring_vm_funcregister("get_gl_always",ring_get_gl_always);
	ring_vm_funcregister("get_gl_src_color",ring_get_gl_src_color);
	ring_vm_funcregister("get_gl_one_minus_src_color",ring_get_gl_one_minus_src_color);
	ring_vm_funcregister("get_gl_src_alpha",ring_get_gl_src_alpha);
	ring_vm_funcregister("get_gl_one_minus_src_alpha",ring_get_gl_one_minus_src_alpha);
	ring_vm_funcregister("get_gl_dst_alpha",ring_get_gl_dst_alpha);
	ring_vm_funcregister("get_gl_one_minus_dst_alpha",ring_get_gl_one_minus_dst_alpha);
	ring_vm_funcregister("get_gl_dst_color",ring_get_gl_dst_color);
	ring_vm_funcregister("get_gl_one_minus_dst_color",ring_get_gl_one_minus_dst_color);
	ring_vm_funcregister("get_gl_src_alpha_saturate",ring_get_gl_src_alpha_saturate);
	ring_vm_funcregister("get_gl_stencil_buffer_bit",ring_get_gl_stencil_buffer_bit);
	ring_vm_funcregister("get_gl_front_left",ring_get_gl_front_left);
	ring_vm_funcregister("get_gl_front_right",ring_get_gl_front_right);
	ring_vm_funcregister("get_gl_back_left",ring_get_gl_back_left);
	ring_vm_funcregister("get_gl_back_right",ring_get_gl_back_right);
	ring_vm_funcregister("get_gl_front",ring_get_gl_front);
	ring_vm_funcregister("get_gl_back",ring_get_gl_back);
	ring_vm_funcregister("get_gl_left",ring_get_gl_left);
	ring_vm_funcregister("get_gl_right",ring_get_gl_right);
	ring_vm_funcregister("get_gl_front_and_back",ring_get_gl_front_and_back);
	ring_vm_funcregister("get_gl_aux0",ring_get_gl_aux0);
	ring_vm_funcregister("get_gl_aux1",ring_get_gl_aux1);
	ring_vm_funcregister("get_gl_aux2",ring_get_gl_aux2);
}
