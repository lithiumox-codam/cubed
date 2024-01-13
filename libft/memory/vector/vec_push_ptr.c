/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_push_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:10:33 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/18 14:20:20 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

/**
 * @brief A function to push a pointer to the end of the vector
 *
 * @param vec The vector to push to
 * @param data The pointer to push
 * @return true When succeeded
 * @return false When failed
 */
bool	vec_push_ptr(t_vector *vec, void *data)
{
	if (vec->length == vec->capacity)
		if (vec_resize(vec, vec->capacity * 2) == false)
			return (false);
	*((void **)vec->data + vec->length) = data;
	vec->length++;
	return (true);
}
