/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_replace.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 13:09:13 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/28 23:07:13 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Replaces one element in the vector with the provided data
 *
 * @param vec The vector to replace in
 * @param index The index of the element to replace
 * @param data The data to replace with
 *
 * @return void* The pointer to the replaced element or NULL if the
 * replacement failed
 *
 * !TODO add a function to replace multiple elements at once
 */
void	*vec_replace(t_vector *vec, size_t index, void *data)
{
	if (!vec_set(vec, index, data))
		return (NULL);
	return (vec->data + index * vec->type_size);
}
