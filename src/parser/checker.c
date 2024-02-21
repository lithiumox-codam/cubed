/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 22:53:43 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/20 17:45:15 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief checks if a door has walls on either side of it
 *
 * @param data
 * @param x
 * @param y
 * @return true
 * @return false
 */
static bool	check_door(t_data *data, int x, int y)
{
	if (data->map.array[y][x + 1] != WALL || data->map.array[y][x - 1] != WALL)
		return (error(DOOR_NOT_CLOSED, NULL));
	else
		return (true);
	if (data->map.array[y + 1][x] != WALL || data->map.array[y - 1][x] != WALL)
		return (error(DOOR_NOT_CLOSED, NULL));
	else
		return (true);
	return (true);
}

/**
 * @brief Construct a new general check object
 *
 * @param data
 * @param x
 * @param y
 * @return true
 * @return false
 */
static bool	general_check(t_data *data, int x, int y)
{
	if (x == 0 || x == data->map.width - 1 || y == 0 || y == data->map.height
		- 1)
	{
		return (error(MAP_NOT_CLOSED, NULL));
	}
	if (data->map.array[y][x + 1] == 0 || data->map.array[y][x - 1] == 0
		|| data->map.array[y + 1][x] == 0 || data->map.array[y - 1][x] == 0)
	{
		return (error(MAP_NOT_CLOSED, NULL));
	}
	if (data->map.array[y][x] == CLOSED_DOOR)
		return (check_door(data, x, y));
	return (true);
}

/**
 * @brief For every floor tile check if it is surrounded by wall
 * or other floor tiles or the player or empty tiles or the edge of the map.
 *
 */
bool	check_floor(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.array[y][x] >= FLOOR
				&& data->map.array[y][x] <= SPRITE)
				if (!general_check(data, x, y))
					return (false);
			x++;
		}
		y++;
	}
	return (true);
}
