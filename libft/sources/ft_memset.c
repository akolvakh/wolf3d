/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:26:08 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:26:10 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)str;
	while (i < n)
	{
		res[i] = (unsigned int)c;
		i++;
	}
	return (res);
}
