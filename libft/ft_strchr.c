/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:43:03 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 19:04:36 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function locates the first occurrence of c (converted to a char)
// in the string pointed to by s.  The terminating null character is considered
// to bepart of the string; therefore if c is `\0', the functions locate the 
// terminating `\0'.
char	*ft_strchr(const char *s, int c)
{
	int	i ;

	i = 0 ;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++ ;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int main (void)
// {
// 	printf ("%s\n", ft_strchr("teste", 1024));
// 	printf ("%s\n", strchr("teste", 1024));
// }
// fed
