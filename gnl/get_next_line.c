/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:12:21 by chbaek            #+#    #+#             */
/*   Updated: 2023/03/31 20:03:02 by chbaek           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*result;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	result = malloc(sizeof(char) * (s1_len + 1));
	if (!result)
		return (0);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

void	free_buf(char **buf)
{
	if (*buf)
		free(*buf);
	*buf = NULL;
}

void	split_buf(char **buf, int result_len)
{
	char	*new_buf;
	char	*temp;
	int		buf_len;
	int		i;

	buf_len = ft_strlen(*buf);
	if (buf_len != result_len + 1)
	{	
		new_buf = malloc(sizeof(char) * (buf_len - result_len));
		if (!new_buf)
			return (free_buf(buf));
		i = 0;
		while ((*buf)[i + result_len + 1] != '\0')
		{
			new_buf[i] = (*buf)[i + result_len + 1];
			i++;
		}
		new_buf[i] = '\0';
		temp = *buf;
		*buf = new_buf;
		free(temp);
	}
	else
		free_buf(buf);
}

char	*make_result(char **buf)
{
	char	*result;
	int		result_len;

	result = NULL;
	result_len = ft_strchr(*buf, '\n');
	if (result_len == -1)
	{
		result = ft_strdup(*buf);
		free_buf(buf);
	}
	else
	{
		result = malloc(sizeof(char) * (result_len + 2));
		if (!result)
		{
			free_buf(buf);
			return (NULL);
		}
		ft_strlcpy(result, *buf, result_len + 2);
		split_buf(buf, result_len);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static char	read_block[BUFFER_SIZE + 1];
	ssize_t		read_number;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_number = read(fd, read_block, BUFFER_SIZE);
	while (read_number > 0)
	{
		read_block[read_number] = '\0';
		buf = ft_strjoin(buf, read_block);
		if (!buf || ft_strchr(read_block, '\n') != -1)
			break ;
		read_number = read(fd, read_block, BUFFER_SIZE);
	}
	if (read_number < 0 || !buf)
	{
		free_buf(&buf);
		return (NULL);
	}
	return (make_result(&buf));
}
