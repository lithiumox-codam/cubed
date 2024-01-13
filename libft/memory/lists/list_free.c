/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_free.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:33:26 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 16:21:00 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

void	list_free(t_list **lst, void (*free_data)(void *))
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if (free_data)
			free_data((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
