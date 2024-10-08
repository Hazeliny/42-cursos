/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:46:20 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 16:43:45 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parameters.h"
#include "../inc/map.h"
#include "../lib/libft/libft.h"

void	init_map_color(t_map *map)
{
	map->colors.menucolor = MENU_COLOR;
	map->colors.groundcolor = GROUND_COLOR;
	map->colors.backcolor = BACK_COLOR;
	map->colors.bottomcolor = BOTTOM_COLOR;
	map->colors.topcolor = TOP_COLOR;
}

void	init_map(t_map *map, int sign)
{
	if (sign) //sign为真1时，才初始化图形的边界和区域，为假0时不用再初始化边界和区域
	{
		map->area = 0;
		map->limits.axis[X] = 0;
		map->limits.axis[Y] = 0;
		map->limits.axis[Z] = 0;
		map->zmin = 0;
	}
	map->f_line = 1;
	map->f_dot = 0;
	map->f_extraline = 0;
	map->f_geo = 0;
	map->f_star = 0;
	map->f_shadow = 1;
	map->scale = 1;
	map->zdivisor = 1;
	map->range = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH; //表示当前点设在除菜单之外的窗口内的中心位置
	map->source.axis[Y] = WINY / 2;
	map->source.axis[Z] = 0;
	map->angle[X] = 0;
	map->angle[Y] = 0;
	map->angle[Z] = 0;
	init_map_color(map);
}

char	*read_map(int fd)
{
	static int	byte_read = BUFFER_READ;
	static int	sum_bytes = 0;
	char		*buffer;
	char		*tmp;
	char		*content;

	buffer = malloc(BUFFER_READ * sizeof(char));
	if (!buffer)
		terminate(ERR_MEMO);
	content = ft_strdup(""); //content是字符串变量，先初始化为空，不初始化会报错，注意这里用了malloc
	while (byte_read == BUFFER_READ)
	{
		ft_memset(buffer, 0, BUFFER_READ); //每次循环，先把buffer初始化为0
		byte_read = read(fd, buffer, BUFFER_READ);
		tmp = content; //先把content的旧内容放到临时变量tmp里
		content = ft_strjoin(content, buffer); //再把本次读到的BUFFER_READ这么多的新内容追加到content里的旧内容里去
		sum_bytes += byte_read; //累计前面已经读取的所有字符数
		free(tmp);
	}
	free(buffer);
	return (content);
}
