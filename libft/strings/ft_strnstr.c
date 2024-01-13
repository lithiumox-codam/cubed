/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 17:51:55 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Locates the first occurrence of the null-terminated string needle
 * in the string haystack, where not more than len characters are searched.
 * Characters that appear after a `\0' character are not searched.
 *
 * @param haystack String to search in
 * @param needle String to search for
 * @param len Maximum number of characters to search
 * @return char* Pointer to the first occurrence of needle in haystack,
 * NULL if needle is not found
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	nlen = ft_strlen(needle);
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if ((haystack[i] == *needle) && ft_strncmp(haystack + i, needle,
				nlen) == 0)
			if ((i + nlen) <= len)
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
