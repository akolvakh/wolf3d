#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stdio.h>//


# define HEIGHT 		800
# define WIDTH 			1400

# define MAPH 			10
# define MAPW 			10

# define YELLOW 		0xF5B201
# define CYAN 			0x3FB1B7
# define PINK 			0xFF0FFF
# define WHITE 			0xFFFFFF
# define RED 			0xCC0000
# define GREEN 			0x98FB98
# define BLUE 			0x0000FF

# define MAP			1
# define MLX			2
# define WIN 			3
# define VALUE 			4
# define FILE 			5
# define MALLOC			6
# define USAGE			7
# define INPUT			8
# define START			9
# define FINISH			10
# define LEFT			11
# define RIGHT			12
# define UP				13
# define DOWN			14




//struct images

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dot;

typedef struct		s_dataset
{
	char			*worldmap[MAPH];

	void			*mlx;
	void			*win;
	void			*img;

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
	int				upkey;
	int				downkey;
	int				leftkey;
	int				rightkey;
	unsigned char	chan[3];



	int				a;
	char			**tmp;
	char			*buff;
	int				ret;
	int				fd;
	int				l;
	int				line;
	int				cnt;
	int				v;
	int				c;
	int				b;
	int				derr;
	int				row;
	int				amount;



	t_dot			*def;
	t_dot			*dot;

}					t_dataset;


void				init_level(t_dataset *data);
void				init_color(t_dataset *data);
//void				init_dataset(t_dataset *data);
t_dataset			*init_dataset(char *argv);

void				sys_printcontrols(int i);
void				sys_exit(char	*str);

//void				sys_errorcheck(char *str);
void				sys_error(int error);
void				sys_message(int message);
int					sys_close(t_dataset *data);



void				movement_up(t_dataset *data);
void				movement_down(t_dataset *data);
void				movement_left(t_dataset *data);
void				movement_right(t_dataset *data);



void				render_geometry(t_dataset *data);
void				drawstuff1(t_dataset *data);
void				drawstuff2(t_dataset *data);
void				drawstuff3(t_dataset *data);
void				drawstuff4(t_dataset *data);
unsigned int		colormagic(int i, double x, double y);
void				novatempus(t_dataset *data, int x);

void				window(t_dataset *data);
void				rendering(t_dataset *data);



int					key_hendler(int key, t_dataset *data);
int					key_push(int key, t_dataset *data);
int					key_pressed(int key, t_dataset *data);
int					key_controllers(t_dataset *data);


 int				parser(t_dataset *data);
 t_dataset			*tinfo_init(char *argv);
 int		    	blocks_counter(char *argv);
 int		   		count_words(const char *s, char c);


#endif
