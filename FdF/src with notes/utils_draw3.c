/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:05:12 by linyao            #+#    #+#             */
/*   Updated: 2024/08/16 13:05:22 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	rotate_x(float angle, int area, t_point *ori_p, t_point *res_p)
{
	int	i;
	float	radian;
	float	p_matrix[3][3];

	radian = angle * M_PI / 180;//角度转为弧度
	init_matrix(p_matrix);//初始化3x3数组备用
	p_matrix[0][0] = 1; //设置x的旋转矩阵，数学公式
	p_matrix[1][1] = cos(radian);
	p_matrix[1][2] = -sin(radian);
	p_matrix[2][1] = sin(radian);
	p_matrix[2][2] = cos(radian);
	i = 0;
	while (i < area)//遍历把每个投影点
	{
		res_p[i] = multiply_vector(ori_p[i], p_matrix);//矢量运算转成旋转结果，把每个点的x,y,z轴值分别与旋转矩阵的每行每列相乘，得到运算结果
		i++;
	}
}

void	rotate_y(float angle, int area, t_point *ori_p, t_point *res_p)
{
	int	i;
	float	radian;
	float	p_matrix[3][3];

	radian = angle * M_PI / 180;
	init_matrix(p_matrix);
	p_matrix[0][0] = cos(radian);
	p_matrix[0][2] = sin(radian);
	p_matrix[1][1] = 1;
	p_matrix[2][0] = -sin(radian);
	p_matrix[2][2] = cos(radian);
	i = 0;
	while (i < area)
	{
		res_p[i] = multiply_vector(ori_p[i], p_matrix);
		i++;
	}
}

void	rotate_z(float angle, int area, t_point *ori_p, t_point *res_p)
{
	int	i;
	float	radian;
	float	p_matrix[3][3];

	radian = angle * M_PI / 180;
	init_matrix(p_matrix);
	p_matrix[0][0] = cos(radian);
	p_matrix[0][1] = -sin(radian);
	p_matrix[1][0] = sin(radian);
	p_matrix[1][1] = cos(radian);
	p_matrix[2][2] = 1;
	i = 0;
	while (i < area)
	{
		res_p[i] = multiply_vector(ori_p[i], p_matrix);
		i++;
	}
}

void	shadow(int area, t_point *p)//投阴影
{
	int	i;

	i = 0;
	while (i < area)//遍历所有点集
	{
		if (p[i].axis[Z] < 0)
			p[i].paint = 0;//点在z轴负值区域的，不投阴影
		else
			p[i].paint = 1;//点在z轴负值区域的，投阴影，用paint标志标记，以备后续调用mlx函数在窗口作画
		i++;
	}
}

void	isome_project(int area, t_point *ori_p, t_point *res_p)//等距投影即在三维空间中将三维物体沿着三条坐标轴以相等的角度（通常是120度）投影到二维平面上的方法，三个主轴（X、Y、Z轴）之间的角度相等（每个120度），各坐标轴的缩放比例相同，物体在三个主轴方向的长度在投影中是相等的，没有透视变形
{
	int	i;
	float	p_matrix[3][3];

	init_matrix(p_matrix);//初始化旋转矩阵备用
	p_matrix[0][0] = 1;
	p_matrix[1][1] = 1;
	i = 0;
	while (i < area)
	{
		res_p[i] = multiply_vector(ori_p[i], p_matrix);//矢量运算转成投影结果，把每个点的x,y,z轴值分别与旋转矩阵的每行每列相乘，得到运算结果
		i++;
	}
}
