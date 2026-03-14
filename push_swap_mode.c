/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:33:49 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/14 00:46:26 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_pa(ps_lst **a, ps_lst **b, config *conf)
{
	ps_lst	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	(*b) = (*b)->next;
	temp->next = NULL;
	ps_lstadd_front(a, temp);
	if (conf)
        conf->pa++;
	write(1, "pa\n", 3);
}

void	ps_pb(ps_lst **a, ps_lst **b, config *conf)
{
	ps_lst	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	temp->next = NULL;
	ps_lstadd_front(b, temp);
	if (conf)
        conf->pb++;
	write(1, "pb\n", 3);
}

void	ps_sa(ps_lst **a, config *conf)
{
	int	temp;
	int	temp_index;

	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	temp_index = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp_index;
	if (conf)
        conf->sa++;
	write(1, "sa\n", 3);
}

void	ps_sb(ps_lst **b, config *conf)
{
	int	temp;
	int	temp_index;

	temp = 0;
	if (!*b || !(*b)->next)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
	temp_index = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp_index;
	if (conf)
        conf->sb++;
	write(1, "sb\n", 3);
}

void	ps_ra(ps_lst **a, config *conf)
{
	ps_lst	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = NULL;
	ps_lstadd_back(a, temp);
	if (conf)
        conf->ra++;
	write(1, "ra\n", 3);
}
