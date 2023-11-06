/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dotcub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:55:28 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/06 16:55:40 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_dotcub(char *map_name)
{
	size_t	name_len;

	name_len = ft_strlen(map_name);
	if (name_len >= 5)
	{
		if (map_name[name_len - 1] != 'b' || \
		map_name[name_len - 2] != 'u' || map_name[name_len - 3] != 'c' || \
		map_name[name_len - 4] != '.')
			error_print("Wrong filename");
	}
	else
		error_print("Wrong filename");
}
