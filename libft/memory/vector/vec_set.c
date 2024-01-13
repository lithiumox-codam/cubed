/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_set.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 15:38:28 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/24 09:45:27 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Reuses the current blocks of memory frees any pointers then proceeds
 * to set the values of an individual element in the vector
 *
 * @param vec The vector to replace in
 * @param index The index of the element to set
 * @param data The data to set the element with
 */
void	*vec_set(t_vector *vec, size_t index, void *data)
{
	if (vec->free)
		vec->free(vec->data + index * vec->type_size);
	ft_memcpy(vec->data + index * vec->type_size, data, vec->type_size);
	return (vec->data + index * vec->type_size);
}
