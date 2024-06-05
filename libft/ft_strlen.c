/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:51:31 by cmakario          #+#    #+#             */
/*   Updated: 2023/10/30 14:08:28 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strlen() function computes the length of the string s.  The strnlen() 
// function attempts to compute the length of s, but never scans beyond the 
// first maxlen bytes of s.
// RETURN VALUES
// The strlen() function returns the number of characters that precede the 
// terminating NUL character.
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++ ;
	return (i);
}
// int main()
// {
//     // defining string
//     char str[] = "GeeksforGeeks";
//     // getting length of str using strlen()
//     int length = ft_strlen(str);
//     printf("Length of string is : %d", length);
//     return 0;
// }