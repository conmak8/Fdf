/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:15:45 by cmakario          #+#    #+#             */
/*   Updated: 2023/12/30 22:51:24 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_s1_free(char *s1, char const *s2)
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
	free(s1);
	s1 = NULL;
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++ ;
	return (i);
}

/* when our string is gonna end and return also its position */
int	endl_index(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/* return substring before the end of the line */
char	*substr_before_endl(char *tmp)
{
	int		i;
	char	*x;
	int		nl_idx;

	if (!tmp || !tmp[0])
		return (free(tmp), NULL);
	i = 0;
	nl_idx = endl_index(tmp);
	if (nl_idx == -1)
		x = malloc(ft_strlen(tmp) + 1);
	else
		x = malloc(nl_idx + 2);
	while (tmp[i])
	{
		x[i] = tmp[i];
		if (tmp[i] == '\n')
		{
			x[++i] = 0;
			break ;
		}
		i++;
	}
	x[i] = 0;
	return (x);
}

/* return substring after the end of the line in case we have bigger buffer */
char	*substr_after_endl(char *tmp)
{
	int		i;
	int		j;
	int		length;
	char	*x;

	i = endl_index(tmp);
	if (i == -1 || !tmp[i + 1])
		return (free(tmp), NULL);
	i++;
	j = 0;
	length = ft_strlen(tmp);
	if (length == i)
		return (free(tmp), NULL);
	x = malloc(sizeof(char) * (length - (i - 1) + 1));
	while (tmp[i] != '\0')
	{
		x[j] = tmp[i];
		i++;
		j++;
	}
	x[j] = 0 ;
	return (free(tmp), x);
}
