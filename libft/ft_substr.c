/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:06:43 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 19:10:00 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
// s: The string from which to create the substring. start: The start index of
// the substring in the string ’s’.
// len: The maximum length of the substring.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*p;
	unsigned int	lenth;

	i = 0;
	lenth = ft_strlen(s);
	if (start > lenth)
		return (ft_strdup(""));
	if ((start <= lenth) && (len <= (lenth - start)))
		p = (char *)malloc((len + 1) * sizeof(char));
	else
	{
		p = (char *)malloc((lenth - start) * sizeof(char) + 1);
		len = (lenth - start);
	}
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	size_t	length = ft_strlen(s);

	// Check if the start index is out of bounds
	if (start >= length)
		return (ft_strdup(""));

	// Adjust len to ensure it doesn't exceed the available characters
	if (len > length - start)
		len = length - start;

	// Allocate memory for the substring with space for the null-terminator
	p = (char *)malloc((len + 1) * sizeof(char));

	if (!p)
		return (0);

	// Copy characters from the original string to the substring
	for (i = 0; i < len; i++)
		p[i] = s[start + i];

	// Null-terminate the new substring
	p[len] = '\0';

	return (p);
} */
