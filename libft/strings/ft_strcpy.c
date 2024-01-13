/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 21:36:22 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Copy the string src to dst (including the terminating `\0' character.)
 *
 * @param dst The destination string.
 * @param src The source string.
 * @return char* A pointer to the destination string dst.
 */
char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (*(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = *(src + i);
	return (dst);
}
