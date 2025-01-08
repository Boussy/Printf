/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:28:22 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 04:13:48 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr(unsigned int n, int *len)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10, len);
	c = (char)(n % 10 + '0');
	write(1, &c, 1);
	(*len)++;
}

int	conversion_u(va_list args)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbr(n, &len);
	return (len);
}
