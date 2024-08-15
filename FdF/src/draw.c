/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:20:23 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 17:42:33 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <time.h>
#include <math.h>

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
