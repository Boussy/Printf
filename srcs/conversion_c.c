/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:27:03 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 02:53:26 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	conversion_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

/*
Les types comme char/short sont promus en int dans une fonction variadique
Sans conversion : Si récupere directement un char avec va_arg(args, char),
cela provoquerait un comportement indéfini,
car la promotion automatique en int a déjà eu lieu.
Avec conversion : La conversion explicite (char) garantit de manipulez que
l'information pertinente et ignorez les bits inutiles.*/
