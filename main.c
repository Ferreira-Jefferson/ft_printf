#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char **arr = ft_validate(" %csp %% %sd%daf%awef %dddd ");

	int i = 0;
	while (arr)
	{
		printf("[%s]\n", arr[i]);
		arr++;
		i++;
	}

	return (0);
}