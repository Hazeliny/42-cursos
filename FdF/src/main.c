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
	meta->frm.mlx = mlx_init();
	meta->frm.win = mlx_new_window(meta->frm.mlx, WINX, WINY, "FdF Linyao");
	meta->bitmap.img = mlx_new_image(meta->frm.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
			&meta->bitmap.bitpixel, &meta->bitmap.linesize, \
			&meta->bitmap.endian);
}

int	main(int ac, char **av)
{
	int			fd;
	t_metadata	meta;
	t_map		*map;

	if (ac == 2)
	{
		init_map(map, 1);
		fd = open(av[1], O_RDONLY);
		if (fd < 2)
			terminate(ERR_OPEN);
		map->memory = read_map(fd);
		close(fd);
		analyze_map(map);
		init_fdf(&meta);
		if (draw_map_win(&meta, FIT) < 0)
			terminate(ERR_MAP);
		mlx_hook(meta.frm.win, 2, 0, press_key, &meta);
		mlx_hook(meta.frm.win, 3, 0, release_key, &meta);
		mlx_hook(meta.frm.win, 4, 0, press_mouse, &meta);
		mlx_hook(meta.frm.win, 5, 0, release_mouse, &meta);
		mlx_hook(meta.frm.win, 6, 0, move_mouse, &meta);
		mlx_hook(meta.frm.win, 17, 0, exit_program, &meta);
		mlx_loop(meta.frm.mlx);
		free(meta.map.points);
		free(meta.map.memory);
	}
	else
		terminate(ERR_ARGV);
	return (0);
}
/*
    meta.frm.mlx = mlx_init();
    meta.frm.win = mlx_new_window(meta.frm.mlx, 1920, 1080, "FdF linyao");
    mlx_hook(meta.frm.win, 2, 1L<<0, close, &meta.frm);
    mlx_loop(meta.frm.mlx);
*/
/*
int close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}
*/
