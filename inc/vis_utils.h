#pragma once

#include "vis_def.h"

namespace vis
{
VIS_DEF void draw_grid(float grid_size, uti::u32 num_lines, uti::u32 num_minor_lines);
VIS_DEF void draw_axis(bool arrows = false);
VIS_DEF void draw_normal(uti::float4& normal, uti::float4& position, float scale = 0.25f/*, bool arrow = true*/);
VIS_DEF void draw_sphere(float radius, float max_azimuth_angle = 0.0f, float min_azimuth_angle = uti::mth::pi * 2.0f, float min_polar_angle = 0.0f, float max_polar_angle = uti::mth::pi);
VIS_DEF void draw_torus(float outer_radius, float tube_radius, float min_tube_angle = 0.0f, float max_tube_angle = uti::mth::pi*2.0f);
}
