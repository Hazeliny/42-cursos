/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:45:01 by linyao            #+#    #+#             */
/*   Updated: 2024/08/16 19:45:05 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

int	limit(t_point *p, int area)//检查map是否在当前窗口范围内显示
{
	int	i;

	i = 0;
	while (i < area)
	{
		if (p[i].axis[X] < (MENU_WIDTH + FIT_MARGIN) || \
			p[i].axis[X] > (WINX - FIT_MARGIN))
			return (1);
		if (p[i].axis[Y] < FIT_MARGIN || \
			p[i].axis[Y] > (WINY - FIT_MARGIN))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_pixel(t_point p)//在窗口范围内的才是有效的像素
{
	if (p.axis[X] < 0 || p.axis[X] > WINX)
		return (0);
	if (p.axis[Y] < 0 || p.axis[Y] > WINY)
		return (0);
	return (1);
}

int	draw_wire(t_metadata *meta, t_point begin, t_point terminus)
{
	int	length;
	int	distance;
	t_point	gap;//差值
	t_point	pixel;

	if (is_valid_pixel(begin) == 0 && is_valid_pixel(terminus) == 0)//判断是不是有效的像素
		return (0);
	gap.axis[X] = terminus.axis[X] - begin.axis[X];
	gap.axis[Y] = terminus.axis[Y] - begin.axis[Y];
	distance = sqrt((gap.axis[X] * gap.axis[X]) + \
			(gap.axis[Y] * gap.axis[Y]));//用勾股定理算出线的长度
	length = distance;
	gap.axis[X] /= distance;
	gap.axis[Y] /= distance;
	pixel.axis[X] = begin.axis[X];
	pixel.axis[Y] = begin.axis[Y];
	while (distance > 0)//如线长度大于0
	{
		pixel.color = gradual_blend(length - distance, length, begin.color, terminus.color);//阶梯渐变上色
		put_pixel(meta, pixel);//设置像素颜色
		pixel.axis[X] += gap.axis[X];
		pixel.axis[Y] += gap.axis[Y];
		distance --;
	}
	return (1);
}

void	draw_wireframe(t_point	*p, t_metadata *meta, int density, int wire)
{
	int	i;
	int	end_x;
	int	end_y;

	i = 0;
	while (i < (int)meta->map.limits.axis[X])//遍历当前行所有点
	{
		end_x = i + density;//计算当前点水平终点位置（据密度值）
		if (end_x >= (int)meta->map.limits.axis[X])
			end_x = (int)meta->map.limits.axis[X] - 1;//确保当前点水平终点位置不超过当前行最大索引
		end_y = i + (int)meta->map.limits.axis[X] * density;//计算当前点垂直终点位置（据密度值）
		if (p[i].paint)//当paint标志不为0时才画线框
		{
			draw_wire(meta, p[i], p[end_x]);//绘制当前点与水平终点的线
			if ((wire + density) < (int)meta->map.limits.axis[Y])//如密度范围内的行还在map范围内（y轴边界以内），则画出当前点与其垂直终点之间的线
				draw_wire(meta, p[i], p[end_y]);
		}
		i += density;
	}
}

void	process_wireframe(t_metadata *meta, t_point *wire)
{
	int	i;
	int	density;

	density = 8 / meta->map.scale;//设置线条的密度值
	if (density == 0)
		density = 1;
	i = 0;
	while (i < meta->map.area)//遍历整个点集。当map放大，密度值变小，线框更密集，反之相反
	{
		draw_wireframe(&wire[i], meta, density, i / meta->map.limits.axis[X]);
		i += meta->map.limits.axis[X] * density;
	}
}
