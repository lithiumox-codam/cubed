/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:06:14 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/14 01:22:08 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_sprite(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	mlx_texture_t	*t;

	i = 0;
	t = *(mlx_texture_t **)vec_get(&data->textures.sprite.images,
									data->textures.sprite.current);
	while (i < t->width)
	{
		j = 0;
		while (j < t->height)
		{
			mlx_put_pixel(data->sprite_image, i, j, *(int *)&t->pixels[(t->width
						* j + i) * 4]);
			j++;
		}
		i++;
	}
}

void	toggle_all_doors(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j] == CLOSED_DOOR)
				map->array[i][j] = OPEN_DOOR;
			else if (map->array[i][j] == OPEN_DOOR)
				map->array[i][j] = CLOSED_DOOR;
			j++;
		}
		i++;
	}
}

void	key_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->frame_count++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		set_new_pos(data, data->player, N, 0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		set_new_pos(data, data->player, S, 0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		set_new_pos(data, data->player, W, 0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		set_new_pos(data, data->player, E, 0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		toggle_all_doors(&data->map);
	raycast(data, data->ray, 0);
	if (BONUS && data->frame_count % 15 == 0)
	{
		draw_sprite(data);
		if (data->textures.sprite.current == data->textures.sprite.images.length
			- 1)
			data->textures.sprite.current = 0;
		else
			data->textures.sprite.current++;
	}
}

int	init_bonus(t_data *data)
{
	data->sprite_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->sprite_image, 0, 0) == -1)
		return (mlx_close_window(data->mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	mlx_set_instance_depth(data->sprite_image->instances, 3);
	return (0);
}

int	init_window(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!data->mlx)
		return (dprintf(2, "%s\n", mlx_strerror(mlx_errno)), 1);
	data->map_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->ray_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->map_image || !data->ray_image)
		return (mlx_close_window(data->mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	if (mlx_image_to_window(data->mlx, data->map_image, 0, 0) == -1)
		return (mlx_close_window(data->mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	if (mlx_image_to_window(data->mlx, data->ray_image, 0, 0) == -1)
		return (mlx_close_window(data->mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	if (BONUS && init_bonus(data))
		return (1);
	mlx_set_instance_depth(data->ray_image->instances, 2);
	mlx_set_instance_depth(data->map_image->instances, 1);
	raycast(data, data->ray, 0);
	mlx_loop_hook(data->mlx, key_hook, data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(data->mlx, cursor_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
