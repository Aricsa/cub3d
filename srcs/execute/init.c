/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:26:19 by junglee           #+#    #+#             */
/*   Updated: 2023/11/12 16:40:34 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include <stdlib.h>

void	init_info(t_info *info)
{
	info->re_buf = 0;
	info->move_speed = 0.05;
	info->rot_speed = 0.05;
}

void	init_key_event(t_info *info)
{
	info->event.key_a = 0;
	info->event.key_w = 0;
	info->event.key_s = 0;
	info->event.key_d = 0;
	info->event.key_esc = 0;
	info->event.key_arrow_r = 0;
	info->event.key_arrow_l = 0;
}

void	init_screen_buf(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	if (info->re_buf == 1)
	{
		while (i < SCREENHEIGHT)
		{
			j = 0;
			while (j < SCREENWIDTH)
			{
				info->buf[i][j] = 0;
				j++;
			}
			i++;
		}
	}
}

void	init_parse(t_parse_var *parse)
{
	parse->pos_x = 0;
	parse->pos_y = 0;
	parse->dir_x = 0;
	parse->dir_y = 0;
	parse->map_width = 0;
	parse->map_height = 0;
	parse->character_flag = 0;
	parse->texture_flag[0] = 0;
	parse->texture_flag[1] = 0;
	parse->texture_flag[2] = 0;
	parse->texture_flag[3] = 0;
	parse->texture_flag[4] = 0;
	parse->texture_flag[5] = 0;
	parse->plane_x = 0;
	parse->plane_y = 0;
}
