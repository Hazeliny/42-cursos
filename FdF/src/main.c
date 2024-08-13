/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:51:33 by linyao            #+#    #+#             */
/*   Updated: 2024/08/13 17:41:23 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../inc/parameters.h"
#include "../inc/handle_errors.h"



int	main(int ac, char **av)
{
	int			fd;
	t_metadata	meta;
	t_map		*map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 2)
			terminate(ERR_OPEN);
		init_map(map);
		map->memory = read_map(fd);
		close(fd);
	}
	else	
		terminate(ERR_ARGV);
	return (0);
}
