/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_reverse.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 17:04:56 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 17:05:45 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

/**
 * @brief A function that reverses the order of the elements in a list.
 *
 * @param lst The list to reverse.
 */
void	list_reverse(t_list **lst)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}
