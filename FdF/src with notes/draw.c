/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:20:23 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 17:42:33 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include <time.h>
#include <math.h>

void	put_pixel(t_metadata *meta, t_point pixel)
{
	int	alpha;
	int	pos_pixel;

	alpha = 0;
	if (pixel.axis[X] < MENU_WIDTH)//像素x坐标在菜单宽度内时透明度设为-10，有透明效果
		alpha = -10;
	if (pixel.axis[X] >= WINX || pixel.axis[Y] >= WINY || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)//如像素超边界直接返回-1
		return (-1);
	pos_pixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);//算出像素的位置
	if (meta->bitmap.bitpixel != 32)//如不是32位色深
		pixel.color = mlx_get_color_value(meta->frm.mlx, pixel.color);//转换色深
	set_color(&meta->bitmap.buffer[pos_pixel], meta->bitmap.endian, \
			pixel.color, alpha);//把颜色写入缓冲区
	return (0);
}

void	draw_circle_edge(t_metadata *meta, t_point pixel, \
				t_point dot, int coordinate)
{
	int	i;

	i = dot.axis[X];
	while (i <= dot.axis[X] + coordinate)//当点的x坐标小于等于其xy坐标之和时
	{
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)dot.axis[Y] + coordinate;
		put_pixel(meta, pixel);//在像素缓冲区特定位置设color
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)dot.aixs[Y] - coordinate;
		put_pixel(meta, pixel);
		i++;
	}
}

void	draw_map(t_metadata *meta, t_point *projection, int f)
{
	if (meta->map.f_star)//若画星星的标志开启，则生成圆点
		make_dots(meta);
	if (f)//如标志为真，调整适配map到窗口中
		adapt_towin(meta, projection);
	if (meta->map.f_line)//若线条状态开启，则画线框
		process_wireframe(meta, projection);
	if (meta->map.f_dot)//若map的圆点标志开启，则填充圆点
		fill_with_dots(meta, projection);
}

void	draw_menu(t_metadata *meta)
{
	draw_control_msg(meta);//绘制控制信息
	draw_paint_info(meta);//显示绘图的信息
	draw_map_info(meta);//显示map的信息
	draw_color_theme(meta);//显示颜色模板
}

int	draw_map_win(t_metadata *meta, int f)//把map画到窗口
{
	clock_t	t;
	t_point	*projection; // 用于存储投影后的地图点 / Used to store projected map points

	t = clock(); //返回当前时间 / return current time
	projection = malloc(sizeof(t_point) * meta->map.area);
	if (projection == NULL)
		terminate(ERR_MEMO);
	meta->map.renders += 1; //记录地图已经渲染的次数 / Record the number of times the map has been rendered
	draw_bkg(meta, meta->map.colors.backcolor, meta->map.colors.menucolor); //生成背景图像，使用地图颜色中的背景色和菜单颜色填充背景 / Generate a background image, using the background color from the map and filling the background with the menu color
	copy_map_projection(meta->map.points, meta->map.area, projection); //将地图点复制到投影变量中，以便后续进行投影绘制 / Copy the map points into the projection variables for subsequent projection drawing
	parse_transform_mapdata(meta, projection); //解析地图数据并进行必要的投影变换，将实际三维点转换为可在屏幕上显示的二维投影点 / Parse the map data and perform the necessary projection transformations, converting the actual 3D points into 2D projection points that can be displayed on the screen
	draw_map(meta, projection, f); //根据投影后的点绘制地图，f变量用于调整图形适应性或缩放比例 / Draw the map based on the projected points. The variable f is used to adjust the graphic adaptability or scaling factor
	mlx_put_image_to_window(meta->frm.mlx, meta->frm.win, \
		meta->bitmap.img, 0, 0); //将生成的图像通过MiniLibX库函数显示到窗口中 / Display the generated image in the window using the MiniLibX library function
	draw_menu(meta); //绘制用户界面菜单 / Draw the user interface menu
	free(projection);//释放投影点
	t = clock() - t;//当前时间减之前获取的时间
	meta->map.perform = ((double)t) / CLOCKS_PER_SEC; //记录此渲染过程所需的时间，衡量程序性能 / Record the time required for this rendering process to measure program performance

	return (1);
}
