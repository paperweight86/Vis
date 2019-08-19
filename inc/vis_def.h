#pragma once

#ifdef TAT_WINDOWS
#ifndef VIS_DEF
#ifdef VIS_LIB
#define VIS_DEF __declspec(dllexport)
#else
#define VIS_DEF __declspec(dllimport)
#endif // VIS_LIB
#endif // VIS_DEF
#else
#define VIS_DEF
#endif // TAT_WINDOWS
