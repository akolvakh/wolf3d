

//поменять порядок и структуру, логику кнопок, для пандоры

#include "wolf3d.h"

void	movement_up(t_dataset *data)
{
	int x;
	int y;

	x = (int)(data->posx + data->dirx * data->movespeed);
	y = (int)(data->posy + data->diry * data->movespeed);
	if (data->upkey == 1 && data->downkey == 0)
	{
		if (data->worldmap[x][y] == '0')
		{
			data->posx += data->dirx * data->movespeed;
			data->posy += data->diry * data->movespeed;
			rendering(data);
			sys_message(UP);
		}
	}
}

void	movement_down(t_dataset *data)
{
	int x;
	int y;

	x = (int)(data->posx - data->dirx * data->movespeed);
	y = (int)(data->posy - data->diry * data->movespeed);
	if (data->downkey == 1 & data->upkey == 0)
	{
		if (data->worldmap[x][y] == '0')
		{
			data->posx -= data->dirx * data->movespeed;
			data->posy -= data->diry * data->movespeed;
			rendering(data);
			sys_message(DOWN);
		}
	}
}

void	movement_right(t_dataset *data)
{
	if (data->rightkey == 1 && data->leftkey == 0)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(-data->rotspeed) - data->diry * sin(-data->rotspeed);
		data->diry = data->olddirx * sin(-data->rotspeed) + data->diry * cos(-data->rotspeed);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(-data->rotspeed) -
			data->planey * sin(-data->rotspeed);
		data->planey = data->oldplanex * sin(-data->rotspeed) +
			data->planey * cos(-data->rotspeed);
		rendering(data);
		sys_message(RIGHT);
	}
}

void	movement_left(t_dataset *data)
{
	if (data->leftkey == 1 && data->rightkey == 0)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(data->rotspeed) - data->diry * sin(data->rotspeed);
		data->diry = data->olddirx * sin(data->rotspeed) +
			data->diry * cos(data->rotspeed);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(data->rotspeed) - data->planey * sin(data->rotspeed);
		data->planey = data->oldplanex * sin(data->rotspeed) +
			data->planey * cos(data->rotspeed);
		rendering(data);
		sys_message(LEFT);
	}
}
