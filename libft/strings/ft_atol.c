/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 15:55:24 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Converts a string to a long integer
 *
 * @param str The string to convert
 * @return long The converted string
 */
long	ft_atol(const char *str)
{
	long	isneg;
	int		i;
	long	reslong;

	isneg = 1;
	i = 0;
	reslong = 0;
	while (checkchar(str[i], " \t\n\v\f\r"))
		i++;
	if (checkchar(str[i], "-+"))
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	while (checkchar(str[i], "1234567890"))
	{
		reslong = (reslong * 10) + (str[i] - '0');
		i++;
	}
	return (reslong * isneg);
}
