/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:01 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/07 11:09:27 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_FC_atoi(char **char_rgb, int type, t_parse_var *parse)
{
	int	i;
	size_t	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 3)
	{
		while (char_rgb[i][j] != '\0')
		{
			if (char_rgb[i][j] >= '0' && char_rgb[i][j] <= '9')
				k = k * 10 + char_rgb[i][j] - '0';
			else
				error_print("Weird FC texture RGB");
			if (k >= 256)
				error_print("Out of range RGB");
			j++;
		}
		parse->fc_color[type][i] = k;
		i++;
	}
}

void	set_FC(char *temp, int type, t_parse_var *parse)
{
	size_t	i;
	char	**char_rgb;

	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	char_rgb = ft_split(temp + i, ',');
	i = 0;
	while (char_rgb[i] != NULL)
		i++;
	if (i != 3)
		error_print("FC texture RGB doesn't matches");
	set_FC_atoi(char_rgb, type, parse);
}

void	get_texture(char *temp, int type, t_parse_var *parse)
{
	size_t	i;
	int		fd;

	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	is_valid_fd(temp + i, &fd);
	close(fd);
	parse -> texture_path[type] = ft_strdup(temp + i);
	if (parse -> texture_flag[type] == 0)
		(parse -> texture_flag[type]++);
	else
		error_print("Double texture declared");
}

void	is_texture_ok(char *temp, t_parse_var *parse)
{

	if (ft_strncmp(temp, "NO ", 3) == 0)
		get_texture(temp + 3, NO, parse);
	else if (ft_strncmp(temp, "SO ", 3) == 0)
		get_texture(temp + 3, SO, parse);
	else if (ft_strncmp(temp, "WE ", 3) == 0)
		get_texture(temp + 3, WE, parse);
	else if (ft_strncmp(temp, "EA ", 3) == 0)
		get_texture(temp + 3, EA, parse);
	else if (ft_strncmp(temp, "F ", 2) == 0)
		set_FC(temp + 2, F, parse);
	else if (ft_strncmp(temp, "C ", 2) == 0)
		set_FC(temp + 2, C, parse);
	else
		error_print("Invalid line in element");
}

void	load_map(char *name, t_parse_var *parse)
{
	int		fd;
	char	*temp;

	is_valid_fd(name, &fd);
	temp = get_next_line(fd);
	if (temp == NULL)
		error_print("No map");
	while (texture_count(parse) != 1)
	{
		if (temp[0] != '\n')
			is_texture_ok(temp, parse);
		free(temp);
		temp = get_next_line(fd);
	}
	load_map2(temp, fd, parse);
}
