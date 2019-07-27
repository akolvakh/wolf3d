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
	ai->tex_color = YELLOW;
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

void	check_distance(t_dataset *ai) 
{
	while (ai->hit == 0)
	{
		if (!(ai->sidedistx < ai->sidedisty))
		{
			ai->sidedisty = ai->sidedisty + ai->deltadisty;
			ai->mapy = ai->mapy + ai->stepy;
			ai->side = 1;
		}
		else
		{
			ai->sidedistx = ai->sidedistx + ai->deltadistx;
			ai->mapx = ai->mapx + ai->stepx;
			ai->side = 0;
		}
		if (ai->worldmap[ai->mapx][ai->mapy] != '0')
			ai->hit = 1;
	}
	if (ai->side == 0)
		ai->perpwalldist = (ai->mapx - ai->rayposx + (1 - ai->stepx) / 2) / ai->raydirx;
	else
		ai->perpwalldist = (ai->mapy - ai->rayposy + (1 - ai->stepy) / 2) / ai->raydiry;
	ai->lineheight = (int)(ai->h / ai->perpwalldist);
	ai->drawstart = -(ai->lineheight) / 2 + ai->h / 2;
}




void	texturation(t_dataset *ai)
{
	ai->texnum = ai->worldmap[ai->mapx][ai->mapy] - 1;
	if (ai->side == 0)
		ai->wallx = ai->posy + ai->perpwalldist * ai->raydiry;
	else
		ai->wallx = ai->posx + ai->perpwalldist * ai->raydirx;
	ai->wallx = ai->wallx - floor((ai->wallx));

	
	ai->texx = (ai->wallx * TEX_WDT);
	if (ai->side == 0 && ai->raydirx > 0)
		ai->texx = TEX_WDT - ai->texx - 1;
	if (ai->side == 1 && ai->raydiry < 0)
		ai->texx = TEX_WDT - ai->texx - 1;
}

void	bitmapping(t_dataset *ai)
{
	int y;
	int d;

	y = ai->drawstart;
	while (y < ai->drawend)
	{
		d = (y * 256 - ai->h * 128 + ai->lineheight * 128); //(*1000 / 1000)
		ai->texy = (((d * TEX_HGT) / ai->lineheight) / 256); // (*1000 / 1000)
		if (ai->side == 1 && ai->raydiry < 0)
			ai->tex_color = (ai->texture[(ai->texnum + ai->texture_mod) % 8]->img_ptr[TEX_WDT * ai->texy + ai->texx] >> 1) & 0x7f7f7f;
		if (ai->side == 1 && ai->raydiry > 0)
			ai->tex_color = (ai->texture[(ai->texnum + 1 + ai->texture_mod) % 8]->img_ptr[TEX_WDT * ai->texy + ai->texx] >> 1) & 0x7f7f7f;
		if (ai->side == 0 && ai->raydirx < 0)
			ai->tex_color = ai->texture[(ai->texnum + 2 + ai->texture_mod) % 8]->img_ptr[TEX_WDT * ai->texy + ai->texx];
		if (ai->side == 0 && ai->raydirx > 0)
			ai->tex_color = ai->texture[(ai->texnum + 3 + ai->texture_mod) % 8]->img_ptr[TEX_WDT * ai->texy + ai->texx];
		draw_dot(ai);
		ai->drawstart++;
		y++;
	}
}

void	visualization(t_dataset *g)
{
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
	if (!(g->drawstart > 0))
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + g->h / 2;
	if (g->drawend >= g->h)
		g->drawend = g->h - 1;
	if (!(g->side != 1))
		g->color = g->color / 2;
}