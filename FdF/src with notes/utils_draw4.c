/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:12:28 by linyao            #+#    #+#             */
/*   Updated: 2024/08/16 14:12:32 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	init_matrix(float matrix[3][3])//初始化用于矢量运算的二维数组
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_point	multiply_vector(t_point ori_p, float p_matrix[3][3])//乘积矢量运算转换坐标（比如旋转等）
{
	int	i;
	int	j;
	t_point	res;

	res = ori_p;
	i = 0;
	while (i < 3)
	{
		res.axis[i] = 0;
		res.color = ori_p.color;
		j = 0;
		while (j < 3)
		{
			res.axis[i] += p_matrix[i][j] * ori_p.axis[j];
			j++;
		}
		i++;
	}
	return (res);
}

void	zoom(int area, int scale, t_point *projection)
{
	int	i;

	i = 0;
	while (i < area)//遍历整个点集，按每个点的scale比例乘以该点的xyz坐标
	{
		projection[i].axis[X] *= scale;
		projection[i].axis[Y] *= scale;
		projection[i].axis[Z] *= scale;
		i++; 
	}
}

void	translate(int area, t_point distance, t_point *p)
{
	int	i;

	i = 0;
	while (i < area)//平移所有点到指定区域，与鼠标右键控制的平移功能不同
	{
		p[i].axis[X] += distance.axis[X];
		p[i].axis[Y] += distance.axis[Y];
		p[i].axis[Z] += distance.axis[Z];
		i++;
	}
}

void	adapt_towin(t_metadata *meta, t_point *p)
{
	meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;//图形中心化
	meta->map.source.axis[Y] = WINY / 2;
	meta->map.source.axis[Z] = 0;
	meta->map.scale = 1;
	copy_map_projection(meta->map.points, meta->map.area, p);//复制投影点
	parse_transform_mapdata(meta, p);//调色深，弯曲，转换坐标为笛卡尔坐标，旋转xyz轴，投阴影，等距投影，平移等
	while (!(limit(p, meta->map.area)))//用limit函数检查map是否在当前窗口，若不在此范围，则循环重复上面复制，调色深等操作，直到map适配窗口为止
	{
		copy_map_projection(meta->map.points, meta->map.area, p);
		parse_transform_mapdata(meta, p);
		meta->map.scale += 0.2;
	}
}
