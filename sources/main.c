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
		display(ai);
	}
}
