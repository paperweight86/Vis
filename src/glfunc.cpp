#include "types.h"

#ifdef TAT_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif // TAT_WINDOWS

#include <GL/gl.h>

#ifdef TAT_WINDOWS
#include <GL/glu.h>
#else
#include <GL/glx.h> 
#include "dlfcn.h"
#endif // TAT_WINDOWS

#include "../gl/glext.h"
#include "../gl/glfunc.h"

// OpenGL 2
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
DEF_GL_FUNC_SIG(glUniform1i);
DEF_GL_FUNC_SIG(glUniform4fv);
DEF_GL_FUNC_SIG(glDeleteProgram);
//DEF_GL_FUNC_SIG(glActiveTexture);
DEF_GL_FUNC_SIG(glDeleteBuffers);

// OpenGL 3
DEF_GL_FUNC_SIG(glTexImage2DMultisample);
DEF_GL_FUNC_SIG(glGenFramebuffers);
DEF_GL_FUNC_SIG(glBindFramebuffer);
DEF_GL_FUNC_SIG(glFramebufferTexture2D);
DEF_GL_FUNC_SIG(glCheckFramebufferStatus);
DEF_GL_FUNC_SIG(glBlitFramebuffer);

// OpenGL 4
DEF_GL_FUNC_SIG(glGenerateMipmap);

void* vis::load_gl_func(const char *name, uti::ptr module)
{
	#ifdef TAT_WINDOWS
	void* p = wglGetProcAddress(name);
	#else
	void* p = (void*)glXGetProcAddress((GLubyte*)name);
	#endif
	if (p == 0 ||
		(p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
		(p == (void*)-1))
	{
		#ifdef TAT_WINDOWS
		p = (void*)GetProcAddress((HMODULE)module, name);
		#else
		p = dlsym((void*)module, name);
		#endif
	}
	return p;
}

void vis::load_gl_functions(uti::ptr module)
{
	//OpenGL 2
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
	LOAD_GL_FUNC(glUniform1i);
	LOAD_GL_FUNC(glUniform4fv);
	LOAD_GL_FUNC(glDeleteProgram);
	//LOAD_GL_FUNC(glActiveTexture);
	LOAD_GL_FUNC(glDeleteBuffers);

	// OpenGL 3
	LOAD_GL_FUNC(glTexImage2DMultisample);
	LOAD_GL_FUNC(glGenFramebuffers);
	LOAD_GL_FUNC(glBindFramebuffer);
	LOAD_GL_FUNC(glFramebufferTexture2D);
	LOAD_GL_FUNC(glCheckFramebufferStatus);
	LOAD_GL_FUNC(glBlitFramebuffer);

	// OpenGL 4
	LOAD_GL_FUNC(glGenerateMipmap);
}
