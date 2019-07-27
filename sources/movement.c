/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:31:50 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:31:52 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//поменять порядок и структуру, логику кнопок

#include "wolf3d.h"

void	movement_up(t_dataset *ai)
{
	int x;
	int y;

	x = (int)(ai->posx + ai->dirx * ai->movespeed);
	y = (int)(ai->posy + ai->diry * ai->movespeed);
	if (ai->control_up == 1 && ai->control_down == 0)
	{
		if (ai->worldmap[x][y] == '0')
		{
			ai->posx = ai->posx + ai->dirx * ai->movespeed;
			ai->posy = ai->posy + ai->diry * ai->movespeed;
			rdr_pipeline(ai);
			sys_message(UP);
		}
	}
}

void	movement_down(t_dataset *ai)
{
	int x;
	int y;

	x = (int)(ai->posx - ai->dirx * ai->movespeed);
	y = (int)(ai->posy - ai->diry * ai->movespeed);
	if (ai->control_down == 1 & ai->control_up == 0)
	{
		if (ai->worldmap[x][y] == '0')
		{
			ai->posx = ai->posx - ai->dirx * ai->movespeed;
			ai->posy = ai->posy - ai->diry * ai->movespeed;
			rdr_pipeline(ai);
			sys_message(DOWN);
		}
	}
}

void	movement_right(t_dataset *ai)
{
	if (ai->control_right == 1 && ai->control_left == 0)
	{
		ai->olddirx = ai->dirx;
		ai->dirx = ai->dirx * cos(-ai->rotspeed) - ai->diry * sin(-ai->rotspeed);
		ai->diry = ai->olddirx * sin(-ai->rotspeed) + ai->diry * cos(-ai->rotspeed);
		ai->oldplanex = ai->planex;
		ai->planex = ai->planex * cos(-ai->rotspeed) - ai->planey * sin(-ai->rotspeed);
		ai->planey = ai->oldplanex * sin(-ai->rotspeed) + ai->planey * cos(-ai->rotspeed);
		rdr_pipeline(ai);
		sys_message(RIGHT);
	}
}

void	movement_left(t_dataset *ai)
{
	if (ai->control_left == 1 && ai->control_right == 0)
	{
		ai->olddirx = ai->dirx;
		ai->dirx = ai->dirx * cos(ai->rotspeed) - ai->diry * sin(ai->rotspeed);
		ai->diry = ai->olddirx * sin(ai->rotspeed) + ai->diry * cos(ai->rotspeed);
		ai->oldplanex = ai->planex;
		ai->planex = ai->planex * cos(ai->rotspeed) - ai->planey * sin(ai->rotspeed);
		ai->planey = ai->oldplanex * sin(ai->rotspeed) + ai->planey * cos(ai->rotspeed);
		rdr_pipeline(ai);
		sys_message(LEFT);
	}
}
