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

void			texturation(t_dataset *ai, int x) // в этом блоке цепляем цвет на стены. И тут нужно будет цеплять текстуры, текстуру на стены. Это - ключевой блок
{
	/*int		initioy; //
	int		mori; // 
	int		initio; //

	mori = ai->drawend;
	if (mori > HGT)
		mori = HGT - 1;
	initioy = ai->drawstart;
	if (initioy < 0)
		initioy = 0;
	initio = -1;
	while (++initio < (HGT / 2))
		ai->img_wall[x + (initio * ai->wall_sl / 4)] = 0xC00000AA;
	while (++initioy < mori)
		ai->img_wall[x + (initioy * ai->wall_sl / 4)] = 0xFF00FF; //color staff
	initio = mori - 1;
	while (++initio < (HGT - 1))
		ai->img_wall[x + (initio * ai->wall_sl / 4)] = 0xC00000AA;*/


  	//generate some textures
  	for(int x = 0; x <TEX_WDT; x++)
  	for(int y = 0; y < TEX_HGT; y++)
  	{
		int xorcolor = (x * 256 / TEX_WDT) ^ (y * 256 / TEX_HGT);
		//int xcolor = x * 256 / TEX_WDT;
		int ycolor = y * 256 / TEX_HGT;
		int xycolor = y * 128 / TEX_HGT + x * 128 / TEX_WDT;
		ai->texture_buf[0][TEX_WDT * y + x] = 65536 * 254 * (x != y && x != TEX_WDT - y); //flat red texture with black cross
		ai->texture_buf[1][TEX_WDT * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
		ai->texture_buf[2][TEX_WDT * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
		ai->texture_buf[3][TEX_WDT * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
		ai->texture_buf[4][TEX_WDT * y + x] = 256 * xorcolor; //xor green
		ai->texture_buf[5][TEX_WDT * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
		ai->texture_buf[6][TEX_WDT * y + x] = 65536 * ycolor; //red gradient
		ai->texture_buf[7][TEX_WDT * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
  	}




      //texturing calculations
      int texNum = ai->worldmap[ai->mapx][ai->mapy] - 1; //1 subtracted from it so that texture 0 can be used!

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if (ai->side == 0) wallX = ai->posy + ai->perpwalldist * ai->raydiry;
      else           wallX = ai->posx + ai->perpwalldist * ai->raydirx;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)(TEX_WDT));
      if(ai->side == 0 && ai->raydirx > 0) texX = TEX_WDT - texX - 1;
      if(ai->side == 1 && ai->raydiry < 0) texX = TEX_WDT - texX - 1;

	 for(int y = ai->drawstart; y<ai->drawend; y++)
     {
        int d = y * 256 - ai->h * 128 + ai->lineheight * 128;  //256 and 128 factors to avoid floats
        // TODO: avoid the division to speed this up
        int texY = ((d * TEX_HGT) / ai->lineheight) / 256;
        unsigned long color = ai->texture_buf[texNum][TEX_HGT * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(ai->side == 1) color = (color >> 1) & 8355711;
        ai->buffer[y][x] = color;
      }
    }







void			visualization(t_dataset *g) //stage 4 - цвет и текстуры, g 
{
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
	if (g->drawstart < 0)
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + g->h / 2;
	if (g->drawend >= g->h)
		g->drawend = g->h - 1;
	init_color(g);
	if (g->side == 1)
		g->color = g->color / 2;
	texturation(g, g->x);
}
