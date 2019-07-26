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

//display plane
//point of view
//ray
//distance
//


#include "wolf3d.h"

void	draw_dot(t_dataset *ai, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x >= (int)WDT || y >= (int)HGT))
		ai->img_wall[x + y * (int)WDT] = color;
}

void	draw_flour(t_dataset *ai, int x)
{
	ai->drawstart--;
	while (++ai->drawstart < HGT)
		draw_dot(ai, x, ai->drawstart, 0x4f4f4f);
}

void			ray(t_dataset *g) //stage 1 - function, ai, different structures, same(one) structure, shaders, buffers, etc.
{
	g->camerax = 2 * g->x / (double)g->w - 1;
	g->rayposx = g->posx;
	g->rayposy = g->posy;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)g->rayposx;
	g->mapy = (int)g->rayposy;
	g->deltadistx = sqrt(1 + (g->raydiry *
				g->raydiry) / (g->raydirx * g->raydirx));
	g->deltadisty = sqrt(1 + (g->raydirx *
				g->raydirx) / (g->raydiry * g->raydiry));
	g->hit = 0;
}

void			drawstuff2(t_dataset *g) //stage 2
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->rayposx - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->rayposx) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->rayposy - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->rayposy) * g->deltadisty;
	}
}

void			drawstuff3(t_dataset *g) //stage 3 // код просто с туториала. Нужно переделывать, переписывать, рефакторить и реорганизовывать, чтобы был разный код, разные дела, детали и механизмы. Чтобы все было разное и пройти пандору, етс.
{//вставлять сторонние вызовы и функции для расчета, просчета, чтобы поменять флоу и етс. Лучше пусть будет запутанным, неоптимизированным, но рабочим и другим, но потом буду делать свое, перепишу, оптимизирую, сделаю и переделаю то, что нужно и так, как надо. Етс. 
//проверка собой, проверка кем-то, проверка ребятами, проверка людьми, проверка пир ревью, проверка пандорой и етс.
	while (g->hit == 0)
	{
		if (g->sidedistx < g->sidedisty)
		{
			g->sidedistx += g->deltadistx;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sidedisty += g->deltadisty;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->worldmap[g->mapx][g->mapy] != '0')
			g->hit = 1;
	}
	if (g->side == 0)
		g->perpwalldist = (g->mapx - g->rayposx +
				(1 - g->stepx) / 2) / g->raydirx;
	else
		g->perpwalldist = (g->mapy - g->rayposy +
				(1 - g->stepy) / 2) / g->raydiry;
	g->lineheight = (int)(g->h / g->perpwalldist);
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
}

void			texturation(t_dataset *ai, int x) // (drawing) в этом блоке цепляем цвет на стены. И тут нужно будет цеплять текстуры, текстуру на стены. Это - ключевой блок
{
      int texnum = ai->worldmap[ai->mapx][ai->mapy] - 1; //1 subtracted from it so that texture 0 can be used!
      double wallx; //where exactly the wall was hit
      if (ai->side == 0) wallx = ai->posy + ai->perpwalldist * ai->raydiry;
      else           wallx = ai->posx + ai->perpwalldist * ai->raydirx;
      wallx -= floor((wallx));
      int texx = (wallx * TEX_WDT);
      if(ai->side == 0 && ai->raydirx > 0) texx = TEX_WDT - texx - 1;
      if(ai->side == 1 && ai->raydiry < 0) texx = TEX_WDT - texx - 1;

			unsigned long color;

	 	for(int y = ai->drawstart; y<ai->drawend; y++)
     {
        int d = y * 256 - ai->h * 128 + ai->lineheight * 128;  //256 and 128 factors to avoid floats
        int texy = ((d * TEX_HGT) / ai->lineheight) / 256;

if (ai->side == 1 && ai->raydiry < 0)
	color = (ai->texture[(texnum + ai->texture_mod) % 8]->img_ptr[64 * texy + texx] >> 1) & 0x7F7F7F;
if (ai->side == 1 && ai->raydiry > 0)
	color = (ai->texture[(texnum + 1 + ai->texture_mod) % 8]->img_ptr[64 * texy + texx] >> 1) & 0x7F7F7F;
if (ai->side == 0 && ai->raydirx < 0)
	color = ai->texture[(texnum + 2 + ai->texture_mod) % 8]->img_ptr[64 * texy + texx];
if (ai->side == 0 && ai->raydirx > 0)
	color = ai->texture[(texnum + 3 + ai->texture_mod) % 8]->img_ptr[64 * texy + texx];
draw_dot(ai, x, ai->drawstart, color);
ai->drawstart++;
		}
//draw_flour(ai, ai->x);
}







void			visualization(t_dataset *g) //stage 4 - цвет и текстуры, g (drawline)
{
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
	if (g->drawstart < 0)
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + g->h / 2;
	if (g->drawend >= g->h)
		g->drawend = g->h - 1;
	if (g->side == 1)
		g->color = g->color / 2;
	texturation(g, g->x);
}
