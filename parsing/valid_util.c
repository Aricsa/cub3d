/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:10:31 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/06 16:37:35 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_valid_fd(char *map, int *fd)
{
	*fd = open(map, O_RDONLY);
	if (*fd < 0)
		error_print("Open failed");
}


