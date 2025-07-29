/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:39:27 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/29 17:56:56 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(va_list args);
int	ft_print_hex_lower(va_list args);
int	ft_print_hex_upper(va_list args);
int	ft_print_int(va_list args);
int	ft_print_percent(va_list args);
int	ft_print_pointer(va_list args);
int	ft_print_string(va_list args);
int	ft_print_unsigned(va_list args);

#endif