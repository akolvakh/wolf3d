#include "wolf3d.h"

int		key_push(int key, t_dataset *data)
{
	if (key == UPKEY || key == W)
		data->control_up = 1;
	else if (key == DOWNKEY || key == S)
		data->control_down = 1;
	else if (key == LEFTKEY || key == A)
		data->control_left = 1;
	else if (key == RIGHTKEY || key == D)
		data->control_right = 1;
	key_hendler(key, data);
	return (0);
}

int		key_pressed(int key, t_dataset *data)
{
	if (key == UPKEY || key == W)
		data->control_up = 0;
	else if (key == DOWNKEY || key == S)
		data->control_down = 0;
	else if (key == LEFTKEY || key == A)
		data->control_left = 0;
	else if (key == RIGHTKEY || key == D)
		data->control_right = 0;
	key_hendler(key, data);
	return (0);
}

int		key_hendler(int key, t_dataset *data)
{
	(void)(data);
	if (key == ESC)
		sys_close(data);
	else if (data->control_up == 1)
		movement_up(data);
	else if (data->control_down == 1)
		movement_down(data);
	else if (data->control_left == 1)
		movement_left(data);
	else if (data->control_right == 1)
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