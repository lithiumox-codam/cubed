/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:02:10 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/02/14 01:20:13 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_ray_plane(t_raycast *ray, double dir)
{
	double	old_plane_x;
	double	old_plane_y;
	double	old_dir_x;
	double	old_dir_y;

	ray->plane_x = 0;
	ray->plane_y = 0.9;
	ray->dir_x = -1;
	ray->dir_y = 0;
	old_plane_x = ray->plane_x;
	old_plane_y = ray->plane_y;
	old_dir_x = ray->dir_x;
	old_dir_y = ray->dir_y;
	ray->plane_x = old_plane_x * cos(dir) - old_plane_y * sin(dir);
	ray->plane_y = old_plane_x * sin(dir) + old_plane_y * cos(dir);
	ray->dir_x = old_dir_x * cos(dir) - old_dir_y * sin(dir);
	ray->dir_y = old_dir_x * sin(dir) + old_dir_y * cos(dir);
}

static mlx_texture_t	*determine_texture(t_data *data)
{
	if (data->ray->txt_type == WALL)
		return (data->textures.wall.directions[data->ray->hit_dir]);
	else if (data->ray->txt_type == CLOSED_DOOR)
		return (data->textures.door_closed.directions[data->ray->hit_dir]);
	else if (data->ray->txt_type == OPEN_DOOR)
		return (data->textures.door_open.directions[data->ray->hit_dir]);
	return (NULL);
}

static void	apply_distance(t_data *data, t_vector *obj)
{
	size_t		i;
	t_objects	*o;
	t_player	*p;

	p = &data->player;
	i = 0;
	while (i < obj->length)
	{
		o = *(t_objects **)vec_get(obj, i);
		o->type = data->map.array[(int)o->y][(int)o->x];
		o->distance = sqrt(pow((p->x - o->x), 2) + pow((p->y - o->y), 2));
		i++;
	}
}

void	raycast(t_data *data, t_raycast *ray, unsigned int x)
{
	init_ray_plane(ray, data->player.dir);
	while (x < data->ray_image->width)
	{
		ray->camera_x = 2 * x / (double)data->ray_image->width - 1;
		ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		dda(data, ray);
		if (ray->side == 0)
			ray->wall_x = data->player.y + ray->perp_wall_dist * ray->ray_dir_y;
		else
			ray->wall_x = data->player.x + ray->perp_wall_dist * ray->ray_dir_x;
		ray->wall_x -= floor(ray->wall_x);
		ray->tex_x = (int)(ray->wall_x
				* (double)determine_texture(data)->width);
		if (ray->side == 0 && ray->ray_dir_x > 0)
			ray->tex_x = determine_texture(data)->width - ray->tex_x - 1;
		if (ray->side == 1 && ray->ray_dir_y < 0)
			ray->tex_x = determine_texture(data)->width - ray->tex_x - 1;
		calc_line(data, ray);
		draw_tex_y(data, ray, determine_texture(data), x);
		x++;
	}
	apply_distance(data, &data->objects);
}
