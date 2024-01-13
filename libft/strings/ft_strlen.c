/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:06:57 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:47:55 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Counts the length of a string
 *
 * @param s Address of the string
 * @return int The length of the string
 */
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
