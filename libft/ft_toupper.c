/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:36:34 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 12:07:09 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The toupper() function converts a lower-case letter to the corresponding 
// upper-case letter.  The argument must be representable as an unsigned char 
// or the value of EOF.
int	ft_toupper(int a)
{
	if (a >= 97 && a <= 122)
	{
		return (a - 32);
	}
	return (a);
}
