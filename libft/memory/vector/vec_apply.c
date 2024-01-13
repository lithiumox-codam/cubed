/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_apply.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 23:48:40 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:31:05 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Applies a function to all elements in the vector
 *
 * @param vec The vector to apply the function to
 * @param f The function to apply
 */
void	vec_apply(t_vector *vec, void (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < vec->length)
	{
		f(vec->data + i * vec->type_size);
		i++;
	}
}
