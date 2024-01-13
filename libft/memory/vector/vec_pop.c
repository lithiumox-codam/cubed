/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_pop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:31:31 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 21:17:56 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Pops the last element of the vector
 *
 * @param vec The vector to pop from
 * @return void* The popped element
 */

void	*vec_pop(t_vector *vec)
{
	void	*data;

	if (vec->length == 0)
		return (NULL);
	data = ft_calloc(1, vec->type_size * vec->length);
	if (!data)
		return (NULL);
	ft_memcpy(
		data,
		vec->data + (vec->length - 1) * vec->type_size,
		vec->type_size);
	vec->length--;
	return (data);
}
