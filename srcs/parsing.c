/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:15:00 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 04:20:09 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parse_conversion(char str, va_list args)
{
	int	res;

	res = 0;
	if (str == 'c')
		return (conversion_c(args));
	else if (str == 's')
	{
		res = conversion_s(args);
		if (res == -1)
			return (-1);
		return (res);
	}
	else if (str == 'p')
		return (conversion_p(args));
	else if (str == 'd' || str == 'i')
		return (conversion_d(args));
	else if (str == 'u')
		return (conversion_u(args));
	else if (str == 'x')
		return (conversion_x(args));
	else if (str == 'X')
		return (conversion_hx(args));
	else if (str == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_parse_str(const char *str, va_list args)
{
	int	len;
	int	res;

	len = 0;
	res = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				res = parse_conversion(*str, args);
			len += res;
			str++;
		}
		else
		{
			len += write(1, str, 1);
			str++;
		}
	}
	return (len);
}
