/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:27:18 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 03:32:06 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	conversion_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len += write(1, &str[len], 1);
	return (len);
}

/*Prints a string (as defined by the common C convention)" :
	- Affiche une chaîne de caractères terminée par '\0'.
	- Utilise les conventions standard du C pour manipuler des chaînes
	(=tableau de caractères avec un marqueur de fin).
	- Applique des fonctions comme printf*/
