/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:28:32 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 04:14:06 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	put_hex_mini(unsigned int n, char *base, int *len)
{
	if (n >= 16)
		put_hex_mini(n / 16, base, len);
	*len += write(1, &base[n % 16], 1);
}

int	conversion_x(va_list args)
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
	put_hex_mini(n, "0123456789abcdef", &len);
	return (len);
}
