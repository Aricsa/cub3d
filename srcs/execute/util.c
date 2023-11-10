/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:41:00 by junglee           #+#    #+#             */
/*   Updated: 2023/11/08 16:01:31 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include <math.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	calc_rotate_matrix(t_parse_var *player, double theta, \
double old_dir_x, double old_plane_x)
{
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-theta) - player->dir_y * sin(-theta);
	player->dir_y = old_dir_x * sin(-theta) + player->dir_y * cos(-theta);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-theta) - \
	player->plane_y * sin(-theta);
	player->plane_y = old_plane_x * sin(-theta) + player->plane_y * cos(-theta);
}
