#include "vis.h"

#include <assert.h>

#include "tat.h"
#include "gel.h"
#include "file_system.h"
#include "log.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <gl/GL.h>
#include "..\gl\glext.h"
#include "..\gl\glfunc.h"

#include "float4.h"

GLenum g_gl_error;
#if NDEBUG
#define BREAK_IF_FAIL() (void)0
#else
#define BREAK_IF_FAIL() \
g_gl_error = glGetError();\
if( g_gl_error != GL_NO_ERROR ) \
{\
	uti::log::err_out("%s - GL Function Failed with %d", __FUNCTIONT__, g_gl_error);\
	DebugBreak();\
}
#endif

void vis::initialise(renderer* renderer, uti::ptr hwnd)
{
	assert(renderer != NULL);

	uti::ptr context = uti::gel::create_gl_context(hwnd);
	uti::gel::set_gl_context(hwnd, context);

	renderer->hwnd = hwnd;
	renderer->hdc = (uti::ptr)GetDC((HWND)hwnd);
	renderer->context = context;

	glClearColor(0.682f, 0.776f, 0.812f, 1.0f);
}

void vis::begin_frame(renderer* renderer)
{
	assert(renderer != NULL);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void vis::end_frame(renderer* renderer)
{
	assert(renderer != NULL);

	uti::gel::swap_gl_buffers(renderer->hdc);
}

void vis::shutdown(renderer* renderer)
{
	assert(renderer != NULL);

	uti::gel::destroy_gl_context(renderer->context);
}

bool vis::create_compiled_vertex_shader( const char* shaderText, uti::u32* shader_id, uti::u32* errors_length )
{
	*shader_id = glCreateShader(GL_VERTEX_SHADER);

	// Compile
	glShaderSource(*shader_id, 1, &shaderText, NULL);
	glCompileShader(*shader_id);

	// Check 
	GLint result = GL_FALSE;
	glGetShaderiv(*shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(*shader_id, GL_INFO_LOG_LENGTH, (GLint*)errors_length);

	return result != GL_FALSE;
}

bool vis::create_compiled_pixel_shader(const char* shaderText, uti::u32* shader_id, uti::u32* errors_length)
{
	*shader_id = glCreateShader(GL_FRAGMENT_SHADER);

	// Compile
	glShaderSource(*shader_id, 1, &shaderText, NULL);
	glCompileShader(*shader_id);

	// Check 
	GLint result = GL_FALSE;
	glGetShaderiv(*shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(*shader_id, GL_INFO_LOG_LENGTH, (GLint*)errors_length);

	return result != GL_FALSE;
}

void vis::get_shader_errors(uti::u32 shader_id, char* shader_error_buffer, uti::u32 shader_error_buffer_len)
{
	glGetShaderInfoLog(shader_id, shader_error_buffer_len, NULL, shader_error_buffer);
}

bool vis::create_linked_shader_program( uti::u32* shader_ids, uti::u32 num_shader_ids, uti::u32* program_id, uti::u32* errors_length)
{
	*program_id = glCreateProgram();
	for (uti::u32 i = 0; i < num_shader_ids; ++i)
	{
		glAttachShader(*program_id, shader_ids[i]);
		BREAK_IF_FAIL();
	}
	glLinkProgram(*program_id);

	// Check
	GLint result = GL_FALSE;
	glGetProgramiv(*program_id, GL_LINK_STATUS,	   &result);
	glGetProgramiv(*program_id, GL_INFO_LOG_LENGTH, (GLint*)errors_length);

	for (uti::u32 i = 0; i < num_shader_ids; ++i)
	{
		glDetachShader(*program_id, shader_ids[i]);
		BREAK_IF_FAIL();
	}

	return result != GL_FALSE;
}

void vis::get_program_errors(uti::u32 program_id, char* program_error_buffer, uti::u32 program_error_buffer_len)
{
	glGetProgramInfoLog(program_id, program_error_buffer_len, NULL, program_error_buffer);
}

void vis::destroy_shader(uti::u32 shader_id)
{
	glDeleteShader(shader_id);
}

void vis::destroy_program(uti::u32 program_id)
{
	glDeleteProgram(program_id);
}

bool vis::get_program_variable_id(uti::u32 program_id, uti::i32* variable_id, uti::cstr name)
{
	*variable_id = glGetUniformLocation(program_id, name);

	return *variable_id != -1;
}

void vis::set_program_variable(uti::i32 variable_id, const uti::float44& matrix)
{
	glUniformMatrix4fv(variable_id, 1, GL_FALSE, matrix.m);
}

void vis::set_program_variable(uti::i32 variable_id, const uti::i32& value)
{
	glUniform1i(variable_id, value);
}

void vis::set_program_variable(uti::i32 variable_id, const uti::float4& value)
{
	float value_array[4] = { 
		uti::get_x(value), 
		uti::get_y(value), 
		uti::get_z(value), 
		uti::get_h(value) };
	glUniform4fv(variable_id, 1, (float*)&value_array[0]);
}

void vis::create_vertex_buffer(const float* elements, uti::u32 num_elements, uti::u32* vbuffer_id)
{
	glGenBuffers(1, vbuffer_id);
	BREAK_IF_FAIL();
	glBindBuffer(GL_ARRAY_BUFFER, *vbuffer_id);
	BREAK_IF_FAIL();
	glBufferData(GL_ARRAY_BUFFER, num_elements*sizeof(float), elements, GL_STATIC_DRAW);
	BREAK_IF_FAIL();
}

void vis::destroy_vertex_buffer(uti::u32* vbuffer_id)
{
	glDeleteBuffers(1, vbuffer_id);
	BREAK_IF_FAIL();
}

void vis::create_index_buffer(const uti::u32* elements, uti::u32 num_elements, uti::u32* ibuffer_id)
{
	glGenBuffers(1, ibuffer_id);
	BREAK_IF_FAIL();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibuffer_id);
	BREAK_IF_FAIL();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_elements*sizeof(uti::u32), elements, GL_STATIC_DRAW);
	BREAK_IF_FAIL();
}

void vis::destroy_index_buffer(uti::u32* ibuffer_id)
{
	glDeleteBuffers(1, ibuffer_id);
	BREAK_IF_FAIL();
}

bool vis::load_shader_program(const char* vs_path, const char* ps_path, uti::u32* program_id)
{
	UTI_LOG_PREFIX_SCOPE("vis");

	char* ptr_ps_file_buffer = nullptr;
	uti::u64 ps_file_len = 0;
	if (!uti::file_load_all_lines(ps_path, &ptr_ps_file_buffer, &ps_file_len))
	{
		uti::log::err_out("[vis][load_shader_program] Failed to load pixel shader \"%s\".", ps_path);
		if (ptr_ps_file_buffer != nullptr)
		{
			delete[] ptr_ps_file_buffer;
			ptr_ps_file_buffer = nullptr;
		}
	}

	char* ptr_vs_file_buffer = nullptr;
	uti::u64 vs_file_len = 0;
	if (!uti::file_load_all_lines(vs_path, &ptr_vs_file_buffer, &vs_file_len))
	{
		uti::log::err_out("Failed to load vertex shader \"%s\".", vs_path);
		if (ptr_vs_file_buffer != nullptr)
		{
			delete[] ptr_vs_file_buffer;
			ptr_vs_file_buffer = nullptr;
		}
	}

	bool got_shader_errors = false;

	uti::u32 pixel_shader = u32_max;
	uti::u32 pixel_shader_errors_len = 0;
	if (!vis::create_compiled_pixel_shader(ptr_ps_file_buffer, &pixel_shader, &pixel_shader_errors_len))
	{
		char* pixel_shader_errors = new char[pixel_shader_errors_len];
		pixel_shader_errors[pixel_shader_errors_len - 1] = 0;
		vis::get_shader_errors(pixel_shader, pixel_shader_errors, pixel_shader_errors_len);
		uti::log::err_out("Error compiling pixel shader\r\n");
		uti::log::err_out(pixel_shader_errors);
		uti::log::err_out("\r\n");
		delete[] pixel_shader_errors;
		got_shader_errors = true;
	}

	uti::u32 vertex_shader = u32_max;
	uti::u32 vertex_shader_errors_len = 0;
	if (!vis::create_compiled_vertex_shader(ptr_vs_file_buffer, &vertex_shader, &vertex_shader_errors_len))
	{
		char* vertex_shader_errors = new char[vertex_shader_errors_len];
		vertex_shader_errors[vertex_shader_errors_len - 1] = 0;
		vis::get_shader_errors(vertex_shader, vertex_shader_errors, vertex_shader_errors_len);
		uti::log::err_out("Error compiling vertex shader\r\n");
		uti::log::err_out(vertex_shader_errors);
		uti::log::err_out("\r\n");
		delete[] vertex_shader_errors;
		got_shader_errors = true;
	}

	uti::u32 new_shader_program = u32_max;
	uti::u32 shader_ids[] = { pixel_shader, vertex_shader };
	uti::u32 shader_program_errors_len = 0;
	if (!vis::create_linked_shader_program(shader_ids, ARRAYSIZE(shader_ids), &new_shader_program, &shader_program_errors_len))
	{
		char* shader_program_errors = new char[shader_program_errors_len];
		shader_program_errors[shader_program_errors_len - 1] = 0;
		vis::get_shader_errors(new_shader_program, shader_program_errors, shader_program_errors_len);
		uti::log::err_out("Error linking shader\r\n");
		uti::log::err_out(shader_program_errors);
		uti::log::err_out("\r\n");
		delete[] shader_program_errors;
	}

	if (got_shader_errors)
	{
		vis::destroy_program(new_shader_program);
	}
	else
	{
		vis::destroy_program(*program_id);
		*program_id = new_shader_program;
	}

	vis::destroy_shader(pixel_shader);
	vis::destroy_shader(vertex_shader);

	if (ptr_ps_file_buffer != nullptr)
	{
		delete[] ptr_ps_file_buffer;
		ptr_ps_file_buffer = nullptr;
	}

	if (ptr_vs_file_buffer != nullptr)
	{
		delete[] ptr_vs_file_buffer;
		ptr_vs_file_buffer = nullptr;
	}

	return !got_shader_errors;
}
