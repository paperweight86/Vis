#pragma once

#ifndef VIS_DEF
#ifdef VIS_LIB
#define VIS_DEF __declspec(dllexport)
#else
#define VIS_DEF __declspec(dllimport)
#endif
#endif
