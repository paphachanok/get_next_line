/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:56 by ppoti             #+#    #+#             */
/*   Updated: 2023/01/22 03:02:20 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_bzero(void *buffer, size_t len)
{
	size_t			i;
	unsigned char	*b;

	i = 0;
	b = buffer;
	while (i < len)
	{
		b[i] = '\0';
		i++;
	}
	return (b);
}

char	*ft_cut_line(char *str, int len)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n'))
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		line[i] = str[i];
		i++;
		len--;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_start(char	*str, int len_n)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str, '\0');
	if (len_n + 1 >= len)
	{
		free(str);
		return (NULL);
	}
	else
	{
		tmp = str;
		str = ft_strjoin_free(NULL, (str + len_n + 1));
		free (tmp);
	}
	return (str);
}

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	int		num;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	num = 1;
	while (num > 0)
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num <= 0)
			break ;
		buffer[num] = '\0';
		str = ft_strjoin_free(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	str[fd] = ft_read(str[fd], fd);
	line = NULL;
	if (str[fd] != NULL)
	{
		len = ft_strlen(str[fd], '\n');
		line = ft_cut_line(str[fd], len);
		str[fd] = ft_new_start(str[fd], len);
	}
	return (line);
}

/*
int main(void)
{
	int	fd;
	char	*str;

	fd = open("newwy", O_RDONLY);
	fd = open("testing", O_RDONLY);

	for (int i = 0; i < 4; i++)
	{

		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
}
*/
