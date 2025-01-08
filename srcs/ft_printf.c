/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:17:20 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 22:51:38 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	if (str == NULL)
		return (-1);
	len = 0;
	va_start(args, str);
	len = ft_parse_str(str, args);
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("Test de ft_printf:\n");
// 	ft_printf("Caractère: %s\n", "");
// 	ft_printf("Chaîne: %s\n", "Bonjour !");
// 	ft_printf("Chaîne: %c   s\n", '\0');
// 	printf("%d\n", ft_printf("Chaîne: %s%s%s       s\n", NULL, NULL, NULL));
// 	ft_printf("Chaîne: %p   s\n", NULL);
// 	ft_printf("Chaîne: %d   s\n", NULL);
// 	ft_printf("Pointeur: %pp%s%%M\n", main, "s");
// 	ft_printf("Pointeur: %p\n", main);
// 	ft_printf("Entier: %d\n", 123);
// 	ft_printf("Entier non signé: %u\n", 123);
// 	ft_printf("Hexadécimal (lower): %x\n", 123);
// 	ft_printf("Hexadécimal (upper): %X\n", 123);
// 	ft_printf("Pourcentage: %%\n");
// 	ft_printf("%");
// 	printf("%d\n", ft_printf(0));
// 	return (0);
// }

// int	main(void)
// {
// 	char	*str;
// 	int		res;
// 	int		re;

// 	str = NULL;
// 	res = ft_printf("The NULL macro represents the %p address\n", ((void *)0));
// 	re = printf("The NULL macro represents the %p address\n", ((void *)0));
// 	printf("%d %d\n", res, re);
// 	return (0);
// }
