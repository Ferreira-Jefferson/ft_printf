/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:42:04 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/30 07:28:13 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(va_list args)
{
	char	*number;
	int		len;

	number = ft_itoa_base(va_arg(args, unsigned int), "0123456789");
	ft_putstr_fd(number, 1);
	len = ft_strlen(number);
	ft_to_free((void **)&number);
	return (len);
}
