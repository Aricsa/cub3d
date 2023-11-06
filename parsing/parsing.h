/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:47:04 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/06 18:51:42 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

typedef struct s_texture_path
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

typedef struct s_game_info{
	void	*mlx;
	void	*win;
	int		map_x;
	int		map_y;
	void	*texture[4];
	int		floar[3];
	int		ceiling[3];
	char	direction;
	char	**map;
	char	*tex_add[4];
	int		texture_flag[6];
}	t_info;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*safe_malloc(void *a, size_t typesize, size_t len);
void	error_print(char *message);
int		ft_isspace(char c);

char	**ft_split(const char *str, char c);

void	is_valid_fd(char *map, int *fd);

void	is_dotcub(char *map_name);
void	load_map(char *name, t_info *game);
void	is_texture_ok(char *line, t_info *game);
void	is_valid_map(t_info *game);
void	init_game(t_info *game);

#endif