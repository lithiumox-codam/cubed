/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 15:12:19 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/03/22 15:23:30 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map_types	safe_map(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (EMPTY);
	return (map->array[y][x]);
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

void	mm_square_wrapper(t_data *data, int x, int y)
{
	const double	offset = data->map_offset;
	const int		player_y = data->player.y * offset;
	const int		player_x = data->player.x * offset;
	int				draw_x;
	int				draw_y;

	draw_x = x * offset - player_x + data->minimap->width / 2;
	draw_y = y * offset - player_y + data->minimap->height / 2;
	if (data->map.array[y][x] == WALL)
		draw_square(data, draw_x, draw_y,
			get_tl_color(data->textures.wall.directions[N]));
	else if (data->map.array[y][x] == SPRITE)
		draw_square(data, draw_x, draw_y, 0xFF0000FF);
	else if (data->map.array[y][x] == OPEN_DOOR)
		draw_square(data, draw_x, draw_y,
			get_tl_color(data->textures.door_open.directions[N]));
	else if (data->map.array[y][x] == CLOSED_DOOR)
		draw_square(data, draw_x, draw_y,
			get_mid_color(data->textures.door_closed.directions[N]));
	else if (data->map.array[y][x] == FLOOR || data->map.array[y][x] == PLAYER)
		draw_square(data, draw_x, draw_y, data->textures.floor);
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	clear_image(data->minimap);
	data->map_offset = (data->minimap->width / data->map.width);
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			mm_square_wrapper(data, x, y);
			x++;
		}
		y++;
	}
	draw_dot(data->minimap);
	draw_line_player(data->minimap, data);
}
