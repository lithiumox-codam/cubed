/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 21:52:28 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/14 16:57:17 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Reallocates a memory space, copies it then frees the old space
 *
 * @param ptr The memory to reallocate
 * @param size The new size of the space in bytes
 * @return void* The reallocated memory or NULL when failed
 *
 * @warning When the new size is smaller than the old size, the data will be
 * lost. Watch out for memory leaks! 🚰
 */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (old_size == new_size)
		return (ptr);
	if (old_size > new_size)
		old_size = new_size;
	new = ft_calloc(1, new_size);
	if (!new)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(new, ptr, old_size);
		free(ptr);
	}
	return (new);
}
