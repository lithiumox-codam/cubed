/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_add_back.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 16:09:17 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 16:19:19 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

/**
 * @brief A function that adds the element ’new’ at the end of the list.
 *
 * @param lst
 * @param new
 */
void	list_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = list_last(*lst);
	last->next = new;
}
