/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:02:10 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/01/23 16:02:51 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// void	init_side_dist(t_data *data, t_raycast *ray)
// {
// 	if (ray->ray_dir_x < 0)
// 	{
// 		ray->step_x = -1;
// 		ray->side_dist_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
// 	}
// 	else
// 	{
// 		ray->step_x = 1;
// 		ray->side_dist_x = (ray->map_x + 1.0 - data->player.x)
// 			* ray->delta_dist_x;
// 	}
// 	if (ray->ray_dir_y < 0)
// 	{
// 		ray->step_y = -1;
// 		ray->side_dist_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
// 	}
// 	else
// 	{
// 		ray->step_y = 1;
// 		ray->side_dist_y = (ray->map_y + 1.0 - data->player.y)
// 			* ray->delta_dist_y;
// 	}
// }

// void	dda_loop(t_data *data, t_raycast *ray)
// {
// 	while (ray->hit == 0)
// 	{
// 		if (ray->side_dist_x < ray->side_dist_y)
// 		{
// 			ray->side_dist_x += ray->delta_dist_x;
// 			ray->map_x += ray->step_x;
// 			ray->side = 0;
// 		}
// 		else
// 		{
// 			ray->side_dist_y += ray->delta_dist_y;
// 			ray->map_y += ray->step_y;
// 			ray->side = 1;
// 		}
// 		if (data->map.array[ray->map_y][ray->map_x] == WALL)
// 		{
// 			ray->hit = 1;
// 			if (ray->side == 0)
// 			{
// 				if (ray->step_x == -1)
// 					ray->wall_dir = W;
// 				else
// 					ray->wall_dir = E;
// 			}
// 			else
// 			{
// 				if (ray->step_y == -1)
// 					ray->wall_dir = N;
// 				else
// 					ray->wall_dir = S;
// 			}
// 		}
// 	}
// }

void	draw_line(t_data *data, t_raycast *ray, int x)
{
	unsigned int	y;
	int				y2;
	int				red;
	int				green;
	int				blue;
	int				white;
	int				roof;


	y2 = 0;
	red = get_rgba("255,0,0");
	green = get_rgba("0,255,0");
	blue = get_rgba("0,0,255");
	white = get_rgba("255,255,255");
	roof = get_rgba("0,0,0");
	y = ray->draw_start;
	while (y2 < ray->draw_start)
	{
		mlx_put_pixel(data->ray_image, x, y2, roof);
		y2++;
	}
	while (y < ray->draw_end)
	{
		if (ray->wall_dir == N)
			mlx_put_pixel(data->ray_image, x, y, red);
		else if (ray->wall_dir == S)
			mlx_put_pixel(data->ray_image, x, y, green);
		else if (ray->wall_dir == E)
			mlx_put_pixel(data->ray_image, x, y, blue);
		else if (ray->wall_dir == W)
			mlx_put_pixel(data->ray_image, x, y, white);
		y++;
	}
	while (y < data->ray_image->height)
	{
		mlx_put_pixel(data->ray_image, x, y, 0);
		y++;
	}
}

// void	calc_line(t_data *data, t_raycast *ray)
// {
// 	ray->line_height = (data->ray_image->height / ray->perp_wall_dist);
// 	ray->draw_start = -ray->line_height / 2 + data->ray_image->height / 2;
// 	if (ray->draw_start < 0)
// 		ray->draw_start = 0;
// 	ray->draw_end = ray->line_height / 2 + data->ray_image->height / 2;
// 	if (ray->draw_end >= data->ray_image->height)
// 		ray->draw_end = data->ray_image->height - 1;
// }

// void	dda(t_data *data, t_raycast *ray)
// {
// 	ray->map_x = (int)data->player.x;
// 	ray->map_y = (int)data->player.y;
// 	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
// 	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
// 	ray->hit = 0;
// 	init_side_dist(data, ray);
// 	dda_loop(data, ray);
// 	if (ray->side == 0)
// 		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
// 	else
// 		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
// }

void	raycast(t_data *data, t_raycast *ray)
{
	unsigned int	x;
	double			tmp_dir;
	double			old_plane_x;
	double			old_plane_y;
	double			old_dir_x;
	double			old_dir_y;

	ray->plane_x = 0;
	ray->plane_y = 0.9;
	ray->dir_x = 1;
	ray->dir_y = 0;
	x = 0;
	tmp_dir = data->player.dir;
	old_plane_x = ray->plane_x;
	old_plane_y = ray->plane_y;
	old_dir_x = ray->dir_x;
	old_dir_y = ray->dir_y;
	ray->plane_x = old_plane_x * cos(tmp_dir) - old_plane_y * sin(tmp_dir);
	ray->plane_y = old_plane_x * sin(tmp_dir) + old_plane_y * cos(tmp_dir);
	ray->dir_x = old_dir_x * cos(tmp_dir) - old_dir_y * sin(tmp_dir);
	ray->dir_y = old_dir_x * sin(tmp_dir) + old_dir_y * cos(tmp_dir);
	while (x < data->ray_image->width)
	{
		ray->camera_x = 2 * x / (double)data->ray_image->width - 1;
		ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		dda(data, ray);
		calc_line(data, ray);
		draw_tex_y(data, ray, data->textures.wall.directions[N], x);
		// draw_line(data, ray, x);
		x++;
	}
}
