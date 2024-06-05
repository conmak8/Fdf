/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 04:01:02 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 11:43:56 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The bzero() function writes n zeroed bytes to the string s.  
// If n is zero, bzero() does nothing.
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)s ;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			a[i] = 0 ;
			i++;
		}
	}
	else
		return ;
}
