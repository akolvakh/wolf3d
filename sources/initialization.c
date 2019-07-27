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
	ai->control_up = 0;
	ai->control_down = 0;
	ai->control_left = 0;
	ai->control_right = 0;
	ai->rotspeed = .4;
	ai->movespeed = .4;
	ai->amount = count_blocks(argv);
	ai->row = 0;
	ai->a = 0;
	ai->cnt = 0;
	ai->line = 0;
	ai->coof = 600;
	ai->dot = (t_dot *)ft_memalloc(sizeof(t_dot) * ai->amount);
	ai->texture_mod = 0;
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
	init_textures(ai);
}

void	init_textures(t_dataset *ai) //4 textures
{
	int i;
	int size;

	size = 64;
	i = -1;
	ai->texture = (t_texture **)ft_memalloc(8 * sizeof(t_texture *));
	while (++i < 8)
		ai->texture[i] = (t_texture *) ft_memalloc(sizeof(t_texture));

	if(!(ai->texture[0]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/crafting_table_side.xpm", &size, &size)))
				sys_error(TEXTURE);
	ai->texture[0]->img_ptr = (int *)mlx_get_data_addr(ai->texture[0]->img, &ai->texture[0]->bpp, &ai->texture[0]->sl, &ai->texture[0]->ending);



	if(!(ai->texture[1]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/sandstone_top.xpm", &size, &size)))
				sys_error(TEXTURE);
	if(!(ai->texture[1]->img_ptr = (int *)mlx_get_data_addr(ai->texture[1]->img, 
			&ai->texture[1]->bpp, &ai->texture[1]->sl, &ai->texture[1]->ending)))
			sys_error(IMG_PTR);



	if(!(ai->texture[2]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/furnace_side.xpm", &size, &size)))
			sys_error(TEXTURE);
	if(!(ai->texture[2]->img_ptr = (int *)mlx_get_data_addr(ai->texture[2]->img, 
			&ai->texture[2]->bpp, &ai->texture[2]->sl, &ai->texture[2]->ending)))
			sys_error(IMG_PTR);


	if(!(ai->texture[3]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/glowstone.xpm", &size, &size)))
			sys_error(TEXTURE);
	if(!(ai->texture[3]->img_ptr = (int *)mlx_get_data_addr(ai->texture[3]->img, 
			&ai->texture[3]->bpp, &ai->texture[3]->sl, &ai->texture[3]->ending)))
			sys_error(IMG_PTR);

	if(!(ai->texture[4]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/gold_block.xpm", &size, &size)))
			sys_error(TEXTURE);
	if(!(ai->texture[4]->img_ptr = (int *)mlx_get_data_addr(ai->texture[4]->img, 
			&ai->texture[4]->bpp, &ai->texture[4]->sl, &ai->texture[4]->ending)))
			sys_error(IMG_PTR);


	if(!(ai->texture[5]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/hay_block_side.xpm", &size, &size)))
			sys_error(TEXTURE);
	if(!(ai->texture[5]->img_ptr = (int *)mlx_get_data_addr(ai->texture[5]->img, 
			&ai->texture[5]->bpp, &ai->texture[5]->sl, &ai->texture[5]->ending)))
			sys_error(IMG_PTR);

	if(!(ai->texture[6]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/lapis_block.xpm", &size, &size)))
			sys_error(TEXTURE);
	if(!(ai->texture[6]->img_ptr = (int *)mlx_get_data_addr(ai->texture[6]->img, 
			&ai->texture[6]->bpp, &ai->texture[6]->sl, &ai->texture[6]->ending)))
			sys_error(IMG_PTR);

	if(!(ai->texture[7]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/stonebrick.xpm", &size, &size)))
			sys_error(TEXTURE);
	if(!(ai->texture[7]->img_ptr = (int *)mlx_get_data_addr(ai->texture[7]->img, 
			&ai->texture[7]->bpp, &ai->texture[7]->sl, &ai->texture[7]->ending)))
			sys_error(IMG_PTR);
}
