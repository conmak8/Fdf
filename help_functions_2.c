/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:46:02 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/03 23:15:19 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Translates the coordinates of a pixel using the given midpoint 
 * and zoom factor.
 * 
 * @param b     Pointer to the pixel to be translated.
 * @param mid   The midpoint and zoom factor used for translation.
 */
void	translate_xy(t_pix *b, t_MidPoint mid, t_window_size window_size)
{
	b->xf = (b->xf - mid.midx) / mid.zoom + (float)window_size.x / 2;
	b->yf = (b->yf - mid.midy) / mid.zoom + (float)window_size.y / 2;
}

/**
 * Centralizes the mesh by translating each point to the center of rotation.
 * 
 * @param data The pointer to the t_meshfdf structure containing the mesh data.
 */
void	centralize(t_meshfdf *data, t_window_size window_size)
{
	t_MidPoint	mid;
	int			i;
	int			j;

	i = 0;
	mid = centralize_rotation(data, window_size);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			translate_xy(&data->mesh_after[i][j], mid, window_size);
			float_to_int(&(data->mesh_after[i][j]));
			j++;
		}
		i++;
	}
}

/**
 * Rotates the mesh in the XYZ plane by the given angles.
 *
 * @param data The mesh data structure.
 * @param alpha The rotation angle around the X-axis.zz
 * @param beta The rotation angle around the Y-axis.
 * @param theta The rotation angle around the Z-axis.
 */
void	rotate_xyz(t_meshfdf *data, t_vars vars, t_window_size	window_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			rotate_x(data->mesh[i][j], &(data->mesh_after[i][j]), vars.rot_x);
			rotate_y(data->mesh_after[i][j], &(data->mesh_after[i][j]), \
			vars.rot_y);
			rotate_z(data->mesh_after[i][j], &(data->mesh_after[i][j]), \
			vars.rot_z);
			j++;
		}
		i++;
	}
	centralize(data, window_size);
}

/**
 * Handles key press events.
 * 
 * @param keycode The keycode of the pressed key.
 * @param vars The main variables struct.
 * @return Returns 0 if the keycode is not 53 (ESC), otherwise exits the program.
 */
int	key_press(int keycode, t_main_vars *vars)
{
	int	i;

	if (keycode != 53)
		return (0);
	i = -1;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	while (++i < vars->data->height)
	{
		free(vars->data->z_coordinates[i]);
		free(vars->data->color[i]);
		free(vars->data->mesh[i]);
		free(vars->data->mesh_after[i]);
	}
	free(vars->data->mesh);
	free(vars->data->mesh_after);
	free(vars->data->z_coordinates);
	free(vars->data->color);
	free(vars->data);
	exit(0);
}

/**
 * @brief Closes the window and frees allocated memory.
 * 
 * This function is responsible for closing the window and freeing the memory
 * allocated for the data structures used in the program.
 * 
 * @param vars A pointer to the main variables structure.
 * @return void
 */
int	close_window(t_main_vars *vars)
{
	int	i;

	i = -1;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	while (++i < vars->data->height)
	{
		free(vars->data->z_coordinates[i]);
		free(vars->data->color[i]);
		free(vars->data->mesh[i]);
		free(vars->data->mesh_after[i]);
	}
	free(vars->data->mesh);
	free(vars->data->mesh_after);
	free(vars->data->z_coordinates);
	free(vars->data->color);
	free(vars->data);
	exit(0);
}
