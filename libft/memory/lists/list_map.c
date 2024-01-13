/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 16:04:43 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 17:08:05 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

/**
 * @brief A function that iterates the list ’lst’ and applies the function then
 * returns a new list resulting of the successive applications of the function.
 *
 * @param lst The list to iterate.
 * @param f The function to apply to every element.
 * @param free_data The function to free the data of the list.
 * If any of the mallocs fail, the function will free the new list and return
 * @return t_list* The new list.
 */
t_list	*list_map(t_list *lst, void *(*f)(void *), void (*free_data)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	new = list_new(f(lst->content));
	if (!new)
		return (NULL);
	temp = new;
	lst = lst->next;
	while (lst)
	{
		temp->next = list_new(f(lst->content));
		if (!temp->next)
		{
			list_free(&new, free_data);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (new);
}
