/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 16:22:17 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/13 18:19:48 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define SCALE 20

uint32_t	min(uint32_t a, uint32_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * @brief A function that draws walls based on a fraction of the image size
 * it takes in a color and a position and draws a square on the screen
 *
 * @param data The main struct
 * @param color The color to draw
 * @param x The x position to draw
 * @param y The y position to draw
*/
void	draw_square(t_data *data, int color, int x, int y)
{
	int	i;
	int	j;
	int	frac_h;
	int	frac_w;

	frac_h = data->minimap->height / SCALE;
	frac_w = data->minimap->width / SCALE;
	i = 0;
	while (i < frac_h)
	{
		j = 0;
		while (j < frac_w)
		{
			mlx_put_pixel(data->minimap, x * frac_w + j, y * frac_h + i, color);
			j++;
		}
		i++;
	}
}

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
			mlx_put_pixel(data->minimap, j, i, data->textures.floor);
			j++;
		}
		i++;
	}
}

void	determine_square(t_data *data, int i, int j)
{
	t_map_types	type;

	type = data->map.array[i][j];
	if (type == WALL)
		draw_square(data, 0xFF0000FF, i, j);
	else if (type == 4)
		draw_square(data, 0x00FF00FF, i, j);
	else if (type == 6)
		draw_square(data, 0x0000FFFF, i, j);
	else if (type == SPRITE)
		draw_square(data, 0xFFFF00FF, i, j);
	else
		draw_square(data, data->textures.floor, i, j);
}

/**
 * @brief Draws the minimap
 *
 * @param data The main struct
 */
void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	clear_image(data);
	while (i < SCALE)
	{
		j = 0;
		while (j < SCALE)
		{
			if (data->map.array[i][j] != 0)
				determine_square(data, i, j);
			j++;
		}
		i++;
	}
}
