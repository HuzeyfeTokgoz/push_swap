/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:33:49 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/24 01:21:29 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_pp(ps_lst **a, ps_lst **b, int papb)
{
	ps_lst	*temp;

	if (papb == 1)
	{
		if (!b || !*b)
			return ;
		temp = *b;
		(*b) = (*b)->next;
		temp->next = NULL;
		ps_lstadd_front(a, temp);
		write (1, "pa\n", 3);
	}
	else if (papb == 0)
	{
		if (!a || !*a)
			return ;
		temp = *a;
		(*a) = (*a)->next;
		temp->next = NULL;
		ps_lstadd_front(b, temp);
		write (1, "pb\n", 3);
	}
}

void	ps_sa(ps_lst **a, int print_flg)
{
	int	temp;

	temp = 0;
	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	if (print_flg)
		write (1, "sa\n", 3);
}

void	ps_sb(ps_lst **b, int print_flg)
{
	int	temp;

	temp = 0;
	if (!*b || !(*b)->next)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
	if (print_flg)
		write (1, "sb\n", 3);
}

void	ps_ss(ps_lst **a, ps_lst **b)
{
	ps_sa(a, 0);
	ps_sb(b, 0);
	write (1, "ss\n", 3);
}

void	ps_ra(ps_lst **a, int print_flg)
{
	ps_lst	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = NULL;
	ps_lstadd_back(a, temp);
	if (print_flg)
		write (1, "ra\n", 3);
}
