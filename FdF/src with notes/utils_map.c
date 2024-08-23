/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:59:10 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 16:12:31 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/parameters.h"
#include "../inc/handle_errors.h"
#include "../inc/map.h"

int	is_point(char *s)
{
	int	flag;

	flag = 0;
	if (*s == '-' || *s == '+' || ft_isdigit(*s))
		flag++;
	s++;
	while (ft_isdigit(*s))
	{
		s++;
		flag++;
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}

int	count_points(char *line, t_map *map, int n_line)
{
	int			i;
	static int	index = 0;
	char		**split;

	i = 0;
	split = ft_split(line, ' ');//传入的tmp是map里的每行，用空格分隔split出来放到二维数组中，split的每行是map里每行的每个元素
	while (split[i] && split[i][0] != '\n')//逐行循环处理
	{
		if (!is_point(&split[i][0])) //判断是不是有效的点，格式检查
			terminate(ERR_EMPTY);
		map->points[index].axis[Z] = ft_atoi(&split[I][0]);//map的points按index存放split内容，split里每行第一个字符转成int，就是points的z坐标
		map->points[index].axis[X] = i - map->limits.axis[X] / 2;//第i个元素即split中第i行减边界x坐标的一半（中心化后）得到该points的x坐标
		map->points[index].axis[Y] = n_line - map->limits.axis[Y] / 2;//该点所在的第n_line行减边界y坐标的一半（中心化后）得到该points的y坐标
		map->points[index].paint = 1;
		map->points[index].color = DEFAULT_COLOR;
		map->points[index].hex_color = has_hexcolors(split[i]);//判断split每行是否有逗号分隔的数值，即十六进制颜色。返回赋值给该点的hex_color
		if (map->limits.axis[Z] < map->points[index].axis[Z])//如该点z坐标大于边界z坐标，把边界z坐标扩成该点z坐标，如该点z坐标小于边界最小z坐标，把边界最小z坐标设成该点z坐标
			map->limits.axis[Z] = map->points[index].axis[Z];
		if (map->zmin > map->points[index].axis[Z])
			map->zmin = map->points[index].axis[Z];
		i++;
		index++;
	}
	free_array(split);//split使用完毕，释放它
	return (i);
}

int	has_hexcolors(char *point)
{
	int		obtain_color;
	char	**color;

	if (ft_strchr(point, ',') != 0)//如有逗号，逗号前的数值就是颜色
	{
		color = ft_split(point, ',');
		obtain_color = strtol(color[1] + 2, NULL, 16);//跳过前两位（0x）取得16进制颜色，返回它
		free_array(color);
		return (obtain_color);
	}
	else
		return (0);
}

int	gradual_blend(int pos, int step, int below_color, int upper_color)
{
	int		res[3];
	int		result_color;
	double	augment[3];

	augment[0] = (double)((upper_color >> 16) - \
							(below_color >> 16)) / (double) step;//高位置红色的渐变色
	augment[1] = (double)(((upper_color >> 8) & 0xFF) - \
							((below_color >> 8) & 0xFF)) / (double) step;//高位置绿色的渐变色
	augment[2] = (double)((upper_color & 0xFF) - (below_color & 0xFF)) \
							/ (double) step;//高位置蓝色的渐变色
	res[0] = (below_color >> 16) + get_round(pos * augment[0]);//低位置红色加上四舍五入的渐变色量
	res[1] = ((below_color >> 8) & 0xFF) + get_round(pos * augment[1]);//低位置绿色加上四舍五入的渐变色量
	res[2] = (below_color & 0xFF) + get_round(pos * augment[2]);//低位置蓝色加上四舍五入的渐变色量
	result_color = (res[0] << 16) + (res[1] << 8) + res[2];//最后把红绿蓝组合为RGB格式的颜色返回它
	return (result_color);
}

void	distribute_colors(t_point *point, t_colors colors, int zmin, int zmax)
{
	point->paint = 1;
	point->color = DEFAULT_COLOR;
	if (point->hex_color > 0)//如该点hex颜色大于0，说明它有16进制颜色，把它设为它的color
	{
		point->color = point->hex_color;
		return ;
	}
	if (point->axis[Z] == zmin && zmin != 0)//如该点z坐标等于z的最小边界，且最小边界不为0，颜色设为底部色
		point->color = colors.bottomcolor;
	else if (point->axis[Z] == 0)////如该点z坐标等于0，颜色设为背景色
		point->color = colors.groundcolor;
	else if (point->axis[Z] == zmax)////如该点z坐标等于z的最大边界，颜色设为顶部色
		point->color = colors.topcolor;
	else if (point->axis[Z] > 0)////如该点z坐标大于0，颜色设为从背景到顶部的渐变色
		point->color = gradual_blend(point->axis[Z], zmax, colors.groundcolor, \
			colors.topcolor);
	else //否则，颜色设为从底部到背景的渐变色
		point->color = gradual_blend(-(zmin - point->axis[Z]), -zmin, \
			colors.bottomcolor, colors.groundcolor);
}
