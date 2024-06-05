/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 00:35:48 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 19:10:59 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strdup() function allocates sufficient memory for a copy of the
// string s1, does the copy, and returns a pointer to it.  The pointer may
// subsequently be used as an argument to the function free.
char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*p;

	len = ft_strlen(s1);
	p = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!p)
		return (0);
	else
	{
		while (i < len)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
}
