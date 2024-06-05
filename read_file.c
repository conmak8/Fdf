/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:00:35 by con.mak           #+#    #+#             */
/*   Updated: 2024/06/03 19:59:03 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Calculates the height of a file by counting the number of lines.
 *
 * @param file_name The name of the file to read.
 * @return The height of the file, or -1 if there was an error opening the file.
 */
int	get_height(char *file_name)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

/**
 * @brief Calculates the width of a file by counting the number 
 * of columns in each line.
 * 
 * @param file_name The name of the file to be read.
 * @return The width of the file, or -1 if there was an error 
 * opening the file.
 */
int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;
	int		i;

	width = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), -1);
	line = get_next_line(fd);
	i = 0;
	if (line[0] != ' ')
		width++;
	while (line[++i] != '\n')
	{
		if (line[i - 1] == ' ' && line[i] != ' ')
			width++;
	}
	close(fd);
	return (width);
}

/**
 * Fills the matrix with values and colors based on the input line.
 *
 * @param z_line  Pointer to the array storing the z-values of each point.
 * @param color   Pointer to the array storing the colors of each point.
 * @param line    The input line containing the values and colors.
 * @param width   The width of the matrix.
 */
void	fill_matrix(int *z_line, int *color, char *line, int width)
{
	char	**nums;
	int		i;
	char	*clr;

	nums = ft_split(line, ' ');
	i = 0;
	while (i < width)
	{
		z_line[i] = ft_atoi(nums[i]);
		clr = nums[i];
		while ((*clr >= '0' && *clr <= '9') || *clr == '-')
			clr++;
		if (*clr && *clr != '\n')
			color[i] = atoi_base_hex(clr + 3);
		else
			color[i] = 0x00FFFFFF;
		free(nums[i]);
		i++;
	}
	free(nums);
}

/**
 * @brief Allocates memory for the z_coordinates and color arrays in the 
 * t_meshfdf structure.
 * 
 * This function dynamically allocates memory for the z_coordinates 
 * and color arrays in the t_meshfdf structure.
 * The size of the arrays is determined by the height and width variables 
 * in the t_meshfdf structure.
 * 
 * @param data A pointer to the t_meshfdf structure.
 */
void	allocate_memory(t_meshfdf *data)
{
	int	i;

	i = 0;
	data->z_coordinates = (int **)malloc(sizeof(int *) * (data->height) + 1);
	if (!data->z_coordinates)
	{
		perror("Failed to allocate memory for z_coordinates"); // remember to free first! has to be fixed
		exit(EXIT_FAILURE);
	}
	data->color = (int **)malloc(sizeof(int *) * (data->height) + 1);
	if (!data->color)
	{
		perror("Failed to allocate memory for color"); // remember to free first! has to be fixed
		exit(EXIT_FAILURE);
	}
	while (i < data->height)
	{
		data->z_coordinates[i] = (int *)malloc(sizeof(int) * (data->width) + 1);
		if (!data->z_coordinates[i]) // remember to free first! has to be fixed
			exit(5);
		data->color[i] = (int *)malloc(sizeof(int) * ((data->width) + 1));
		if (!data->color[i]) // remember to free first! has to be fixed
			exit(6);
		i++;
	}
}

/**
 * Reads a file and populates a t_meshfdf structure with the data.
 *
 * @param file_name The name of the file to be read.
 * @param data A pointer to the t_meshfdf structure to store the data.
 * @return 0 if the file was successfully read, -1 otherwise.
 */
int	read_file(char *file_name, t_meshfdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	allocate_memory(data);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), -1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->z_coordinates[i], data->color[i], line, data->width);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
