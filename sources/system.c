


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
	//free memory
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

void	memory_free(t_dataset *data)
{
	int i;

	i = -1;
	while(++i <= data->row)
		free(data->worldmap[i]);
	free(data->worldmap);
}
