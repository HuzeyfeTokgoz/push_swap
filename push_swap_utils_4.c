/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:41:38 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/07 02:41:34 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	quick_pivot_value(ps_lst *lst_a, int size, int flag)
{
	int min;
	int max;
	int pivot;
	int i;

	i = 0;
	min = lst_a->index;
	max = lst_a->index;
	while (size > i)
	{
		if (min > lst_a->index)
			min = lst_a->index;
		if (max < lst_a->index)
			max = lst_a->index;
		lst_a = lst_a->next;
		i++;
	}
	if (flag == 1)
		pivot = min + ((max - min) / 4);
	else
		pivot = min + ((max - min) / 2);
	return (pivot);
}

void	quick_pb(ps_lst **lst_a, ps_lst **lst_b, int size)
{
	int median;
	int quarter;
	int ra_counter;
	int rb_counter;
	int pb_counter;
	int i;

	i = 0;
	rb_counter = 0;
	ra_counter = 0;
	pb_counter = 0;
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*lst_a)->index > (*lst_a)->next->index) 
			ps_sa(lst_a, 1);
		return ;
	}	
	median = quick_pivot_value(*lst_a, size, 0);
	quarter = quick_pivot_value(*lst_a, size, 1);
	// if (ps_disorder(*lst_a) == 0.0)
	// 	return ;
	while (size > i)
	{
		if (median >= (*lst_a)->index)
		{
			ps_pp(lst_a, lst_b, 0);
			pb_counter++;
			if (quarter >= (*lst_b)->index)
			{
				ps_rb(lst_b, 1);
				rb_counter++;
			}
		}
		else
		{
			ps_ra(lst_a, 1);
			ra_counter++;
		}
		i++;
	}
	while (ra_counter--)
		ps_rra(lst_a, 1);
	quick_pb(lst_a, lst_b, (size - pb_counter));
	quick_pa(lst_a, lst_b, (pb_counter - rb_counter));
	while (rb_counter--)
		ps_rrb(lst_b, 1);
	quick_pa(lst_a, lst_b, rb_counter);
}

void	quick_pa(ps_lst **lst_a, ps_lst **lst_b, int size)
{
	int i;
	int median;
	int rb_counter;
	int pa_counter;

	if (size <= 0)
   		return ;
	if (size == 1)
	{
		ps_pp(lst_a, lst_b, 1);
		return ;
	}
	if (size == 2)
	{
		ps_pp(lst_a, lst_b, 1);
		ps_pp(lst_a, lst_b, 1);
		if ((*lst_a)->index > (*lst_a)->next->index)
			ps_sa(lst_a, 1);
		return ;
	}
	i = 0;
	pa_counter = 0;
	rb_counter = 0;
	median = quick_pivot_value(*lst_b, size, 0);
	while (size > i)
	{
		if (median <= (*lst_b)->index)
		{
			ps_pp(lst_a, lst_b, 1);
			pa_counter++;
		}
		else
		{
			ps_rb(lst_b, 1);
			rb_counter++;
		}
		i++;
	}
	while (rb_counter--)
		ps_rrb(lst_b, 1);
	quick_pb(lst_a, lst_b, pa_counter);
	quick_pa(lst_a, lst_b, (size - pa_counter));
}
