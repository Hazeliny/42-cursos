/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:46:20 by linyao            #+#    #+#             */
/*   Updated: 2024/08/13 21:46:25 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parameters.h"
#include "../inc/map.h"
#include "../lib/libft/libft.h"

void    init_map_color(t_map *map)
{
	map->colors.menucolor = MENU_COLOR;
	map->colors.groundcolor = GROUND_COLOR;
	map->colors.backcolor = BACK_COLOR;
	map->colors.bottomcolor = BOTTOM_COLOR;
	map->colors.topcolor = TOP_COLOR;
}

void	init_map(t_map *map)
{
	map->length = 0;
	map->limits.axis[X] = 0;
	map->limits.axis[Y] = 0;
	map->limits.axis[Z] = 0;
	map->zmin = 0;
	map->f_line = 1;
	map->f_dot = 0;
	map->f_extraline = 0;
	map->f_geo = 0;
	map->f_star = 0;
	map->f_shadow = 1;
	map->scale = 1;
	map->zdivisor = 1;
	map->range = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
	map->source.axis[Z] = 0;
	map->angle[X] = 0;
	map->angle[Y] = 0;
	map->angle[Z] = 0;
	init_map_color(map);
}
