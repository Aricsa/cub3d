/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:01 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/06 18:53:25 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_FC(char *temp, int type, t_info *game)
{
	size_t	i;

	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	// 구조체 맞추기/
}

void	get_texture(char *temp, int type, t_info *game)
{
	size_t	i;
	int		fd;

	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	is_valid_fd(temp + i, &fd);
	close(fd);
	(game -> tex_add)[type] = ft_strdup(temp + i);
	(game -> texture_flag[type]++);
}

void	is_texture_ok(char *temp, t_info *game)
{

	if (ft_strncmp(temp, "NO ", 3) == 0)
		get_texture(temp + 3, NO, game);
	else if (ft_strncmp(temp, "SO ", 3) == 0)
		get_texture(temp + 3, SO, game);
	else if (ft_strncmp(temp, "WE ", 3) == 0)
		get_texture(temp + 3, WE, game);
	else if (ft_strncmp(temp, "EA ", 3) == 0)
		get_texture(temp + 3, EA, game);
	else if (ft_strncmp(temp, "F ", 2) == 0)
		set_FC(temp + 2, F, game);
	else if (ft_strncmp(temp, "C ", 2) == 0)
		set_FCw(temp + 2, C, game);
}

void	load_map(char *name, t_info *game)
{
	int		fd;
	char	*temp;
	char	*temp2;

	game->texture_flag[0] = 0;
	game->texture_flag[1] = 0;
	game->texture_flag[2] = 0;
	game->texture_flag[3] = 0;
	game->texture_flag[4] = 0;
	game->texture_flag[5] = 0;
	is_valid_fd(name, &fd);
	temp = get_next_line(fd);
	if (temp == NULL)
		error_print("No map");
	while (texture_count(game) != 1)
	{
		if (temp[0] != '\n')
			is_texture_ok(temp, game);
		free(temp);
		temp = get_next_line(fd);
	}
	while (temp != NULL)
	{
		if (temp[0] == '\n')
		{
			free(temp);
			temp = get_next_line(fd);
		}
		else
			break;
	}
	while (temp != NULL)
	{
		if (temp[0] == '\n')
			error_print("There was a newline while reading map");
		temp2 = ft_strjoin(temp2, temp);
		free(temp);
		if (temp2 == 0)
			error_print("Malloc error");
		temp = get_next_line(fd);
	}
	game -> map = ft_split(temp2, '\n');
	free(temp2);
	if (game -> map == NULL)
		error_print("Malloc error");
}
