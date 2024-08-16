/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:32:51 by linyao            #+#    #+#             */
/*   Updated: 2024/08/16 22:32:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
//#include "../lib/minilibx-macos/mlx.h"
#include "../inc/parameters.h"
#include "../inc/map.h"
#include "../lib/libft/libft.h"
#include <math.h>

void	display_msg(t_metadata *meta, int key, int size, char *str)
{
	mlx_string_put(meta->frm.mlx, meta->frm.win, key, size, \
						TEXT_COLOR, str);
}

void	put_nbr(t_metadata *meta, int key, int size, int nbr)
{
	char	*s;

	s = ft_itoa(nbr);
	mlx_string_put(meta->frm.mlx, meta->frm.win, key, size, \
						NUMBER_COLOR, s);
}
