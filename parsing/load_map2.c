/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:56 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/07 12:30:29 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	load_map2(char *temp, int fd, t_parse_var *parse)
{
	char	*temp2;

	temp2 = NULL;
	while (temp != NULL)
	{
		if (temp[0] != '\n')
			break;
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
	parse -> map = ft_split(temp2, '\n');
	free(temp2);
}
