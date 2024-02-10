/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:25:05 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/09 16:51:57 by mdekker       ########   odam.nl         */
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
			return (free(line), error(MAP_ERROR, NULL));
		if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (!vec_push(strings, &line))
			return (error(MALLOC, NULL));
	}
	return (true);
}

static bool	init_bonus(t_data *data)
{
	if (!BONUS)
		return (true);
	if (!vec_init(&data->textures.sprite.images, 10, sizeof(void **),
			free_sprite))
		return (error(MALLOC, " at sprite vector"));
	data->textures.sprite.current = 0;
	if (!vec_init(&data->objects, 5, sizeof(void **), NULL))
		return (error(MALLOC, " at object vector"));
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
	ft_memset(&data->check, 0, sizeof(bool) * CHECK_LENGTH);
	if (!init_bonus(data))
		return (close(fd), false);
	return (close(fd), true);
}
