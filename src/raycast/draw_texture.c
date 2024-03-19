/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_texture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 16:11:38 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/03/13 17:49:12 by mdekker       ########   odam.nl         */
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

void	draw_tex_y(t_data *data, t_raycast *ray, mlx_texture_t *tex, int x)
{
	double			step;
	double			tex_pos;
	unsigned int	y;
	uint32_t		color;

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
		mlx_put_pixel(data->ray_image, x, y, color);
		y++;
	}
	draw_floor(data, ray, x);
}

/**
 * @brief The main function that draws the door on the screen
 *
 * @param data The main data struct
 * @param ray The ray struct
 * @param tex The texture to use
 * @param x The x position on the screen
 */
void	draw_tex_door(t_data *data, t_raycast *ray, mlx_texture_t *tex, int x)
{
	double			step;
	double			tex_pos;
	unsigned int	y;
	uint32_t		color;

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
		if ((color & 0x000000FF) != 0)
			mlx_put_pixel(data->door_image, x, y, color);
		y++;
	}
}

/**
 * @brief Draws a sprite on the screen using the texture and the ray
 * Remember to make the sprite transparent. otherwise it will look like a wall.
 *
 * @param data The main data struct
 * @param ray The ray struct
 * @param tex The texture to use
 * @param x The x position on the screen
 */
void	draw_tex_sprite(t_data *data, t_raycast *ray, mlx_texture_t *tex, int x)
{
	double			step;
	double			tex_pos;
	unsigned int	y;
	uint32_t		color;

	y = ray->draw_start;
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = 0;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)tex_pos;
		tex_pos += step;
		color = *(int *)&tex->pixels[(tex->width * ray->tex_y + ray->tex_x)
			* 4];
		if ((color & 0x000000FF) != 0)
			mlx_put_pixel(data->door_image, x, y, color);
		y++;
	}
}
