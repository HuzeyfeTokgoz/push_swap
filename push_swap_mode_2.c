/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mode_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:58:08 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/24 01:21:04 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_rb(ps_lst **b, int print_flg)
{
	ps_lst	*temp;

	if (!b ||!*b || !(*b)->next)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	temp->next = NULL;
	ps_lstadd_back(b, temp);
	if (print_flg)
		write (1, "rb\n", 3);
}

void	ps_rr(ps_lst **a, ps_lst **b)
{
	ps_ra(a, 0);
	ps_rb(b, 0);
	write (1, "rr\n", 3);
}

void	ps_rra(ps_lst **a, int print_flg)
{
	ps_lst	*temp;

	if (!a ||!*a || !(*a)->next)
		return ;
	temp = (*a);
	while (temp->next->next != NULL)
		temp = temp->next;
	ps_lstadd_front(a, temp->next);
	temp->next = NULL;
	if (print_flg)
		write (1, "rra\n", 4);
}

void	ps_rrb(ps_lst **b, int print_flg)
{
	ps_lst	*temp;

	if (!b ||!*b || !(*b)->next)
		return ;
	temp = (*b);
	while (temp->next->next != NULL)
		temp = temp->next;
	ps_lstadd_front(b, temp->next);
	temp->next = NULL;
	if (print_flg)
		write (1, "rrb\n", 4);
}

void	ps_rrr(ps_lst **a, ps_lst **b)
{
	ps_rra(a, 0);
	ps_rrb(b, 0);
	write (1, "rrr\n", 4);
}
