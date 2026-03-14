/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:41:38 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/14 03:13:53 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_a(ps_lst **lst_a, ps_lst **lst_b, config *conf)
{
    int a;
    int b;
    int c;

    a = (*lst_a)->index;
    b = (*lst_a)->next->index;
    c = (*lst_a)->next->next->index;
    if (a < b && b < c)
        return ;
    else if (a < c && c < b)
    {
        ps_pb(lst_a, lst_b, conf);
        ps_sa(lst_a, conf);
        ps_pa(lst_a, lst_b, conf);
    }
    else if (b < a && a < c)
        ps_sa(lst_a, conf);
    else if (c < a && a < b)
    {
        ps_pb(lst_a, lst_b, conf);
        ps_sa(lst_a, conf);
        ps_pa(lst_a, lst_b, conf);
        ps_sa(lst_a, conf);
    }
    else if (b < c && c < a)
    {
        ps_sa(lst_a, conf);
        ps_pb(lst_a, lst_b, conf);
        ps_sa(lst_a, conf);
        ps_pa(lst_a, lst_b, conf);
    }
    else if (c < b && b < a)
    {
        ps_sa(lst_a, conf);
        ps_pb(lst_a, lst_b, conf);
        ps_sa(lst_a, conf);
        ps_pa(lst_a, lst_b, conf);
        ps_sa(lst_a, conf);
    }
}

int is_chunk_sorted_a(ps_lst *lst, int size)
{
    while (--size && lst && lst->next)
    {
        if (lst->index > lst->next->index)
            return (0);
        lst = lst->next;
    }
    return (1);
}

int is_chunk_sorted_b(ps_lst *lst, int size)
{
    while (--size && lst && lst->next)
    {
        if (lst->index < lst->next->index)
            return (0);
        lst = lst->next;
    }
    return (1);
}

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

void	quick_pb(ps_lst **lst_a, ps_lst **lst_b, int size, config *conf)
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
			ps_sa(lst_a, conf);
		return ;
	}
	if (size == 3)
    {
        sort_three_a(lst_a, lst_b, conf);
        return ;
    }
	if (is_chunk_sorted_a(*lst_a, size))
        return ;
	median = quick_pivot_value(*lst_a, size, 0);
	quarter = quick_pivot_value(*lst_a, size, 1);
	while (size > i)
	{
		if (median >= (*lst_a)->index)
		{
			ps_pb(lst_a, lst_b, conf);
			pb_counter++;
			if (quarter >= (*lst_b)->index)
			{
				ps_rb(lst_b, conf);
				rb_counter++;
			}
		}
		else
		{
			ps_ra(lst_a, conf);
			ra_counter++;
		}
		i++;
	}
	if (ra_counter != ps_lstsize(*lst_a))
	{
		while (ra_counter--)
			ps_rra(lst_a, conf);
	}
	quick_pb(lst_a, lst_b, (size - pb_counter), conf);
	quick_pa(lst_a, lst_b, (pb_counter - rb_counter), conf);
	i = rb_counter;
	while (i--)
		ps_rrb(lst_b, conf);
	quick_pa(lst_a, lst_b, rb_counter, conf);
}

void	quick_pa(ps_lst **lst_a, ps_lst **lst_b, int size, config *conf)
{
	int i;
	int median;
	int rb_counter;
	int pa_counter;

	if (size <= 0)
   		return ;
	if (size == 1)
	{
		ps_pa(lst_a, lst_b, conf);
		return ;
	}
	if (size == 2)
	{
		ps_pa(lst_a, lst_b, conf);
		ps_pa(lst_a, lst_b, conf);
		if ((*lst_a)->index > (*lst_a)->next->index)
			ps_sa(lst_a, conf);
		return ;
	}
	if (size == 3)
    {
        ps_pa(lst_a, lst_b, conf);
        ps_pa(lst_a, lst_b, conf);
        ps_pa(lst_a, lst_b, conf);
        sort_three_a(lst_a, lst_b, conf);
        return ;
    }
	if (is_chunk_sorted_b(*lst_b, size))
    {
        while (size--)
            ps_pa(lst_a, lst_b, conf);
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
			ps_pa(lst_a, lst_b, conf);
			pa_counter++;
		}
		else
		{
			ps_rb(lst_b, conf);
			rb_counter++;
		}
		i++;
	}
	if (rb_counter != ps_lstsize(*lst_b))
	{	
		i = rb_counter;
		while (i--)
			ps_rrb(lst_b, conf);
	}
	quick_pb(lst_a, lst_b, pa_counter, conf);
	quick_pa(lst_a, lst_b, (size - pa_counter), conf);
}
