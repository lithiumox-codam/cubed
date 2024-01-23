/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_texture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 16:11:38 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/01/23 16:06:04 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_ceiling(t_data *data, t_raycast *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(data->ray_image, x, y, data->textures.ceiling);
		y++;
	}
}

void	draw_floor(t_data *data, t_raycast *ray, int x)
{
	unsigned int	y;

	y = ray->draw_end;
	while (y < data->ray_image->height)
	{
		mlx_put_pixel(data->ray_image, x, y, data->textures.floor);
		y++;
	}
}


void	draw_tex_y(t_data *data, t_raycast *ray, mlx_texture_t *tex, int x)
{
	double			step;
	double			tex_pos;
	unsigned int	y;

	draw_ceiling(data, ray, x);
	y = ray->draw_start;
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - data->map_image->height / 2 + ray->line_height
			/ 2) * step;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		mlx_put_pixel(data->ray_image, x, y, tex->pixels[tex->height
			* ray->tex_y + ray->tex_x]);
		y++;
	}
	draw_floor(data, ray, x);
}