/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 21:13:18 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/21 16:18:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief The function that handles the path strings.
 *
 * @param str The string to handle.
 * @param type The type of the string.
 * @param data The main struct.
 * @return true When the path is successfully loaded.
 * @return false When the path could not be loaded.
 */
bool	handle_path(char *str, t_info_types type, t_data *data)
{
	char	*path;

	str += 2;
	path = ft_strtrim(str, " \n");
	if (path == NULL)
		return (error(MALLOC, NULL));
	if (!str_ends_with(path, ".png"))
		return (error(PNG_ERROR, path), free(path), false);
	if (!get_image(&data->textures.wall.directions[type], path))
		return (error(INVALID_PATH, path), free(path), false);
	return (free(path), true);
}

/**
 * @brief The function that handles the floor and ceiling colors.
 *
 * @param str The string to handle.
 * @param type The type of the string.
 * @param data The main struct.
 * @return true The color is successfully loaded.
 * @return false The color could not be loaded.
 */
bool	handle_rgba(char *str, t_info_types type, t_data *data)
{
	int		rgba;
	char	*rgba_str;

	str += 1;
	rgba_str = ft_strtrim(str, " \n");
	if (!check_rgb(rgba_str))
		return (error(INVALID_COLOR, rgba_str), free(rgba_str), false);
	if (!get_rgba(&rgba, rgba_str))
		return (error(INVALID_COLOR, rgba_str), free(rgba_str), false);
	free(rgba_str);
	if (type == F)
		data->textures.floor = rgba;
	else if (type == C)
		data->textures.ceiling = rgba;
	return (true);
}

bool	handle_door(char *str, t_info_types type, t_data *data)
{
	char	*path;

	(void)type;
	if (!BONUS)
		return (error(BONUS_ERROR, NULL));
	str += 1;
	path = ft_strtrim(str, " \n");
	if (path == NULL)
		return (error(MALLOC, NULL));
	if (!get_doors(&data->textures, path))
		return (free(path), false);
	return (free(path), true);
}

bool	handle_sprite(char *str, t_info_types type, t_data *data)
{
	char	*path;

	(void)type;
	if (!BONUS)
		return (error(BONUS_ERROR, NULL));
	str += 1;
	path = ft_strtrim(str, " \n");
	if (path == NULL)
		return (error(MALLOC, NULL));
	if (!get_sprites(&data->textures.sprite.images, path))
		return (free(path), false);
	return (free(path), true);
}
