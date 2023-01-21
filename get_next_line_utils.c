/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:14:05 by ppoti             #+#    #+#             */
/*   Updated: 2023/01/22 00:36:10 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str, int c)
{
	size_t	num;

	num = 0;
	if (!str) // must protect! s1 s2 may be NULL
		return (0);
	while (str[num] != '\0')
	{
		if (str[num] == (char)c && (char)c == '\n')
			return (num);
		num++;
	}
	return (num);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	int		i;
	int		j;


	if (s2 == NULL)
		return (NULL);
	ans = malloc(sizeof(char) * (ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1) // if it's the first reading, s1(empty) won't be read
	{
		while (s1[j] != '\0')
			ans[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		ans[i++] = s2[j++];
	}
	ans[i] = '\0';
	return (ans);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (s1)
		free (s1);
	return (s);
}


char	*ft_strchr(char *str, int s)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)s)
			return (str + i);
		i++;
	}
	return (NULL);
}
