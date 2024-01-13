/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:07:20 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_loop(char *dst, char *src, size_t len, size_t dir)
{
	size_t	i;

	i = 0;
	if (dir == 0)
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (dir == 1)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst[i] = src[i];
		}
	}
}

/**
 * @brief Copies len bytes from src to dst. The two strings may overlap.
 *
 * @param dst Address of memory to copy to
 * @param src Address of memory to copy from
 * @param len Amount of bytes to copy
 * @return void* Address of dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*to;
	char	*from;

	to = (char *)dst;
	from = (char *)src;
	if (to < from)
		ft_loop(to, from, len, 0);
	else if (to > from)
		ft_loop(to, from, len, 1);
	return (dst);
}
