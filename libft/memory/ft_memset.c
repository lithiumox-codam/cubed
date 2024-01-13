/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:07:25 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Sets len bytes of memory to c
 *
 * @param b Address of memory to set
 * @param c Value to set memory to
 * @param len Amount of bytes to set
 * @return void* Address of b
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;

	i = -1;
	while (++i < len)
		((unsigned char *)b)[i] = (unsigned char)c;
	return (b);
}
