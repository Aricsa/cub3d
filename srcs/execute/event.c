/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:53:05 by junglee           #+#    #+#             */
/*   Updated: 2023/11/11 00:01:20 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_executor.h"
#include <stdlib.h>

#define K_ESC 53
#define K_W 13
#define K_A 0
#define K_S 1
#define K_D 2
#define K_AR_L 123
#define K_AR_R 124

int	key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->event.key_w = 1;
	else if (key == K_A)
		info->event.key_a = 1;
	else if (key == K_S)
		info->event.key_s = 1;
	else if (key == K_D)
		info->event.key_d = 1;
	else if (key == K_AR_L)
		info->event.key_arrow_l = 1;
	else if (key == K_AR_R)
		info->event.key_arrow_r = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->event.key_w = 0;
	else if (key == K_A)
		info->event.key_a = 0;
	else if (key == K_S)
		info->event.key_s = 0;
	else if (key == K_D)
		info->event.key_d = 0;
	else if (key == K_AR_L)
		info->event.key_arrow_l = 0;
	else if (key == K_AR_R)
		info->event.key_arrow_r = 0;
	return (0);
}
