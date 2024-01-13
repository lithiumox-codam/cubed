/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_size.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 16:05:43 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 17:06:02 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

/**
 * @brief A function that counts the number of elements in a list.
 *
 * @param lst The list to count.
 * @return int The amount of elements in the list.
 */
int	list_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
