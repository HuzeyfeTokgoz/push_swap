/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:46:06 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/23 23:14:18 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_ps_lst **lst, t_ps_lst *new)
{
	t_ps_lst	*last;

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

void	ps_lstadd_front(t_ps_lst **lst, t_ps_lst *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_ps_lst	*ps_lstnew(int content)
{
	t_ps_lst	*newnode;

	newnode = (t_ps_lst *)malloc(sizeof(t_ps_lst));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->index = 0;
	newnode->next = NULL;
	return (newnode);
}

t_ps_lst	*ps_lstlast(t_ps_lst *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ps_lstclear(t_ps_lst **lst)
{
	t_ps_lst	*tmp;
	t_ps_lst	*next;

	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
	}
	*lst = NULL;
}
