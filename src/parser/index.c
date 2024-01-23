/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:30:43 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/24 00:37:07 by mdekker       ########   odam.nl         */
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
		{"NO ", N, handle_path},
		{"SO ", S, handle_path},
		{"EA ", E, handle_path},
		{"WE ", W, handle_path},
		{"F ", F, handle_rgba},
		{"C ", C, handle_rgba},
		{"D ", D, handle_door},
		{"S ", SP, handle_sprite},
		{NULL, NONE, NULL}};
	return (func_array);
}

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
		return (false);
	if (arr[type] == true)
		return (false);
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
			return (printf("Error\nMissing argument: %s\n", func_arr[i].str),
					false);
		i++;
	}
	return (true);
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
static bool	info_helper(t_data *data, char *str, int *j)
{
	const t_func	*arr;

	arr = return_arr();
	while (*str == ' ')
		str++;
	while (arr[*j].str != NULL)
	{
		if (ft_strncmp(str, arr[*j].str, ft_strlen(arr[*j].str)) == 0)
		{
			if (!check_arr(arr[*j].type, data->check) || !arr[*j].func_ptr(str,
					arr[*j].type, data))
				return (false);
			(*j) = 0;
			break ;
		}
		(*j)++;
	}
	if (arr[*j].str == NULL)
		return (false);
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
static bool	parse_info(t_data *data, int *i)
{
	char	*str;
	int		j;

	j = 0;
	while ((size_t)*i < data->strings.length && *i < CHECK_LENGTH)
	{
		str = *(char **)vec_get(&data->strings, (size_t)*i);
		if (!info_helper(data, str, &j))
			return (check_info(data->check), false);
		(*i)++;
	}
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
static bool	parse_map(t_data *data, int *i)
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
	int	i;

	i = 0;
	if (!parse_info(data, &i))
		return (false);
	if (!parse_map(data, &i))
		return (false);
	return (true);
}
