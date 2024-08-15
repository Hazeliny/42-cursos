/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:24:26 by linyao            #+#    #+#             */
/*   Updated: 2024/08/15 17:06:51 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_H
# define PARAMETERS_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# define WINX 1920
# define WINY 1080

# define X 0
# define Y 1
# define Z 2

# define LAT 0
# define LONG 1

# define ROJO		0xc1272d
# define VERDE		0x33cc55
# define FUCSIA		0xff255c
# define AZUL		0x1B8EFA
# define SUPERAZUL	0x0000FF
# define JAFFA		0xEF8633

# define DEFAULT_COLOR	JAFFA
# define GROUND_COLOR	SAFFRON
# define BOTTOM_COLOR	AZUL
# define TOP_COLOR	BRICK_RED
# define MENU_COLOR     0x202020
# define BACK_COLOR     0x151515
# define TEXT_COLOR	0xEAEAEA
# define NUMBER_COLOR	0xF3AF3D

# define MENU_WIDTH	350
# define FIT_MARGIN	50

# define FIT		1
# define FREE		0

# define BUFFER_READ 5000

typedef struct s_point
{
	int		color;
	int		hex_color;
	float	axis[3];
	float	ordinate[2];
	bool	paint;
}		t_point;

typedef struct s_colors
{
	int	menucolor;
	int	groundcolor;
	int	backcolor;
	int	bottomcolor;
	int	topcolor;
}		t_colors;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_bitmap
{
	void	*img;
	int		bitpixel;
	int		linesize;
	int		endian;
	char	*buffer;
}		t_bitmap;

typedef struct s_map
{
	t_point		*points;
	t_point		limits;
	t_point		source;
	t_colors	colors;
	char		*memory;
	char		**lines;
	int			zmin;
	int			area;
	int			renders;
	double		perform;
	float		angle[3];
	float		zdivisor;
	float		scale;
	float		range;
	float		proportion;
	float		radius;
	bool		f_line;
	bool		f_dot;
	bool		f_extraline;
	bool		f_geo;
	bool		f_star;
	bool		f_shadow;
}		t_map;

typedef struct s_control
{
	bool	mouse_l;
	bool	mouse_r;
	bool	keyctrl;
	t_point	click_l;
	t_point	click_r;
}		t_control;

typedef struct s_metadata
{
	t_vars		frm;
	t_bitmap	bitmap;
	t_map		map;
	t_control	ctrl;
}		t_metadata;

#endif
