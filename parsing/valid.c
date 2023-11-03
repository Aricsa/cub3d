#include "parsing.h"

int	is_dotcub(char *map_name)
{
	size_t	name_len;

	name_len = ft_strlen(map_name);
	if (name_len >= 5)
	{
		if (map_name[name_len - 1] != 'b' || \
		map_name[name_len - 2] != 'u' || map_name[name_len - 3] != 'c' || \
		map_name[name_len - 4] != '.')
			return (0);
	}
	else
		return (0);
	return (1);
}

int	is_texture_ok()
{
	return 0;
}
