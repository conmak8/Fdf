/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:06:07 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 11:47:17 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The isdigit() function tests for a decimal digit character.  Regardless of
//      locale, this includes the following characters only:

//      ``0''         ``1''         ``2''         ``3''         ``4''
//      ``5''         ``6''         ``7''         ``8''         ``9''
int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}
