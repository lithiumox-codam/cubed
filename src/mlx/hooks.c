/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:24:40 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/21 00:38:00 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_data			*data;
	static double	lastx;
	double			delta_x;

	(void)ypos;
	data = (t_data *)param;
	delta_x = xpos - lastx;
	lastx = xpos;
	data->player.dir = data->player.dir - (delta_x * 0.002);
	if (data->player.dir > 2 * M_PI)
		data->player.dir = 0;
	if (data->player.dir < 0)
		data->player.dir = 2 * M_PI;
}

static void	toggle_all_doors(t_map *map)
{
	int			i;
	int			j;
	static bool	toggled;

	toggled = false;
	if (toggled == false)
		toggled = true;
	else
		toggled = false;
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
		data->textures.sprite.current = (data->textures.sprite.current + 1)
			% data->textures.sprite.images.length;
		draw_minimap(data);
	}
}
