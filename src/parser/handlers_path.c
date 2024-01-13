/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers_path.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 21:13:18 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/13 17:36:56 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	handle_no(char *str, t_data *data)
{
	char	*path;

	path = ft_strtrim(str, "NO \n");
	if (path == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	data->textures.north = mlx_load_png(path);
	if (data->textures.north == NULL)
		return (printf("Error\nCould not load texture: %s\n", path), false);
	return (true);
}

bool	handle_so(char *str, t_data *data)
{
	char	*path;

	path = ft_strtrim(str, "SO \n");
	if (path == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	data->textures.south = mlx_load_png(path);
	if (data->textures.south == NULL)
		return (printf("Error\nCould not load texture: %s\n", path), false);
	return (true);
}

bool	handle_we(char *str, t_data *data)
{
	char	*path;

	path = ft_strtrim(str, "WE \n");
	if (path == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	data->textures.west = mlx_load_png(path);
	if (data->textures.west == NULL)
		return (printf("Error\nCould not load texture: %s\n", path), false);
	return (true);
}

bool	handle_ea(char *str, t_data *data)
{
	char	*path;

	path = ft_strtrim(str, "EA \n");
	if (path == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	data->textures.east = mlx_load_png(path);
	if (data->textures.east == NULL)
		return (printf("Error\nCould not load texture: %s\n", path), false);
	return (true);
}
