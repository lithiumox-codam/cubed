/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxvalk <maxvalk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:33:14 by maxvalk       #+#    #+#                 */
/*   Updated: 2024/01/22 16:29:57 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static	void	free_ray(void *ray)
// {
// 	free((t_raycast *)ray);
// }

t_vector	*init_frame(t_data *data)
{
	t_vector	*frame;
	int			i;

	frame = NULL;
	vec_init(frame, WIDTH, sizeof(t_raycast), free);
	if (!frame)
		return (NULL);
	i = 0;
	while (i < WIDTH)
	{
		vec_push(frame, data->ray);
		i++;
	}
	return (frame);
}
