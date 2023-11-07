/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:46:49 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/07 11:13:04 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_parse(t_parse_var *parse)
{
	parse->pos_x = 0;
	parse->pos_y = 0;
	parse->dir_x = 0;
	parse->dir_y = 0;
	parse->map_width = 0;
	parse->map_height = 0;
	parse->texture_flag[0] = 0;
	parse->texture_flag[1] = 0;
	parse->texture_flag[2] = 0;
	parse->texture_flag[3] = 0;
	parse->texture_flag[4] = 0;
	parse->texture_flag[5] = 0;
}

int main(int argc, char *argv[])
{
	t_parse_var	*parse;

	parse = NULL;
	parse = safe_malloc(parse, sizeof(t_parse_var), 1);
	if (argc != 2)
		error_print("Wrong argument count");
	is_dotcub(argv[1]);
	init_parse(parse);
	load_map(argv[1], parse);
	is_valid_map(parse);
	
	//구현부

	return (0);
}