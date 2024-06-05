/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:46:58 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 11:50:18 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memmove() function copies len bytes from string src to string dst. The 
// two strings may overlap; the copy is always done in a non-destructive manner.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (b < a)
	{
		while (len > 0)
		{
			len--;
			a[len] = b[len];
		}
	}
	else
		ft_memcpy(a, b, len);
	return (dst);
}
/* 
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *tmp;
	char *dest;

	tmp = (char *)src;
	dest = (char *)dst;
	if (tmp < dest)
	{
		while (n--)
			dest[n] = tmp[n];
	}
	else
		ft_memcpy(dest, tmp, n);
	return (dst);
} */