#include "ring.h"


/*
	OpenGL 1.5 Extension
	Copyright (c) 2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/



#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>

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

RING_FUNC(ring_get_gl_aux3)
{
	RING_API_RETNUMBER(GL_AUX3);
}

RING_FUNC(ring_get_gl_invalid_enum)
{
	RING_API_RETNUMBER(GL_INVALID_ENUM);
}

RING_FUNC(ring_get_gl_invalid_value)
{
	RING_API_RETNUMBER(GL_INVALID_VALUE);
}

RING_FUNC(ring_get_gl_invalid_operation)
{
	RING_API_RETNUMBER(GL_INVALID_OPERATION);
}

RING_FUNC(ring_get_gl_stack_overflow)
{
	RING_API_RETNUMBER(GL_STACK_OVERFLOW);
}

RING_FUNC(ring_get_gl_stack_underflow)
{
	RING_API_RETNUMBER(GL_STACK_UNDERFLOW);
}

RING_FUNC(ring_get_gl_out_of_memory)
{
	RING_API_RETNUMBER(GL_OUT_OF_MEMORY);
}

RING_FUNC(ring_get_gl_2d)
{
	RING_API_RETNUMBER(GL_2D);
}

RING_FUNC(ring_get_gl_3d)
{
	RING_API_RETNUMBER(GL_3D);
}

RING_FUNC(ring_get_gl_3d_color)
{
	RING_API_RETNUMBER(GL_3D_COLOR);
}

RING_FUNC(ring_get_gl_3d_color_texture)
{
	RING_API_RETNUMBER(GL_3D_COLOR_TEXTURE);
}

RING_FUNC(ring_get_gl_4d_color_texture)
{
	RING_API_RETNUMBER(GL_4D_COLOR_TEXTURE);
}

RING_FUNC(ring_get_gl_pass_through_token)
{
	RING_API_RETNUMBER(GL_PASS_THROUGH_TOKEN);
}

RING_FUNC(ring_get_gl_point_token)
{
	RING_API_RETNUMBER(GL_POINT_TOKEN);
}

RING_FUNC(ring_get_gl_line_token)
{
	RING_API_RETNUMBER(GL_LINE_TOKEN);
}

RING_FUNC(ring_get_gl_polygon_token)
{
	RING_API_RETNUMBER(GL_POLYGON_TOKEN);
}

RING_FUNC(ring_get_gl_bitmap_token)
{
	RING_API_RETNUMBER(GL_BITMAP_TOKEN);
}

RING_FUNC(ring_get_gl_draw_pixel_token)
{
	RING_API_RETNUMBER(GL_DRAW_PIXEL_TOKEN);
}

RING_FUNC(ring_get_gl_copy_pixel_token)
{
	RING_API_RETNUMBER(GL_COPY_PIXEL_TOKEN);
}

RING_FUNC(ring_get_gl_line_reset_token)
{
	RING_API_RETNUMBER(GL_LINE_RESET_TOKEN);
}

RING_FUNC(ring_get_gl_exp)
{
	RING_API_RETNUMBER(GL_EXP);
}

RING_FUNC(ring_get_gl_viewport_bit)
{
	RING_API_RETNUMBER(GL_VIEWPORT_BIT);
}

RING_FUNC(ring_get_gl_exp2)
{
	RING_API_RETNUMBER(GL_EXP2);
}

RING_FUNC(ring_get_gl_cw)
{
	RING_API_RETNUMBER(GL_CW);
}

RING_FUNC(ring_get_gl_ccw)
{
	RING_API_RETNUMBER(GL_CCW);
}

RING_FUNC(ring_get_gl_coeff)
{
	RING_API_RETNUMBER(GL_COEFF);
}

RING_FUNC(ring_get_gl_order)
{
	RING_API_RETNUMBER(GL_ORDER);
}

RING_FUNC(ring_get_gl_domain)
{
	RING_API_RETNUMBER(GL_DOMAIN);
}

RING_FUNC(ring_get_gl_current_color)
{
	RING_API_RETNUMBER(GL_CURRENT_COLOR);
}

RING_FUNC(ring_get_gl_current_index)
{
	RING_API_RETNUMBER(GL_CURRENT_INDEX);
}

RING_FUNC(ring_get_gl_current_normal)
{
	RING_API_RETNUMBER(GL_CURRENT_NORMAL);
}

RING_FUNC(ring_get_gl_current_texture_coords)
{
	RING_API_RETNUMBER(GL_CURRENT_TEXTURE_COORDS);
}

RING_FUNC(ring_get_gl_current_raster_color)
{
	RING_API_RETNUMBER(GL_CURRENT_RASTER_COLOR);
}

RING_FUNC(ring_get_gl_current_raster_index)
{
	RING_API_RETNUMBER(GL_CURRENT_RASTER_INDEX);
}

RING_FUNC(ring_get_gl_current_raster_texture_coords)
{
	RING_API_RETNUMBER(GL_CURRENT_RASTER_TEXTURE_COORDS);
}

RING_FUNC(ring_get_gl_current_raster_position)
{
	RING_API_RETNUMBER(GL_CURRENT_RASTER_POSITION);
}

RING_FUNC(ring_get_gl_current_raster_position_valid)
{
	RING_API_RETNUMBER(GL_CURRENT_RASTER_POSITION_VALID);
}

RING_FUNC(ring_get_gl_current_raster_distance)
{
	RING_API_RETNUMBER(GL_CURRENT_RASTER_DISTANCE);
}

RING_FUNC(ring_get_gl_point_smooth)
{
	RING_API_RETNUMBER(GL_POINT_SMOOTH);
}

RING_FUNC(ring_get_gl_point_size)
{
	RING_API_RETNUMBER(GL_POINT_SIZE);
}

RING_FUNC(ring_get_gl_point_size_range)
{
	RING_API_RETNUMBER(GL_POINT_SIZE_RANGE);
}

RING_FUNC(ring_get_gl_point_size_granularity)
{
	RING_API_RETNUMBER(GL_POINT_SIZE_GRANULARITY);
}

RING_FUNC(ring_get_gl_line_smooth)
{
	RING_API_RETNUMBER(GL_LINE_SMOOTH);
}

RING_FUNC(ring_get_gl_line_width)
{
	RING_API_RETNUMBER(GL_LINE_WIDTH);
}

RING_FUNC(ring_get_gl_line_width_range)
{
	RING_API_RETNUMBER(GL_LINE_WIDTH_RANGE);
}

RING_FUNC(ring_get_gl_line_width_granularity)
{
	RING_API_RETNUMBER(GL_LINE_WIDTH_GRANULARITY);
}

RING_FUNC(ring_get_gl_line_stipple)
{
	RING_API_RETNUMBER(GL_LINE_STIPPLE);
}

RING_FUNC(ring_get_gl_line_stipple_pattern)
{
	RING_API_RETNUMBER(GL_LINE_STIPPLE_PATTERN);
}

RING_FUNC(ring_get_gl_line_stipple_repeat)
{
	RING_API_RETNUMBER(GL_LINE_STIPPLE_REPEAT);
}

RING_FUNC(ring_get_gl_list_mode)
{
	RING_API_RETNUMBER(GL_LIST_MODE);
}

RING_FUNC(ring_get_gl_max_list_nesting)
{
	RING_API_RETNUMBER(GL_MAX_LIST_NESTING);
}

RING_FUNC(ring_get_gl_list_base)
{
	RING_API_RETNUMBER(GL_LIST_BASE);
}

RING_FUNC(ring_get_gl_list_index)
{
	RING_API_RETNUMBER(GL_LIST_INDEX);
}

RING_FUNC(ring_get_gl_polygon_mode)
{
	RING_API_RETNUMBER(GL_POLYGON_MODE);
}

RING_FUNC(ring_get_gl_polygon_smooth)
{
	RING_API_RETNUMBER(GL_POLYGON_SMOOTH);
}

RING_FUNC(ring_get_gl_polygon_stipple)
{
	RING_API_RETNUMBER(GL_POLYGON_STIPPLE);
}

RING_FUNC(ring_get_gl_edge_flag)
{
	RING_API_RETNUMBER(GL_EDGE_FLAG);
}

RING_FUNC(ring_get_gl_cull_face)
{
	RING_API_RETNUMBER(GL_CULL_FACE);
}

RING_FUNC(ring_get_gl_cull_face_mode)
{
	RING_API_RETNUMBER(GL_CULL_FACE_MODE);
}

RING_FUNC(ring_get_gl_front_face)
{
	RING_API_RETNUMBER(GL_FRONT_FACE);
}

RING_FUNC(ring_get_gl_lighting)
{
	RING_API_RETNUMBER(GL_LIGHTING);
}

RING_FUNC(ring_get_gl_light_model_local_viewer)
{
	RING_API_RETNUMBER(GL_LIGHT_MODEL_LOCAL_VIEWER);
}

RING_FUNC(ring_get_gl_light_model_two_side)
{
	RING_API_RETNUMBER(GL_LIGHT_MODEL_TWO_SIDE);
}

RING_FUNC(ring_get_gl_light_model_ambient)
{
	RING_API_RETNUMBER(GL_LIGHT_MODEL_AMBIENT);
}

RING_FUNC(ring_get_gl_shade_model)
{
	RING_API_RETNUMBER(GL_SHADE_MODEL);
}

RING_FUNC(ring_get_gl_color_material_face)
{
	RING_API_RETNUMBER(GL_COLOR_MATERIAL_FACE);
}

RING_FUNC(ring_get_gl_color_material_parameter)
{
	RING_API_RETNUMBER(GL_COLOR_MATERIAL_PARAMETER);
}

RING_FUNC(ring_get_gl_color_material)
{
	RING_API_RETNUMBER(GL_COLOR_MATERIAL);
}

RING_FUNC(ring_get_gl_fog)
{
	RING_API_RETNUMBER(GL_FOG);
}

RING_FUNC(ring_get_gl_fog_index)
{
	RING_API_RETNUMBER(GL_FOG_INDEX);
}

RING_FUNC(ring_get_gl_fog_density)
{
	RING_API_RETNUMBER(GL_FOG_DENSITY);
}

RING_FUNC(ring_get_gl_fog_start)
{
	RING_API_RETNUMBER(GL_FOG_START);
}

RING_FUNC(ring_get_gl_fog_end)
{
	RING_API_RETNUMBER(GL_FOG_END);
}

RING_FUNC(ring_get_gl_fog_mode)
{
	RING_API_RETNUMBER(GL_FOG_MODE);
}

RING_FUNC(ring_get_gl_fog_color)
{
	RING_API_RETNUMBER(GL_FOG_COLOR);
}

RING_FUNC(ring_get_gl_depth_range)
{
	RING_API_RETNUMBER(GL_DEPTH_RANGE);
}

RING_FUNC(ring_get_gl_depth_test)
{
	RING_API_RETNUMBER(GL_DEPTH_TEST);
}

RING_FUNC(ring_get_gl_depth_writemask)
{
	RING_API_RETNUMBER(GL_DEPTH_WRITEMASK);
}

RING_FUNC(ring_get_gl_depth_clear_value)
{
	RING_API_RETNUMBER(GL_DEPTH_CLEAR_VALUE);
}

RING_FUNC(ring_get_gl_depth_func)
{
	RING_API_RETNUMBER(GL_DEPTH_FUNC);
}

RING_FUNC(ring_get_gl_accum_clear_value)
{
	RING_API_RETNUMBER(GL_ACCUM_CLEAR_VALUE);
}

RING_FUNC(ring_get_gl_stencil_test)
{
	RING_API_RETNUMBER(GL_STENCIL_TEST);
}

RING_FUNC(ring_get_gl_stencil_clear_value)
{
	RING_API_RETNUMBER(GL_STENCIL_CLEAR_VALUE);
}

RING_FUNC(ring_get_gl_stencil_func)
{
	RING_API_RETNUMBER(GL_STENCIL_FUNC);
}

RING_FUNC(ring_get_gl_stencil_value_mask)
{
	RING_API_RETNUMBER(GL_STENCIL_VALUE_MASK);
}

RING_FUNC(ring_get_gl_stencil_fail)
{
	RING_API_RETNUMBER(GL_STENCIL_FAIL);
}

RING_FUNC(ring_get_gl_stencil_pass_depth_fail)
{
	RING_API_RETNUMBER(GL_STENCIL_PASS_DEPTH_FAIL);
}

RING_FUNC(ring_get_gl_stencil_pass_depth_pass)
{
	RING_API_RETNUMBER(GL_STENCIL_PASS_DEPTH_PASS);
}

RING_FUNC(ring_get_gl_stencil_ref)
{
	RING_API_RETNUMBER(GL_STENCIL_REF);
}

RING_FUNC(ring_get_gl_stencil_writemask)
{
	RING_API_RETNUMBER(GL_STENCIL_WRITEMASK);
}

RING_FUNC(ring_get_gl_matrix_mode)
{
	RING_API_RETNUMBER(GL_MATRIX_MODE);
}

RING_FUNC(ring_get_gl_normalize)
{
	RING_API_RETNUMBER(GL_NORMALIZE);
}

RING_FUNC(ring_get_gl_viewport)
{
	RING_API_RETNUMBER(GL_VIEWPORT);
}

RING_FUNC(ring_get_gl_modelview_stack_depth)
{
	RING_API_RETNUMBER(GL_MODELVIEW_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_projection_stack_depth)
{
	RING_API_RETNUMBER(GL_PROJECTION_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_texture_stack_depth)
{
	RING_API_RETNUMBER(GL_TEXTURE_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_modelview_matrix)
{
	RING_API_RETNUMBER(GL_MODELVIEW_MATRIX);
}

RING_FUNC(ring_get_gl_projection_matrix)
{
	RING_API_RETNUMBER(GL_PROJECTION_MATRIX);
}

RING_FUNC(ring_get_gl_texture_matrix)
{
	RING_API_RETNUMBER(GL_TEXTURE_MATRIX);
}

RING_FUNC(ring_get_gl_attrib_stack_depth)
{
	RING_API_RETNUMBER(GL_ATTRIB_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_client_attrib_stack_depth)
{
	RING_API_RETNUMBER(GL_CLIENT_ATTRIB_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_alpha_test)
{
	RING_API_RETNUMBER(GL_ALPHA_TEST);
}

RING_FUNC(ring_get_gl_alpha_test_func)
{
	RING_API_RETNUMBER(GL_ALPHA_TEST_FUNC);
}

RING_FUNC(ring_get_gl_alpha_test_ref)
{
	RING_API_RETNUMBER(GL_ALPHA_TEST_REF);
}

RING_FUNC(ring_get_gl_dither)
{
	RING_API_RETNUMBER(GL_DITHER);
}

RING_FUNC(ring_get_gl_blend_dst)
{
	RING_API_RETNUMBER(GL_BLEND_DST);
}

RING_FUNC(ring_get_gl_blend_src)
{
	RING_API_RETNUMBER(GL_BLEND_SRC);
}

RING_FUNC(ring_get_gl_blend)
{
	RING_API_RETNUMBER(GL_BLEND);
}

RING_FUNC(ring_get_gl_logic_op_mode)
{
	RING_API_RETNUMBER(GL_LOGIC_OP_MODE);
}

RING_FUNC(ring_get_gl_index_logic_op)
{
	RING_API_RETNUMBER(GL_INDEX_LOGIC_OP);
}

RING_FUNC(ring_get_gl_color_logic_op)
{
	RING_API_RETNUMBER(GL_COLOR_LOGIC_OP);
}

RING_FUNC(ring_get_gl_aux_buffers)
{
	RING_API_RETNUMBER(GL_AUX_BUFFERS);
}

RING_FUNC(ring_get_gl_draw_buffer)
{
	RING_API_RETNUMBER(GL_DRAW_BUFFER);
}

RING_FUNC(ring_get_gl_read_buffer)
{
	RING_API_RETNUMBER(GL_READ_BUFFER);
}

RING_FUNC(ring_get_gl_scissor_box)
{
	RING_API_RETNUMBER(GL_SCISSOR_BOX);
}

RING_FUNC(ring_get_gl_scissor_test)
{
	RING_API_RETNUMBER(GL_SCISSOR_TEST);
}

RING_FUNC(ring_get_gl_index_clear_value)
{
	RING_API_RETNUMBER(GL_INDEX_CLEAR_VALUE);
}

RING_FUNC(ring_get_gl_index_writemask)
{
	RING_API_RETNUMBER(GL_INDEX_WRITEMASK);
}

RING_FUNC(ring_get_gl_color_clear_value)
{
	RING_API_RETNUMBER(GL_COLOR_CLEAR_VALUE);
}

RING_FUNC(ring_get_gl_color_writemask)
{
	RING_API_RETNUMBER(GL_COLOR_WRITEMASK);
}

RING_FUNC(ring_get_gl_index_mode)
{
	RING_API_RETNUMBER(GL_INDEX_MODE);
}

RING_FUNC(ring_get_gl_rgba_mode)
{
	RING_API_RETNUMBER(GL_RGBA_MODE);
}

RING_FUNC(ring_get_gl_doublebuffer)
{
	RING_API_RETNUMBER(GL_DOUBLEBUFFER);
}

RING_FUNC(ring_get_gl_stereo)
{
	RING_API_RETNUMBER(GL_STEREO);
}

RING_FUNC(ring_get_gl_render_mode)
{
	RING_API_RETNUMBER(GL_RENDER_MODE);
}

RING_FUNC(ring_get_gl_perspective_correction_hint)
{
	RING_API_RETNUMBER(GL_PERSPECTIVE_CORRECTION_HINT);
}

RING_FUNC(ring_get_gl_point_smooth_hint)
{
	RING_API_RETNUMBER(GL_POINT_SMOOTH_HINT);
}

RING_FUNC(ring_get_gl_line_smooth_hint)
{
	RING_API_RETNUMBER(GL_LINE_SMOOTH_HINT);
}

RING_FUNC(ring_get_gl_polygon_smooth_hint)
{
	RING_API_RETNUMBER(GL_POLYGON_SMOOTH_HINT);
}

RING_FUNC(ring_get_gl_fog_hint)
{
	RING_API_RETNUMBER(GL_FOG_HINT);
}

RING_FUNC(ring_get_gl_texture_gen_s)
{
	RING_API_RETNUMBER(GL_TEXTURE_GEN_S);
}

RING_FUNC(ring_get_gl_texture_gen_t)
{
	RING_API_RETNUMBER(GL_TEXTURE_GEN_T);
}

RING_FUNC(ring_get_gl_texture_gen_r)
{
	RING_API_RETNUMBER(GL_TEXTURE_GEN_R);
}

RING_FUNC(ring_get_gl_texture_gen_q)
{
	RING_API_RETNUMBER(GL_TEXTURE_GEN_Q);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_i)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_I);
}

RING_FUNC(ring_get_gl_pixel_map_s_to_s)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_S_TO_S);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_r)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_R);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_g)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_G);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_b)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_B);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_a)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_A);
}

RING_FUNC(ring_get_gl_pixel_map_r_to_r)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_R_TO_R);
}

RING_FUNC(ring_get_gl_pixel_map_g_to_g)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_G_TO_G);
}

RING_FUNC(ring_get_gl_pixel_map_b_to_b)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_B_TO_B);
}

RING_FUNC(ring_get_gl_pixel_map_a_to_a)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_A_TO_A);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_i_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_I_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_s_to_s_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_S_TO_S_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_r_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_R_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_g_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_G_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_b_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_B_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_i_to_a_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_I_TO_A_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_r_to_r_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_R_TO_R_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_g_to_g_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_G_TO_G_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_b_to_b_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_B_TO_B_SIZE);
}

RING_FUNC(ring_get_gl_pixel_map_a_to_a_size)
{
	RING_API_RETNUMBER(GL_PIXEL_MAP_A_TO_A_SIZE);
}

RING_FUNC(ring_get_gl_unpack_swap_bytes)
{
	RING_API_RETNUMBER(GL_UNPACK_SWAP_BYTES);
}

RING_FUNC(ring_get_gl_unpack_lsb_first)
{
	RING_API_RETNUMBER(GL_UNPACK_LSB_FIRST);
}

RING_FUNC(ring_get_gl_unpack_row_length)
{
	RING_API_RETNUMBER(GL_UNPACK_ROW_LENGTH);
}

RING_FUNC(ring_get_gl_unpack_skip_rows)
{
	RING_API_RETNUMBER(GL_UNPACK_SKIP_ROWS);
}

RING_FUNC(ring_get_gl_unpack_skip_pixels)
{
	RING_API_RETNUMBER(GL_UNPACK_SKIP_PIXELS);
}

RING_FUNC(ring_get_gl_unpack_alignment)
{
	RING_API_RETNUMBER(GL_UNPACK_ALIGNMENT);
}

RING_FUNC(ring_get_gl_pack_swap_bytes)
{
	RING_API_RETNUMBER(GL_PACK_SWAP_BYTES);
}

RING_FUNC(ring_get_gl_pack_lsb_first)
{
	RING_API_RETNUMBER(GL_PACK_LSB_FIRST);
}

RING_FUNC(ring_get_gl_pack_row_length)
{
	RING_API_RETNUMBER(GL_PACK_ROW_LENGTH);
}

RING_FUNC(ring_get_gl_pack_skip_rows)
{
	RING_API_RETNUMBER(GL_PACK_SKIP_ROWS);
}

RING_FUNC(ring_get_gl_pack_skip_pixels)
{
	RING_API_RETNUMBER(GL_PACK_SKIP_PIXELS);
}

RING_FUNC(ring_get_gl_pack_alignment)
{
	RING_API_RETNUMBER(GL_PACK_ALIGNMENT);
}

RING_FUNC(ring_get_gl_map_color)
{
	RING_API_RETNUMBER(GL_MAP_COLOR);
}

RING_FUNC(ring_get_gl_map_stencil)
{
	RING_API_RETNUMBER(GL_MAP_STENCIL);
}

RING_FUNC(ring_get_gl_index_shift)
{
	RING_API_RETNUMBER(GL_INDEX_SHIFT);
}

RING_FUNC(ring_get_gl_index_offset)
{
	RING_API_RETNUMBER(GL_INDEX_OFFSET);
}

RING_FUNC(ring_get_gl_red_scale)
{
	RING_API_RETNUMBER(GL_RED_SCALE);
}

RING_FUNC(ring_get_gl_red_bias)
{
	RING_API_RETNUMBER(GL_RED_BIAS);
}

RING_FUNC(ring_get_gl_zoom_x)
{
	RING_API_RETNUMBER(GL_ZOOM_X);
}

RING_FUNC(ring_get_gl_zoom_y)
{
	RING_API_RETNUMBER(GL_ZOOM_Y);
}

RING_FUNC(ring_get_gl_green_scale)
{
	RING_API_RETNUMBER(GL_GREEN_SCALE);
}

RING_FUNC(ring_get_gl_green_bias)
{
	RING_API_RETNUMBER(GL_GREEN_BIAS);
}

RING_FUNC(ring_get_gl_blue_scale)
{
	RING_API_RETNUMBER(GL_BLUE_SCALE);
}

RING_FUNC(ring_get_gl_blue_bias)
{
	RING_API_RETNUMBER(GL_BLUE_BIAS);
}

RING_FUNC(ring_get_gl_alpha_scale)
{
	RING_API_RETNUMBER(GL_ALPHA_SCALE);
}

RING_FUNC(ring_get_gl_alpha_bias)
{
	RING_API_RETNUMBER(GL_ALPHA_BIAS);
}

RING_FUNC(ring_get_gl_depth_scale)
{
	RING_API_RETNUMBER(GL_DEPTH_SCALE);
}

RING_FUNC(ring_get_gl_depth_bias)
{
	RING_API_RETNUMBER(GL_DEPTH_BIAS);
}

RING_FUNC(ring_get_gl_max_eval_order)
{
	RING_API_RETNUMBER(GL_MAX_EVAL_ORDER);
}

RING_FUNC(ring_get_gl_max_lights)
{
	RING_API_RETNUMBER(GL_MAX_LIGHTS);
}

RING_FUNC(ring_get_gl_max_clip_planes)
{
	RING_API_RETNUMBER(GL_MAX_CLIP_PLANES);
}

RING_FUNC(ring_get_gl_max_texture_size)
{
	RING_API_RETNUMBER(GL_MAX_TEXTURE_SIZE);
}

RING_FUNC(ring_get_gl_max_pixel_map_table)
{
	RING_API_RETNUMBER(GL_MAX_PIXEL_MAP_TABLE);
}

RING_FUNC(ring_get_gl_max_attrib_stack_depth)
{
	RING_API_RETNUMBER(GL_MAX_ATTRIB_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_max_modelview_stack_depth)
{
	RING_API_RETNUMBER(GL_MAX_MODELVIEW_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_max_name_stack_depth)
{
	RING_API_RETNUMBER(GL_MAX_NAME_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_max_projection_stack_depth)
{
	RING_API_RETNUMBER(GL_MAX_PROJECTION_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_max_texture_stack_depth)
{
	RING_API_RETNUMBER(GL_MAX_TEXTURE_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_max_viewport_dims)
{
	RING_API_RETNUMBER(GL_MAX_VIEWPORT_DIMS);
}

RING_FUNC(ring_get_gl_max_client_attrib_stack_depth)
{
	RING_API_RETNUMBER(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_subpixel_bits)
{
	RING_API_RETNUMBER(GL_SUBPIXEL_BITS);
}

RING_FUNC(ring_get_gl_index_bits)
{
	RING_API_RETNUMBER(GL_INDEX_BITS);
}

RING_FUNC(ring_get_gl_red_bits)
{
	RING_API_RETNUMBER(GL_RED_BITS);
}

RING_FUNC(ring_get_gl_green_bits)
{
	RING_API_RETNUMBER(GL_GREEN_BITS);
}

RING_FUNC(ring_get_gl_blue_bits)
{
	RING_API_RETNUMBER(GL_BLUE_BITS);
}

RING_FUNC(ring_get_gl_alpha_bits)
{
	RING_API_RETNUMBER(GL_ALPHA_BITS);
}

RING_FUNC(ring_get_gl_depth_bits)
{
	RING_API_RETNUMBER(GL_DEPTH_BITS);
}

RING_FUNC(ring_get_gl_stencil_bits)
{
	RING_API_RETNUMBER(GL_STENCIL_BITS);
}

RING_FUNC(ring_get_gl_accum_red_bits)
{
	RING_API_RETNUMBER(GL_ACCUM_RED_BITS);
}

RING_FUNC(ring_get_gl_accum_green_bits)
{
	RING_API_RETNUMBER(GL_ACCUM_GREEN_BITS);
}

RING_FUNC(ring_get_gl_accum_blue_bits)
{
	RING_API_RETNUMBER(GL_ACCUM_BLUE_BITS);
}

RING_FUNC(ring_get_gl_accum_alpha_bits)
{
	RING_API_RETNUMBER(GL_ACCUM_ALPHA_BITS);
}

RING_FUNC(ring_get_gl_name_stack_depth)
{
	RING_API_RETNUMBER(GL_NAME_STACK_DEPTH);
}

RING_FUNC(ring_get_gl_auto_normal)
{
	RING_API_RETNUMBER(GL_AUTO_NORMAL);
}

RING_FUNC(ring_get_gl_map1_color_4)
{
	RING_API_RETNUMBER(GL_MAP1_COLOR_4);
}

RING_FUNC(ring_get_gl_map1_index)
{
	RING_API_RETNUMBER(GL_MAP1_INDEX);
}

RING_FUNC(ring_get_gl_map1_normal)
{
	RING_API_RETNUMBER(GL_MAP1_NORMAL);
}

RING_FUNC(ring_get_gl_map1_texture_coord_1)
{
	RING_API_RETNUMBER(GL_MAP1_TEXTURE_COORD_1);
}

RING_FUNC(ring_get_gl_map1_texture_coord_2)
{
	RING_API_RETNUMBER(GL_MAP1_TEXTURE_COORD_2);
}

RING_FUNC(ring_get_gl_map1_texture_coord_3)
{
	RING_API_RETNUMBER(GL_MAP1_TEXTURE_COORD_3);
}

RING_FUNC(ring_get_gl_map1_texture_coord_4)
{
	RING_API_RETNUMBER(GL_MAP1_TEXTURE_COORD_4);
}

RING_FUNC(ring_get_gl_map1_vertex_3)
{
	RING_API_RETNUMBER(GL_MAP1_VERTEX_3);
}

RING_FUNC(ring_get_gl_map1_vertex_4)
{
	RING_API_RETNUMBER(GL_MAP1_VERTEX_4);
}

RING_FUNC(ring_get_gl_map2_color_4)
{
	RING_API_RETNUMBER(GL_MAP2_COLOR_4);
}

RING_FUNC(ring_get_gl_map2_index)
{
	RING_API_RETNUMBER(GL_MAP2_INDEX);
}

RING_FUNC(ring_get_gl_map2_normal)
{
	RING_API_RETNUMBER(GL_MAP2_NORMAL);
}

RING_FUNC(ring_get_gl_map2_texture_coord_1)
{
	RING_API_RETNUMBER(GL_MAP2_TEXTURE_COORD_1);
}

RING_FUNC(ring_get_gl_map2_texture_coord_2)
{
	RING_API_RETNUMBER(GL_MAP2_TEXTURE_COORD_2);
}

RING_FUNC(ring_get_gl_map2_texture_coord_3)
{
	RING_API_RETNUMBER(GL_MAP2_TEXTURE_COORD_3);
}

RING_FUNC(ring_get_gl_map2_texture_coord_4)
{
	RING_API_RETNUMBER(GL_MAP2_TEXTURE_COORD_4);
}

RING_FUNC(ring_get_gl_map2_vertex_3)
{
	RING_API_RETNUMBER(GL_MAP2_VERTEX_3);
}

RING_FUNC(ring_get_gl_map2_vertex_4)
{
	RING_API_RETNUMBER(GL_MAP2_VERTEX_4);
}

RING_FUNC(ring_get_gl_map1_grid_domain)
{
	RING_API_RETNUMBER(GL_MAP1_GRID_DOMAIN);
}

RING_FUNC(ring_get_gl_map1_grid_segments)
{
	RING_API_RETNUMBER(GL_MAP1_GRID_SEGMENTS);
}

RING_FUNC(ring_get_gl_map2_grid_domain)
{
	RING_API_RETNUMBER(GL_MAP2_GRID_DOMAIN);
}

RING_FUNC(ring_get_gl_map2_grid_segments)
{
	RING_API_RETNUMBER(GL_MAP2_GRID_SEGMENTS);
}

RING_FUNC(ring_get_gl_texture_1d)
{
	RING_API_RETNUMBER(GL_TEXTURE_1D);
}

RING_FUNC(ring_get_gl_texture_2d)
{
	RING_API_RETNUMBER(GL_TEXTURE_2D);
}

RING_FUNC(ring_get_gl_feedback_buffer_pointer)
{
	RING_API_RETNUMBER(GL_FEEDBACK_BUFFER_POINTER);
}

RING_FUNC(ring_get_gl_feedback_buffer_size)
{
	RING_API_RETNUMBER(GL_FEEDBACK_BUFFER_SIZE);
}

RING_FUNC(ring_get_gl_feedback_buffer_type)
{
	RING_API_RETNUMBER(GL_FEEDBACK_BUFFER_TYPE);
}

RING_FUNC(ring_get_gl_selection_buffer_pointer)
{
	RING_API_RETNUMBER(GL_SELECTION_BUFFER_POINTER);
}

RING_FUNC(ring_get_gl_selection_buffer_size)
{
	RING_API_RETNUMBER(GL_SELECTION_BUFFER_SIZE);
}

RING_FUNC(ring_get_gl_texture_width)
{
	RING_API_RETNUMBER(GL_TEXTURE_WIDTH);
}

RING_FUNC(ring_get_gl_transform_bit)
{
	RING_API_RETNUMBER(GL_TRANSFORM_BIT);
}

RING_FUNC(ring_get_gl_texture_height)
{
	RING_API_RETNUMBER(GL_TEXTURE_HEIGHT);
}

RING_FUNC(ring_get_gl_texture_internal_format)
{
	RING_API_RETNUMBER(GL_TEXTURE_INTERNAL_FORMAT);
}

RING_FUNC(ring_get_gl_texture_border_color)
{
	RING_API_RETNUMBER(GL_TEXTURE_BORDER_COLOR);
}

RING_FUNC(ring_get_gl_texture_border)
{
	RING_API_RETNUMBER(GL_TEXTURE_BORDER);
}

RING_FUNC(ring_get_gl_dont_care)
{
	RING_API_RETNUMBER(GL_DONT_CARE);
}

RING_FUNC(ring_get_gl_fastest)
{
	RING_API_RETNUMBER(GL_FASTEST);
}

RING_FUNC(ring_get_gl_nicest)
{
	RING_API_RETNUMBER(GL_NICEST);
}

RING_FUNC(ring_get_gl_ambient)
{
	RING_API_RETNUMBER(GL_AMBIENT);
}

RING_FUNC(ring_get_gl_diffuse)
{
	RING_API_RETNUMBER(GL_DIFFUSE);
}

RING_FUNC(ring_get_gl_specular)
{
	RING_API_RETNUMBER(GL_SPECULAR);
}

RING_FUNC(ring_get_gl_position)
{
	RING_API_RETNUMBER(GL_POSITION);
}

RING_FUNC(ring_get_gl_spot_direction)
{
	RING_API_RETNUMBER(GL_SPOT_DIRECTION);
}

RING_FUNC(ring_get_gl_spot_exponent)
{
	RING_API_RETNUMBER(GL_SPOT_EXPONENT);
}

RING_FUNC(ring_get_gl_spot_cutoff)
{
	RING_API_RETNUMBER(GL_SPOT_CUTOFF);
}

RING_FUNC(ring_get_gl_constant_attenuation)
{
	RING_API_RETNUMBER(GL_CONSTANT_ATTENUATION);
}

RING_FUNC(ring_get_gl_linear_attenuation)
{
	RING_API_RETNUMBER(GL_LINEAR_ATTENUATION);
}

RING_FUNC(ring_get_gl_quadratic_attenuation)
{
	RING_API_RETNUMBER(GL_QUADRATIC_ATTENUATION);
}

RING_FUNC(ring_get_gl_compile)
{
	RING_API_RETNUMBER(GL_COMPILE);
}

RING_FUNC(ring_get_gl_compile_and_execute)
{
	RING_API_RETNUMBER(GL_COMPILE_AND_EXECUTE);
}

RING_FUNC(ring_get_gl_byte)
{
	RING_API_RETNUMBER(GL_BYTE);
}

RING_FUNC(ring_get_gl_unsigned_byte)
{
	RING_API_RETNUMBER(GL_UNSIGNED_BYTE);
}

RING_FUNC(ring_get_gl_short)
{
	RING_API_RETNUMBER(GL_SHORT);
}

RING_FUNC(ring_get_gl_unsigned_short)
{
	RING_API_RETNUMBER(GL_UNSIGNED_SHORT);
}

RING_FUNC(ring_get_gl_int)
{
	RING_API_RETNUMBER(GL_INT);
}

RING_FUNC(ring_get_gl_unsigned_int)
{
	RING_API_RETNUMBER(GL_UNSIGNED_INT);
}

RING_FUNC(ring_get_gl_float)
{
	RING_API_RETNUMBER(GL_FLOAT);
}

RING_FUNC(ring_get_gl_2_bytes)
{
	RING_API_RETNUMBER(GL_2_BYTES);
}

RING_FUNC(ring_get_gl_3_bytes)
{
	RING_API_RETNUMBER(GL_3_BYTES);
}

RING_FUNC(ring_get_gl_4_bytes)
{
	RING_API_RETNUMBER(GL_4_BYTES);
}

RING_FUNC(ring_get_gl_double)
{
	RING_API_RETNUMBER(GL_DOUBLE);
}

RING_FUNC(ring_get_gl_clear)
{
	RING_API_RETNUMBER(GL_CLEAR);
}

RING_FUNC(ring_get_gl_and)
{
	RING_API_RETNUMBER(GL_AND);
}

RING_FUNC(ring_get_gl_and_reverse)
{
	RING_API_RETNUMBER(GL_AND_REVERSE);
}

RING_FUNC(ring_get_gl_copy)
{
	RING_API_RETNUMBER(GL_COPY);
}

RING_FUNC(ring_get_gl_and_inverted)
{
	RING_API_RETNUMBER(GL_AND_INVERTED);
}

RING_FUNC(ring_get_gl_noop)
{
	RING_API_RETNUMBER(GL_NOOP);
}

RING_FUNC(ring_get_gl_xor)
{
	RING_API_RETNUMBER(GL_XOR);
}

RING_FUNC(ring_get_gl_or)
{
	RING_API_RETNUMBER(GL_OR);
}

RING_FUNC(ring_get_gl_nor)
{
	RING_API_RETNUMBER(GL_NOR);
}

RING_FUNC(ring_get_gl_equiv)
{
	RING_API_RETNUMBER(GL_EQUIV);
}

RING_FUNC(ring_get_gl_invert)
{
	RING_API_RETNUMBER(GL_INVERT);
}

RING_FUNC(ring_get_gl_or_reverse)
{
	RING_API_RETNUMBER(GL_OR_REVERSE);
}

RING_FUNC(ring_get_gl_copy_inverted)
{
	RING_API_RETNUMBER(GL_COPY_INVERTED);
}

RING_FUNC(ring_get_gl_or_inverted)
{
	RING_API_RETNUMBER(GL_OR_INVERTED);
}

RING_FUNC(ring_get_gl_nand)
{
	RING_API_RETNUMBER(GL_NAND);
}

RING_FUNC(ring_get_gl_set)
{
	RING_API_RETNUMBER(GL_SET);
}

RING_FUNC(ring_get_gl_emission)
{
	RING_API_RETNUMBER(GL_EMISSION);
}

RING_FUNC(ring_get_gl_shininess)
{
	RING_API_RETNUMBER(GL_SHININESS);
}

RING_FUNC(ring_get_gl_ambient_and_diffuse)
{
	RING_API_RETNUMBER(GL_AMBIENT_AND_DIFFUSE);
}

RING_FUNC(ring_get_gl_color_indexes)
{
	RING_API_RETNUMBER(GL_COLOR_INDEXES);
}

RING_FUNC(ring_get_gl_modelview)
{
	RING_API_RETNUMBER(GL_MODELVIEW);
}

RING_FUNC(ring_get_gl_projection)
{
	RING_API_RETNUMBER(GL_PROJECTION);
}

RING_FUNC(ring_get_gl_texture)
{
	RING_API_RETNUMBER(GL_TEXTURE);
}

RING_FUNC(ring_get_gl_color)
{
	RING_API_RETNUMBER(GL_COLOR);
}

RING_FUNC(ring_get_gl_depth)
{
	RING_API_RETNUMBER(GL_DEPTH);
}

RING_FUNC(ring_get_gl_stencil)
{
	RING_API_RETNUMBER(GL_STENCIL);
}

RING_FUNC(ring_get_gl_color_index)
{
	RING_API_RETNUMBER(GL_COLOR_INDEX);
}

RING_FUNC(ring_get_gl_stencil_index)
{
	RING_API_RETNUMBER(GL_STENCIL_INDEX);
}

RING_FUNC(ring_get_gl_depth_component)
{
	RING_API_RETNUMBER(GL_DEPTH_COMPONENT);
}

RING_FUNC(ring_get_gl_red)
{
	RING_API_RETNUMBER(GL_RED);
}

RING_FUNC(ring_get_gl_green)
{
	RING_API_RETNUMBER(GL_GREEN);
}

RING_FUNC(ring_get_gl_blue)
{
	RING_API_RETNUMBER(GL_BLUE);
}

RING_FUNC(ring_get_gl_alpha)
{
	RING_API_RETNUMBER(GL_ALPHA);
}

RING_FUNC(ring_get_gl_rgb)
{
	RING_API_RETNUMBER(GL_RGB);
}

RING_FUNC(ring_get_gl_rgba)
{
	RING_API_RETNUMBER(GL_RGBA);
}

RING_FUNC(ring_get_gl_luminance)
{
	RING_API_RETNUMBER(GL_LUMINANCE);
}

RING_FUNC(ring_get_gl_luminance_alpha)
{
	RING_API_RETNUMBER(GL_LUMINANCE_ALPHA);
}

RING_FUNC(ring_get_gl_bitmap)
{
	RING_API_RETNUMBER(GL_BITMAP);
}

RING_FUNC(ring_get_gl_point)
{
	RING_API_RETNUMBER(GL_POINT);
}

RING_FUNC(ring_get_gl_line)
{
	RING_API_RETNUMBER(GL_LINE);
}

RING_FUNC(ring_get_gl_fill)
{
	RING_API_RETNUMBER(GL_FILL);
}

RING_FUNC(ring_get_gl_render)
{
	RING_API_RETNUMBER(GL_RENDER);
}

RING_FUNC(ring_get_gl_feedback)
{
	RING_API_RETNUMBER(GL_FEEDBACK);
}

RING_FUNC(ring_get_gl_select)
{
	RING_API_RETNUMBER(GL_SELECT);
}

RING_FUNC(ring_get_gl_flat)
{
	RING_API_RETNUMBER(GL_FLAT);
}

RING_FUNC(ring_get_gl_smooth)
{
	RING_API_RETNUMBER(GL_SMOOTH);
}

RING_FUNC(ring_get_gl_keep)
{
	RING_API_RETNUMBER(GL_KEEP);
}

RING_FUNC(ring_get_gl_replace)
{
	RING_API_RETNUMBER(GL_REPLACE);
}

RING_FUNC(ring_get_gl_incr)
{
	RING_API_RETNUMBER(GL_INCR);
}

RING_FUNC(ring_get_gl_decr)
{
	RING_API_RETNUMBER(GL_DECR);
}

RING_FUNC(ring_get_gl_vendor)
{
	RING_API_RETNUMBER(GL_VENDOR);
}

RING_FUNC(ring_get_gl_renderer)
{
	RING_API_RETNUMBER(GL_RENDERER);
}

RING_FUNC(ring_get_gl_version)
{
	RING_API_RETNUMBER(GL_VERSION);
}

RING_FUNC(ring_get_gl_extensions)
{
	RING_API_RETNUMBER(GL_EXTENSIONS);
}

RING_FUNC(ring_get_gl_s)
{
	RING_API_RETNUMBER(GL_S);
}

RING_FUNC(ring_get_gl_enable_bit)
{
	RING_API_RETNUMBER(GL_ENABLE_BIT);
}

RING_FUNC(ring_get_gl_t)
{
	RING_API_RETNUMBER(GL_T);
}

RING_FUNC(ring_get_gl_r)
{
	RING_API_RETNUMBER(GL_R);
}

RING_FUNC(ring_get_gl_q)
{
	RING_API_RETNUMBER(GL_Q);
}

RING_FUNC(ring_get_gl_modulate)
{
	RING_API_RETNUMBER(GL_MODULATE);
}

RING_FUNC(ring_get_gl_decal)
{
	RING_API_RETNUMBER(GL_DECAL);
}

RING_FUNC(ring_get_gl_texture_env_mode)
{
	RING_API_RETNUMBER(GL_TEXTURE_ENV_MODE);
}

RING_FUNC(ring_get_gl_texture_env_color)
{
	RING_API_RETNUMBER(GL_TEXTURE_ENV_COLOR);
}

RING_FUNC(ring_get_gl_texture_env)
{
	RING_API_RETNUMBER(GL_TEXTURE_ENV);
}

RING_FUNC(ring_get_gl_eye_linear)
{
	RING_API_RETNUMBER(GL_EYE_LINEAR);
}

RING_FUNC(ring_get_gl_object_linear)
{
	RING_API_RETNUMBER(GL_OBJECT_LINEAR);
}

RING_FUNC(ring_get_gl_sphere_map)
{
	RING_API_RETNUMBER(GL_SPHERE_MAP);
}

RING_FUNC(ring_get_gl_texture_gen_mode)
{
	RING_API_RETNUMBER(GL_TEXTURE_GEN_MODE);
}

RING_FUNC(ring_get_gl_object_plane)
{
	RING_API_RETNUMBER(GL_OBJECT_PLANE);
}

RING_FUNC(ring_get_gl_eye_plane)
{
	RING_API_RETNUMBER(GL_EYE_PLANE);
}

RING_FUNC(ring_get_gl_nearest)
{
	RING_API_RETNUMBER(GL_NEAREST);
}

RING_FUNC(ring_get_gl_linear)
{
	RING_API_RETNUMBER(GL_LINEAR);
}

RING_FUNC(ring_get_gl_nearest_mipmap_nearest)
{
	RING_API_RETNUMBER(GL_NEAREST_MIPMAP_NEAREST);
}

RING_FUNC(ring_get_gl_linear_mipmap_nearest)
{
	RING_API_RETNUMBER(GL_LINEAR_MIPMAP_NEAREST);
}

RING_FUNC(ring_get_gl_nearest_mipmap_linear)
{
	RING_API_RETNUMBER(GL_NEAREST_MIPMAP_LINEAR);
}

RING_FUNC(ring_get_gl_linear_mipmap_linear)
{
	RING_API_RETNUMBER(GL_LINEAR_MIPMAP_LINEAR);
}

RING_FUNC(ring_get_gl_texture_mag_filter)
{
	RING_API_RETNUMBER(GL_TEXTURE_MAG_FILTER);
}

RING_FUNC(ring_get_gl_texture_min_filter)
{
	RING_API_RETNUMBER(GL_TEXTURE_MIN_FILTER);
}

RING_FUNC(ring_get_gl_texture_wrap_s)
{
	RING_API_RETNUMBER(GL_TEXTURE_WRAP_S);
}

RING_FUNC(ring_get_gl_texture_wrap_t)
{
	RING_API_RETNUMBER(GL_TEXTURE_WRAP_T);
}

RING_FUNC(ring_get_gl_clamp)
{
	RING_API_RETNUMBER(GL_CLAMP);
}

RING_FUNC(ring_get_gl_repeat)
{
	RING_API_RETNUMBER(GL_REPEAT);
}

RING_FUNC(ring_get_gl_polygon_offset_units)
{
	RING_API_RETNUMBER(GL_POLYGON_OFFSET_UNITS);
}

RING_FUNC(ring_get_gl_polygon_offset_point)
{
	RING_API_RETNUMBER(GL_POLYGON_OFFSET_POINT);
}

RING_FUNC(ring_get_gl_polygon_offset_line)
{
	RING_API_RETNUMBER(GL_POLYGON_OFFSET_LINE);
}

RING_FUNC(ring_get_gl_r3_g3_b2)
{
	RING_API_RETNUMBER(GL_R3_G3_B2);
}

RING_FUNC(ring_get_gl_v2f)
{
	RING_API_RETNUMBER(GL_V2F);
}

RING_FUNC(ring_get_gl_v3f)
{
	RING_API_RETNUMBER(GL_V3F);
}

RING_FUNC(ring_get_gl_c4ub_v2f)
{
	RING_API_RETNUMBER(GL_C4UB_V2F);
}

RING_FUNC(ring_get_gl_c4ub_v3f)
{
	RING_API_RETNUMBER(GL_C4UB_V3F);
}

RING_FUNC(ring_get_gl_c3f_v3f)
{
	RING_API_RETNUMBER(GL_C3F_V3F);
}

RING_FUNC(ring_get_gl_n3f_v3f)
{
	RING_API_RETNUMBER(GL_N3F_V3F);
}

RING_FUNC(ring_get_gl_c4f_n3f_v3f)
{
	RING_API_RETNUMBER(GL_C4F_N3F_V3F);
}

RING_FUNC(ring_get_gl_t2f_v3f)
{
	RING_API_RETNUMBER(GL_T2F_V3F);
}

RING_FUNC(ring_get_gl_t4f_v4f)
{
	RING_API_RETNUMBER(GL_T4F_V4F);
}

RING_FUNC(ring_get_gl_t2f_c4ub_v3f)
{
	RING_API_RETNUMBER(GL_T2F_C4UB_V3F);
}

RING_FUNC(ring_get_gl_t2f_c3f_v3f)
{
	RING_API_RETNUMBER(GL_T2F_C3F_V3F);
}

RING_FUNC(ring_get_gl_t2f_n3f_v3f)
{
	RING_API_RETNUMBER(GL_T2F_N3F_V3F);
}

RING_FUNC(ring_get_gl_t2f_c4f_n3f_v3f)
{
	RING_API_RETNUMBER(GL_T2F_C4F_N3F_V3F);
}

RING_FUNC(ring_get_gl_t4f_c4f_n3f_v4f)
{
	RING_API_RETNUMBER(GL_T4F_C4F_N3F_V4F);
}

RING_FUNC(ring_get_gl_clip_plane0)
{
	RING_API_RETNUMBER(GL_CLIP_PLANE0);
}

RING_FUNC(ring_get_gl_clip_plane1)
{
	RING_API_RETNUMBER(GL_CLIP_PLANE1);
}

RING_FUNC(ring_get_gl_clip_plane2)
{
	RING_API_RETNUMBER(GL_CLIP_PLANE2);
}

RING_FUNC(ring_get_gl_clip_plane3)
{
	RING_API_RETNUMBER(GL_CLIP_PLANE3);
}

RING_FUNC(ring_get_gl_clip_plane4)
{
	RING_API_RETNUMBER(GL_CLIP_PLANE4);
}

RING_FUNC(ring_get_gl_clip_plane5)
{
	RING_API_RETNUMBER(GL_CLIP_PLANE5);
}

RING_FUNC(ring_get_gl_light0)
{
	RING_API_RETNUMBER(GL_LIGHT0);
}

RING_FUNC(ring_get_gl_color_buffer_bit)
{
	RING_API_RETNUMBER(GL_COLOR_BUFFER_BIT);
}

RING_FUNC(ring_get_gl_light1)
{
	RING_API_RETNUMBER(GL_LIGHT1);
}

RING_FUNC(ring_get_gl_light2)
{
	RING_API_RETNUMBER(GL_LIGHT2);
}

RING_FUNC(ring_get_gl_light3)
{
	RING_API_RETNUMBER(GL_LIGHT3);
}

RING_FUNC(ring_get_gl_light4)
{
	RING_API_RETNUMBER(GL_LIGHT4);
}

RING_FUNC(ring_get_gl_light5)
{
	RING_API_RETNUMBER(GL_LIGHT5);
}

RING_FUNC(ring_get_gl_light6)
{
	RING_API_RETNUMBER(GL_LIGHT6);
}

RING_FUNC(ring_get_gl_light7)
{
	RING_API_RETNUMBER(GL_LIGHT7);
}

RING_FUNC(ring_get_gl_hint_bit)
{
	RING_API_RETNUMBER(GL_HINT_BIT);
}

RING_FUNC(ring_get_gl_polygon_offset_fill)
{
	RING_API_RETNUMBER(GL_POLYGON_OFFSET_FILL);
}

RING_FUNC(ring_get_gl_polygon_offset_factor)
{
	RING_API_RETNUMBER(GL_POLYGON_OFFSET_FACTOR);
}

RING_FUNC(ring_get_gl_alpha4)
{
	RING_API_RETNUMBER(GL_ALPHA4);
}

RING_FUNC(ring_get_gl_alpha8)
{
	RING_API_RETNUMBER(GL_ALPHA8);
}

RING_FUNC(ring_get_gl_alpha12)
{
	RING_API_RETNUMBER(GL_ALPHA12);
}

RING_FUNC(ring_get_gl_alpha16)
{
	RING_API_RETNUMBER(GL_ALPHA16);
}

RING_FUNC(ring_get_gl_luminance4)
{
	RING_API_RETNUMBER(GL_LUMINANCE4);
}

RING_FUNC(ring_get_gl_luminance8)
{
	RING_API_RETNUMBER(GL_LUMINANCE8);
}

RING_FUNC(ring_get_gl_luminance12)
{
	RING_API_RETNUMBER(GL_LUMINANCE12);
}

RING_FUNC(ring_get_gl_luminance16)
{
	RING_API_RETNUMBER(GL_LUMINANCE16);
}

RING_FUNC(ring_get_gl_luminance4_alpha4)
{
	RING_API_RETNUMBER(GL_LUMINANCE4_ALPHA4);
}

RING_FUNC(ring_get_gl_luminance6_alpha2)
{
	RING_API_RETNUMBER(GL_LUMINANCE6_ALPHA2);
}

RING_FUNC(ring_get_gl_luminance8_alpha8)
{
	RING_API_RETNUMBER(GL_LUMINANCE8_ALPHA8);
}

RING_FUNC(ring_get_gl_luminance12_alpha4)
{
	RING_API_RETNUMBER(GL_LUMINANCE12_ALPHA4);
}

RING_FUNC(ring_get_gl_luminance12_alpha12)
{
	RING_API_RETNUMBER(GL_LUMINANCE12_ALPHA12);
}

RING_FUNC(ring_get_gl_luminance16_alpha16)
{
	RING_API_RETNUMBER(GL_LUMINANCE16_ALPHA16);
}

RING_FUNC(ring_get_gl_intensity)
{
	RING_API_RETNUMBER(GL_INTENSITY);
}

RING_FUNC(ring_get_gl_intensity4)
{
	RING_API_RETNUMBER(GL_INTENSITY4);
}

RING_FUNC(ring_get_gl_intensity8)
{
	RING_API_RETNUMBER(GL_INTENSITY8);
}

RING_FUNC(ring_get_gl_intensity12)
{
	RING_API_RETNUMBER(GL_INTENSITY12);
}

RING_FUNC(ring_get_gl_intensity16)
{
	RING_API_RETNUMBER(GL_INTENSITY16);
}

RING_FUNC(ring_get_gl_rgb4)
{
	RING_API_RETNUMBER(GL_RGB4);
}

RING_FUNC(ring_get_gl_rgb5)
{
	RING_API_RETNUMBER(GL_RGB5);
}

RING_FUNC(ring_get_gl_rgb8)
{
	RING_API_RETNUMBER(GL_RGB8);
}

RING_FUNC(ring_get_gl_rgb10)
{
	RING_API_RETNUMBER(GL_RGB10);
}

RING_FUNC(ring_get_gl_rgb12)
{
	RING_API_RETNUMBER(GL_RGB12);
}

RING_FUNC(ring_get_gl_rgb16)
{
	RING_API_RETNUMBER(GL_RGB16);
}

RING_FUNC(ring_get_gl_rgba2)
{
	RING_API_RETNUMBER(GL_RGBA2);
}

RING_FUNC(ring_get_gl_rgba4)
{
	RING_API_RETNUMBER(GL_RGBA4);
}

RING_FUNC(ring_get_gl_rgb5_a1)
{
	RING_API_RETNUMBER(GL_RGB5_A1);
}

RING_FUNC(ring_get_gl_rgba8)
{
	RING_API_RETNUMBER(GL_RGBA8);
}

RING_FUNC(ring_get_gl_rgb10_a2)
{
	RING_API_RETNUMBER(GL_RGB10_A2);
}

RING_FUNC(ring_get_gl_rgba12)
{
	RING_API_RETNUMBER(GL_RGBA12);
}

RING_FUNC(ring_get_gl_rgba16)
{
	RING_API_RETNUMBER(GL_RGBA16);
}

RING_FUNC(ring_get_gl_texture_red_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_RED_SIZE);
}

RING_FUNC(ring_get_gl_texture_green_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_GREEN_SIZE);
}

RING_FUNC(ring_get_gl_texture_blue_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_BLUE_SIZE);
}

RING_FUNC(ring_get_gl_texture_alpha_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_ALPHA_SIZE);
}

RING_FUNC(ring_get_gl_texture_luminance_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_LUMINANCE_SIZE);
}

RING_FUNC(ring_get_gl_texture_intensity_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_INTENSITY_SIZE);
}

RING_FUNC(ring_get_gl_proxy_texture_1d)
{
	RING_API_RETNUMBER(GL_PROXY_TEXTURE_1D);
}

RING_FUNC(ring_get_gl_proxy_texture_2d)
{
	RING_API_RETNUMBER(GL_PROXY_TEXTURE_2D);
}

RING_FUNC(ring_get_gl_texture_priority)
{
	RING_API_RETNUMBER(GL_TEXTURE_PRIORITY);
}

RING_FUNC(ring_get_gl_texture_resident)
{
	RING_API_RETNUMBER(GL_TEXTURE_RESIDENT);
}

RING_FUNC(ring_get_gl_texture_binding_1d)
{
	RING_API_RETNUMBER(GL_TEXTURE_BINDING_1D);
}

RING_FUNC(ring_get_gl_texture_binding_2d)
{
	RING_API_RETNUMBER(GL_TEXTURE_BINDING_2D);
}

RING_FUNC(ring_get_gl_vertex_array)
{
	RING_API_RETNUMBER(GL_VERTEX_ARRAY);
}

RING_FUNC(ring_get_gl_normal_array)
{
	RING_API_RETNUMBER(GL_NORMAL_ARRAY);
}

RING_FUNC(ring_get_gl_color_array)
{
	RING_API_RETNUMBER(GL_COLOR_ARRAY);
}

RING_FUNC(ring_get_gl_index_array)
{
	RING_API_RETNUMBER(GL_INDEX_ARRAY);
}

RING_FUNC(ring_get_gl_texture_coord_array)
{
	RING_API_RETNUMBER(GL_TEXTURE_COORD_ARRAY);
}

RING_FUNC(ring_get_gl_edge_flag_array)
{
	RING_API_RETNUMBER(GL_EDGE_FLAG_ARRAY);
}

RING_FUNC(ring_get_gl_vertex_array_size)
{
	RING_API_RETNUMBER(GL_VERTEX_ARRAY_SIZE);
}

RING_FUNC(ring_get_gl_vertex_array_type)
{
	RING_API_RETNUMBER(GL_VERTEX_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_vertex_array_stride)
{
	RING_API_RETNUMBER(GL_VERTEX_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_normal_array_type)
{
	RING_API_RETNUMBER(GL_NORMAL_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_normal_array_stride)
{
	RING_API_RETNUMBER(GL_NORMAL_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_color_array_size)
{
	RING_API_RETNUMBER(GL_COLOR_ARRAY_SIZE);
}

RING_FUNC(ring_get_gl_color_array_type)
{
	RING_API_RETNUMBER(GL_COLOR_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_color_array_stride)
{
	RING_API_RETNUMBER(GL_COLOR_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_index_array_type)
{
	RING_API_RETNUMBER(GL_INDEX_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_index_array_stride)
{
	RING_API_RETNUMBER(GL_INDEX_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_texture_coord_array_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_COORD_ARRAY_SIZE);
}

RING_FUNC(ring_get_gl_texture_coord_array_type)
{
	RING_API_RETNUMBER(GL_TEXTURE_COORD_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_texture_coord_array_stride)
{
	RING_API_RETNUMBER(GL_TEXTURE_COORD_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_edge_flag_array_stride)
{
	RING_API_RETNUMBER(GL_EDGE_FLAG_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_vertex_array_pointer)
{
	RING_API_RETNUMBER(GL_VERTEX_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_normal_array_pointer)
{
	RING_API_RETNUMBER(GL_NORMAL_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_color_array_pointer)
{
	RING_API_RETNUMBER(GL_COLOR_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_index_array_pointer)
{
	RING_API_RETNUMBER(GL_INDEX_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_texture_coord_array_pointer)
{
	RING_API_RETNUMBER(GL_TEXTURE_COORD_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_edge_flag_array_pointer)
{
	RING_API_RETNUMBER(GL_EDGE_FLAG_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_color_index1_ext)
{
	RING_API_RETNUMBER(GL_COLOR_INDEX1_EXT);
}

RING_FUNC(ring_get_gl_color_index2_ext)
{
	RING_API_RETNUMBER(GL_COLOR_INDEX2_EXT);
}

RING_FUNC(ring_get_gl_color_index4_ext)
{
	RING_API_RETNUMBER(GL_COLOR_INDEX4_EXT);
}

RING_FUNC(ring_get_gl_color_index8_ext)
{
	RING_API_RETNUMBER(GL_COLOR_INDEX8_EXT);
}

RING_FUNC(ring_get_gl_color_index12_ext)
{
	RING_API_RETNUMBER(GL_COLOR_INDEX12_EXT);
}

RING_FUNC(ring_get_gl_color_index16_ext)
{
	RING_API_RETNUMBER(GL_COLOR_INDEX16_EXT);
}

RING_FUNC(ring_get_gl_eval_bit)
{
	RING_API_RETNUMBER(GL_EVAL_BIT);
}

RING_FUNC(ring_get_gl_list_bit)
{
	RING_API_RETNUMBER(GL_LIST_BIT);
}

RING_FUNC(ring_get_gl_texture_bit)
{
	RING_API_RETNUMBER(GL_TEXTURE_BIT);
}

RING_FUNC(ring_get_gl_scissor_bit)
{
	RING_API_RETNUMBER(GL_SCISSOR_BIT);
}

RING_FUNC(ring_get_gl_all_attrib_bits)
{
	RING_API_RETNUMBER(GL_ALL_ATTRIB_BITS);
}

RING_FUNC(ring_get_gl_client_all_attrib_bits)
{
	RING_API_RETNUMBER(GL_CLIENT_ALL_ATTRIB_BITS);
}

RING_FUNC(ring_get_gl_smooth_point_size_range)
{
	RING_API_RETNUMBER(GL_SMOOTH_POINT_SIZE_RANGE);
}

RING_FUNC(ring_get_gl_smooth_point_size_granularity)
{
	RING_API_RETNUMBER(GL_SMOOTH_POINT_SIZE_GRANULARITY);
}

RING_FUNC(ring_get_gl_smooth_line_width_range)
{
	RING_API_RETNUMBER(GL_SMOOTH_LINE_WIDTH_RANGE);
}

RING_FUNC(ring_get_gl_smooth_line_width_granularity)
{
	RING_API_RETNUMBER(GL_SMOOTH_LINE_WIDTH_GRANULARITY);
}

RING_FUNC(ring_get_gl_unsigned_byte_3_3_2)
{
	RING_API_RETNUMBER(GL_UNSIGNED_BYTE_3_3_2);
}

RING_FUNC(ring_get_gl_unsigned_short_4_4_4_4)
{
	RING_API_RETNUMBER(GL_UNSIGNED_SHORT_4_4_4_4);
}

RING_FUNC(ring_get_gl_unsigned_short_5_5_5_1)
{
	RING_API_RETNUMBER(GL_UNSIGNED_SHORT_5_5_5_1);
}

RING_FUNC(ring_get_gl_unsigned_int_8_8_8_8)
{
	RING_API_RETNUMBER(GL_UNSIGNED_INT_8_8_8_8);
}

RING_FUNC(ring_get_gl_unsigned_int_10_10_10_2)
{
	RING_API_RETNUMBER(GL_UNSIGNED_INT_10_10_10_2);
}

RING_FUNC(ring_get_gl_rescale_normal)
{
	RING_API_RETNUMBER(GL_RESCALE_NORMAL);
}

RING_FUNC(ring_get_gl_texture_binding_3d)
{
	RING_API_RETNUMBER(GL_TEXTURE_BINDING_3D);
}

RING_FUNC(ring_get_gl_pack_skip_images)
{
	RING_API_RETNUMBER(GL_PACK_SKIP_IMAGES);
}

RING_FUNC(ring_get_gl_pack_image_height)
{
	RING_API_RETNUMBER(GL_PACK_IMAGE_HEIGHT);
}

RING_FUNC(ring_get_gl_unpack_skip_images)
{
	RING_API_RETNUMBER(GL_UNPACK_SKIP_IMAGES);
}

RING_FUNC(ring_get_gl_unpack_image_height)
{
	RING_API_RETNUMBER(GL_UNPACK_IMAGE_HEIGHT);
}

RING_FUNC(ring_get_gl_texture_3d)
{
	RING_API_RETNUMBER(GL_TEXTURE_3D);
}

RING_FUNC(ring_get_gl_proxy_texture_3d)
{
	RING_API_RETNUMBER(GL_PROXY_TEXTURE_3D);
}

RING_FUNC(ring_get_gl_texture_depth)
{
	RING_API_RETNUMBER(GL_TEXTURE_DEPTH);
}

RING_FUNC(ring_get_gl_texture_wrap_r)
{
	RING_API_RETNUMBER(GL_TEXTURE_WRAP_R);
}

RING_FUNC(ring_get_gl_max_3d_texture_size)
{
	RING_API_RETNUMBER(GL_MAX_3D_TEXTURE_SIZE);
}

RING_FUNC(ring_get_gl_bgr)
{
	RING_API_RETNUMBER(GL_BGR);
}

RING_FUNC(ring_get_gl_bgra)
{
	RING_API_RETNUMBER(GL_BGRA);
}

RING_FUNC(ring_get_gl_max_elements_vertices)
{
	RING_API_RETNUMBER(GL_MAX_ELEMENTS_VERTICES);
}

RING_FUNC(ring_get_gl_max_elements_indices)
{
	RING_API_RETNUMBER(GL_MAX_ELEMENTS_INDICES);
}

RING_FUNC(ring_get_gl_clamp_to_edge)
{
	RING_API_RETNUMBER(GL_CLAMP_TO_EDGE);
}

RING_FUNC(ring_get_gl_texture_min_lod)
{
	RING_API_RETNUMBER(GL_TEXTURE_MIN_LOD);
}

RING_FUNC(ring_get_gl_texture_max_lod)
{
	RING_API_RETNUMBER(GL_TEXTURE_MAX_LOD);
}

RING_FUNC(ring_get_gl_texture_base_level)
{
	RING_API_RETNUMBER(GL_TEXTURE_BASE_LEVEL);
}

RING_FUNC(ring_get_gl_texture_max_level)
{
	RING_API_RETNUMBER(GL_TEXTURE_MAX_LEVEL);
}

RING_FUNC(ring_get_gl_light_model_color_control)
{
	RING_API_RETNUMBER(GL_LIGHT_MODEL_COLOR_CONTROL);
}

RING_FUNC(ring_get_gl_single_color)
{
	RING_API_RETNUMBER(GL_SINGLE_COLOR);
}

RING_FUNC(ring_get_gl_separate_specular_color)
{
	RING_API_RETNUMBER(GL_SEPARATE_SPECULAR_COLOR);
}

RING_FUNC(ring_get_gl_unsigned_byte_2_3_3_rev)
{
	RING_API_RETNUMBER(GL_UNSIGNED_BYTE_2_3_3_REV);
}

RING_FUNC(ring_get_gl_unsigned_short_5_6_5)
{
	RING_API_RETNUMBER(GL_UNSIGNED_SHORT_5_6_5);
}

RING_FUNC(ring_get_gl_unsigned_short_5_6_5_rev)
{
	RING_API_RETNUMBER(GL_UNSIGNED_SHORT_5_6_5_REV);
}

RING_FUNC(ring_get_gl_unsigned_short_4_4_4_4_rev)
{
	RING_API_RETNUMBER(GL_UNSIGNED_SHORT_4_4_4_4_REV);
}

RING_FUNC(ring_get_gl_unsigned_short_1_5_5_5_rev)
{
	RING_API_RETNUMBER(GL_UNSIGNED_SHORT_1_5_5_5_REV);
}

RING_FUNC(ring_get_gl_unsigned_int_8_8_8_8_rev)
{
	RING_API_RETNUMBER(GL_UNSIGNED_INT_8_8_8_8_REV);
}

RING_FUNC(ring_get_gl_aliased_point_size_range)
{
	RING_API_RETNUMBER(GL_ALIASED_POINT_SIZE_RANGE);
}

RING_FUNC(ring_get_gl_aliased_line_width_range)
{
	RING_API_RETNUMBER(GL_ALIASED_LINE_WIDTH_RANGE);
}

RING_FUNC(ring_get_gl_multisample)
{
	RING_API_RETNUMBER(GL_MULTISAMPLE);
}

RING_FUNC(ring_get_gl_sample_alpha_to_coverage)
{
	RING_API_RETNUMBER(GL_SAMPLE_ALPHA_TO_COVERAGE);
}

RING_FUNC(ring_get_gl_sample_alpha_to_one)
{
	RING_API_RETNUMBER(GL_SAMPLE_ALPHA_TO_ONE);
}

RING_FUNC(ring_get_gl_sample_coverage)
{
	RING_API_RETNUMBER(GL_SAMPLE_COVERAGE);
}

RING_FUNC(ring_get_gl_sample_buffers)
{
	RING_API_RETNUMBER(GL_SAMPLE_BUFFERS);
}

RING_FUNC(ring_get_gl_samples)
{
	RING_API_RETNUMBER(GL_SAMPLES);
}

RING_FUNC(ring_get_gl_sample_coverage_value)
{
	RING_API_RETNUMBER(GL_SAMPLE_COVERAGE_VALUE);
}

RING_FUNC(ring_get_gl_sample_coverage_invert)
{
	RING_API_RETNUMBER(GL_SAMPLE_COVERAGE_INVERT);
}

RING_FUNC(ring_get_gl_clamp_to_border)
{
	RING_API_RETNUMBER(GL_CLAMP_TO_BORDER);
}

RING_FUNC(ring_get_gl_texture0)
{
	RING_API_RETNUMBER(GL_TEXTURE0);
}

RING_FUNC(ring_get_gl_texture1)
{
	RING_API_RETNUMBER(GL_TEXTURE1);
}

RING_FUNC(ring_get_gl_texture2)
{
	RING_API_RETNUMBER(GL_TEXTURE2);
}

RING_FUNC(ring_get_gl_texture3)
{
	RING_API_RETNUMBER(GL_TEXTURE3);
}

RING_FUNC(ring_get_gl_texture4)
{
	RING_API_RETNUMBER(GL_TEXTURE4);
}

RING_FUNC(ring_get_gl_texture5)
{
	RING_API_RETNUMBER(GL_TEXTURE5);
}

RING_FUNC(ring_get_gl_texture6)
{
	RING_API_RETNUMBER(GL_TEXTURE6);
}

RING_FUNC(ring_get_gl_texture7)
{
	RING_API_RETNUMBER(GL_TEXTURE7);
}

RING_FUNC(ring_get_gl_texture8)
{
	RING_API_RETNUMBER(GL_TEXTURE8);
}

RING_FUNC(ring_get_gl_texture9)
{
	RING_API_RETNUMBER(GL_TEXTURE9);
}

RING_FUNC(ring_get_gl_texture10)
{
	RING_API_RETNUMBER(GL_TEXTURE10);
}

RING_FUNC(ring_get_gl_texture11)
{
	RING_API_RETNUMBER(GL_TEXTURE11);
}

RING_FUNC(ring_get_gl_texture12)
{
	RING_API_RETNUMBER(GL_TEXTURE12);
}

RING_FUNC(ring_get_gl_texture13)
{
	RING_API_RETNUMBER(GL_TEXTURE13);
}

RING_FUNC(ring_get_gl_texture14)
{
	RING_API_RETNUMBER(GL_TEXTURE14);
}

RING_FUNC(ring_get_gl_texture15)
{
	RING_API_RETNUMBER(GL_TEXTURE15);
}

RING_FUNC(ring_get_gl_texture16)
{
	RING_API_RETNUMBER(GL_TEXTURE16);
}

RING_FUNC(ring_get_gl_texture17)
{
	RING_API_RETNUMBER(GL_TEXTURE17);
}

RING_FUNC(ring_get_gl_texture18)
{
	RING_API_RETNUMBER(GL_TEXTURE18);
}

RING_FUNC(ring_get_gl_texture19)
{
	RING_API_RETNUMBER(GL_TEXTURE19);
}

RING_FUNC(ring_get_gl_texture20)
{
	RING_API_RETNUMBER(GL_TEXTURE20);
}

RING_FUNC(ring_get_gl_texture21)
{
	RING_API_RETNUMBER(GL_TEXTURE21);
}

RING_FUNC(ring_get_gl_texture22)
{
	RING_API_RETNUMBER(GL_TEXTURE22);
}

RING_FUNC(ring_get_gl_texture23)
{
	RING_API_RETNUMBER(GL_TEXTURE23);
}

RING_FUNC(ring_get_gl_texture24)
{
	RING_API_RETNUMBER(GL_TEXTURE24);
}

RING_FUNC(ring_get_gl_texture25)
{
	RING_API_RETNUMBER(GL_TEXTURE25);
}

RING_FUNC(ring_get_gl_texture26)
{
	RING_API_RETNUMBER(GL_TEXTURE26);
}

RING_FUNC(ring_get_gl_texture27)
{
	RING_API_RETNUMBER(GL_TEXTURE27);
}

RING_FUNC(ring_get_gl_texture28)
{
	RING_API_RETNUMBER(GL_TEXTURE28);
}

RING_FUNC(ring_get_gl_texture29)
{
	RING_API_RETNUMBER(GL_TEXTURE29);
}

RING_FUNC(ring_get_gl_texture30)
{
	RING_API_RETNUMBER(GL_TEXTURE30);
}

RING_FUNC(ring_get_gl_texture31)
{
	RING_API_RETNUMBER(GL_TEXTURE31);
}

RING_FUNC(ring_get_gl_active_texture)
{
	RING_API_RETNUMBER(GL_ACTIVE_TEXTURE);
}

RING_FUNC(ring_get_gl_client_active_texture)
{
	RING_API_RETNUMBER(GL_CLIENT_ACTIVE_TEXTURE);
}

RING_FUNC(ring_get_gl_max_texture_units)
{
	RING_API_RETNUMBER(GL_MAX_TEXTURE_UNITS);
}

RING_FUNC(ring_get_gl_transpose_modelview_matrix)
{
	RING_API_RETNUMBER(GL_TRANSPOSE_MODELVIEW_MATRIX);
}

RING_FUNC(ring_get_gl_transpose_projection_matrix)
{
	RING_API_RETNUMBER(GL_TRANSPOSE_PROJECTION_MATRIX);
}

RING_FUNC(ring_get_gl_transpose_texture_matrix)
{
	RING_API_RETNUMBER(GL_TRANSPOSE_TEXTURE_MATRIX);
}

RING_FUNC(ring_get_gl_transpose_color_matrix)
{
	RING_API_RETNUMBER(GL_TRANSPOSE_COLOR_MATRIX);
}

RING_FUNC(ring_get_gl_subtract)
{
	RING_API_RETNUMBER(GL_SUBTRACT);
}

RING_FUNC(ring_get_gl_compressed_alpha)
{
	RING_API_RETNUMBER(GL_COMPRESSED_ALPHA);
}

RING_FUNC(ring_get_gl_compressed_luminance)
{
	RING_API_RETNUMBER(GL_COMPRESSED_LUMINANCE);
}

RING_FUNC(ring_get_gl_compressed_luminance_alpha)
{
	RING_API_RETNUMBER(GL_COMPRESSED_LUMINANCE_ALPHA);
}

RING_FUNC(ring_get_gl_compressed_intensity)
{
	RING_API_RETNUMBER(GL_COMPRESSED_INTENSITY);
}

RING_FUNC(ring_get_gl_compressed_rgb)
{
	RING_API_RETNUMBER(GL_COMPRESSED_RGB);
}

RING_FUNC(ring_get_gl_compressed_rgba)
{
	RING_API_RETNUMBER(GL_COMPRESSED_RGBA);
}

RING_FUNC(ring_get_gl_texture_compression_hint)
{
	RING_API_RETNUMBER(GL_TEXTURE_COMPRESSION_HINT);
}

RING_FUNC(ring_get_gl_normal_map)
{
	RING_API_RETNUMBER(GL_NORMAL_MAP);
}

RING_FUNC(ring_get_gl_reflection_map)
{
	RING_API_RETNUMBER(GL_REFLECTION_MAP);
}

RING_FUNC(ring_get_gl_texture_cube_map)
{
	RING_API_RETNUMBER(GL_TEXTURE_CUBE_MAP);
}

RING_FUNC(ring_get_gl_texture_binding_cube_map)
{
	RING_API_RETNUMBER(GL_TEXTURE_BINDING_CUBE_MAP);
}

RING_FUNC(ring_get_gl_texture_cube_map_positive_x)
{
	RING_API_RETNUMBER(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
}

RING_FUNC(ring_get_gl_texture_cube_map_negative_x)
{
	RING_API_RETNUMBER(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
}

RING_FUNC(ring_get_gl_texture_cube_map_positive_y)
{
	RING_API_RETNUMBER(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
}

RING_FUNC(ring_get_gl_texture_cube_map_negative_y)
{
	RING_API_RETNUMBER(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
}

RING_FUNC(ring_get_gl_texture_cube_map_positive_z)
{
	RING_API_RETNUMBER(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
}

RING_FUNC(ring_get_gl_texture_cube_map_negative_z)
{
	RING_API_RETNUMBER(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
}

RING_FUNC(ring_get_gl_proxy_texture_cube_map)
{
	RING_API_RETNUMBER(GL_PROXY_TEXTURE_CUBE_MAP);
}

RING_FUNC(ring_get_gl_max_cube_map_texture_size)
{
	RING_API_RETNUMBER(GL_MAX_CUBE_MAP_TEXTURE_SIZE);
}

RING_FUNC(ring_get_gl_combine)
{
	RING_API_RETNUMBER(GL_COMBINE);
}

RING_FUNC(ring_get_gl_combine_rgb)
{
	RING_API_RETNUMBER(GL_COMBINE_RGB);
}

RING_FUNC(ring_get_gl_combine_alpha)
{
	RING_API_RETNUMBER(GL_COMBINE_ALPHA);
}

RING_FUNC(ring_get_gl_rgb_scale)
{
	RING_API_RETNUMBER(GL_RGB_SCALE);
}

RING_FUNC(ring_get_gl_add_signed)
{
	RING_API_RETNUMBER(GL_ADD_SIGNED);
}

RING_FUNC(ring_get_gl_interpolate)
{
	RING_API_RETNUMBER(GL_INTERPOLATE);
}

RING_FUNC(ring_get_gl_constant)
{
	RING_API_RETNUMBER(GL_CONSTANT);
}

RING_FUNC(ring_get_gl_primary_color)
{
	RING_API_RETNUMBER(GL_PRIMARY_COLOR);
}

RING_FUNC(ring_get_gl_previous)
{
	RING_API_RETNUMBER(GL_PREVIOUS);
}

RING_FUNC(ring_get_gl_source0_rgb)
{
	RING_API_RETNUMBER(GL_SOURCE0_RGB);
}

RING_FUNC(ring_get_gl_source1_rgb)
{
	RING_API_RETNUMBER(GL_SOURCE1_RGB);
}

RING_FUNC(ring_get_gl_source2_rgb)
{
	RING_API_RETNUMBER(GL_SOURCE2_RGB);
}

RING_FUNC(ring_get_gl_source0_alpha)
{
	RING_API_RETNUMBER(GL_SOURCE0_ALPHA);
}

RING_FUNC(ring_get_gl_source1_alpha)
{
	RING_API_RETNUMBER(GL_SOURCE1_ALPHA);
}

RING_FUNC(ring_get_gl_source2_alpha)
{
	RING_API_RETNUMBER(GL_SOURCE2_ALPHA);
}

RING_FUNC(ring_get_gl_operand0_rgb)
{
	RING_API_RETNUMBER(GL_OPERAND0_RGB);
}

RING_FUNC(ring_get_gl_operand1_rgb)
{
	RING_API_RETNUMBER(GL_OPERAND1_RGB);
}

RING_FUNC(ring_get_gl_operand2_rgb)
{
	RING_API_RETNUMBER(GL_OPERAND2_RGB);
}

RING_FUNC(ring_get_gl_operand0_alpha)
{
	RING_API_RETNUMBER(GL_OPERAND0_ALPHA);
}

RING_FUNC(ring_get_gl_operand1_alpha)
{
	RING_API_RETNUMBER(GL_OPERAND1_ALPHA);
}

RING_FUNC(ring_get_gl_operand2_alpha)
{
	RING_API_RETNUMBER(GL_OPERAND2_ALPHA);
}

RING_FUNC(ring_get_gl_texture_compressed_image_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_COMPRESSED_IMAGE_SIZE);
}

RING_FUNC(ring_get_gl_texture_compressed)
{
	RING_API_RETNUMBER(GL_TEXTURE_COMPRESSED);
}

RING_FUNC(ring_get_gl_num_compressed_texture_formats)
{
	RING_API_RETNUMBER(GL_NUM_COMPRESSED_TEXTURE_FORMATS);
}

RING_FUNC(ring_get_gl_compressed_texture_formats)
{
	RING_API_RETNUMBER(GL_COMPRESSED_TEXTURE_FORMATS);
}

RING_FUNC(ring_get_gl_dot3_rgb)
{
	RING_API_RETNUMBER(GL_DOT3_RGB);
}

RING_FUNC(ring_get_gl_dot3_rgba)
{
	RING_API_RETNUMBER(GL_DOT3_RGBA);
}

RING_FUNC(ring_get_gl_multisample_bit)
{
	RING_API_RETNUMBER(GL_MULTISAMPLE_BIT);
}

RING_FUNC(ring_get_gl_blend_dst_rgb)
{
	RING_API_RETNUMBER(GL_BLEND_DST_RGB);
}

RING_FUNC(ring_get_gl_blend_src_rgb)
{
	RING_API_RETNUMBER(GL_BLEND_SRC_RGB);
}

RING_FUNC(ring_get_gl_blend_dst_alpha)
{
	RING_API_RETNUMBER(GL_BLEND_DST_ALPHA);
}

RING_FUNC(ring_get_gl_blend_src_alpha)
{
	RING_API_RETNUMBER(GL_BLEND_SRC_ALPHA);
}

RING_FUNC(ring_get_gl_point_size_min)
{
	RING_API_RETNUMBER(GL_POINT_SIZE_MIN);
}

RING_FUNC(ring_get_gl_point_size_max)
{
	RING_API_RETNUMBER(GL_POINT_SIZE_MAX);
}

RING_FUNC(ring_get_gl_point_fade_threshold_size)
{
	RING_API_RETNUMBER(GL_POINT_FADE_THRESHOLD_SIZE);
}

RING_FUNC(ring_get_gl_point_distance_attenuation)
{
	RING_API_RETNUMBER(GL_POINT_DISTANCE_ATTENUATION);
}

RING_FUNC(ring_get_gl_generate_mipmap)
{
	RING_API_RETNUMBER(GL_GENERATE_MIPMAP);
}

RING_FUNC(ring_get_gl_generate_mipmap_hint)
{
	RING_API_RETNUMBER(GL_GENERATE_MIPMAP_HINT);
}

RING_FUNC(ring_get_gl_depth_component16)
{
	RING_API_RETNUMBER(GL_DEPTH_COMPONENT16);
}

RING_FUNC(ring_get_gl_depth_component24)
{
	RING_API_RETNUMBER(GL_DEPTH_COMPONENT24);
}

RING_FUNC(ring_get_gl_depth_component32)
{
	RING_API_RETNUMBER(GL_DEPTH_COMPONENT32);
}

RING_FUNC(ring_get_gl_mirrored_repeat)
{
	RING_API_RETNUMBER(GL_MIRRORED_REPEAT);
}

RING_FUNC(ring_get_gl_fog_coordinate_source)
{
	RING_API_RETNUMBER(GL_FOG_COORDINATE_SOURCE);
}

RING_FUNC(ring_get_gl_fog_coordinate)
{
	RING_API_RETNUMBER(GL_FOG_COORDINATE);
}

RING_FUNC(ring_get_gl_fragment_depth)
{
	RING_API_RETNUMBER(GL_FRAGMENT_DEPTH);
}

RING_FUNC(ring_get_gl_current_fog_coordinate)
{
	RING_API_RETNUMBER(GL_CURRENT_FOG_COORDINATE);
}

RING_FUNC(ring_get_gl_fog_coordinate_array_type)
{
	RING_API_RETNUMBER(GL_FOG_COORDINATE_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_fog_coordinate_array_stride)
{
	RING_API_RETNUMBER(GL_FOG_COORDINATE_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_fog_coordinate_array_pointer)
{
	RING_API_RETNUMBER(GL_FOG_COORDINATE_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_fog_coordinate_array)
{
	RING_API_RETNUMBER(GL_FOG_COORDINATE_ARRAY);
}

RING_FUNC(ring_get_gl_color_sum)
{
	RING_API_RETNUMBER(GL_COLOR_SUM);
}

RING_FUNC(ring_get_gl_current_secondary_color)
{
	RING_API_RETNUMBER(GL_CURRENT_SECONDARY_COLOR);
}

RING_FUNC(ring_get_gl_secondary_color_array_size)
{
	RING_API_RETNUMBER(GL_SECONDARY_COLOR_ARRAY_SIZE);
}

RING_FUNC(ring_get_gl_secondary_color_array_type)
{
	RING_API_RETNUMBER(GL_SECONDARY_COLOR_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_secondary_color_array_stride)
{
	RING_API_RETNUMBER(GL_SECONDARY_COLOR_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_secondary_color_array_pointer)
{
	RING_API_RETNUMBER(GL_SECONDARY_COLOR_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_secondary_color_array)
{
	RING_API_RETNUMBER(GL_SECONDARY_COLOR_ARRAY);
}

RING_FUNC(ring_get_gl_max_texture_lod_bias)
{
	RING_API_RETNUMBER(GL_MAX_TEXTURE_LOD_BIAS);
}

RING_FUNC(ring_get_gl_texture_filter_control)
{
	RING_API_RETNUMBER(GL_TEXTURE_FILTER_CONTROL);
}

RING_FUNC(ring_get_gl_texture_lod_bias)
{
	RING_API_RETNUMBER(GL_TEXTURE_LOD_BIAS);
}

RING_FUNC(ring_get_gl_incr_wrap)
{
	RING_API_RETNUMBER(GL_INCR_WRAP);
}

RING_FUNC(ring_get_gl_decr_wrap)
{
	RING_API_RETNUMBER(GL_DECR_WRAP);
}

RING_FUNC(ring_get_gl_texture_depth_size)
{
	RING_API_RETNUMBER(GL_TEXTURE_DEPTH_SIZE);
}

RING_FUNC(ring_get_gl_depth_texture_mode)
{
	RING_API_RETNUMBER(GL_DEPTH_TEXTURE_MODE);
}

RING_FUNC(ring_get_gl_texture_compare_mode)
{
	RING_API_RETNUMBER(GL_TEXTURE_COMPARE_MODE);
}

RING_FUNC(ring_get_gl_texture_compare_func)
{
	RING_API_RETNUMBER(GL_TEXTURE_COMPARE_FUNC);
}

RING_FUNC(ring_get_gl_compare_r_to_texture)
{
	RING_API_RETNUMBER(GL_COMPARE_R_TO_TEXTURE);
}

RING_FUNC(ring_get_gl_current_fog_coord)
{
	RING_API_RETNUMBER(GL_CURRENT_FOG_COORD);
}

RING_FUNC(ring_get_gl_fog_coord)
{
	RING_API_RETNUMBER(GL_FOG_COORD);
}

RING_FUNC(ring_get_gl_fog_coord_array)
{
	RING_API_RETNUMBER(GL_FOG_COORD_ARRAY);
}

RING_FUNC(ring_get_gl_fog_coord_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_FOG_COORD_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_fog_coord_array_pointer)
{
	RING_API_RETNUMBER(GL_FOG_COORD_ARRAY_POINTER);
}

RING_FUNC(ring_get_gl_fog_coord_array_stride)
{
	RING_API_RETNUMBER(GL_FOG_COORD_ARRAY_STRIDE);
}

RING_FUNC(ring_get_gl_fog_coord_array_type)
{
	RING_API_RETNUMBER(GL_FOG_COORD_ARRAY_TYPE);
}

RING_FUNC(ring_get_gl_fog_coord_src)
{
	RING_API_RETNUMBER(GL_FOG_COORD_SRC);
}

RING_FUNC(ring_get_gl_src0_alpha)
{
	RING_API_RETNUMBER(GL_SRC0_ALPHA);
}

RING_FUNC(ring_get_gl_src0_rgb)
{
	RING_API_RETNUMBER(GL_SRC0_RGB);
}

RING_FUNC(ring_get_gl_src1_alpha)
{
	RING_API_RETNUMBER(GL_SRC1_ALPHA);
}

RING_FUNC(ring_get_gl_src1_rgb)
{
	RING_API_RETNUMBER(GL_SRC1_RGB);
}

RING_FUNC(ring_get_gl_src2_alpha)
{
	RING_API_RETNUMBER(GL_SRC2_ALPHA);
}

RING_FUNC(ring_get_gl_src2_rgb)
{
	RING_API_RETNUMBER(GL_SRC2_RGB);
}

RING_FUNC(ring_get_gl_buffer_size)
{
	RING_API_RETNUMBER(GL_BUFFER_SIZE);
}

RING_FUNC(ring_get_gl_buffer_usage)
{
	RING_API_RETNUMBER(GL_BUFFER_USAGE);
}

RING_FUNC(ring_get_gl_query_counter_bits)
{
	RING_API_RETNUMBER(GL_QUERY_COUNTER_BITS);
}

RING_FUNC(ring_get_gl_current_query)
{
	RING_API_RETNUMBER(GL_CURRENT_QUERY);
}

RING_FUNC(ring_get_gl_query_result)
{
	RING_API_RETNUMBER(GL_QUERY_RESULT);
}

RING_FUNC(ring_get_gl_query_result_available)
{
	RING_API_RETNUMBER(GL_QUERY_RESULT_AVAILABLE);
}

RING_FUNC(ring_get_gl_array_buffer)
{
	RING_API_RETNUMBER(GL_ARRAY_BUFFER);
}

RING_FUNC(ring_get_gl_element_array_buffer)
{
	RING_API_RETNUMBER(GL_ELEMENT_ARRAY_BUFFER);
}

RING_FUNC(ring_get_gl_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_element_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_ELEMENT_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_vertex_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_VERTEX_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_normal_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_NORMAL_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_color_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_COLOR_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_index_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_INDEX_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_texture_coord_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_edge_flag_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_secondary_color_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_fog_coordinate_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_weight_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_WEIGHT_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_vertex_attrib_array_buffer_binding)
{
	RING_API_RETNUMBER(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING);
}

RING_FUNC(ring_get_gl_read_only)
{
	RING_API_RETNUMBER(GL_READ_ONLY);
}

RING_FUNC(ring_get_gl_write_only)
{
	RING_API_RETNUMBER(GL_WRITE_ONLY);
}

RING_FUNC(ring_get_gl_read_write)
{
	RING_API_RETNUMBER(GL_READ_WRITE);
}

RING_FUNC(ring_get_gl_buffer_access)
{
	RING_API_RETNUMBER(GL_BUFFER_ACCESS);
}

RING_FUNC(ring_get_gl_buffer_mapped)
{
	RING_API_RETNUMBER(GL_BUFFER_MAPPED);
}

RING_FUNC(ring_get_gl_buffer_map_pointer)
{
	RING_API_RETNUMBER(GL_BUFFER_MAP_POINTER);
}

RING_FUNC(ring_get_gl_stream_draw)
{
	RING_API_RETNUMBER(GL_STREAM_DRAW);
}

RING_FUNC(ring_get_gl_stream_read)
{
	RING_API_RETNUMBER(GL_STREAM_READ);
}

RING_FUNC(ring_get_gl_stream_copy)
{
	RING_API_RETNUMBER(GL_STREAM_COPY);
}

RING_FUNC(ring_get_gl_static_draw)
{
	RING_API_RETNUMBER(GL_STATIC_DRAW);
}

RING_FUNC(ring_get_gl_static_read)
{
	RING_API_RETNUMBER(GL_STATIC_READ);
}

RING_FUNC(ring_get_gl_static_copy)
{
	RING_API_RETNUMBER(GL_STATIC_COPY);
}

RING_FUNC(ring_get_gl_dynamic_draw)
{
	RING_API_RETNUMBER(GL_DYNAMIC_DRAW);
}

RING_FUNC(ring_get_gl_dynamic_read)
{
	RING_API_RETNUMBER(GL_DYNAMIC_READ);
}

RING_FUNC(ring_get_gl_dynamic_copy)
{
	RING_API_RETNUMBER(GL_DYNAMIC_COPY);
}

RING_FUNC(ring_get_gl_samples_passed)
{
	RING_API_RETNUMBER(GL_SAMPLES_PASSED);
}


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
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glAlphaFunc( (GLenum )  (int) RING_API_GETNUMBER(1), (GLclampf )  (int) RING_API_GETNUMBER(2));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISSTRING(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBitmap( (GLsizei )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4), (GLfloat ) RING_API_GETNUMBER(5), (GLfloat ) RING_API_GETNUMBER(6),RING_API_GETSTRING(7));
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glCallLists( (GLsizei )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"));
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
	glClearColor( (GLclampf )  (int) RING_API_GETNUMBER(1), (GLclampf )  (int) RING_API_GETNUMBER(2), (GLclampf )  (int) RING_API_GETNUMBER(3), (GLclampf )  (int) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glClearDepth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glClearDepth( (GLclampd ) RING_API_GETNUMBER(1));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	glColor3b( (GLbyte ) RING_API_GETNUMBER(1), (GLbyte ) RING_API_GETNUMBER(2), (GLbyte ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glColor3bv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3bv((GLbyte *) RING_API_GETCPOINTER(1,"GLbyte"));
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


RING_FUNC(ring_glColor3dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
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


RING_FUNC(ring_glColor3fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
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


RING_FUNC(ring_glColor3iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glColor3s)
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
	glColor3s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glColor3sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glColor3ub)
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
	glColor3ub( (GLubyte ) RING_API_GETNUMBER(1), (GLubyte ) RING_API_GETNUMBER(2), (GLubyte ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glColor3ubv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3ubv(RING_API_GETSTRING(1));
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


RING_FUNC(ring_glColor3uiv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3uiv((GLuint *) RING_API_GETCPOINTER(1,"GLuint"));
}


RING_FUNC(ring_glColor3us)
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
	glColor3us( (GLushort ) RING_API_GETNUMBER(1), (GLushort ) RING_API_GETNUMBER(2), (GLushort ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glColor3usv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor3usv((GLushort *) RING_API_GETCPOINTER(1,"GLushort"));
}


RING_FUNC(ring_glColor4b)
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
	glColor4b( (GLbyte ) RING_API_GETNUMBER(1), (GLbyte ) RING_API_GETNUMBER(2), (GLbyte ) RING_API_GETNUMBER(3), (GLbyte ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor4bv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4bv((GLbyte *) RING_API_GETCPOINTER(1,"GLbyte"));
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


RING_FUNC(ring_glColor4dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
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


RING_FUNC(ring_glColor4fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
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


RING_FUNC(ring_glColor4iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glColor4s)
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
	glColor4s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3), (GLshort ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor4sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glColor4ub)
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
	glColor4ub( (GLubyte ) RING_API_GETNUMBER(1), (GLubyte ) RING_API_GETNUMBER(2), (GLubyte ) RING_API_GETNUMBER(3), (GLubyte ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor4ubv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4ubv(RING_API_GETSTRING(1));
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


RING_FUNC(ring_glColor4uiv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4uiv((GLuint *) RING_API_GETCPOINTER(1,"GLuint"));
}


RING_FUNC(ring_glColor4us)
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
	glColor4us( (GLushort ) RING_API_GETNUMBER(1), (GLushort ) RING_API_GETNUMBER(2), (GLushort ) RING_API_GETNUMBER(3), (GLushort ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glColor4usv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColor4usv((GLushort *) RING_API_GETCPOINTER(1,"GLushort"));
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glColorPointer( (GLint ) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3),(void *) RING_API_GETCPOINTER(4,"void"));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDepthRange( (GLclampd ) RING_API_GETNUMBER(1), (GLclampd ) RING_API_GETNUMBER(2));
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
	glDisable( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glDisableClientState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDisableClientState( (GLenum )  (int) RING_API_GETNUMBER(1));
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDrawElements( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3),(void *) RING_API_GETCPOINTER(4,"void"));
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glDrawPixels( (GLsizei )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4),(void *) RING_API_GETCPOINTER(5,"void"));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEdgeFlagPointer( (GLsizei )  (int) RING_API_GETNUMBER(1),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_glEdgeFlagv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEdgeFlagv((GLboolean *) RING_API_GETCPOINTER(1,"GLboolean"));
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
	glEnable( (GLenum )  (int) RING_API_GETNUMBER(1));
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


RING_FUNC(ring_glEvalCoord1dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEvalCoord1dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
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


RING_FUNC(ring_glEvalCoord1fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEvalCoord1fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
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


RING_FUNC(ring_glEvalCoord2dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEvalCoord2dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
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


RING_FUNC(ring_glEvalCoord2fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glEvalCoord2fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
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


RING_FUNC(ring_glEvalMesh2)
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
	glEvalMesh2( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5));
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glFogfv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLfloat *) RING_API_GETCPOINTER(2,"GLfloat"));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glFogiv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLint *) RING_API_GETCPOINTER(2,"GLint"));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetBooleanv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLboolean *) RING_API_GETCPOINTER(2,"GLboolean"));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetClipPlane( (GLenum )  (int) RING_API_GETNUMBER(1),(GLdouble *) RING_API_GETCPOINTER(2,"GLdouble"));
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetDoublev( (GLenum )  (int) RING_API_GETNUMBER(1),(GLdouble *) RING_API_GETCPOINTER(2,"GLdouble"));
}


RING_FUNC(ring_glGetError)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glGetError());
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
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetIntegerv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLint *) RING_API_GETCPOINTER(2,"GLint"));
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetMaterialiv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetPixelMapfv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetPixelMapfv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLfloat *) RING_API_GETCPOINTER(2,"GLfloat"));
}


RING_FUNC(ring_glGetPixelMapuiv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetPixelMapuiv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glGetPixelMapusv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetPixelMapusv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLushort *) RING_API_GETCPOINTER(2,"GLushort"));
}


RING_FUNC(ring_glGetPointerv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetPointerv( (GLenum )  (int) RING_API_GETNUMBER(1),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_glGetPolygonStipple)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetPolygonStipple(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glGetString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(glGetString( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glGetTexEnvfv)
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
	glGetTexEnvfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetTexEnviv)
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
	glGetTexEnviv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetTexGendv)
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
	glGetTexGendv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLdouble *) RING_API_GETCPOINTER(3,"GLdouble"));
}


RING_FUNC(ring_glGetTexGenfv)
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
	glGetTexGenfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetTexGeniv)
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
	glGetTexGeniv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glGetTexImage)
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetTexImage( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3), (GLenum )  (int) RING_API_GETNUMBER(4),(void *) RING_API_GETCPOINTER(5,"void"));
}


RING_FUNC(ring_glGetTexLevelParameterfv)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetTexLevelParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3),(GLfloat *) RING_API_GETCPOINTER(4,"GLfloat"));
}


RING_FUNC(ring_glGetTexLevelParameteriv)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGetTexLevelParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3),(GLint *) RING_API_GETCPOINTER(4,"GLint"));
}


RING_FUNC(ring_glGetTexParameterfv)
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
	glGetTexParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glGetTexParameteriv)
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
	glGetTexParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glHint)
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
	glHint( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glIndexMask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexMask( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glIndexPointer)
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
	glIndexPointer( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"));
}


RING_FUNC(ring_glIndexd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexd( (GLdouble ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glIndexdv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexdv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glIndexf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexf( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glIndexfv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexfv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glIndexi)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexi( (GLint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glIndexiv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexiv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glIndexs)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexs( (GLshort ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glIndexsv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexsv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glIndexub)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexub( (GLubyte ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glIndexubv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glIndexubv(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glInitNames)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glInitNames();
}


RING_FUNC(ring_glInterleavedArrays)
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
	glInterleavedArrays( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"));
}


RING_FUNC(ring_glIsEnabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glIsEnabled( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glIsList)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glIsList( (GLuint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glIsTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glIsTexture( (GLuint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glLightModelf)
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
	glLightModelf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glLightModelfv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glLightModelfv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLfloat *) RING_API_GETCPOINTER(2,"GLfloat"));
}


RING_FUNC(ring_glLightModeli)
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
	glLightModeli( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glLightModeliv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glLightModeliv( (GLenum )  (int) RING_API_GETNUMBER(1),(GLint *) RING_API_GETCPOINTER(2,"GLint"));
}


RING_FUNC(ring_glLightf)
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
	glLightf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glLightfv)
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
	glLightfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glLighti)
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
	glLighti( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glLightiv)
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
	glLightiv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glLineStipple)
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
	glLineStipple( (GLint ) RING_API_GETNUMBER(1), (GLushort ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glLineWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glLineWidth( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glListBase)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glListBase( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glLoadIdentity)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glLoadIdentity();
}


RING_FUNC(ring_glLoadMatrixd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glLoadMatrixd((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glLoadMatrixf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glLoadMatrixf((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glLoadName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glLoadName( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glLogicOp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glLogicOp( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glMap1d)
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glMap1d( (GLenum )  (int) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5),(GLdouble *) RING_API_GETCPOINTER(6,"GLdouble"));
}


RING_FUNC(ring_glMap1f)
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glMap1f( (GLenum )  (int) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5),(GLfloat *) RING_API_GETCPOINTER(6,"GLfloat"));
}


RING_FUNC(ring_glMap2d)
{
	if ( RING_API_PARACOUNT != 10 ) {
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
	if ( ! RING_API_ISCPOINTER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glMap2d( (GLenum )  (int) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLdouble ) RING_API_GETNUMBER(6), (GLdouble ) RING_API_GETNUMBER(7), (GLint ) RING_API_GETNUMBER(8), (GLint ) RING_API_GETNUMBER(9),(GLdouble *) RING_API_GETCPOINTER(10,"GLdouble"));
}


RING_FUNC(ring_glMap2f)
{
	if ( RING_API_PARACOUNT != 10 ) {
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
	if ( ! RING_API_ISCPOINTER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glMap2f( (GLenum )  (int) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLfloat ) RING_API_GETNUMBER(6), (GLfloat ) RING_API_GETNUMBER(7), (GLint ) RING_API_GETNUMBER(8), (GLint ) RING_API_GETNUMBER(9),(GLfloat *) RING_API_GETCPOINTER(10,"GLfloat"));
}


RING_FUNC(ring_glMapGrid1d)
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
	glMapGrid1d( (GLint ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glMapGrid1f)
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
	glMapGrid1f( (GLint ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glMapGrid2d)
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
	glMapGrid2d( (GLint ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLdouble ) RING_API_GETNUMBER(5), (GLdouble ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_glMapGrid2f)
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
	glMapGrid2f( (GLint ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLfloat ) RING_API_GETNUMBER(5), (GLfloat ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_glMaterialf)
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
	glMaterialf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glMaterialfv)
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
	glMaterialfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glMateriali)
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
	glMateriali( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glMaterialiv)
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
	glMaterialiv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
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
	glMatrixMode( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glMultMatrixd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glMultMatrixd((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glMultMatrixf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glMultMatrixf((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glNewList)
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
	glNewList( (GLuint ) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glNormal3b)
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
	glNormal3b( (GLbyte ) RING_API_GETNUMBER(1), (GLbyte ) RING_API_GETNUMBER(2), (GLbyte ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glNormal3bv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glNormal3bv((GLbyte *) RING_API_GETCPOINTER(1,"GLbyte"));
}


RING_FUNC(ring_glNormal3d)
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
	glNormal3d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glNormal3dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glNormal3dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glNormal3f)
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
	glNormal3f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glNormal3fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glNormal3fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glNormal3i)
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
	glNormal3i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glNormal3iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glNormal3iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glNormal3s)
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
	glNormal3s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glNormal3sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glNormal3sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glNormalPointer)
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
	glNormalPointer( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"));
}


RING_FUNC(ring_glOrtho)
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
	glOrtho( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4), (GLdouble ) RING_API_GETNUMBER(5), (GLdouble ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_glPassThrough)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glPassThrough( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glPixelMapfv)
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
	glPixelMapfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glPixelMapuiv)
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
	glPixelMapuiv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(GLuint *) RING_API_GETCPOINTER(3,"GLuint"));
}


RING_FUNC(ring_glPixelMapusv)
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
	glPixelMapusv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLsizei )  (int) RING_API_GETNUMBER(2),(GLushort *) RING_API_GETCPOINTER(3,"GLushort"));
}


RING_FUNC(ring_glPixelStoref)
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
	glPixelStoref( (GLenum )  (int) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glPixelStorei)
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
	glPixelStorei( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glPixelTransferf)
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
	glPixelTransferf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glPixelTransferi)
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
	glPixelTransferi( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glPixelZoom)
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
	glPixelZoom( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glPointSize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glPointSize( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glPolygonMode)
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
	glPolygonMode( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glPolygonOffset)
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
	glPolygonOffset( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glPolygonStipple)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glPolygonStipple(RING_API_GETSTRING(1));
}


RING_FUNC(ring_glPopAttrib)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glPopAttrib();
}


RING_FUNC(ring_glPopClientAttrib)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glPopClientAttrib();
}


RING_FUNC(ring_glPopMatrix)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glPopMatrix();
}


RING_FUNC(ring_glPopName)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glPopName();
}


RING_FUNC(ring_glPrioritizeTextures)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
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
	glPrioritizeTextures( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"),(GLclampf *) RING_API_GETCPOINTER(3,"GLclampf"));
}


RING_FUNC(ring_glPushAttrib)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glPushAttrib( (GLbitfield )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glPushClientAttrib)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glPushClientAttrib( (GLbitfield )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glPushMatrix)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	glPushMatrix();
}


RING_FUNC(ring_glPushName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glPushName( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glRasterPos2d)
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
	glRasterPos2d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glRasterPos2dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos2dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glRasterPos2f)
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
	glRasterPos2f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glRasterPos2fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos2fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glRasterPos2i)
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
	glRasterPos2i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glRasterPos2iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos2iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glRasterPos2s)
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
	glRasterPos2s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glRasterPos2sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos2sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glRasterPos3d)
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
	glRasterPos3d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glRasterPos3dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos3dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glRasterPos3f)
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
	glRasterPos3f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glRasterPos3fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos3fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glRasterPos3i)
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
	glRasterPos3i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glRasterPos3iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos3iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glRasterPos3s)
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
	glRasterPos3s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glRasterPos3sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos3sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glRasterPos4d)
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
	glRasterPos4d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRasterPos4dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos4dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glRasterPos4f)
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
	glRasterPos4f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRasterPos4fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos4fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glRasterPos4i)
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
	glRasterPos4i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRasterPos4iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos4iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glRasterPos4s)
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
	glRasterPos4s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3), (GLshort ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRasterPos4sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glRasterPos4sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glReadBuffer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glReadBuffer( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glReadPixels)
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
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glReadPixels( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5), (GLenum )  (int) RING_API_GETNUMBER(6),(void *) RING_API_GETCPOINTER(7,"void"));
}


RING_FUNC(ring_glRectd)
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
	glRectd( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRectdv)
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
	glRectdv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"),(GLdouble *) RING_API_GETCPOINTER(2,"GLdouble"));
}


RING_FUNC(ring_glRectf)
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
	glRectf( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRectfv)
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
	glRectfv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"),(GLfloat *) RING_API_GETCPOINTER(2,"GLfloat"));
}


RING_FUNC(ring_glRecti)
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
	glRecti( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRectiv)
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
	glRectiv((GLint *) RING_API_GETCPOINTER(1,"GLint"),(GLint *) RING_API_GETCPOINTER(2,"GLint"));
}


RING_FUNC(ring_glRects)
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
	glRects( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3), (GLshort ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glRectsv)
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
	glRectsv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"),(GLshort *) RING_API_GETCPOINTER(2,"GLshort"));
}


RING_FUNC(ring_glRenderMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glRenderMode( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glRotated)
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
	glRotated( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4));
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
	glRotatef( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glScaled)
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
	glScaled( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glScalef)
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
	glScalef( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glScissor)
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
	glScissor( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glSelectBuffer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glSelectBuffer( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glShadeModel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glShadeModel( (GLenum )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glStencilFunc)
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
	glStencilFunc( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLuint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glStencilMask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glStencilMask( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glStencilOp)
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
	glStencilOp( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLenum )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexCoord1d)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1d( (GLdouble ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glTexCoord1dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glTexCoord1f)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1f( (GLfloat ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glTexCoord1fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glTexCoord1i)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1i( (GLint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glTexCoord1iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glTexCoord1s)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1s( (GLshort ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glTexCoord1sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord1sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glTexCoord2d)
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
	glTexCoord2d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glTexCoord2dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord2dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glTexCoord2f)
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
	glTexCoord2f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glTexCoord2fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord2fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glTexCoord2i)
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
	glTexCoord2i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glTexCoord2iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord2iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glTexCoord2s)
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
	glTexCoord2s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glTexCoord2sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord2sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glTexCoord3d)
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
	glTexCoord3d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexCoord3dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord3dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glTexCoord3f)
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
	glTexCoord3f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexCoord3fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord3fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glTexCoord3i)
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
	glTexCoord3i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexCoord3iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord3iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glTexCoord3s)
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
	glTexCoord3s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexCoord3sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord3sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glTexCoord4d)
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
	glTexCoord4d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glTexCoord4dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord4dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glTexCoord4f)
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
	glTexCoord4f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glTexCoord4fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord4fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glTexCoord4i)
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
	glTexCoord4i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glTexCoord4iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord4iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glTexCoord4s)
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
	glTexCoord4s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3), (GLshort ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glTexCoord4sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoord4sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glTexCoordPointer)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexCoordPointer( (GLint ) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3),(void *) RING_API_GETCPOINTER(4,"void"));
}


RING_FUNC(ring_glTexEnvf)
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
	glTexEnvf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexEnvfv)
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
	glTexEnvfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glTexEnvi)
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
	glTexEnvi( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexEnviv)
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
	glTexEnviv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glTexGend)
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
	glTexGend( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexGendv)
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
	glTexGendv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLdouble *) RING_API_GETCPOINTER(3,"GLdouble"));
}


RING_FUNC(ring_glTexGenf)
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
	glTexGenf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexGenfv)
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
	glTexGenfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glTexGeni)
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
	glTexGeni( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexGeniv)
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
	glTexGeniv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glTexImage1D)
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
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexImage1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLint ) RING_API_GETNUMBER(5), (GLenum )  (int) RING_API_GETNUMBER(6), (GLenum )  (int) RING_API_GETNUMBER(7),(void *) RING_API_GETCPOINTER(8,"void"));
}


RING_FUNC(ring_glTexImage2D)
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
	if ( ! RING_API_ISCPOINTER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexImage2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5), (GLint ) RING_API_GETNUMBER(6), (GLenum )  (int) RING_API_GETNUMBER(7), (GLenum )  (int) RING_API_GETNUMBER(8),(void *) RING_API_GETCPOINTER(9,"void"));
}


RING_FUNC(ring_glTexParameterf)
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
	glTexParameterf( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexParameterfv)
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
	glTexParameterfv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLfloat *) RING_API_GETCPOINTER(3,"GLfloat"));
}


RING_FUNC(ring_glTexParameteri)
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
	glTexParameteri( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glTexParameteriv)
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
	glTexParameteriv( (GLenum )  (int) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2),(GLint *) RING_API_GETCPOINTER(3,"GLint"));
}


RING_FUNC(ring_glTexSubImage1D)
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
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexSubImage1D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4), (GLenum )  (int) RING_API_GETNUMBER(5), (GLenum )  (int) RING_API_GETNUMBER(6),(void *) RING_API_GETCPOINTER(7,"void"));
}


RING_FUNC(ring_glTexSubImage2D)
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
	if ( ! RING_API_ISCPOINTER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glTexSubImage2D( (GLenum )  (int) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4), (GLsizei )  (int) RING_API_GETNUMBER(5), (GLsizei )  (int) RING_API_GETNUMBER(6), (GLenum )  (int) RING_API_GETNUMBER(7), (GLenum )  (int) RING_API_GETNUMBER(8),(void *) RING_API_GETCPOINTER(9,"void"));
}


RING_FUNC(ring_glTranslated)
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
	glTranslated( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
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
	glTranslatef( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glVertex2d)
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
	glVertex2d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glVertex2dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex2dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glVertex2f)
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
	glVertex2f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glVertex2fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex2fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glVertex2i)
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
	glVertex2i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glVertex2iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex2iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glVertex2s)
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
	glVertex2s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_glVertex2sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex2sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glVertex3d)
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
	glVertex3d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glVertex3dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex3dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
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
	glVertex3f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glVertex3fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex3fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glVertex3i)
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
	glVertex3i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glVertex3iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex3iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glVertex3s)
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
	glVertex3s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_glVertex3sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex3sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glVertex4d)
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
	glVertex4d( (GLdouble ) RING_API_GETNUMBER(1), (GLdouble ) RING_API_GETNUMBER(2), (GLdouble ) RING_API_GETNUMBER(3), (GLdouble ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glVertex4dv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex4dv((GLdouble *) RING_API_GETCPOINTER(1,"GLdouble"));
}


RING_FUNC(ring_glVertex4f)
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
	glVertex4f( (GLfloat ) RING_API_GETNUMBER(1), (GLfloat ) RING_API_GETNUMBER(2), (GLfloat ) RING_API_GETNUMBER(3), (GLfloat ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glVertex4fv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex4fv((GLfloat *) RING_API_GETCPOINTER(1,"GLfloat"));
}


RING_FUNC(ring_glVertex4i)
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
	glVertex4i( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLint ) RING_API_GETNUMBER(3), (GLint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glVertex4iv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex4iv((GLint *) RING_API_GETCPOINTER(1,"GLint"));
}


RING_FUNC(ring_glVertex4s)
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
	glVertex4s( (GLshort ) RING_API_GETNUMBER(1), (GLshort ) RING_API_GETNUMBER(2), (GLshort ) RING_API_GETNUMBER(3), (GLshort ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glVertex4sv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertex4sv((GLshort *) RING_API_GETCPOINTER(1,"GLshort"));
}


RING_FUNC(ring_glVertexPointer)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glVertexPointer( (GLint ) RING_API_GETNUMBER(1), (GLenum )  (int) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3),(void *) RING_API_GETCPOINTER(4,"void"));
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
	glViewport( (GLint ) RING_API_GETNUMBER(1), (GLint ) RING_API_GETNUMBER(2), (GLsizei )  (int) RING_API_GETNUMBER(3), (GLsizei )  (int) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_glBindVertexArray)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glBindVertexArray( (GLuint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_glGenVertexArrays)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	glGenVertexArrays( (GLsizei )  (int) RING_API_GETNUMBER(1),(GLuint *) RING_API_GETCPOINTER(2,"GLuint"));
}


RING_FUNC(ring_glewInit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(glewInit());
}


RING_FUNC(ring_glewIsSupported)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glewIsSupported(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_glewGetExtension)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(glewGetExtension(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_glewGetErrorString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(glewGetErrorString( (GLenum )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_glewGetString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(glewGetString( (GLenum )  (int) RING_API_GETNUMBER(1)));
}

RING_LIBINIT
{
	RING_API_REGISTER("glaccum",ring_glAccum);
	RING_API_REGISTER("glalphafunc",ring_glAlphaFunc);
	RING_API_REGISTER("glaretexturesresident",ring_glAreTexturesResident);
	RING_API_REGISTER("glarrayelement",ring_glArrayElement);
	RING_API_REGISTER("glbegin",ring_glBegin);
	RING_API_REGISTER("glbindtexture",ring_glBindTexture);
	RING_API_REGISTER("glbitmap",ring_glBitmap);
	RING_API_REGISTER("glblendfunc",ring_glBlendFunc);
	RING_API_REGISTER("glcalllist",ring_glCallList);
	RING_API_REGISTER("glcalllists",ring_glCallLists);
	RING_API_REGISTER("glclear",ring_glClear);
	RING_API_REGISTER("glclearaccum",ring_glClearAccum);
	RING_API_REGISTER("glclearcolor",ring_glClearColor);
	RING_API_REGISTER("glcleardepth",ring_glClearDepth);
	RING_API_REGISTER("glclearindex",ring_glClearIndex);
	RING_API_REGISTER("glclearstencil",ring_glClearStencil);
	RING_API_REGISTER("glclipplane",ring_glClipPlane);
	RING_API_REGISTER("glcolor3b",ring_glColor3b);
	RING_API_REGISTER("glcolor3bv",ring_glColor3bv);
	RING_API_REGISTER("glcolor3d",ring_glColor3d);
	RING_API_REGISTER("glcolor3dv",ring_glColor3dv);
	RING_API_REGISTER("glcolor3f",ring_glColor3f);
	RING_API_REGISTER("glcolor3fv",ring_glColor3fv);
	RING_API_REGISTER("glcolor3i",ring_glColor3i);
	RING_API_REGISTER("glcolor3iv",ring_glColor3iv);
	RING_API_REGISTER("glcolor3s",ring_glColor3s);
	RING_API_REGISTER("glcolor3sv",ring_glColor3sv);
	RING_API_REGISTER("glcolor3ub",ring_glColor3ub);
	RING_API_REGISTER("glcolor3ubv",ring_glColor3ubv);
	RING_API_REGISTER("glcolor3ui",ring_glColor3ui);
	RING_API_REGISTER("glcolor3uiv",ring_glColor3uiv);
	RING_API_REGISTER("glcolor3us",ring_glColor3us);
	RING_API_REGISTER("glcolor3usv",ring_glColor3usv);
	RING_API_REGISTER("glcolor4b",ring_glColor4b);
	RING_API_REGISTER("glcolor4bv",ring_glColor4bv);
	RING_API_REGISTER("glcolor4d",ring_glColor4d);
	RING_API_REGISTER("glcolor4dv",ring_glColor4dv);
	RING_API_REGISTER("glcolor4f",ring_glColor4f);
	RING_API_REGISTER("glcolor4fv",ring_glColor4fv);
	RING_API_REGISTER("glcolor4i",ring_glColor4i);
	RING_API_REGISTER("glcolor4iv",ring_glColor4iv);
	RING_API_REGISTER("glcolor4s",ring_glColor4s);
	RING_API_REGISTER("glcolor4sv",ring_glColor4sv);
	RING_API_REGISTER("glcolor4ub",ring_glColor4ub);
	RING_API_REGISTER("glcolor4ubv",ring_glColor4ubv);
	RING_API_REGISTER("glcolor4ui",ring_glColor4ui);
	RING_API_REGISTER("glcolor4uiv",ring_glColor4uiv);
	RING_API_REGISTER("glcolor4us",ring_glColor4us);
	RING_API_REGISTER("glcolor4usv",ring_glColor4usv);
	RING_API_REGISTER("glcolormask",ring_glColorMask);
	RING_API_REGISTER("glcolormaterial",ring_glColorMaterial);
	RING_API_REGISTER("glcolorpointer",ring_glColorPointer);
	RING_API_REGISTER("glcopypixels",ring_glCopyPixels);
	RING_API_REGISTER("glcopyteximage1d",ring_glCopyTexImage1D);
	RING_API_REGISTER("glcopyteximage2d",ring_glCopyTexImage2D);
	RING_API_REGISTER("glcopytexsubimage1d",ring_glCopyTexSubImage1D);
	RING_API_REGISTER("glcopytexsubimage2d",ring_glCopyTexSubImage2D);
	RING_API_REGISTER("glcullface",ring_glCullFace);
	RING_API_REGISTER("gldeletelists",ring_glDeleteLists);
	RING_API_REGISTER("gldeletetextures",ring_glDeleteTextures);
	RING_API_REGISTER("gldepthfunc",ring_glDepthFunc);
	RING_API_REGISTER("gldepthmask",ring_glDepthMask);
	RING_API_REGISTER("gldepthrange",ring_glDepthRange);
	RING_API_REGISTER("gldisable",ring_glDisable);
	RING_API_REGISTER("gldisableclientstate",ring_glDisableClientState);
	RING_API_REGISTER("gldrawarrays",ring_glDrawArrays);
	RING_API_REGISTER("gldrawbuffer",ring_glDrawBuffer);
	RING_API_REGISTER("gldrawelements",ring_glDrawElements);
	RING_API_REGISTER("gldrawpixels",ring_glDrawPixels);
	RING_API_REGISTER("gledgeflag",ring_glEdgeFlag);
	RING_API_REGISTER("gledgeflagpointer",ring_glEdgeFlagPointer);
	RING_API_REGISTER("gledgeflagv",ring_glEdgeFlagv);
	RING_API_REGISTER("glenable",ring_glEnable);
	RING_API_REGISTER("glenableclientstate",ring_glEnableClientState);
	RING_API_REGISTER("glend",ring_glEnd);
	RING_API_REGISTER("glendlist",ring_glEndList);
	RING_API_REGISTER("glevalcoord1d",ring_glEvalCoord1d);
	RING_API_REGISTER("glevalcoord1dv",ring_glEvalCoord1dv);
	RING_API_REGISTER("glevalcoord1f",ring_glEvalCoord1f);
	RING_API_REGISTER("glevalcoord1fv",ring_glEvalCoord1fv);
	RING_API_REGISTER("glevalcoord2d",ring_glEvalCoord2d);
	RING_API_REGISTER("glevalcoord2dv",ring_glEvalCoord2dv);
	RING_API_REGISTER("glevalcoord2f",ring_glEvalCoord2f);
	RING_API_REGISTER("glevalcoord2fv",ring_glEvalCoord2fv);
	RING_API_REGISTER("glevalmesh1",ring_glEvalMesh1);
	RING_API_REGISTER("glevalmesh2",ring_glEvalMesh2);
	RING_API_REGISTER("glevalpoint1",ring_glEvalPoint1);
	RING_API_REGISTER("glevalpoint2",ring_glEvalPoint2);
	RING_API_REGISTER("glfeedbackbuffer",ring_glFeedbackBuffer);
	RING_API_REGISTER("glfinish",ring_glFinish);
	RING_API_REGISTER("glflush",ring_glFlush);
	RING_API_REGISTER("glfogf",ring_glFogf);
	RING_API_REGISTER("glfogfv",ring_glFogfv);
	RING_API_REGISTER("glfogi",ring_glFogi);
	RING_API_REGISTER("glfogiv",ring_glFogiv);
	RING_API_REGISTER("glfrontface",ring_glFrontFace);
	RING_API_REGISTER("glfrustum",ring_glFrustum);
	RING_API_REGISTER("glgenlists",ring_glGenLists);
	RING_API_REGISTER("glgentextures",ring_glGenTextures);
	RING_API_REGISTER("glgetbooleanv",ring_glGetBooleanv);
	RING_API_REGISTER("glgetclipplane",ring_glGetClipPlane);
	RING_API_REGISTER("glgetdoublev",ring_glGetDoublev);
	RING_API_REGISTER("glgeterror",ring_glGetError);
	RING_API_REGISTER("glgetfloatv",ring_glGetFloatv);
	RING_API_REGISTER("glgetintegerv",ring_glGetIntegerv);
	RING_API_REGISTER("glgetlightfv",ring_glGetLightfv);
	RING_API_REGISTER("glgetlightiv",ring_glGetLightiv);
	RING_API_REGISTER("glgetmapdv",ring_glGetMapdv);
	RING_API_REGISTER("glgetmapfv",ring_glGetMapfv);
	RING_API_REGISTER("glgetmapiv",ring_glGetMapiv);
	RING_API_REGISTER("glgetmaterialfv",ring_glGetMaterialfv);
	RING_API_REGISTER("glgetmaterialiv",ring_glGetMaterialiv);
	RING_API_REGISTER("glgetpixelmapfv",ring_glGetPixelMapfv);
	RING_API_REGISTER("glgetpixelmapuiv",ring_glGetPixelMapuiv);
	RING_API_REGISTER("glgetpixelmapusv",ring_glGetPixelMapusv);
	RING_API_REGISTER("glgetpointerv",ring_glGetPointerv);
	RING_API_REGISTER("glgetpolygonstipple",ring_glGetPolygonStipple);
	RING_API_REGISTER("glgetstring",ring_glGetString);
	RING_API_REGISTER("glgettexenvfv",ring_glGetTexEnvfv);
	RING_API_REGISTER("glgettexenviv",ring_glGetTexEnviv);
	RING_API_REGISTER("glgettexgendv",ring_glGetTexGendv);
	RING_API_REGISTER("glgettexgenfv",ring_glGetTexGenfv);
	RING_API_REGISTER("glgettexgeniv",ring_glGetTexGeniv);
	RING_API_REGISTER("glgetteximage",ring_glGetTexImage);
	RING_API_REGISTER("glgettexlevelparameterfv",ring_glGetTexLevelParameterfv);
	RING_API_REGISTER("glgettexlevelparameteriv",ring_glGetTexLevelParameteriv);
	RING_API_REGISTER("glgettexparameterfv",ring_glGetTexParameterfv);
	RING_API_REGISTER("glgettexparameteriv",ring_glGetTexParameteriv);
	RING_API_REGISTER("glhint",ring_glHint);
	RING_API_REGISTER("glindexmask",ring_glIndexMask);
	RING_API_REGISTER("glindexpointer",ring_glIndexPointer);
	RING_API_REGISTER("glindexd",ring_glIndexd);
	RING_API_REGISTER("glindexdv",ring_glIndexdv);
	RING_API_REGISTER("glindexf",ring_glIndexf);
	RING_API_REGISTER("glindexfv",ring_glIndexfv);
	RING_API_REGISTER("glindexi",ring_glIndexi);
	RING_API_REGISTER("glindexiv",ring_glIndexiv);
	RING_API_REGISTER("glindexs",ring_glIndexs);
	RING_API_REGISTER("glindexsv",ring_glIndexsv);
	RING_API_REGISTER("glindexub",ring_glIndexub);
	RING_API_REGISTER("glindexubv",ring_glIndexubv);
	RING_API_REGISTER("glinitnames",ring_glInitNames);
	RING_API_REGISTER("glinterleavedarrays",ring_glInterleavedArrays);
	RING_API_REGISTER("glisenabled",ring_glIsEnabled);
	RING_API_REGISTER("glislist",ring_glIsList);
	RING_API_REGISTER("glistexture",ring_glIsTexture);
	RING_API_REGISTER("gllightmodelf",ring_glLightModelf);
	RING_API_REGISTER("gllightmodelfv",ring_glLightModelfv);
	RING_API_REGISTER("gllightmodeli",ring_glLightModeli);
	RING_API_REGISTER("gllightmodeliv",ring_glLightModeliv);
	RING_API_REGISTER("gllightf",ring_glLightf);
	RING_API_REGISTER("gllightfv",ring_glLightfv);
	RING_API_REGISTER("gllighti",ring_glLighti);
	RING_API_REGISTER("gllightiv",ring_glLightiv);
	RING_API_REGISTER("gllinestipple",ring_glLineStipple);
	RING_API_REGISTER("gllinewidth",ring_glLineWidth);
	RING_API_REGISTER("gllistbase",ring_glListBase);
	RING_API_REGISTER("glloadidentity",ring_glLoadIdentity);
	RING_API_REGISTER("glloadmatrixd",ring_glLoadMatrixd);
	RING_API_REGISTER("glloadmatrixf",ring_glLoadMatrixf);
	RING_API_REGISTER("glloadname",ring_glLoadName);
	RING_API_REGISTER("gllogicop",ring_glLogicOp);
	RING_API_REGISTER("glmap1d",ring_glMap1d);
	RING_API_REGISTER("glmap1f",ring_glMap1f);
	RING_API_REGISTER("glmap2d",ring_glMap2d);
	RING_API_REGISTER("glmap2f",ring_glMap2f);
	RING_API_REGISTER("glmapgrid1d",ring_glMapGrid1d);
	RING_API_REGISTER("glmapgrid1f",ring_glMapGrid1f);
	RING_API_REGISTER("glmapgrid2d",ring_glMapGrid2d);
	RING_API_REGISTER("glmapgrid2f",ring_glMapGrid2f);
	RING_API_REGISTER("glmaterialf",ring_glMaterialf);
	RING_API_REGISTER("glmaterialfv",ring_glMaterialfv);
	RING_API_REGISTER("glmateriali",ring_glMateriali);
	RING_API_REGISTER("glmaterialiv",ring_glMaterialiv);
	RING_API_REGISTER("glmatrixmode",ring_glMatrixMode);
	RING_API_REGISTER("glmultmatrixd",ring_glMultMatrixd);
	RING_API_REGISTER("glmultmatrixf",ring_glMultMatrixf);
	RING_API_REGISTER("glnewlist",ring_glNewList);
	RING_API_REGISTER("glnormal3b",ring_glNormal3b);
	RING_API_REGISTER("glnormal3bv",ring_glNormal3bv);
	RING_API_REGISTER("glnormal3d",ring_glNormal3d);
	RING_API_REGISTER("glnormal3dv",ring_glNormal3dv);
	RING_API_REGISTER("glnormal3f",ring_glNormal3f);
	RING_API_REGISTER("glnormal3fv",ring_glNormal3fv);
	RING_API_REGISTER("glnormal3i",ring_glNormal3i);
	RING_API_REGISTER("glnormal3iv",ring_glNormal3iv);
	RING_API_REGISTER("glnormal3s",ring_glNormal3s);
	RING_API_REGISTER("glnormal3sv",ring_glNormal3sv);
	RING_API_REGISTER("glnormalpointer",ring_glNormalPointer);
	RING_API_REGISTER("glortho",ring_glOrtho);
	RING_API_REGISTER("glpassthrough",ring_glPassThrough);
	RING_API_REGISTER("glpixelmapfv",ring_glPixelMapfv);
	RING_API_REGISTER("glpixelmapuiv",ring_glPixelMapuiv);
	RING_API_REGISTER("glpixelmapusv",ring_glPixelMapusv);
	RING_API_REGISTER("glpixelstoref",ring_glPixelStoref);
	RING_API_REGISTER("glpixelstorei",ring_glPixelStorei);
	RING_API_REGISTER("glpixeltransferf",ring_glPixelTransferf);
	RING_API_REGISTER("glpixeltransferi",ring_glPixelTransferi);
	RING_API_REGISTER("glpixelzoom",ring_glPixelZoom);
	RING_API_REGISTER("glpointsize",ring_glPointSize);
	RING_API_REGISTER("glpolygonmode",ring_glPolygonMode);
	RING_API_REGISTER("glpolygonoffset",ring_glPolygonOffset);
	RING_API_REGISTER("glpolygonstipple",ring_glPolygonStipple);
	RING_API_REGISTER("glpopattrib",ring_glPopAttrib);
	RING_API_REGISTER("glpopclientattrib",ring_glPopClientAttrib);
	RING_API_REGISTER("glpopmatrix",ring_glPopMatrix);
	RING_API_REGISTER("glpopname",ring_glPopName);
	RING_API_REGISTER("glprioritizetextures",ring_glPrioritizeTextures);
	RING_API_REGISTER("glpushattrib",ring_glPushAttrib);
	RING_API_REGISTER("glpushclientattrib",ring_glPushClientAttrib);
	RING_API_REGISTER("glpushmatrix",ring_glPushMatrix);
	RING_API_REGISTER("glpushname",ring_glPushName);
	RING_API_REGISTER("glrasterpos2d",ring_glRasterPos2d);
	RING_API_REGISTER("glrasterpos2dv",ring_glRasterPos2dv);
	RING_API_REGISTER("glrasterpos2f",ring_glRasterPos2f);
	RING_API_REGISTER("glrasterpos2fv",ring_glRasterPos2fv);
	RING_API_REGISTER("glrasterpos2i",ring_glRasterPos2i);
	RING_API_REGISTER("glrasterpos2iv",ring_glRasterPos2iv);
	RING_API_REGISTER("glrasterpos2s",ring_glRasterPos2s);
	RING_API_REGISTER("glrasterpos2sv",ring_glRasterPos2sv);
	RING_API_REGISTER("glrasterpos3d",ring_glRasterPos3d);
	RING_API_REGISTER("glrasterpos3dv",ring_glRasterPos3dv);
	RING_API_REGISTER("glrasterpos3f",ring_glRasterPos3f);
	RING_API_REGISTER("glrasterpos3fv",ring_glRasterPos3fv);
	RING_API_REGISTER("glrasterpos3i",ring_glRasterPos3i);
	RING_API_REGISTER("glrasterpos3iv",ring_glRasterPos3iv);
	RING_API_REGISTER("glrasterpos3s",ring_glRasterPos3s);
	RING_API_REGISTER("glrasterpos3sv",ring_glRasterPos3sv);
	RING_API_REGISTER("glrasterpos4d",ring_glRasterPos4d);
	RING_API_REGISTER("glrasterpos4dv",ring_glRasterPos4dv);
	RING_API_REGISTER("glrasterpos4f",ring_glRasterPos4f);
	RING_API_REGISTER("glrasterpos4fv",ring_glRasterPos4fv);
	RING_API_REGISTER("glrasterpos4i",ring_glRasterPos4i);
	RING_API_REGISTER("glrasterpos4iv",ring_glRasterPos4iv);
	RING_API_REGISTER("glrasterpos4s",ring_glRasterPos4s);
	RING_API_REGISTER("glrasterpos4sv",ring_glRasterPos4sv);
	RING_API_REGISTER("glreadbuffer",ring_glReadBuffer);
	RING_API_REGISTER("glreadpixels",ring_glReadPixels);
	RING_API_REGISTER("glrectd",ring_glRectd);
	RING_API_REGISTER("glrectdv",ring_glRectdv);
	RING_API_REGISTER("glrectf",ring_glRectf);
	RING_API_REGISTER("glrectfv",ring_glRectfv);
	RING_API_REGISTER("glrecti",ring_glRecti);
	RING_API_REGISTER("glrectiv",ring_glRectiv);
	RING_API_REGISTER("glrects",ring_glRects);
	RING_API_REGISTER("glrectsv",ring_glRectsv);
	RING_API_REGISTER("glrendermode",ring_glRenderMode);
	RING_API_REGISTER("glrotated",ring_glRotated);
	RING_API_REGISTER("glrotatef",ring_glRotatef);
	RING_API_REGISTER("glscaled",ring_glScaled);
	RING_API_REGISTER("glscalef",ring_glScalef);
	RING_API_REGISTER("glscissor",ring_glScissor);
	RING_API_REGISTER("glselectbuffer",ring_glSelectBuffer);
	RING_API_REGISTER("glshademodel",ring_glShadeModel);
	RING_API_REGISTER("glstencilfunc",ring_glStencilFunc);
	RING_API_REGISTER("glstencilmask",ring_glStencilMask);
	RING_API_REGISTER("glstencilop",ring_glStencilOp);
	RING_API_REGISTER("gltexcoord1d",ring_glTexCoord1d);
	RING_API_REGISTER("gltexcoord1dv",ring_glTexCoord1dv);
	RING_API_REGISTER("gltexcoord1f",ring_glTexCoord1f);
	RING_API_REGISTER("gltexcoord1fv",ring_glTexCoord1fv);
	RING_API_REGISTER("gltexcoord1i",ring_glTexCoord1i);
	RING_API_REGISTER("gltexcoord1iv",ring_glTexCoord1iv);
	RING_API_REGISTER("gltexcoord1s",ring_glTexCoord1s);
	RING_API_REGISTER("gltexcoord1sv",ring_glTexCoord1sv);
	RING_API_REGISTER("gltexcoord2d",ring_glTexCoord2d);
	RING_API_REGISTER("gltexcoord2dv",ring_glTexCoord2dv);
	RING_API_REGISTER("gltexcoord2f",ring_glTexCoord2f);
	RING_API_REGISTER("gltexcoord2fv",ring_glTexCoord2fv);
	RING_API_REGISTER("gltexcoord2i",ring_glTexCoord2i);
	RING_API_REGISTER("gltexcoord2iv",ring_glTexCoord2iv);
	RING_API_REGISTER("gltexcoord2s",ring_glTexCoord2s);
	RING_API_REGISTER("gltexcoord2sv",ring_glTexCoord2sv);
	RING_API_REGISTER("gltexcoord3d",ring_glTexCoord3d);
	RING_API_REGISTER("gltexcoord3dv",ring_glTexCoord3dv);
	RING_API_REGISTER("gltexcoord3f",ring_glTexCoord3f);
	RING_API_REGISTER("gltexcoord3fv",ring_glTexCoord3fv);
	RING_API_REGISTER("gltexcoord3i",ring_glTexCoord3i);
	RING_API_REGISTER("gltexcoord3iv",ring_glTexCoord3iv);
	RING_API_REGISTER("gltexcoord3s",ring_glTexCoord3s);
	RING_API_REGISTER("gltexcoord3sv",ring_glTexCoord3sv);
	RING_API_REGISTER("gltexcoord4d",ring_glTexCoord4d);
	RING_API_REGISTER("gltexcoord4dv",ring_glTexCoord4dv);
	RING_API_REGISTER("gltexcoord4f",ring_glTexCoord4f);
	RING_API_REGISTER("gltexcoord4fv",ring_glTexCoord4fv);
	RING_API_REGISTER("gltexcoord4i",ring_glTexCoord4i);
	RING_API_REGISTER("gltexcoord4iv",ring_glTexCoord4iv);
	RING_API_REGISTER("gltexcoord4s",ring_glTexCoord4s);
	RING_API_REGISTER("gltexcoord4sv",ring_glTexCoord4sv);
	RING_API_REGISTER("gltexcoordpointer",ring_glTexCoordPointer);
	RING_API_REGISTER("gltexenvf",ring_glTexEnvf);
	RING_API_REGISTER("gltexenvfv",ring_glTexEnvfv);
	RING_API_REGISTER("gltexenvi",ring_glTexEnvi);
	RING_API_REGISTER("gltexenviv",ring_glTexEnviv);
	RING_API_REGISTER("gltexgend",ring_glTexGend);
	RING_API_REGISTER("gltexgendv",ring_glTexGendv);
	RING_API_REGISTER("gltexgenf",ring_glTexGenf);
	RING_API_REGISTER("gltexgenfv",ring_glTexGenfv);
	RING_API_REGISTER("gltexgeni",ring_glTexGeni);
	RING_API_REGISTER("gltexgeniv",ring_glTexGeniv);
	RING_API_REGISTER("glteximage1d",ring_glTexImage1D);
	RING_API_REGISTER("glteximage2d",ring_glTexImage2D);
	RING_API_REGISTER("gltexparameterf",ring_glTexParameterf);
	RING_API_REGISTER("gltexparameterfv",ring_glTexParameterfv);
	RING_API_REGISTER("gltexparameteri",ring_glTexParameteri);
	RING_API_REGISTER("gltexparameteriv",ring_glTexParameteriv);
	RING_API_REGISTER("gltexsubimage1d",ring_glTexSubImage1D);
	RING_API_REGISTER("gltexsubimage2d",ring_glTexSubImage2D);
	RING_API_REGISTER("gltranslated",ring_glTranslated);
	RING_API_REGISTER("gltranslatef",ring_glTranslatef);
	RING_API_REGISTER("glvertex2d",ring_glVertex2d);
	RING_API_REGISTER("glvertex2dv",ring_glVertex2dv);
	RING_API_REGISTER("glvertex2f",ring_glVertex2f);
	RING_API_REGISTER("glvertex2fv",ring_glVertex2fv);
	RING_API_REGISTER("glvertex2i",ring_glVertex2i);
	RING_API_REGISTER("glvertex2iv",ring_glVertex2iv);
	RING_API_REGISTER("glvertex2s",ring_glVertex2s);
	RING_API_REGISTER("glvertex2sv",ring_glVertex2sv);
	RING_API_REGISTER("glvertex3d",ring_glVertex3d);
	RING_API_REGISTER("glvertex3dv",ring_glVertex3dv);
	RING_API_REGISTER("glvertex3f",ring_glVertex3f);
	RING_API_REGISTER("glvertex3fv",ring_glVertex3fv);
	RING_API_REGISTER("glvertex3i",ring_glVertex3i);
	RING_API_REGISTER("glvertex3iv",ring_glVertex3iv);
	RING_API_REGISTER("glvertex3s",ring_glVertex3s);
	RING_API_REGISTER("glvertex3sv",ring_glVertex3sv);
	RING_API_REGISTER("glvertex4d",ring_glVertex4d);
	RING_API_REGISTER("glvertex4dv",ring_glVertex4dv);
	RING_API_REGISTER("glvertex4f",ring_glVertex4f);
	RING_API_REGISTER("glvertex4fv",ring_glVertex4fv);
	RING_API_REGISTER("glvertex4i",ring_glVertex4i);
	RING_API_REGISTER("glvertex4iv",ring_glVertex4iv);
	RING_API_REGISTER("glvertex4s",ring_glVertex4s);
	RING_API_REGISTER("glvertex4sv",ring_glVertex4sv);
	RING_API_REGISTER("glvertexpointer",ring_glVertexPointer);
	RING_API_REGISTER("glviewport",ring_glViewport);
	RING_API_REGISTER("glbindvertexarray",ring_glBindVertexArray);
	RING_API_REGISTER("glgenvertexarrays",ring_glGenVertexArrays);
	RING_API_REGISTER("glewinit",ring_glewInit);
	RING_API_REGISTER("glewissupported",ring_glewIsSupported);
	RING_API_REGISTER("glewgetextension",ring_glewGetExtension);
	RING_API_REGISTER("glewgeterrorstring",ring_glewGetErrorString);
	RING_API_REGISTER("glewgetstring",ring_glewGetString);
	RING_API_REGISTER("get_gl_zero",ring_get_gl_zero);
	RING_API_REGISTER("get_gl_false",ring_get_gl_false);
	RING_API_REGISTER("get_gl_logic_op",ring_get_gl_logic_op);
	RING_API_REGISTER("get_gl_none",ring_get_gl_none);
	RING_API_REGISTER("get_gl_texture_components",ring_get_gl_texture_components);
	RING_API_REGISTER("get_gl_no_error",ring_get_gl_no_error);
	RING_API_REGISTER("get_gl_points",ring_get_gl_points);
	RING_API_REGISTER("get_gl_current_bit",ring_get_gl_current_bit);
	RING_API_REGISTER("get_gl_true",ring_get_gl_true);
	RING_API_REGISTER("get_gl_one",ring_get_gl_one);
	RING_API_REGISTER("get_gl_client_pixel_store_bit",ring_get_gl_client_pixel_store_bit);
	RING_API_REGISTER("get_gl_lines",ring_get_gl_lines);
	RING_API_REGISTER("get_gl_line_loop",ring_get_gl_line_loop);
	RING_API_REGISTER("get_gl_point_bit",ring_get_gl_point_bit);
	RING_API_REGISTER("get_gl_client_vertex_array_bit",ring_get_gl_client_vertex_array_bit);
	RING_API_REGISTER("get_gl_line_strip",ring_get_gl_line_strip);
	RING_API_REGISTER("get_gl_line_bit",ring_get_gl_line_bit);
	RING_API_REGISTER("get_gl_triangles",ring_get_gl_triangles);
	RING_API_REGISTER("get_gl_triangle_strip",ring_get_gl_triangle_strip);
	RING_API_REGISTER("get_gl_triangle_fan",ring_get_gl_triangle_fan);
	RING_API_REGISTER("get_gl_quads",ring_get_gl_quads);
	RING_API_REGISTER("get_gl_quad_strip",ring_get_gl_quad_strip);
	RING_API_REGISTER("get_gl_polygon_bit",ring_get_gl_polygon_bit);
	RING_API_REGISTER("get_gl_polygon",ring_get_gl_polygon);
	RING_API_REGISTER("get_gl_polygon_stipple_bit",ring_get_gl_polygon_stipple_bit);
	RING_API_REGISTER("get_gl_pixel_mode_bit",ring_get_gl_pixel_mode_bit);
	RING_API_REGISTER("get_gl_lighting_bit",ring_get_gl_lighting_bit);
	RING_API_REGISTER("get_gl_fog_bit",ring_get_gl_fog_bit);
	RING_API_REGISTER("get_gl_depth_buffer_bit",ring_get_gl_depth_buffer_bit);
	RING_API_REGISTER("get_gl_accum",ring_get_gl_accum);
	RING_API_REGISTER("get_gl_load",ring_get_gl_load);
	RING_API_REGISTER("get_gl_return",ring_get_gl_return);
	RING_API_REGISTER("get_gl_mult",ring_get_gl_mult);
	RING_API_REGISTER("get_gl_add",ring_get_gl_add);
	RING_API_REGISTER("get_gl_never",ring_get_gl_never);
	RING_API_REGISTER("get_gl_accum_buffer_bit",ring_get_gl_accum_buffer_bit);
	RING_API_REGISTER("get_gl_less",ring_get_gl_less);
	RING_API_REGISTER("get_gl_equal",ring_get_gl_equal);
	RING_API_REGISTER("get_gl_lequal",ring_get_gl_lequal);
	RING_API_REGISTER("get_gl_greater",ring_get_gl_greater);
	RING_API_REGISTER("get_gl_notequal",ring_get_gl_notequal);
	RING_API_REGISTER("get_gl_gequal",ring_get_gl_gequal);
	RING_API_REGISTER("get_gl_always",ring_get_gl_always);
	RING_API_REGISTER("get_gl_src_color",ring_get_gl_src_color);
	RING_API_REGISTER("get_gl_one_minus_src_color",ring_get_gl_one_minus_src_color);
	RING_API_REGISTER("get_gl_src_alpha",ring_get_gl_src_alpha);
	RING_API_REGISTER("get_gl_one_minus_src_alpha",ring_get_gl_one_minus_src_alpha);
	RING_API_REGISTER("get_gl_dst_alpha",ring_get_gl_dst_alpha);
	RING_API_REGISTER("get_gl_one_minus_dst_alpha",ring_get_gl_one_minus_dst_alpha);
	RING_API_REGISTER("get_gl_dst_color",ring_get_gl_dst_color);
	RING_API_REGISTER("get_gl_one_minus_dst_color",ring_get_gl_one_minus_dst_color);
	RING_API_REGISTER("get_gl_src_alpha_saturate",ring_get_gl_src_alpha_saturate);
	RING_API_REGISTER("get_gl_stencil_buffer_bit",ring_get_gl_stencil_buffer_bit);
	RING_API_REGISTER("get_gl_front_left",ring_get_gl_front_left);
	RING_API_REGISTER("get_gl_front_right",ring_get_gl_front_right);
	RING_API_REGISTER("get_gl_back_left",ring_get_gl_back_left);
	RING_API_REGISTER("get_gl_back_right",ring_get_gl_back_right);
	RING_API_REGISTER("get_gl_front",ring_get_gl_front);
	RING_API_REGISTER("get_gl_back",ring_get_gl_back);
	RING_API_REGISTER("get_gl_left",ring_get_gl_left);
	RING_API_REGISTER("get_gl_right",ring_get_gl_right);
	RING_API_REGISTER("get_gl_front_and_back",ring_get_gl_front_and_back);
	RING_API_REGISTER("get_gl_aux0",ring_get_gl_aux0);
	RING_API_REGISTER("get_gl_aux1",ring_get_gl_aux1);
	RING_API_REGISTER("get_gl_aux2",ring_get_gl_aux2);
	RING_API_REGISTER("get_gl_aux3",ring_get_gl_aux3);
	RING_API_REGISTER("get_gl_invalid_enum",ring_get_gl_invalid_enum);
	RING_API_REGISTER("get_gl_invalid_value",ring_get_gl_invalid_value);
	RING_API_REGISTER("get_gl_invalid_operation",ring_get_gl_invalid_operation);
	RING_API_REGISTER("get_gl_stack_overflow",ring_get_gl_stack_overflow);
	RING_API_REGISTER("get_gl_stack_underflow",ring_get_gl_stack_underflow);
	RING_API_REGISTER("get_gl_out_of_memory",ring_get_gl_out_of_memory);
	RING_API_REGISTER("get_gl_2d",ring_get_gl_2d);
	RING_API_REGISTER("get_gl_3d",ring_get_gl_3d);
	RING_API_REGISTER("get_gl_3d_color",ring_get_gl_3d_color);
	RING_API_REGISTER("get_gl_3d_color_texture",ring_get_gl_3d_color_texture);
	RING_API_REGISTER("get_gl_4d_color_texture",ring_get_gl_4d_color_texture);
	RING_API_REGISTER("get_gl_pass_through_token",ring_get_gl_pass_through_token);
	RING_API_REGISTER("get_gl_point_token",ring_get_gl_point_token);
	RING_API_REGISTER("get_gl_line_token",ring_get_gl_line_token);
	RING_API_REGISTER("get_gl_polygon_token",ring_get_gl_polygon_token);
	RING_API_REGISTER("get_gl_bitmap_token",ring_get_gl_bitmap_token);
	RING_API_REGISTER("get_gl_draw_pixel_token",ring_get_gl_draw_pixel_token);
	RING_API_REGISTER("get_gl_copy_pixel_token",ring_get_gl_copy_pixel_token);
	RING_API_REGISTER("get_gl_line_reset_token",ring_get_gl_line_reset_token);
	RING_API_REGISTER("get_gl_exp",ring_get_gl_exp);
	RING_API_REGISTER("get_gl_viewport_bit",ring_get_gl_viewport_bit);
	RING_API_REGISTER("get_gl_exp2",ring_get_gl_exp2);
	RING_API_REGISTER("get_gl_cw",ring_get_gl_cw);
	RING_API_REGISTER("get_gl_ccw",ring_get_gl_ccw);
	RING_API_REGISTER("get_gl_coeff",ring_get_gl_coeff);
	RING_API_REGISTER("get_gl_order",ring_get_gl_order);
	RING_API_REGISTER("get_gl_domain",ring_get_gl_domain);
	RING_API_REGISTER("get_gl_current_color",ring_get_gl_current_color);
	RING_API_REGISTER("get_gl_current_index",ring_get_gl_current_index);
	RING_API_REGISTER("get_gl_current_normal",ring_get_gl_current_normal);
	RING_API_REGISTER("get_gl_current_texture_coords",ring_get_gl_current_texture_coords);
	RING_API_REGISTER("get_gl_current_raster_color",ring_get_gl_current_raster_color);
	RING_API_REGISTER("get_gl_current_raster_index",ring_get_gl_current_raster_index);
	RING_API_REGISTER("get_gl_current_raster_texture_coords",ring_get_gl_current_raster_texture_coords);
	RING_API_REGISTER("get_gl_current_raster_position",ring_get_gl_current_raster_position);
	RING_API_REGISTER("get_gl_current_raster_position_valid",ring_get_gl_current_raster_position_valid);
	RING_API_REGISTER("get_gl_current_raster_distance",ring_get_gl_current_raster_distance);
	RING_API_REGISTER("get_gl_point_smooth",ring_get_gl_point_smooth);
	RING_API_REGISTER("get_gl_point_size",ring_get_gl_point_size);
	RING_API_REGISTER("get_gl_point_size_range",ring_get_gl_point_size_range);
	RING_API_REGISTER("get_gl_point_size_granularity",ring_get_gl_point_size_granularity);
	RING_API_REGISTER("get_gl_line_smooth",ring_get_gl_line_smooth);
	RING_API_REGISTER("get_gl_line_width",ring_get_gl_line_width);
	RING_API_REGISTER("get_gl_line_width_range",ring_get_gl_line_width_range);
	RING_API_REGISTER("get_gl_line_width_granularity",ring_get_gl_line_width_granularity);
	RING_API_REGISTER("get_gl_line_stipple",ring_get_gl_line_stipple);
	RING_API_REGISTER("get_gl_line_stipple_pattern",ring_get_gl_line_stipple_pattern);
	RING_API_REGISTER("get_gl_line_stipple_repeat",ring_get_gl_line_stipple_repeat);
	RING_API_REGISTER("get_gl_list_mode",ring_get_gl_list_mode);
	RING_API_REGISTER("get_gl_max_list_nesting",ring_get_gl_max_list_nesting);
	RING_API_REGISTER("get_gl_list_base",ring_get_gl_list_base);
	RING_API_REGISTER("get_gl_list_index",ring_get_gl_list_index);
	RING_API_REGISTER("get_gl_polygon_mode",ring_get_gl_polygon_mode);
	RING_API_REGISTER("get_gl_polygon_smooth",ring_get_gl_polygon_smooth);
	RING_API_REGISTER("get_gl_polygon_stipple",ring_get_gl_polygon_stipple);
	RING_API_REGISTER("get_gl_edge_flag",ring_get_gl_edge_flag);
	RING_API_REGISTER("get_gl_cull_face",ring_get_gl_cull_face);
	RING_API_REGISTER("get_gl_cull_face_mode",ring_get_gl_cull_face_mode);
	RING_API_REGISTER("get_gl_front_face",ring_get_gl_front_face);
	RING_API_REGISTER("get_gl_lighting",ring_get_gl_lighting);
	RING_API_REGISTER("get_gl_light_model_local_viewer",ring_get_gl_light_model_local_viewer);
	RING_API_REGISTER("get_gl_light_model_two_side",ring_get_gl_light_model_two_side);
	RING_API_REGISTER("get_gl_light_model_ambient",ring_get_gl_light_model_ambient);
	RING_API_REGISTER("get_gl_shade_model",ring_get_gl_shade_model);
	RING_API_REGISTER("get_gl_color_material_face",ring_get_gl_color_material_face);
	RING_API_REGISTER("get_gl_color_material_parameter",ring_get_gl_color_material_parameter);
	RING_API_REGISTER("get_gl_color_material",ring_get_gl_color_material);
	RING_API_REGISTER("get_gl_fog",ring_get_gl_fog);
	RING_API_REGISTER("get_gl_fog_index",ring_get_gl_fog_index);
	RING_API_REGISTER("get_gl_fog_density",ring_get_gl_fog_density);
	RING_API_REGISTER("get_gl_fog_start",ring_get_gl_fog_start);
	RING_API_REGISTER("get_gl_fog_end",ring_get_gl_fog_end);
	RING_API_REGISTER("get_gl_fog_mode",ring_get_gl_fog_mode);
	RING_API_REGISTER("get_gl_fog_color",ring_get_gl_fog_color);
	RING_API_REGISTER("get_gl_depth_range",ring_get_gl_depth_range);
	RING_API_REGISTER("get_gl_depth_test",ring_get_gl_depth_test);
	RING_API_REGISTER("get_gl_depth_writemask",ring_get_gl_depth_writemask);
	RING_API_REGISTER("get_gl_depth_clear_value",ring_get_gl_depth_clear_value);
	RING_API_REGISTER("get_gl_depth_func",ring_get_gl_depth_func);
	RING_API_REGISTER("get_gl_accum_clear_value",ring_get_gl_accum_clear_value);
	RING_API_REGISTER("get_gl_stencil_test",ring_get_gl_stencil_test);
	RING_API_REGISTER("get_gl_stencil_clear_value",ring_get_gl_stencil_clear_value);
	RING_API_REGISTER("get_gl_stencil_func",ring_get_gl_stencil_func);
	RING_API_REGISTER("get_gl_stencil_value_mask",ring_get_gl_stencil_value_mask);
	RING_API_REGISTER("get_gl_stencil_fail",ring_get_gl_stencil_fail);
	RING_API_REGISTER("get_gl_stencil_pass_depth_fail",ring_get_gl_stencil_pass_depth_fail);
	RING_API_REGISTER("get_gl_stencil_pass_depth_pass",ring_get_gl_stencil_pass_depth_pass);
	RING_API_REGISTER("get_gl_stencil_ref",ring_get_gl_stencil_ref);
	RING_API_REGISTER("get_gl_stencil_writemask",ring_get_gl_stencil_writemask);
	RING_API_REGISTER("get_gl_matrix_mode",ring_get_gl_matrix_mode);
	RING_API_REGISTER("get_gl_normalize",ring_get_gl_normalize);
	RING_API_REGISTER("get_gl_viewport",ring_get_gl_viewport);
	RING_API_REGISTER("get_gl_modelview_stack_depth",ring_get_gl_modelview_stack_depth);
	RING_API_REGISTER("get_gl_projection_stack_depth",ring_get_gl_projection_stack_depth);
	RING_API_REGISTER("get_gl_texture_stack_depth",ring_get_gl_texture_stack_depth);
	RING_API_REGISTER("get_gl_modelview_matrix",ring_get_gl_modelview_matrix);
	RING_API_REGISTER("get_gl_projection_matrix",ring_get_gl_projection_matrix);
	RING_API_REGISTER("get_gl_texture_matrix",ring_get_gl_texture_matrix);
	RING_API_REGISTER("get_gl_attrib_stack_depth",ring_get_gl_attrib_stack_depth);
	RING_API_REGISTER("get_gl_client_attrib_stack_depth",ring_get_gl_client_attrib_stack_depth);
	RING_API_REGISTER("get_gl_alpha_test",ring_get_gl_alpha_test);
	RING_API_REGISTER("get_gl_alpha_test_func",ring_get_gl_alpha_test_func);
	RING_API_REGISTER("get_gl_alpha_test_ref",ring_get_gl_alpha_test_ref);
	RING_API_REGISTER("get_gl_dither",ring_get_gl_dither);
	RING_API_REGISTER("get_gl_blend_dst",ring_get_gl_blend_dst);
	RING_API_REGISTER("get_gl_blend_src",ring_get_gl_blend_src);
	RING_API_REGISTER("get_gl_blend",ring_get_gl_blend);
	RING_API_REGISTER("get_gl_logic_op_mode",ring_get_gl_logic_op_mode);
	RING_API_REGISTER("get_gl_index_logic_op",ring_get_gl_index_logic_op);
	RING_API_REGISTER("get_gl_color_logic_op",ring_get_gl_color_logic_op);
	RING_API_REGISTER("get_gl_aux_buffers",ring_get_gl_aux_buffers);
	RING_API_REGISTER("get_gl_draw_buffer",ring_get_gl_draw_buffer);
	RING_API_REGISTER("get_gl_read_buffer",ring_get_gl_read_buffer);
	RING_API_REGISTER("get_gl_scissor_box",ring_get_gl_scissor_box);
	RING_API_REGISTER("get_gl_scissor_test",ring_get_gl_scissor_test);
	RING_API_REGISTER("get_gl_index_clear_value",ring_get_gl_index_clear_value);
	RING_API_REGISTER("get_gl_index_writemask",ring_get_gl_index_writemask);
	RING_API_REGISTER("get_gl_color_clear_value",ring_get_gl_color_clear_value);
	RING_API_REGISTER("get_gl_color_writemask",ring_get_gl_color_writemask);
	RING_API_REGISTER("get_gl_index_mode",ring_get_gl_index_mode);
	RING_API_REGISTER("get_gl_rgba_mode",ring_get_gl_rgba_mode);
	RING_API_REGISTER("get_gl_doublebuffer",ring_get_gl_doublebuffer);
	RING_API_REGISTER("get_gl_stereo",ring_get_gl_stereo);
	RING_API_REGISTER("get_gl_render_mode",ring_get_gl_render_mode);
	RING_API_REGISTER("get_gl_perspective_correction_hint",ring_get_gl_perspective_correction_hint);
	RING_API_REGISTER("get_gl_point_smooth_hint",ring_get_gl_point_smooth_hint);
	RING_API_REGISTER("get_gl_line_smooth_hint",ring_get_gl_line_smooth_hint);
	RING_API_REGISTER("get_gl_polygon_smooth_hint",ring_get_gl_polygon_smooth_hint);
	RING_API_REGISTER("get_gl_fog_hint",ring_get_gl_fog_hint);
	RING_API_REGISTER("get_gl_texture_gen_s",ring_get_gl_texture_gen_s);
	RING_API_REGISTER("get_gl_texture_gen_t",ring_get_gl_texture_gen_t);
	RING_API_REGISTER("get_gl_texture_gen_r",ring_get_gl_texture_gen_r);
	RING_API_REGISTER("get_gl_texture_gen_q",ring_get_gl_texture_gen_q);
	RING_API_REGISTER("get_gl_pixel_map_i_to_i",ring_get_gl_pixel_map_i_to_i);
	RING_API_REGISTER("get_gl_pixel_map_s_to_s",ring_get_gl_pixel_map_s_to_s);
	RING_API_REGISTER("get_gl_pixel_map_i_to_r",ring_get_gl_pixel_map_i_to_r);
	RING_API_REGISTER("get_gl_pixel_map_i_to_g",ring_get_gl_pixel_map_i_to_g);
	RING_API_REGISTER("get_gl_pixel_map_i_to_b",ring_get_gl_pixel_map_i_to_b);
	RING_API_REGISTER("get_gl_pixel_map_i_to_a",ring_get_gl_pixel_map_i_to_a);
	RING_API_REGISTER("get_gl_pixel_map_r_to_r",ring_get_gl_pixel_map_r_to_r);
	RING_API_REGISTER("get_gl_pixel_map_g_to_g",ring_get_gl_pixel_map_g_to_g);
	RING_API_REGISTER("get_gl_pixel_map_b_to_b",ring_get_gl_pixel_map_b_to_b);
	RING_API_REGISTER("get_gl_pixel_map_a_to_a",ring_get_gl_pixel_map_a_to_a);
	RING_API_REGISTER("get_gl_pixel_map_i_to_i_size",ring_get_gl_pixel_map_i_to_i_size);
	RING_API_REGISTER("get_gl_pixel_map_s_to_s_size",ring_get_gl_pixel_map_s_to_s_size);
	RING_API_REGISTER("get_gl_pixel_map_i_to_r_size",ring_get_gl_pixel_map_i_to_r_size);
	RING_API_REGISTER("get_gl_pixel_map_i_to_g_size",ring_get_gl_pixel_map_i_to_g_size);
	RING_API_REGISTER("get_gl_pixel_map_i_to_b_size",ring_get_gl_pixel_map_i_to_b_size);
	RING_API_REGISTER("get_gl_pixel_map_i_to_a_size",ring_get_gl_pixel_map_i_to_a_size);
	RING_API_REGISTER("get_gl_pixel_map_r_to_r_size",ring_get_gl_pixel_map_r_to_r_size);
	RING_API_REGISTER("get_gl_pixel_map_g_to_g_size",ring_get_gl_pixel_map_g_to_g_size);
	RING_API_REGISTER("get_gl_pixel_map_b_to_b_size",ring_get_gl_pixel_map_b_to_b_size);
	RING_API_REGISTER("get_gl_pixel_map_a_to_a_size",ring_get_gl_pixel_map_a_to_a_size);
	RING_API_REGISTER("get_gl_unpack_swap_bytes",ring_get_gl_unpack_swap_bytes);
	RING_API_REGISTER("get_gl_unpack_lsb_first",ring_get_gl_unpack_lsb_first);
	RING_API_REGISTER("get_gl_unpack_row_length",ring_get_gl_unpack_row_length);
	RING_API_REGISTER("get_gl_unpack_skip_rows",ring_get_gl_unpack_skip_rows);
	RING_API_REGISTER("get_gl_unpack_skip_pixels",ring_get_gl_unpack_skip_pixels);
	RING_API_REGISTER("get_gl_unpack_alignment",ring_get_gl_unpack_alignment);
	RING_API_REGISTER("get_gl_pack_swap_bytes",ring_get_gl_pack_swap_bytes);
	RING_API_REGISTER("get_gl_pack_lsb_first",ring_get_gl_pack_lsb_first);
	RING_API_REGISTER("get_gl_pack_row_length",ring_get_gl_pack_row_length);
	RING_API_REGISTER("get_gl_pack_skip_rows",ring_get_gl_pack_skip_rows);
	RING_API_REGISTER("get_gl_pack_skip_pixels",ring_get_gl_pack_skip_pixels);
	RING_API_REGISTER("get_gl_pack_alignment",ring_get_gl_pack_alignment);
	RING_API_REGISTER("get_gl_map_color",ring_get_gl_map_color);
	RING_API_REGISTER("get_gl_map_stencil",ring_get_gl_map_stencil);
	RING_API_REGISTER("get_gl_index_shift",ring_get_gl_index_shift);
	RING_API_REGISTER("get_gl_index_offset",ring_get_gl_index_offset);
	RING_API_REGISTER("get_gl_red_scale",ring_get_gl_red_scale);
	RING_API_REGISTER("get_gl_red_bias",ring_get_gl_red_bias);
	RING_API_REGISTER("get_gl_zoom_x",ring_get_gl_zoom_x);
	RING_API_REGISTER("get_gl_zoom_y",ring_get_gl_zoom_y);
	RING_API_REGISTER("get_gl_green_scale",ring_get_gl_green_scale);
	RING_API_REGISTER("get_gl_green_bias",ring_get_gl_green_bias);
	RING_API_REGISTER("get_gl_blue_scale",ring_get_gl_blue_scale);
	RING_API_REGISTER("get_gl_blue_bias",ring_get_gl_blue_bias);
	RING_API_REGISTER("get_gl_alpha_scale",ring_get_gl_alpha_scale);
	RING_API_REGISTER("get_gl_alpha_bias",ring_get_gl_alpha_bias);
	RING_API_REGISTER("get_gl_depth_scale",ring_get_gl_depth_scale);
	RING_API_REGISTER("get_gl_depth_bias",ring_get_gl_depth_bias);
	RING_API_REGISTER("get_gl_max_eval_order",ring_get_gl_max_eval_order);
	RING_API_REGISTER("get_gl_max_lights",ring_get_gl_max_lights);
	RING_API_REGISTER("get_gl_max_clip_planes",ring_get_gl_max_clip_planes);
	RING_API_REGISTER("get_gl_max_texture_size",ring_get_gl_max_texture_size);
	RING_API_REGISTER("get_gl_max_pixel_map_table",ring_get_gl_max_pixel_map_table);
	RING_API_REGISTER("get_gl_max_attrib_stack_depth",ring_get_gl_max_attrib_stack_depth);
	RING_API_REGISTER("get_gl_max_modelview_stack_depth",ring_get_gl_max_modelview_stack_depth);
	RING_API_REGISTER("get_gl_max_name_stack_depth",ring_get_gl_max_name_stack_depth);
	RING_API_REGISTER("get_gl_max_projection_stack_depth",ring_get_gl_max_projection_stack_depth);
	RING_API_REGISTER("get_gl_max_texture_stack_depth",ring_get_gl_max_texture_stack_depth);
	RING_API_REGISTER("get_gl_max_viewport_dims",ring_get_gl_max_viewport_dims);
	RING_API_REGISTER("get_gl_max_client_attrib_stack_depth",ring_get_gl_max_client_attrib_stack_depth);
	RING_API_REGISTER("get_gl_subpixel_bits",ring_get_gl_subpixel_bits);
	RING_API_REGISTER("get_gl_index_bits",ring_get_gl_index_bits);
	RING_API_REGISTER("get_gl_red_bits",ring_get_gl_red_bits);
	RING_API_REGISTER("get_gl_green_bits",ring_get_gl_green_bits);
	RING_API_REGISTER("get_gl_blue_bits",ring_get_gl_blue_bits);
	RING_API_REGISTER("get_gl_alpha_bits",ring_get_gl_alpha_bits);
	RING_API_REGISTER("get_gl_depth_bits",ring_get_gl_depth_bits);
	RING_API_REGISTER("get_gl_stencil_bits",ring_get_gl_stencil_bits);
	RING_API_REGISTER("get_gl_accum_red_bits",ring_get_gl_accum_red_bits);
	RING_API_REGISTER("get_gl_accum_green_bits",ring_get_gl_accum_green_bits);
	RING_API_REGISTER("get_gl_accum_blue_bits",ring_get_gl_accum_blue_bits);
	RING_API_REGISTER("get_gl_accum_alpha_bits",ring_get_gl_accum_alpha_bits);
	RING_API_REGISTER("get_gl_name_stack_depth",ring_get_gl_name_stack_depth);
	RING_API_REGISTER("get_gl_auto_normal",ring_get_gl_auto_normal);
	RING_API_REGISTER("get_gl_map1_color_4",ring_get_gl_map1_color_4);
	RING_API_REGISTER("get_gl_map1_index",ring_get_gl_map1_index);
	RING_API_REGISTER("get_gl_map1_normal",ring_get_gl_map1_normal);
	RING_API_REGISTER("get_gl_map1_texture_coord_1",ring_get_gl_map1_texture_coord_1);
	RING_API_REGISTER("get_gl_map1_texture_coord_2",ring_get_gl_map1_texture_coord_2);
	RING_API_REGISTER("get_gl_map1_texture_coord_3",ring_get_gl_map1_texture_coord_3);
	RING_API_REGISTER("get_gl_map1_texture_coord_4",ring_get_gl_map1_texture_coord_4);
	RING_API_REGISTER("get_gl_map1_vertex_3",ring_get_gl_map1_vertex_3);
	RING_API_REGISTER("get_gl_map1_vertex_4",ring_get_gl_map1_vertex_4);
	RING_API_REGISTER("get_gl_map2_color_4",ring_get_gl_map2_color_4);
	RING_API_REGISTER("get_gl_map2_index",ring_get_gl_map2_index);
	RING_API_REGISTER("get_gl_map2_normal",ring_get_gl_map2_normal);
	RING_API_REGISTER("get_gl_map2_texture_coord_1",ring_get_gl_map2_texture_coord_1);
	RING_API_REGISTER("get_gl_map2_texture_coord_2",ring_get_gl_map2_texture_coord_2);
	RING_API_REGISTER("get_gl_map2_texture_coord_3",ring_get_gl_map2_texture_coord_3);
	RING_API_REGISTER("get_gl_map2_texture_coord_4",ring_get_gl_map2_texture_coord_4);
	RING_API_REGISTER("get_gl_map2_vertex_3",ring_get_gl_map2_vertex_3);
	RING_API_REGISTER("get_gl_map2_vertex_4",ring_get_gl_map2_vertex_4);
	RING_API_REGISTER("get_gl_map1_grid_domain",ring_get_gl_map1_grid_domain);
	RING_API_REGISTER("get_gl_map1_grid_segments",ring_get_gl_map1_grid_segments);
	RING_API_REGISTER("get_gl_map2_grid_domain",ring_get_gl_map2_grid_domain);
	RING_API_REGISTER("get_gl_map2_grid_segments",ring_get_gl_map2_grid_segments);
	RING_API_REGISTER("get_gl_texture_1d",ring_get_gl_texture_1d);
	RING_API_REGISTER("get_gl_texture_2d",ring_get_gl_texture_2d);
	RING_API_REGISTER("get_gl_feedback_buffer_pointer",ring_get_gl_feedback_buffer_pointer);
	RING_API_REGISTER("get_gl_feedback_buffer_size",ring_get_gl_feedback_buffer_size);
	RING_API_REGISTER("get_gl_feedback_buffer_type",ring_get_gl_feedback_buffer_type);
	RING_API_REGISTER("get_gl_selection_buffer_pointer",ring_get_gl_selection_buffer_pointer);
	RING_API_REGISTER("get_gl_selection_buffer_size",ring_get_gl_selection_buffer_size);
	RING_API_REGISTER("get_gl_texture_width",ring_get_gl_texture_width);
	RING_API_REGISTER("get_gl_transform_bit",ring_get_gl_transform_bit);
	RING_API_REGISTER("get_gl_texture_height",ring_get_gl_texture_height);
	RING_API_REGISTER("get_gl_texture_internal_format",ring_get_gl_texture_internal_format);
	RING_API_REGISTER("get_gl_texture_border_color",ring_get_gl_texture_border_color);
	RING_API_REGISTER("get_gl_texture_border",ring_get_gl_texture_border);
	RING_API_REGISTER("get_gl_dont_care",ring_get_gl_dont_care);
	RING_API_REGISTER("get_gl_fastest",ring_get_gl_fastest);
	RING_API_REGISTER("get_gl_nicest",ring_get_gl_nicest);
	RING_API_REGISTER("get_gl_ambient",ring_get_gl_ambient);
	RING_API_REGISTER("get_gl_diffuse",ring_get_gl_diffuse);
	RING_API_REGISTER("get_gl_specular",ring_get_gl_specular);
	RING_API_REGISTER("get_gl_position",ring_get_gl_position);
	RING_API_REGISTER("get_gl_spot_direction",ring_get_gl_spot_direction);
	RING_API_REGISTER("get_gl_spot_exponent",ring_get_gl_spot_exponent);
	RING_API_REGISTER("get_gl_spot_cutoff",ring_get_gl_spot_cutoff);
	RING_API_REGISTER("get_gl_constant_attenuation",ring_get_gl_constant_attenuation);
	RING_API_REGISTER("get_gl_linear_attenuation",ring_get_gl_linear_attenuation);
	RING_API_REGISTER("get_gl_quadratic_attenuation",ring_get_gl_quadratic_attenuation);
	RING_API_REGISTER("get_gl_compile",ring_get_gl_compile);
	RING_API_REGISTER("get_gl_compile_and_execute",ring_get_gl_compile_and_execute);
	RING_API_REGISTER("get_gl_byte",ring_get_gl_byte);
	RING_API_REGISTER("get_gl_unsigned_byte",ring_get_gl_unsigned_byte);
	RING_API_REGISTER("get_gl_short",ring_get_gl_short);
	RING_API_REGISTER("get_gl_unsigned_short",ring_get_gl_unsigned_short);
	RING_API_REGISTER("get_gl_int",ring_get_gl_int);
	RING_API_REGISTER("get_gl_unsigned_int",ring_get_gl_unsigned_int);
	RING_API_REGISTER("get_gl_float",ring_get_gl_float);
	RING_API_REGISTER("get_gl_2_bytes",ring_get_gl_2_bytes);
	RING_API_REGISTER("get_gl_3_bytes",ring_get_gl_3_bytes);
	RING_API_REGISTER("get_gl_4_bytes",ring_get_gl_4_bytes);
	RING_API_REGISTER("get_gl_double",ring_get_gl_double);
	RING_API_REGISTER("get_gl_clear",ring_get_gl_clear);
	RING_API_REGISTER("get_gl_and",ring_get_gl_and);
	RING_API_REGISTER("get_gl_and_reverse",ring_get_gl_and_reverse);
	RING_API_REGISTER("get_gl_copy",ring_get_gl_copy);
	RING_API_REGISTER("get_gl_and_inverted",ring_get_gl_and_inverted);
	RING_API_REGISTER("get_gl_noop",ring_get_gl_noop);
	RING_API_REGISTER("get_gl_xor",ring_get_gl_xor);
	RING_API_REGISTER("get_gl_or",ring_get_gl_or);
	RING_API_REGISTER("get_gl_nor",ring_get_gl_nor);
	RING_API_REGISTER("get_gl_equiv",ring_get_gl_equiv);
	RING_API_REGISTER("get_gl_invert",ring_get_gl_invert);
	RING_API_REGISTER("get_gl_or_reverse",ring_get_gl_or_reverse);
	RING_API_REGISTER("get_gl_copy_inverted",ring_get_gl_copy_inverted);
	RING_API_REGISTER("get_gl_or_inverted",ring_get_gl_or_inverted);
	RING_API_REGISTER("get_gl_nand",ring_get_gl_nand);
	RING_API_REGISTER("get_gl_set",ring_get_gl_set);
	RING_API_REGISTER("get_gl_emission",ring_get_gl_emission);
	RING_API_REGISTER("get_gl_shininess",ring_get_gl_shininess);
	RING_API_REGISTER("get_gl_ambient_and_diffuse",ring_get_gl_ambient_and_diffuse);
	RING_API_REGISTER("get_gl_color_indexes",ring_get_gl_color_indexes);
	RING_API_REGISTER("get_gl_modelview",ring_get_gl_modelview);
	RING_API_REGISTER("get_gl_projection",ring_get_gl_projection);
	RING_API_REGISTER("get_gl_texture",ring_get_gl_texture);
	RING_API_REGISTER("get_gl_color",ring_get_gl_color);
	RING_API_REGISTER("get_gl_depth",ring_get_gl_depth);
	RING_API_REGISTER("get_gl_stencil",ring_get_gl_stencil);
	RING_API_REGISTER("get_gl_color_index",ring_get_gl_color_index);
	RING_API_REGISTER("get_gl_stencil_index",ring_get_gl_stencil_index);
	RING_API_REGISTER("get_gl_depth_component",ring_get_gl_depth_component);
	RING_API_REGISTER("get_gl_red",ring_get_gl_red);
	RING_API_REGISTER("get_gl_green",ring_get_gl_green);
	RING_API_REGISTER("get_gl_blue",ring_get_gl_blue);
	RING_API_REGISTER("get_gl_alpha",ring_get_gl_alpha);
	RING_API_REGISTER("get_gl_rgb",ring_get_gl_rgb);
	RING_API_REGISTER("get_gl_rgba",ring_get_gl_rgba);
	RING_API_REGISTER("get_gl_luminance",ring_get_gl_luminance);
	RING_API_REGISTER("get_gl_luminance_alpha",ring_get_gl_luminance_alpha);
	RING_API_REGISTER("get_gl_bitmap",ring_get_gl_bitmap);
	RING_API_REGISTER("get_gl_point",ring_get_gl_point);
	RING_API_REGISTER("get_gl_line",ring_get_gl_line);
	RING_API_REGISTER("get_gl_fill",ring_get_gl_fill);
	RING_API_REGISTER("get_gl_render",ring_get_gl_render);
	RING_API_REGISTER("get_gl_feedback",ring_get_gl_feedback);
	RING_API_REGISTER("get_gl_select",ring_get_gl_select);
	RING_API_REGISTER("get_gl_flat",ring_get_gl_flat);
	RING_API_REGISTER("get_gl_smooth",ring_get_gl_smooth);
	RING_API_REGISTER("get_gl_keep",ring_get_gl_keep);
	RING_API_REGISTER("get_gl_replace",ring_get_gl_replace);
	RING_API_REGISTER("get_gl_incr",ring_get_gl_incr);
	RING_API_REGISTER("get_gl_decr",ring_get_gl_decr);
	RING_API_REGISTER("get_gl_vendor",ring_get_gl_vendor);
	RING_API_REGISTER("get_gl_renderer",ring_get_gl_renderer);
	RING_API_REGISTER("get_gl_version",ring_get_gl_version);
	RING_API_REGISTER("get_gl_extensions",ring_get_gl_extensions);
	RING_API_REGISTER("get_gl_s",ring_get_gl_s);
	RING_API_REGISTER("get_gl_enable_bit",ring_get_gl_enable_bit);
	RING_API_REGISTER("get_gl_t",ring_get_gl_t);
	RING_API_REGISTER("get_gl_r",ring_get_gl_r);
	RING_API_REGISTER("get_gl_q",ring_get_gl_q);
	RING_API_REGISTER("get_gl_modulate",ring_get_gl_modulate);
	RING_API_REGISTER("get_gl_decal",ring_get_gl_decal);
	RING_API_REGISTER("get_gl_texture_env_mode",ring_get_gl_texture_env_mode);
	RING_API_REGISTER("get_gl_texture_env_color",ring_get_gl_texture_env_color);
	RING_API_REGISTER("get_gl_texture_env",ring_get_gl_texture_env);
	RING_API_REGISTER("get_gl_eye_linear",ring_get_gl_eye_linear);
	RING_API_REGISTER("get_gl_object_linear",ring_get_gl_object_linear);
	RING_API_REGISTER("get_gl_sphere_map",ring_get_gl_sphere_map);
	RING_API_REGISTER("get_gl_texture_gen_mode",ring_get_gl_texture_gen_mode);
	RING_API_REGISTER("get_gl_object_plane",ring_get_gl_object_plane);
	RING_API_REGISTER("get_gl_eye_plane",ring_get_gl_eye_plane);
	RING_API_REGISTER("get_gl_nearest",ring_get_gl_nearest);
	RING_API_REGISTER("get_gl_linear",ring_get_gl_linear);
	RING_API_REGISTER("get_gl_nearest_mipmap_nearest",ring_get_gl_nearest_mipmap_nearest);
	RING_API_REGISTER("get_gl_linear_mipmap_nearest",ring_get_gl_linear_mipmap_nearest);
	RING_API_REGISTER("get_gl_nearest_mipmap_linear",ring_get_gl_nearest_mipmap_linear);
	RING_API_REGISTER("get_gl_linear_mipmap_linear",ring_get_gl_linear_mipmap_linear);
	RING_API_REGISTER("get_gl_texture_mag_filter",ring_get_gl_texture_mag_filter);
	RING_API_REGISTER("get_gl_texture_min_filter",ring_get_gl_texture_min_filter);
	RING_API_REGISTER("get_gl_texture_wrap_s",ring_get_gl_texture_wrap_s);
	RING_API_REGISTER("get_gl_texture_wrap_t",ring_get_gl_texture_wrap_t);
	RING_API_REGISTER("get_gl_clamp",ring_get_gl_clamp);
	RING_API_REGISTER("get_gl_repeat",ring_get_gl_repeat);
	RING_API_REGISTER("get_gl_polygon_offset_units",ring_get_gl_polygon_offset_units);
	RING_API_REGISTER("get_gl_polygon_offset_point",ring_get_gl_polygon_offset_point);
	RING_API_REGISTER("get_gl_polygon_offset_line",ring_get_gl_polygon_offset_line);
	RING_API_REGISTER("get_gl_r3_g3_b2",ring_get_gl_r3_g3_b2);
	RING_API_REGISTER("get_gl_v2f",ring_get_gl_v2f);
	RING_API_REGISTER("get_gl_v3f",ring_get_gl_v3f);
	RING_API_REGISTER("get_gl_c4ub_v2f",ring_get_gl_c4ub_v2f);
	RING_API_REGISTER("get_gl_c4ub_v3f",ring_get_gl_c4ub_v3f);
	RING_API_REGISTER("get_gl_c3f_v3f",ring_get_gl_c3f_v3f);
	RING_API_REGISTER("get_gl_n3f_v3f",ring_get_gl_n3f_v3f);
	RING_API_REGISTER("get_gl_c4f_n3f_v3f",ring_get_gl_c4f_n3f_v3f);
	RING_API_REGISTER("get_gl_t2f_v3f",ring_get_gl_t2f_v3f);
	RING_API_REGISTER("get_gl_t4f_v4f",ring_get_gl_t4f_v4f);
	RING_API_REGISTER("get_gl_t2f_c4ub_v3f",ring_get_gl_t2f_c4ub_v3f);
	RING_API_REGISTER("get_gl_t2f_c3f_v3f",ring_get_gl_t2f_c3f_v3f);
	RING_API_REGISTER("get_gl_t2f_n3f_v3f",ring_get_gl_t2f_n3f_v3f);
	RING_API_REGISTER("get_gl_t2f_c4f_n3f_v3f",ring_get_gl_t2f_c4f_n3f_v3f);
	RING_API_REGISTER("get_gl_t4f_c4f_n3f_v4f",ring_get_gl_t4f_c4f_n3f_v4f);
	RING_API_REGISTER("get_gl_clip_plane0",ring_get_gl_clip_plane0);
	RING_API_REGISTER("get_gl_clip_plane1",ring_get_gl_clip_plane1);
	RING_API_REGISTER("get_gl_clip_plane2",ring_get_gl_clip_plane2);
	RING_API_REGISTER("get_gl_clip_plane3",ring_get_gl_clip_plane3);
	RING_API_REGISTER("get_gl_clip_plane4",ring_get_gl_clip_plane4);
	RING_API_REGISTER("get_gl_clip_plane5",ring_get_gl_clip_plane5);
	RING_API_REGISTER("get_gl_light0",ring_get_gl_light0);
	RING_API_REGISTER("get_gl_color_buffer_bit",ring_get_gl_color_buffer_bit);
	RING_API_REGISTER("get_gl_light1",ring_get_gl_light1);
	RING_API_REGISTER("get_gl_light2",ring_get_gl_light2);
	RING_API_REGISTER("get_gl_light3",ring_get_gl_light3);
	RING_API_REGISTER("get_gl_light4",ring_get_gl_light4);
	RING_API_REGISTER("get_gl_light5",ring_get_gl_light5);
	RING_API_REGISTER("get_gl_light6",ring_get_gl_light6);
	RING_API_REGISTER("get_gl_light7",ring_get_gl_light7);
	RING_API_REGISTER("get_gl_hint_bit",ring_get_gl_hint_bit);
	RING_API_REGISTER("get_gl_polygon_offset_fill",ring_get_gl_polygon_offset_fill);
	RING_API_REGISTER("get_gl_polygon_offset_factor",ring_get_gl_polygon_offset_factor);
	RING_API_REGISTER("get_gl_alpha4",ring_get_gl_alpha4);
	RING_API_REGISTER("get_gl_alpha8",ring_get_gl_alpha8);
	RING_API_REGISTER("get_gl_alpha12",ring_get_gl_alpha12);
	RING_API_REGISTER("get_gl_alpha16",ring_get_gl_alpha16);
	RING_API_REGISTER("get_gl_luminance4",ring_get_gl_luminance4);
	RING_API_REGISTER("get_gl_luminance8",ring_get_gl_luminance8);
	RING_API_REGISTER("get_gl_luminance12",ring_get_gl_luminance12);
	RING_API_REGISTER("get_gl_luminance16",ring_get_gl_luminance16);
	RING_API_REGISTER("get_gl_luminance4_alpha4",ring_get_gl_luminance4_alpha4);
	RING_API_REGISTER("get_gl_luminance6_alpha2",ring_get_gl_luminance6_alpha2);
	RING_API_REGISTER("get_gl_luminance8_alpha8",ring_get_gl_luminance8_alpha8);
	RING_API_REGISTER("get_gl_luminance12_alpha4",ring_get_gl_luminance12_alpha4);
	RING_API_REGISTER("get_gl_luminance12_alpha12",ring_get_gl_luminance12_alpha12);
	RING_API_REGISTER("get_gl_luminance16_alpha16",ring_get_gl_luminance16_alpha16);
	RING_API_REGISTER("get_gl_intensity",ring_get_gl_intensity);
	RING_API_REGISTER("get_gl_intensity4",ring_get_gl_intensity4);
	RING_API_REGISTER("get_gl_intensity8",ring_get_gl_intensity8);
	RING_API_REGISTER("get_gl_intensity12",ring_get_gl_intensity12);
	RING_API_REGISTER("get_gl_intensity16",ring_get_gl_intensity16);
	RING_API_REGISTER("get_gl_rgb4",ring_get_gl_rgb4);
	RING_API_REGISTER("get_gl_rgb5",ring_get_gl_rgb5);
	RING_API_REGISTER("get_gl_rgb8",ring_get_gl_rgb8);
	RING_API_REGISTER("get_gl_rgb10",ring_get_gl_rgb10);
	RING_API_REGISTER("get_gl_rgb12",ring_get_gl_rgb12);
	RING_API_REGISTER("get_gl_rgb16",ring_get_gl_rgb16);
	RING_API_REGISTER("get_gl_rgba2",ring_get_gl_rgba2);
	RING_API_REGISTER("get_gl_rgba4",ring_get_gl_rgba4);
	RING_API_REGISTER("get_gl_rgb5_a1",ring_get_gl_rgb5_a1);
	RING_API_REGISTER("get_gl_rgba8",ring_get_gl_rgba8);
	RING_API_REGISTER("get_gl_rgb10_a2",ring_get_gl_rgb10_a2);
	RING_API_REGISTER("get_gl_rgba12",ring_get_gl_rgba12);
	RING_API_REGISTER("get_gl_rgba16",ring_get_gl_rgba16);
	RING_API_REGISTER("get_gl_texture_red_size",ring_get_gl_texture_red_size);
	RING_API_REGISTER("get_gl_texture_green_size",ring_get_gl_texture_green_size);
	RING_API_REGISTER("get_gl_texture_blue_size",ring_get_gl_texture_blue_size);
	RING_API_REGISTER("get_gl_texture_alpha_size",ring_get_gl_texture_alpha_size);
	RING_API_REGISTER("get_gl_texture_luminance_size",ring_get_gl_texture_luminance_size);
	RING_API_REGISTER("get_gl_texture_intensity_size",ring_get_gl_texture_intensity_size);
	RING_API_REGISTER("get_gl_proxy_texture_1d",ring_get_gl_proxy_texture_1d);
	RING_API_REGISTER("get_gl_proxy_texture_2d",ring_get_gl_proxy_texture_2d);
	RING_API_REGISTER("get_gl_texture_priority",ring_get_gl_texture_priority);
	RING_API_REGISTER("get_gl_texture_resident",ring_get_gl_texture_resident);
	RING_API_REGISTER("get_gl_texture_binding_1d",ring_get_gl_texture_binding_1d);
	RING_API_REGISTER("get_gl_texture_binding_2d",ring_get_gl_texture_binding_2d);
	RING_API_REGISTER("get_gl_vertex_array",ring_get_gl_vertex_array);
	RING_API_REGISTER("get_gl_normal_array",ring_get_gl_normal_array);
	RING_API_REGISTER("get_gl_color_array",ring_get_gl_color_array);
	RING_API_REGISTER("get_gl_index_array",ring_get_gl_index_array);
	RING_API_REGISTER("get_gl_texture_coord_array",ring_get_gl_texture_coord_array);
	RING_API_REGISTER("get_gl_edge_flag_array",ring_get_gl_edge_flag_array);
	RING_API_REGISTER("get_gl_vertex_array_size",ring_get_gl_vertex_array_size);
	RING_API_REGISTER("get_gl_vertex_array_type",ring_get_gl_vertex_array_type);
	RING_API_REGISTER("get_gl_vertex_array_stride",ring_get_gl_vertex_array_stride);
	RING_API_REGISTER("get_gl_normal_array_type",ring_get_gl_normal_array_type);
	RING_API_REGISTER("get_gl_normal_array_stride",ring_get_gl_normal_array_stride);
	RING_API_REGISTER("get_gl_color_array_size",ring_get_gl_color_array_size);
	RING_API_REGISTER("get_gl_color_array_type",ring_get_gl_color_array_type);
	RING_API_REGISTER("get_gl_color_array_stride",ring_get_gl_color_array_stride);
	RING_API_REGISTER("get_gl_index_array_type",ring_get_gl_index_array_type);
	RING_API_REGISTER("get_gl_index_array_stride",ring_get_gl_index_array_stride);
	RING_API_REGISTER("get_gl_texture_coord_array_size",ring_get_gl_texture_coord_array_size);
	RING_API_REGISTER("get_gl_texture_coord_array_type",ring_get_gl_texture_coord_array_type);
	RING_API_REGISTER("get_gl_texture_coord_array_stride",ring_get_gl_texture_coord_array_stride);
	RING_API_REGISTER("get_gl_edge_flag_array_stride",ring_get_gl_edge_flag_array_stride);
	RING_API_REGISTER("get_gl_vertex_array_pointer",ring_get_gl_vertex_array_pointer);
	RING_API_REGISTER("get_gl_normal_array_pointer",ring_get_gl_normal_array_pointer);
	RING_API_REGISTER("get_gl_color_array_pointer",ring_get_gl_color_array_pointer);
	RING_API_REGISTER("get_gl_index_array_pointer",ring_get_gl_index_array_pointer);
	RING_API_REGISTER("get_gl_texture_coord_array_pointer",ring_get_gl_texture_coord_array_pointer);
	RING_API_REGISTER("get_gl_edge_flag_array_pointer",ring_get_gl_edge_flag_array_pointer);
	RING_API_REGISTER("get_gl_color_index1_ext",ring_get_gl_color_index1_ext);
	RING_API_REGISTER("get_gl_color_index2_ext",ring_get_gl_color_index2_ext);
	RING_API_REGISTER("get_gl_color_index4_ext",ring_get_gl_color_index4_ext);
	RING_API_REGISTER("get_gl_color_index8_ext",ring_get_gl_color_index8_ext);
	RING_API_REGISTER("get_gl_color_index12_ext",ring_get_gl_color_index12_ext);
	RING_API_REGISTER("get_gl_color_index16_ext",ring_get_gl_color_index16_ext);
	RING_API_REGISTER("get_gl_eval_bit",ring_get_gl_eval_bit);
	RING_API_REGISTER("get_gl_list_bit",ring_get_gl_list_bit);
	RING_API_REGISTER("get_gl_texture_bit",ring_get_gl_texture_bit);
	RING_API_REGISTER("get_gl_scissor_bit",ring_get_gl_scissor_bit);
	RING_API_REGISTER("get_gl_all_attrib_bits",ring_get_gl_all_attrib_bits);
	RING_API_REGISTER("get_gl_client_all_attrib_bits",ring_get_gl_client_all_attrib_bits);
	RING_API_REGISTER("get_gl_smooth_point_size_range",ring_get_gl_smooth_point_size_range);
	RING_API_REGISTER("get_gl_smooth_point_size_granularity",ring_get_gl_smooth_point_size_granularity);
	RING_API_REGISTER("get_gl_smooth_line_width_range",ring_get_gl_smooth_line_width_range);
	RING_API_REGISTER("get_gl_smooth_line_width_granularity",ring_get_gl_smooth_line_width_granularity);
	RING_API_REGISTER("get_gl_unsigned_byte_3_3_2",ring_get_gl_unsigned_byte_3_3_2);
	RING_API_REGISTER("get_gl_unsigned_short_4_4_4_4",ring_get_gl_unsigned_short_4_4_4_4);
	RING_API_REGISTER("get_gl_unsigned_short_5_5_5_1",ring_get_gl_unsigned_short_5_5_5_1);
	RING_API_REGISTER("get_gl_unsigned_int_8_8_8_8",ring_get_gl_unsigned_int_8_8_8_8);
	RING_API_REGISTER("get_gl_unsigned_int_10_10_10_2",ring_get_gl_unsigned_int_10_10_10_2);
	RING_API_REGISTER("get_gl_rescale_normal",ring_get_gl_rescale_normal);
	RING_API_REGISTER("get_gl_texture_binding_3d",ring_get_gl_texture_binding_3d);
	RING_API_REGISTER("get_gl_pack_skip_images",ring_get_gl_pack_skip_images);
	RING_API_REGISTER("get_gl_pack_image_height",ring_get_gl_pack_image_height);
	RING_API_REGISTER("get_gl_unpack_skip_images",ring_get_gl_unpack_skip_images);
	RING_API_REGISTER("get_gl_unpack_image_height",ring_get_gl_unpack_image_height);
	RING_API_REGISTER("get_gl_texture_3d",ring_get_gl_texture_3d);
	RING_API_REGISTER("get_gl_proxy_texture_3d",ring_get_gl_proxy_texture_3d);
	RING_API_REGISTER("get_gl_texture_depth",ring_get_gl_texture_depth);
	RING_API_REGISTER("get_gl_texture_wrap_r",ring_get_gl_texture_wrap_r);
	RING_API_REGISTER("get_gl_max_3d_texture_size",ring_get_gl_max_3d_texture_size);
	RING_API_REGISTER("get_gl_bgr",ring_get_gl_bgr);
	RING_API_REGISTER("get_gl_bgra",ring_get_gl_bgra);
	RING_API_REGISTER("get_gl_max_elements_vertices",ring_get_gl_max_elements_vertices);
	RING_API_REGISTER("get_gl_max_elements_indices",ring_get_gl_max_elements_indices);
	RING_API_REGISTER("get_gl_clamp_to_edge",ring_get_gl_clamp_to_edge);
	RING_API_REGISTER("get_gl_texture_min_lod",ring_get_gl_texture_min_lod);
	RING_API_REGISTER("get_gl_texture_max_lod",ring_get_gl_texture_max_lod);
	RING_API_REGISTER("get_gl_texture_base_level",ring_get_gl_texture_base_level);
	RING_API_REGISTER("get_gl_texture_max_level",ring_get_gl_texture_max_level);
	RING_API_REGISTER("get_gl_light_model_color_control",ring_get_gl_light_model_color_control);
	RING_API_REGISTER("get_gl_single_color",ring_get_gl_single_color);
	RING_API_REGISTER("get_gl_separate_specular_color",ring_get_gl_separate_specular_color);
	RING_API_REGISTER("get_gl_unsigned_byte_2_3_3_rev",ring_get_gl_unsigned_byte_2_3_3_rev);
	RING_API_REGISTER("get_gl_unsigned_short_5_6_5",ring_get_gl_unsigned_short_5_6_5);
	RING_API_REGISTER("get_gl_unsigned_short_5_6_5_rev",ring_get_gl_unsigned_short_5_6_5_rev);
	RING_API_REGISTER("get_gl_unsigned_short_4_4_4_4_rev",ring_get_gl_unsigned_short_4_4_4_4_rev);
	RING_API_REGISTER("get_gl_unsigned_short_1_5_5_5_rev",ring_get_gl_unsigned_short_1_5_5_5_rev);
	RING_API_REGISTER("get_gl_unsigned_int_8_8_8_8_rev",ring_get_gl_unsigned_int_8_8_8_8_rev);
	RING_API_REGISTER("get_gl_aliased_point_size_range",ring_get_gl_aliased_point_size_range);
	RING_API_REGISTER("get_gl_aliased_line_width_range",ring_get_gl_aliased_line_width_range);
	RING_API_REGISTER("get_gl_multisample",ring_get_gl_multisample);
	RING_API_REGISTER("get_gl_sample_alpha_to_coverage",ring_get_gl_sample_alpha_to_coverage);
	RING_API_REGISTER("get_gl_sample_alpha_to_one",ring_get_gl_sample_alpha_to_one);
	RING_API_REGISTER("get_gl_sample_coverage",ring_get_gl_sample_coverage);
	RING_API_REGISTER("get_gl_sample_buffers",ring_get_gl_sample_buffers);
	RING_API_REGISTER("get_gl_samples",ring_get_gl_samples);
	RING_API_REGISTER("get_gl_sample_coverage_value",ring_get_gl_sample_coverage_value);
	RING_API_REGISTER("get_gl_sample_coverage_invert",ring_get_gl_sample_coverage_invert);
	RING_API_REGISTER("get_gl_clamp_to_border",ring_get_gl_clamp_to_border);
	RING_API_REGISTER("get_gl_texture0",ring_get_gl_texture0);
	RING_API_REGISTER("get_gl_texture1",ring_get_gl_texture1);
	RING_API_REGISTER("get_gl_texture2",ring_get_gl_texture2);
	RING_API_REGISTER("get_gl_texture3",ring_get_gl_texture3);
	RING_API_REGISTER("get_gl_texture4",ring_get_gl_texture4);
	RING_API_REGISTER("get_gl_texture5",ring_get_gl_texture5);
	RING_API_REGISTER("get_gl_texture6",ring_get_gl_texture6);
	RING_API_REGISTER("get_gl_texture7",ring_get_gl_texture7);
	RING_API_REGISTER("get_gl_texture8",ring_get_gl_texture8);
	RING_API_REGISTER("get_gl_texture9",ring_get_gl_texture9);
	RING_API_REGISTER("get_gl_texture10",ring_get_gl_texture10);
	RING_API_REGISTER("get_gl_texture11",ring_get_gl_texture11);
	RING_API_REGISTER("get_gl_texture12",ring_get_gl_texture12);
	RING_API_REGISTER("get_gl_texture13",ring_get_gl_texture13);
	RING_API_REGISTER("get_gl_texture14",ring_get_gl_texture14);
	RING_API_REGISTER("get_gl_texture15",ring_get_gl_texture15);
	RING_API_REGISTER("get_gl_texture16",ring_get_gl_texture16);
	RING_API_REGISTER("get_gl_texture17",ring_get_gl_texture17);
	RING_API_REGISTER("get_gl_texture18",ring_get_gl_texture18);
	RING_API_REGISTER("get_gl_texture19",ring_get_gl_texture19);
	RING_API_REGISTER("get_gl_texture20",ring_get_gl_texture20);
	RING_API_REGISTER("get_gl_texture21",ring_get_gl_texture21);
	RING_API_REGISTER("get_gl_texture22",ring_get_gl_texture22);
	RING_API_REGISTER("get_gl_texture23",ring_get_gl_texture23);
	RING_API_REGISTER("get_gl_texture24",ring_get_gl_texture24);
	RING_API_REGISTER("get_gl_texture25",ring_get_gl_texture25);
	RING_API_REGISTER("get_gl_texture26",ring_get_gl_texture26);
	RING_API_REGISTER("get_gl_texture27",ring_get_gl_texture27);
	RING_API_REGISTER("get_gl_texture28",ring_get_gl_texture28);
	RING_API_REGISTER("get_gl_texture29",ring_get_gl_texture29);
	RING_API_REGISTER("get_gl_texture30",ring_get_gl_texture30);
	RING_API_REGISTER("get_gl_texture31",ring_get_gl_texture31);
	RING_API_REGISTER("get_gl_active_texture",ring_get_gl_active_texture);
	RING_API_REGISTER("get_gl_client_active_texture",ring_get_gl_client_active_texture);
	RING_API_REGISTER("get_gl_max_texture_units",ring_get_gl_max_texture_units);
	RING_API_REGISTER("get_gl_transpose_modelview_matrix",ring_get_gl_transpose_modelview_matrix);
	RING_API_REGISTER("get_gl_transpose_projection_matrix",ring_get_gl_transpose_projection_matrix);
	RING_API_REGISTER("get_gl_transpose_texture_matrix",ring_get_gl_transpose_texture_matrix);
	RING_API_REGISTER("get_gl_transpose_color_matrix",ring_get_gl_transpose_color_matrix);
	RING_API_REGISTER("get_gl_subtract",ring_get_gl_subtract);
	RING_API_REGISTER("get_gl_compressed_alpha",ring_get_gl_compressed_alpha);
	RING_API_REGISTER("get_gl_compressed_luminance",ring_get_gl_compressed_luminance);
	RING_API_REGISTER("get_gl_compressed_luminance_alpha",ring_get_gl_compressed_luminance_alpha);
	RING_API_REGISTER("get_gl_compressed_intensity",ring_get_gl_compressed_intensity);
	RING_API_REGISTER("get_gl_compressed_rgb",ring_get_gl_compressed_rgb);
	RING_API_REGISTER("get_gl_compressed_rgba",ring_get_gl_compressed_rgba);
	RING_API_REGISTER("get_gl_texture_compression_hint",ring_get_gl_texture_compression_hint);
	RING_API_REGISTER("get_gl_normal_map",ring_get_gl_normal_map);
	RING_API_REGISTER("get_gl_reflection_map",ring_get_gl_reflection_map);
	RING_API_REGISTER("get_gl_texture_cube_map",ring_get_gl_texture_cube_map);
	RING_API_REGISTER("get_gl_texture_binding_cube_map",ring_get_gl_texture_binding_cube_map);
	RING_API_REGISTER("get_gl_texture_cube_map_positive_x",ring_get_gl_texture_cube_map_positive_x);
	RING_API_REGISTER("get_gl_texture_cube_map_negative_x",ring_get_gl_texture_cube_map_negative_x);
	RING_API_REGISTER("get_gl_texture_cube_map_positive_y",ring_get_gl_texture_cube_map_positive_y);
	RING_API_REGISTER("get_gl_texture_cube_map_negative_y",ring_get_gl_texture_cube_map_negative_y);
	RING_API_REGISTER("get_gl_texture_cube_map_positive_z",ring_get_gl_texture_cube_map_positive_z);
	RING_API_REGISTER("get_gl_texture_cube_map_negative_z",ring_get_gl_texture_cube_map_negative_z);
	RING_API_REGISTER("get_gl_proxy_texture_cube_map",ring_get_gl_proxy_texture_cube_map);
	RING_API_REGISTER("get_gl_max_cube_map_texture_size",ring_get_gl_max_cube_map_texture_size);
	RING_API_REGISTER("get_gl_combine",ring_get_gl_combine);
	RING_API_REGISTER("get_gl_combine_rgb",ring_get_gl_combine_rgb);
	RING_API_REGISTER("get_gl_combine_alpha",ring_get_gl_combine_alpha);
	RING_API_REGISTER("get_gl_rgb_scale",ring_get_gl_rgb_scale);
	RING_API_REGISTER("get_gl_add_signed",ring_get_gl_add_signed);
	RING_API_REGISTER("get_gl_interpolate",ring_get_gl_interpolate);
	RING_API_REGISTER("get_gl_constant",ring_get_gl_constant);
	RING_API_REGISTER("get_gl_primary_color",ring_get_gl_primary_color);
	RING_API_REGISTER("get_gl_previous",ring_get_gl_previous);
	RING_API_REGISTER("get_gl_source0_rgb",ring_get_gl_source0_rgb);
	RING_API_REGISTER("get_gl_source1_rgb",ring_get_gl_source1_rgb);
	RING_API_REGISTER("get_gl_source2_rgb",ring_get_gl_source2_rgb);
	RING_API_REGISTER("get_gl_source0_alpha",ring_get_gl_source0_alpha);
	RING_API_REGISTER("get_gl_source1_alpha",ring_get_gl_source1_alpha);
	RING_API_REGISTER("get_gl_source2_alpha",ring_get_gl_source2_alpha);
	RING_API_REGISTER("get_gl_operand0_rgb",ring_get_gl_operand0_rgb);
	RING_API_REGISTER("get_gl_operand1_rgb",ring_get_gl_operand1_rgb);
	RING_API_REGISTER("get_gl_operand2_rgb",ring_get_gl_operand2_rgb);
	RING_API_REGISTER("get_gl_operand0_alpha",ring_get_gl_operand0_alpha);
	RING_API_REGISTER("get_gl_operand1_alpha",ring_get_gl_operand1_alpha);
	RING_API_REGISTER("get_gl_operand2_alpha",ring_get_gl_operand2_alpha);
	RING_API_REGISTER("get_gl_texture_compressed_image_size",ring_get_gl_texture_compressed_image_size);
	RING_API_REGISTER("get_gl_texture_compressed",ring_get_gl_texture_compressed);
	RING_API_REGISTER("get_gl_num_compressed_texture_formats",ring_get_gl_num_compressed_texture_formats);
	RING_API_REGISTER("get_gl_compressed_texture_formats",ring_get_gl_compressed_texture_formats);
	RING_API_REGISTER("get_gl_dot3_rgb",ring_get_gl_dot3_rgb);
	RING_API_REGISTER("get_gl_dot3_rgba",ring_get_gl_dot3_rgba);
	RING_API_REGISTER("get_gl_multisample_bit",ring_get_gl_multisample_bit);
	RING_API_REGISTER("get_gl_blend_dst_rgb",ring_get_gl_blend_dst_rgb);
	RING_API_REGISTER("get_gl_blend_src_rgb",ring_get_gl_blend_src_rgb);
	RING_API_REGISTER("get_gl_blend_dst_alpha",ring_get_gl_blend_dst_alpha);
	RING_API_REGISTER("get_gl_blend_src_alpha",ring_get_gl_blend_src_alpha);
	RING_API_REGISTER("get_gl_point_size_min",ring_get_gl_point_size_min);
	RING_API_REGISTER("get_gl_point_size_max",ring_get_gl_point_size_max);
	RING_API_REGISTER("get_gl_point_fade_threshold_size",ring_get_gl_point_fade_threshold_size);
	RING_API_REGISTER("get_gl_point_distance_attenuation",ring_get_gl_point_distance_attenuation);
	RING_API_REGISTER("get_gl_generate_mipmap",ring_get_gl_generate_mipmap);
	RING_API_REGISTER("get_gl_generate_mipmap_hint",ring_get_gl_generate_mipmap_hint);
	RING_API_REGISTER("get_gl_depth_component16",ring_get_gl_depth_component16);
	RING_API_REGISTER("get_gl_depth_component24",ring_get_gl_depth_component24);
	RING_API_REGISTER("get_gl_depth_component32",ring_get_gl_depth_component32);
	RING_API_REGISTER("get_gl_mirrored_repeat",ring_get_gl_mirrored_repeat);
	RING_API_REGISTER("get_gl_fog_coordinate_source",ring_get_gl_fog_coordinate_source);
	RING_API_REGISTER("get_gl_fog_coordinate",ring_get_gl_fog_coordinate);
	RING_API_REGISTER("get_gl_fragment_depth",ring_get_gl_fragment_depth);
	RING_API_REGISTER("get_gl_current_fog_coordinate",ring_get_gl_current_fog_coordinate);
	RING_API_REGISTER("get_gl_fog_coordinate_array_type",ring_get_gl_fog_coordinate_array_type);
	RING_API_REGISTER("get_gl_fog_coordinate_array_stride",ring_get_gl_fog_coordinate_array_stride);
	RING_API_REGISTER("get_gl_fog_coordinate_array_pointer",ring_get_gl_fog_coordinate_array_pointer);
	RING_API_REGISTER("get_gl_fog_coordinate_array",ring_get_gl_fog_coordinate_array);
	RING_API_REGISTER("get_gl_color_sum",ring_get_gl_color_sum);
	RING_API_REGISTER("get_gl_current_secondary_color",ring_get_gl_current_secondary_color);
	RING_API_REGISTER("get_gl_secondary_color_array_size",ring_get_gl_secondary_color_array_size);
	RING_API_REGISTER("get_gl_secondary_color_array_type",ring_get_gl_secondary_color_array_type);
	RING_API_REGISTER("get_gl_secondary_color_array_stride",ring_get_gl_secondary_color_array_stride);
	RING_API_REGISTER("get_gl_secondary_color_array_pointer",ring_get_gl_secondary_color_array_pointer);
	RING_API_REGISTER("get_gl_secondary_color_array",ring_get_gl_secondary_color_array);
	RING_API_REGISTER("get_gl_max_texture_lod_bias",ring_get_gl_max_texture_lod_bias);
	RING_API_REGISTER("get_gl_texture_filter_control",ring_get_gl_texture_filter_control);
	RING_API_REGISTER("get_gl_texture_lod_bias",ring_get_gl_texture_lod_bias);
	RING_API_REGISTER("get_gl_incr_wrap",ring_get_gl_incr_wrap);
	RING_API_REGISTER("get_gl_decr_wrap",ring_get_gl_decr_wrap);
	RING_API_REGISTER("get_gl_texture_depth_size",ring_get_gl_texture_depth_size);
	RING_API_REGISTER("get_gl_depth_texture_mode",ring_get_gl_depth_texture_mode);
	RING_API_REGISTER("get_gl_texture_compare_mode",ring_get_gl_texture_compare_mode);
	RING_API_REGISTER("get_gl_texture_compare_func",ring_get_gl_texture_compare_func);
	RING_API_REGISTER("get_gl_compare_r_to_texture",ring_get_gl_compare_r_to_texture);
	RING_API_REGISTER("get_gl_current_fog_coord",ring_get_gl_current_fog_coord);
	RING_API_REGISTER("get_gl_fog_coord",ring_get_gl_fog_coord);
	RING_API_REGISTER("get_gl_fog_coord_array",ring_get_gl_fog_coord_array);
	RING_API_REGISTER("get_gl_fog_coord_array_buffer_binding",ring_get_gl_fog_coord_array_buffer_binding);
	RING_API_REGISTER("get_gl_fog_coord_array_pointer",ring_get_gl_fog_coord_array_pointer);
	RING_API_REGISTER("get_gl_fog_coord_array_stride",ring_get_gl_fog_coord_array_stride);
	RING_API_REGISTER("get_gl_fog_coord_array_type",ring_get_gl_fog_coord_array_type);
	RING_API_REGISTER("get_gl_fog_coord_src",ring_get_gl_fog_coord_src);
	RING_API_REGISTER("get_gl_src0_alpha",ring_get_gl_src0_alpha);
	RING_API_REGISTER("get_gl_src0_rgb",ring_get_gl_src0_rgb);
	RING_API_REGISTER("get_gl_src1_alpha",ring_get_gl_src1_alpha);
	RING_API_REGISTER("get_gl_src1_rgb",ring_get_gl_src1_rgb);
	RING_API_REGISTER("get_gl_src2_alpha",ring_get_gl_src2_alpha);
	RING_API_REGISTER("get_gl_src2_rgb",ring_get_gl_src2_rgb);
	RING_API_REGISTER("get_gl_buffer_size",ring_get_gl_buffer_size);
	RING_API_REGISTER("get_gl_buffer_usage",ring_get_gl_buffer_usage);
	RING_API_REGISTER("get_gl_query_counter_bits",ring_get_gl_query_counter_bits);
	RING_API_REGISTER("get_gl_current_query",ring_get_gl_current_query);
	RING_API_REGISTER("get_gl_query_result",ring_get_gl_query_result);
	RING_API_REGISTER("get_gl_query_result_available",ring_get_gl_query_result_available);
	RING_API_REGISTER("get_gl_array_buffer",ring_get_gl_array_buffer);
	RING_API_REGISTER("get_gl_element_array_buffer",ring_get_gl_element_array_buffer);
	RING_API_REGISTER("get_gl_array_buffer_binding",ring_get_gl_array_buffer_binding);
	RING_API_REGISTER("get_gl_element_array_buffer_binding",ring_get_gl_element_array_buffer_binding);
	RING_API_REGISTER("get_gl_vertex_array_buffer_binding",ring_get_gl_vertex_array_buffer_binding);
	RING_API_REGISTER("get_gl_normal_array_buffer_binding",ring_get_gl_normal_array_buffer_binding);
	RING_API_REGISTER("get_gl_color_array_buffer_binding",ring_get_gl_color_array_buffer_binding);
	RING_API_REGISTER("get_gl_index_array_buffer_binding",ring_get_gl_index_array_buffer_binding);
	RING_API_REGISTER("get_gl_texture_coord_array_buffer_binding",ring_get_gl_texture_coord_array_buffer_binding);
	RING_API_REGISTER("get_gl_edge_flag_array_buffer_binding",ring_get_gl_edge_flag_array_buffer_binding);
	RING_API_REGISTER("get_gl_secondary_color_array_buffer_binding",ring_get_gl_secondary_color_array_buffer_binding);
	RING_API_REGISTER("get_gl_fog_coordinate_array_buffer_binding",ring_get_gl_fog_coordinate_array_buffer_binding);
	RING_API_REGISTER("get_gl_weight_array_buffer_binding",ring_get_gl_weight_array_buffer_binding);
	RING_API_REGISTER("get_gl_vertex_attrib_array_buffer_binding",ring_get_gl_vertex_attrib_array_buffer_binding);
	RING_API_REGISTER("get_gl_read_only",ring_get_gl_read_only);
	RING_API_REGISTER("get_gl_write_only",ring_get_gl_write_only);
	RING_API_REGISTER("get_gl_read_write",ring_get_gl_read_write);
	RING_API_REGISTER("get_gl_buffer_access",ring_get_gl_buffer_access);
	RING_API_REGISTER("get_gl_buffer_mapped",ring_get_gl_buffer_mapped);
	RING_API_REGISTER("get_gl_buffer_map_pointer",ring_get_gl_buffer_map_pointer);
	RING_API_REGISTER("get_gl_stream_draw",ring_get_gl_stream_draw);
	RING_API_REGISTER("get_gl_stream_read",ring_get_gl_stream_read);
	RING_API_REGISTER("get_gl_stream_copy",ring_get_gl_stream_copy);
	RING_API_REGISTER("get_gl_static_draw",ring_get_gl_static_draw);
	RING_API_REGISTER("get_gl_static_read",ring_get_gl_static_read);
	RING_API_REGISTER("get_gl_static_copy",ring_get_gl_static_copy);
	RING_API_REGISTER("get_gl_dynamic_draw",ring_get_gl_dynamic_draw);
	RING_API_REGISTER("get_gl_dynamic_read",ring_get_gl_dynamic_read);
	RING_API_REGISTER("get_gl_dynamic_copy",ring_get_gl_dynamic_copy);
	RING_API_REGISTER("get_gl_samples_passed",ring_get_gl_samples_passed);
}
