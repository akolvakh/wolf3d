#include "wolf3d.h"

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
		ai->perpwalldist = (ai->mapx - ai->rayposx +
			(1 - ai->stepx) / 2) / ai->raydirx;
	else
		ai->perpwalldist = (ai->mapy - ai->rayposy +
			(1 - ai->stepy) / 2) / ai->raydiry;
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
		d = (1000 * (y * 256 - ai->h * 128 + ai->lineheight * 128) / 1000); //(*1000 / 1000)
		ai->texy = (1000 * (((d * TEX_HGT) / ai->lineheight) / 256) / 1000); // (*1000 / 1000)
		if (ai->side == 1 && ai->raydiry > 0)
			ai->tex_color = (ai->txt[(ai->texnum + 1 + A) % 8]->
			img_ptr[TEX_WDT * ai->texy + ai->texx] >> 1) & 0x7f7f7f;//
		if (ai->side == 0 && ai->raydirx < 0)
			ai->tex_color = ai->txt[(ai->texnum + 2 + A) % 8]->
			img_ptr[TEX_WDT * ai->texy + ai->texx];//
		if (ai->side == 1 && ai->raydiry < 0)
			ai->tex_color = (ai->txt[(ai->texnum) % 8]->
			img_ptr[TEX_WDT * ai->texy + ai->texx + A] >> 1) & 0x7f7f7f;//
		if (ai->side == 0 && ai->raydirx > 0)
			ai->tex_color = ai->txt[(ai->texnum + 3 + A) % 8]->
			img_ptr[TEX_WDT * ai->texy + ai->texx];//
		draw_dot(ai);
		ai->drawstart++;
		y++;
	}
}

void	visualization(t_dataset *ai)
{
	ai->drawstart = -(ai->lineheight) / 2 + ai->h / 2;
	if (!(ai->drawstart > 0))
		ai->drawstart = 0;
	ai->drawend = ai->lineheight / 2 + ai->h / 2;
	if (ai->drawend >= ai->h)
		ai->drawend = ai->h - 1;
	if (!(ai->side != 1))
		ai->color = ai->color / 2;
}