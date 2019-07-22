/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:35:04 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:35:05 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;

	if (*needle == '\0')
		return ((char *)haystack);
	count = ft_strlen(needle);
	while (*haystack != '\0' && count <= len--)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, count) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
