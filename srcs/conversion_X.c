/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:28:42 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 23:00:27 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr_base_upper(unsigned int n, char *base, int *len)
{
	if (n >= 16)
		ft_putnbr_base_upper(n / 16, base, len);
	*len += write(1, &base[n % 16], 1);
}

int	conversion_hx(va_list args)
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
	ft_putnbr_base_upper(n, "0123456789ABCDEF", &len);
	return (len);
}
