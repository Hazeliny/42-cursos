/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:32:51 by linyao            #+#    #+#             */
/*   Updated: 2024/08/16 22:32:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include "../lib/libft/libft.h"
#include <math.h>

int	get_round(double n)//四舍五入
{
	int	res;

	res = (int)n;
	if (n - res >= .5)
		res++;
	return (res);
}

void	display_msg(t_metadata *meta, int key, int size, char *str)//调用minilibX库函数显示信息
{
	mlx_string_put(meta->frm.mlx, meta->frm.win, key, size, \
						TEXT_COLOR, str);
}

void	put_nbr(t_metadata *meta, int key, int size, int nbr)//数字转字符，打印到窗口
{
	char	*s;

	s = ft_itoa(nbr);
	mlx_string_put(meta->frm.mlx, meta->frm.win, key, size, \
						NUMBER_COLOR, s);
	free(s);//别忘了释放内存
}

void	parallelize_view(t_map *map)//平行投影的视角
{
	map->f_geo = 0;
	map->angle[X] = 90;
	map->angle[Y] = 0;
	map->angle[Z] = 0;
	map->range = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
}

void	isometrize_view(t_map *map)//等距投影的视角
{
	map->f_geo = 0;
	map->angle[X] = 30;
	map->angle[Y] = 330;
	map->angle[Z] = 30;
	map->range = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
}