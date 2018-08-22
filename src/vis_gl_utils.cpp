#include "types.h"

#include "vis_utils.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <gl/GL.h>
#include "..\gl\glext.h"
#include "..\gl\glfunc.h"

#include "tat.h"
#include "float4.h"

using namespace uti;

void vis::draw_grid(float grid_size, u32 num_lines, u32 num_minor_lines)
{
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	float cur = -grid_size / 2.0f;
	float inc = grid_size / num_lines;
	bool draw_minor = num_minor_lines > 0;
	float minor_inc = 0.0f;
	if (draw_minor)
		minor_inc = grid_size / num_minor_lines;
	for (u32 i = 0; i < num_lines; ++i)
	{
		glVertex3f(cur, 0.0f, -grid_size / 2.0f);
		glVertex3f(cur, 0.0f, grid_size / 2.0f);

		glVertex3f(-grid_size / 2.0f, 0.0f, cur);
		glVertex3f(grid_size / 2.0f, 0.0f, cur);

		cur += inc;
	}

	glEnd();

	glLineWidth(2.0f);

	glBegin(GL_LINES);

	if (draw_minor)
	{
		inc = grid_size / num_lines;
		minor_inc = inc / num_minor_lines;
		cur = minor_inc;
		float cur_maj = -grid_size / 2.0f;
		for (u32 i = 0; i < num_lines; ++i)
		{
			for (u32 j = 1; j < num_minor_lines; ++j)
			{
				glVertex3f(cur_maj + cur, 0.0f, -grid_size / 2.0f);
				glVertex3f(cur_maj + cur, 0.0f, grid_size / 2.0f);

				glVertex3f(-grid_size / 2.0f, 0.0f, cur_maj + cur);
				glVertex3f(grid_size / 2.0f, 0.0f, cur_maj + cur);

				cur += minor_inc;
			}
			cur = minor_inc;
			cur_maj += inc;
		}
	}

	glEnd();
}

void vis::draw_axis(bool arrows)
{
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();
	if (arrows)
	{
		float arrow_size = 0.1f;

		// X
		glBegin(GL_LINE_STRIP);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, arrow_size / 2.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, arrow_size / 2.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, -arrow_size / 2.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, -arrow_size / 2.0f);
		glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, arrow_size / 2.0f);
		glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, arrow_size / 2.0f);
		glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, -arrow_size / 2.0f);
		glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, -arrow_size / 2.0f);
		glEnd();

		//Y
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(arrow_size / 2.0f, 1.0f - arrow_size, arrow_size / 2.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-arrow_size / 2.0f, 1.0f - arrow_size, arrow_size / 2.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(arrow_size / 2.0f, 1.0f - arrow_size, -arrow_size / 2.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-arrow_size / 2.0f, 1.0f - arrow_size, -arrow_size / 2.0f);
		glVertex3f(-arrow_size / 2.0f, 1.0f - arrow_size, arrow_size / 2.0f);
		glVertex3f(arrow_size / 2.0f, 1.0f - arrow_size, arrow_size / 2.0f);
		glVertex3f(arrow_size / 2.0f, 1.0f - arrow_size, -arrow_size / 2.0f);
		glVertex3f(-arrow_size / 2.0f, 1.0f - arrow_size, -arrow_size / 2.0f);
		glEnd();

		//Z
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(arrow_size / 2.0f, arrow_size / 2.0f, 1.0f - arrow_size);
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-arrow_size / 2.0f, arrow_size / 2.0f, 1.0f - arrow_size);
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(arrow_size / 2.0f, -arrow_size / 2.0f, 1.0f - arrow_size);
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-arrow_size / 2.0f, -arrow_size / 2.0f, 1.0f - arrow_size);
		glVertex3f(-arrow_size / 2.0f, arrow_size / 2.0f, 1.0f - arrow_size);
		glVertex3f(arrow_size / 2.0f, arrow_size / 2.0f, 1.0f - arrow_size);
		glVertex3f(arrow_size / 2.0f, -arrow_size / 2.0f, 1.0f - arrow_size);
		glVertex3f(-arrow_size / 2.0f, -arrow_size / 2.0f, 1.0f - arrow_size);
		glEnd();
	}
}

void vis::draw_normal(uti::float4& normal, uti::float4& position, float scale /*= 0.25f, bool arrow = true*/)
{
	glLineWidth(5.0f);
	uti::float4 posPlusNorm = position + normal * scale;
	glBegin(GL_LINES);
	glVertex3f(uti::get_x(position),
			   uti::get_y(position),
			   uti::get_z(position));
	glVertex3f(uti::get_x(posPlusNorm),
			   uti::get_y(posPlusNorm),
			   uti::get_z(posPlusNorm));
	glEnd();
	//if (arrow)
	//{
	//	float arrow_size = 0.1f;

	//	glBegin(GL_LINE_STRIP);
	//	glVertex3f(	get_x(posPlusNorm),
	//				get_y(posPlusNorm),
	//				get_z(posPlusNorm));
	//	glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, arrow_size / 2.0f);
	//	glVertex3f(	get_x(posPlusNorm),
	//				get_y(posPlusNorm),
	//				get_z(posPlusNorm));
	//	glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, arrow_size / 2.0f);
	//	glVertex3f(	get_x(posPlusNorm),
	//				get_y(posPlusNorm),
	//				get_z(posPlusNorm));
	//	glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, -arrow_size / 2.0f);
	//	glVertex3f(	get_x(posPlusNorm),
	//				get_y(posPlusNorm),
	//				get_z(posPlusNorm));
	//	glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, -arrow_size / 2.0f);
	//	glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, arrow_size / 2.0f);
	//	glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, arrow_size / 2.0f);
	//	glVertex3f(1.0f - arrow_size, arrow_size / 2.0f, -arrow_size / 2.0f);
	//	glVertex3f(1.0f - arrow_size, -arrow_size / 2.0f, -arrow_size / 2.0f);
	//	glEnd();
	//}
}

void vis::draw_sphere(float radius, float max_azimuth_angle, float min_azimuth_angle, float min_polar_angle, float max_polar_angle)
{
	glDisable(GL_CULL_FACE);
	glBegin(GL_TRIANGLE_STRIP);

	const u32 num_azimuth_segments = 30;
	const u32 num_polar_segments = 10;

	float azimuth_angle_inc = (max_azimuth_angle - min_azimuth_angle) / (float)num_azimuth_segments;
	float azimuth_angle = min_azimuth_angle;

	float polar_angle_inc = (max_polar_angle - min_polar_angle) / (float)num_polar_segments;
	float polar_angle = min_polar_angle;

	for (u32 u = 0; u < num_azimuth_segments; ++u)
	{
		polar_angle = min_polar_angle;
		for (u32 v = 0; v < num_polar_segments; ++v)
		{
			float uf = azimuth_angle;
			float vf = polar_angle;

			float x = radius * cosf(uf) * sinf(vf);
			float y = radius * cos(vf);
			float z = radius * sinf(uf) * sinf(vf);

			glVertex3f(x, y, z);

			u32 un = u + 1;
			u32 vn = v + 1;

			if (un > num_azimuth_segments)
				un = 0;

			if (vn > num_polar_segments)
				vn = 0;

			uf = azimuth_angle + azimuth_angle_inc;
			vf = polar_angle;
			x = radius * cosf(uf) * sinf(vf);
			y = radius * cos(vf);
			z = radius * sinf(uf) * sinf(vf);

			glVertex3f(x, y, z);

			uf = azimuth_angle;
			vf = polar_angle + polar_angle_inc;
			x = radius * cosf(uf) * sinf(vf);
			y = radius * cos(vf);
			z = radius * sinf(uf) * sinf(vf);

			glVertex3f(x, y, z);

			uf = azimuth_angle + azimuth_angle_inc;
			vf = polar_angle + polar_angle_inc;
			x = radius * cosf(uf) * sinf(vf);
			y = radius * cos(vf);
			z = radius * sinf(uf) * sinf(vf);

			glVertex3f(x, y, z);

			polar_angle += polar_angle_inc;
		}
		azimuth_angle += azimuth_angle_inc;
	}

	glEnd();
	glEnable(GL_CULL_FACE);
}

void vis::draw_torus(float outer_radius, float tube_radius, float min_tube_angle, float max_tube_angle)
{
	glDisable(GL_CULL_FACE);
	glBegin(GL_TRIANGLE_STRIP);

	const u32 num_outer_segments = 30;
	const u32 num_tube_segments = 10;

	float tube_angle_inc = (max_tube_angle - min_tube_angle) / (float)num_tube_segments;

	float tube_angle = min_tube_angle;

	for (u32 u = 0; u < num_outer_segments; ++u)
	{
		tube_angle = min_tube_angle;
		for (u32 v = 0; v < num_tube_segments; ++v)
		{
			float uf = (float)u / (float)num_outer_segments*2.0f*uti::mth::pi;
			float vf = tube_angle;// (float)v / (float)num_tube_segments*2.0f*pi;

			float x = (outer_radius + tube_radius * cosf(vf)) * cosf(uf);
			float y = tube_radius * sinf(vf);
			float z = (outer_radius + tube_radius * cosf(vf)) * sinf(uf);

			glVertex3f(x, y, z);

			u32 un = u + 1;
			u32 vn = v + 1;

			if (un > num_outer_segments)
				un = 0;

			if (vn > num_tube_segments)
				vn = 0;

			uf = (float)un / (float)num_outer_segments*2.0f*uti::mth::pi;
			vf = tube_angle;//(float)v / (float)num_tube_segments*2.0f*pi;
			x = (outer_radius + tube_radius * cosf(vf)) * cosf(uf);
			y = tube_radius * sinf(vf);
			z = (outer_radius + tube_radius * cosf(vf)) * sinf(uf);

			glVertex3f(x, y, z);

			uf = (float)u / (float)num_outer_segments*2.0f*uti::mth::pi;
			vf = tube_angle + tube_angle_inc;// (float)vn / (float)num_tube_segments*2.0f*pi;
			x = (outer_radius + tube_radius * cosf(vf)) * cosf(uf);
			y = tube_radius * sinf(vf);
			z = (outer_radius + tube_radius * cosf(vf)) * sinf(uf);

			glVertex3f(x, y, z);

			uf = (float)un / (float)num_outer_segments*2.0f*uti::mth::pi;
			vf = tube_angle + tube_angle_inc;
			x = (outer_radius + tube_radius * cosf(vf)) * cosf(uf);
			y = tube_radius * sinf(vf);
			z = (outer_radius + tube_radius * cosf(vf)) * sinf(uf);

			glVertex3f(x, y, z);

			tube_angle += tube_angle_inc;
		}
	}

	glEnd();
	glEnable(GL_CULL_FACE);
}
