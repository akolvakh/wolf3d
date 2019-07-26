/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:31:40 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:31:41 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dataset	*init_dataset(char *argv)
{
	t_dataset *ai;

	ai = (t_dataset *)ft_memalloc(sizeof(t_dataset));
	ai->w = WDT;
	ai->h = HGT;
	ai->posx = 6;
	ai->posy = 8;
	ai->dirx = -1;
	ai->diry = 0;
	ai->planex = 0;
	ai->planey = 0.66;
	ai->time = 0;
	ai->oldtime = 0;
	ai->control_up = 0;
	ai->control_down = 0;
	ai->control_left = 0;
	ai->control_right = 0;
	ai->rotspeed = .2;
	ai->movespeed = .2;
	ai->amount = count_blocks(argv);
	ai->row = 0;
	ai->a = 0;
	ai->cnt = 0;
	ai->line = 0;
	ai->coof = 600;
	ai->dot = (t_dot *)ft_memalloc(sizeof(t_dot) * ai->amount);
	return (ai);
}

void	init_color(t_dataset *ai)
{
	char color;

	color = ai->worldmap[ai->mapx][ai->mapy];//менять цвет в зависимости от текстуры. То есть, брать ее, считывать, записывать в файл, проходиться по нему и записывать его.
	//вектор записать по формуле х * у и дальше искать нужную координату, етс. 
	if (color == '1')
		ai->color = PINK;
	else if (color == '2')
		ai->color = YELLOW;
	else if (color == '3')
		ai->color = BLUE;
	else if (color == '4')
		ai->color = GREEN;
	else if (color == '0')
		ai->color = WHITE;
}
