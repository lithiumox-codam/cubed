/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_char_push.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 23:16:39 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/16 23:17:54 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

/**
 * @brief Pushes a char to the end of the vector.
 *
 * @param vec The vector to push to.
 * @param c The char to push.
 */
bool	vec_char_push(t_vector *vec, char c)
{
	if (vec->length == vec->capacity)
		if (vec_resize(vec, vec->capacity * 2))
			return (false);
	((char *)vec->data)[vec->length] = c;
	vec->length++;
	return (true);
}
