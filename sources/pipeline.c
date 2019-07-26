/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:32:01 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:32:02 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_geometry(t_dataset *ai)
{
	ai->img_wall = (int*)mlx_get_data_addr(ai->img, &(ai->wall_bpp),
		&(ai->wall_sl), &(ai->wall_end));
	ai->x = -1;
	while (++ai->x < ai->w)
	{
		ray(ai);//change
		drawstuff2(ai);//change
		drawstuff3(ai);//change
		visualization(ai);//change
	}
}

void	render_player(t_dataset *ai)
{
	ai->coof = 600;
	ai->wep_right = mlx_xpm_file_to_image(ai->mlx, "./textures/sword_right.xpm",
			&(ai->wep_right_w), &(ai->wep_right_h));
	ai->img_wep_right = (int*)mlx_get_data_addr(ai->wep_right, &(ai->wep_right_bpp),
			&(ai->wep_right_sl), &(ai->wep_right_end));
	ai->wep_left = mlx_xpm_file_to_image(ai->mlx, "./textures/sword_left.xpm",
			&(ai->wep_left_w), &(ai->wep_left_h));
	ai->img_wep_left = (int*)mlx_get_data_addr(ai->wep_left, &(ai->wep_left_bpp),
			&(ai->wep_left_sl), &(ai->wep_left_end));
	if (ai->control_up == 1 || ai->control_down == 1)
	{
		while (ai->coof < 650)
			ai->coof += 25;
		while (ai->coof > 650)
			ai->coof -= 25;
	}
	mlx_put_image_to_window(ai->mlx, ai->win, ai->wep_right, 1200, ai->coof);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->wep_left, 10, ai->coof);
}

void	render_interface(t_dataset *ai)
{
	ai->ceil = mlx_xpm_file_to_image(ai->mlx, "./textures/ceil.xpm",
			&(ai->ceil_w), &(ai->ceil_h));
	ai->img_ceil = (int*)mlx_get_data_addr(ai->ceil, &(ai->ceil_bpp),
			&(ai->ceil_sl), &(ai->ceil_end));
	ai->floor = mlx_xpm_file_to_image(ai->mlx, "./textures/floor.xpm",
			&(ai->floor_w), &(ai->floor_h));
	ai->img_floor = (int*)mlx_get_data_addr(ai->floor, &(ai->floor_bpp),
			&(ai->floor_sl), &(ai->floor_end));
	ai->menu = mlx_xpm_file_to_image(ai->mlx, "./textures/gui.xpm",
			&(ai->menu_w), &(ai->menu_h));
	ai->img_menu = (int*)mlx_get_data_addr(ai->menu, &(ai->menu_bpp),
			&(ai->menu_sl), &(ai->menu_end));
	mlx_put_image_to_window(ai->mlx, ai->win, ai->ceil, 0, 0);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->floor, 0, 400);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->img, 0, 0);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->menu, 0, 0);
}

void	rendering(t_dataset *ai)
{
	mlx_destroy_image(ai->mlx, ai->img);
	ai->img = mlx_new_image(ai->mlx, WDT, HGT);
	render_geometry(ai);
	render_interface(ai);
	render_player(ai);
}

void	display(t_dataset *ai)
{
	ai->mlx = mlx_init();
	if (!(ai->win = mlx_new_window(ai->mlx, WDT, HGT, "Wolf3D")))
		sys_error(WIN);
	ai->img = mlx_new_image(ai->mlx, WDT, HGT);
	rendering(ai);
	mlx_loop_hook(ai->mlx, key_controllers, ai);
	mlx_loop(ai->mlx);
}
