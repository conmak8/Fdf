/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:04:13 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/04 01:58:37 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Draws lines connecting the points in a mesh.
 *
 * @param img The image data structure.
 * @param mesh_after The 2D array of pixels representing the mesh.
 * @param height The height of the mesh.
 * @param width The width of the mesh.
 */
void	draw_lines(t_imdata *img, t_pix **mesh_after, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j + 1 < width)
		{
			paint_line(img, mesh_after[i][j], mesh_after[i][j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while ((i + 1) < height)
	{
		j = 0;
		while (j < width)
		{
			paint_line(img, mesh_after[i][j], mesh_after[i + 1][j]);
			j++;
		}
		i++;
	}
}

/**
 * Initializes the mlx, mlx_win, img, and addr variables.
 * 
 * @param img The t_imdata struct that holds image data.
 * @param mlx A pointer to the mlx instance.
 * @param mlx_win A pointer to the mlx window instance.
 * @param window_size The t_window_size struct that holds the window size.
 */
void	init_mlx(t_imdata *img, void **mlx, void **mlx_win, \
t_window_size *window_size)
{
	*mlx = mlx_init();
	*mlx_win = mlx_new_window(*mlx, window_size->x, \
	window_size->y, "fdf");
	img->img = mlx_new_image(*mlx, window_size->x, \
	window_size->y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}

/**
 * Initializes the mesh data structure with the given parameters.
 *
 * @param data The t_meshfdf structure containing the mesh data.
 * @param mesh A pointer to a pointer to a t_pix structure representing 
 * the mesh.
 * @param mesh_after A pointer to a pointer to a t_pix structure representing 
 * the modified mesh.
 * @param scale The scaling factor for the mesh coordinates.
 */
void	init_mesh(t_meshfdf *data, t_pix ***mesh, t_pix ***mesh_after, \
int scale)
{
	int	i;
	int	j;

	i = 0;
	*mesh = (t_pix **)malloc(data->height * sizeof(t_pix *));
	*mesh_after = (t_pix **)malloc(data->height * sizeof(t_pix *));
	while (i < data->height)
	{
		(*mesh)[i] = (t_pix *)malloc(data->width * sizeof(t_pix));
		(*mesh_after)[i] = (t_pix *)malloc(data->width * sizeof(t_pix));
		j = 0;
		while (j < data->width)
		{
			(*mesh)[i][j].z = data->z_coordinates[i][j];
			(*mesh_after)[i][j].color = data->color[i][j];
			(*mesh)[i][j].x = j * scale;
			(*mesh)[i][j].y = i * scale;
			int_to_float(&(*mesh)[i][j]);
			j++;
		}
		i++;
	}
}

/**
 * Initializes the data structure for the FDF mesh and reads the file.
 *
 * @param data      A pointer to a pointer to the t_meshfdf structure.
 * @param file_name The name of the file to be read.
 */
void	init_data(t_meshfdf **data, char *file_name)
{
	*data = (t_meshfdf *)malloc(sizeof(t_meshfdf));
	read_file(file_name, *data);
}

/**
 * Initializes the variables of a t_vars struct.
 * 
 * @param vars The t_vars struct to initialize.
 */
void	init_variables(t_vars *vars)
{
	vars->scale = 2;
	vars->rot_x = 0.3f;
	vars->rot_y = 0.3f;
	vars->rot_z = 0.3f;
}
