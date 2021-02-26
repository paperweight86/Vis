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

// Define a signature type for each function
#undef XMACRO_GL_FUNCTION
#define XMACRO_GL_FUNCTION(FUNCTIONNAME, ...) FUNCTIONNAME##_Signature* FUNCTIONNAME;
#include "glfunc_xmacro.h" 

// Load each function
#undef XMACRO_GL_FUNCTION
#define XMACRO_GL_FUNCTION(FUNCTIONNAME, ...) LOAD_GL_FUNC( FUNCTIONNAME );

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
	#include "glfunc_xmacro.h" 
}
