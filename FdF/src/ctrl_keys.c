/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:09:49 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 18:01:21 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/keys.h"
#include "../inc/map.h"
#include "../lib/libft/libft.h"
#include <math.h>

static void	ctrl_key1(int key, t_metadata *meta)
{
	if (key == KEY_ESC)
		exit_program(meta);
	if (key == KEY_R)
	{
		init_map(&meta->map, 0);
		meta->map.proportion = meta->map.limits.axis[Z] / \
					meta->map.limits.axis[X];
		if (meta->map.proportion > 0.5)
			meta->map.zdivisor = meta->map.proportion * 30;
		color_map(&meta->map);
		draw_map_win(meta, FIT);
	}
	if (key == KEY_C)
	{
		meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
		meta->map.source.axis[Y] = WINY / 2;
	}
	if (key == KEY_P)
	{
		parallelize_view(&meta->map);
		draw_map_win(meta, FIT);
	}
}

static void	ctrl_key2(int key, t_metadata *meta)
{
	if (key == KEY_D)
		meta->map.f_dot = !meta->map.f_dot;
	if (key == KEY_L)
		meta->map.f_line = !meta->map.f_line;
	if (key == KEY_X)
		meta->map.f_extraline = !meta->map.f_extraline;
	if (key == KEY_G)
		meta->map.f_geo = !meta->map.f_geo;
	if (key == KEY_S)
		meta->map.f_star = !meta->map.f_star;
	if (key == KEY_H)
		meta->map.f_shadow = !meta->map.f_shadow;
	if (key == KEY_F)
		draw_map_win(meta, FIT);
	if (key == KEY_CMD)
		meta->ctrl.keyctrl = 1;
}

static void	ctrl_key3(int key, t_metadata *meta)
{
	if (key == KEY_B)
	{
		if (meta->ctrl.keyctrl)
			meta->map.range -= 0.0001;
		else
			meta->map.range += 0.0001;
	}
	if (key == KEY_SUM || key == KEY_SUM2)
	{
		if (meta->ctrl.keyctrl)
			meta->map.scale *= 1.5;
		if (meta->map.zdivisor > 1)
			meta->map.zdivisor -= 10;
	}
	if (key == KEY_I)
	{
		isometrize_view(&meta->map);
		draw_map_win(meta, FIT);
	}
}

int	press_key(int key, void *para)
{
	t_metadata	*meta;

	ft_printf("%d Test\n", key);
	meta = (t_metadata *)para;
	ctrl_angle(key, meta);
	ctrl_key1(key, meta);
	ctrl_key2(key, meta);
	ctrl_key3(key, meta);
	if (key >= KEY_1 && key <= KEY_4)
		ctrl_colortheme(key, &meta->map);
	draw_map_win(meta, FREE);
	return (0);
}

int	release_key(int key, void *para)
{
	t_metadata	*meta;

	meta = (t_metadata *)para;
	if (key == KEY_CMD)
		meta->ctrl.keyctrl = 0;
	return (0);
}
