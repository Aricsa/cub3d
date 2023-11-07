/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:26:28 by chbaek            #+#    #+#             */
/*   Updated: 2023/11/07 12:01:19 by chbaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_word_cnt(const char *str, char c)
{
	int	temp;
	int	answer;

	answer = 0;
	temp = 0;
	while (str[temp])
	{
		while (str[temp] && str[temp] == c)
			temp++;
		if (str[temp] != 0)
			answer += 1;
		while (str[temp] && str[temp] != c)
			temp++;
	}
	return (answer);
}

static char	*ft_word_check(const char **str, char c)
{
	char	*answer;
	int		index;
	int		cnt;

	index = 0;
	while (**str && **str == c)
		(*str)++;
	cnt = 0;
	while ((*str)[cnt] && (*str)[cnt] != c)
		cnt += 1;
	while (**str && **str != c)
	{
		if (index == 0)
		{
			answer = safe_malloc(answer, sizeof(char), cnt + 1);
		}
		answer[index] = **str;
		(*str)++;
		index++;
	}
	answer[index] = '\0';
	return (answer);
}

int	ft_listlen(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i += 1;
	return (i + 1);
}

char	**ft_split(const char *str, char c)
{
	char	**answer;
	int		word_cnt;
	int		temp;
	int		temp2;

	word_cnt = ft_word_cnt(str, c);
	answer = NULL;
	answer = safe_malloc(answer, sizeof (char *), word_cnt + 1);
	temp = 0;
	while (temp < word_cnt)
	{
		answer[temp] = ft_word_check(&str, c);
		if (answer[temp] == NULL)
		{
			temp2 = -1;
			while (++temp2 <= temp)
				free(answer[temp2]);
			free(answer);
			return (NULL);
		}
		temp += 1;
	}
	answer[temp] = NULL;
	return (answer);
}
