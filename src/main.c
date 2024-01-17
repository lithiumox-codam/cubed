/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:20:25 by mdekker       #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2024/01/15 17:13:33 by maxvalk       ########   odam.nl         */
=======
/*   Updated: 2024/01/16 17:03:05 by mdekker       ########   odam.nl         */
>>>>>>> main
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
<<<<<<< HEAD
	// printf("player x = %f player y = %f player dir = %f map[player y][player x] = %d\n", data->player.x, data->player.y, data->player.dir, data->map.array[(int)data->player.y][(int)data->player.x]);
	init_window(data);
	printf("NO: %p\n", data->textures.wall.north);
	printf("SO: %p\n", data->textures.wall.south);
	printf("EA: %p\n", data->textures.wall.east);
	printf("WE: %p\n", data->textures.wall.west);
	printf("NO[0]: %p\n", data->textures.wall.directions[0]);
	printf("SO[1]: %p\n", data->textures.wall.directions[1]);
	printf("EA[2]: %p\n", data->textures.wall.directions[2]);
	printf("WE[3]: %p\n", data->textures.wall.directions[3]);
	printf("F: %d\n", data->textures.floor);
	printf("C: %d\n", data->textures.ceiling);
	printf("Map:\n");
	printf("Width: %d\n", data->map.width);
	printf("Height: %d\n", data->map.height);
=======
	print_data(data);
>>>>>>> main
	free_all(data);
	return (0);
}
