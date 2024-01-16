/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:30:43 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/15 20:58:29 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Returns an array of structs containing the string, the type and the
 * function pointer. The function pointer is used to call the correct function
 * for the given string.
 *
 * @return const t_func* The array of structs
 */
static const t_func	*return_arr(void)
{
	static const t_func func_array[] = {
		{"NO", N, handle_path},
		{"SO", S, handle_path},
		{"WE", W, handle_path},
		{"EA", E, handle_path},
		{"F ", F, handle_rgba},
		{"C ", C, handle_rgba},
		{NULL, -1, NULL}};
	return (func_array);
}

/**
 * @brief This function loops through the array of structs and calls the
 * correct function for the given string. If the string is not found, it
 * returns false.
 *
 * @param data
 * @param str
 * @param j
 * @return true
 * @return false
 */
static bool	info_helper(t_data *data, char *str, size_t *j)
{
	const t_func	*arr;

	arr = return_arr();
	while (*str == ' ')
		str++;
	while (arr[*j].str != NULL)
	{
		if (ft_strncmp(str, arr[*j].str, 2) == 0)
		{
			if (!arr[*j].func_ptr(str, arr[*j].type, data))
				return (false);
			else
				(*j) = 0;
			break ;
		}
		(*j)++;
	}
	if (arr[*j].str == NULL)
		return (printf("Error\nWrong argument type: %.2s\n", str), false);
	return (true);
}

/**
 * @brief Parse info from the file. The function loops through the vector of
 * strings and calls the info_helper function for each string. Returns false if
 * it encounters an error.
 *
 * @param data The main struct containing the vector with strings
 * @return true When all strings are parsed succesfully
 * @return false When an error occurs
 */
static bool	parse_info(t_data *data, size_t *i)
{
	char	*str;
	size_t	j;

	j = 0;
	while (*i < data->strings.length && *i < 6)
	{
		str = *(char **)vec_get(&data->strings, *i);
		if (!info_helper(data, str, &j))
			return (false);
		(*i)++;
	}
	if (*i != 6)
		return (printf("Error\nMissing arguments\n"), false);
	return (true);
}

/**
 * @brief Parse the map from the file.
 * The function loops through the vector of strings and calls the correct
 * function for each string. Returns false if it encounters an error.
 *
 * @param data The main struct containing the vector with strings
 * @return true When all strings are parsed succesfully
 * @return false When an error occurs
 */
static bool	parse_map(t_data *data, size_t *i)
{
	get_w_and_h(data, i);
	if (!create_2d_arr(data))
		return (false);
	if (!apply_strings_to_array(data, i))
		return (false);
	if (!check_floor(data))
		return (false);
	print_array(data);
	return (true);
}

/**
 * @brief The main parse function. Calls the parse_info and parse_map functions.
 *
 * @param data The main struct containing the vector with strings
 * @return true The map is succesfully parsed
 * @return false There was an error while parsing
 */
bool	parse(t_data *data)
{
	size_t	i;

	i = 0;
	if (!parse_info(data, &i))
		return (false);
	if (!parse_map(data, &i))
		return (false);
	return (true);
}
