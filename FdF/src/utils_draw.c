/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:45:26 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 21:45:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	draw_bkg(t_metadata *meta, int backcolor, int menucolor)
{
	int	pos_pixel;
	int	axis[2];
	int	color;

	backcolor = get_color(meta, backcolor);
	menucolor = get_color(meta, menucolor);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY)
	{
		while (axis[X] < WINX)
		{
			if (axis[X] < MENU_WIDTH)
				color = menucolor;
			else
				color = backcolor;
			pos_pixel = (axis[Y] * meta->bitmap.linesize) + \
					(axis[X] * 4);
			set_color(&meta->bitmap.buffer[pos_pixel], \
				meta->bitmap.endian, color, 1);
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;
	}
}

void	copy_map_projection(t_point * s, int area, t_point *d)
{
	int	i;

	i = 0;
	while (i < area)
	{
		d[i] = s[i];
		i++;
	}
}

void	parse_transform_mapdata(t_metadata *meta, t_point *projection)
{
	adjust_depth(projection, meta->map.zdivisor, meta->map.area);
	flexion(projection, meta->map.area, meta->map.range);
	if (meta->map.f_geo)
		convert_polar_cartesian(&meta->map, projection);
	rotate_x(meta->map.angle[X], meta->map.area, projection, projection);
	rotate_y(meta->map.angle[Y], meta->map.area, projection, projection);
	rotate_z(meta->map.angle[Z], meta->map.area, projection, projection);
	if (meta->map.f_geo && meta->map.f_shadow)
		shadow(meta->map.area, projection);
	isome_project(meta->map.area, projection, projection);
	zoom(meta->map.area, meta->map.scale, projection);
	translate(meta->map.area, meta->map.source, projection);
}

void	draw_dots(t_point dot, t_metadata *meta, int radius)
{
	int	axis[2];
	int	variation[2];
	int	radius_deviation;
	t_point	pixel;

	axis[X] = radius;
	axis[Y] = 0;
	variation[X] = 1 - (radius << 1);
	variation[Y] = 0;
	radius_deviation = 0;
	pixel.color = dot.color;
	while (axis[X] >= axis[Y])
	{
		draw_circle_edge(meta, pixel, dot, axis[Y]);
		draw_circle_edge(meta, pixel, dot, axis[X]);
		axis[Y]++;
		radius_deviation = += variation[Y];
		variation[Y] += 2;
		if (((radius_deviation << 1) + variation[X]) > 0)
		{
			axis[X]--;
			radius_deviation += variation[X];
			variation[X] += 2;
		}
	}
}

void	make_dots(t_metadata *meta)
{
	int	i;
	t_point	dot;
	int	border_x[2];
	int	border_y[2];

	if (meta->map.f_geo == 0)
		return ;
	border_x[0] = meta->map.source.axis[X] - (meta->map.radius * meta->map.scale);
	border_x[1] = meta->map.source.axis[X] + (meta->map.radius * meta->map.scale);
	border_y[0] = meta->map.source.axis[Y] - (meta->map.radius * meta->map.scale);
	border_x[1] = meta->map.source.axis[Y] + (meta->map.radius * meta->map.scale);
	i = 0;
	while (i < 200)
	{
		dot.axis[X] = rand() % WINX;
		dot.axis[Y] = rand() % WINY;
		dot.color = WHITE;
		if (dot.axis[X] < border_x[0] || dot.axis[X] > border_x[1] || \
			dot.axis[Y] < border_y[0] || dot.axis[Y] > border_y[1])
			draw_dots(dot, meta, 2);
		i++;
	}
}
