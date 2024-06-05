/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:30:16 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 20:49:49 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_ar_split(char **ar_split, int i)
{
	while (i >= 0)
	{
		free(ar_split[i]);
		i--;
	}
	free(ar_split);
}

static int	ft_letter_count(char *s, char c)
{
	int	nletters;

	nletters = 0;
	while (s[nletters] && s[nletters] != c)
		nletters++;
	return (nletters);
}

static char	**ft_substring(char const *s, char c, char **ar_split,
						unsigned int nwords)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < nwords)
	{
		while (s[j] != 0 && s[j] == c)
			j++;
		if (s[j] != 0)
		{
			ar_split[i] = ft_substr(s, j, ft_letter_count((char *)&s[j], c));
			if (!ar_split[i])
			{
				free_ar_split(ar_split, i);
				return (NULL);
			}
		}
		while (s[j] != 0 && s[j] != c)
			j++;
		i++;
	}
	ar_split[i] = NULL;
	return (ar_split);
}

static unsigned int	ft_word_count(char const *s, char c)
{
	unsigned int	w_count;
	unsigned int	i;

	i = 0;
	w_count = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			w_count += 1;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (w_count);
}

// Allocates (with malloc) and returns an array of strings obtained by spli-
// tting ’s’ using the character ’c’ as a delimiter. The array must end with a 
// NULL pointer.      	s: The string to be split.
//						c: The delimiter character.
// R: The array of new strings resulting from the split. 
// NULL if the allocation fails.
char	**ft_split(char const *s, char c)
{
	unsigned int	nwords;
	char			**ar_split;

	if (!s)
		return (NULL);
	nwords = ft_word_count(s, c);
	ar_split = ft_calloc(nwords + 1, sizeof(char *));
	if (!ar_split)
		return (NULL);
	ar_split = ft_substring(s, c, ar_split, nwords);
	return (ar_split);
}
