/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:26:19 by junglee           #+#    #+#             */
/*   Updated: 2023/11/10 16:13:53 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include <stdlib.h>
# include <stdio.h>

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
	for (int i = 0; i < 10; i++)
	{
		info->basic_var.map[0][i] = 1;
		info->basic_var.map[9][i] = 1;
	}
	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0 || j == 9)
				info->basic_var.map[i][j] = 1;
			else
				info->basic_var.map[i][j] = 0;
		}
	}
}

