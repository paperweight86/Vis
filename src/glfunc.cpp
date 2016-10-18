#include "types.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "..\..\Vis\gl\glext.h"

#include "..\gl\glfunc.h"

DEF_GL_FUNC_SIG(glGenVertexArrays);
DEF_GL_FUNC_SIG(glBindVertexArray);
DEF_GL_FUNC_SIG(glGenBuffers);
DEF_GL_FUNC_SIG(glBindBuffer);
DEF_GL_FUNC_SIG(glBufferData);
DEF_GL_FUNC_SIG(glEnableVertexAttribArray);
DEF_GL_FUNC_SIG(glVertexAttribPointer);
DEF_GL_FUNC_SIG(glDisableVertexAttribArray);
DEF_GL_FUNC_SIG(glCreateShader);
DEF_GL_FUNC_SIG(glShaderSource);
DEF_GL_FUNC_SIG(glCompileShader);
DEF_GL_FUNC_SIG(glGetShaderiv);
DEF_GL_FUNC_SIG(glGetShaderInfoLog);
DEF_GL_FUNC_SIG(glCreateProgram);
DEF_GL_FUNC_SIG(glAttachShader);
DEF_GL_FUNC_SIG(glLinkProgram);
DEF_GL_FUNC_SIG(glGetProgramiv);
DEF_GL_FUNC_SIG(glGetProgramInfoLog);
DEF_GL_FUNC_SIG(glDetachShader);
DEF_GL_FUNC_SIG(glDeleteShader);
DEF_GL_FUNC_SIG(glUseProgram);
DEF_GL_FUNC_SIG(glGetUniformLocation);
DEF_GL_FUNC_SIG(glUniformMatrix4fv);
DEF_GL_FUNC_SIG(glDeleteProgram);


void* vis::load_gl_func(const char *name, uti::ptr module)
{
	void* p = wglGetProcAddress(name);
	if (p == 0 ||
		(p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
		(p == (void*)-1))
	{
		p = (void*)GetProcAddress((HMODULE)module, name);
	}
	return p;
}

void vis::load_gl_functions(uti::ptr module)
{
	LOAD_GL_FUNC(glGenVertexArrays);
	LOAD_GL_FUNC(glBindVertexArray);
	LOAD_GL_FUNC(glGenBuffers);
	LOAD_GL_FUNC(glBindBuffer);
	LOAD_GL_FUNC(glBufferData);
	LOAD_GL_FUNC(glEnableVertexAttribArray);
	LOAD_GL_FUNC(glVertexAttribPointer);
	LOAD_GL_FUNC(glDisableVertexAttribArray);
	LOAD_GL_FUNC(glCreateShader);
	LOAD_GL_FUNC(glShaderSource);
	LOAD_GL_FUNC(glCompileShader);
	LOAD_GL_FUNC(glGetShaderiv);
	LOAD_GL_FUNC(glGetShaderInfoLog);
	LOAD_GL_FUNC(glCreateProgram);
	LOAD_GL_FUNC(glAttachShader);
	LOAD_GL_FUNC(glLinkProgram);
	LOAD_GL_FUNC(glGetProgramiv);
	LOAD_GL_FUNC(glGetProgramInfoLog);
	LOAD_GL_FUNC(glDetachShader);
	LOAD_GL_FUNC(glDeleteShader);
	LOAD_GL_FUNC(glUseProgram);
	LOAD_GL_FUNC(glGetUniformLocation);
	LOAD_GL_FUNC(glUniformMatrix4fv);
	LOAD_GL_FUNC(glDeleteProgram);
}