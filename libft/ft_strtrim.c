/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:04:24 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 21:06:59 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// /**
//  * @brief Allocates with malloc and returns a copy of ’s1’ with the 
//  * characters  specified in ’set’ removed from the beginning and the end 
//  * of the string
//  * @param s1 The string to be trimmed.
//  * @param set The reference set of characters to trim.
//  * @return 	The trimmed string.
// 			NULL if the allocation fails.
//  */
static int	check_rem_char(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (s1 == 0)
		return (ft_strdup(s1));
	if (set == 0)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && check_rem_char(set, s1[i]) == 1)
		i++;
	while (j > i && check_rem_char(set, s1[j]) == 1)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}

// --------------------------------------------------------------------
// Ti ehei grapsei i tipissa!!!!
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	i;

// 	if (!s1 || !set)
// 		return (0);
// 	while (*s1 && ft_strchr(set, *s1))
// 		s1++;
// 	i = ft_strlen(s1);
// 	while (i && ft_strchr(set, s1[i]))
// 		i--;
// 	return (ft_substr(s1, 0, i + 1));
// }