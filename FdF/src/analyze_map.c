/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:35:24 by linyao            #+#    #+#             */
/*   Updated: 2024/08/14 18:00:42 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parameters.h"
#include "../lib/libft/libft.h"

static void	get_mapsize(t_map *map)
{
    int i = -1;
    int elements = 0;

    while (map->memory[++i])
	{
		if (map->memory[i] == '\n' && map->memory[i + 1] == '\0')
			break;
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

int	count_points(char *line, t_map *map, int n_line)
{
	int			i;
	static int	index = 0;		
	char		**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] && split[i][0] != '\n')
	{
		if(!is_point(&split[i][0]))
			terminate(ERR_EMPTY);
		map->points[index].axis[Z] = ft_atoi(&split[i][0]);
		map->points[index].axis[X] = i - map->limits.axis[X] / 2;
		map->points[index].axis[Y] = n_line - map->limits.axis[Y] / 2;
		map->points[index].paint = 1;
		map->points[index].color = DEFAULT_COLOR;
		map->points[index].hex_color = has_hexcolors(split[i]);
		if (map->limits.axis[Z] < map->points[index].axis[Z])
			map->limits.axis[Z] = map->points[index].axis[Z];
		if(map->zmin > map->points[index].axis[Z])
			map->zmin = map->points[index].axis[Z];
		i++;
		index++;
	}
	free_array(split);
	return (i);
}

void	get_points(t_map *map)
{
	int		i;
	char	*tmp;
	char	*current;
	int		n_points = 0;
	int		n_line = 0;

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
				break;
			current = &map->memory[i + 1];
			n_points += count_points(tmp, map, n_line++);
		}
	}
	if (tmp != NULL)
		free(tmp);
}

void	analyze_map(t_map *map)
{
	get_mapsize(map);
	get_points(map);
	color_map(map);
}

