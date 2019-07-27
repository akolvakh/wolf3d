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
# include "mlx.h"

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
	BLACK = 0x000000,
	CLR = 0xe8e5c3
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
	IMG_PTR = 13,
	PLAYER = 14
};

enum				e_moves
{
	LEFT = 11,
	RIGHT = 12,
	UP = 13,
	DOWN = 14
};

typedef	struct		s_texture
{
	void			*img;
	int				*img_ptr;
	int				bpp;
	int				sl;
	int				ending;
}					t_texture;

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
	void			*menu;
	void			*wep_left;
	void			*wep_right;
	int				*img_wall;
	int				*img_wep_left;
	int				*img_wep_right;
	int				*img_menu;
	void			*start_img;
	int				*start_ptr;
	void			*skybox;
	int				*imgsky;

	int				sky_sl;
	int				sky_bpp;
	int				sky_end;
	int				sky_w;
	int				sky_h;


	int				wall_sl;
	int				wall_end;
	int				wall_bpp;

	int				start_img_sl;
	int				start_img_bpp;
	int				start_img_ending;
	int				start_img_w;
	int				start_img_h;

	void			*tx0;
	int				*img_tx0;
	int				tx0_sl;
	int				tx0_end;
	int				tx0_bpp;
	int				tx0_w;
	int				tx0_h;

	void			*tx1;
	int				*img_tx1;
	int				tx1_sl;
	int				tx1_end;
	int				tx1_bpp;
	int				tx1_w;
	int				tx1_h;

	void			*tx2;
	int				*img_tx2;
	int				tx2_sl;
	int				tx2_end;
	int				tx2_bpp;
	int				tx2_w;
	int				tx2_h;

	void			*tx3;
	int				*img_tx3;
	int				tx3_sl;
	int				tx3_end;
	int				tx3_bpp;
	int				tx3_w;
	int				tx3_h;

	void			*tx4;
	int				*img_tx4;
	int				tx4_sl;
	int				tx4_end;
	int				tx4_bpp;
	int				tx4_w;
	int				tx4_h;

	void			*tx5;
	int				*img_tx5;
	int				tx5_sl;
	int				tx5_end;
	int				tx5_bpp;
	int				tx5_w;
	int				tx5_h;

	void			*tx6;
	int				*img_tx6;
	int				tx6_sl;
	int				tx6_end;
	int				tx6_bpp;
	int				tx6_w;
	int				tx6_h;

	void			*tx7;
	int				*img_tx7;
	int				tx7_sl;
	int				tx7_end;
	int				tx7_bpp;
	int				tx7_w;
	int				tx7_h;

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
	**   bitmapping
	*/
	t_texture		**txt;
	double 			wallx; 
	int 			texnum;
	int 			texx;
	int 			texy;
	unsigned long 	tex_color;
	int 			size;
	int				checker;
}					t_dataset;

t_dataset			*init_dataset(t_dataset *ai, char *argv);
void				init_level(t_dataset *ai);
void				init_textures1(t_dataset *ai);
void				init_textures2(t_dataset *ai);
void				init_textures3(t_dataset *ai);
void				init_mlx(t_dataset *ai);

void				validate_level(t_dataset *ai);
void				validate_param(t_dataset *ai);

void				sys_error(t_dataset *ai, int error);
void				sys_message(int msg);
void				sys_free(t_dataset *ai);
int					sys_close(t_dataset *ai);

void				movement_up(t_dataset *ai);
void				movement_down(t_dataset *ai);
void				movement_left(t_dataset *ai);
void				movement_right(t_dataset *ai);


void				ray(t_dataset *ai);
void				check_raydirx(t_dataset *ai);
void				check_raydiry(t_dataset *ai);
void				check_distance(t_dataset *ai); 
void				visualization(t_dataset *ai);
void				texturation(t_dataset *ai);
void				draw_floor(t_dataset *ai);
void				draw_dot(t_dataset *ai);
void				bitmapping(t_dataset *ai);

void				rdr_display(t_dataset *ai);
void				rdr_pipeline(t_dataset *ai);
void				rdr_geometry(t_dataset *ai);

int					key_hendler(int key, t_dataset *ai);
int					key_push(int key, t_dataset *ai);
int					key_pressed(int key, t_dataset *ai);
int					key_controllers(t_dataset *ai);

int					count_blocks(t_dataset *ai, char *argv);
int					count_words(t_dataset *ai, const char *s, char c);
int					parser(t_dataset *ai);
 
#endif
