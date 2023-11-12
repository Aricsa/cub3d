/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:01 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/10 21:25:05 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_fc_atoi(char **char_rgb, int type, t_parse_var *parse)
{
	int		i;
	size_t	j;
	int		k;

	i = -1;
	while (++i < 3)
	{
		j = 0;
		k = 0;
		while (char_rgb[i][j] != '\0')
		{
			if (char_rgb[i][j] >= '0' && char_rgb[i][j] <= '9')
				k = k * 10 + char_rgb[i][j] - '0';
			else if (i == 2 && j != 0 && char_rgb[i][j] == '\n' && \
					char_rgb[i][j + 1] == '\0')
				break ;
			else
				error_print("Weird FC texture RGB");
			if (k >= 256)
				error_print("Out of range RGB");
			j++;
		}
		parse->fc_color[type][i] = k;
	}
	set_fc_atoi_util(parse, type);
}

void	set_fc(char *temp, int type, t_parse_var *parse)
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
	set_fc_atoi(char_rgb, type, parse);
	free(char_rgb[0]);
	free(char_rgb[1]);
	free(char_rgb[2]);
	free(char_rgb);
}

void	get_texture(char *temp, int type, t_parse_var *parse)
{
	int		fd;
	size_t	i;
	char	*temp2;

	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	temp2 = ft_substr_non(temp);
	is_dotid(temp2, ".xpm");
	is_valid_fd(temp2, &fd);
	parse -> texture_path[type] = ft_strdup(temp2);
	if (parse -> texture_flag[type] == 0)
		(parse -> texture_flag[type]++);
	else
		error_print("Double texture declared");
	free(temp2);
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
		set_fc(temp + 2, F, parse);
	else if (ft_strncmp(temp, "C ", 2) == 0)
		set_fc(temp + 2, C, parse);
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
	is_same_texture(parse);
	load_map2(temp, fd, parse);
}
