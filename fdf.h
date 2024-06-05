/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:00:21 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/03 16:11:01 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// STRUCTS
/**
 * @struct t_window_size
 * @brief Represents the size of a window.
 *
 * The `t_window_size` struct stores the width and height of a window.
 * The `x` member represents the width of the window,
	while the `y` member represents the height of the window.
 */
typedef struct s_window_size
{
	int				x;
	int				y;
}					t_window_size;

/**
 * @brief Structure representing image data.
 *
 * This structure holds information about an image,
	including the image data itself,
 * the address of the image, the number of bits per pixel,
	the length of each image line,
 * and the endianess of the image.
 */
typedef struct s_imdata
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_imdata;

/**
 * @struct s_vars
 * @brief Represents the variables used in the FDF program.
 *
 * The `s_vars` structure holds the variables used in the FDF program.
 * It includes the scale factor, window size, and rotation angles along the x,
	y, and z axes.
 */
typedef struct s_vars
{
	int				scale;
	t_window_size	window;
	float			rot_x;
	float			rot_y;
	float			rot_z;
}					t_vars;

/**
 * @struct t_pix
 * @brief Represents a pixel with its coordinates, depth,
	normalized coordinates, and color.
 *

	* The `t_pix` structure is used to store information 
	about a pixel in a 3D space.
 * It contains the pixel's x, y, and z coordinates,
	as well as their normalized floating-point values (xf, yf, zf).
 * The `color` field represents the color of the pixel.
 */
typedef struct s_pix
{
	int				x;
	int				y;
	int				z;
	float			xf;
	float			yf;
	float			zf;
	int				color;
}					t_pix;

/**
 * @struct t_line_Params
 * @brief Represents the parameters for drawing a line.
 *
 * This struct contains various parameters used for drawing a line,
	such as the change in x and y coordinates (dx and dy),
 * the step direction (sx and sy), the error value (err),
	the error increment (e2), the squared length (len2),
	the color difference (color_diff),
 * and an additional squared length (len2b).
 */
typedef struct s_line_Params
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	float			len2;
	int				color_diff;
	float			len2b;
}					t_line_Params;

/**
 * @struct  s_meshfdf
 * @brief   Represents a mesh for the FDF project.
 *

	* The `s_meshfdf` struct stores information about the mesh used in 
	the FDF project.
 * It contains the width and height of the mesh, the 2D array of z-coordinates,
 * the 2D array of colors,
	and two 2D arrays of `t_pix` structs representing the mesh
 * before and after transformations.
 */
typedef struct s_meshfdf
{
	int				width;
	int				height;
	int				**z_coordinates;
	int				**color;

	t_pix			**mesh;
	t_pix			**mesh_after;
}					t_meshfdf;

/**
 * @struct t_main_vars
 * @brief Represents the main variables used in the fdf program.
 *
 * This struct contains the following members:
 * - data: A pointer to the t_meshfdf struct that holds the fdf data.
 * - mesh: A 2D array of t_pix structs representing the initial mesh.
 *
	- mesh_after: A 2D array of t_pix structs representing 
	the mesh after transformations.
 * - vars: An instance of the t_vars struct that holds program variables.
 * - mlx: A pointer to the mlx library instance.
 * - mlx_win: A pointer to the mlx window instance.
 * - img: An instance of the t_imdata struct that holds image data.
 */
typedef struct s_main_vars
{
	void			*mlx;
	void			*mlx_win;
	t_meshfdf		*data;
	t_pix			**mesh;
	t_pix			**mesh_after;
	t_vars			vars;
	t_imdata		img;
}					t_main_vars;

/**
 * @struct t_MidPoint
 * @brief Structure representing the midpoint of a line in a 2D space.
 *
 * The t_MidPoint structure stores the x and y coordinates of the midpoint,
 * as well as a zoom factor for scaling purposes.
 */
typedef struct s_MidPoint
{
	float			midx;
	float			midy;
	float			zoom;
}					t_MidPoint;

// main.c
// main_blocks.c
void				draw_lines(t_imdata *img, t_pix **mesh_after, int height,
						int width);
void				init_mlx(t_imdata *img, void **mlx, void **mlx_win,
						t_window_size *window_size);
void				init_mesh(t_meshfdf *data, t_pix ***mesh,
						t_pix ***mesh_after, int scale);
void				init_data(t_meshfdf **data, char *file_name);
void				init_variables(t_vars *vars);
// help_functions.c
void				int_to_float(t_pix *data);
void				float_to_int(t_pix *data);
void				rotate_x(t_pix a, t_pix *b, float theta);
void				rotate_y(t_pix a, t_pix *b, float theta);
void				rotate_z(t_pix a, t_pix *b, float theta);
// help_functions_2.c
void				translate_xy(t_pix *b, t_MidPoint mid,
						t_window_size window_size);
void				centralize(t_meshfdf *data, t_window_size window_size);
void				rotate_xyz(t_meshfdf *data, t_vars vars,
						t_window_size window_size);
int					key_press(int keycode, t_main_vars *vars);
int					close_window(t_main_vars *vars);
// help_functions_3.c
void				find_max_min(float *mm, t_meshfdf *data);
t_MidPoint			centralize_rotation(t_meshfdf *data, \
						t_window_size window_size);
int					get_digit(char c);
int					atoi_base_hex(char *str);
// paint_line.c
void				init_line(t_pix a, t_pix b, t_line_Params *params);
void				paint_line(t_imdata *data, t_pix a, t_pix b);
void				my_mlx_pixel_put(t_imdata *data, int x, int y, int color);
// read_file.c
int					get_height(char *file_name);
int					get_width(char *file_name);
void				fill_matrix(int *z_line, int *color, char *line, int width);
void				allocate_memory(t_meshfdf *data);
int					read_file(char *file_name, t_meshfdf *data);

#endif