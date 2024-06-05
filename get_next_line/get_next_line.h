/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:15:52 by cmakario          #+#    #+#             */
/*   Updated: 2023/12/31 01:53:13 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* FUNCTIONS OF THE MANDATORY */
// int	is_this_the_end(char *str);

char	*ft_strjoin_s1_free(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		endl_index( char *str);
char	*substr_before_endl(char *tmp);
char	*substr_after_endl(char *tmp);
char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_H