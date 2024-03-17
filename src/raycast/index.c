/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:02:10 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/03/13 17:31:16 by maxvalk       ########   odam.nl         */
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

mlx_texture_t	*determine_texture(t_data *data, t_raycast *ray)
{
	if (ray->txt_type == WALL)
		return (data->textures.wall.directions[ray->hit_dir]);
	else if (ray->txt_type == CLOSED_DOOR)
		return (data->textures.door_closed.directions[0]);
	else if (ray->txt_type == OPEN_DOOR)
		return (data->textures.door_open.directions[0]);
	else if (ray->txt_type == SPRITE)
		return (*(mlx_texture_t **)vec_get(&data->textures.sprite.images,
				data->textures.sprite.current));
	return (data->textures.wall.directions[ray->hit_dir]);
}

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

void	draw_tex_sprite(t_data *data, t_raycast *ray, mlx_texture_t *tex, int x)
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

void	fill_clear_image(mlx_image_t *img)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, 0);
			x++;
		}
		y++;
	}
}

static void	draw_bonus(t_data *data)
{
	t_raycast	*ray_cp;

	if (!BONUS)
		return ;
	fill_clear_image(data->door_image);
	if (data->bonus.length == 0)
		return ;
	while (data->bonus.length > 0)
	{
		ray_cp = (t_raycast *)vec_get(&data->bonus, data->bonus.length - 1);
		if (ray_cp == NULL)
			return ;
		if (ray_cp->txt_type == CLOSED_DOOR || ray_cp->txt_type == OPEN_DOOR)
			draw_tex_door(data, ray_cp, determine_texture(data, ray_cp),
				ray_cp->x);
		else if (ray_cp->txt_type == SPRITE)
			draw_tex_sprite(data, ray_cp, determine_texture(data, ray_cp),
				ray_cp->x);
		data->bonus.length--;
	}
}

void	raycast(t_data *data, t_raycast *ray, unsigned int x)
{
	init_ray_plane(ray, data->player.dir);
	while (x < data->ray_image->width)
	{
		ray->x = x;
		ray->camera_x = 2 * x / (double)data->ray_image->width - 1;
		ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		dda(data, ray);
		calc_line(data, ray);
		// data->hit_depth[x] = ray->perp_wall_dist;
		if (ray->side == 0)
			ray->wall_x = data->player.y + ray->perp_wall_dist * ray->ray_dir_y;
		else
			ray->wall_x = data->player.x + ray->perp_wall_dist * ray->ray_dir_x;
		ray->wall_x -= floor(ray->wall_x);
		ray->tex_x = (int)(ray->wall_x * (double)determine_texture(data,
					ray)->width);
		if (ray->side == 0 && ray->ray_dir_x > 0)
			ray->tex_x = determine_texture(data, ray)->width - ray->tex_x - 1;
		if (ray->side == 1 && ray->ray_dir_y < 0)
			ray->tex_x = determine_texture(data, ray)->width - ray->tex_x - 1;
		draw_tex_y(data, ray, determine_texture(data, ray), x);
		x++;
	}
	draw_bonus(data);
}
