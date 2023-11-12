/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:48:51 by junglee           #+#    #+#             */
/*   Updated: 2023/11/12 16:39:39 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include "mlx.h"
#include <stdlib.h>

static void	load_image(t_info *info, int *texture, char *path, t_img *img);
static int	load_texture(t_info *info);

int	init_texture(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	info->texture = (int **)malloc(sizeof(int *) * 4);
	if (!(info->texture))
		return (-1);
	while (++i < 4)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!(info->texture[i]))
			return (-1);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TEXHEIGHT * TEXWIDTH)
			info->texture[i][j] = 0;
	}
	load_texture(info);
	return (0);
}

static void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = -1;
	img->img = mlx_xpm_file_to_image(info->mlx, path, \
	&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
	&img->size_l, &img->endian);
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

static int	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->basic_var.texture_path[0], &img);
	load_image(info, info->texture[1], info->basic_var.texture_path[1], &img);
	load_image(info, info->texture[2], info->basic_var.texture_path[2], &img);
	load_image(info, info->texture[3], \
	info->basic_var.texture_path[3], &img);
}
