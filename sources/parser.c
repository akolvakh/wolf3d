/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:03:12 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/22 18:00:13 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "fractol.h"

static int		count_words(const char *s, char c)
{
	int i;
	int word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			word++;
		if ((s[i] < '0' || s[i] > '4') && s[i] != '-' && s[i] != '+' &&
			s[i] != '\n' && s[i] != '\0' && s[i] != ' ')
			sys_error(VALUE);
		i++;
	}
	if (s[0] != c)
		word++;
	return (word);
}

static int		blocks_counter(char *argv)
{
	int		i;
	int		j;
	int		fd;
	int		ret;
	char	*buff;

	if (!(fd = open(argv, O_RDONLY)))
		set_error(FILE);
	i = 0;
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		j = count_words(buff, ' ');
		i += j;
		free(buff);
	}
	close(fd);
	return (i);
}

static t_info	*tinfo_init(t_dataset *data,char *argv)
{
	if (!(info = (t_dataset *)ft_memalloc(sizeof(t_dataset))))
		set_error(MALLOC);
	data->meta->amount = blocks_counter(argv);
	info->meta->scale = 2;
	info->meta->projection = 0;
	info->meta->row = 32;
	info->i = 0;
	info->cnt = 0;
	info->line = 0;
	if (!(info->def = (t_dot *)ft_memalloc(sizeof(t_dot) * info->meta->amount)))
		set_error(MALLOC);
	if (!(info->dot = (t_dot *)ft_memalloc(sizeof(t_dot) * info->meta->amount)))
		set_error(MALLOC);
	if (!(info->crd = (t_crd *)ft_memalloc(sizeof(t_crd))))
		set_error(MALLOC);
	return (info);
}

static int		parser(t_info *info)
{
	info->tmp = (char **)ft_memalloc(sizeof(char **));
	while ((info->ret = get_next_line(info->fd, &info->buff)) > 0)
	{
		info->l = count_words(info->buff, ' ');
		if (info->i != 0 && info->l != info->i)
			set_error(MAP);
		info->i = -1;
		free(info->tmp);
		info->tmp = ft_strsplit(info->buff, ' ');
		while (info->tmp[++info->i])
		{
			info->dot[info->cnt].y = info->line;
			info->dot[info->cnt].x = info->i;
			info->dot[info->cnt].z = ft_atoi(info->tmp[info->i]);
			info->cnt++;
			free(info->tmp[info->i]);
		}
		info->i = count_words(info->buff, ' ');
		free(info->buff);
		info->line++;
	}
	free(info->tmp);
	return (info->i);
}

int				main(int argc, char **argv)
{
	t_info *info;

	if (argc != 2)
		set_error(USAGE);
	info = tinfo_init(argv[1]);
	info->fd = open(argv[1], O_RDONLY);
	if ((info->meta->row = parser(info) - 1) < 0)
		set_error(MAP);
	close(info->fd);
	info->cnt = -1;
	while (++info->cnt < info->meta->amount)
	{
		info->def[info->cnt].x = info->dot[info->cnt].x;
		info->def[info->cnt].y = info->dot[info->cnt].y;
		info->def[info->cnt].z = info->dot[info->cnt].z;
	}
	info->mlx_ptr = mlx_init();
	if (!(info->win_ptr = mlx_new_window(info->mlx_ptr, WTH, HTH, argv[1])))
		set_error(WIN);
	set_description(info);
	mlx_key_hook(info->win_ptr, deal_key, info);
	mlx_mouse_hook(info->win_ptr, deal_mouse, info);
	mlx_hook(info->win_ptr, 17, 0, deal_cross, (void *)0);
	mlx_loop(info->mlx_ptr);
	return (0);
}
*/