/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:43:03 by cmakario          #+#    #+#             */
/*   Updated: 2023/10/30 13:14:30 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strrchr() function locates the LAST occurrence of c (converted to a char)
// in the string pointed to by s.  The terminating null character is considered
// to be part of the string;
// therefore if c is `\0', the functions locate the terminating `\0'
// RETURN VALUES
// The functions strchr() and strrchr() return a pointer to the located char,
// or NULL if the character does not appear in the string.
char	*ft_strrchr(const char *s, int c)
{
	int	i ;

	i = ft_strlen(s);
	while (s[i] != (char)c && i > 0)
		i--;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
// #include <string.h>
// #include <stdio.h>

// int main (void)
// {
// 	printf ("%s\n", ft_strchr("teste", 1024));
// 	printf ("%s\n", strchr("teste", 1024));
// }

// Giati sketo (char) hwris asteraki?????
