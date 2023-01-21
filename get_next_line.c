/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:56 by ppoti             #+#    #+#             */
/*   Updated: 2023/01/22 02:10:38 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_bzero(void *buffer, size_t len)
// {
// 	size_t			i;
// 	unsigned char	*b;

// 	i = 0;
// 	b = buffer;
// 	while (i < len)
// 	{
// 		b[i] = '\0';
// 		i++;
// 	}
// 	return (b);
// }

char	*ft_cut_line(char *str, int len) //! don't you dare touching this
{
	char	*line;
	// int		len;
	int		i;
	// int		mode;

	if (!str)
		return (NULL);
	// len = ft_strlen(str, '\n'); // len with '\n'
	if (ft_strchr(str, '\n'))
		len++;
	line = malloc(sizeof(char) * (len + 1));
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
	// int		len_n;

	// if (ft_strchr(str, '\n') != NULL) // cannot be this bc if EOF has '\n', it won't return NULL
	//* check if there's '\n' and no '\n'
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
		// buffer = ft_memset(buffer, 0, BUFFER_SIZE + 1);
		// buffer = ft_bzero(buffer, BUFFER_SIZE + 1);
		num = read(fd, buffer, BUFFER_SIZE);
		if (num <= 0)
			break;
		buffer[num] = '\0';
		str = ft_strjoin_free(str, buffer);
		if (ft_strchr(str, '\n'))
			break;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*next;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	next = NULL;
	line = NULL;
	// printf("\n*==>str:%s*\n", str);
	if (str != NULL) // if it reached until here, it means str either has '\n' or EOF
	{
		len = ft_strlen(str, '\n');
		line = ft_cut_line(str, len);
		str = ft_new_start(str, len);
		// printf("=>str after move:%s<=\n", str);
	}
	return (line);
}


// int main(void)
// {
// 	int	fd;
// 	char	*str;

// 	fd = open("newwy", O_RDONLY);
// 	// fd = open("testing", O_RDONLY);

// 	for (int i = 0; i < 4; i++)
// 	{

// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 	}
// 	close(fd);
// }

