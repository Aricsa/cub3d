/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:46:49 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/01 17:48:27 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (is_dotcub(argv[1]))
		{
			// if (is_texture_ok())
			// {
			// 	is_valid_map();
			// 		;		//구현부
			// }
			// else
			// 	error_print("Wrong texture value");
		}
		else
			error_print("Wrong filename");
	}
	else
		error_print("Wrong argument count");
	return (0);
}