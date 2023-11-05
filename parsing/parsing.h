/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:47:04 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/01 17:52:40 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_game_info{
	void	*mlx;
	void	*win;
	void	*texture[4];
	int		floar[3];
	int		ceiling[3];
	char	direction;
	char	**map;
}	t_info;

size_t	ft_strlen(char *s);
void	error_print(char *message);
int		is_dotcub(char *map_name);
void	*safe_malloc(void *a, size_t typesize, size_t len);


#endif