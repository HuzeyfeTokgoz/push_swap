/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:46:06 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/21 02:27:11 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ps_lstadd_back(ps_lst **lst, ps_lst *new)
{
	ps_lst	*last;

	if (!lst && !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
}
ps_lst	*ps_lstnew(int content)
{
	ps_lst	*newnode;

	newnode = (ps_lst *)malloc(sizeof(ps_lst));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
ps_lst	*ps_lstlast(ps_lst *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
