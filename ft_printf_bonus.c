/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:42:43 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/30 07:07:09 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef int(*t_type_func)(va_list);

static t_type_func	ft_get_function_to_closing_char(char c);
static char			*ft_search_valid_closing(char *format);
static char			**ft_split_by_closing_char(char *format);
static int			ft_print_final_str(const char *original, \
										char **format_closing, va_list	args);

int	ft_printf(const char *format, ...)
{
	char	**format_closing;
	va_list	args;
	int		size;

	va_start(args, format);
	format_closing = ft_split_by_closing_char((char *)format);
	size = ft_print_final_str(format, format_closing, args);
	return (size);
}

static t_type_func	ft_get_function_to_closing_char(char c)
{
	size_t		i;
	char		*identificator;
	t_type_func	functions[10];

	identificator = ft_strdup("cspdiuxX%");
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

static char	*ft_search_valid_closing(char *format)
{
	char	*start;
	char	*end;
	char	*format_excerpt;
	char	*ret_chr;

	start = format++;
	end = NULL;
	while (*format)
	{
		ret_chr = ft_strchr("cspdiuxX%", *format);
		if (ret_chr)
			end = ++format;
		if (!ret_chr || *format == '%')
			break ;
	}
	if (!end)
		return (ft_strdup("*"));
	format_excerpt = (char *) malloc((end - start) + 1);
	if (!format_excerpt)
		return (NULL);
	ft_strlcpy(format_excerpt, start, (end - start) + 1);
	return (format_excerpt);
}

static char	**ft_split_by_closing_char(char *format)
{
	char	*format_excerpt;
	char	**arr;
	size_t	i;

	i = 0;
	arr = NULL;
	while (*format)
	{	
		if (*format == '%')
		{
			format_excerpt = ft_search_valid_closing(format);
			arr = ft_realloc((void **) &arr, i, i + 1, sizeof(char *));
			arr[i++] = format_excerpt;
			if (format_excerpt)
			{
				format += ft_strlen(format_excerpt);
				continue ;
			}
		}
		format++;
	}
	arr = ft_realloc((void **) &arr, i, i + 1, sizeof(char *));
	arr[i] = NULL;
	return (arr);
}

static int	ft_print_final_str(const char *original, \
										char **format_closing, va_list	args)
{
	int			i;
	int			len;
	char		*current_closing;
	t_type_func	function;

	i = 0;
	len = 0;
	while (*original)
	{
		if (*original == '%')
		{
			current_closing = format_closing[i++];
			if (current_closing[0] != '*')
			{
				function = ft_get_function_to_closing_char(current_closing[1]);
				len += function(args);
				original += 2;
			}
		}
		ft_putchar_fd(*original, 1);
		len++;
		original++;
	}
	return (len);
}
