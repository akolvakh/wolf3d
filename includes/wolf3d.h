#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

#define texWidth 64
#define texHeight 64

enum				e_keys
{
	Q = 12, E = 14, R = 15,
	ONE = 18, TWO = 19,
	THREE = 20, FOUR = 21,
	TAB = 1, SHIFT = 2,
	P = 35, ESC = 53,
	CLICK = 1, SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	UPKEY = 126, W = 13,
	DOWNKEY = 125, S = 1,
	LEFTKEY = 123, A = 0,
	RIGHTKEY = 124, D = 2,



};

enum				e_colors
{
	YELLOW = 0xF5B201, CYAN = 0x3FB1B7,
	PINK = 0xFF0FFF, WHITE = 0xFFFFFF,
	RED = 0xCC0000, GREEN = 0x98FB98,
	BLUE = 0x0000FF, DEF_COLOR = 0xF5B201
};

enum				e_display
{
	START_X = 100, START_Y = 100,
	WIDTH = 1400, HEIGHT = 800
};

enum				e_errors
{
	MAP = 1, MLX = 2,
	WIN = 3, VALUE = 4,
	FILE = 5, MALLOC = 6,
	USAGE = 7, INPUT = 8,
	START = 9, FINISH = 10,
};

enum				e_moves
{
	LEFT = 11, RIGHT = 12,
	UP = 13, DOWN = 14
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
	char			**worldmap;
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

	int				control_up;
	int				control_down;
	int				control_left;
	int				control_right;

	unsigned char	chan[3];

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

}					t_dataset;

void				init_level(t_dataset *data);
void				init_color(t_dataset *data);
t_dataset			*init_dataset(char *argv);

void				sys_error(int error);
void				sys_message(int message);
void				sys_free(t_dataset *data);
int					sys_close(t_dataset *data);

void				movement_up(t_dataset *data);
void				movement_down(t_dataset *data);
void				movement_left(t_dataset *data);
void				movement_right(t_dataset *data);

void				render_geometry(t_dataset *data);
void				ray(t_dataset *data);
void				drawstuff2(t_dataset *data);
void				drawstuff3(t_dataset *data);
void				visualization(t_dataset *data);
unsigned int		colormagic(int i, double x, double y);
void				texturation(t_dataset *data, int x);

void				display(t_dataset *data);
void				rendering(t_dataset *data);

int					key_hendler(int key, t_dataset *data);
int					key_push(int key, t_dataset *data);
int					key_pressed(int key, t_dataset *data);
int					key_controllers(t_dataset *data);

int					count_blocks(char *argv);
int					count_words(const char *s, char c);
int					parser(t_dataset *data);
 
#endif
