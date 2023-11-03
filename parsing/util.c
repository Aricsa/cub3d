#include "parsing.h"

size_t	ft_strlen(char *s)
{
	size_t i;
	
	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	error_print(char *message)
{
	printf("Error\n%s\n", message);
}
