/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:46:49 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/06 18:45:34 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int argc, char *argv[])
{
	t_info	*game;

	game = NULL;
	game = safe_malloc(game, sizeof(t_info), 1);
	game -> mlx = mlx_init();
	if (argc != 2)
		error_print("Wrong argument count");
	is_dotcub(argv[1]);
	load_map(argv[1], game);
	is_valid_map(game);
	
	//구현부

	return (0);
}