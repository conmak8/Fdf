/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:50:28 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/04 00:10:53 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Finds the maximum and minimum values of x and y coordinates in the given 
 * mesh data.
 *
 * @param mm An array of size 4 to store the maximum and minimum values 
 * of x and y coordinates.
 *           The values are stored in the following order: 
 * [min_x, min_y, max_x, max_y].
 * @param data The mesh data containing the x and y coordinates.
 */
void	find_max_min(float *mm, t_meshfdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->mesh_after[i][j].xf > mm[2])
				mm[2] = data->mesh_after[i][j].xf;
			if (data->mesh_after[i][j].yf > mm[3])
				mm[3] = data->mesh_after[i][j].yf;
			if (data->mesh_after[i][j].xf < mm[0])
				mm[0] = data->mesh_after[i][j].xf;
			if (data->mesh_after[i][j].yf < mm[1])
				mm[1] = data->mesh_after[i][j].yf;
			j++;
		}
		i++;
	}
}

/**
  Calculates the centralization and zoom level for rotation.
 *
 * @param data The meshfdf data.
 * @param window_size The size of the window.
 * @return The calculated midpoint with zoom level.
 */
t_MidPoint	centralize_rotation(t_meshfdf *data, t_window_size window_size)
{
	float		mm[4];
	t_MidPoint	mid;

	mm[0] = 0.0f;
	mm[1] = 0.0f;
	mm[2] = 0.0f;
	mm[3] = 0.0f;
	find_max_min(mm, data);
	if ((mm[2] - mm[0]) / (float)window_size.x >= \
	(mm[3] - mm[1]) / (float)window_size.y)
		mid.zoom = (mm[2] - mm[0]) / (float)window_size.x;
	else
		mid.zoom = (mm[3] - mm[1]) / (float)window_size.y;
	mid.midx = (mm[2] + mm[0]) * 0.5f;
	mid.midy = (mm[3] + mm[1]) * 0.5f;
	mid.zoom *= 1.1f;
	return (mid);
}

/**
 * Returns the decimal value of a hexadecimal digit or a decimal digit.
 * 
 * @param c The character representing the digit.
 * @return The decimal value of the digit, or -1 if the character 
 * is not a valid digit.
 */
int	get_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (c - '0');
	else if (c <= 'f' && c >= 'a')
		return (c - 'a' + 10);
	else if (c <= 'F' && c >= 'A')
		return (c - 'A' + 10);
	else
		return (-1);
}

/**
  Converts a string representation of a hexadecimal number to an integer.
 *
 * @param str The string to convert.
 * @return The converted integer value.
 */
int	atoi_base_hex(char *str)
{
	int	result;
	int	digit;

	result = 0;
	digit = get_digit(*str);
	while (digit >= 0)
	{
		result = result * 16 + digit;
		++str;
		digit = get_digit(*str);
	}
	return (result);
}
