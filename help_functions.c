/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:01:15 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/03 06:03:43 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Converts the integer values of a t_pix struct to floating-point values.
 * 
 * @param data The t_pix struct containing the integer values to be converted.
 */
void	int_to_float(t_pix *data)
{
	data->xf = (float)data->x;
	data->yf = (float)data->y;
	data->zf = (float)data->z;
}

/**
 * Converts the floating-point values of a t_pix struct to integers.
 * 
 * @param data The t_pix struct containing the floating-point values 
 * to be converted.
 */
void	float_to_int(t_pix *data)
{
	data->x = (int)data->xf;
	data->y = (int)data->yf;
	data->z = (int)data->zf;
}

/**
 * Rotates a point `a` around the x-axis by an angle `theta` 
 * and stores the result in `b`.
 *
 * @param a     The point to be rotated.
 * @param b     Pointer to the resulting rotated point.
 * @param theta The angle of rotation in radians.
 */
void	rotate_x(t_pix a, t_pix *b, float theta)
{
	b->yf = a.yf * cosf(theta) - a.zf * sinf(theta);
	b->zf = a.yf * sinhf(theta) + a.zf * cosf(theta);
	b->xf = a.xf;
}

/**
 * Rotates a point around the y-axis by a given angle.
 *
 * @param a The original point to be rotated.
 * @param b Pointer to the rotated point.
 * @param theta The angle of rotation in radians.
 */

void	rotate_y(t_pix a, t_pix *b, float theta)
{
	b->xf = a.xf * cosf(theta) + a.zf * sinf(theta);
	b->zf = -a.xf * sinf(theta) + a.zf * cosf(theta);
	b->yf = a.yf;
}

/**
 * Rotates a point around the z-axis by a given angle.
 *
 * @param a The original point to be rotated.
 * @param b Pointer to the rotated point.
 * @param theta The angle of rotation in radians.
 */

void	rotate_z(t_pix a, t_pix *b, float theta)
{
	b->xf = a.xf * cosf(theta) - a.yf * sinf(theta);
	b->yf = a.xf * sinf(theta) + a.yf * cosf(theta);
	b->zf = a.zf;
}
