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