/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:35:10 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 17:06:22 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <lists.h>

/**
 * @brief A function that allocates and returns a new element.
 *
 * @param content The content to put in the new element.
 * @return t_list* The new element.
 */
t_list	*list_new(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
