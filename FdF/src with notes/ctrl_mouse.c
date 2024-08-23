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
	if (button == 1)//鼠标左键
	{
		meta->ctrl.mouse_l = 1;
		meta->ctrl.click_l.axis[X] = x;
		meta->ctrl.click_l.axis[Y] = y;
	}
	if (button == 3)//鼠标右键
	{
		meta->ctrl.mouse_r = 1;
		meta->ctrl.click_r.axis[X] = x;
		meta->ctrl.click_r.axis[Y] = y;
	}
	if (button == 4)//鼠标中键向上滚动
		meta->map.scale *= 1.5;
	if (button == 5)//鼠标中键向下滚动
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
	else if (meta->ctrl.mouse_r)//鼠标右键控制拖动平移map图形
	{
		meta->map.source.axis[X] -= ((int)meta->ctrl.click_r.axis[X] - x);//计算本次按下鼠标右键坐标位置距离上次位置的差距，再加上map图形原来的中心位置坐标，得到拖动到当前位置的map图形的新的中心位置
		meta->map.source.axis[Y] -= ((int)meta->ctrl.click_r.axis[Y] - y);
		meta->map.source.axis[Z] = 0;
		meta->ctrl.click_r.axis[X] = x;
		meta->ctrl.click_r.axis[Y] = y;
		draw_map_win(meta, FREE);
	}
	return (0);
}
