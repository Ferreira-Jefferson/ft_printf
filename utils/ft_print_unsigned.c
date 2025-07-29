/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:42:04 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/29 17:54:03 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putunbr_fd(number, 1);
	return (ft_count_decimal_places(number));
}
