/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:45:26 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 21:45:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	draw_bkg(t_metadata *meta, int backcolor, int menucolor)
{
	int	pos_pixel;
	int	axis[2];
	int	color;

	backcolor = get_color(meta, backcolor);
	menucolor = get_color(meta, menucolor);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY)
	{
		while (axis[X] < WINX)
		{
			if (axis[X] < MENU_WIDTH)
				color = menucolor;
			else
				color = backcolor;
			pos_pixel = (axis[Y] * meta->bitmap.linesize) + \
					(axis[X] * 4);
			set_color(&meta->bitmap.buffer[pos_pixel], \
				meta->bitmap.endian, color, 1);
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;
	}
}
