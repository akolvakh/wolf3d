#include "wolf3d.h"

void	sys_error(int error)
{
	char *msg;

	if ((error == MAP && (msg = "ERROR: invalid map\n"))
	|| (error == MLX && (msg = "ERROR: can't initialize mlx\n"))
	|| (error == WIN && (msg = "ERROR: can't create window\n"))
	|| (error == VALUE && (msg = "ERROR: invalid value\n"))
	|| (error == FILE && (msg = "ERROR: can't open file\n"))
	|| (error == MALLOC && (msg = "ERROR: can't malloc memory\n"))
	|| (error == INPUT && (msg = "ERROR: too much input\n"))
	|| (error == FINISH && (msg = "MESSAGE: Exit the game\n")))
		ft_putstr(msg);
	//free memory
	exit(-1);
}

void	sys_message(int message)
{
	char *msg;

	if ((message == USAGE && (msg = "USAGE:\nControls:\nArrow Keys & WASD to Move\nEsc to Exit\nType start to begin the game\n"))
	|| (message == START && (msg = "MESSAGE: Start the game\n"))
	|| (message == LEFT && (msg = "MESSAGE: Left\n"))
	|| (message == RIGHT && (msg = "MESSAGE: Right\n"))
	|| (message == UP && (msg = "MESSAGE: Up\n"))
	|| (message == DOWN && (msg = "MESSAGE: Down\n")))
		ft_putstr(msg);
}

int		sys_close(t_dataset *data)
{
	mlx_destroy_window(data->mlx, data->win);
	sys_error(FINISH);
	return (0);
}

void	sys_free(t_dataset *data)
{
	int i;

	i = -1;
	while(++i <= data->row)
		free(data->worldmap[i]);
	free(data->worldmap);
}
