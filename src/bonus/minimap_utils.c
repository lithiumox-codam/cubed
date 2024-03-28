/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 15:12:15 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/03/22 15:12:17 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	clear_image(mlx_image_t *img)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			mlx_put_pixel(img, j, i, 0);
			j++;
		}
		i++;
	}
}

void	draw_dot(mlx_image_t *img)
{
	int	i;
	int	j;
	int	center_x;
	int	center_y;

	i = -2;
	center_x = img->width / 2;
	center_y = img->height / 2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			mlx_put_pixel(img, center_x + i, center_y + j, 0xFF0000FF);
			j++;
		}
		i++;
	}
}

void	draw_line_player(mlx_image_t *img, t_data *data)
{
	double		dir;
	int			center_x;
	int			center_y;
	uint32_t	i;

	dir = data->player.dir;
	center_x = img->width / 2;
	center_y = img->height / 2;
	i = 0;
	while (i < img->width / 8)
	{
		mlx_put_pixel(img, center_x - i * cos(dir), center_y - i * sin(dir),
			0xFF0000FF);
		i++;
	}
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_offset)
	{
		j = 0;
		while (j < data->map_offset)
		{
			if (x + i >= 0 && y + j >= 0 && x + i < (int)data->minimap->width
				&& y + j < (int)data->minimap->height)
				mlx_put_pixel(data->minimap, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
