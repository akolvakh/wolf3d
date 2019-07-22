/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:33:39 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:33:41 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*first;
	size_t	i;

	i = -1;
	first = s1;
	while (*first != '\0')
		first++;
	while (*s2 && ++i < n)
		*first++ = *s2++;
	*first = '\0';
	return (s1);
}
