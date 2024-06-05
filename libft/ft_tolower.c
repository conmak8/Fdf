/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:58:04 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 12:06:08 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The tolower() function converts an upper-case letter to the corresponding 
// lower-case letter. The argument must be representable as an unsigned char or
//  the value of EOF.
int	ft_tolower(int a)
{
	if (a >= 65 && a <= 90)
	{
		a += 32 ;
	}
	return (a);
}
