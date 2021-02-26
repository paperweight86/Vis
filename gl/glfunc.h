#pragma once

#include "vis.h"

#define XMACRO_GL_FUNCTION(FUNCTIONNAME, RETURNTYPE, ...) typedef RETURNTYPE FUNCTIONNAME##_Signature(__VA_ARGS__); VIS_DEF extern FUNCTIONNAME##_Signature* FUNCTIONNAME;
#define LOAD_GL_FUNC(FUNCTIONNAME) FUNCTIONNAME = (FUNCTIONNAME##_Signature*)load_gl_func( #FUNCTIONNAME, module)

#include "glfunc_xmacro.h"

namespace vis
{
	VIS_DEF void* load_gl_func(const char *name, uti::ptr module);

	VIS_DEF void load_gl_functions(uti::ptr module);
}
