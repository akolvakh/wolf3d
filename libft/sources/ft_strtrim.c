/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:35:51 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:35:53 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	while (s[len - 1] && ft_iswhitespace(s[len - 1]))
		len--;
	if (s[i] == '\0')
	{
		str = ft_strsub(s, 0, 0);
		return (str);
	}
	str = ft_strsub(s, i, len - i);
	return (str);
}
