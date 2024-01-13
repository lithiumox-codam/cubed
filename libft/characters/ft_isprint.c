/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:07:04 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:27:42 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is printable
 *
 * @param c The character to check
 * @return int 1 if the character is printable, 0 if not
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
