/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:45:26 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 21:45:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	draw_bkg(t_metadata *meta, int backcolor, int menucolor)
{
	int	pos_pixel;
	int	axis[2];
	int	color;

// 确保颜色值的格式与图像的色深兼容
	backcolor = get_color(meta, backcolor);
	menucolor = get_color(meta, menucolor);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY) //遍历每行每列
	{
		while (axis[X] < WINX)
		{
			if (axis[X] < MENU_WIDTH) //若x坐标在菜单宽度范围内设菜单色
				color = menucolor;
			else //若x坐标在菜单宽度范围外设背景色
				color = backcolor;
			pos_pixel = (axis[Y] * meta->bitmap.linesize) + \
					(axis[X] * 4); //计算当前像素在meta->bitmap.linesize中的偏移量,即该像素所在位置，每个像素占4个字节（RGBA），所以乘以4
			set_color(&meta->bitmap.buffer[pos_pixel], \
				meta->bitmap.endian, color, 1); // 设置meta->bitmap.buffer中指定位置像素的颜色，并考虑到endian字节序
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;//画背景，据给定的背景色和菜单色填充窗口，遍历每个像素，设置它们的颜色，使左侧menu_width显示为菜单颜色，其余显示为背景色
	}
}

void	copy_map_projection(t_point * s, int area, t_point *d)//把map的每个points copy到投影里
{
	int	i;

	i = 0;
	while (i < area)
	{
		d[i] = s[i];
		i++;
	}
}

// 执行几何变换和投影操作，处理t_point数组(代表三维空间中的点）并将其转换为二维投影坐标
void	parse_transform_mapdata(t_metadata *meta, t_point *projection)
{
	adjust_depth(projection, meta->map.zdivisor, meta->map.area); //把copy好的投影点的z轴按比例调整深度，缩放Z轴高度，调整深度效果或避免图形失真
	flexion(projection, meta->map.area, meta->map.range); //根据范围meta->map.range对点进行非线性变换，模拟鱼眼效果或其他的透视效果
	if (meta->map.f_geo)//如果地理空间geospatial的标志是开启状态
		convert_polar_cartesian(&meta->map, projection); //把极坐标转换成笛卡尔坐标，将projection中的点映射到球面上，实现球面投影或其他球形效果
	rotate_x(meta->map.angle[X], meta->map.area, projection, projection); //绕X轴旋转，调整图像俯仰角度
	rotate_y(meta->map.angle[Y], meta->map.area, projection, projection); //绕Y轴旋转，调整图像偏航角度
	rotate_z(meta->map.angle[Z], meta->map.area, projection, projection); //绕Z轴旋转，调整图像滚动角度
	if (meta->map.f_geo && meta->map.f_shadow)//如果地理空间geospatial的标志和阴影标志都是开启状态
		shadow(meta->map.area, projection); //添加阴影效果，增强视觉深度或立体感
	isome_project(meta->map.area, projection, projection); //将三维坐标等距投影到二维平面上，去除透视效果
	zoom(meta->map.area, meta->map.scale, projection); //调整图像大小
	translate(meta->map.area, meta->map.source, projection); //将图像移动到指定的显示区域内
}

void	draw_dots(t_point dot, t_metadata *meta, int radius)//以下是Bresenham圆绘制算法
{
	int	axis[2];
	int	variation[2];//差值
	int	radius_deviation;//半径误差
	t_point	pixel;

	axis[X] = radius;
	axis[Y] = 0;
	variation[X] = 1 - (radius << 1);
	variation[Y] = 0;
	radius_deviation = 0;
	pixel.color = dot.color;
	while (axis[X] >= axis[Y])//在x坐标大于y坐标时，循环绘制圆的8个对称点中的一部分
	{
		draw_circle_edge(meta, pixel, dot, axis[Y]);//两次调用该函数，画出当前步长下两个对称的圆点
		draw_circle_edge(meta, pixel, dot, axis[X]);
		axis[Y]++;
		radius_deviation = += variation[Y];//半径误差累加差值
		variation[Y] += 2;//差值按2递增
		if (((radius_deviation << 1) + variation[X]) > 0)//当误差大于一定值时调整X轴坐标，减一让圆不变形
		{
			axis[X]--;
			radius_deviation += variation[X];
			variation[X] += 2;
		}
	}
}

void	make_dots(t_metadata *meta)
{
	int	i;
	t_point	dot;
	int	border_x[2];
	int	border_y[2];

	if (meta->map.f_geo == 0)//若图形的地理空间geospatial标志是关闭状态，则不画圆点
		return ;
//当图形成为球体时，才进行如下操作画圆点
	border_x[0] = meta->map.source.axis[X] - (meta->map.radius * meta->map.scale);//定义边界，在图形外面和窗口以内画圆点
	border_x[1] = meta->map.source.axis[X] + (meta->map.radius * meta->map.scale);
	border_y[0] = meta->map.source.axis[Y] - (meta->map.radius * meta->map.scale);
	border_x[1] = meta->map.source.axis[Y] + (meta->map.radius * meta->map.scale);
	i = 0;
	while (i < 200)
	{
		dot.axis[X] = rand() % WINX;//用rand函数在窗口范围内随机产生圆点的xy坐标
		dot.axis[Y] = rand() % WINY;
		dot.color = WHITE;
		if (dot.axis[X] < border_x[0] || dot.axis[X] > border_x[1] || \
			dot.axis[Y] < border_y[0] || dot.axis[Y] > border_y[1])//在球形图形的边界以外窗口以内才画圆点
			draw_dots(dot, meta, 2);
		i++;
	}
}