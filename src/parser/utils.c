/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 16:02:07 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/28 15:47:43 by mdekker       ########   odam.nl         */
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
	char	*temp;

	i = 0;
	split = ft_split(str, ',');
	if (split == NULL || count_arr(split) != 3)
		return (false);
	while (i < 3)
	{
		temp = ft_strtrim(split[i], " ");
		if (temp == NULL)
			return (false);
		if (checkstr(temp, "0123456789") == 0)
			return (false);
		rgba[i] = ft_atoi(temp);
		if (rgba[i] < 0 || rgba[i] > 255)
			return (false);
		free(temp);
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
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief A function that checks if a string ends with a certain string.
 *
 * @param str The string to check.
 * @param end The string to check for.
 * @return true When the string ends with the end string.
 * @return false When the string does not end with the end string.
*/
bool	str_ends_with(char *str, char *end)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(end) - 1;
	while (j >= 0)
	{
		if (str[i] != end[j])
			return (false);
		i--;
		j--;
	}
	return (true);
}
