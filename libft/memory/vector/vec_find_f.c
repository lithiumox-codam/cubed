/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_find_f.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 14:11:53 by mdekker       #+#    #+#                 */
/*   Updated: 2023/10/31 17:30:13 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @brief Finds the first occurance of an item in a vector that matches the
 * given function
 *
 * @param v The vector to search in
 * @param f The function to use as a filter
 * @return void * The item that matches the function or NULL if not found
 */
void	*vec_find_f(t_vector *v, bool (*f)(void *, void *), void *data)
{
	size_t	i;

	i = 0;
	while (i < v->length)
	{
		if (f(vec_get(v, i), data))
			return (vec_get(v, i));
		i++;
	}
	return (NULL);
}
