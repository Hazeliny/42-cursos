/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:20:23 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 15:36:43 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/handle_errors.h"
#include "../inc/map.h"
#include <time.h>
#include <math.h>

int	put_pixel(t_metadata *meta, t_point pixel)
{
	int	alpha;
	int	pos_pixel;

	alpha = 0;
	if (pixel.axis[X] < MENU_WIDTH)
		alpha = -10;
	if (pixel.axis[X] >= WINX || pixel.axis[Y] >= WINY || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return (-1);
	pos_pixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);
	if (meta->bitmap.bitpixel != 32)
		pixel.color = mlx_get_color_value(meta->frm.mlx, pixel.color);
	set_color(&meta->bitmap.buffer[pos_pixel], meta->bitmap.endian, \
			pixel.color, alpha);
	return (0);
}

void	draw_circle_edge(t_metadata *meta, t_point pixel, \
				t_point dot, int coordinate)
{
	int	i;

	i = dot.axis[X];
	while (i <= dot.axis[X] + coordinate)
	{
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)dot.axis[Y] + coordinate;
		put_pixel(meta, pixel);
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)dot.axis[Y] - coordinate;
		put_pixel(meta, pixel);
		i++;
	}
}

void	draw_map(t_metadata *meta, t_point *projection, int f)
{
	if (meta->map.f_star)
		make_dots(meta);
	if (f)
		adapt_towin(meta, projection);
	if (meta->map.f_line)
		process_wireframe(meta, projection);
	if (meta->map.f_dot)
		fill_with_dots(meta, projection);
}

void	draw_menu(t_metadata *meta)
{
	draw_control_msg(meta);
	draw_paint_info(meta);
	draw_map_info(meta);
	draw_color_theme(meta);
}

int	draw_map_win(t_metadata *meta, int f)
{
	clock_t	t;
	t_point	*projection;

	t = clock();
	projection = malloc(sizeof(t_point) * meta->map.area);
	if (projection == NULL)
		terminate(ERR_MEMO);
	meta->map.renders += 1;
	draw_bkg(meta, meta->map.colors.backcolor, meta->map.colors.menucolor);
	copy_map_projection(meta->map.points, meta->map.area, projection);
	parse_transform_mapdata(meta, projection);
	draw_map(meta, projection, f);
	mlx_put_image_to_window(meta->frm.mlx, meta->frm.win, \
		meta->bitmap.img, 0, 0);
	draw_menu(meta);
	free(projection);
	t = clock() - t;
	meta->map.perform = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
