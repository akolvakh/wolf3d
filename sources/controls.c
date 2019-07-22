#include "wolf3d.h"

int		key_push(int key, t_dataset *data)
{
	if (key == 126 || key == 13)
		data->upkey = 1;
	else if (key == 125 || key == 1)
		data->downkey = 1;
	else if (key == 123 || key == 0)
		data->leftkey = 1;
	else if (key == 124 || key == 2)
		data->rightkey = 1;
	key_hendler(key, data);
	return (0);
}

int		key_pressed(int key, t_dataset *data)
{
	if (key == 126 || key == 13)
		data->upkey = 0;
	else if (key == 125 || key == 1)
		data->downkey = 0;
	else if (key == 123 || key == 0)
		data->leftkey = 0;
	else if (key == 124 || key == 2)
		data->rightkey = 0;
	key_hendler(key, data);
	return (0);
}

int		key_hendler(int key, t_dataset *data)
{
	(void)(data);
	if (key == 53)
		sys_close(data);
	else if (data->upkey == 1)
		movement_up(data);
	else if (data->downkey == 1)
		movement_down(data);
	else if (data->leftkey == 1)
		movement_left(data);
	else if (data->rightkey == 1)
		movement_right(data);
	return (0);
}

int		key_controllers(t_dataset *data)
{
	mlx_hook(data->win, 2, 0, key_push, data);
	mlx_hook(data->win, 3, 0, key_pressed, data);
	mlx_hook(data->win, 17, 0, sys_close, data);
	return (0);
}