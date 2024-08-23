/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:35:24 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 13:56:07 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parameters.h"
#include "../lib/libft/libft.h"
#include "../inc/map.h"
#include "../inc/handle_errors.h"
#include <math.h>

static void	get_mapsize(t_map *map)
{
	static int	i = -1;
	static int	elements = 0;

	while (map->memory[++i]) //循环逐字符分析memory的内容
	{
		if (map->memory[i] == '\n' && map->memory[i + 1] == '\0')//如字符是换行符，且下一个是结束符，就说明该字符串已处理完毕
			break ;
		if (ft_isalnum(map->memory[i]) && (map->memory[i + 1] == ' ' || \
				map->memory[i + 1] == '\n' || map->memory[i + 1] == '\0'))//如果是字符或数字，且后一个字符是空格，换行符或结束符，map的大小就计一个
			elements++; //记录的是map二维数组中一行中的元素个数
		if (map->memory[i] == '\n')
		{
			map->limits.axis[Y]++;//遇到事换行符map的边界limits的Y坐标就计一个，来到了下一行
			if (map->limits.axis[X] != 0 && (map->limits.axis[X] != elements))//如边界x坐标不是第一个且边界x坐标不等于计数的元素个数，说明这一行出错了，结束程序
				terminate(ERR_LINE);
			else
				map->limits.axis[X] = elements;//如不是，则正常，确保边界x坐标即是本行计数的元素个数
			elements = 0;
		}
	}
	if (elements > 0 && (map->limits.axis[X] != elements))//如元素个数不为0，且边界x坐标不等于元素个数，则出错，结束程序。
		terminate(ERR_LINE);
	map->limits.axis[Y]++;//最后Y坐标+1（因为它是从0开始计数的）
	map->area = map->limits.axis[X] * map->limits.axis[Y];//map的面积尺寸等于边界的x，y坐标相乘（即是map结构文件中二维数组全部元素个数）
}

static void	get_points(t_map *map)
{
	int			i;
	char		*tmp;
	char		*current;
	static int	n_points = 0;
	static int	n_line = 0;

	i = 0;
	tmp = NULL;
	current = map->memory;//先把map的memory（此时是map文件的全部内容）存放到变量current里
	map->points = ft_calloc(map->area, sizeof(t_point));
	while (++i)
	{
		if (map->memory[i] == '\n' || map->memory[i] == '\0')//逐行处理
		{
			if (tmp != NULL)
				free(tmp);
			tmp = ft_substr(current, 0, &map->memory[i] - current);//从memory中逐行substr出来放到tmp里（放的是每一行），current逐渐减少到最后一行
			if (map->memory[i] == '\0')
				break ;
			current = &map->memory[i + 1];
			n_points += count_points(tmp, map, n_line++);//点的个数用函数数出来累加
		}
	}
	if (tmp != NULL)
		free(tmp);
}

void	color_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->area)//在整个map的点中遍历，给每个点分配颜色
	{
		distribute_colors(&map->points[i], map->colors, map->zmin, \
			(int)map->limits.axis[Z]);
		i++;
	}
}

static void	convert_polar(t_map *map)//由笛卡尔坐标变换为极坐标
{
	int		i;
	float	variance_long;//经度差值
	float	variance_lat;//纬度差值

	variance_long = (M_PI * 2) / (map->limits.axis[X] - 1);
	variance_lat = M_PI / (map->limits.axis[Y]);
	map->radius = map->limits.axis[X] / (M_PI * 2);
	i = 0;
	while (i < map->area)
	{
		map->points[i].polar[LONG] = -(map->points[i].axis[X]) * variance_long;
		if (map->points[i].axis[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2)) * variance_lat - 0.5 * variance_lat;
		else
			map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2) - 1) * variance_lat + 0.5 * variance_lat;
		i++;
	}
}
//分析从文件读到的所有map数据
void	analyze_map(t_map *map)
{
	get_mapsize(map);
	get_points(map);
	color_map(map);
	convert_polar(map);
}
