/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:31:54 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/29 17:57:06 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex_lower(va_list args)
{
	char	*hex_ptr;
	int		len;

	hex_ptr = ft_itoa_base(va_arg(args, unsigned long), "0123456789abcdef");
	ft_putstr_fd(hex_ptr, 1);
	len = ft_strlen(hex_ptr);
	ft_to_free((void **)&hex_ptr);
	return (len);
}
