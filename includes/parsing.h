/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:47:04 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/10 21:23:46 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "cub3d_executor.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 0
# define C 1

//	util.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*safe_malloc(void *a, size_t typesize, size_t len);
void	error_print(char *message);
int		ft_isspace(char c);
void	is_valid_fd(char *map, int *fd);

//	util2.c
int		max(int a, int b);

//	ft_split.c
char	**ft_split(const char *str, char c);

//	is_dotcub.c
void	is_dotid(char *map_name, char *id);

//	load_map.c
void	load_map(char *name, t_parse_var *parse);

//	load_map2.c
void	is_same_texture(t_parse_var *parse);
void	load_map2(char *temp, int fd, t_parse_var *parse);

//	load_mad_util.c
char	*ft_substr_non(char *temp);
int		texture_count(t_parse_var *parse);
void	set_fc_atoi_util(t_parse_var *parse, int type);

//	is_valid_map.c
void	is_valid_map(t_parse_var *parse);

//	con_map.c
void	con_map(t_parse_var *parse);

#endif