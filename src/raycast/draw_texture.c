/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_texture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 16:11:38 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/01/24 04:01:18 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_ceiling(t_data *data, t_raycast *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(data->ray_image, x, y, data->textures.ceiling);
		y++;
	}
}

static void	draw_floor(t_data *data, t_raycast *ray, int x)
{
	unsigned int	y;

	y = ray->draw_end;
	while (y < data->ray_image->height)
	{
		mlx_put_pixel(data->ray_image, x, y, data->textures.floor);
		y++;
	}
}

static int	argb_to_rgba(int color)
{
	int	r;
	int	g;
	int	b;
	int	a;

	a = (color >> 24) & 0xFF;
	b = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	r = color & 0xFF;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_tex_y(t_data *data, t_raycast *ray, mlx_texture_t *tex, int x)
{
	double			step;
	double			tex_pos;
	unsigned int	y;
	int				color;

	draw_ceiling(data, ray, x);
	y = ray->draw_start;
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - data->ray_image->height / 2 + ray->line_height
			/ 2) * step;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)tex_pos;
		tex_pos += step;
		color = *(int *)&tex->pixels[(tex->width * ray->tex_y + ray->tex_x)
			* 4];
		color = argb_to_rgba(color);
		mlx_put_pixel(data->ray_image, x, y, color);
		y++;
	}
	draw_floor(data, ray, x);
}
