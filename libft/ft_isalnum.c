/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:12:47 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 12:18:34 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isalnum(int a)
// {
// 	if (ft_isalpha(a) || ft_isdigit(a))
// 		return (1);
// 	return (0);
// }

// The isalnum() function tests for any character for which isalpha(3) or 
// isdigit(3) is true.
int	ft_isalnum(int a)
{
	if (((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) || (a > 47 && a < 58))
		return (1);
	return (0);
}

// return (((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) || 
// (a > 47 && a < 58));