/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:06:14 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/21 00:47:10 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	round_10(int num)
{
	if (num % 10 < 5)
		return (num - (num % 10));
	else
		return (num + (10 - (num % 10)));
}

bool	init_bonus(t_data *data)
{
	int	size;

	size = round_10(HEIGHT / 4);
	data->sprite_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->sprite_image, 0, 0) == -1)
		return (mlx_close_window(data->mlx), error(MLX_ERROR,
				mlx_strerror(mlx_errno)));
	data->minimap = mlx_new_image(data->mlx, size, size);
	if (mlx_image_to_window(data->mlx, data->minimap, 5, 5) == -1)
		return (mlx_close_window(data->mlx), error(MLX_ERROR,
				mlx_strerror(mlx_errno)));
	mlx_set_instance_depth(data->sprite_image->instances, 2);
	mlx_set_instance_depth(data->minimap->instances, 3);
	return (true);
}

bool	init_window(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!data->mlx)
		return (dprintf(2, "%s\n", mlx_strerror(mlx_errno)), 1);
	data->ray_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->ray_image)
		if (mlx_image_to_window(data->mlx, data->ray_image, 0, 0) == -1)
			return (mlx_close_window(data->mlx), error(MLX_ERROR,
					mlx_strerror(mlx_errno)));
	if (BONUS && !init_bonus(data))
		return (1);
	mlx_set_instance_depth(data->ray_image->instances, 1);
	raycast(data, data->ray, 0);
	mlx_loop_hook(data->mlx, key_hook, data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(data->mlx, cursor_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (true);
}
