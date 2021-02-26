// TODO: Autogenerate this file from https://raw.githubusercontent.com/BSVino/docs.gl/mainline/specs/gl.xml 

// OpenGL2+
XMACRO_GL_FUNCTION(glGenVertexArrays, void, GLsizei n, GLuint *arrays);
XMACRO_GL_FUNCTION(glBindVertexArray, void, GLuint arr);
XMACRO_GL_FUNCTION(glGenBuffers, void, GLsizei n, GLuint * buffers);
XMACRO_GL_FUNCTION(glBindBuffer, void, GLenum target, GLuint buffer);
XMACRO_GL_FUNCTION(glBufferData, void, GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
XMACRO_GL_FUNCTION(glEnableVertexAttribArray, void, GLuint index);
XMACRO_GL_FUNCTION(glVertexAttribPointer, void, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
XMACRO_GL_FUNCTION(glDisableVertexAttribArray, void, GLuint index);
XMACRO_GL_FUNCTION(glCreateShader, GLuint, GLenum shaderType);
XMACRO_GL_FUNCTION(glShaderSource, void, GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
XMACRO_GL_FUNCTION(glCompileShader, void, GLuint shader);
XMACRO_GL_FUNCTION(glGetShaderiv, void, GLuint shader, GLenum pname, GLint* params);
XMACRO_GL_FUNCTION(glGetShaderInfoLog, void, GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog);
XMACRO_GL_FUNCTION(glCreateProgram, GLuint, void);
XMACRO_GL_FUNCTION(glAttachShader, void, GLuint program, GLuint shader);
XMACRO_GL_FUNCTION(glLinkProgram, void, GLuint program);
XMACRO_GL_FUNCTION(glGetProgramiv, void, GLuint program, GLenum pname, GLint* params);
XMACRO_GL_FUNCTION(glGetProgramInfoLog, void, GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog);
XMACRO_GL_FUNCTION(glDetachShader, void, GLuint program, GLuint shader);
XMACRO_GL_FUNCTION(glDeleteShader, void, GLuint shader);
XMACRO_GL_FUNCTION(glUseProgram, void, GLuint program);
XMACRO_GL_FUNCTION(glGetUniformLocation, GLint, GLuint program, const GLchar* name);
XMACRO_GL_FUNCTION(glUniformMatrix4fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
XMACRO_GL_FUNCTION(glUniform1i, void, GLint location, GLint v0);
XMACRO_GL_FUNCTION(glUniform4fv, void, GLint location, GLsizei count, const GLfloat* value);
XMACRO_GL_FUNCTION(glDeleteProgram, void, GLuint  program);
XMACRO_GL_FUNCTION(glDeleteBuffers, void, GLsizei n, const GLuint* buffers);
XMACRO_GL_FUNCTION(glBlendEquation, void, GLenum mode);
XMACRO_GL_FUNCTION(glBlendFuncSeparate, void, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
XMACRO_GL_FUNCTION(glBindSampler, void, GLuint unit, GLuint sampler);
XMACRO_GL_FUNCTION(glActiveTexture, void, GLenum texture);
XMACRO_GL_FUNCTION(glBlendEquationSeparate, void, GLenum modeRGB, GLenum modeAlpha);
XMACRO_GL_FUNCTION(glGetAttribLocation, GLint, GLuint program, const GLchar* name);

// OpenGL3+
XMACRO_GL_FUNCTION(glTexImage2DMultisample, void, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
XMACRO_GL_FUNCTION(glGenFramebuffers, void, GLsizei n, GLuint *ids);
XMACRO_GL_FUNCTION(glBindFramebuffer, void, GLenum target, GLuint framebuffer);
XMACRO_GL_FUNCTION(glFramebufferTexture2D, void, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
XMACRO_GL_FUNCTION(glCheckFramebufferStatus, GLenum, GLenum target);
XMACRO_GL_FUNCTION(glBlitFramebuffer, void, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
XMACRO_GL_FUNCTION(glDrawElementsBaseVertex, void, GLenum mode,	GLsizei count, GLenum type,	GLvoid *indices, GLint basevertex);
XMACRO_GL_FUNCTION(glDeleteVertexArrays, void, GLsizei n, const GLuint *arrays);

// OpenGL4
XMACRO_GL_FUNCTION(glGenerateMipmap, void, GLenum target);