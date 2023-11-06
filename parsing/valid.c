/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:47:09 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/06 18:47:11 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	load_map(char *name, t_info *game)
{
	int		fd;
	char	*temp;
	char	*temp2;

	game->texture_count = 0;
	is_valid_fd(name, &fd);
	temp = get_next_line(fd);
	if (temp == NULL)
		error_print("No map");
	while (game->texture_count != 6)
	{
		if (temp[0] != '\n')
			is_texture_ok(temp, game);
		free(temp);
		temp = get_next_line(fd);
	}
}

void	get_texture(char *temp, int type, t_info *game)
{
	size_t	i;
	int		fd;

	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	is_valid_fd(temp + i, &fd);
	free(fd);
	(game -> tex_add)[type] = ft_strdup(temp + i);
}

void	is_texture_ok(char *temp, t_info *game)
{

	if (ft_strncmp(temp, "NO", 2) == 0)
		get_texture(temp + 2, NO, game);
	else if (ft_strncmp(temp, "SO", 2) == 0)
		get_texture(temp + 2, SO, game);
	else if (ft_strncmp(temp, "WE", 2) == 0)
		get_texture(temp + 2, WE, game);
	else if (ft_strncmp(temp, "EA", 2) == 0)
		get_texture(temp + 2, EA, game);
}

void	is_valid_map(t_info *game)
{

}
