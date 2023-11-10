/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:50:11 by junglee           #+#    #+#             */
/*   Updated: 2023/11/10 00:03:42 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include <math.h>
#include <stdlib.h>

static void	move_ws_pos(t_info *info);
static void	rotate_plane(t_info *info);
static void move_ad_pos(t_info *info);

void	key_update(t_info *info)
{
	move_ws_pos(info);
	move_ad_pos(info);
	rotate_plane(info);
	if (info->event.key_esc)
		exit(0);
}

static void	move_ws_pos(t_info *info)
{
	t_parse_var	*player;

	player = &(info->basic_var);
	if (info->event.key_w)
	{
		if (!player->map[(int)(player->pos_x + player->dir_x * \
		info->move_speed)][(int)(player->pos_y)])
			player->pos_x += player->dir_x * info->move_speed;
		if (!player->map[(int)player->pos_x] \
		[(int)(player->pos_y + player->dir_y * info->move_speed)])
			player->pos_y += player->dir_y * info->move_speed;
	}
	if (info->event.key_s)
	{
		if (!player->map[(int)(player->pos_x - player->dir_x * \
		info->move_speed)][(int)(player->pos_y)])
			player->pos_x -= player->dir_x * info->move_speed;
		if (!player->map[(int)player->pos_x] \
		[(int)(player->pos_y - player->dir_y * info->move_speed)])
			player->pos_y -= player->dir_y * info->move_speed;
	}
}

static void move_ad_pos(t_info *info)
{
	t_parse_var	*player;

	player = &(info->basic_var);
	if (info->event.key_a)
	{
		if (!player->map[(int)(player->pos_x - player->plane_x * \
		info->move_speed)][(int)(player->pos_y)])
			player->pos_x -= player->plane_x * info->move_speed;
		if (!player->map[(int)player->pos_x] \
		[(int)(player->pos_y - player->plane_y * info->move_speed)])
			player->pos_y -= player->plane_y * info->move_speed;
	}
	if (info->event.key_d)
	{
		if (!player->map[(int)(player->pos_x + player->plane_x * \
		info->move_speed)][(int)(player->pos_y)])
			player->pos_x += player->plane_x * info->move_speed;
		if (!player->map[(int)player->pos_x] \
		[(int)(player->pos_y + player->plane_y * info->move_speed)])
			player->pos_y += player->plane_y * info->move_speed;
	}
}

static void	rotate_plane(t_info *info)
{
	t_parse_var	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &(info->basic_var);
	old_dir_x = 0;
	old_plane_x = 0;
	if (info->event.key_arrow_r)
		calc_rotate_matrix(player, info->rot_speed, old_dir_x, old_plane_x);
	if (info->event.key_arrow_l)
		calc_rotate_matrix(player, -info->rot_speed, old_dir_x, old_plane_x);
}