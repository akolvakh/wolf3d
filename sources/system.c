/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:32:05 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:32:07 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		sys_close(t_dataset *ai)
{
	if(ai->mlx)
		mlx_destroy_window(ai->mlx, ai->win);
	sys_free(ai);
	ft_putendl("Exit the game");
	exit(-1);
	return (0);
}

void	sys_error(t_dataset *ai, int err)
{
	char *out;

	if ((err == MAP && (out = "ERROR: invalid map\n"))
	|| (err == MLX && (out = "ERROR: can't initialize mlx\n"))
	|| (err == IMG && (out = "ERROR: can't create image mlx\n"))
	|| (err == WIN && (out = "ERROR: can't create window\n"))
	|| (err == VALUE && (out = "ERROR: invalid value\n"))
	|| (err == IMG_PTR && (out = "ERROR: can't get image ptr\n"))
	|| (err == FILE && (out = "ERROR: can't open file\n"))
	|| (err == MALLOC && (out = "ERROR: can't malloc memory\n"))
	|| (err == INPUT && (out = "ERROR: too much input\n"))
	|| (err == FINISH && (out = "MESSAGE: Exit the game\n"))
	|| (err == TEXTURE && (out = "ERROR: invalid textures\n"))
	|| (err == PLAYER && (out = "ERROR: player don't have free space\n"))
	|| (err == USAGE && (out = "ERROR: invalid input. Read it ->\n\n")))
		ft_putstr(out);
	sys_close(ai);
}

void	sys_message(int msg)
{
	char *out;

	if ((msg == USAGE && (out = "USAGE:\nControls:\nArrow Keys & WASD to Move\n"
			"Shift to super speed\nEsc to Exit\nChoose map to begin the game\n"))
	|| (msg == START && (out = "MESSAGE: Start the game\n"))
	|| (msg == LEFT && (out = "MESSAGE: Left\n"))
	|| (msg == RIGHT && (out = "MESSAGE: Right\n"))
	|| (msg == UP && (out = "MESSAGE: Up\n"))
	|| (msg == DOWN && (out = "MESSAGE: Down\n")))
		ft_putstr(out);
}

void	sys_free(t_dataset *ai)
{
	int i;
	int j;

	i = -1;
	if(!(ai->worldmap))
		exit(-1);
	while (++i <= ai->row)
	{
		j = 0;
		while (ai->worldmap[i][j])
		{
			ai->worldmap[i][j] = '\0';
			j++;
		}
		free(ai->worldmap[i]);
	}
	if(ai->worldmap)
		free(ai->dot);
	free(ai->worldmap);
	if(!(ai->txt))
		exit(-1);
	i = -1;
	while (++i < 8)
		free(ai->txt[i]);
	free(ai->txt);
}
