/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:31:44 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:31:46 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf3d.h"

void	init_textures(t_dataset *ai)
{

	if(!(ai->tx0 = mlx_xpm_file_to_image(ai->mlx, "./textures/eagle.xpm",
			&(ai->tx0_w), &(ai->tx0_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx0 = (int*)mlx_get_data_addr(ai->tx0, &(ai->tx0_bpp),
			&(ai->tx0_sl), &(ai->tx0_end))))
			sys_error(IMG_PTR);


	if(!(ai->tx1 = mlx_xpm_file_to_image(ai->mlx, "./textures/redbrick.xpm",
			&(ai->tx1_w), &(ai->tx1_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx1 = (int*)mlx_get_data_addr(ai->tx1, &(ai->tx1_bpp),
			&(ai->tx1_sl), &(ai->tx1_end))))
			sys_error(IMG_PTR);

	if(!(ai->tx2 = mlx_xpm_file_to_image(ai->mlx, "./textures/purplestone.xpm",
			&(ai->tx2_w), &(ai->tx2_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx2 = (int*)mlx_get_data_addr(ai->tx2, &(ai->tx2_bpp),
			&(ai->tx2_sl), &(ai->tx2_end))))
			sys_error(IMG_PTR);


	if(!(ai->tx3 = mlx_xpm_file_to_image(ai->mlx, "./textures/greystone.xpm",
			&(ai->tx3_w), &(ai->tx3_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx3 = (int*)mlx_get_data_addr(ai->tx3, &(ai->tx3_bpp),
			&(ai->tx3_sl), &(ai->tx3_end))))
			sys_error(IMG_PTR);
	
	if(!(ai->tx4 = mlx_xpm_file_to_image(ai->mlx, "./textures/bluestone.xpm",
			&(ai->tx4_w), &(ai->tx4_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx4 = (int*)mlx_get_data_addr(ai->tx4, &(ai->tx4_bpp),
			&(ai->tx4_sl), &(ai->tx4_end))))
			sys_error(IMG_PTR);

	if(!(ai->tx5 = mlx_xpm_file_to_image(ai->mlx, "./textures/mossy.xpm",
			&(ai->tx5_w), &(ai->tx5_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx5 = (int*)mlx_get_data_addr(ai->tx5, &(ai->tx5_bpp),
			&(ai->tx5_sl), &(ai->tx5_end))))
			sys_error(IMG_PTR);

	if(!(ai->tx6 = mlx_xpm_file_to_image(ai->mlx, "./textures/wood.xpm",
			&(ai->tx6_w), &(ai->tx6_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx6 = (int*)mlx_get_data_addr(ai->tx6, &(ai->tx6_bpp),
			&(ai->tx6_sl), &(ai->tx6_end))))
			sys_error(IMG_PTR);

	if(!(ai->tx7 = mlx_xpm_file_to_image(ai->mlx, "./textures/colorstone.xpm",
			&(ai->tx7_w), &(ai->tx7_h))))
			sys_error(TEXTURE);
	if(!(ai->img_tx7 = (int*)mlx_get_data_addr(ai->tx7, &(ai->tx7_bpp),
			&(ai->tx7_sl), &(ai->tx7_end))))
			sys_error(IMG_PTR);
}

int	main(int argc, char **argv)
{
	t_dataset *ai;

	if (argc < 2)
		sys_message(USAGE);
	if (argc > 2)
		sys_error(INPUT);
	if (argc == 2)
	{
		ai = init_dataset(argv[1]);
		ai->fd = open(argv[1], O_RDONLY);
		if ((ai->row = parser(ai) - 1) < 0)
			sys_error(MAP);
		close(ai->fd);

		init_level(ai);
		validate_level(ai);
		init_textures(ai);
		rdr_display(ai);
	}
}
