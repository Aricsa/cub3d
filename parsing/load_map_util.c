/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:57:24 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/07 10:58:00 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_substr_non(char *temp)
{
	size_t	i;
	char	*temp2;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			break ;
		i++;
	}
	if (!temp[i])
		return NULL;
	temp2 = NULL;
	temp2 = safe_malloc(temp2, sizeof(char), i + 1);
	i = 0;
	while (temp[i] != '\n')
	{
		temp2[i] = temp[i];
		i++;
	}
	temp2[i] = '\0';
	return (temp2);
}

int		texture_count(t_parse_var *parse)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (parse->texture_flag[i] != 1)
			return 0;
		i++;
	}
	return 1;
}