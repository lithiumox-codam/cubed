/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 16:38:11 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Finds the last occurence of a character in a string
 *
 * @param s String to search
 * @param c Character to search for
 * @return char* Pointer to the last occurence of c in s, NULL if not found
 */
char	*ft_strrchr(const char *s, int c)
{
	int	dl;

	dl = ft_strlen(s);
	while (dl >= 0)
	{
		if (s[dl] == (char)c)
			return ((char *)s + dl);
		dl--;
	}
	return (NULL);
}
