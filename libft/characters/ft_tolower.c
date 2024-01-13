/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:07:43 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:56:34 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a character to lowercase
 *
 * @param c The character to convert
 * @return int The converted character
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
