/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker/jde-baai <team@codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:07:17 by mdekker       #+#    #+#                 */
/*   Updated: 2023/11/20 20:20:01 by mdekker/jde   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Copies n bytes from src to dst
 *
 * @param dst Address of memory to copy to
 * @param src Address of memory to copy from
 * @param n Amount of bytes to copy
 * @return void* Address of dst
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (n-- > 0)
		*(destination++) = *(source++);
	return (dst);
}
