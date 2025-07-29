/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:38:02 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/29 17:55:49 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdint.h>
#include <stdarg.h>

int	ft_print_pointer(va_list args)
{
	char	*hex_ptr;
	int		len;

	hex_ptr = ft_itoa_base(va_arg(args, uintptr_t), "0123456789abcdef");
	if (ft_strlen(hex_ptr) == 1)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_ptr, 1);
	len = 2 + ft_strlen(hex_ptr);
	ft_to_free((void **)&hex_ptr);
	return (len);
}
