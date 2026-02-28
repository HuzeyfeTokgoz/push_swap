/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:24:20 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/28 01:13:14 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(ps_lst **lst_a, ps_lst **lst_b)
{
	int size;
	int	min_index;
	int moves;
	
	size = ps_lstsize(*lst_a);
	while (size > 3)
	{
		min_index = get_minmax_index(*lst_a, 0);
		if (min_index <= (size / 2))
		{
			while (min_index--)
				ps_ra(lst_a, 1);
		}
		else
		{
			moves = size - min_index;
			while(moves--)
				ps_rra(lst_a, 1);
		}	
		ps_pp(lst_a, lst_b, 0);
		size--;
	}
	sort_three(lst_a);
	while (*lst_b)
		ps_pp(lst_a, lst_b, 1);
}

void	sort_push_a(ps_lst **lst_a, ps_lst **lst_b)
{
	int target;
	int flag;

	flag = 0;
	target = ps_lstsize(*lst_b) - 1;
	while (*lst_b)
	{
		if ((*lst_b)->content == target)
			push_target(lst_a, lst_b, &target, &flag);
		else if ((*lst_b)->content == target - 1)
		{
			ps_pp(lst_a, lst_b, 1);
			flag = 1;
		}
		else
		{
			if (get_minmax_index(*lst_b, 1) <= (ps_lstsize(*lst_b) / 2))
				ps_rb(lst_b, 1);
			else
				ps_rrb(lst_b, 1);
		}
	}	
}

void	sort_push_b(ps_lst **lst_a, ps_lst **lst_b, int chunk_size)
{
	int size;
	int limit;
	
	size = 0;
	limit = chunk_size;
	while (*lst_a)
	{
		if ((*lst_a)->content <= limit)
		{
			ps_pp(lst_a, lst_b, 0);
			size++;
			if ((*lst_b)->content < limit - (chunk_size / 2))
				ps_rb(lst_b, 1);
			if (limit == size)
				limit += chunk_size;
		}
		else
			ps_ra(lst_a, 1);
	}
}	

void	sort_medium(ps_lst **lst_a, ps_lst **lst_b)
{
	int size;
	int chunk_size;

	*lst_a = lst_to_index(*lst_a);
	size = ps_lstsize(*lst_a);
	if (size <= 100)
		chunk_size = 25;
	else
		chunk_size = 60;
	sort_push_b(lst_a, lst_b, chunk_size);
	sort_push_a(lst_a, lst_b);
}

void	sort_complex(ps_lst **lst_a, ps_lst **lst_b)
{
	(void)lst_a;
	(void)lst_b;

}

void	sort_benchmark(ps_lst **lst_a, ps_lst **lst_b)
{
	(void)lst_a;
	(void)lst_b;
}