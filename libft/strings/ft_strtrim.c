/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 17:51:31 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

/**
 * @brief Get the start object
 *
 * @param s1 String to check
 * @param set String to check against
 * @return int Index of the first character that is not in set
 */
static int	get_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (checkchar(s1[i], (char *)set))
		i++;
	return (i);
}

/**
 * @brief Get the end object
 *
 * @param s1 String to check
 * @param set String to check against
 * @return int Index of the last character that is not in set
 */
static int	get_end(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1);
	while (len > 0 && checkchar(s1[len - 1], (char *)set))
		len--;
	return (len);
}

/**

	* @brief Allocates (with malloc(3)) and returns a copy of ’s1’
	with the characters specified in ’set’ removed from the beginning
	and the end of the string.
 *
 * @param s1 Address of the string to be trimmed
 * @param set The reference set of characters to trim
 * @return char* The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0' || set[0] == '\0')
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	return (ft_substr(s1, start, end - start));
}
