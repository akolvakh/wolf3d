#include "wolf3d.h"

t_dataset	*init_dataset(char *argv)
{
	t_dataset *data;

	if (!(data = (t_dataset *)ft_memalloc(sizeof(t_dataset))))
		sys_error(MALLOC);
	data->w = WIDTH;
	data->h = HEIGHT;
	data->posx = 6;
	data->posy = 8;
	data->dirx = -1;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->time = 0;
	data->oldtime = 0;
	data->upkey = 0;
	data->downkey = 0;
	data->leftkey = 0;
	data->rightkey = 0;
	data->rotspeed = .2;
	data->movespeed = .2;



	data->amount = blocks_counter(argv);
	data->row = 32;
	data->a = 0;
	data->cnt = 0;
	data->line = 0;
	if (!(data->def = (t_dot *)ft_memalloc(sizeof(t_dot) * data->amount)))
		sys_error(MALLOC);
	if (!(data->dot = (t_dot *)ft_memalloc(sizeof(t_dot) * data->amount)))
		sys_error(MALLOC);
	return (data);



}

void	init_level(t_dataset *data)
{
	/*data->cnt = -1;
	while (++data->cnt < data->amount) //фришить память и етс. Переписать из того буфера в этот, а тот очистить.
	{
		data->def[data->cnt].x = data->dot[data->cnt].x;
		data->def[data->cnt].y = data->dot[data->cnt].y;
		data->def[data->cnt].z = data->dot[data->cnt].z;
	}*/

	data->worldmap[0] = "1111111111";
	data->worldmap[1] = "1000000001";
	data->worldmap[2] = "1000000001";
	data->worldmap[3] = "1000000001";
	data->worldmap[4] = "1000000001";
	data->worldmap[5] = "1000300001";
	data->worldmap[6] = "1000000001";
	data->worldmap[7] = "1000000001";
	data->worldmap[8] = "1000000001";
	data->worldmap[9] = "1111111111";
}

void	init_color(t_dataset *data)
{
	char color;

	color = data->worldmap[data->mapx][data->mapy];
	if (color == '1')
		data->color = 0x00FFFF;
	else if (color == '2')
		data->color = 0x0000FF;
	else if (color == '3')
		data->color = 0x9400D3;
	else if (color == '4')
		data->color = 0xFF8C00;
	else if (color == '0')
		data->color = 0x008080;
}
