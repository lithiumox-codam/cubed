/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:19:30 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/01/17 15:32:46 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_circle(mlx_image_t *img, int centerX, int centerY, int color)
{
	int	radius;

	radius = CUBESIZE / 4;
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

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = (data->player.x * CUBESIZE);
	y = (data->player.y * CUBESIZE);
	draw_square(data->image, x, y, CUBESIZE / 2, get_rgba("255,230,0"));
	draw_line_from_angle(data, x + CUBESIZE / 4, y + CUBESIZE / 4, data->player.dir, CUBESIZE * 2, get_rgba("20,255,0"));
}
