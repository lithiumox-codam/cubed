/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:12:49 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:27:36 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a digit
 *
 * @param c The character to check
 * @return int 1 if the character is a digit, 0 if not
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
