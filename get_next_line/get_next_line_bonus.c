/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:15:48 by cmakario          #+#    #+#             */
/*   Updated: 2023/12/31 02:06:56 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <stdio.h>

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	copy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (*str)
	{
		copy[i] = *str;
		i++;
		str++;
	}
	copy[i] = 0;
	return (copy);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*re;
	size_t		read_size;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (free(tmp[fd]), tmp[fd] = NULL, NULL);
	while (endl_index(tmp[fd]) < 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		buffer[read_size] = 0;
		if (tmp[fd] == NULL)
			tmp[fd] = ft_strdup(buffer);
		else
			tmp[fd] = ft_strjoin_s1_free(tmp[fd], buffer);
	}
	re = substr_before_endl(tmp[fd]);
	if (tmp[fd])
		tmp[fd] = substr_after_endl(tmp[fd]);
	return (re);
}
