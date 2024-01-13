/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_remove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker/jde-baai <team@codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:47:29 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/14 16:56:48 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Removes an element from the vector
 *
 * @param v The vector to remove from
 * @param i The index of the element to remove
 * @return void* The new vector
 */
void	*vec_remove(t_vector *v, size_t i)
{
	if (i >= v->length)
		return (NULL);
	if (v->free)
		v->free(v->data + i * v->type_size);
	ft_memmove(
		v->data + i * v->type_size,
		v->data + (i + 1) * v->type_size,
		(v->length - i - 1) * v->type_size);
	v->length--;
	return (v->data);
}
