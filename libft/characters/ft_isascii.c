/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:50:36 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:27:29 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is ascii
 *
 * @param c The character to check
 * @return int 1 if the character is ascii, 0 if not
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
