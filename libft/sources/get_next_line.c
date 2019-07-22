/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:36:28 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:36:30 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					verifying_line(char **stack, char **line)
{
	char			*strchr_stack;
	char			*temporary;
	int				j;

	j = 0;
	strchr_stack = *stack;
	while (strchr_stack[j] != '\n')
		if (!strchr_stack[j++])
			return (0);
	temporary = &strchr_stack[j];
	*temporary = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(temporary + 1);
	free(strchr_stack);
	return (1);
}

int					reading_file(int fd, char *buf, char **stack, char **line)
{
	int				out;
	char			*temporary;

	while ((out = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[out] = '\0';
		if (*stack)
		{
			temporary = *stack;
			*stack = ft_strjoin(temporary, buf);
			free(temporary);
		}
		else
			*stack = ft_strdup(buf);
		if (verifying_line(stack, line))
			break ;
	}
	if (out > 0)
		return (1);
	return (out);
}

int					get_next_line(int const fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*buf;
	int				out;
	int				j;

	if (SHORT || !(buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd] && verifying_line(&stack[fd], line))
		return (1);
	j = 0;
	while (j < BUFF_SIZE)
		buf[j++] = '\0';
	out = reading_file(fd, buf, &stack[fd], line);
	free(buf);
	if (out != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!out && *line)
			*line = NULL;
		return (out);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
