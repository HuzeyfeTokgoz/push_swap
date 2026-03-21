/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mode_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:58:08 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/21 15:54:00 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_rb(ps_lst **b, config *conf)
{
	ps_lst	*temp;

	if (!b ||!*b || !(*b)->next)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	temp->next = NULL;
	ps_lstadd_back(b, temp);
	if (conf)
        conf->rb++;
	if (conf && conf->is_checker == 0)
		write (1, "rb\n", 3);
}

void	ps_rra(ps_lst **a, config *conf)
{
	ps_lst	*temp;

	if (!a ||!*a || !(*a)->next)
		return ;
	temp = (*a);
	while (temp->next->next != NULL)
		temp = temp->next;
	ps_lstadd_front(a, temp->next);
	temp->next = NULL;
	if (conf)
        conf->rra++;
	if (conf && conf->is_checker == 0)
		write (1, "rra\n", 4);}

void	ps_rrb(ps_lst **b, config *conf)
{
	ps_lst	*temp;

	if (!b ||!*b || !(*b)->next)
		return ;
	temp = (*b);
	while (temp->next->next != NULL)
		temp = temp->next;
	ps_lstadd_front(b, temp->next);
	temp->next = NULL;
	if (conf)
        conf->rrb++;
	if (conf && conf->is_checker == 0)
		write (1, "rrb\n", 4);}
