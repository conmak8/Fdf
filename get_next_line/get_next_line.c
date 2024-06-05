/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:15:48 by cmakario          #+#    #+#             */
/*   Updated: 2023/12/31 01:50:03 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <stdio.h>

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	copy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (*str)
	{
		copy[i] = *str;
		i++;
		str++;
	}
	copy[i] = 0;
	return (copy);
}

// void	re_from_tmp(char **tmp, char **re)
// {
// 	*re = substr_before_endl(*tmp);
// 	if (*tmp)
// 		*tmp = substr_after_endl(*tmp);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*tmp = NULL;
// 	char		buffer[BUFFER_SIZE + 1];
// 	char		*re;
// 	size_t		read_size;

// 	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
// 		return (free(tmp), tmp = NULL, NULL);
// 	if (endl_index(tmp) >= 0)
// 		return (re_from_tmp(&tmp, &re), re);
// 	while (endl_index(tmp) < 0)
// 	{
// 		read_size = read(fd, buffer, BUFFER_SIZE);
// 		if (read_size == 0)
// 			break ;
// 		buffer[read_size] = 0;
// 		if (tmp == NULL)
// 			tmp = ft_strdup(buffer);
// 		else
// 			tmp = ft_strjoin_s1_free(tmp, buffer);
// 	}
// 	return (re_from_tmp(&tmp, &re), re);
// }

// ----------how it was before the 25 limitation

char	*get_next_line(int fd)
{
	static char	*tmp = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*re;
	size_t		read_size;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (free(tmp), tmp = NULL, NULL);
	while (endl_index(tmp) < 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		buffer[read_size] = 0;
		if (tmp == NULL)
			tmp = ft_strdup(buffer);
		else
			tmp = ft_strjoin_s1_free(tmp, buffer);
	}
	re = substr_before_endl(tmp);
	if (tmp)
		tmp = substr_after_endl(tmp);
	return (re);
}

// ------wish it could fit also for better implemantation of the code
		// if (read_size < 0)
		// {
		// 	if (tmp)
		// 		free(tmp);
		// 	tmp = NULL;
		// 	return (NULL);
		// }

// logic behind the program
	// if tmp has endl
	//	re = before endl
	//  tmp = after endl
	//  return re;
	// while (no endl in tmp)
	// {	read buffer
	//		tmp = join tmp buffer
	//	}
	//	re = before tmp;
	//  tmp = after tmp;
	//	return re

// Hey Yo way of thinking
// -------------------------------------------------------------
// tmp: stores leftover
// buffer: stores the bytes from read()
// re: the output string

// BUFFER_SIZE=3
// "abcd\ndef\n"
//                  | read  |       | read   | gnl returns |
// tmp    | NULL    |  NULL |  NULL | NULL   | "d"         |
// buffer | garbage | "abc" | "abc" | "d\nd" | "d\nd"      |
// re     | NULL    | NULL  | "abc" | "abc"  | "abcd\n"    |

// 						      | read   | gnl returns |
// tmp    | "d"     | NULL    | NULL   | NULL        |
// buffer | garbage | garabge | "ef\n" | "ef\n"      |
// re     | NULL    | "d"     | "d"    | "def\n"     |

// 		            | gnl returns |
// tmp    | NULL    | NULL |
// buffer | garbage | "\0" |
// re     | NULL    | NULL |

// BUFFER_SIZE=10
// "abcd\ndef\n12345"

//                  | read			 | gnl returns	   |
// tmp    | NULL    | NULL           | "def\n1"       |
// buffer | garbage | "abcd\ndef\n1" | "abcd\ndef\n1" |
// re     | NULL    | NULL           | "abcd\n"       |

// 				     | gnl returns |
// tmp    | "def\n1" | "1"         |
// buffer | garbage  | garbage     |
// re     | NULL     | "def\n"     |

// 				     | gnl returns |
// tmp    | "1"      | NULL        |
// buffer | garbage  | garbage     |
// re     | NULL     | "1"         |

// Cases:

// First: I check the leftover.
//  1. If there is leftover and a newline in it, i return the line 
// and save the rest back to leftover.
//  2. If there is leftover but no newline, I copy it to re and 
// proceed with the rest of the logic.

// Secondly: I read until I reached a new line.
//  1. read
//  2. If there is newline in the buffer,
//  	copy the first part to re and second part to leftover,
// 	return re
//  3. Otherwise append the buffer to re and goes back to 1.

// 1. I starts with a non NULL tmp.
//   -> Append tmp to re
// 2. \n is found in the tmp
//   -> Append the chars before \n (including \n) to re
//   -> If there is chars after \n
// 	-> Saves the char after \n to tmp
//   -> return re

// 3. No \n is found in the buffer
//   -> Append buffer to re
// 4. \n is found in the buffer
//   -> Append the chars before \n (including \n) to re
//   -> If there is chars after \n
// 	-> Saves the char after \n to tmp
//   -> return re

// BUFFER_SIZE=3
// "abcd\ndef\n"

//        | read  |       | read   |           | gnl returns
// tmp    | NULL  | "abc" | "abc"  | "abcd\nd" | "d"
// buffer | "abc" | "abc" | "d\nd" | "d\nd"    | "d\nd"
// re     | NULL  | NULL  | NULL   | NULL      | "abcd\n"
