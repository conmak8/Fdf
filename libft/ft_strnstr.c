/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:44:22 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 21:06:06 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strnstr() function locates the first occurrence of the null-terminated 
// string needle in the string haystack, where not more than len characters 
// are searched.Characters that appear after a `\0' character are not searched. 
// RETURN VALUES
// If needle is an empty string, haystack is returned; if needle occurs nowhere
// in haystack, NULL is returned; otherwise a pointer to the first character of 
// the first occurrence of needle is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lnee;
	size_t	lhay;
	size_t	i;
	size_t	j;

	lnee = ft_strlen(needle);
	lhay = ft_strlen(haystack);
	i = 0;
	if (lnee == 0)
		return ((char *)(haystack));
	while (i < len && i < lhay)
	{
		j = 0;
		while ((i + j) < len && haystack[i + j] == needle[j]
			&& needle[j] != '\0')
			j++;
		if (j == lnee)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/* char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lnee;
	size_t	lhay;
	size_t	i;
	size_t	j;

	lnee = ft_strlen(needle);
	lhay = ft_strlen(haystack);
	i = 0;
	if (lnee == 0)
		return ((char *)(haystack));
	while (i < len && i < lhay)
	{
		j = 0;
		while (i + j < len && needle[j])
		{
			if (haystack[i + j] == needle[j])
				j++;
		}
		if (j == lnee)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
} */
/* 
int main(void)
{
	char hay[] = "aaxx";
	char nee[] = "xx";
	char *a;
	char *b;
	a = strnstr(hay, nee, 8);
	b = ft_strnstr(hay, nee, 8);
	printf("%s\n%s\n", a, b);
	return (0);
} */