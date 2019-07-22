/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:35:32 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:35:34 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int count;
	int len;

	i = 0;
	count = 0;
	len = 0;
	while (needle[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[count] == haystack[i + count])
		{
			if (count == len - 1)
				return ((char *)haystack + i);
			count++;
		}
		count = 0;
		i++;
	}
	return (0);
}
