/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/06 18:02:30 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Converts an integer to a string
 *
 * @param n The integer to convert
 * @return char* The string representation of the integer
 */
char	*ft_itoa(int n)
{
	int		intlen;
	char	*ptr;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	intlen = ft_intlen(n);
	if (n < 0)
		intlen++;
	ptr = ft_calloc(sizeof(char), intlen + 1);
	if (ptr == NULL)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n)
	{
		ptr[--intlen] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
