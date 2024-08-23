/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:51:33 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 17:18:05 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../inc/parameters.h"
#include "../inc/handle_errors.h"
#include "../inc/map.h"
//#include "../lib/minilibx-macos/mlx.h"

static void	init_fdf(t_metadata *meta)
{
	meta->map.renders = 0;
	meta->map.proportion = meta->map.limits.axis[Z] / meta->map.limits.axis[X];
	if (meta->map.proportion > 0.5)
		meta->map.zdivisor = meta->map.proportion * 30;
	meta->ctrl.keyctrl = 0;
	meta->ctrl.mouse_l = 0;
	meta->ctrl.mouse_r = 0;
	meta->frm.mlx = mlx_init();//初始化框架
	meta->frm.win = mlx_new_window(meta->frm.mlx, WINX, WINY, "FdF Linyao");//新建窗口
	meta->bitmap.img = mlx_new_image(meta->frm.mlx, WINX, WINY);//新建图像
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
			&meta->bitmap.bitpixel, &meta->bitmap.linesize, \
			&meta->bitmap.endian);//获取数据地址
}

int	main(int ac, char **av)
//int	main(void)
{
	int			fd;
	t_metadata	meta;
	t_map		*map;

	if (ac == 2)
	{
		init_map(map); //初始化map
		fd = open(av[1], O_RDONLY);
		if (fd < 2)
			terminate(ERR_OPEN);
		map->memory = read_map(fd); //一次性把文件内容读出来放进memory里。memory是一维字符串
		close(fd);
		analyze_map(map);
		init_fdf(&meta);//初始化meta元数据有关系统和窗口控制和mlx库的相关变量
		if (draw_map_win(&meta, FIT) < 0)//若返回负值，说明画图不成功，结束程序
			terminate(ERR_MAP);
		mlx_hook(meta.frm.win, 2, 1L << 0, press_key, &meta);//等待事件，按键
		mlx_hook(meta.frm.win, 3, 1L << 1, release_key, &meta);//释放键盘
		mlx_hook(meta.frm.win, 4, 1L << 2, press_mouse, &meta);//按下鼠标左键
		mlx_hook(meta.frm.win, 5, 1L << 3, release_mouse, &meta);//释放鼠标键
		mlx_hook(meta.frm.win, 6, 1L << 13, move_mouse, &meta);//按下鼠标右键
		mlx_hook(meta.frm.win, 17, 0, exit_program, &meta);//点击右上角的叉关闭窗口退出程序
		mlx_loop(meta.frm.mlx);
		free(meta.map.points);
		free(meta.map.memory);
	}
	else
		terminate(ERR_ARGV);
	return (0);
}
