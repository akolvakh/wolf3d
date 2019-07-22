


#include "wolf3d.h"

void	sys_error(int error)
{
	if (error == MAP)
		ft_putstr("ERROR: invalid map\n");
	if (error == MLX)
		ft_putstr("ERROR: can't initialize mlx\n");
	if (error == WIN)
		ft_putstr("ERROR: can't create window\n");
	if (error == VALUE)
		ft_putstr("ERROR: invalid value\n");
	if (error == FILE)
		ft_putstr("ERROR: can't open file\n");
	if (error == MALLOC)
		ft_putstr("ERROR: can't malloc memory\n");
	if (error == INPUT)
		ft_putstr("ERROR: too much input\n");
	if (error == FINISH)//
		ft_putstr("MESSAGE: Exit the game\n");
	exit(-1);
}

void	sys_message(int message)
{
	if (message == USAGE)
		ft_putstr("USAGE:\nControls:\nArrow Keys & WASD to Move\nEsc to Exit\nType start to begin the game\n");
	if (message == START)
		ft_putstr("MESSAGE: Start the game\n");
	if (message == LEFT)
		ft_putstr("MESSAGE: Left\n");
	if (message == RIGHT)
		ft_putstr("MESSAGE: Right\n");
	if (message == UP)
		ft_putstr("MESSAGE: Up\n");
	if (message == DOWN)
		ft_putstr("MESSAGE: Down\n");
}

int		sys_close(t_dataset *data)
{
	mlx_destroy_window(data->mlx, data->win);
	sys_error(FINISH);
	return (0);
}

void	sys_errorcheck(char *str) //заменить на парсер и на карту
{
	if (ft_strcmp(str, "start") == 0)
		sys_message(START);
	else
		sys_error(MAP);
}

int		sys_repeat(t_dataset *g)
{
	mlx_hook(g->win, 2, 0, key_push, g);
	mlx_hook(g->win, 3, 0, key_pressed, g);
	mlx_hook(g->win, 17, 0, sys_close, g);
	return (0);
}