/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 15:09:04 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Duplicates a string
 *
 * @param s1 The string to duplicate
 * @return char* A pointer to the new string, NULL if malloc fails
 */
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	else
		ft_strlcpy(ptr, s1, len);
	return (ptr);
}
