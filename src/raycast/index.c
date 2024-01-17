/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:02:10 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/01/17 17:35:56 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_side_dist(t_data *data, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.y)
			* ray->delta_dist_y;
	}
}

void	dda_loop(t_data *data, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.array[ray->map_y][ray->map_x] == WALL)
			ray->hit = 1;
	}
}

void	draw_line(t_data *data, t_raycast *ray, int x)
{
	int	y;
	int	color;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		color = 0;
		if (ray->side == 1)
			color = get_rgba("0,255,0");
		else
			color = get_rgba("255,0,0");
		mlx_put_pixel(data->ray_image, x, y, color);
		y++;
	}
}

void	calc_line(t_data *data, t_raycast *ray)
{
	ray->line_height = (data->map.height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->map.height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->map.height / 2;
	if (ray->draw_end >= data->map.height)
		ray->draw_end = data->map.height - 1;
}

void	dda(t_data *data, t_raycast *ray)
{
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	if (ray->ray_dir_x == 0)
		ray->ray_dir_x = INFINITY;
	if (ray->ray_dir_y == 0)
		ray->ray_dir_y = INFINITY;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	init_side_dist(data, ray);
	dda_loop(data, ray);
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void	raycast(t_data *data)
{
	t_raycast	ray;
	double		dir_x;
	double		dir_y;
	int			x;

	ft_memset(&ray, 0, sizeof(t_raycast));
	ray.plane_x = 0;
	ray.plane_y = 0.66;
	dir_x = -1;
	dir_y = 0;
	x = 0;
	while (x < data->map.width)
	{
		ray.camera_x = 2 * x / (double)data->map.width - 1;
		ray.ray_dir_x = dir_x + ray.plane_x * ray.camera_x;
		ray.ray_dir_y = dir_y + ray.plane_y * ray.camera_x;
		dda(data, &ray);
		calc_line(data, &ray);
		draw_line(data, &ray, x);
		x++;
	}
}
