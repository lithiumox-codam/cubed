/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 18:05:54 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/13 18:06:23 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Checks if the given type is already in the array. If it is not, it
 * adds the type to the array and returns true. If it is, it returns false.
 *
 * @param type The type to check
 * @param arr The array to check
 * @return true When the type is not in the array
 * @return false When the type is in the array
 */
bool	check_arr(t_info_types type, bool *arr)
{
	if (!BONUS && type > 5)
		return (error(BONUS_ERROR, NULL));
	if (arr[type] == true)
		return (error(DUPLICATE, NULL));
	arr[type] = true;
	return (true);
}

/**
 * @brief Checks if all the required arguments are in the array. If not, it
 * prints an error message.
 *
 * @param arr The array to check
 * @return true When all the required arguments are in the array
 * @return false When not all the required arguments are in the array
 */
bool	check_info(bool *arr)
{
	const t_func	*func_arr;
	int				i;

	i = 0;
	func_arr = return_arr();
	while (i < CHECK_LENGTH)
	{
		if (arr[i] == false)
			return (error(MISSING, func_arr[i].str));
		i++;
	}
	return (true);
}
