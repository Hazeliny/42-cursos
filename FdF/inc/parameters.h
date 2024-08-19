/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:24:26 by linyao            #+#    #+#             */
/*   Updated: 2024/08/19 15:43:29 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_H
# define PARAMETERS_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WINX 1920
# define WINY 1080

# define X 0
# define Y 1
# define Z 2

# define LAT 0
# define LONG 1

# define RED		0xc1272d
# define GREEN		0x33cc55
# define FUCSIA		0xff255c
# define BLUE		0x1B8EFA
# define DEEPBLUE	0x0000FF
# define JAFFA		0xEF8633
# define CARBON		0x151515
# define WHITE		0xBBBBBB
# define DISCO		0x9A1F6A
# define BRICK_RED	0xC2294E
# define FLEMINGO	0xEC4B27
# define SAFFRON	0xF3AF3D

# define DEFAULT_COLOR	JAFFA
# define GROUND_COLOR	SAFFRON
# define BOTTOM_COLOR	BLUE
# define TOP_COLOR	BRICK_RED
# define MENU_COLOR     0x202020
# define BACK_COLOR     0x151515
# define TEXT_COLOR		0xEAEAEA
# define NUMBER_COLOR	0xF3AF3D

# define MENU_WIDTH	350
# define FIT_MARGIN	50

# define FIT		1
# define FREE		0

# define BUFFER_READ 5000

# define CONTROL_BOX			650
# define DRAWINFO_BOX			40
# define MAPINFO_BOX			280
# define COLORSCHEME_BOX		480
# define LINE_SIZE				30
# define MENU_TAB				30

typedef struct s_point
{
	int		color;
	int		hex_color;
	float	axis[3];
	float	polar[2];
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

# define DEF_COLOR	"\033[0;39m"
# define SH_GRAY	"\033[0;90m"
# define SH_RED		"\033[0;91m"
# define SH_GREEN	"\033[0;92m"
# define SH_YELLOW	"\033[0;93m"
# define SH_BLUE	"\033[0;94m"
# define SH_MAGENTA	"\033[0;95m"
# define SH_CYAN	"\033[0;96m"
# define SH_WHITE	"\033[0;97m"
# define SH_KNR		"\x1B[0m"
# define SH_KRED	"\x1B[31m"
# define SH_KGRN	"\x1B[32m"
# define SH_KYEL	"\x1B[33m"
# define SH_KBLU	"\x1B[34m"
# define SH_KMAG	"\x1B[35m"
# define SH_KCYN	"\x1B[36m"
# define SH_KWHT	"\x1B[37m"
# define U_ORANGE	"\033[48:5:208m"
# define U_WHITE	"\033[37;7:208m"
# define U_YELLOW	"\033[33;7:208m"
# define U_BLUE		"\033[34;7:208m"

#endif
