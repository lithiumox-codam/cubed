/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:25:05 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/23 19:17:38 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Helper function for the vec_free that will free the strings in the
 * vector. After tht the main data pointer is freed by the vec_free.
 *
 * @param data Pointer to the string to free.
 */
static void	free_strings(void *data)
{
	free(*(char **)data);
}

/**
 * @brief Grabs the strings from the file and puts them in a vector.
 * Within the first 6 lines all enters are removed. And if the file contains
 * enters after the first 6 lines, the function returns false.
 *
 * @param strings The vector to put the strings in.
 * @param fd The file descriptor.
 * @return true When all strings are put in the vector.
 * @return false When a malloc fails or the file contains enters after the first
 * 6 lines.
 */
static bool	init_loop(t_vector *strings, int fd)
{
	char	*line;

	line = "\0";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((*strings).length > CHECK_LENGTH && line[0] == '\n')
			return (printf("Error\nMap contains enters\n"), free(line), false);
		if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (!vec_push(strings, &line))
			return (printf("Error\nMalloc failed\n"), false);
	}
	return (true);
}

/**
 * @brief The main init function. It calls the init_main function and closes the
 *
 * @param data
 * @param file
 * @return true
 * @return false
 */
bool	init(t_data *data, char *file)
{
	int	fd;

	if (!vec_init(&data->strings, 10, sizeof(void **), free_strings))
		return (printf("Error\nMalloc failed\n"), false);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCould not open file\n"), close(fd), 1);
	if (!init_loop(&data->strings, fd))
		return (close(fd), false);
	data->ray = ft_calloc(1, sizeof(t_raycast));
	if (!data->ray)
		return (printf("Error\nMalloc failed\n"), false);
	ft_memset(&data->check, 0, sizeof(bool) * 8);
	return (close(fd), true);
}
