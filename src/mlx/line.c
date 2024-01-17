/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:15:55 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/01/17 17:34:26 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void put_line(t_data *data, int x, int y, int col)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
		mlx_put_pixel(data->map_image, x, y, col);
}

void draw_line_from_angle(t_data *data, double start_x, double start_y, float angle, int len, int col)
{
	double end_x = start_x + len * cos(angle);
	double end_y = start_y + len * sin(angle);
	double dx = end_x - start_x;
	double dy = end_y - start_y;
	int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	double x_increment = dx / steps;
	double y_increment = dy / steps;
	double x = start_x;
	double y = start_y;
	int i = 0;

	while (i <= steps)
	{
		put_line(data, round(x), round(y), col);
		x += x_increment;
		y += y_increment;
		i++;
	}
}
