/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:46:47 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/01 10:23:16 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isprint() function tests for any printing character, 
// including space (` ')
int	ft_isprint(int a)
{
	if (a >= 040 && a <= 0176)
		return (1);
	return (0);
}
