/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:52:11 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 15:32:34 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "stdio.h"

// The atoi() function converts the initial portion of the string pointed to 
// by str to int representation.
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// ----------------------CHECK LEAKS TRICK-----------------------------------
/* void check_leaks( void )
{
	system("leaks a.out");
}

// "        -45"
int main(void)
{
	int aa;
	int bb;
	
	atexit(check_leaks);
	char a[]="2334";
	aa = ft_atoi(a);
	bb = atoi(a);
	
	printf("aa= %d\n original= %d\n",aa,bb);

	return (0);
	
	
}*/