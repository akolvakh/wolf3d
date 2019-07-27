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
	mlx_destroy_window(ai->mlx, ai->win);
	sys_free(ai);
	sys_error(FINISH);
	return (0);
}

void	sys_error(int err)
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
	|| (err == FINISH && (out = "MESSAGE: Exit the program\n"))
	|| (err == TEXTURE && (out = "ERROR: invalid textures\n"))
	|| (err == USAGE && (out = "ERROR: invalid input. Read it ->\n\n")))
		ft_putstr(out);
	exit(-1);
}

void	sys_message(int msg)
{
	char *out;

	if ((msg == USAGE && (out = "USAGE:\nControls:\nArrow Keys & WASD to Move\n"
			"Esc to Exit\nType start to begin the game\n"))
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

	i = -1;
	while (++i <= ai->row)
		free(ai->worldmap[i]);
	free(ai->dot);
	i = -1;
	while (++i < 8)
		free(ai->txt[i]);
	free(ai->txt);
	free(ai->worldmap);
	free(ai);//double free
}
