#pragma once

#include "vis.h"

#define DEF_GL_FUNC_SIG(FUNCTIONNAME, RETURNTYPE, ...) typedef RETURNTYPE FUNCTIONNAME##_Signature(__VA_ARGS__); VIS_DEF extern FUNCTIONNAME##_Signature* FUNCTIONNAME;
#define LOAD_GL_FUNC(FUNCTIONNAME) FUNCTIONNAME = (FUNCTIONNAME##_Signature*)load_gl_func( #FUNCTIONNAME, module)

// OpenGL2+
DEF_GL_FUNC_SIG(glGenVertexArrays, void, GLsizei n, GLuint *arrays);
DEF_GL_FUNC_SIG(glBindVertexArray, void, GLuint arr);
DEF_GL_FUNC_SIG(glGenBuffers, void, GLsizei n, GLuint * buffers);
DEF_GL_FUNC_SIG(glBindBuffer, void, GLenum target, GLuint buffer);
DEF_GL_FUNC_SIG(glBufferData, void, GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
DEF_GL_FUNC_SIG(glEnableVertexAttribArray, void, GLuint index);
DEF_GL_FUNC_SIG(glVertexAttribPointer, void, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
DEF_GL_FUNC_SIG(glDisableVertexAttribArray, void, GLuint index);
DEF_GL_FUNC_SIG(glCreateShader, GLuint, GLenum shaderType);
DEF_GL_FUNC_SIG(glShaderSource, void, GLuint shader, GLsizei count,	const GLchar** string, const GLint* length);
DEF_GL_FUNC_SIG(glCompileShader, void, GLuint shader);
DEF_GL_FUNC_SIG(glGetShaderiv, void, GLuint shader, GLenum pname, GLint* params);
DEF_GL_FUNC_SIG(glGetShaderInfoLog, void, GLuint shader, GLsizei maxLength,	GLsizei* length, GLchar* infoLog);
DEF_GL_FUNC_SIG(glCreateProgram, GLuint, void);
DEF_GL_FUNC_SIG(glAttachShader, void, GLuint program, GLuint shader);
DEF_GL_FUNC_SIG(glLinkProgram, void, GLuint program);
DEF_GL_FUNC_SIG(glGetProgramiv, void, GLuint program, GLenum pname,	GLint* params);
DEF_GL_FUNC_SIG(glGetProgramInfoLog, void, GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog);
DEF_GL_FUNC_SIG(glDetachShader, void, GLuint program, GLuint shader);
DEF_GL_FUNC_SIG(glDeleteShader, void, GLuint shader);
DEF_GL_FUNC_SIG(glUseProgram, void, GLuint program);
DEF_GL_FUNC_SIG(glGetUniformLocation, GLint, GLuint program, const GLchar* name);
DEF_GL_FUNC_SIG(glUniformMatrix4fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
DEF_GL_FUNC_SIG(glUniform1i, void, GLint location, GLint v0);
DEF_GL_FUNC_SIG(glDeleteProgram, void, GLuint  program);
DEF_GL_FUNC_SIG(glActiveTexture, void, GLenum texture);


// OpenGL3+
DEF_GL_FUNC_SIG(glTexImage2DMultisample, void, 
				GLenum target,
				GLsizei samples,
				GLint internalformat,
				GLsizei width,
				GLsizei height,
				GLboolean fixedsamplelocations);
DEF_GL_FUNC_SIG(glGenFramebuffers, void,
				GLsizei n,
				GLuint *ids);
DEF_GL_FUNC_SIG(glBindFramebuffer, void,
				GLenum target,
				GLuint framebuffer);
DEF_GL_FUNC_SIG(glFramebufferTexture2D, void, 
				GLenum target,
				GLenum attachment,
				GLenum textarget,
				GLuint texture,
				GLint level);
DEF_GL_FUNC_SIG(glCheckFramebufferStatus, GLenum, 
				GLenum target);
DEF_GL_FUNC_SIG(glBlitFramebuffer, void,
				GLint srcX0,
				GLint srcY0,
				GLint srcX1,
				GLint srcY1,
				GLint dstX0,
				GLint dstY0,
				GLint dstX1,
				GLint dstY1,
				GLbitfield mask,
				GLenum filter);




namespace vis
{
	VIS_DEF void* load_gl_func(const char *name, uti::ptr module);

	VIS_DEF void load_gl_functions(uti::ptr module);
}

#undef DEF_GL_FUNC_SIG
#define DEF_GL_FUNC_SIG(FUNCTIONNAME, ...) FUNCTIONNAME##_Signature* FUNCTIONNAME;
