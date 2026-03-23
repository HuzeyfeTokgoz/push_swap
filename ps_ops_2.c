/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:58:08 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/23 23:16:10 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_rb(t_ps_lst **b, t_config *conf)
{
	t_ps_lst	*temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	temp->next = NULL;
	ps_lstadd_back(b, temp);
	if (conf)
		conf->rb++;
	if (conf && conf->is_checker == 0)
		write(1, "rb\n", 3);
}

void	ps_rra(t_ps_lst **a, t_config *conf)
{
	t_ps_lst	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a);
	while (temp->next->next != NULL)
		temp = temp->next;
	ps_lstadd_front(a, temp->next);
	temp->next = NULL;
	if (conf)
		conf->rra++;
	if (conf && conf->is_checker == 0)
		write(1, "rra\n", 4);
}

void	ps_rrb(t_ps_lst **b, t_config *conf)
{
	t_ps_lst	*temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = (*b);
	while (temp->next->next != NULL)
		temp = temp->next;
	ps_lstadd_front(b, temp->next);
	temp->next = NULL;
	if (conf)
		conf->rrb++;
	if (conf && conf->is_checker == 0)
		write(1, "rrb\n", 4);
}
