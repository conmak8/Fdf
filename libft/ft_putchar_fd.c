/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:26:10 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/01 15:39:02 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the character ’c’ to the given file descriptor.
// c: The character to output.
// fd: The file descriptor on which to write.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
