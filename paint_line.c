/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:00:54 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/03 08:05:04 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Initializes the line parameters for drawing a line between two pixels.
 *
 * @param a The starting pixel of the line.
 * @param b The ending pixel of the line.
 * @param params Pointer to the line parameters structure.
 */
void	init_line(t_pix a, t_pix b, t_line_Params *params)
{
	params->dx = abs(b.x - a.x);
	params->dy = -abs(b.y - a.y);
	params->err = params->dx + params->dy;
	if (a.x < b.x)
		params->sx = 1;
	else
		params->sx = -1;
	if (a.y < b.y)
		params->sy = 1;
	else
		params->sy = -1;
}

/**
 * Draws a line between two points on the screen.
 *
 * @param data The image data structure.
 * @param a The starting point of the line.
 * @param b The ending point of the line.
 */
void	paint_line(t_imdata *data, t_pix a, t_pix b)
{
	t_line_Params	params;

	init_line(a, b, &params);
	params.len2 = sqrtf((a.x - b.x) * (a.x - b.x) +(a.y - b.y) * (a.y - b.y));
	params.color_diff = b.color - a.color;
	while (1)
	{
		params.len2b = sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * \
			(a.y - b.y));
		my_mlx_pixel_put(data, a.x, a.y, a.color + \
		params.color_diff * params.len2b / params.len2);
		if (a.x == b.x && a.y == b.y)
			break ;
		params.e2 = 2 * params.err;
		if (params.e2 >= params.dy)
		{
			params.err += params.dy;
			a.x += params.sx;
		}
		if (params.e2 <= params.dx)
		{
			params.err += params.dx;
			a.y += params.sy;
		}
	}
}

/**
 * Sets the color of a pixel in an image.
 *
 * @param data The image data structure.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color value of the pixel.
 */
void	my_mlx_pixel_put(t_imdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
