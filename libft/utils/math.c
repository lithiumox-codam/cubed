/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 12:00:59 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Calculates the power of a number
 *
 * @param base The number to calculate the power of
 * @param power The power to calculate
 * @return int The result of the calculation
 */
int	ft_pow(int base, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

/**
 * @brief Calculates the length of an integer by counting the amount of digits
 *
 * @param n The integer to calculate the length of
 * @return int The length of the integer
 */
int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
