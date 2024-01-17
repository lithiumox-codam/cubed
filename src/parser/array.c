/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 13:27:21 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/17 15:50:15 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Get the w maximum and h of the map
 *
 * @param data The main struct
 * @param i The index of the first string after the info
 */
void	get_w_and_h(t_data *data, size_t *i)
{
	char	*str;
	size_t	j;
	size_t	start;

	j = 0;
	start = *i;
	while (*i < data->strings.length)
	{
		str = *(char **)vec_get(&data->strings, *i);
		if (ft_strlen(str) > j)
			j = ft_strlen(str) - 1;
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

static bool	player_helper(t_data *data, char p, size_t *j, size_t *k)
{
	if (data->player.x != 0 || data->player.y != 0)
		return (printf("Error\nMultiple players\n"), false);
	if (p == 'N')
		data->player.dir = 270;
	else if (p == 'E')
		data->player.dir = 0;
	else if (p == 'S')
		data->player.dir = 90;
	else if (p == 'W')
		data->player.dir = 180;
	data->player.x = (*k) + 0.25;
	data->player.y = (*j) + 0.25;
	data->map.array[*j][*k] = PLAYER;

	// printf("player x = %f player y = %f player dir = %f map[player y][player x] = %d\n", data->player.x, data->player.y, data->player.dir, data->map.array[(int)data->player.y][(int)data->player.x]);
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
static bool	other_types_helper(t_data *data, char p, size_t *y, size_t *x)
{
	if (p == '1')
		data->map.array[*y][*x] = WALL;
	else if (p == '0')
		data->map.array[*y][*x] = FLOOR;
	else if (!checkchar(p, "NSEW10 \n"))
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
bool	apply_strings_to_array(t_data *data, size_t *i)
{
	char	*str;
	size_t	y;
	size_t	x;

	y = 0;
	while (*i < data->strings.length)
	{
		str = *(char **)vec_get(&data->strings, *i);
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
