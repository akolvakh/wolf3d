/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:31:56 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:31:57 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//тут цикл и вертушку по записи сразу в нужный буфер?
//(писать сразу значения сюда и в этот буфер?)

#include "wolf3d.h"

int		    count_words(const char *s, char c)
{
	int i;
	int word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			word++;
		if ((s[i] < '0' || s[i] > '4') &&
			s[i] != '\n' && s[i] != '\0' && s[i] != ' ')
			sys_error(VALUE);
		i++;
	}
	if (s[0] != c)
		word++;
	return (word);
}

int		    count_blocks(char *argv)
{
	int		i;
	int		j;
	int		fd;
	int		ret;
	char	*buff;

	if (!(fd = open(argv, O_RDONLY)))
		sys_error(FILE);
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

int         parser(t_dataset *data)
{
	data->tmp = (char **)ft_memalloc(sizeof(char **));
	while ((data->ret = get_next_line(data->fd, &data->buff)) > 0)
	{
		data->l = count_words(data->buff, ' ');
		if (data->a != 0 && data->l != data->a)
			sys_error(MAP);
		data->a = -1;
		free(data->tmp);
		data->tmp = ft_strsplit(data->buff, ' ');
		while (data->tmp[++data->a])
		{
			data->dot[data->cnt].x = data->line;
			data->dot[data->cnt].y = data->a;
			data->dot[data->cnt].z = ft_atoi(data->tmp[data->a]);
			data->cnt++;
			free(data->tmp[data->a]);
		}
		data->a = count_words(data->buff, ' ');
		free(data->buff);
		data->line++;
	}
	free(data->tmp);
	return (data->line);
}
