/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:36:25 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/29 17:54:50 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(va_list args)
{
	int	number;

	number = va_arg(args, int);
	ft_putnbr_fd(number, 1);
	return (ft_count_decimal_places(number));
}
