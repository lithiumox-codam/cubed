/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_insert.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:40:55 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/14 16:56:54 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Inserts an element into the vector
 *
 * @param v The vector to insert into
 * @param i The index to insert at
 * @param data The data to insert
 * @return bool true when succeeded, false when failed
 *
 */
bool	vec_insert(t_vector *v, size_t i, void *data)
{
	if (i > v->length)
		return (false);
	if (v->length == v->capacity)
		if (vec_resize(v, v->capacity * 2) == false)
			return (false);
	ft_memmove(
		v->data + (i + 1) * v->type_size,
		v->data + i * v->type_size,
		(v->length - i) * v->type_size);
	ft_memcpy(v->data + i * v->type_size, data, v->type_size);
	free(data);
	v->length++;
	return (true);
}
