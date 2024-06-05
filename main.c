/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: con.mak <con.mak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:00:45 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/05 16:39:49 by con.mak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return The exit status of the program.
 */
int	main(int argc, char **argv)
{
	t_main_vars		vars;
	t_window_size	window_size;

	(void)argc;
	window_size.x = 1200;
	window_size.y = 800;
	init_variables(&(vars.vars));
	init_data(&(vars.data), argv[1]);
	init_mesh(vars.data, &(vars.mesh), &(vars.mesh_after), vars.vars.scale);
	vars.data->mesh = vars.mesh;
	vars.data->mesh_after = vars.mesh_after;
	init_mlx(&(vars.img), &(vars.mlx), &(vars.mlx_win), \
	&(window_size));
	mlx_hook(vars.mlx_win, 2, 0, key_press, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_window, &vars);
	rotate_xyz(vars.data, vars.vars, window_size);
	draw_lines(&(vars.img), vars.mesh_after, vars.data->height, \
	vars.data->width);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}
