/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 16:22:17 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/09 17:22:15 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_objects	*create_object(t_map_types type, int y, int x)
{
	t_objects	*object;

	object = malloc(sizeof(t_objects));
	if (object == NULL)
		return (NULL);
	object->type = type;
	object->distance = 0;
	object->x = x;
	object->y = y;
	// printf("object created at %d, %d\n", object->y, object->x);
		// TODO: remove
	return (object);
}
