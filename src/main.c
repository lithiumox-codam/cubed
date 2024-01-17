/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:20:25 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/17 15:18:23 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief A function that clears the map array.
 *
 * @param array The array to clear.
 * @param height The height of the array.
 */
void	clear_2d_array(t_map_types **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_if_not_null(mlx_texture_t *texture)
{
	if (texture != NULL)
		mlx_delete_texture(texture);
}

void	free_all(t_data *data)
{
	free_if_not_null(data->textures.wall.north);
	free_if_not_null(data->textures.wall.south);
	free_if_not_null(data->textures.wall.east);
	free_if_not_null(data->textures.wall.west);
	vec_free(&data->strings);
	clear_2d_array(data->map.array, data->map.height);
	free(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (printf("Error\nWrong number of arguments\n"), 1);
	data = ft_calloc(1, sizeof(t_data));
	if (!init(data, av[1]))
		return (free_all(data), 1);
	if (!parse(data))
		return (free_all(data), 1);
	init_window(data);
	print_data(data);
	free_all(data);
	return (0);
}
