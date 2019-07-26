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
	ai->dot = (t_dot *)ft_memalloc(sizeof(t_dot) * ai->amount);
	return (ai);
}

void	init_level(t_dataset *ai)//leaks
{
	int i;
	int k;
	int j;
	char numb;
	char *ptr;
	
	i = -1;
	k = 0;
	ai->worldmap = (char **)ft_memalloc(sizeof(char) * ai->l * ai->row);
	while(++i <= ai->row)
		ai->worldmap[i] = (char *)ft_memalloc(sizeof(char*)*ai->l);
	i = 0;
	while(i <= ai->row)
	{
		j = -1;
		while(++j < ai->l)
		{
			ptr = ft_itoa(ai->dot[k].z);
			numb = *ptr;
			ai->worldmap[i][j] = numb;
			k++;
			free(ptr);
		}
		//ai->worldmap[i][j+1] = '\0';//
		/*if(i == 0 || i == ai->row)
		{
			j = 0;
			while (ai->worldmap[i][j])
			{
				if (ai->worldmap[i][j] == '0')
					sys_error(MAP);
				j++;
			}
		}
		ft_putnbr(j);
		if( ai->worldmap[i][0] == '0' || ai->worldmap[i][j - 1] == '0')
			sys_error(MAP);
			*/
		i++;
	}
}

void	validate_level(t_dataset *ai)
{
	int i;
	int j;

	i = 0;
	while(i <= ai->row)
	{
		if(i == 0 || i == ai->row)
		{
			j = 0;
			while (ai->worldmap[i][j])
			{
				if (ai->worldmap[i][j] == '0')
					sys_error(MAP);
				j++;
			}
		}
		if( ai->worldmap[i][0] == '0' || ai->worldmap[i][j - 1] == '0')
			sys_error(MAP);
		i++;
	}
}



void	init_color(t_dataset *ai)
{
	char color;

	color = ai->worldmap[ai->mapx][ai->mapy];
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
