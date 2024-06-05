/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:50:12 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/01 10:14:05 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isalpha() function tests for any character for which isupper(3) or 
// islower(3) is true.
int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	return (0);
}
