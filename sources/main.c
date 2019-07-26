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


	int i;
	int size;

	size = 64;


	i = -1;
	ai->texture = (t_texture **)ft_memalloc(8 * sizeof(t_texture *));
	while (++i < 8)
	{
		ai->texture[i] = (t_texture *) ft_memalloc(sizeof(t_texture));
		ai->texture[i]->img = (void *)ft_memalloc(sizeof(void));
		ai->texture[i]->img_ptr = (int *)ft_memalloc(sizeof(int));
	}






	ai->texture[0]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/eagle.xpm", &size, &size);

	ai->texture[0]->img_ptr = (int *)mlx_get_data_addr(ai->texture[0]->img, &ai->texture[0]->bpp, &ai->texture[0]->sl, &ai->texture[0]->ending);

	ai->texture[1]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/redbrick.xpm",
			&size, &size);
	if(!(ai->texture[1]->img_ptr = (int *)mlx_get_data_addr(ai->texture[1]->img, 
			&ai->texture[1]->bpp, &ai->texture[1]->sl, &ai->texture[1]->ending)))
			sys_error(IMG_PTR);

	ai->texture[2]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/purplestone.xpm",
			&size, &size);
	if(!(ai->texture[2]->img_ptr = (int *)mlx_get_data_addr(ai->texture[2]->img, 
			&ai->texture[2]->bpp, &ai->texture[2]->sl, &ai->texture[2]->ending)))
			sys_error(IMG_PTR);


	ai->texture[3]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/greystone.xpm",
			&size, &size);

	if(!(ai->texture[3]->img_ptr = (int *)mlx_get_data_addr(ai->texture[3]->img, 
			&ai->texture[3]->bpp, &ai->texture[3]->sl, &ai->texture[3]->ending)))
			sys_error(IMG_PTR);
		ft_putendl("HERE");
	ai->texture[4]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/bluestone.xpm",
			&size, &size);

	if(!(ai->texture[4]->img_ptr = (int *)mlx_get_data_addr(ai->texture[4]->img, 
			&ai->texture[4]->bpp, &ai->texture[4]->sl, &ai->texture[4]->ending)))
			sys_error(IMG_PTR);


	ai->texture[5]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/mossy.xpm",
			&size, &size);
	if(!(ai->texture[5]->img_ptr = (int *)mlx_get_data_addr(ai->texture[5]->img, 
			&ai->texture[5]->bpp, &ai->texture[5]->sl, &ai->texture[5]->ending)))
			sys_error(IMG_PTR);

	ai->texture[6]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/wood.xpm",
			&size, &size);

	if(!(ai->texture[6]->img_ptr = (int *)mlx_get_data_addr(ai->texture[6]->img, 
			&ai->texture[6]->bpp, &ai->texture[6]->sl, &ai->texture[6]->ending)))
			sys_error(IMG_PTR);

	ai->texture[7]->img = mlx_xpm_file_to_image(ai->mlx, "./textures/colorstone.xpm",
			&size, &size);

	if(!(ai->texture[7]->img_ptr = (int *)mlx_get_data_addr(ai->texture[7]->img, 
			&ai->texture[7]->bpp, &ai->texture[7]->sl, &ai->texture[7]->ending)))
			sys_error(IMG_PTR);
}

int	main(int argc, char **argv)
{
	t_dataset *ai;

	ai = (t_dataset *)ft_memalloc(sizeof(t_dataset));

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
		rdr_display(ai);


	}
}
