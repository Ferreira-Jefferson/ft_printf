/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:38:02 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/30 12:02:40 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_pointer(va_list args)
{
	char	*hex_ptr;
	int		len;

	hex_ptr = ft_itoa_base(va_arg(args, unsigned long int), "0123456789abcdef");
	if (!hex_ptr)
		return (0);
	if (ft_strlen(hex_ptr) == 1 && *hex_ptr == '0')
	{
		ft_putstr_fd("(nil)", 1);
		ft_to_free((void **)&hex_ptr);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_ptr, 1);
	len = 2 + ft_strlen(hex_ptr);
	ft_to_free((void **)&hex_ptr);
	return (len);
}
