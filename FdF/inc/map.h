/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:00:59 by linyao            #+#    #+#             */
/*   Updated: 2024/08/14 15:37:26 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

void    init_map(t_map *map);
void    init_map_color(t_map *map);
char    *read_map(int fd);
void    analyze_map(t_map *map);

#endif
