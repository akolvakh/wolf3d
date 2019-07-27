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
		if ((s[i] < '0' || s[i] > '8') &&
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

int         parser(t_dataset *ai)
{
	ai->tmp = (char **)ft_memalloc(sizeof(char **));
	while ((ai->ret = get_next_line(ai->fd, &ai->buff)) > 0)
	{
		ai->l = count_words(ai->buff, ' ');
		if (ai->a != 0 && ai->l != ai->a)
			sys_error(MAP);
		ai->a = -1;
		free(ai->tmp);
		ai->tmp = ft_strsplit(ai->buff, ' ');
		while (ai->tmp[++ai->a])
		{
			ai->dot[ai->cnt].x = ai->line;
			ai->dot[ai->cnt].y = ai->a;
			ai->dot[ai->cnt].z = ft_atoi(ai->tmp[ai->a]);
			ai->cnt++;
			free(ai->tmp[ai->a]);
		}
		ai->a = count_words(ai->buff, ' ');
		free(ai->buff);
		ai->line++;
	}
	free(ai->tmp);
	return (ai->line);
}

void	init_level(t_dataset *ai)
{
	int i;
	int k;
	int j;
	char numb;
	char *ptr;
	
	i = -1;
	k = 0;
	ai->worldmap = (char **)ft_memalloc(sizeof(char) * ai->l * ai->row);
	while(++i <= ai->row)
		ai->worldmap[i] = (char *)ft_memalloc(sizeof(char*)*ai->l);
	i = 0;
	while(i <= ai->row)
	{
		j = -1;
		while(++j < ai->l)
		{
			ptr = ft_itoa(ai->dot[k].z);
			numb = *ptr;
			ai->worldmap[i][j] = numb;
			k++;
			free(ptr);
		}
		i++;
	}
}

void	validate_level(t_dataset *ai)
{
	int i;
	int j;

	i = 0;
	while(i <= ai->row)
	{
		if(i == 0 || i == ai->row)
		{
			j = 0;
			while (ai->worldmap[i][j])
			{
				if (ai->worldmap[i][j] == '0')
					sys_error(MAP);
				j++;
			}
		}
		if( ai->worldmap[i][0] == '0' || ai->worldmap[i][j - 1] == '0')
			sys_error(MAP);
		i++;
	}
	if (ai-> row < 3)
		sys_error(MAP);
}

