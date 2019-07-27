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

t_dataset	*init_dataset(t_dataset *ai, char *argv)
{
	ai->control_up = 0;
	ai->control_down = 0;
	ai->control_left = 0;
	ai->control_right = 0;
	ai->amount = count_blocks(argv);
	ai->w = WDT;
	ai->h = HGT;
	ai->posx = 1;
	ai->posy = 1;
	ai->dirx = -1;
	ai->diry = 0;
	ai->planex = 0;
	ai->planey = 0.66;
	ai->time = 0;
	ai->oldtime = 0;
	ai->rotspeed = .4;
	ai->movespeed = .3;
	ai->row = 0;
	ai->a = 0;
	ai->cnt = 0;
	ai->line = 0;
	ai->coof = 600;
	ai->txt_mod = 0;
	ai->dot = (t_dot *)ft_memalloc(sizeof(t_dot) * ai->amount);
	return (ai);
}

void	init_mlx(t_dataset *ai)
{
	if (!(ai->mlx = mlx_init()))
		sys_error(MLX);
	if (!(ai->win = mlx_new_window(ai->mlx, WDT, HGT, "Wolf3D")))
		sys_error(WIN);
	if (!(ai->img = mlx_new_image(ai->mlx, WDT, HGT)))
		sys_error(IMG);
	init_textures1(ai);
	init_textures2(ai);
	init_textures3(ai);
}

void	init_textures1(t_dataset *ai)
{
	int i;

	ai->size = 64;
	i = -1;
	ai->txt = (t_texture **)ft_memalloc(8 * sizeof(t_texture *));
	while (++i < 8)
		ai->txt[i] = (t_texture *) ft_memalloc(sizeof(t_texture));
	if(!(ai->txt[0]->img = mlx_xpm_file_to_image(ai->mlx, 
				"./textures/crafting_table_side.xpm", &ai->size, &ai->size)))
				sys_error(TEXTURE);
	if(!(ai->txt[0]->img_ptr = (int *)mlx_get_data_addr(ai->txt[0]->img,
				&ai->txt[0]->bpp, &ai->txt[0]->sl, &ai->txt[0]->ending)))
				sys_error(IMG_PTR);
	if(!(ai->txt[1]->img = mlx_xpm_file_to_image(ai->mlx, 
				"./textures/sandstone_top.xpm", &ai->size, &ai->size)))
				sys_error(TEXTURE);
	if(!(ai->txt[1]->img_ptr = (int *)mlx_get_data_addr(ai->txt[1]->img,
				&ai->txt[1]->bpp, &ai->txt[1]->sl, &ai->txt[1]->ending)))
			sys_error(IMG_PTR);
	if(!(ai->txt[2]->img = mlx_xpm_file_to_image(ai->mlx, 
				"./textures/furnace_side.xpm", &ai->size, &ai->size)))
			sys_error(TEXTURE);
}

void	init_textures2(t_dataset *ai)
{
	if(!(ai->txt[2]->img_ptr = (int *)mlx_get_data_addr(ai->txt[2]->img,
			&ai->txt[2]->bpp, &ai->txt[2]->sl, &ai->txt[2]->ending)))
			sys_error(IMG_PTR);
	if(!(ai->txt[3]->img = mlx_xpm_file_to_image(ai->mlx,
			"./textures/glowstone.xpm", &ai->size, &ai->size)))
			sys_error(TEXTURE);
	if(!(ai->txt[3]->img_ptr = (int *)mlx_get_data_addr(ai->txt[3]->img,
			&ai->txt[3]->bpp, &ai->txt[3]->sl, &ai->txt[3]->ending)))
			sys_error(IMG_PTR);
	if(!(ai->txt[4]->img = mlx_xpm_file_to_image(ai->mlx,
			"./textures/gold_block.xpm", &ai->size, &ai->size)))
			sys_error(TEXTURE);
	if(!(ai->txt[4]->img_ptr = (int *)mlx_get_data_addr(ai->txt[4]->img,
			&ai->txt[4]->bpp, &ai->txt[4]->sl, &ai->txt[4]->ending)))
			sys_error(IMG_PTR);
	if(!(ai->txt[5]->img = mlx_xpm_file_to_image(ai->mlx,
			"./textures/hay_block_side.xpm", &ai->size, &ai->size)))
			sys_error(TEXTURE);
	if(!(ai->txt[5]->img_ptr = (int *)mlx_get_data_addr(ai->txt[5]->img,
			&ai->txt[5]->bpp, &ai->txt[5]->sl, &ai->txt[5]->ending)))
			sys_error(IMG_PTR);
	if(!(ai->txt[6]->img = mlx_xpm_file_to_image(ai->mlx,
			"./textures/lapis_block.xpm", &ai->size, &ai->size)))
			sys_error(TEXTURE);
}

void	init_textures3(t_dataset *ai)
{
	if(!(ai->txt[6]->img_ptr = (int *)mlx_get_data_addr(ai->txt[6]->img,
			&ai->txt[6]->bpp, &ai->txt[6]->sl, &ai->txt[6]->ending)))
			sys_error(IMG_PTR);
	if(!(ai->txt[7]->img = mlx_xpm_file_to_image(ai->mlx,
			"./textures/stonebrick.xpm", &ai->size, &ai->size)))
			sys_error(TEXTURE);
	if(!(ai->txt[7]->img_ptr = (int *)mlx_get_data_addr(ai->txt[7]->img,
			&ai->txt[7]->bpp, &ai->txt[7]->sl, &ai->txt[7]->ending)))
			sys_error(IMG_PTR);
}