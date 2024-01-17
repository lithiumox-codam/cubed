/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:24:40 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/17 17:23:40 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_data			*data;
	static double	lastx;
	double			delta_x;

	(void)ypos;
	data = (t_data *)param;
	delta_x = xpos - lastx;
	lastx = xpos;
	data->player.dir = data->player.dir + (delta_x * 0.01);
	if (data->player.dir > 2 * M_PI)
		data->player.dir -= 2 * M_PI;
	if (data->player.dir < 0)
		data->player.dir += 2 * M_PI;
}
