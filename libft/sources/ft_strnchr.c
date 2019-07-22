/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:33:52 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:33:54 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(const char *s, int c, int n)
{
	char	*str;

	str = (char*)s;
	while (*str != c && n > 0)
	{
		if (*str == '\0')
			return (NULL);
		str++;
		n--;
	}
	return (str);
}
