/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:28:29 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:28:31 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*first;

	first = s1;
	while (*first != '\0')
		first++;
	while (*s2)
		*first++ = *s2++;
	*first = '\0';
	return (s1);
}
