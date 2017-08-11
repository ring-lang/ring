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
	ring_vm_funcregister("get_gl_aux3",ring_get_gl_aux3);
	ring_vm_funcregister("get_gl_invalid_enum",ring_get_gl_invalid_enum);
	ring_vm_funcregister("get_gl_invalid_value",ring_get_gl_invalid_value);
	ring_vm_funcregister("get_gl_invalid_operation",ring_get_gl_invalid_operation);
	ring_vm_funcregister("get_gl_stack_overflow",ring_get_gl_stack_overflow);
	ring_vm_funcregister("get_gl_stack_underflow",ring_get_gl_stack_underflow);
	ring_vm_funcregister("get_gl_out_of_memory",ring_get_gl_out_of_memory);
	ring_vm_funcregister("get_gl_2d",ring_get_gl_2d);
	ring_vm_funcregister("get_gl_3d",ring_get_gl_3d);
	ring_vm_funcregister("get_gl_3d_color",ring_get_gl_3d_color);
	ring_vm_funcregister("get_gl_3d_color_texture",ring_get_gl_3d_color_texture);
	ring_vm_funcregister("get_gl_4d_color_texture",ring_get_gl_4d_color_texture);
	ring_vm_funcregister("get_gl_pass_through_token",ring_get_gl_pass_through_token);
	ring_vm_funcregister("get_gl_point_token",ring_get_gl_point_token);
	ring_vm_funcregister("get_gl_line_token",ring_get_gl_line_token);
	ring_vm_funcregister("get_gl_polygon_token",ring_get_gl_polygon_token);
	ring_vm_funcregister("get_gl_bitmap_token",ring_get_gl_bitmap_token);
	ring_vm_funcregister("get_gl_draw_pixel_token",ring_get_gl_draw_pixel_token);
	ring_vm_funcregister("get_gl_copy_pixel_token",ring_get_gl_copy_pixel_token);
	ring_vm_funcregister("get_gl_line_reset_token",ring_get_gl_line_reset_token);
	ring_vm_funcregister("get_gl_exp",ring_get_gl_exp);
	ring_vm_funcregister("get_gl_viewport_bit",ring_get_gl_viewport_bit);
	ring_vm_funcregister("get_gl_exp2",ring_get_gl_exp2);
	ring_vm_funcregister("get_gl_cw",ring_get_gl_cw);
	ring_vm_funcregister("get_gl_ccw",ring_get_gl_ccw);
	ring_vm_funcregister("get_gl_coeff",ring_get_gl_coeff);
	ring_vm_funcregister("get_gl_order",ring_get_gl_order);
	ring_vm_funcregister("get_gl_domain",ring_get_gl_domain);
	ring_vm_funcregister("get_gl_current_color",ring_get_gl_current_color);
	ring_vm_funcregister("get_gl_current_index",ring_get_gl_current_index);
	ring_vm_funcregister("get_gl_current_normal",ring_get_gl_current_normal);
	ring_vm_funcregister("get_gl_current_texture_coords",ring_get_gl_current_texture_coords);
	ring_vm_funcregister("get_gl_current_raster_color",ring_get_gl_current_raster_color);
	ring_vm_funcregister("get_gl_current_raster_index",ring_get_gl_current_raster_index);
	ring_vm_funcregister("get_gl_current_raster_texture_coords",ring_get_gl_current_raster_texture_coords);
	ring_vm_funcregister("get_gl_current_raster_position",ring_get_gl_current_raster_position);
	ring_vm_funcregister("get_gl_current_raster_position_valid",ring_get_gl_current_raster_position_valid);
	ring_vm_funcregister("get_gl_current_raster_distance",ring_get_gl_current_raster_distance);
	ring_vm_funcregister("get_gl_point_smooth",ring_get_gl_point_smooth);
	ring_vm_funcregister("get_gl_point_size",ring_get_gl_point_size);
	ring_vm_funcregister("get_gl_point_size_range",ring_get_gl_point_size_range);
	ring_vm_funcregister("get_gl_point_size_granularity",ring_get_gl_point_size_granularity);
	ring_vm_funcregister("get_gl_line_smooth",ring_get_gl_line_smooth);
	ring_vm_funcregister("get_gl_line_width",ring_get_gl_line_width);
	ring_vm_funcregister("get_gl_line_width_range",ring_get_gl_line_width_range);
	ring_vm_funcregister("get_gl_line_width_granularity",ring_get_gl_line_width_granularity);
	ring_vm_funcregister("get_gl_line_stipple",ring_get_gl_line_stipple);
	ring_vm_funcregister("get_gl_line_stipple_pattern",ring_get_gl_line_stipple_pattern);
	ring_vm_funcregister("get_gl_line_stipple_repeat",ring_get_gl_line_stipple_repeat);
	ring_vm_funcregister("get_gl_list_mode",ring_get_gl_list_mode);
	ring_vm_funcregister("get_gl_max_list_nesting",ring_get_gl_max_list_nesting);
	ring_vm_funcregister("get_gl_list_base",ring_get_gl_list_base);
	ring_vm_funcregister("get_gl_list_index",ring_get_gl_list_index);
	ring_vm_funcregister("get_gl_polygon_mode",ring_get_gl_polygon_mode);
	ring_vm_funcregister("get_gl_polygon_smooth",ring_get_gl_polygon_smooth);
	ring_vm_funcregister("get_gl_polygon_stipple",ring_get_gl_polygon_stipple);
	ring_vm_funcregister("get_gl_edge_flag",ring_get_gl_edge_flag);
	ring_vm_funcregister("get_gl_cull_face",ring_get_gl_cull_face);
	ring_vm_funcregister("get_gl_cull_face_mode",ring_get_gl_cull_face_mode);
	ring_vm_funcregister("get_gl_front_face",ring_get_gl_front_face);
	ring_vm_funcregister("get_gl_lighting",ring_get_gl_lighting);
	ring_vm_funcregister("get_gl_light_model_local_viewer",ring_get_gl_light_model_local_viewer);
	ring_vm_funcregister("get_gl_light_model_two_side",ring_get_gl_light_model_two_side);
	ring_vm_funcregister("get_gl_light_model_ambient",ring_get_gl_light_model_ambient);
	ring_vm_funcregister("get_gl_shade_model",ring_get_gl_shade_model);
	ring_vm_funcregister("get_gl_color_material_face",ring_get_gl_color_material_face);
	ring_vm_funcregister("get_gl_color_material_parameter",ring_get_gl_color_material_parameter);
	ring_vm_funcregister("get_gl_color_material",ring_get_gl_color_material);
	ring_vm_funcregister("get_gl_fog",ring_get_gl_fog);
	ring_vm_funcregister("get_gl_fog_index",ring_get_gl_fog_index);
	ring_vm_funcregister("get_gl_fog_density",ring_get_gl_fog_density);
	ring_vm_funcregister("get_gl_fog_start",ring_get_gl_fog_start);
	ring_vm_funcregister("get_gl_fog_end",ring_get_gl_fog_end);
	ring_vm_funcregister("get_gl_fog_mode",ring_get_gl_fog_mode);
	ring_vm_funcregister("get_gl_fog_color",ring_get_gl_fog_color);
	ring_vm_funcregister("get_gl_depth_range",ring_get_gl_depth_range);
	ring_vm_funcregister("get_gl_depth_test",ring_get_gl_depth_test);
	ring_vm_funcregister("get_gl_depth_writemask",ring_get_gl_depth_writemask);
	ring_vm_funcregister("get_gl_depth_clear_value",ring_get_gl_depth_clear_value);
	ring_vm_funcregister("get_gl_depth_func",ring_get_gl_depth_func);
	ring_vm_funcregister("get_gl_accum_clear_value",ring_get_gl_accum_clear_value);
	ring_vm_funcregister("get_gl_stencil_test",ring_get_gl_stencil_test);
	ring_vm_funcregister("get_gl_stencil_clear_value",ring_get_gl_stencil_clear_value);
	ring_vm_funcregister("get_gl_stencil_func",ring_get_gl_stencil_func);
	ring_vm_funcregister("get_gl_stencil_value_mask",ring_get_gl_stencil_value_mask);
	ring_vm_funcregister("get_gl_stencil_fail",ring_get_gl_stencil_fail);
	ring_vm_funcregister("get_gl_stencil_pass_depth_fail",ring_get_gl_stencil_pass_depth_fail);
	ring_vm_funcregister("get_gl_stencil_pass_depth_pass",ring_get_gl_stencil_pass_depth_pass);
	ring_vm_funcregister("get_gl_stencil_ref",ring_get_gl_stencil_ref);
	ring_vm_funcregister("get_gl_stencil_writemask",ring_get_gl_stencil_writemask);
	ring_vm_funcregister("get_gl_matrix_mode",ring_get_gl_matrix_mode);
	ring_vm_funcregister("get_gl_normalize",ring_get_gl_normalize);
	ring_vm_funcregister("get_gl_viewport",ring_get_gl_viewport);
	ring_vm_funcregister("get_gl_modelview_stack_depth",ring_get_gl_modelview_stack_depth);
	ring_vm_funcregister("get_gl_projection_stack_depth",ring_get_gl_projection_stack_depth);
	ring_vm_funcregister("get_gl_texture_stack_depth",ring_get_gl_texture_stack_depth);
	ring_vm_funcregister("get_gl_modelview_matrix",ring_get_gl_modelview_matrix);
	ring_vm_funcregister("get_gl_projection_matrix",ring_get_gl_projection_matrix);
	ring_vm_funcregister("get_gl_texture_matrix",ring_get_gl_texture_matrix);
	ring_vm_funcregister("get_gl_attrib_stack_depth",ring_get_gl_attrib_stack_depth);
	ring_vm_funcregister("get_gl_client_attrib_stack_depth",ring_get_gl_client_attrib_stack_depth);
	ring_vm_funcregister("get_gl_alpha_test",ring_get_gl_alpha_test);
	ring_vm_funcregister("get_gl_alpha_test_func",ring_get_gl_alpha_test_func);
	ring_vm_funcregister("get_gl_alpha_test_ref",ring_get_gl_alpha_test_ref);
	ring_vm_funcregister("get_gl_dither",ring_get_gl_dither);
	ring_vm_funcregister("get_gl_blend_dst",ring_get_gl_blend_dst);
	ring_vm_funcregister("get_gl_blend_src",ring_get_gl_blend_src);
	ring_vm_funcregister("get_gl_blend",ring_get_gl_blend);
	ring_vm_funcregister("get_gl_logic_op_mode",ring_get_gl_logic_op_mode);
	ring_vm_funcregister("get_gl_index_logic_op",ring_get_gl_index_logic_op);
	ring_vm_funcregister("get_gl_color_logic_op",ring_get_gl_color_logic_op);
	ring_vm_funcregister("get_gl_aux_buffers",ring_get_gl_aux_buffers);
	ring_vm_funcregister("get_gl_draw_buffer",ring_get_gl_draw_buffer);
	ring_vm_funcregister("get_gl_read_buffer",ring_get_gl_read_buffer);
	ring_vm_funcregister("get_gl_scissor_box",ring_get_gl_scissor_box);
	ring_vm_funcregister("get_gl_scissor_test",ring_get_gl_scissor_test);
	ring_vm_funcregister("get_gl_index_clear_value",ring_get_gl_index_clear_value);
	ring_vm_funcregister("get_gl_index_writemask",ring_get_gl_index_writemask);
	ring_vm_funcregister("get_gl_color_clear_value",ring_get_gl_color_clear_value);
	ring_vm_funcregister("get_gl_color_writemask",ring_get_gl_color_writemask);
	ring_vm_funcregister("get_gl_index_mode",ring_get_gl_index_mode);
	ring_vm_funcregister("get_gl_rgba_mode",ring_get_gl_rgba_mode);
	ring_vm_funcregister("get_gl_doublebuffer",ring_get_gl_doublebuffer);
	ring_vm_funcregister("get_gl_stereo",ring_get_gl_stereo);
	ring_vm_funcregister("get_gl_render_mode",ring_get_gl_render_mode);
	ring_vm_funcregister("get_gl_perspective_correction_hint",ring_get_gl_perspective_correction_hint);
	ring_vm_funcregister("get_gl_point_smooth_hint",ring_get_gl_point_smooth_hint);
	ring_vm_funcregister("get_gl_line_smooth_hint",ring_get_gl_line_smooth_hint);
	ring_vm_funcregister("get_gl_polygon_smooth_hint",ring_get_gl_polygon_smooth_hint);
	ring_vm_funcregister("get_gl_fog_hint",ring_get_gl_fog_hint);
	ring_vm_funcregister("get_gl_texture_gen_s",ring_get_gl_texture_gen_s);
	ring_vm_funcregister("get_gl_texture_gen_t",ring_get_gl_texture_gen_t);
	ring_vm_funcregister("get_gl_texture_gen_r",ring_get_gl_texture_gen_r);
	ring_vm_funcregister("get_gl_texture_gen_q",ring_get_gl_texture_gen_q);
	ring_vm_funcregister("get_gl_pixel_map_i_to_i",ring_get_gl_pixel_map_i_to_i);
	ring_vm_funcregister("get_gl_pixel_map_s_to_s",ring_get_gl_pixel_map_s_to_s);
	ring_vm_funcregister("get_gl_pixel_map_i_to_r",ring_get_gl_pixel_map_i_to_r);
	ring_vm_funcregister("get_gl_pixel_map_i_to_g",ring_get_gl_pixel_map_i_to_g);
	ring_vm_funcregister("get_gl_pixel_map_i_to_b",ring_get_gl_pixel_map_i_to_b);
	ring_vm_funcregister("get_gl_pixel_map_i_to_a",ring_get_gl_pixel_map_i_to_a);
	ring_vm_funcregister("get_gl_pixel_map_r_to_r",ring_get_gl_pixel_map_r_to_r);
	ring_vm_funcregister("get_gl_pixel_map_g_to_g",ring_get_gl_pixel_map_g_to_g);
	ring_vm_funcregister("get_gl_pixel_map_b_to_b",ring_get_gl_pixel_map_b_to_b);
	ring_vm_funcregister("get_gl_pixel_map_a_to_a",ring_get_gl_pixel_map_a_to_a);
	ring_vm_funcregister("get_gl_pixel_map_i_to_i_size",ring_get_gl_pixel_map_i_to_i_size);
	ring_vm_funcregister("get_gl_pixel_map_s_to_s_size",ring_get_gl_pixel_map_s_to_s_size);
	ring_vm_funcregister("get_gl_pixel_map_i_to_r_size",ring_get_gl_pixel_map_i_to_r_size);
	ring_vm_funcregister("get_gl_pixel_map_i_to_g_size",ring_get_gl_pixel_map_i_to_g_size);
	ring_vm_funcregister("get_gl_pixel_map_i_to_b_size",ring_get_gl_pixel_map_i_to_b_size);
	ring_vm_funcregister("get_gl_pixel_map_i_to_a_size",ring_get_gl_pixel_map_i_to_a_size);
	ring_vm_funcregister("get_gl_pixel_map_r_to_r_size",ring_get_gl_pixel_map_r_to_r_size);
	ring_vm_funcregister("get_gl_pixel_map_g_to_g_size",ring_get_gl_pixel_map_g_to_g_size);
	ring_vm_funcregister("get_gl_pixel_map_b_to_b_size",ring_get_gl_pixel_map_b_to_b_size);
	ring_vm_funcregister("get_gl_pixel_map_a_to_a_size",ring_get_gl_pixel_map_a_to_a_size);
	ring_vm_funcregister("get_gl_unpack_swap_bytes",ring_get_gl_unpack_swap_bytes);
	ring_vm_funcregister("get_gl_unpack_lsb_first",ring_get_gl_unpack_lsb_first);
	ring_vm_funcregister("get_gl_unpack_row_length",ring_get_gl_unpack_row_length);
	ring_vm_funcregister("get_gl_unpack_skip_rows",ring_get_gl_unpack_skip_rows);
	ring_vm_funcregister("get_gl_unpack_skip_pixels",ring_get_gl_unpack_skip_pixels);
	ring_vm_funcregister("get_gl_unpack_alignment",ring_get_gl_unpack_alignment);
	ring_vm_funcregister("get_gl_pack_swap_bytes",ring_get_gl_pack_swap_bytes);
	ring_vm_funcregister("get_gl_pack_lsb_first",ring_get_gl_pack_lsb_first);
	ring_vm_funcregister("get_gl_pack_row_length",ring_get_gl_pack_row_length);
	ring_vm_funcregister("get_gl_pack_skip_rows",ring_get_gl_pack_skip_rows);
	ring_vm_funcregister("get_gl_pack_skip_pixels",ring_get_gl_pack_skip_pixels);
	ring_vm_funcregister("get_gl_pack_alignment",ring_get_gl_pack_alignment);
	ring_vm_funcregister("get_gl_map_color",ring_get_gl_map_color);
	ring_vm_funcregister("get_gl_map_stencil",ring_get_gl_map_stencil);
	ring_vm_funcregister("get_gl_index_shift",ring_get_gl_index_shift);
	ring_vm_funcregister("get_gl_index_offset",ring_get_gl_index_offset);
	ring_vm_funcregister("get_gl_red_scale",ring_get_gl_red_scale);
	ring_vm_funcregister("get_gl_red_bias",ring_get_gl_red_bias);
	ring_vm_funcregister("get_gl_zoom_x",ring_get_gl_zoom_x);
	ring_vm_funcregister("get_gl_zoom_y",ring_get_gl_zoom_y);
	ring_vm_funcregister("get_gl_green_scale",ring_get_gl_green_scale);
	ring_vm_funcregister("get_gl_green_bias",ring_get_gl_green_bias);
	ring_vm_funcregister("get_gl_blue_scale",ring_get_gl_blue_scale);
	ring_vm_funcregister("get_gl_blue_bias",ring_get_gl_blue_bias);
	ring_vm_funcregister("get_gl_alpha_scale",ring_get_gl_alpha_scale);
	ring_vm_funcregister("get_gl_alpha_bias",ring_get_gl_alpha_bias);
	ring_vm_funcregister("get_gl_depth_scale",ring_get_gl_depth_scale);
	ring_vm_funcregister("get_gl_depth_bias",ring_get_gl_depth_bias);
	ring_vm_funcregister("get_gl_max_eval_order",ring_get_gl_max_eval_order);
	ring_vm_funcregister("get_gl_max_lights",ring_get_gl_max_lights);
	ring_vm_funcregister("get_gl_max_clip_planes",ring_get_gl_max_clip_planes);
	ring_vm_funcregister("get_gl_max_texture_size",ring_get_gl_max_texture_size);
	ring_vm_funcregister("get_gl_max_pixel_map_table",ring_get_gl_max_pixel_map_table);
	ring_vm_funcregister("get_gl_max_attrib_stack_depth",ring_get_gl_max_attrib_stack_depth);
	ring_vm_funcregister("get_gl_max_modelview_stack_depth",ring_get_gl_max_modelview_stack_depth);
	ring_vm_funcregister("get_gl_max_name_stack_depth",ring_get_gl_max_name_stack_depth);
	ring_vm_funcregister("get_gl_max_projection_stack_depth",ring_get_gl_max_projection_stack_depth);
	ring_vm_funcregister("get_gl_max_texture_stack_depth",ring_get_gl_max_texture_stack_depth);
	ring_vm_funcregister("get_gl_max_viewport_dims",ring_get_gl_max_viewport_dims);
	ring_vm_funcregister("get_gl_max_client_attrib_stack_depth",ring_get_gl_max_client_attrib_stack_depth);
	ring_vm_funcregister("get_gl_subpixel_bits",ring_get_gl_subpixel_bits);
	ring_vm_funcregister("get_gl_index_bits",ring_get_gl_index_bits);
	ring_vm_funcregister("get_gl_red_bits",ring_get_gl_red_bits);
	ring_vm_funcregister("get_gl_green_bits",ring_get_gl_green_bits);
	ring_vm_funcregister("get_gl_blue_bits",ring_get_gl_blue_bits);
	ring_vm_funcregister("get_gl_alpha_bits",ring_get_gl_alpha_bits);
	ring_vm_funcregister("get_gl_depth_bits",ring_get_gl_depth_bits);
	ring_vm_funcregister("get_gl_stencil_bits",ring_get_gl_stencil_bits);
	ring_vm_funcregister("get_gl_accum_red_bits",ring_get_gl_accum_red_bits);
	ring_vm_funcregister("get_gl_accum_green_bits",ring_get_gl_accum_green_bits);
	ring_vm_funcregister("get_gl_accum_blue_bits",ring_get_gl_accum_blue_bits);
	ring_vm_funcregister("get_gl_accum_alpha_bits",ring_get_gl_accum_alpha_bits);
	ring_vm_funcregister("get_gl_name_stack_depth",ring_get_gl_name_stack_depth);
	ring_vm_funcregister("get_gl_auto_normal",ring_get_gl_auto_normal);
	ring_vm_funcregister("get_gl_map1_color_4",ring_get_gl_map1_color_4);
	ring_vm_funcregister("get_gl_map1_index",ring_get_gl_map1_index);
	ring_vm_funcregister("get_gl_map1_normal",ring_get_gl_map1_normal);
	ring_vm_funcregister("get_gl_map1_texture_coord_1",ring_get_gl_map1_texture_coord_1);
	ring_vm_funcregister("get_gl_map1_texture_coord_2",ring_get_gl_map1_texture_coord_2);
	ring_vm_funcregister("get_gl_map1_texture_coord_3",ring_get_gl_map1_texture_coord_3);
	ring_vm_funcregister("get_gl_map1_texture_coord_4",ring_get_gl_map1_texture_coord_4);
	ring_vm_funcregister("get_gl_map1_vertex_3",ring_get_gl_map1_vertex_3);
	ring_vm_funcregister("get_gl_map1_vertex_4",ring_get_gl_map1_vertex_4);
	ring_vm_funcregister("get_gl_map2_color_4",ring_get_gl_map2_color_4);
	ring_vm_funcregister("get_gl_map2_index",ring_get_gl_map2_index);
	ring_vm_funcregister("get_gl_map2_normal",ring_get_gl_map2_normal);
	ring_vm_funcregister("get_gl_map2_texture_coord_1",ring_get_gl_map2_texture_coord_1);
	ring_vm_funcregister("get_gl_map2_texture_coord_2",ring_get_gl_map2_texture_coord_2);
	ring_vm_funcregister("get_gl_map2_texture_coord_3",ring_get_gl_map2_texture_coord_3);
	ring_vm_funcregister("get_gl_map2_texture_coord_4",ring_get_gl_map2_texture_coord_4);
	ring_vm_funcregister("get_gl_map2_vertex_3",ring_get_gl_map2_vertex_3);
	ring_vm_funcregister("get_gl_map2_vertex_4",ring_get_gl_map2_vertex_4);
	ring_vm_funcregister("get_gl_map1_grid_domain",ring_get_gl_map1_grid_domain);
	ring_vm_funcregister("get_gl_map1_grid_segments",ring_get_gl_map1_grid_segments);
	ring_vm_funcregister("get_gl_map2_grid_domain",ring_get_gl_map2_grid_domain);
	ring_vm_funcregister("get_gl_map2_grid_segments",ring_get_gl_map2_grid_segments);
	ring_vm_funcregister("get_gl_texture_1d",ring_get_gl_texture_1d);
	ring_vm_funcregister("get_gl_texture_2d",ring_get_gl_texture_2d);
	ring_vm_funcregister("get_gl_feedback_buffer_pointer",ring_get_gl_feedback_buffer_pointer);
	ring_vm_funcregister("get_gl_feedback_buffer_size",ring_get_gl_feedback_buffer_size);
	ring_vm_funcregister("get_gl_feedback_buffer_type",ring_get_gl_feedback_buffer_type);
	ring_vm_funcregister("get_gl_selection_buffer_pointer",ring_get_gl_selection_buffer_pointer);
	ring_vm_funcregister("get_gl_selection_buffer_size",ring_get_gl_selection_buffer_size);
	ring_vm_funcregister("get_gl_texture_width",ring_get_gl_texture_width);
	ring_vm_funcregister("get_gl_transform_bit",ring_get_gl_transform_bit);
	ring_vm_funcregister("get_gl_texture_height",ring_get_gl_texture_height);
	ring_vm_funcregister("get_gl_texture_internal_format",ring_get_gl_texture_internal_format);
	ring_vm_funcregister("get_gl_texture_border_color",ring_get_gl_texture_border_color);
	ring_vm_funcregister("get_gl_texture_border",ring_get_gl_texture_border);
	ring_vm_funcregister("get_gl_dont_care",ring_get_gl_dont_care);
	ring_vm_funcregister("get_gl_fastest",ring_get_gl_fastest);
	ring_vm_funcregister("get_gl_nicest",ring_get_gl_nicest);
	ring_vm_funcregister("get_gl_ambient",ring_get_gl_ambient);
	ring_vm_funcregister("get_gl_diffuse",ring_get_gl_diffuse);
	ring_vm_funcregister("get_gl_specular",ring_get_gl_specular);
	ring_vm_funcregister("get_gl_position",ring_get_gl_position);
	ring_vm_funcregister("get_gl_spot_direction",ring_get_gl_spot_direction);
	ring_vm_funcregister("get_gl_spot_exponent",ring_get_gl_spot_exponent);
	ring_vm_funcregister("get_gl_spot_cutoff",ring_get_gl_spot_cutoff);
	ring_vm_funcregister("get_gl_constant_attenuation",ring_get_gl_constant_attenuation);
	ring_vm_funcregister("get_gl_linear_attenuation",ring_get_gl_linear_attenuation);
	ring_vm_funcregister("get_gl_quadratic_attenuation",ring_get_gl_quadratic_attenuation);
	ring_vm_funcregister("get_gl_compile",ring_get_gl_compile);
	ring_vm_funcregister("get_gl_compile_and_execute",ring_get_gl_compile_and_execute);
	ring_vm_funcregister("get_gl_byte",ring_get_gl_byte);
	ring_vm_funcregister("get_gl_unsigned_byte",ring_get_gl_unsigned_byte);
	ring_vm_funcregister("get_gl_short",ring_get_gl_short);
	ring_vm_funcregister("get_gl_unsigned_short",ring_get_gl_unsigned_short);
	ring_vm_funcregister("get_gl_int",ring_get_gl_int);
	ring_vm_funcregister("get_gl_unsigned_int",ring_get_gl_unsigned_int);
	ring_vm_funcregister("get_gl_float",ring_get_gl_float);
	ring_vm_funcregister("get_gl_2_bytes",ring_get_gl_2_bytes);
	ring_vm_funcregister("get_gl_3_bytes",ring_get_gl_3_bytes);
	ring_vm_funcregister("get_gl_4_bytes",ring_get_gl_4_bytes);
	ring_vm_funcregister("get_gl_double",ring_get_gl_double);
	ring_vm_funcregister("get_gl_clear",ring_get_gl_clear);
	ring_vm_funcregister("get_gl_and",ring_get_gl_and);
	ring_vm_funcregister("get_gl_and_reverse",ring_get_gl_and_reverse);
	ring_vm_funcregister("get_gl_copy",ring_get_gl_copy);
	ring_vm_funcregister("get_gl_and_inverted",ring_get_gl_and_inverted);
	ring_vm_funcregister("get_gl_noop",ring_get_gl_noop);
	ring_vm_funcregister("get_gl_xor",ring_get_gl_xor);
	ring_vm_funcregister("get_gl_or",ring_get_gl_or);
	ring_vm_funcregister("get_gl_nor",ring_get_gl_nor);
	ring_vm_funcregister("get_gl_equiv",ring_get_gl_equiv);
	ring_vm_funcregister("get_gl_invert",ring_get_gl_invert);
	ring_vm_funcregister("get_gl_or_reverse",ring_get_gl_or_reverse);
	ring_vm_funcregister("get_gl_copy_inverted",ring_get_gl_copy_inverted);
	ring_vm_funcregister("get_gl_or_inverted",ring_get_gl_or_inverted);
	ring_vm_funcregister("get_gl_nand",ring_get_gl_nand);
	ring_vm_funcregister("get_gl_set",ring_get_gl_set);
	ring_vm_funcregister("get_gl_emission",ring_get_gl_emission);
	ring_vm_funcregister("get_gl_shininess",ring_get_gl_shininess);
	ring_vm_funcregister("get_gl_ambient_and_diffuse",ring_get_gl_ambient_and_diffuse);
	ring_vm_funcregister("get_gl_color_indexes",ring_get_gl_color_indexes);
	ring_vm_funcregister("get_gl_modelview",ring_get_gl_modelview);
	ring_vm_funcregister("get_gl_projection",ring_get_gl_projection);
	ring_vm_funcregister("get_gl_texture",ring_get_gl_texture);
	ring_vm_funcregister("get_gl_color",ring_get_gl_color);
	ring_vm_funcregister("get_gl_depth",ring_get_gl_depth);
	ring_vm_funcregister("get_gl_stencil",ring_get_gl_stencil);
	ring_vm_funcregister("get_gl_color_index",ring_get_gl_color_index);
	ring_vm_funcregister("get_gl_stencil_index",ring_get_gl_stencil_index);
	ring_vm_funcregister("get_gl_depth_component",ring_get_gl_depth_component);
	ring_vm_funcregister("get_gl_red",ring_get_gl_red);
	ring_vm_funcregister("get_gl_green",ring_get_gl_green);
	ring_vm_funcregister("get_gl_blue",ring_get_gl_blue);
	ring_vm_funcregister("get_gl_alpha",ring_get_gl_alpha);
	ring_vm_funcregister("get_gl_rgb",ring_get_gl_rgb);
	ring_vm_funcregister("get_gl_rgba",ring_get_gl_rgba);
	ring_vm_funcregister("get_gl_luminance",ring_get_gl_luminance);
	ring_vm_funcregister("get_gl_luminance_alpha",ring_get_gl_luminance_alpha);
	ring_vm_funcregister("get_gl_bitmap",ring_get_gl_bitmap);
	ring_vm_funcregister("get_gl_point",ring_get_gl_point);
	ring_vm_funcregister("get_gl_line",ring_get_gl_line);
	ring_vm_funcregister("get_gl_fill",ring_get_gl_fill);
	ring_vm_funcregister("get_gl_render",ring_get_gl_render);
	ring_vm_funcregister("get_gl_feedback",ring_get_gl_feedback);
	ring_vm_funcregister("get_gl_select",ring_get_gl_select);
	ring_vm_funcregister("get_gl_flat",ring_get_gl_flat);
	ring_vm_funcregister("get_gl_smooth",ring_get_gl_smooth);
	ring_vm_funcregister("get_gl_keep",ring_get_gl_keep);
	ring_vm_funcregister("get_gl_replace",ring_get_gl_replace);
	ring_vm_funcregister("get_gl_incr",ring_get_gl_incr);
	ring_vm_funcregister("get_gl_decr",ring_get_gl_decr);
	ring_vm_funcregister("get_gl_vendor",ring_get_gl_vendor);
	ring_vm_funcregister("get_gl_renderer",ring_get_gl_renderer);
	ring_vm_funcregister("get_gl_version",ring_get_gl_version);
}
