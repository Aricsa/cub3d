/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:10:31 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/10 16:02:15 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	con_map(t_parse_var *parse)
{
	int	**temp;
	int	i;
	int	j;
	int	len;

	temp = NULL;
	temp = safe_malloc(temp, sizeof(int *), parse->map_height);
	i = -1;
	while (++i < parse->map_height)
	{
		len = ft_strlen(parse->char_map[i]);
		temp[i] = safe_malloc(temp[i], sizeof(int), len);
		j = -1;
		while (++j < len)
			temp[i][j] = parse->char_map[i][j] - '0';
	}
	parse->map = temp;
}
