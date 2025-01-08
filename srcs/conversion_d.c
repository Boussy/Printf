/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:27:50 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 22:50:39 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr_d(int nb, int *len)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		(*len)++;
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_d(nb / 10, len);
	}
	c = (char)(nb % 10 + '0');
	write(1, &c, 1);
	(*len)++;
}

int	conversion_d(va_list args)
{
	int	n;
	int	len;

	len = 0;
	n = va_arg(args, int);
	ft_putnbr_d(n, &len);
	return (len);
}
