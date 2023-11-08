#include "parsing.h"

void	is_right_content2(t_parse_var *parse)
{
	if (parse->character_dir == 'N')
	{
		parse->dir_x = -1;
		parse->dir_y = 0;
	}
	else if (parse->character_dir == 'S')
	{
		parse->dir_x = 1;
		parse->dir_y = 0;
	}
	else if (parse->character_dir == 'W')
	{
		parse->dir_x = 0;
		parse->dir_y = -1;
	}
	else if (parse->character_dir == 'E')
	{
		parse->dir_x = 0;
		parse->dir_y = 1;
	}
}

void	is_right_content(t_parse_var *parse, int w, int h)
{
	while (++h < parse->map_height)
	{
		w = -1;
		while (++w < (int)ft_strlen(parse->map[h]))
		{
			if (parse->map[h][w] != '0' && parse->map[h][w] != '1' && \
				parse->map[h][w] != 'N' && parse->map[h][w] != 'S' && \
				parse->map[h][w] != 'W' && parse->map[h][w] != 'E' && \
				parse->map[h][w] != ' ')
				error_print("Weird value in map");
			if (parse->map[h][w] == 'N' || parse->map[h][w] == 'S' || \
				parse->map[h][w] == 'W' || parse->map[h][w] == 'E')
			{
				if (parse->character_flag == 1)
					error_print("Double character direction exists");
				parse->character_flag++;
				parse->character_dir = parse->map[h][w];
				parse->pos_x = w;
				parse->pos_y = h;
			}
		}
	}
	is_right_content2(parse);
}

void	is_surrounded_by_1(t_parse_var *parse, int w, int h)
{
	while (++h < parse->map_height)
	{
		w = -1;
		while (++w < (int)ft_strlen(parse->map[h]))
		{
			if (parse->map[h][w] == 'N' || parse->map[h][w] == 'S' || \
				parse->map[h][w] == 'W' || parse->map[h][w] == 'E' || \
				parse->map[h][w] == '0')
			{
				if (h == 0 || h == parse->map_height - 1 || \
					w == 0 || w == parse->map_width - 1)
					error_print("There is a hole in map");
				if (w > (int)ft_strlen(parse->map[h + 1]) || \
					w > (int)ft_strlen(parse->map[h - 1]))
						error_print("There is a hole in map2");
				if (parse->map[h][w + 1] == '\0' || parse->map[h][w + 1] == '\n' || \
					parse->map[h][w + 1] == ' ' || parse->map[h][w - 1] == ' ' || \
					parse->map[h + 1][w] == ' ' || parse->map[h - 1][w] == ' ')
					error_print("There is a hole in map3");
			}
		}
	}
}

void	set_parse(t_parse_var *parse, int w)
{
	int	i;
	int len;

	i = 0;
	while (parse->map[i] != NULL)
	{
		len = ft_strlen(parse->map[i]);
		if (w < len)
			w = len;
		i++;
	}
	parse->map_width = w;
	parse->map_height = i;
}

void	is_valid_map(t_parse_var *parse)
{
	set_parse(parse, 0);
	is_right_content(parse, -1, -1);
	is_surrounded_by_1(parse, -1, -1);
}
