/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:30:23 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:30:25 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include <mlx.h>//include "mlx.h" 

enum				e_keys
{
	TAB = 48,
	SPACE = 49,
	SHIFT = 257,
	MOTION = 6,
	A = 0,
	S = 1,
	D = 2,
	Q = 12,
	W = 13,
	E = 14,
	R = 15,
	CROSS = 17,
	ONE = 18,
	TWO = 19,
	THREE = 20,
	FOUR = 21,
	FIVE = 23,
	SIX = 22,
	SEVEN = 26,
	EIGTH = 28,
	PLUS = 24,
	MINUS = 27,
	P = 35,
	ESC = 53,
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	PAGE_UP = 116,
	PAGE_DOWN = 121,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	RIGHT_ARROW = 124,
	LEFT_ARROW = 123
};

enum				e_colors
{
	YELLOW = 0xF5B201,
	CYAN = 0x3FB1B7,
	PINK = 0xFF0FFF,
	WHITE = 0xFFFFFF,
	RED = 0xCC0000,
	GREEN = 0x98FB98,
	BLUE = 0x0000FF,
	DARK_GREEN = 0x247812,
	BLACK = 0x000000
};

enum				e_fractols ///
{
	JULIA = 1,
	MANDEL = 2,
	SHIP = 3,
	TRICORN = 4,
	MANDELCUBED = 5
};

enum				e_display
{
	WDT = 1400,
	HGT = 800
};

enum				e_textures
{
	TEX_WDT = 64,
	TEX_HGT = 64
};

enum				e_errors
{
	MAP = 1,
	MLX = 2,
	WIN = 3,
	VALUE = 4,
	FILE = 5,
	MALLOC = 6,
	USAGE = 7,
	INPUT = 8,
	START = 9,
	FINISH = 10,
	TEXTURE = 11,
	IMG = 12,
	IMG_PTR = 13
};

enum				e_moves
{
	LEFT = 11,
	RIGHT = 12,
	UP = 13,
	DOWN = 14
};

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dot;

typedef struct		s_dataset
{
	/*
	**   window init
	*/
	void			*mlx;
	void			*win;
	void			*img;
	/*
	**   parser
	*/
	char			**worldmap;
	int				a;
	char			**tmp;
	char			*buff;
	int				ret;
	int				fd;
	int				l;
	int				line;
	int				cnt;
	int				row;
	int				amount;
	int				coof;
	t_dot			*dot;
	/*
	**   textures
	*/
	void			*ceil;
	void			*floor;
	void			*menu;
	void			*wep_left;
	void			*wep_right;
	int				*img_wall;
	int				*img_ceil;
	int				*img_floor;
	int				*img_wep_left;
	int				*img_wep_right;
	int				*img_menu;
	int				wall_sl;
	int				wall_end;
	int				wall_bpp;
	int				ceil_sl;
	int				ceil_end;
	int				ceil_bpp;
	int				ceil_w;
	int				ceil_h;
	int				floor_h;
	int				floor_w;
	int				floor_sl;
	int				floor_end;
	int				floor_bpp;
	int				menu_h;
	int				menu_w;
	int				menu_sl;
	int				menu_end;
	int				menu_bpp;
	int				wep_left_h;
	int				wep_left_w;
	int				wep_left_bpp;
	int				wep_left_sl;
	int				wep_left_end;
	int				wep_right_w;
	int				wep_right_h;
	int				wep_right_bpp;
	int				wep_right_sl;
	int				wep_right_end;
	/*
	**   world & DDA
	*/
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				x;
	int				y;
	int				w;
	int				d;
	int				h;
	int				color;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				ycolor;
	int				xcolor;
	double			movespeed;
	double			rotspeed;
	double			oldplanex;
	double			olddirx;
	/*
	**   controls
	*/
	int				control_up;
	int				control_down;
	int				control_left;
	int				control_right;
	/*
	**   color
	*/
	unsigned char	chan[3];



}					t_dataset;

void				init_level(t_dataset *ai);
void				init_color(t_dataset *ai);
t_dataset			*init_dataset(char *argv);
void				validate_level(t_dataset *ai);

void				sys_error(int error);
void				sys_message(int msg);
void				sys_free(t_dataset *ai);
int					sys_close(t_dataset *ai);

void				movement_up(t_dataset *ai);
void				movement_down(t_dataset *ai);
void				movement_left(t_dataset *ai);
void				movement_right(t_dataset *ai);

void				render_geometry(t_dataset *ai);
void				ray(t_dataset *ai);
void				drawstuff2(t_dataset *ai);
void				drawstuff3(t_dataset *ai);
void				visualization(t_dataset *ai);
unsigned int		colormagic(int i, double x, double y);
void				texturation(t_dataset *ai, int x);

void				display(t_dataset *ai);
void				rendering(t_dataset *ai);

int					key_hendler(int key, t_dataset *ai);
int					key_push(int key, t_dataset *ai);
int					key_pressed(int key, t_dataset *ai);
int					key_controllers(t_dataset *ai);

int					count_blocks(char *argv);
int					count_words(const char *s, char c);
int					parser(t_dataset *ai);


///
void				init_formula(t_dataset *ai);
void				init_julia(t_dataset *ai);
void				init_mandel(t_dataset *ai);
void				init_ship(t_dataset *ai);
void				init_main(t_dataset *ai);
int					controls_mouse(int mousekey, int x, int y, t_dataset *ai);
int					controls_buttons(int key, t_dataset *ai);
int					controls_arrows(int key, t_dataset *ai);
int					controls_numbers(int key, t_dataset *ai);
int					controls_keys(int key, t_dataset *ai);
void				formula_fractol(int c, t_dataset *ai);
void				formula_tricorn(t_dataset *ai);
void				formula_scale(int flag, int x, int y, t_dataset *ai);
int					formula_motion(int x, int y, t_dataset *ai);
void				algo_julia(t_dataset *ai);
void				algo_tricorn(t_dataset *ai);
void				algo_general(int flag, t_dataset *ai);
void				sys_validator(t_dataset *ai, char *input);
void				sys_error(int err);

void				sys_option(t_dataset *ai);
int					sys_close(t_dataset *ai);
void				render_display(t_dataset *ai);
void				render_interface(t_dataset *ai);
void				render_scene(t_dataset *ai);
void				render_color(int color, int x, int y, t_dataset *ai);
unsigned int		render_gradient(double x, double y, int i, t_dataset *ai);

 
#endif
