/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:48:56 by junglee           #+#    #+#             */
/*   Updated: 2023/11/11 00:00:31 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include "mlx.h"

static void	draw_wall(t_info *info);
static void	draw_floor(t_info *info);
static void	draw_ceiling(t_info *info);

void	draw(t_info *info)
{
	draw_floor(info);
	draw_wall(info);
}

static void	draw_wall(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			info->img.data[y * SCREENWIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

static void	draw_floor(t_info *info)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;
	int	color;

	x = 0;
	floor_color = create_trgb(0, info->basic_var.fc_color[0][0], \
	info->basic_var.fc_color[0][1], info->basic_var.fc_color[0][2]);
	ceiling_color = create_trgb(0, info->basic_var.fc_color[1][0], \
	info->basic_var.fc_color[1][1], info->basic_var.fc_color[1][2]);
	while (x < SCREENWIDTH)
	{
		y = 0;
		color = ceiling_color;
		while (y < SCREENHEIGHT)
		{
			if (info->buf[y][x] == 0)
				info->buf[y][x] = color;
			else
				color = floor_color;
			y++;
		}
		x++;
	}
}

static void	draw_ceiling(t_info *info)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	color = BLUE;
	while (x < SCREENWIDTH)
	{
		y = 0;
		while (y < SCREENHEIGHT / 2)
		{
			mlx_pixel_put(info->mlx, info->win, x, y, color);
			y++;
		}
		x++;
	}
}
