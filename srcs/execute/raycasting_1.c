/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:03:27 by junglee           #+#    #+#             */
/*   Updated: 2023/11/10 17:21:14 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include <math.h>
#include <stdio.h> // test

void	raycasting(t_info *info)
{
	int	x;

	x = 0;
	if (info->re_buf == 1)
		init_screen_buf(info);
	while (x < SCREENWIDTH)
	{
		set_ray_dir(info, x); // 1. 기본 변수 초기화 (카메라 평면 좌표 구하고 이를통해 광선벡터 설정)
		printf("1\n");
		set_slope_dist(info); // 2. info->step_x, stepy 설정
		printf("1\n");
		perform_dda(info); // 3. DDA 실행
		printf("1\n");
		calc_draw_pos(info); // 4. 벽 거리 계산 및 그리는 지점 계산
		calc_texturing(info); // 5. ㅌㅔㄱ스쳐 비비율율
		mapping_texture_color(info, x);
		x++;
	}
}

void	set_ray_dir(t_info *info, int x)
{
	info->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	info->raydir_x = info->basic_var.dir_x + \
	info->basic_var.plane_x * info->camera_x;
	info->raydir_y = info->basic_var.dir_y + \
	info->basic_var.plane_y * info->camera_x;
	// ..
	info->map_x = (int)info->basic_var.pos_x;
	info->map_y = (int)info->basic_var.pos_y;
	info->delta_dist_x = fabs(1 / info->raydir_x);
	info->delta_dist_y = fabs(1 / info->raydir_y);
	info->hit = 0;
	// printf("----------------------\n");
	// printf("%f %f %f %f %f\n", info->camera_x, info->raydir_x, info->raydir_y, \
	// info->delta_dist_x, info->delta_dist_y);
	// printf("-----------%d----------\n", x);
}

void	set_slope_dist(t_info *info)
{
	if (info->raydir_x < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (info->basic_var.pos_x - info->map_x) \
		* info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - info->basic_var.pos_x) \
		* info->delta_dist_x;
	}
	if (info->raydir_y < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (info->basic_var.pos_y - info->map_y) \
		* info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - info->basic_var.pos_y) \
		* info->delta_dist_y;
	}
}