/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:56 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/10 21:11:49 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_same_texture(t_parse_var *parse)
{
	int	max_len;

	if (parse->fc_color[0][0] == parse->fc_color[1][0] && \
		parse->fc_color[0][1] == parse->fc_color[1][1] && \
		parse->fc_color[0][2] == parse->fc_color[1][2])
		error_print("Floar and ceiling is same color..");
	max_len = max(ft_strlen(parse->texture_path[0]), \
				ft_strlen(parse->texture_path[1]));
	max_len = max(max_len, ft_strlen(parse->texture_path[2]));
	max_len = max(max_len, ft_strlen(parse->texture_path[3]));
	if (ft_strncmp(parse->texture_path[0], \
		parse->texture_path[1], max_len) == 0 || \
		ft_strncmp(parse->texture_path[0], \
		parse->texture_path[2], max_len) == 0 || \
		ft_strncmp(parse->texture_path[0], \
		parse->texture_path[3], max_len) == 0 || \
		ft_strncmp(parse->texture_path[1], \
		parse->texture_path[2], max_len) == 0 || \
		ft_strncmp(parse->texture_path[1], \
		parse->texture_path[3], max_len) == 0 || \
		ft_strncmp(parse->texture_path[2], \
		parse->texture_path[3], max_len) == 0)
		error_print("Some textures are same color..");
}

void	load_map2(char *temp, int fd, t_parse_var *parse)
{
	char	*temp2;

	temp2 = NULL;
	while (temp != NULL)
	{
		if (temp[0] != '\n')
			break ;
		free(temp);
		temp = get_next_line(fd);
	}
	while (temp != NULL)
	{
		if (temp[0] == '\n')
			error_print("There was a newline while reading map");
		temp2 = ft_strjoin(temp2, temp);
		free(temp);
		if (temp2 == NULL)
			error_print("Malloc error");
		temp = get_next_line(fd);
	}
	if (temp2 == NULL)
		error_print("There was no map");
	parse -> char_map = ft_split(temp2, '\n');
	free(temp2);
}
