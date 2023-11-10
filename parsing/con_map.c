/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:10:31 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/08 19:38:41 by chbaek           ###   ########.fr       */
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
		len = ft_strlen(parse->map[i]);
		temp[i] = safe_malloc(temp[i], sizeof(int), len);
		j = -1;
		while (++j < len)
			temp[i][j] = parse->map[i][j];
	}
	temp = parse->con_map;
}
