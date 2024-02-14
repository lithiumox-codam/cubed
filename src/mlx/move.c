/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:21:47 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/02/14 01:22:20 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	is_floor(t_data *data, double x, double y)
{
	int	mapx;
	int	mapy;

	mapx = (int)x;
	mapy = (int)y;
	if (data->map.array[mapy][mapx] == FLOOR
		|| data->map.array[mapy][mapx] == PLAYER
		|| data->map.array[mapy][mapx] == OPEN_DOOR
		|| data->map.array[mapy][mapx] == SPRITE)
		return (true);
	return (false);
}

double	set_newx(t_player player, t_info_types dir, double incr)
{
	double	newx;

	newx = player.x;
	if (dir == S)
		newx = player.x + cos(player.dir) * incr;
	else if (dir == N)
		newx = player.x - cos(player.dir) * incr;
	else if (dir == W)
		newx = player.x + sin(player.dir) * incr;
	else if (dir == E)
		newx = player.x - sin(player.dir) * incr;
	return (newx);
}

double	set_newy(t_player player, t_info_types dir, double incr)
{
	double	newy;

	newy = player.y;
	if (dir == S)
		newy = player.y + sin(player.dir) * incr;
	else if (dir == N)
		newy = player.y - sin(player.dir) * incr;
	else if (dir == W)
		newy = player.y - cos(player.dir) * incr;
	else if (dir == E)
		newy = player.y + cos(player.dir) * incr;
	return (newy);
}

void	set_new_pos(t_data *data, t_player player, t_info_types dir,
		double incr)
{
	double	newx;
	double	newy;

	newx = set_newx(player, dir, incr);
	newy = set_newy(player, dir, incr);
	if (is_floor(data, newx, newy))
	{
		data->player.x = newx;
		data->player.y = newy;
	}
}
