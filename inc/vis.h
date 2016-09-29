#pragma once

#include "types.h"

#ifdef VIS_LIB
#define VIS_DEF __declspec(dllexport)
#else
#define VIS_DEF __declspec(dllimport)
#endif

namespace vis
{
	struct renderer
	{
		uti::ptr hwnd;
		uti::ptr context;
	};

	VIS_DEF void initialise(renderer* renderer, uti::ptr hwnd);

	VIS_DEF void begin_frame(renderer* renderer);

	VIS_DEF void end_frame(renderer* renderer);

	VIS_DEF void shutdown(renderer* renderer);
}
