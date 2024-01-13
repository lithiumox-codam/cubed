/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:19:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/14 16:56:58 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Initializes a vector
 *
 * @param vec The vector to initialize
 * @param capacity The total amount of elements the vector can hold
 * @param type_size The size of the content of the vector
 * @param f The function to free the data in the vector or NULL when not needed
 * @return void * The initialized vector or NULL if malloc fails
 */
void	*vec_init(t_vector *vec, size_t capacity, size_t type_size,
		void (*free_data)(void *))
{
	vec->data = malloc(capacity * type_size);
	if (!vec->data)
		return (NULL);
	vec->length = 0;
	vec->capacity = capacity;
	vec->type_size = type_size;
	vec->free = free_data;
	return (vec);
}
