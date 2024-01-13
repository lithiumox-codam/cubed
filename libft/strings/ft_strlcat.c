/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:07:28 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Appends src to dst, but only up to
 * dstsize - 1 characters,
 * and adds a terminating '\0'
 *
 * @param dst Pointer to the destination string
 * @param src Pointer to the source string
 * @param dstsize The size of the destination string

	* @return size_t Len of string or size of dst
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dl;
	size_t	sl;

	i = 0;
	j = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dstsize == 0)
		return (sl);
	if (dstsize <= dl)
		return (dstsize + sl);
	while (dst[i])
		i++;
	while (src[j] && j < dstsize - dl - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dl + sl);
}
