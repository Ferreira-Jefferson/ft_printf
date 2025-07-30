/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:36:25 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/30 06:48:25 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(va_list args)
{
	char	*number;
	int		len;

	number = ft_itoa(va_arg(args, int));
	ft_putstr_fd(number, 1);
	len = ft_strlen(number);
	ft_to_free((void **)&number);
	return (len);
}
