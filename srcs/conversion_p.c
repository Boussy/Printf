/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:27:38 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 04:28:09 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_put_hex(unsigned long long n, char *base, int *len)
{
	if (n >= 16)
		ft_put_hex(n / 16, base, len);
	*len += write(1, &base[n % 16], 1);
}

int	conversion_p(va_list args)
{
	unsigned long long	ptr;
	int					len;

	len = 0;
	ptr = (unsigned long long)va_arg(args, void *);
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	if (!ptr)
		len += write(1, "0", 1);
	else
		ft_put_hex(ptr, "0123456789abcdef", &len);
	return (len);
}
