/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:36:28 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 16:22:09 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

/**
 * @brief Applies a function to every element of the list.
 *
 * @param lst The list to iterate over.
 * @param f The function to apply to every element.
 */
void	list_iter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
