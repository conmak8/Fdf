/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:02:55 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 13:30:59 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "stdio.h"

static int	find_n_of_digits(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		n = -n;
		counter += 1;
	}
	else if (n == 0)
		counter = 1;
	while (n != 0)
	{
		counter++;
		n = (n / 10);
	}
	return (counter);
}

static char	*smallest_n(void)
{
	char	*smallest_n;

	smallest_n = ft_calloc(12, (sizeof(char)));
	if (!smallest_n)
		return (NULL);
	ft_strlcpy (smallest_n, "-2147483648", 12);
	return (smallest_n);
}

// Allocates (with malloc) and returns a string representing the integer 
// received as an argument. Negative numbers must be handled.
// The string representing the integer. NULL if the allocation fails.
char	*ft_itoa(int n)
{
	int		num_of_dig;
	char	*array_itoa;

	if (n == -2147483648)
		return (smallest_n());
	num_of_dig = find_n_of_digits(n);
	array_itoa = ft_calloc((num_of_dig + 1), sizeof(char));
	if (!array_itoa)
		return (NULL);
	if (n == 0)
		array_itoa[0] = '0';
	if (n < 0)
	{
		n = -n;
		*array_itoa = '-';
	}
	while (n != 0)
	{
		array_itoa[--num_of_dig] = (n % 10) + '0';
		n = n / 10;
	}
	return (array_itoa);
}

// int main (void)
// {
// 	int a = 9;
// 	printf("%s",ft_itoa(a));
// 	return (0);
// }