/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:27:18 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 15:41:35 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/keys.h"
#include "../inc/map.h"
#include "../lib/libft/libft.h"
#include <math.h>

void	get_angle(float *angle, float diff)
{
	*angle += diff;
	if (*angle < 0)
		*angle = 360 + *angle;
	if (*angle >= 360)
		*angle = *angle - 360;
}

void	ctrl_angle(int key, t_metadata *meta)
{
	int	angle;

	angle = 1;
	if (meta->ctrl.keyctrl)
		angle = 90;
	if (key == KEY_DOWN)
		get_angle(&meta->map.angle[X], angle);
	if (key == KEY_UP)
		get_angle(&meta->map.angle[X], -angle);
	if (key == KEY_LEFT)
		get_angle(&meta->map.angle[Y], angle);
	if (key == KEY_RIGHT)
		get_angle(&meta->map.angle[Y], -angle);
	if (key == KEY_Q)
		get_angle(&meta->map.angle[Z], angle);
	if (key == KEY_W)
		get_angle(&meta->map.angle[Z], -angle);
}

void	ctrl_colortheme(int key, t_map *map)
{
	map->colors.backcolor = CARBON;
	map->colors.bottomcolor = BLUE;
	map->colors.topcolor = BRICK_RED;
	map->colors.groundcolor = SAFFRON;
	if (key == KEY_2)
	{
		map->colors.backcolor = WHITE;
		map->colors.bottomcolor = CARBON;
		map->colors.topcolor = CARBON;
		map->colors.groundcolor = CARBON;
	}
	if (key == KEY_3)
	{
		map->colors.bottomcolor = WHITE;
		map->colors.topcolor = WHITE;
		map->colors.groundcolor = WHITE;
	}
	if (key == KEY_4)
	{
		map->colors.bottomcolor = DEEPBLUE;
		map->colors.topcolor = RED;
		map->colors.groundcolor = GREEN;
	}
	color_map(map);
}

int	exit_program(void *para)
{
	t_metadata	*meta;

	meta = (t_metadata *)para;
	mlx_destroy_window(meta->frm.mlx, meta->frm.win);
	free(meta->map.points);
	exit(0);
}
