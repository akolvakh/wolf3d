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

int	main(int argc, char **argv)
{
	t_dataset *data;

	if (argc < 2)
		sys_message(USAGE);
	if (argc > 2)
		sys_error(INPUT);
	if (argc == 2)
	{
		data = init_dataset(argv[1]);
		data->fd = open(argv[1], O_RDONLY);
		if ((data->row = parser(data) - 1) < 0)
			sys_error(MAP);
		close(data->fd);
		init_level(data);
		display(data);
	}
}
