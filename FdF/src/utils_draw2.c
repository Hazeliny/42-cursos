/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:24:30 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 12:45:10 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

int	get_color(t_metadata *meta, int color)
{
	if (meta->bitmap.bitpixel != 32)
		color = mlx_get_color_value(meta->frm.mlx, color);
	return (color);
}

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = color & 0xFF;
	}
	else
	{
		buffer[0] = color & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

void	adjust_depth(t_point *p, float d, int area)
{
	int	i;

	i = 0;
	while (i < area)
	{
		p[i].axis[Z] = p[i].axis[Z] / d;
		i++;
	}
}

void	flexion(t_point *p, int area, float range)
{
	int		i;
	float	curvature;

	i = 0;
	while (i < area)
	{
		curvature = ((p[i].axis[X] * p[i].axis[X]) * range) + \
				((p[i].axis[Y] * p[i].axis[Y]) * range);
		p[i].axis[Z] -= curvature;
		i++;
	}
}

void	convert_polar_cartesian(t_map *map, t_point *p)
{
	int	i;

	i = 0;
	while (i < map->area)
	{
		p[i].axis[X] = (map->radius + p[i].axis[Z]) * \
		cos(p[i].polar[LONG]) * sin(p[i].polar[LAT]);
		p[i].axis[Y] = (map->radius + p[i].axis[Z]) * \
		sin(p[i].polar[LONG]) * sin(p[i].polar[LAT]);
		p[i].axis[Z] = (map->radius + p[i].axis[Z]) * \
		cos(p[i].polar[LAT]);
		i++;
	}
}
