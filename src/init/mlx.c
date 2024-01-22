/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:06:14 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/18 20:56:34 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_img(t_data *data, int color)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	(void)color;
	while (i < data->map_image->width)
	{
		j = 0;
		while (j < data->map_image->height)
		{
			mlx_put_pixel(data->map_image, i, j, 255);
			j++;
		}
		i++;
	}
}

bool	is_floor(t_data *data, double x, double y)
{
	int	mapx;
	int	mapy;

	mapx = (int)x;
	mapy = (int)y;
	if (data->map.array[mapy][mapx] == FLOOR
		|| data->map.array[mapy][mapx] == PLAYER)
		return (true);
	return (false);
}

void	set_new_pos(t_data *data, t_player player, t_info_types dir,
		double incr)
{
	double	newx;
	double	newy;

	newx = player.x;
	newy = player.y;
	if (dir == S)
	{
		newx = player.x - cos(player.dir) * incr;
		newy = player.y - sin(player.dir) * incr;
	}
	else if (dir == N)
	{
		newx = player.x + cos(player.dir) * incr;
		newy = player.y + sin(player.dir) * incr;
	}
	else if (dir == W)
	{
		newx = player.x + sin(player.dir) * incr;
		newy = player.y - cos(player.dir) * incr;
	}
	else if (dir == E)
	{
		newx = player.x - sin(player.dir) * incr;
		newy = player.y + cos(player.dir) * incr;
	}
	if (is_floor(data, newx, newy) && is_floor(data, newx + PLAYER_SIZE, newy
			+ PLAYER_SIZE) && is_floor(data, newx + PLAYER_SIZE, newy)
		&& is_floor(data, newx, newy + PLAYER_SIZE))
	{
		data->player.x = newx;
		data->player.y = newy;
	}
	raycast(data, data->ray);
}

void	draw_square(mlx_image_t *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	fill_img(data, 0 << 24 | 0 << 16 | 0 << 8 | 150);
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.array[y][x] == WALL)
				draw_square(data->map_image, x * CUBESIZE, y * CUBESIZE, CUBESIZE
						- 1, 255 << 24 | 0 << 16 | 0 << 8 | 255);
			else if (data->map.array[y][x] == FLOOR
					|| data->map.array[y][x] == PLAYER)
				draw_square(data->map_image, x * CUBESIZE, y * CUBESIZE, CUBESIZE
						- 1, 255 << 24 | 255 << 16 | 255 << 8 | 255);
			else if (data->map.array[y][x] == EMPTY)
				draw_square(data->map_image, x * CUBESIZE, y * CUBESIZE, CUBESIZE
						- 1, 0 << 24 | 0 << 16 | 0 << 8 | 255);
			x++;
		}
		y++;
	}
	draw_player(data);
}

void	key_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
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
	raycast(data, data->ray);

}

int	init_window(t_data *data)
{
	static mlx_image_t	*map_image;
	static mlx_image_t	*ray_image;
	mlx_t				*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		return (dprintf(2, "%s\n", mlx_strerror(mlx_errno)), 1);
	map_image = mlx_new_image(mlx, WIDTH, HEIGHT);
	ray_image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!map_image || !ray_image)
		return (mlx_close_window(mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	if (mlx_image_to_window(mlx, map_image, 0, 0) == -1)
		return (mlx_close_window(mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	if (mlx_image_to_window(mlx, ray_image, 0, 0) == -1)
		return (mlx_close_window(mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	data->mlx = mlx;
	data->map_image = map_image;
	data->ray_image = ray_image;
	// draw_map(data);
	raycast(data, data->ray);
	mlx_loop_hook(mlx, key_hook, data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(mlx, cursor_hook, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
