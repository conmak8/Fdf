/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:43:41 by cmakario          #+#    #+#             */
/*   Updated: 2023/10/30 12:54:38 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new string, which is the result of 
// the concatenation of ’s1’ and ’s2’.
// s1: The prefix string.
// s2: The suffix string.
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*p;
	int		i;

	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	p = (char *)malloc(((lens1 + lens2) + 1) * sizeof(char));
	if (!p)
		return (0);
	while (i < (lens1 + lens2))
	{
		if (i < lens1)
			p[i] = s1[i];
		else
			p[i] = s2[i - lens1];
		i++;
	}
	p[i] = '\0';
	return (p);
}
