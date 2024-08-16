/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:45:01 by linyao            #+#    #+#             */
/*   Updated: 2024/08/16 19:45:05 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

int	limit(t_point *p, int area)
{
	int	i;

	i = 0;
	while (i < area)
	{
		if (p[i].axis[X] < (MENU_WIDTH + FIT_MARGIN) || \
			p[i].axis[X] > (WINX - FIT_MARGIN))
			return (1);
		if (p[i].axis[Y] < FIT_MARGIN || \
			p[i].axis[Y] > (WINY - FIT_MARGIN))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_pixel(t_point p)
{
	if (p.axis[X] < 0 || p.axis[X] > WINX)
		return (0);
	if (p.axis[Y] < 0 || p.axis[Y] > WINY)
		return (0);
	return (1);
}

int	draw_wire(t_metadata *meta, t_point begin, t_point terminus)
{
	int	length;
	int	distance;
	t_point	gap;
	t_point	pixel;

	if (is_valid_pixel(begin) == 0 && is_valid_pixel(terminus) == 0)
		return (0);
	gap.axis[X] = terminus.axis[X] - begin.axis[X];
	gap.axis[Y] = terminus.axis[Y] - begin.axis[Y];
	distance = sqrt((gap.axis[X] * gap.axis[X]) + \
			(gap.axis[Y] * gap.axis[Y]));
	length = distance;
	gap.axis[X] /= distance;
	gap.axis[Y] /= distance;
	pixel.axis[X] = begin.axis[X];
	pixel.axis[Y] = begin.axis[Y];
	while (distance > 0)
	{
		pixel.color = gradual_blend(length - distance, length, begin.color, terminus.color);
		put_pixel(meta, pixel);
		pixel.axis[X] += gap.axis[X];
		pixel.axis[Y] += gap.axis[Y];
		distance --;
	}
	return (1);
}

void	draw_wireframe(t_point	*p, t_metadata *meta, int density, int wire)
{
	int	i;
	int	end_x;
	int	end_y;

	i = 0;
	while (i < (int)meta->map.limits.axis[X])
	{
		end_x = i + density;
		if (end_x >= (int)meta->map.limits.axis[X])
			end_x = (int)meta->map.limits.axis[X] - 1;
		end_y = i + (int)meta->map.limits.axis[X] * density;
		if (p[i].paint)
		{
			draw_wire(meta, p[i], p[end_x]);
			if ((wire + density) < (int)meta->map.limits.axis[Y])
				draw_wire(meta, p[i], p[end_y]);
		}
		i += density;
	}
}

void	process_wireframe(t_metadata *meta, t_point *wire)
{
	int	i;
	int	density;

	density = 8 / meta->map.scale;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < meta->map.area)
	{
		draw_wireframe(&wire[i], meta, density, i / meta->map.limits.axis[X]);
		i += meta->map.limits.axis[X] * density;
	}
}
