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
//if语句是检查位深度。bitpixel 表示每个像素的位数，也即图像的色深。通常，32位色深表示每个像素由红色、绿色、蓝色和透明度（alpha）四个通道组成，每个通道8位，总共32位
	if (meta->bitmap.bitpixel != 32) //如果bitpixel不是RGBA格式32位标准色深
		color = mlx_get_color_value(meta->frm.mlx, color);//MiniLibX库函数，用于将颜色值转换为与当前图像的色深兼容的格式,color需要转换的颜色值,该函数将color转换维适合当前图像位深度的格式
	return (color);
}

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1) //处理大端字节序，把高有效字节（MSB）存储在低地址处，低有效字节（LSB）存储在高地址处，颜色值的最高字节（红色通道）被存储在 buffer[1] 处，接着是绿色通道和蓝色通道
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;//高有效字节（MSB）的红色存储在低地址处
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = color & 0xFF;
	}
	else // 处理小端字节序，正好相反
	{
		buffer[0] = color & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

void	adjust_depth(t_point *p, float d, int area)// 缩放Z轴高度，调整深度效果或避免图形失真
{
	int	i;

	i = 0;
	while (i < area)
	{
		p[i].axis[Z] = p[i].axis[Z] / d;
		i++;
	}
}

void	flexion(t_point *p, int area, float range)
{
	int	i;
	float	curvature; // 弯曲度

	i = 0;
	while (i < area)//遍历所有点集，修改它们的z坐标，按比例（即x，y坐标的平方分别乘以range再相加得到该比例）
	{
		curvature = ((p[i].axis[X] * p[i].axis[X]) * range) + \
				((p[i].axis[Y] * p[i].axis[Y]) * range); //x轴和y轴的平方乘一个弯曲度比例因子range，两者相加
		p[i].axis[Z] -= curvature; //z坐标减去该比例，随X和Y坐标值的增加，Z 坐标会减少，形成向下或压缩的效果
		i++;
	}
}

//将点从极坐标系（Polar Coordinates）转换到笛卡尔坐标系（Cartesian Coordinates），并根据极坐标的经度（LONG）和纬度（LAT）重新计算每个点的X、Y和Z坐标
void	convert_polar_cartesian(t_map *map, t_point *p)
{
	int	i;

	i = 0;
	while (i < map->area)
	{
		p[i].axis[X] = (map->radius + p[i].axis[Z]) * \
		cos(p[i].polar[LONG]) * sin(p[i].polar[LAT]); //在给定纬度下，沿经度方向投影到 X 轴上的分量
		p[i].axis[Y] = (map->radius + p[i].axis[Z]) * \
		sin(p[i].polar[LONG]) * sin(p[i].polar[LAT]); //在给定纬度下，沿经度方向投影到 Y 轴上的分量
		p[i].axis[Z] = (map->radius + p[i].axis[Z]) * \
		cos(p[i].polar[LAT]); //沿 Z 轴的投影分量
		i++;
	}//以上操作是将球面或极坐标下点集转为三维空间中适合渲染的点集
}