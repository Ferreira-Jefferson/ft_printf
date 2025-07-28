#include "ft_printf.h"

#include <stdio.h>

char	*ft_split_by_close_char(char *format)
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
			break;
	}
	if (!end)
		return (NULL);
	format_excerpt = (char *) malloc((end - start) + 1);
	if (!format_excerpt)
		return (NULL);
	ft_strlcpy(format_excerpt, start, (end - start) + 1);
	printf("Dentro: [%s]\n", format_excerpt);
	return (format_excerpt);
}


char	**ft_validate(char *format)
{
	char *format_excerpt;
	char **arr;
	size_t	i;

	i = 0;
	arr = NULL;
	format_excerpt = NULL;
	while (*format)
	{	
		if (*format == '%')
		{
			format_excerpt = ft_split_by_close_char(format);
			if (!format_excerpt)
				printf("Invalid format.\n");
			else
			{
				arr = ft_realloc((void **) &arr, i, i + 1, sizeof(char *));
				arr[i++] = format_excerpt;
				format += ft_strlen(format_excerpt);
				ft_to_free((void **) &format_excerpt);
				continue ;
			}
		}
		format++;
	}
	arr = ft_realloc((void **) &arr, i, i + 1, sizeof(char *));
	arr[i++] = NULL;
	return (arr);
}
