/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:24:30 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 22:24:39 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

int	get_color(t_metadata *meta, int color)
{
	if (meta->bitmap.bitpixel != 32)
		color = mlx_get_color_value(meta->frm.mlx, color);
	return (color);
}
