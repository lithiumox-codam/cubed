/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 21:13:18 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/24 00:24:43 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief The function that handles the path strings.
 *
 * @param str The string to handle.
 * @param type The type of the string.
 * @param data The main struct.
 * @return true When the path is succesfully loaded.
 * @return false When the path could not be loaded.
 */
bool	handle_path(char *str, t_info_types type, t_data *data)
{
	char	*path;
	int		fd;

	str += 2;
	path = ft_strtrim(str, " \n");
	if (path == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		data->textures.wall.directions[type] = NULL;
		return (printf("Error\nFile does not exist: %s\n", path), free(path),
			close(fd), false);
	}
	close(fd);
	data->textures.wall.directions[type] = mlx_load_png(path);
	if (data->textures.wall.directions[type] == NULL)
		return (printf("Error\nCould not load texture: %s\n", path), exit(1),
			false);
	return (free(path), true);
}

/**
 * @brief The function that handles the floor and ceiling colors.
 *
 * @param str The string to handle.
 * @param type The type of the string.
 * @param data The main struct.
 * @return true The color is succesfully loaded.
 * @return false The color could not be loaded.
 */
bool	handle_rgba(char *str, t_info_types type, t_data *data)
{
	int		rgba;
	char	*rgba_str;

	str += 1;
	rgba_str = ft_strtrim(str, " \n");
	if (!check_rgb(rgba_str))
		return (free(rgba_str), printf("Error\nThe RGB string is faulty!\n"),
			false);
	rgba = get_rgba(rgba_str);
	free(rgba_str);
	if (rgba == -1)
		return (printf("Error\nMalloc failed\n"), false);
	if (type == F)
		data->textures.floor = rgba;
	else if (type == C)
		data->textures.ceiling = rgba;
	return (true);
}

bool	handle_door(char *str, t_info_types type, t_data *data)
{
	(void)data;
	(void)type;
	if (!BONUS)
		return (printf("Error\nBonus is not enabled\n"), false);
	str += 1;
	printf("Door handler triggered! %s\n", str);
	return (true);
}

bool	handle_sprite(char *str, t_info_types type, t_data *data)
{
	(void)data;
	(void)type;
	if (!BONUS)
		return (printf("Error\nBonus is not enabled\n"), false);
	str += 1;
	printf("Sprite handler triggered! %s\n", str);
	return (true);
}
