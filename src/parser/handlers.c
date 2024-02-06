/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 21:13:18 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/02 18:15:54 by mdekker       ########   odam.nl         */
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
    if (!get_image(&data->textures.wall.directions[type], path))
        return (free(path), error(INVALID_PATH, path));
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
		return (free(rgba_str), error(INVALID_COLOR, NULL));
	if (!get_rgba(&rgba, rgba_str))
        return (error(INVALID_COLOR, NULL), false);
	free(rgba_str);
	if (type == F)
		data->textures.floor = rgba;
	else if (type == C)
		data->textures.ceiling = rgba;
	return (true);
}

bool	handle_door(char *str, t_info_types type, t_data *data)
{
	mlx_texture_t	*tmp;
	char			*path;
	(void)type;
	tmp = NULL;
//	if (!BONUS)
//		return (printf("Error\nBonus is not enabled\n"), false);
	str += 1;
	path = ft_strtrim(str, " \n");
	if (path == NULL)
		return (error(MALLOC, NULL));
    if (!get_image(&tmp, path))
        return (free(path), false);
    data->textures.door.north = tmp;
    data->textures.door.south = tmp;
    data->textures.door.east = tmp;
    data->textures.door.west = tmp;
	return (free(path), true);
}

bool	handle_sprite(char *str, t_info_types type, t_data *data)
{
    char *path;
	(void)type;
    (void)data;
//	if (!BONUS)
//		return (printf("Error\nBonus is not enabled\n"), false);
    str += 1;
    path = ft_strtrim(str, " \n");
    if (path == NULL)
        return (error(MALLOC, NULL));
    if (!get_sprites(&data->textures.sprite.images, path))
        return (free(path), false);
    return (free(path), true);
}
