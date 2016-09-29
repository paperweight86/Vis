#include "vis.h"

#include <assert.h>

#include "tat.h"
#include "gel.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <gl/GL.h>

void vis::initialise(renderer* renderer, uti::ptr hwnd)
{
	assert(renderer != NULL);

	uti::ptr context = uti::gel::create_gl_context(hwnd);
	uti::gel::set_gl_context(hwnd, context);

	renderer->hwnd = hwnd;
	renderer->context = context;

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
}

void vis::begin_frame(renderer* renderer)
{
	assert(renderer != NULL);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void vis::end_frame(renderer* renderer)
{
	assert(renderer != NULL);

	uti::gel::swap_gl_buffers(renderer->hwnd);
}

void vis::shutdown(renderer* renderer)
{
	assert(renderer != NULL);

	uti::gel::destroy_gl_context(renderer->context);
}
