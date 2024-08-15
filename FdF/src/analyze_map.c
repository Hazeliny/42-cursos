/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:35:24 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 16:35:19 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parameters.h"
#include "../lib/libft/libft.h"
#include "../inc/map.h"
#include <math.h>

static void	get_mapsize(t_map *map)
{
	static int	i = -1;
	static int	elements = 0;

	while (map->memory[++i])
	{
		if (map->memory[i] == '\n' && map->memory[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->memory[i]) && (map->memory[i + 1] == ' ' || \
				map->memory[i + 1] == '\n' || map->memory[i + 1] == '\0'))
			elements++;
		if (map->memory[i] == '\n')
		{
			map->limits.axis[Y]++;
			if (map->limits.axis[X] != 0 && (map->limits.axis[X] != elements))
				terminate(ERR_LINE);
			else
				map->limits.axis[X] = elements;
			elements = 0;
		}
	}
	if (elements > 0 && (map->limits.axis[X] != elements))
		terminate(ERR_LINE);
	map->limits.axis[Y]++;
	map->area = map->limits.axis[X] * map->limits.axis[Y];
}

void	get_points(t_map *map)
{
	int			i;
	char		*tmp;
	char		*current;
	static int	n_points = 0;
	static int	n_line = 0;

	i = 0;
	tmp = NULL;
	current = map->memory;
	map->points = ft_calloc(map->area, sizeof(t_point));
	while (++i)
	{
		if (map->memory[i] == '\n' || map->memory[i] == '\0')
		{
			if (tmp != NULL)
				free(tmp);
			tmp = ft_substr(current, 0, &map->memory[i] - current);
			if (map->memory[i] == '\0')
				break ;
			current = &map->memory[i + 1];
			n_points += count_points(tmp, map, n_line++);
		}
	}
	if (tmp != NULL)
		free(tmp);
}

void	color_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->area)
	{
		distribute_colors(&map->points[i], map->colors, map->zmin, \
			(int)map->limits.axis[Z]);
		i++;
	}
}

void	convert_polar(t_map *map)
{
	int		i;
	float	variance_long;
	float	variance_lat;

	variance_long = (M_PI * 2) / (map->limits.axis[X] - 1);
	variance_lat = M_PI / (map->limits.axis[Y]);
	map->radius = map->limits.axis[X] / (M_PI * 2);
	i = 0;
	while (i < map->area)
	{
		map->points[i].polar[LONG] = -(map->points[i].axis[X]) * variance_long;
		if (map->points[i].axis[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2)) * variance_lat - 0.5 * variance_lat;
		else
			map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2) - 1) * variance_lat + 0.5 * variance_lat;
		i++;
	}
}

void	analyze_map(t_map *map)
{
	get_mapsize(map);
	get_points(map);
	color_map(map);
	convert_polar(map);
}
