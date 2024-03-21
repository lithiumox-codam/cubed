#include <cub3d.h>

void	clear_image(t_data *data)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < data->minimap->height)
	{
		j = 0;
		while (j < data->minimap->width)
		{
			mlx_put_pixel(data->minimap, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

t_map_types	safe_map(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (EMPTY);
	return (map->array[y][x]);
}

void	draw_dot(mlx_image_t *img)
{
	int	i;
	int	j;
	int	centerX;
	int	centerY;

	i = -2;
	centerX = img->width / 2;
	centerY = img->height / 2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			mlx_put_pixel(img, centerX + i, centerY + j, 0xFF0000FF);
			j++;
		}
		i++;
	}
}

void	draw_line_player(mlx_image_t *img, t_data *data)
{
	double		dir;
	int			centerX;
	int			centerY;
	uint32_t	i;

	dir = data->player.dir;
	centerX = img->width / 2;
	centerY = img->height / 2;
	i = 0;
	while (i < img->width / 8)
	{
		mlx_put_pixel(img, centerX - i * cos(dir), centerY - i * sin(dir),
				0xFF0000FF);
		i++;
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
			if (x + i >= 0 && y + j >= 0 && x + i < (int)img->width && y
				+ j < (int)img->height)
				mlx_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	get_tl_color(mlx_texture_t *tex)
{
	return (*(int *)&tex->pixels[(tex->width * 0 + 0) * 4]);
}

int	get_mid_color(mlx_texture_t *tex)
{
	return (*(int *)&tex->pixels[(tex->width * tex->height / 2 + tex->width / 2)
		* 4]);
}

void	draw_minimap(t_data *data)
{
	double	offset;
	int		x;
	int		y;
	int		playerX;
	int		playerY;
	int		drawX;
	int		drawY;

	clear_image(data);
	offset = (data->minimap->width / data->map.width);
	playerX = data->player.x * offset;
	playerY = data->player.y * offset;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			drawX = x * offset - playerX + data->minimap->width / 2;
			drawY = y * offset - playerY + data->minimap->height / 2;
			if (data->map.array[y][x] == WALL)
				draw_square(data->minimap, drawX, drawY, offset,
						get_tl_color(data->textures.wall.directions[N]));
			else if (data->map.array[y][x] == SPRITE)
				draw_square(data->minimap, drawX, drawY, offset, 0xFF0000FF);
			else if (data->map.array[y][x] == OPEN_DOOR)
				draw_square(data->minimap, drawX, drawY, offset,
						get_tl_color(data->textures.door_open.directions[N]));
			else if (data->map.array[y][x] == CLOSED_DOOR)
				draw_square(data->minimap, drawX, drawY, offset,
						get_mid_color(data->textures.door_closed.directions[N]));
			else if (data->map.array[y][x] == FLOOR
					|| data->map.array[y][x] == PLAYER)
				draw_square(data->minimap, drawX, drawY, offset,
						data->textures.floor);
			x++;
		}
		y++;
	}
	draw_dot(data->minimap);
	draw_line_player(data->minimap, data);
}
