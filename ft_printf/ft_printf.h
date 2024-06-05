/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:08:07 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/20 18:55:13 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// /* Structure for counter */
// typedef struct s_count
// {
// 	int		*count;
// }			t_count;

/* FUNCTIONS OF MANDATORY */
int		ft_printf(const char *string, ...);
int		ft_printf_options(char specifier, va_list args);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_digit(long n, int base, int a);
int		ft_print_p(void *data);
int		ft_print_digit2(unsigned long n, unsigned long base, int small_big);
#endif //FT_PRINTF_H
