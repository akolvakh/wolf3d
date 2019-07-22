#include "wolf3d.h"

unsigned int	colormagic(int i, double x, double y)
{
	unsigned int	color;
	double			magic;
	double			i2;
	t_dataset		data;

	magic = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	data.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	data.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	data.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (data.chan[0] << 16) + (data.chan[1] << 8) + (data.chan[2] + 255);
	return (color);
}

void			novatempus(t_dataset *data, int x)
{
	int		initioy;
	int		mori;
	int		initio;

	mori = data->drawend;
	if (mori > HEIGHT)
		mori = HEIGHT - 1;
	initioy = data->drawstart;
	if (initioy < 0)
		initioy = 0;
	initio = -1;
	while (++initio < (HEIGHT / 2))
		data->img_wall[x + (initio * data->wall_sl / 4)] = 0xC00000AA;
	while (++initioy < mori)
		data->img_wall[x + (initioy * data->wall_sl / 4)] = colormagic(data->
				color, x, initioy);
	initio = mori - 1;
	while (++initio < (HEIGHT - 1))
		data->img_wall[x + (initio * data->wall_sl / 4)] = 0xC00000AA;
}

void			drawstuff1(t_dataset *g) //stage 1 - function, data, different structures, same(one) structure, shaders, buffers, etc.
{
	g->camerax = 2 * g->x / (double)g->w - 1;
	g->rayposx = g->posx;
	g->rayposy = g->posy;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)g->rayposx;
	g->mapy = (int)g->rayposy;
	g->deltadistx = sqrt(1 + (g->raydiry *
				g->raydiry) / (g->raydirx * g->raydirx));
	g->deltadisty = sqrt(1 + (g->raydirx *
				g->raydirx) / (g->raydiry * g->raydiry));
	g->hit = 0;
}

void			drawstuff2(t_dataset *g) //stage 2
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->rayposx - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->rayposx) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->rayposy - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->rayposy) * g->deltadisty;
	}
}

void			drawstuff3(t_dataset *g) //stage 3
{
	while (g->hit == 0)
	{
		if (g->sidedistx < g->sidedisty)
		{
			g->sidedistx += g->deltadistx;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sidedisty += g->deltadisty;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->worldmap[g->mapx][g->mapy] != '0')
			g->hit = 1;
	}
	if (g->side == 0)
		g->perpwalldist = (g->mapx - g->rayposx +
				(1 - g->stepx) / 2) / g->raydirx;
	else
		g->perpwalldist = (g->mapy - g->rayposy +
				(1 - g->stepy) / 2) / g->raydiry;
	g->lineheight = (int)(g->h / g->perpwalldist);
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
}

void			drawstuff4(t_dataset *g) //stage 4
{
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
	if (g->drawstart < 0)
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + g->h / 2;
	if (g->drawend >= g->h)
		g->drawend = g->h - 1;
	init_color(g);
	if (g->side == 1)
		g->color = g->color / 2;
	novatempus(g, g->x);
}