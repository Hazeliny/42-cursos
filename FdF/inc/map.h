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
int	gradual_blend(int pos, int step, int below_color, int upper_color);
void    draw_bkg(t_metadata *meta, int backcolor, int menucolor);
int     get_color(t_metadata *meta, int color);
void    set_color(char *buffer, int endian, int color, int alpha);
void    copy_map_projection(t_point * s, int area, t_point *d);
void    parse_transform_mapdata(t_metadata *meta, t_point *projection);
void    adjust_depth(t_point *p, float d, int area);
void    flexion(t_point *p, int area, float range);
void    convert_polar_cartesian(t_map *map, t_point *p);
void    rotate_x(float angle, int area, t_point *ori_p, t_point *res_p);
void    init_matrix(float matrix[3][3]);
t_point multiply_vector(t_point ori_p, float p_matrix[3][3]);
void    rotate_y(float angle, int area, t_point *ori_p, t_point *res_p);
void    rotate_z(float angle, int area, t_point *ori_p, t_point *res_p);
void    shadow(int area, t_point *p);
void    isome_project(int area, t_point *ori_p, t_point *res_p);
void    zoom(int area, int scale, t_point *projection);
void    translate(int area, t_point distance, t_point *p);
void    draw_map(t_metadata *meta, t_point *projection, int f);
void    make_dots(t_metadata *meta);
void    draw_dots(t_point dot, t_metadata *meta, int radius);
void    draw_circle_edge(t_metadata *meta, t_point pixel, \
					t_point dot, int coordinate);
void    put_pixel(t_metadata *meta, t_point pixel);
void    adapt_towin(t_metadata *meta, t_point *p);
int     limit(t_point *p, int area);
int     is_valid_pixel(t_point p);
int	draw_wire(t_metadata *meta, t_point begin, t_point terminus);
void    draw_wireframe(t_point  *p, t_metadata *meta, int density, int wire);
void    process_wireframe(t_metadata *meta, t_point *wire);
void    fill_with_dots(t_metadata *meta, t_point *projection);
void    draw_menu(t_metadata *meta);
void    draw_control_msg(t_metadata *meta);
void    draw_paint_info(t_metadata *meta);
void    draw_map_info(t_metadata *meta);
void    draw_color_theme(t_metadata *meta);
void    display_msg(t_metadata *meta, int key, int size, char *str);

#endif
