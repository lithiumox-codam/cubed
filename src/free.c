/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 15:58:55 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/19 16:04:11 by mdekker       ########   odam.nl         */
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

/**
 * @brief Frees the texture if it is not NULL.
 *
 * @param texture The texture to free.
 */
void	free_if_not_null(mlx_texture_t *texture)
{
	if (texture != NULL)
		mlx_delete_texture(texture);
}

/**
 * @brief The free function for the sprite. (specifically for the vector)
 *
 * @param sprite The sprite to free. (void pointer to a mlx_texture_t pointer)
 */
void	free_sprite(void *sprite)
{
	mlx_texture_t	*s;

	s = *(mlx_texture_t **)sprite;
	free_if_not_null(s);
}

/**
 * @brief Frees all bonus related data.
 *
 * @param data The data to free.
 */
void	free_bonus(t_data *data)
{
	vec_free(&data->textures.sprite.images);
	vec_free(&data->bonus);
	free_if_not_null(data->textures.door_open.north);
	free_if_not_null(data->textures.door_closed.north);
}

/**
 * @brief The main free function for the data struct.
 *
 * @param data The data struct to free.
 */
void	free_all(t_data *data)
{
	free_if_not_null(data->textures.wall.north);
	free_if_not_null(data->textures.wall.south);
	free_if_not_null(data->textures.wall.east);
	free_if_not_null(data->textures.wall.west);
	vec_free(&data->strings);
	if (BONUS)
		free_bonus(data);
	free(data->ray);
	clear_2d_array(data->map.array, data->map.height);
	free(data);
}
