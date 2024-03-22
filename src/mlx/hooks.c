/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:24:40 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/22 10:36:20 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static mouse_mode_t	mode_set(t_data *data, mouse_mode_t mode)
{
	static mouse_mode_t	current_mode;
	static double		last_press = 0;

	current_mode = MLX_MOUSE_DISABLED;
	if (mlx_get_time() - last_press < 0.5)
		return (current_mode);
	if (mode == MLX_MOUSE_DISABLED)
	{
		current_mode = MLX_MOUSE_DISABLED;
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	}
	else if (mode == MLX_MOUSE_NORMAL)
	{
		current_mode = MLX_MOUSE_NORMAL;
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	}
	return (current_mode);
}

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_data			*data;
	static double	lastx;
	double			delta_x;

	(void)ypos;
	data = (t_data *)param;
	if (mode_set(data, MLX_MOUSE_HIDDEN) == MLX_MOUSE_NORMAL)
		return ;
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
	int				i;
	int				j;
	static double	last_press = 0;

	i = 0;
	if (mlx_get_time() - last_press < 0.5)
		return ;
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
	last_press = mlx_get_time();
}

static void	esq_hook(t_data *data)
{
	static double	last_press = 0;

	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		if (mlx_get_time() - last_press < 0.5)
			return ;
		if (mode_set(data, MLX_MOUSE_HIDDEN) == MLX_MOUSE_DISABLED)
			mode_set(data, MLX_MOUSE_NORMAL);
		else if (mode_set(data, MLX_MOUSE_HIDDEN) == MLX_MOUSE_NORMAL)
			mode_set(data, MLX_MOUSE_DISABLED);
		last_press = mlx_get_time();
	}
	else
		mlx_close_window(data->mlx);
}

void	key_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->frame_count++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		esq_hook(data);
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
	arrow_keys(data);
	raycast(data, data->ray, 0);
	if (BONUS && data->frame_count % 5 == 0)
	{
		data->textures.sprite.current = (data->textures.sprite.current + 1)
			% data->textures.sprite.images.length;
	}
	else if (BONUS)
		draw_minimap(data);
}
