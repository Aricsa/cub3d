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

void	*safe_malloc(void *a, size_t typesize, size_t len)
{
	size_t	i;
	size_t	amount;

	if (typesize == 0 || len == 0)
		error_print("TRY TO MALLOC 0");
	amount = typesize * len;
	a = malloc(amount);
	if (a == NULL)
		error_print("MALLOC FAILED");
	i = 0;
	while (i < amount)
		((char *)a)[i++] = '\0';
	return (a);
}
void	error_print(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}
