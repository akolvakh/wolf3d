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
	t_dataset *data;

	data = (t_dataset *)ft_memalloc(sizeof(t_dataset));
	data->w = WIDTH;
	data->h = HEIGHT;
	data->posx = 6;
	data->posy = 8;
	data->dirx = -1;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->time = 0;
	data->oldtime = 0;
	data->control_up = 0;
	data->control_down = 0;
	data->control_left = 0;
	data->control_right = 0;
	data->rotspeed = .2;
	data->movespeed = .2;
	data->amount = count_blocks(argv);
	data->row = 0;
	data->a = 0;
	data->cnt = 0;
	data->line = 0;
	data->dot = (t_dot *)ft_memalloc(sizeof(t_dot) * data->amount);
	return (data);
}

void	init_level(t_dataset *data)
{
	int i;
	int k;
	int j;
	char numb;
	char *ptr;
	
	i = -1;
	k = 0;
	data->worldmap = (char **)ft_memalloc(sizeof(char) * data->l * data->row);
	while(++i <= data->row)
		data->worldmap[i] = (char *)ft_memalloc(sizeof(char*)*data->l);
	i = 0;
	while(i <= data->row)
	{
		j = -1;
		while(++j < data->l)
		{
			ptr = ft_itoa(data->dot[k].z);
			numb = *ptr;
			data->worldmap[i][j] = numb;
			k++;
		}
		data->worldmap[i][j+1] = '\0';
		i++;
	}
}

void	init_color(t_dataset *data)
{
	char color;

	color = data->worldmap[data->mapx][data->mapy];
	if (color == '1')
		data->color = PINK;
	else if (color == '2')
		data->color = YELLOW;
	else if (color == '3')
		data->color = BLUE;
	else if (color == '4')
		data->color = GREEN;
	else if (color == '0')
		data->color = WHITE;
}
