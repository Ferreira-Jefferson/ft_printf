/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:42:43 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/01 11:52:48 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef int(*t_type_func)(va_list);

static t_type_func	ft_get_function_to_closing_char(char c);
static int			ft_print_final_str(const char *original, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	va_start(args, format);
	size = ft_print_final_str(format, args);
	return (size);
}

static t_type_func	ft_get_function_to_closing_char(char c)
{
	size_t		i;
	char		*identificator;
	t_type_func	functions[10];

	identificator = "cspdiuxX%";
	functions[0] = ft_print_char;
	functions[1] = ft_print_string;
	functions[2] = ft_print_pointer;
	functions[3] = ft_print_int;
	functions[4] = ft_print_int;
	functions[5] = ft_print_unsigned;
	functions[6] = ft_print_hex_lower;
	functions[7] = ft_print_hex_upper;
	functions[8] = ft_print_percent;
	functions[9] = NULL;
	i = 0;
	while (identificator[i])
	{
		if (identificator[i] == c)
			return (functions[i]);
		i++;
	}
	return (NULL);
}

static int	ft_print_final_str(const char *original, va_list	args)
{
	int			i;
	int			len;
	t_type_func	function;

	i = 0;
	len = 0;
	while (*original)
	{
		if (*original == '%' && *(original + 1) != '\0')
		{
			function = ft_get_function_to_closing_char(*(original + 1));
			if (function)
			{
				len += function(args);
				original += 2;
				continue ;
			}				
		}
		ft_putchar_fd(*original, 1);
		len++;
		original++;
	}
	return (len);
}
