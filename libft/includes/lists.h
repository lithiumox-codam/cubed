/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:06:43 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/15 17:04:37 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*list_new(void *content);
void				list_add_front(t_list **lst, t_list *new);
void				list_add_back(t_list **lst, t_list *new);
int					list_size(t_list *lst);
t_list				*list_last(t_list *lst);
void				list_free(t_list **lst, void (*free_data)(void *));
void				list_iter(t_list *lst, void (*f)(void *));
t_list				*list_map(t_list *lst, void *(*f)(void *),
						void (*free_data)(void *));

#endif
