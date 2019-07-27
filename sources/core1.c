/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:31:35 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:31:36 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_dot(t_dataset *ai)
{
	if (!(ai->x < 0
	|| ai->drawstart < 0
	|| ai->x >= (int)WDT
	|| ai->drawstart >= (int)HGT))
		ai->img_wall[ai->x + ai->drawstart * (int)WDT] = ai->tex_color;
}

void	draw_floor(t_dataset *ai)
{
	ai->tex_color = CLR;
	ai->drawstart--;
	while (++ai->drawstart < HGT)
		draw_dot(ai);
}

void	ray(t_dataset *ai)
{
	ai->camerax = 2 * ai->x / (double)ai->w - 1;
	ai->rayposx = ai->posx;
	ai->rayposy = ai->posy;
	ai->raydirx = ai->dirx + ai->planex * ai->camerax;
	ai->raydiry = ai->diry + ai->planey * ai->camerax;
	ai->mapx = (int)ai->rayposx;
	ai->mapy = (int)ai->rayposy;
	ai->deltadistx = sqrt(1 + (ai->raydiry * ai->raydiry) / (ai->raydirx * ai->raydirx));
	ai->deltadisty = sqrt(1 + (ai->raydirx * ai->raydirx) / (ai->raydiry * ai->raydiry));
	ai->hit = 0;
}

void	check_raydirx(t_dataset *ai)
{
	if (!(ai->raydirx < 0))
	{
		ai->stepx = 1;
		ai->sidedistx = (ai->mapx + 1.0 - ai->rayposx) * ai->deltadistx;

	}
	else
	{
		ai->stepx = -1;
		ai->sidedistx = (ai->rayposx - ai->mapx) * ai->deltadistx;
	}
}

void	check_raydiry(t_dataset *ai)
{
	if (!(ai->raydiry < 0))
	{
		ai->stepy = 1;
		ai->sidedisty = (ai->mapy + 1.0 - ai->rayposy) * ai->deltadisty;
	}
	else
	{
		ai->stepy = -1;
		ai->sidedisty = (ai->rayposy - ai->mapy) * ai->deltadisty;
	}
}
