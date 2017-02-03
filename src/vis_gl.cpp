#include "vis.h"

#include <assert.h>

#include "tat.h"
#include "gel.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <gl/GL.h>
#include "..\gl\glext.h"
#include "..\gl\glfunc.h"

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
		glAttachShader(*program_id, shader_ids[i]);
	glLinkProgram(*program_id);

	// Check
	GLint result = GL_FALSE;
	glGetProgramiv(*program_id, GL_LINK_STATUS,	   &result);
	glGetProgramiv(*program_id, GL_INFO_LOG_LENGTH, (GLint*)errors_length);

	for (uti::u32 i = 0; i < num_shader_ids; ++i)
		glDetachShader(*program_id, shader_ids[i]);

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

void vis::create_vertex_buffer(const float* elements, uti::u32 num_elements, uti::u32* vbuffer_id)
{
	glGenBuffers(1, vbuffer_id);
	glBindBuffer(GL_ARRAY_BUFFER, *vbuffer_id);
	glBufferData(GL_ARRAY_BUFFER, num_elements*sizeof(float), elements, GL_STATIC_DRAW);
}

void vis::create_index_buffer(const uti::u32* elements, uti::u32 num_elements, uti::u32* ibuffer_id)
{
	glGenBuffers(1, ibuffer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibuffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_elements*sizeof(uti::u32), elements, GL_STATIC_DRAW);
}
