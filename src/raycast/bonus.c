/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 17:33:31 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/13 17:39:49 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Makes a copy of the ray and sets the texture type to the bonus type
 * and pushes it to the bonus vector in the data struct so it can be rendered
 * later
 *
 * @param data the main data struct
 * @param ray_og the original ray
 * @param type the type of bonus texture
 */
void	set_bonus_ray(t_data *data, t_raycast *ray_og, t_map_types type)
{
	t_raycast	ray_cp;

	ray_cp = *ray_og;
	ray_cp.txt_type = type;
	if (ray_cp.side == 0)
		ray_cp.perp_wall_dist = (ray_cp.side_dist_x - ray_cp.delta_dist_x);
	else
		ray_cp.perp_wall_dist = (ray_cp.side_dist_y - ray_cp.delta_dist_y);
	calc_line(data, &ray_cp);
	if (ray_cp.side == 0)
		ray_cp.wall_x = data->player.y + ray_cp.perp_wall_dist
			* ray_cp.ray_dir_y;
	else
		ray_cp.wall_x = data->player.x + ray_cp.perp_wall_dist
			* ray_cp.ray_dir_x;
	ray_cp.wall_x -= floor(ray_cp.wall_x);
	ray_cp.tex_x = (int)(ray_cp.wall_x * (double)texture(data, &ray_cp)->width);
	if (ray_cp.side == 0 && ray_cp.ray_dir_x > 0)
		ray_cp.tex_x = texture(data, &ray_cp)->width - ray_cp.tex_x - 1;
	if (ray_cp.side == 1 && ray_cp.ray_dir_y < 0)
		ray_cp.tex_x = texture(data, &ray_cp)->width - ray_cp.tex_x - 1;
	if (!vec_push(&data->bonus, &ray_cp))
		error(MALLOC, NULL);
}

/**
 * @brief Checks if the type provided is a bonus type and renderable
 *
 * @param type the type to check
 * @return true if the type is a bonus type
 * @return false if the type is not a bonus type
 */
bool	is_renderable(t_map_types type)
{
	if (type == CLOSED_DOOR || type == OPEN_DOOR || type == SPRITE)
		return (true);
	return (false);
}
