/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 21:13:18 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/15 17:56:29 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief A function that counts the amount of strings in an array.
 *
 * @param arr The array to count.
 * @return int The amount of strings in the array.
 */
static int	count_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

/**
 * @brief Get the rgba int from the string.
 *
 * @param str The string to get the rgba int from.
 * @return int The rgba int.
 */
int	get_rgba(char *str)
{
	char	**split;
	int		rgba[3];
	int		i;

	i = 0;
	split = ft_split(str, ',');
	if (split == NULL || count_arr(split) != 3)
		return (printf("Error\nRGBA function failed. Wrong input.\n"), -1);
	while (i < 3)
	{
		if (checkstr(split[i], "0123456789") == 0)
			return (printf("Error\nWrong argument type\n"), -1);
		rgba[i] = ft_atoi(split[i]);
		if (rgba[i] < 0 || rgba[i] > 255)
			return (printf("Error\nWrong argument type\n"), -1);
		i++;
	}
	ft_free(split);
	return (rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | 255);
}

/**
 * @brief Checks if the string is a valid rgb string.
 *
 * @param str The string to check.
 * @return true When the string is valid.
 * @return false When the string is invalid.
 */
static bool	check_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief The function that handles the path strings.
 *
 * @param str The string to handle.
 * @param type The type of the string.
 * @param data The main struct.
 * @return true When the path is succesfully loaded.
 * @return false When the path could not be loaded.
 * !TODO: When the path does not exist the program crashes.
 */
bool	handle_path(char *str, t_info_types type, t_data *data)
{
	char	*path;

	str += 2;
	path = ft_strtrim(str, " \n");
	if (path == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	data->textures.wall.directions[type] = mlx_load_png(path);
	if (data->textures.wall.directions[type] == NULL)
		return (printf("Error\nCould not load texture: %s\n", path), free(path),
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
