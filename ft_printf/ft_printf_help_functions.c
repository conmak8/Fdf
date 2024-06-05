/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:07:13 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/27 16:50:44 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * it's called chain because i transform the value of a function
 * into a "boolean" one
*/
int	chain_result(int *count, int parser_result)
{
	if (parser_result == -1)
		return (EXIT_FAILURE);
	else
	{
		*count += parser_result;
		return (EXIT_SUCCESS);
	}
}
/**
 * @brief How a || b works:
 * 
 * If a = 0 => 0 || b, b will run
 * If a = 1 => 1 || b, because "1 || anything" is going to be 1 anyway,
 * so it won't run b.
 */

int	ft_print_digit(long n, int base, int small_big)
{
	int		count;
	char	*symbols;
	char	*symbols_cap;

	symbols = "0123456789abcdef";
	symbols_cap = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_print_digit(-n, base, 0) + 1);
	}
	else if (n < base && small_big == 0)
		return (ft_print_char(symbols[n]));
	else if (n < base && small_big == 1)
		return (ft_print_char(symbols_cap[n]));
	else
	{
		if (chain_result(&count, ft_print_digit(n / base, base, small_big)) || \
			chain_result(&count, ft_print_digit(n % base, base, small_big)))
			return (-1);
		return (count);
	}
}
		// int temp_count;
		// temp_count = ft_print_digit(n / base, base, small_big);
		// if (temp_count == -1)
		// 	return (-1);
		// count += temp_count;
		// temp_count = ft_print_digit(n % base, base, small_big);
		// if (temp_count == -1)
		// 	return (-1);
		// count += temp_count;

int	ft_print_digit2(unsigned long n, unsigned long base, int small_big)
{
	int		count;
	char	*symbols;
	char	*symbols_cap;

	symbols = "0123456789abcdef";
	symbols_cap = "0123456789ABCDEF";
	count = 0;
	if (n < base && small_big == 0)
		return (ft_print_char(symbols[n]));
	else if (n < base && small_big == 1)
		return (ft_print_char(symbols_cap[n]));
	else
	{
		if (chain_result(&count, ft_print_digit2(n / base, base, small_big)) || \
			chain_result(&count, ft_print_digit2(n % base, base, small_big)))
			return (-1);
		return (count);
	}
}
		// count = ft_print_digit2(n / base, base, small_big);
		// if (count == -1)
		// 	return (-1);
		// return (count + ft_print_digit2(n % base, base, small_big));

int	ft_print_p(void *data)
{
	int		count;

	if (data == NULL)
		return (write(1, "0x0", 3));
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = 2;
	if (chain_result(&count, ft_print_digit2((unsigned long)data, 16, 0)))
		return (-1);
	return (count);
}
