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

void	rdr_geometry(t_dataset *ai)
{
	ai->img_wall = (int*)mlx_get_data_addr(ai->img, &(ai->wall_bpp),
		&(ai->wall_sl), &(ai->wall_end));
	ai->x = -1;
	while (++ai->x < ai->w)
	{
		ray(ai);//change
		check_raydirx(ai);
		check_raydiry(ai);
		check_distance(ai);//change
		visualization(ai);//change
		texturation(ai);
		bitmapping(ai);
		draw_floor(ai);
	}
}

void	rdr_player(t_dataset *ai)
{
	if (ai->control_up == 0 || ai->control_down == 0)
	{
		while (ai->coof < 600)
			ai->coof = ai->coof + 150;
		while (ai->coof > 600)
			ai->coof = ai->coof - 150;
	}
	mlx_put_image_to_window(ai->mlx, ai->win, ai->wep_right, 1200, ai->coof);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->wep_left, 10, ai->coof);
}

void	rdr_interface(t_dataset *ai)
{
	mlx_put_image_to_window(ai->mlx, ai->win, ai->img, 0, 0);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->menu, 0, 0);
	//mlx_put_image_to_window(ai->mlx, ai->win, ai->skybox, 0, 0);//

}

void	rdr_pipeline(t_dataset *ai)
{
	mlx_destroy_image(ai->mlx, ai->img);
	if(!(ai->img = mlx_new_image(ai->mlx, WDT, HGT)))
		sys_error(ai, IMG);
	rdr_geometry(ai);
	rdr_interface(ai);
	rdr_player(ai);
}

void	rdr_display(t_dataset *ai)
{
	if (ai->checker == 1)
		rdr_pipeline(ai);
	else
	{
		mlx_put_image_to_window(ai->mlx, ai->win, ai->start_img, 0, 0);
		ai->checker = 1;
	}
	mlx_loop_hook(ai->mlx, key_controllers, ai);
	mlx_loop(ai->mlx);
}
