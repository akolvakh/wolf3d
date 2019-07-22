/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:27:07 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:27:09 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd(('-'), fd);
		if (nb <= -10)
			ft_putnbr_fd((nb / -10), fd);
		ft_putchar_fd((-(nb % 10) + 48), fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10 + 48), fd);
	}
	else
		ft_putchar_fd((nb + 48), fd);
}
