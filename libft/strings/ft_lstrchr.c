/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 23:49:31 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/17 16:38:42 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Finds the first occurence of a character in a string
 *
 * @param s String to search
 * @param c Character to search for
 * @param len Length of the string to search
 * @return char* Pointer to the first occurence of c in s, NULL if not found
 */
char	*ft_lstrchr(const char *s, int c, int len)
{
	while (*s && len > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		len--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
