/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:59:10 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 16:42:21 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/parameters.h"
#include "../inc/handle_errors.h"
#include "../inc/map.h"

int	is_point(char *s)
{
	int	flag;

	flag = 0;
	if (*s == '-' || *s == '+' || ft_isdigit(*s))
		flag++;
	s++;
	while (ft_isdigit(*s))
	{
		s++;
		flag++;
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}

int	count_points(char *line, t_map *map, int n_line)
{
	int			i;
	static int	index = 0;
	char		**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] && split[i][0] != '\n')
	{
		if (!is_point(&split[i][0]))
			terminate(ERR_EMPTY);
		map->points[index].axis[Z] = ft_atoi(&split[i][0]);
		map->points[index].axis[X] = i - map->limits.axis[X] / 2;
		map->points[index].axis[Y] = n_line - map->limits.axis[Y] / 2;
		map->points[index].paint = 1;
		map->points[index].color = DEFAULT_COLOR;
		map->points[index].hex_color = has_hexcolors(split[i]);
		if (map->limits.axis[Z] < map->points[index].axis[Z])
			map->limits.axis[Z] = map->points[index].axis[Z];
		if (map->zmin > map->points[index].axis[Z])
			map->zmin = map->points[index].axis[Z];
		i++;
		index++;
	}
	free_array(split);
	return (i);
}

int	has_hexcolors(char *point)
{
	int		obtain_color;
	char	**color;

	if (ft_strchr(point, ',') != 0)
	{
		color = ft_split(point, ',');
		obtain_color = strtol(color[1] + 2, NULL, 16);
		free_array(color);
		return (obtain_color);
	}
	else
		return (0);
}

int	gradual_blend(int pos, int step, int below_color, int upper_color)
{
	int		res[3];
	int		result_color;
	double	augment[3];

	augment[0] = (double)((upper_color >> 16) - \
							(below_color >> 16)) / (double) step;
	augment[1] = (double)(((upper_color >> 8) & 0xFF) - \
							((below_color >> 8) & 0xFF)) / (double) step;
	augment[2] = (double)((upper_color & 0xFF) - (below_color & 0xFF)) \
							/ (double) step;
	res[0] = (below_color >> 16) + get_round(pos * augment[0]);
	res[1] = ((below_color >> 8) & 0xFF) + get_round(pos * augment[1]);
	res[2] = (below_color & 0xFF) + get_round(pos * augment[2]);
	result_color = (res[0] << 16) + (res[1] << 8) + res[2];
	return (result_color);
}

void	distribute_colors(t_point *point, t_colors colors, int zmin, int zmax)
{
	point->paint = 1;
	point->color = DEFAULT_COLOR;
	if (point->hex_color > 0)
	{
		point->color = point->hex_color;
		return ;
	}
	if (point->axis[Z] == zmin && zmin != 0)
		point->color = colors.bottomcolor;
	else if (point->axis[Z] == 0)
		point->color = colors.groundcolor;
	else if (point->axis[Z] == zmax)
		point->color = colors.topcolor;
	else if (point->axis[Z] > 0)
		point->color = gradual_blend(point->axis[Z], zmax, colors.groundcolor, \
			colors.topcolor);
	else
		point->color = gradual_blend(-(min - point->axis[Z]), -zmin, \
			colors.bottomcolor, colors.groundcolor);
}
