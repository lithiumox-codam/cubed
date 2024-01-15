#include <cub3d.h>
// #include <config.h>

void	fill_img(t_data *data, int color)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	(void)color;
	while (i < data->image->width)
	{
		j = 0;
		while (j < data->image->height)
		{
			mlx_put_pixel(data->image, i, j, 255);
			j++;
		}
		i++;
	}
}

void draw_circle(mlx_image_t *img, int centerX, int centerY, int color)
{
	int radius = CUBESIZE / 4;
	int x, y;

	for (int i = -radius; i <= radius; i++)
	{
		for (int j = -radius; j <= radius; j++)
		{
			if (i * i + j * j <= radius * radius)
			{
				x = centerX + i;
				y = centerY + j;
				mlx_put_pixel(img, x, y, color);
			}
		}
	}
}

void	set_new_pos(t_data *data, double newy, double newx)
{
	// printf("newx: %f, newy: %f\n", newx, newy);
	// printf("data->map.array[newy][newx]: %d\n", data->map.array[(int)newy][(int)newx]);
	// printf("data->map.array[(int)data->player.y][(int)data->player.x]: %d\n",
		// data->map.array[(int)data->player.y][(int)data->player.x]);
	// printf("data->player.x: %f, data->player.y: %f\n", data->player.x,
	
	if (data->map.array[(int)newy][(int)newx] == FLOOR || data->map.array[(int)newy][(int)newx] == PLAYER)
	{
		data->player.x = newx;
		data->player.y = newy;
	}
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

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = (data->player.x * CUBESIZE) + (CUBESIZE / 2);
	y = (data->player.y * CUBESIZE) + (CUBESIZE / 2);
	draw_circle(data->image, x, y, get_rgba("255,230,0"));
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
				draw_square(data->image, x * CUBESIZE, y * CUBESIZE, CUBESIZE
					- 1, 255 << 24 | 0 << 16 | 0 << 8 | 255);
			else if (data->map.array[y][x] == FLOOR
				|| data->map.array[y][x] == PLAYER)
				draw_square(data->image, x * CUBESIZE, y * CUBESIZE, CUBESIZE
					- 1, 255 << 24 | 255 << 16 | 255 << 8 | 255);
			// else if (data->map.array[y][x] == PLAYER)
			// 	draw_square(data->image, x * CUBESIZE, y * CUBESIZE, CUBESIZE
					// - 1, 255 << 24 | 255 << 16 | 0 << 8 | 255);
			else if (data->map.array[y][x] == EMPTY)
				draw_square(data->image, x * CUBESIZE, y * CUBESIZE, CUBESIZE
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
		set_new_pos(data, data->player.y - 0.1, data->player.x);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		set_new_pos(data, data->player.y + 0.1, data->player.x);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		set_new_pos(data, data->player.y, data->player.x - 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		set_new_pos(data, data->player.y, data->player.x + 0.1);
	draw_map(data);
	usleep(50000);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	// 	data->player.dir -= 0.1;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	// 	data->player.dir += 0.1;
}

int	init_window(t_data *data)
{
	static mlx_image_t	*image;
	mlx_t				*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		return (dprintf(2, "%s\n", mlx_strerror(mlx_errno)), 1);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		return (mlx_close_window(mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		return (mlx_close_window(mlx), dprintf(2, "%s\n",
				mlx_strerror(mlx_errno)), 1);
	data->mlx = mlx;
	data->image = image;
	draw_map(data);
	mlx_loop_hook(mlx, key_hook, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
