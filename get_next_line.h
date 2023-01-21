/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:46:01 by ppoti             #+#    #+#             */
/*   Updated: 2023/01/22 01:23:51 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	*ft_bzero(void *buffer, size_t len);
char	*ft_cut_line(char *str, int len);
char	*ft_new_start(char	*str, int len);
char	*ft_read(char *buffer, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strchr(char *str, int s);



#endif
