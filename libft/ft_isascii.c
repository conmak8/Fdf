/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:40:48 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 11:46:27 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isascii() function tests for an ASCII character, which is any character
// between 0 and octal 0177 inclusive.
int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}
