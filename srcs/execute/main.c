/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:52:57 by junglee           #+#    #+#             */
/*   Updated: 2023/11/11 00:08:53 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d_executor.h"
#include "parsing.h"

static int	main_loop(t_info *info);
static void	init_parse(t_parse_var *parse);
static void	map_test(t_info *info);

int	main(int argc, char *argv[])
{
	t_info	info;

	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	info.img.img = mlx_new_image(info.mlx, SCREENWIDTH, SCREENHEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, \
	&info.img.size_l, &info.img.endian);
	if (argc != 2)
		error_print("Wrong argument count");
	is_dotid(argv[1], ".cub");
	init_parse(&(info.basic_var));
	load_map(argv[1], &(info.basic_var));
	is_valid_map(&(info.basic_var));
	con_map(&(info.basic_var));
	init_info(&info);
	init_key_event(&info);
	init_screen_buf(&info);
	if (init_texture(&info) < 0)
		return (1);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_loop(info.mlx);
}

static int	main_loop(t_info *info)
{
	raycasting(info);
	draw(info);
	key_update(info);
	return (0);
}

static void	init_parse(t_parse_var *parse)
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
