/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:34:41 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/02/10 02:18:52 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_side_dist(t_data *data, t_raycast *ray)
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

static void	check_side_dist(t_raycast *ray)
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
}

static bool	is_renderable(t_map_types type, t_raycast *ray)
{
	if (type == WALL || type == OPEN_DOOR || type == CLOSED_DOOR)
	{
		ray->txt_type = type;
		return (true);
	}
	return (false);
}

static void	dda_loop(t_data *data, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		check_side_dist(ray);
		if (is_renderable(data->map.array[ray->map_y][ray->map_x], ray))
		{
			ray->hit = 1;
			if (ray->side == 0)
			{
				if (ray->step_x == -1)
					ray->hit_dir = W;
				else
					ray->hit_dir = E;
			}
			else
			{
				if (ray->step_y == -1)
					ray->hit_dir = N;
				else
					ray->hit_dir = S;
			}
		}
	}
}

void	calc_line(t_data *data, t_raycast *ray)
{
	ray->line_height = (data->ray_image->height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->ray_image->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->ray_image->height / 2;
	if (ray->draw_end >= data->ray_image->height)
		ray->draw_end = data->ray_image->height - 1;
}

void	dda(t_data *data, t_raycast *ray)
{
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	init_side_dist(data, ray);
	dda_loop(data, ray);
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	}
	else
	{
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	}
}
