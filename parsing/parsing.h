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

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6

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
	int		texture_count;
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