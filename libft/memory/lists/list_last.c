/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_last.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:36:40 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 16:20:48 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

/**
 * @brief Gets the last element of the list.
 *
 * @param lst The list to get the last element from.
 * @return t_list* The last element of the list.
 */
t_list	*list_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
