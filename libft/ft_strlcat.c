/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:18:37 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 11:57:47 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strlcpy() and strlcat() functions copy and concatenate strings 
// strlcat() appends string src to the end of dst.  It will append at most 
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
// dstsize is 0 or the original dst string was longer than dstsize 
// (in practice this should not happen as it means that either dstsize is 
// incorrect or that dst is not a proper string).
// If the src and dst strings overlap, the behavior is undefined.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	x;

	i = 0;
	if (dstsize == 0 || dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	y = ft_strlen(dst);
	x = ft_strlen(dst);
	while (y < (dstsize - 1) && src[i] != '\0')
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (x + ft_strlen(src));
}

/* #include <stdio.h>
#include <string.h>

void test(int size)
{
	char string[] = "Hello there, Venus";
	char buffer[19];
	int r;

	r = strlcpy(buffer,string,size);

	printf("Copied '%s' into '%s', length %d\n",
			string,
			buffer,
			r
		  );
}

int main()
{
	test(19);
	test(10);
	test(1);
	test(0);

	return(0);
}  */