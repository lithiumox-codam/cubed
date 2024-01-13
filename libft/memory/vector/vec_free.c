/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_free.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:34:11 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/14 16:57:04 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Frees a vector and the data in it
 *
 * @param vec The vector to free
 */
void	vec_free(t_vector *vec)
{
	size_t	i;

	i = 0;
	if (vec->free)
	{
		while (i < vec->length)
		{
			vec->free(vec->data + i * vec->type_size);
			i++;
		}
	}
	free(vec->data);
	vec->data = NULL;
	vec->length = 0;
	vec->capacity = 0;
	vec->type_size = 0;
	vec->free = NULL;
}
