/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:06:14 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/28 11:11:26 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	init_bonus(t_data *data)
{
	data->door_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->door_image, 0, 0) == -1)
		return (mlx_close_window(data->mlx), error(MLX_ERROR,
				mlx_strerror(mlx_errno)));
	data->minimap = mlx_new_image(data->mlx, 400, 400);
	if (mlx_image_to_window(data->mlx, data->minimap, 5, 5) == -1)
		return (mlx_close_window(data->mlx), error(MLX_ERROR,
				mlx_strerror(mlx_errno)));
	mlx_set_instance_depth(data->door_image->instances, 2);
	mlx_set_instance_depth(data->minimap->instances, 3);
	if (!vec_init(&data->bonus, 10, sizeof(t_raycast), NULL))
	{
		error(MALLOC, NULL);
		mlx_close_window(data->mlx);
	}
	return (0);
}

bool	init_window(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!data->mlx)
		return (error(MLX_ERROR, mlx_strerror(mlx_errno)));
	data->ray_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->ray_image)
		if (mlx_image_to_window(data->mlx, data->ray_image, 0, 0) == -1)
			return (mlx_close_window(data->mlx), error(MLX_ERROR,
					mlx_strerror(mlx_errno)));
	mlx_set_instance_depth(data->ray_image->instances, 1);
	if (BONUS && init_bonus(data))
		return (false);
	// mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
	raycast(data, data->ray, 0);
	mlx_loop_hook(data->mlx, key_hook, data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(data->mlx, cursor_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (true);
}
