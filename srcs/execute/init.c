/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:26:19 by junglee           #+#    #+#             */
/*   Updated: 2023/11/11 00:03:37 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include <stdlib.h>

static void	init_map(t_info *info);

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

static void	init_map(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		info->basic_var.map[0][i] = 1;
		info->basic_var.map[9][i] = 1;
	}
	i = 0;
	while (++i < 9)
	{
		j = -1;
		while (++j < 10)
		{
			if (j == 0 || j == 9)
				info->basic_var.map[i][j] = 1;
			else
				info->basic_var.map[i][j] = 0;
		}
	}
}
