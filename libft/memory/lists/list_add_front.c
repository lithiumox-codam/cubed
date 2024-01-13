/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_add_front.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 16:09:35 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 16:22:51 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

void	list_add_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
