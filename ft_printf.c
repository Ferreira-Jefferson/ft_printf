#include "ft_printf.h"

#include <stdio.h>

char *split_format(char *format)
{
	char	*start;
	char	*end;
	char	*close_char;
	char	*format_excerpt;

	close_char = ft_strdup("cspdiuxX%");
	if (!close_char)
		return (NULL);
	start = NULL;
	end = NULL;
	while(*format)
	{
		if (!start && *format == '%')
			start = *format++;
		if (start && ft_strchr(close_char, *format))
			end = *format;
		format++;
	}
	free(close_char);
	if (!end)
		return (NULL);
	format_excerpt = (char *) malloc((end - start) + 1);
	if (!format_excerpt)
		return (NULL);
	ft_strlcpy(format_excerpt, start, (end - start) + 1);
	printf("%s\n", format_excerpt);
	return (format_excerpt);
}
int ft_validate(char *format, char **split_format)
{
	int i = 0;
	char *format_excerpt;

	split_format = ft_split(format, '%');
	while (split_format[i])
	{
		
		i++;
	}
	return (1);
}