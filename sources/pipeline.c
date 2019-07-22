


#include "wolf3d.h"

void	render_geometry(t_dataset *data)
{
	data->img_wall = (int*)mlx_get_data_addr(data->img, &(data->wall_bpp),
		&(data->wall_sl), &(data->wall_end));
	data->x = -1;
	printf("I AM HERE\n");
	while (++data->x < data->w)
	{
		drawstuff1(data);//change
		drawstuff2(data);//change
		drawstuff3(data);//change
		drawstuff4(data);//change
	}
}

void	render_player(t_dataset *data)
{
	int num;

	num = 600;
	data->wep_right = mlx_xpm_file_to_image(data->mlx, "./textures/sword_right.xpm",
			&(data->wep_right_w), &(data->wep_right_h));
	data->img_wep_right = (int*)mlx_get_data_addr(data->wep_right, &(data->wep_right_bpp),
			&(data->wep_right_sl), &(data->wep_right_end));
	data->wep_left = mlx_xpm_file_to_image(data->mlx, "./textures/sword_left.xpm",
			&(data->wep_left_w), &(data->wep_left_h));
	data->img_wep_left = (int*)mlx_get_data_addr(data->wep_left, &(data->wep_left_bpp),
			&(data->wep_left_sl), &(data->wep_left_end));
	if (data->upkey == 1 || data->downkey == 1)
	{
		while (num < 650)
			num += 25;
		while (num > 650)
			num -= 25;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->wep_right, 1200, num);
	mlx_put_image_to_window(data->mlx, data->win, data->wep_left, 10, num);
}

void	render_interface(t_dataset *data)
{
	data->ceil = mlx_xpm_file_to_image(data->mlx, "./textures/ceil.xpm",
			&(data->ceil_w), &(data->ceil_h));
	data->img_ceil = (int*)mlx_get_data_addr(data->ceil, &(data->ceil_bpp),
			&(data->ceil_sl), &(data->ceil_end));
	data->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",
			&(data->floor_w), &(data->floor_h));
	data->img_floor = (int*)mlx_get_data_addr(data->floor, &(data->floor_bpp),
			&(data->floor_sl), &(data->floor_end));
	data->menu = mlx_xpm_file_to_image(data->mlx, "./textures/gui.xpm",
			&(data->menu_w), &(data->menu_h));
	data->img_menu = (int*)mlx_get_data_addr(data->menu, &(data->menu_bpp),
			&(data->menu_sl), &(data->menu_end));
	mlx_put_image_to_window(data->mlx, data->win, data->ceil, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->floor, 0, 400);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->menu, 0, 0);
}

void	rendering(t_dataset *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	render_geometry(data);
	render_interface(data);
	render_player(data);
}

void	display(t_dataset *data)
{
	data->mlx = mlx_init();
	if (!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Wolf3D")))
		sys_error(WIN);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	//init_dataset(*data);
	printf("TEST3\n");
	rendering(data);
	mlx_loop_hook(data->mlx, key_controllers, data);
	mlx_loop(data->mlx);

}
