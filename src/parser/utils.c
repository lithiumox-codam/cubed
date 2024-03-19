/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 16:02:07 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/19 15:29:43 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief A function that counts the amount of strings in an array.
 *
 * @param arr The array to count.
 * @return int The amount of strings in the array.
 */
int	count_arr(char **arr)
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
 * @param res The result of the function will be stored here.
 * @param str The string to get the rgba int from.
 * @return bool true When the string is valid. false when it is not.
 */
bool	get_rgba(int *res, char *str)
{
	char	**split;
	int		rgba[3];
	int		i;

	i = 0;
	split = ft_split(str, ',');
	if (split == NULL || count_arr(split) != 3)
		return (false);
	while (i < 3)
	{
		if (checkstr(split[i], "0123456789") == 0)
			return (false);
		rgba[i] = ft_atoi(split[i]);
		if (rgba[i] < 0 || rgba[i] > 255)
			return (false);
		i++;
	}
	ft_free(split);
	*res = rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | 255;
	return (true);
}

/**
 * @brief Checks if the string is a valid rgb string.
 *
 * @param str The string to check.
 * @return true When the string is valid.
 * @return false When the string is invalid.
 */
bool	check_rgb(char *str)
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
 * @brief A function that appends a path with a slash (if it does not end with
 * one) then an arbitrary string. Followed by .png then returns the string.
 * @param path The path to append.
 * @param i The number to append.
 * @return char* The new string.
 */
static char	*append_path(char *path, char *str)
{
	char	*file;
	char	*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		if (tmp == NULL)
			return (free(str), error(MALLOC, NULL), NULL);
		file = ft_strjoin(tmp, str);
		free(tmp);
	}
	else
		file = ft_strjoin(path, str);
	if (file == NULL)
		return (free(str), error(MALLOC, NULL), NULL);
	tmp = ft_strjoin(file, ".png");
	free(file);
	free(str);
	return (tmp);
}

/**
* @brief Gets a directory as a string uses open() to check if it exists.
 * Then it loops thru images that that with 00.png to 99.png and loads them into
 * the array of textures.
 * @param sprites The vector containing the textures.
 * @param path The path to the directory.
 * @return bool True when the images are loaded, false when they are not.
*/
bool	get_sprites(t_vector *sprites, char *path)
{
	mlx_texture_t	*tmp;
	char			*file;
	int				i;

	i = 0;
	while (true)
	{
		file = append_path(path, ft_itoa(i));
		if (file == NULL)
			return (error(MALLOC, NULL));
		if (!get_image(&tmp, file))
		{
			free(file);
			break ;
		}
		free(file);
		if (!vec_push(sprites, &tmp))
			return (error(MALLOC, NULL));
		i++;
	}
	if (i == 0)
		return (error(NO_SPRITES, NULL));
	return (true);
}

void	apply_textures(t_texture *txt, mlx_texture_t *img)
{
	txt->north = img;
	txt->south = img;
	txt->east = img;
	txt->west = img;
}

/**
* @brief The door helper that gets the open and closed door textures.
 * @param str The string to handle.
 * @param data The main struct.
 * @return bool True when the textures are loaded, false when they are not.
*/
bool	get_doors(t_textures *textures, char *path)
{
	mlx_texture_t	*tmp;
	char			*path_open;
	char			*path_closed;

	path_open = append_path(path, ft_strdup("open"));
	path_closed = append_path(path, ft_strdup("closed"));
	if (path_closed == NULL || path_open == NULL)
		return (free(path_open), free(path_closed), error(MALLOC, NULL));
	if (!get_image(&tmp, path_open))
		return (free(path_open), free(path_closed), error(INVALID_DOOR, NULL));
	apply_textures(&textures->door_open, tmp);
	if (!get_image(&tmp, path_closed))
		return (free(path_open), free(path_closed), error(INVALID_DOOR, NULL));
	apply_textures(&textures->door_closed, tmp);
	return (free(path_open), free(path_closed), true);
}
