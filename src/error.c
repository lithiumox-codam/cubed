/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 21:13:18 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/20 15:29:32 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Prints an error message and returns false
 * @param message The message to print
 * @param extra An extra message to print like a path or a number
 * @return false
*/
bool	error(const char *message, const char *extra)
{
	static bool	printed = false;

	if (!printed)
	{
		ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
		ft_putstr_fd(message, 2);
		if (extra != NULL)
			ft_putstr_fd(extra, 2);
		ft_putstr_fd("\n", 2);
		printed = true;
	}
	return (false);
}
