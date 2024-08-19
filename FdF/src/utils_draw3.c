/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:05:12 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 12:47:46 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <math.h>

void	rotate_x(float angle, int area, t_point *ori_p, t_point *res_p)
{
	int		i;
	float	radian;
	float	p_matrix[3][3];

	radian = angle * M_PI / 180;
	init_matrix(p_matrix);
	p_matrix[0][0] = 1;
	p_matrix[1][1] = cos(radian);
	p_matrix[1][2] = -sin(radian);
	p_matrix[2][1] = sin(radian);
	p_matrix[2][2] = cos(radian);
	i = 0;
	while (i < area)
	{
		res_p[i] = multiply_vector(ori_p[i], p_matrix);
		i++;
	}
}

void	rotate_y(float angle, int area, t_point *ori_p, t_point *res_p)
{
	int		i;
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
	int		i;
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

void	shadow(int area, t_point *p)
{
	int	i;

	i = 0;
	while (i < area)
	{
		if (p[i].axis[Z] < 0)
			p[i].paint = 0;
		else
			p[i].paint = 1;
		i++;
	}
}

void	isome_project(int area, t_point *ori_p, t_point *res_p)
{
	int		i;
	float	p_matrix[3][3];

	init_matrix(p_matrix);
	p_matrix[0][0] = 1;
	p_matrix[1][1] = 1;
	i = 0;
	while (i < area)
	{
		res_p[i] = multiply_vector(ori_p[i], p_matrix);
		i++;
	}
}
