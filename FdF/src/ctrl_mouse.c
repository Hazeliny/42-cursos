/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:05:20 by linyao            #+#    #+#             */
/*   Updated: 2024/08/17 22:05:29 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include "../lib/libft/libft.h"

int	press_mouse(int button, int x, int y, void *para)
{
	t_metadata	*meta;

	meta = (t_metadata *)para;
	if (button == 1)
	{
		meta->ctrl.mouse_l = 1;
		meta->ctrl.click_l.axis[X] = x;
		meta->ctrl.click_l.axis[Y] = y;
	}
	if (button == 2)
	{
		meta->ctrl.mouse_r = 1;
		meta->ctrl.click_r.axis[X] = x;
		meta->ctrl.click_r.axis[Y] = y;
	}
	if (button == 4)
		meta->map.scale *= 1.5;
	if (button == 5)
	{
		if (meta->map.scale > 2)
			meta->map.scale /= 1.5;
	}
	draw_map_win(meta, FREE);
	return (0);
}

int	release_mouse(int button, int x, int y, void *para)
{
	t_metadata	*meta;

	meta = (t_metadata *)para;
	(void)x;
	(void)y;
	if (button == 1)
		meta->ctrl.mouse_l = 0;
	if (button == 2)
		meta->ctrl.mouse_r = 0;
	return (0);
}

int	move_mouse(int x, int y, void *para)
{
	t_metadata	*meta;

	meta = (t_metadata *)para;
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	if (meta->ctrl.mouse_l)
	{
		get_angle(&meta->map.angle[X], (int)meta->ctrl.click_l.axis[Y] - y);
		get_angle(&meta->map.angle[Y], (int)meta->ctrl.click_l.axis[X] - x);
		meta->ctrl.click_l.axis[X] = x;
		meta->ctrl.click_l.axis[Y] = y;
		draw_map_win(meta, FREE);
	}
	if (meta->ctrl.mouse_r)
	{
		meta->map.source.axis[X] -= ((int)meta->ctrl.click_r.axis[X] - x);
		meta->map.source.axis[Y] -= ((int)meta->ctrl.click_r.axis[Y] - y);
		meta->map.source.axis[Z] = 0;
		meta->ctrl.click_r.axis[X] = x;
		meta->ctrl.click_r.axis[Y] = y;
		draw_map_win(meta, FREE);
	}
	return (0);
}
