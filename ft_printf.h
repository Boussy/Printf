/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:17:52 by bferdjan          #+#    #+#             */
/*   Updated: 2024/12/08 23:00:28 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

// Prototypes des fonctions
int	ft_parse_str(const char *str, va_list args);
int	ft_printf(const char *str, ...);
int	parse_conversion(char str, va_list args);

// Fonctions de conversion
int	conversion_c(va_list args);
int	conversion_s(va_list args);
int	conversion_p(va_list args);
int	conversion_d(va_list args);
int	conversion_i(va_list args);
int	conversion_u(va_list args);
int	conversion_x(va_list args);
int	conversion_hx(va_list args);
int	conversion_o(va_list args);

#endif
