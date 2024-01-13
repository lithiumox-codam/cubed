/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 17:51:47 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Allocates and returns a new string,
	which is the result of the concatenation
 * @param s1 String to concatenate
 * @param s2 String to concatenate
 * @return char* Pointer to the new string, NULL if allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		memspace;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(s2));
	if (ft_strlen(s2) == 0)
		return (ft_strdup(s1));
	memspace = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(memspace * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[memspace - 1] = '\0';
	return (ptr);
}
