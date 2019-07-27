/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:31:26 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:31:28 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_push(int key, t_dataset *ai)//связать и оптимизировать
{
	if (key == UP_ARROW || key == W)
		ai->control_up = 1;
	 if (key == DOWN_ARROW || key == S)
		ai->control_down = 1;
	 if (key == LEFT_ARROW || key == A)
		ai->control_left = 1;
	 if (key == RIGHT_ARROW || key == D)
		ai->control_right = 1;
	 if (key == SHIFT)
		ai->movespeed = .6;
	key_hendler(key, ai);
	return (0);
}

int		key_pressed(int key, t_dataset *ai)
{
	if (key == UP_ARROW || key == W)
		ai->control_up = 0;
	 if (key == DOWN_ARROW || key == S)
		ai->control_down = 0;
	 if (key == LEFT_ARROW || key == A)
		ai->control_left = 0;
	 if (key == RIGHT_ARROW || key == D)
		ai->control_right = 0;
	 if (key == SHIFT)
		ai->movespeed = .3;
	key_hendler(key, ai);
	return (0);
}

int		key_hendler(int key, t_dataset *ai)
{
	(void)(ai);
	if (key == ESC)
		sys_close(ai);
	 if (ai->control_up == 1)
		movement_up(ai);
	 if (ai->control_down == 1)
		movement_down(ai);
	 if (ai->control_left == 1)
		movement_left(ai);
	 if (ai->control_right == 1)
		movement_right(ai);
	return (0);
}

int		key_controllers(t_dataset *ai)//сравнить с кодом. Етс
{
	mlx_hook(ai->win, 2, 0, key_push, ai);
	mlx_hook(ai->win, 3, 0, key_pressed, ai);
	mlx_hook(ai->win, 17, 0, sys_close, ai);
	return (0);
}
