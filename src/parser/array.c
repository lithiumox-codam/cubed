/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 13:27:21 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/24 00:35:52 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Get the w maximum and h of the map
 *
 * @param data The main struct
 * @param i The index of the first string after the info
 */
void	get_w_and_h(t_data *data, int *i)
{
	char	*str;
	int		j;
	int		start;

	j = 0;
	start = *i;
	while ((size_t)*i < data->strings.length)
	{
		str = *(char **)vec_get(&data->strings, *i);
		if ((int)ft_strlen(str) > j)
			j = (int)ft_strlen(str) - 1;
		(*i)++;
	}
	data->map.width = j;
	data->map.height = ((*i) - start);
	(*i) = start;
}

bool	create_2d_arr(t_data *data)
{
	int	i;

	i = 0;
	data->map.array = ft_calloc(data->map.height, sizeof(t_map_types **));
	if (data->map.array == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	while (i < data->map.height)
	{
		data->map.array[i] = ft_calloc(data->map.width, sizeof(t_map_types));
		if (data->map.array[i] == NULL)
		{
			while (i > 0)
			{
				free(data->map.array[i]);
				i--;
			}
			free(data->map.array);
			return (printf("Error\nMalloc failed\n"), false);
		}
		i++;
	}
	return (true);
}

static bool	player_helper(t_data *data, char p, int *j, int *k)
{
	if (data->player.x != 0 || data->player.y != 0)
		return (printf("Error\nMultiple players\n"), false);
	if (p == 'N')
		data->player.dir = M_PI / 2;
	else if (p == 'E')
		data->player.dir = 0;
	else if (p == 'S')
		data->player.dir = M_PI * 1.5;
	else if (p == 'W')
		data->player.dir = M_PI;
	data->player.x = (*k) + 0.25;
	data->player.y = (*j) + 0.25;
	data->map.array[*j][*k] = PLAYER;
	return (true);
}

/**
 * @brief Handles the other types of characters in the map
 * such as 1, 0, ' ' and checks if there are no invalid characters
 *
 * @param data The main struct
 * @param p The character to be checked
 * @param j The y index of the map array
 * @param k The x index of the map array
 * @return bool true when no errors occur and false when an error occurs
 */
static bool	other_types_helper(t_data *data, char p, int *y, int *x)
{
	if (p == '1')
		data->map.array[*y][*x] = WALL;
	else if (p == '0')
		data->map.array[*y][*x] = FLOOR;
	if (BONUS && p == 'D')
		data->map.array[*y][*x] = CLOSED_DOOR;
	else if (BONUS && p == 'X')
		data->map.array[*y][*x] = SPRITE;
	if (!checkchar(p, VALID_MAP_CHARS))
		return (printf("Error\nInvalid character in map: %c\n", p), false);
	return (true);
}

/**
 * @brief Apply the strings to the map array
 *
 * @param data The main struct
 * @param i The index of the first string after the info
 * @return true When all strings are applied succesfully
 * @return false When an error occurs
 */
bool	apply_strings_to_array(t_data *data, int *i)
{
	char	*str;
	int		y;
	int		x;

	y = 0;
	while ((size_t)*i < data->strings.length)
	{
		str = *(char **)vec_get(&data->strings, (size_t)*i);
		x = 0;
		while (str[x] != '\0')
		{
			if (checkchar(str[x], "NSEW"))
				if (!player_helper(data, str[x], &y, &x))
					return (false);
			if (!other_types_helper(data, str[x], &y, &x))
				return (false);
			x++;
		}
		y++;
		(*i)++;
	}
	return (true);
}
