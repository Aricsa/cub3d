/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_executor.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:39 by junglee           #+#    #+#             */
/*   Updated: 2023/11/06 18:52:11 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EXECUTOR_H
#define CUB3D_EXECUTOR_H

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define RED 0x00FF0000
#define BLUE 0x000000FF
#define GREEN 0x0000FF00

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_textuer_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture_path;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;


typedef struct s_parse_var
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				map_width;
	int				map_height;
	int				**map;
	t_color			floor_color;
	t_color			cell_color;
	t_texture_path	textures;
}	t_parse_var;

typedef	struct s_info
{
	t_parse_var	basic_var;
	int			re_buf;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			texture_color;
	int			**buf;
	double		move_speed;
	double		rot_speed;
}	t_info;


# endif