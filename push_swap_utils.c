/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:46:06 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/23 02:00:52 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ps_lstadd_front(ps_lst **lst, ps_lst *new)
{	
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
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

void	ps_lstclear(ps_lst **lst)
{
	ps_lst	*tmp;
	ps_lst	*next;

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

int	lst_dup(ps_lst *lst, int a)
{
	while (lst != NULL)
	{
		if (lst->content == a)
			return (-1);
		lst = lst->next;
	}
	return (1);
}

int is_numeric(char *str)
{
	int i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (-1);
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

int	ps_lstsize(ps_lst *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}