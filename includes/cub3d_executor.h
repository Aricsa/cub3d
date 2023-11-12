/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_executor.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:39 by junglee           #+#    #+#             */
/*   Updated: 2023/11/12 16:40:42 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EXECUTOR_H
# define CUB3D_EXECUTOR_H

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 1280
# define SCREENHEIGHT 960
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17

typedef struct s_img
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

typedef struct s_event
{
	int	key_a;
	int	key_w;
	int	key_s;
	int	key_d;
	int	key_esc;
	int	key_arrow_r;
	int	key_arrow_l;
}	t_event;

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
	char			**char_map;
	int				**map;
	t_texture_path	textures;
	int				fc_color[2][3];
	char			*texture_path[4];
	char			character_dir;
	int				character_flag;
	int				texture_flag[6];
}	t_parse_var;

typedef struct s_info
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
	int			**texture;
	int			buf[SCREENHEIGHT][SCREENWIDTH];
	double		move_speed;
	double		rot_speed;
	void		*mlx;
	void		*win;
	t_img		img;
	t_event		event;
}	t_info;

// main.c
// int		main_loop(t_info *info);

// event.c
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);

// raycasting_1.c
void	raycasting(t_info *info);
void	init_screen_buf(t_info *info);
void	set_ray_dir(t_info *info, int x);
void	set_slope_dist(t_info *info);

// raycasting_2.c
void	perform_dda(t_info *info);
void	calc_draw_pos(t_info *info);
void	calc_texturing(t_info *info);
void	mapping_texture_color(t_info *info, int x);

// draw
void	draw(t_info *info);

// key_update
void	key_update(t_info *info);

// load_asset.c
int		init_texture(t_info *info);

// util.c
int		create_trgb(int t, int r, int g, int b);
void	calc_rotate_matrix(t_parse_var *player, double theta, \
double old_dir_x, double old_plane_x);

// init.c
void	init_info(t_info *info);
void	init_key_event(t_info *info);
void	init_screen_buf(t_info *info);
void	init_parse(t_parse_var *parse);

#endif