/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:16:00 by linyao            #+#    #+#             */
/*   Updated: 2024/08/16 21:16:04 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	fill_with_dots(t_metadata *meta, t_point *projection)
{
	int	i;

	i = 0;
	while (i < meta->map.area)//遍历
	{
		if (projection[i].paint)//若map的圆点标志开启，则画圆点
			draw_dots(projection[i], meta, 1);
		i++;
	}
}

void	draw_control_msg(t_metadata *meta)
{
	int	size;

	size = CONTROL_BOX:
	display_msg(meta, MENU_TAB, size, "### CONTROL MSG ###");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Scroll: Zoom In/Out");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Left Click: Rotate X/Y axis");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Right Click: Move");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Arrows: Rotate X/Y axis");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Q/W: Rotate Z axis");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "+/-: Z Divisor");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "B/Ctr + B: Blending");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "P/I Parallel/Isometric Views");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "F/C Fit/Center");
	size += LINE_SIZE;
}

void	draw_paint_info(t_metadata *meta)
{
	int	size;

	size = DRAWINFO_BOX;
	display_msg(meta, MENU_TAB, size, "### PAINT INFO ###");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Reenders:");
	put_nbr(meta, MENU_TAB + 100, size, meta->map.renders);//将数字转成字符并显示到窗口
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Performance(ms):");
	put_nbr(meta, MENU_TAB + 170, size, meta->map.performance * 1000);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "X, Y, Z: [   ] [   ] [   ]");
	put_nbr(meta, MENU_TAB + 100, size, meta->map.angle[X]);
	put_nbr(meta, MENU_TAB + 160, size, meta->map.angle[Y]);
	put_nbr(meta, MENU_TAB + 220, size, meta->map.angle[Z]);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Zoom:");
	put_nbr(meta, MENU_TAB + 80, size, meta->map.scale);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Z Divisor:");
	put_nbr(meta, MENU_TAB + 110, size, meta->map.zdivisor);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Blending:");
	put_nbr(meta, MENU_TAB + 100, size, meta->map.range * 10000);
}

void	draw_map_info(t_metadata *meta)
{
	int	size;

	size = MAPINFO_BOX;
	display_msg(meta, MENU_TAB, size, "### MAP INFO ###");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "Size:");
	put_nbr(meta, MENU_TAB + 80, size, meta->map.area);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "AxisX Max:");
	put_nbr(meta, MENU_TAB + 80, size, meta->map.limits.axis[X]);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "AxisY Max:");
	put_nbr(meta, MENU_TAB + 80, size, meta->map.limits.axis[Y]);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "AxisZ Max:");
	put_nbr(meta, MENU_TAB + 80, size, meta->map.limits.axis[Z]);
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "AxisZ Min:");
	put_nbr(meta, MENU_TAB + 80, size, meta->map.limits.zmin);
	size += LINE_SIZE;
}

void	draw_color_theme(t_metadata *meta)//颜色主题
{
	int	size;

	size = COLORSCHEME_BOX;
	display_msg(meta, MENU_TAB, size, "### COLOR THEME ###");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "0: DEFAULT");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "1: TERRAIN");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "2: BLACK & WHITE");
	size += LINE_SIZE;
	display_msg(meta, MENU_TAB, size, "3: WHITE & BLACK");
	size += LINE_SIZE;
}
