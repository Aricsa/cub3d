/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:47:04 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/07 11:13:16 by chbaek           ###   ########.fr       */
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
# define F 0
# define C 1

typedef struct s_parse_var
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		map_width;
	int		map_height;
	int		**map;
	int		fc_color[2][3];
	char	*texture_path[4];
	int		texture_flag[6];
}	t_parse_var;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*safe_malloc(void *a, size_t typesize, size_t len);
void	error_print(char *message);
int		ft_isspace(char c);

char	**ft_split(const char *str, char c);

void	is_valid_fd(char *map, int *fd);

void	is_dotcub(char *map_name);
void	load_map(char *name, t_parse_var *parse);
void	load_map2(char *temp, int fd, t_parse_var *parse);
int		texture_count(t_parse_var *parse);
void	is_valid_map(t_parse_var *parse);

#endif