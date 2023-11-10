/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:13:22 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/10 21:16:58 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_right_content2(t_parse_var *parse)
{
	if (parse->character_dir == 'N')
	{
		parse->dir_x = -1;
		parse->plane_y = 0.66;
	}
	else if (parse->character_dir == 'S')
	{
		parse->dir_x = 1;
		parse->plane_y = -0.66;
	}
	else if (parse->character_dir == 'W')
	{
		parse->dir_y = -1;
		parse->plane_x = -0.66;
	}
	else if (parse->character_dir == 'E')
	{
		parse->dir_y = 1;
		parse->plane_x = 0.66;
	}
}

void	is_right_content(t_parse_var *parse, int w, int h)
{
	while (++h < parse->map_height)
	{
		w = -1;
		while (++w < (int)ft_strlen(parse->char_map[h]))
		{
			if (parse->char_map[h][w] != '0' && parse->char_map[h][w] != '1' && \
				parse->char_map[h][w] != 'N' && parse->char_map[h][w] != 'S' && \
				parse->char_map[h][w] != 'W' && parse->char_map[h][w] != 'E' && \
				parse->char_map[h][w] != ' ')
				error_print("Weird value in map");
			if (parse->char_map[h][w] == 'N' || parse->char_map[h][w] == 'S' || \
				parse->char_map[h][w] == 'W' || parse->char_map[h][w] == 'E')
			{
				if (parse->character_flag == 1)
					error_print("Double character direction exists");
				parse->character_flag++;
				parse->character_dir = parse->char_map[h][w];
				parse->pos_x = h;
				parse->pos_y = w;
				parse->char_map[h][w] = '0';
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
		while (++w < (int)ft_strlen(parse->char_map[h]))
		{
			if (parse->char_map[h][w] == 'N' || parse->char_map[h][w] == 'S' || \
				parse->char_map[h][w] == 'W' || parse->char_map[h][w] == 'E' || \
				parse->char_map[h][w] == '0')
			{
				if (h == 0 || h == parse->map_height - 1 || \
					w == 0 || w == parse->map_width - 1)
					error_print("There is a hole in map : type1");
				if (w >= (int)ft_strlen(parse->char_map[h + 1]) || \
					w >= (int)ft_strlen(parse->char_map[h - 1]))
					error_print("There is a hole in map : type2");
				if (parse->char_map[h][w + 1] == '\0' || \
					parse->char_map[h][w + 1] == '\n' || \
					parse->char_map[h][w + 1] == ' ' || \
					parse->char_map[h][w - 1] == ' ' || \
					parse->char_map[h + 1][w] == ' ' || \
					parse->char_map[h - 1][w] == ' ')
					error_print("There is a hole in map : type3");
			}
		}
	}
}

void	set_parse(t_parse_var *parse, int w)
{
	int	i;
	int	len;

	i = 0;
	while (parse->char_map[i] != NULL)
	{
		len = ft_strlen(parse->char_map[i]);
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
