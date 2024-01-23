/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 16:02:07 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/23 17:29:22 by mdekker       ########   odam.nl         */
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
