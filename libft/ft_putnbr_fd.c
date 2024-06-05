/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:26:57 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 19:20:29 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the integer ’n’ to the given file descriptor.
void	ft_putnbr_fd(int n, int fd)
{
	char	num_to_str[12];
	int		digit_n ;
	int		i ;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * (-1);
		}
		i = 0 ;
		while ((n / 10) != 0)
		{
			digit_n = n % 10 ;
			num_to_str[i++] = digit_n + '0';
			n = n / 10 ;
		}
		num_to_str[i] = n + '0';
		while (i >= 0)
			write(fd, &num_to_str[i--], 1);
		return ;
	}
}
