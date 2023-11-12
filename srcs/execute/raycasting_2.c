/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:39:39 by junglee           #+#    #+#             */
/*   Updated: 2023/11/12 16:42:16 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include "parsing.h"
#include <math.h>

#define WALL_X 0
#define WALL_Y 1

void	perform_dda(t_info *info)
{
	while (info->hit == 0)
	{
		if (info->side_dist_x < info->side_dist_y)
		{
			info->side_dist_x += info->delta_dist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->side_dist_y += info->delta_dist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (info->basic_var.map[info->map_x][info->map_y] == 1)
			info->hit = 1;
	}
	if (info->side == 0)
		info->perp_wall_dist = (info->map_x - info->basic_var.pos_x + \
		(1 - info->step_x) / 2) / info->raydir_x;
	else
		info->perp_wall_dist = (info->map_y - info->basic_var.pos_y + \
		(1 - info->step_y) / 2) / info->raydir_y;
}

void	calc_draw_pos(t_info *info)
{
	info->line_height = (int)(SCREENHEIGHT / info->perp_wall_dist);
	info->draw_start = -info->line_height / 2 + SCREENHEIGHT / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_height / 2 + SCREENHEIGHT / 2;
	if (info->draw_end >= SCREENHEIGHT)
		info->draw_end = SCREENHEIGHT - 1;
	if (info->side == WALL_X)
	{
		if (info->raydir_x > 0)
			info->tex_num = NO;
		else
			info->tex_num = SO;
	}
	else if (info->side == WALL_Y)
	{
		if (info->raydir_y > 0)
			info->tex_num = WE;
		else
			info->tex_num = EA;
	}
}

void	calc_texturing(t_info *info)
{
	if (info->side == 0)
		info->wall_x = info->basic_var.pos_y + info->perp_wall_dist \
		* info->raydir_y;
	else
		info->wall_x = info->basic_var.pos_x + info->perp_wall_dist \
		* info->raydir_x;
	info->wall_x -= floor(info->wall_x);
	info->tex_x = (int)(info->wall_x * (double)TEXWIDTH);
	if (info->side == 0 && info->raydir_x > 0)
		info->tex_x = TEXWIDTH - info->tex_x - 1;
	if (info->side == 1 && info->raydir_y < 0)
		info->tex_x = TEXWIDTH - info->tex_x - 1;
}

void	mapping_texture_color(t_info *info, int x)
{
	int	y;

	y = info->draw_start;
	info->step = 1.0 * TEXHEIGHT / info->line_height;
	info->tex_pos = (info->draw_start - SCREENHEIGHT / 2 + \
					info->line_height / 2) * info->step;
	while (y < info->draw_end)
	{	
		info->tex_y = (int)info->tex_pos & (TEXHEIGHT - 1);
		info->tex_pos += info->step;
		info->texture_color = \
		info->texture[info->tex_num][TEXHEIGHT * info->tex_y + info->tex_x];
		if (info->side == 1)
			info->texture_color = (info->texture_color >> 1) & 8355711;
		info->buf[y][x] = info->texture_color;
		y++;
	}
	info->re_buf = 1;
}
