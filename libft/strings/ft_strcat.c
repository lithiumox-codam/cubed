/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 21:37:20 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Append a copy of the null-terminated string s2 to the end of another
 *
 * @param s1 String to append to.
 * @param s2 String to append from.
 * @return char* A pointer to the resulting string s1.
 */
char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(s1 + i + j) = *(s2 + j);
		j++;
	}
	*(s1 + i + j) = *(s2 + j);
	return (s1);
}
