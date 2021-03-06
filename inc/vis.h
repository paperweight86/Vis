#pragma once

#include "types.h"

#include "vis_def.h"

namespace vis
{
	struct renderer
	{
		uti::ptr hwnd;
		uti::ptr hdc;
		uti::ptr context;
	};

	VIS_DEF void initialise(renderer* renderer, uti::ptr hwnd);

	VIS_DEF void begin_frame(renderer* renderer);

	VIS_DEF void end_frame(renderer* renderer);

	VIS_DEF void shutdown(renderer* renderer);

	VIS_DEF void get_shader_errors(uti::u32 shader_id, char* shader_error_buffer, uti::u32 shader_error_buffer_len);

	VIS_DEF bool create_compiled_vertex_shader(const char* shaderText, uti::u32* shader_id, uti::u32* errors_length);

	VIS_DEF bool create_compiled_pixel_shader(const char* shaderText, uti::u32* shader_id, uti::u32* errors_length);

	VIS_DEF bool create_linked_shader_program(uti::u32* shader_ids, uti::u32 num_shader_ids, uti::u32* program_id, uti::u32* errors_length);

	VIS_DEF void get_program_errors(uti::u32 program_id, char* program_error_buffer, uti::u32 program_error_buffer_len);

	VIS_DEF void destroy_shader(uti::u32 shader_id);

	VIS_DEF void destroy_program(uti::u32 program_id);

	VIS_DEF bool get_program_variable_id(uti::u32 program_id, uti::i32* variable_id, uti::cstr name);

	VIS_DEF void set_program_variable(uti::i32 variable_id, const uti::float44& matrix);

	VIS_DEF void set_program_variable(uti::i32 variable_id, const uti::i32& texture);

	VIS_DEF void set_program_variable(uti::i32 variable_id, const uti::float4& value);

	VIS_DEF void create_vertex_buffer(const float* elements, uti::u32 num_elements, uti::u32* vbuffer_id);

	VIS_DEF void destroy_vertex_buffer(uti::u32* vbuffer_id);

	VIS_DEF void create_index_buffer(const uti::u32* elements, uti::u32 num_elements, uti::u32* ibuffer_id);

	VIS_DEF void destroy_index_buffer(uti::u32* ibuffer_id);

	VIS_DEF bool load_shader_program(const char* vs_path, const char* ps_path, uti::u32* program_id);
}
