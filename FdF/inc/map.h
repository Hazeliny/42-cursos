/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:00:59 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 17:08:03 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

void	init_map(t_map *map);
void	init_map_color(t_map *map);
char	*read_map(int fd);
void	analyze_map(t_map *map);
int		is_point(char *s);
int		count_points(char *line, t_map *map, int n_line);
int		has_hexcolors(char *point);
void	distribute_colors(t_point *point, t_colors colors, int zmin, int zmax);
void	gradual_blend(int pos, int step, int below_color, int upper_color);
void    draw_bkg(t_metadata *meta, int backcolor, int menucolor);
int     get_color(t_metadata *meta, int color);

#endif
