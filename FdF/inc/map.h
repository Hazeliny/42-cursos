/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:00:59 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 15:58:25 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

void	init_map(t_map *map, int sign);
void	init_map_color(t_map *map);
char	*read_map(int fd);
void	analyze_map(t_map *map);
void	color_map(t_map *map);
int		is_point(char *s);
int		count_points(char *line, t_map *map, int n_line);
int		has_hexcolors(char *point);
void	distribute_colors(t_point *point, t_colors colors, int zmin, int zmax);
int		gradual_blend(int pos, int step, int below_color, int upper_color);
int		get_round(double n);
int		draw_map_win(t_metadata *meta, int f);
void	draw_bkg(t_metadata *meta, int backcolor, int menucolor);
int		get_color(t_metadata *meta, int color);
void	set_color(char *buffer, int endian, int color, int alpha);
void	copy_map_projection(t_point *s, int area, t_point *d);
void	parse_transform_mapdata(t_metadata *meta, t_point *projection);
void	adjust_depth(t_point *p, float d, int area);
void	flexion(t_point *p, int area, float range);
void	convert_polar_cartesian(t_map *map, t_point *p);
void	rotate_x(float angle, int area, t_point *ori_p, t_point *res_p);
void	init_matrix(float matrix[3][3]);
t_point	multiply_vector(t_point ori_p, float p_matrix[3][3]);
void	rotate_y(float angle, int area, t_point *ori_p, t_point *res_p);
void	rotate_z(float angle, int area, t_point *ori_p, t_point *res_p);
void	shadow(int area, t_point *p);
void	isome_project(int area, t_point *ori_p, t_point *res_p);
void	zoom(int area, int scale, t_point *projection);
void	translate(int area, t_point distance, t_point *p);
void	draw_map(t_metadata *meta, t_point *projection, int f);
void	make_dots(t_metadata *meta);
void	draw_dots(t_point dot, t_metadata *meta, int radius);
void	draw_circle_edge(t_metadata *meta, t_point pixel, \
					t_point dot, int coordinate);
int		put_pixel(t_metadata *meta, t_point pixel);
void	adapt_towin(t_metadata *meta, t_point *p);
int		limit(t_point *p, int area);
int		is_valid_pixel(t_point p);
int		draw_wire(t_metadata *meta, t_point bg, t_point tm);
void	draw_wireframe(t_point *p, t_metadata *meta, int density, int wire);
void	process_wireframe(t_metadata *meta, t_point *wire);
void	fill_with_dots(t_metadata *meta, t_point *projection);
void	draw_menu(t_metadata *meta);
void	draw_control_msg(t_metadata *meta);
void	draw_paint_info(t_metadata *meta);
void	draw_map_info(t_metadata *meta);
void	draw_color_theme(t_metadata *meta);
void	display_msg(t_metadata *meta, int key, int size, char *str);
void	put_nbr(t_metadata *meta, int key, int size, int nbr);
int		press_key(int key, void *para);
void	ctrl_angle(int key, t_metadata *meta);
void	get_angle(float *angle, float diff);
void	parallelize_view(t_map *map);
void	isometrize_view(t_map *map);
void	ctrl_colortheme(int key, t_map *map);
int		release_key(int key, void *para);
int		press_mouse(int button, int x, int y, void *para);
int		release_mouse(int button, int x, int y, void *para);
int		move_mouse(int x, int y, void *para);
int		exit_program(void *para);

#endif
