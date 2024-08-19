/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:12:28 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 12:48:36 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	init_matrix(float matrix[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_point	multiply_vector(t_point ori_p, float p_matrix[3][3])
{
	int		i;
	int		j;
	t_point	res;

	res = ori_p;
	i = 0;
	while (i < 3)
	{
		res.axis[i] = 0;
		res.color = ori_p.color;
		j = 0;
		while (j < 3)
		{
			res.axis[i] += p_matrix[i][j] * ori_p.axis[j];
			j++;
		}
		i++;
	}
	return (res);
}

void	zoom(int area, int scale, t_point *projection)
{
	int	i;

	i = 0;
	while (i < area)
	{
		projection[i].axis[X] *= scale;
		projection[i].axis[Y] *= scale;
		projection[i].axis[Z] *= scale;
		i++;
	}
}

void	translate(int area, t_point distance, t_point *p)
{
	int	i;

	i = 0;
	while (i < area)
	{
		p[i].axis[X] += distance.axis[X];
		p[i].axis[Y] += distance.axis[Y];
		p[i].axis[Z] += distance.axis[Z];
		i++;
	}
}

void	adapt_towin(t_metadata *meta, t_point *p)
{
	meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	meta->map.source.axis[Y] = WINY / 2;
	meta->map.source.axis[Z] = 0;
	meta->map.scale = 1;
	copy_map_projection(meta->map.points, meta->map.area, p);
	parse_transform_mapdata(meta, p);
	while (!(limit(p, meta->map.area)))
	{
		copy_map_projection(meta->map.points, meta->map.area, p);
		parse_transform_mapdata(meta, p);
		meta->map.scale += 0.2;
	}
}
