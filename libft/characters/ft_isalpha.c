/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:09:57 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:25:04 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is alphabetic
 *
 * @param c The character to check
 * @return int 1 if the character is alphabetic, 0 if not
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
