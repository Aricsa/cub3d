/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dotcub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:55:28 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/09 16:28:29 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_dotid(char *map_name, char *id)
{
	size_t	name_len;

	name_len = ft_strlen(map_name);
	if (name_len >= 5)
	{
		if (map_name[name_len - 1] != id[3] || \
		map_name[name_len - 2] != id[2] || map_name[name_len - 3] != id[1] || \
		map_name[name_len - 4] != id[0])
			error_print("Wrong filename");
		if (map_name[name_len - 5] == '/')
			error_print("Wrong filename");
	}
	else
		error_print("Wrong filename");
}
