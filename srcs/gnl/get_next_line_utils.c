/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:12:23 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/06 17:23:17 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *read_block, int enter)
{
	int	i;

	i = 0;
	while (read_block[i] != '\0')
	{
		if (read_block[i] == enter)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while (src[i] && (dstsize - dst_len - 1 - i))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
	{
		free(s1);
		s1 = NULL;
		return (0);
	}
	result[0] = '\0';
	ft_strlcpy(result, s1, s1_len + 1);
	free(s1);
	ft_strlcat(result, s2, s1_len + s2_len + 1);
	return (result);
}
