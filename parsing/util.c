#include "parsing.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*con_s1;
	unsigned char	*con_s2;

	if (n == 0 || s1 == NULL || s2 == NULL)
		error_print("Wrong string input");
	con_s1 = (unsigned char *)s1;
	con_s2 = (unsigned char *)s2;
	while (*con_s1 && *con_s2 && --n > 0)
	{
		if (*con_s1 != *con_s2)
			return (*con_s1 - *con_s2);
		con_s1++;
		con_s2++;
	}
	return (*con_s1 - *con_s2);
}

void	*safe_malloc(void *a, size_t typesize, size_t len)
{
	size_t	i;
	size_t	amount;

	if (typesize == 0 || len == 0)
		error_print("Try to malloc 0");
	amount = typesize * len;
	a = malloc(amount);
	if (a == NULL)
		error_print("Malloc failed");
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

int	ft_isspace(char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}
