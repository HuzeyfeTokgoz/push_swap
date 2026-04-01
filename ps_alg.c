/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:05:15 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/04/01 21:58:09 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_ps_lst **lst_a, t_ps_lst **lst_b,
			t_config *conf, int size)
{
	int	i;
	int	j;

	i = 0;
	while ((size - 1) >> i)
	{
		j = 0;
		while (j < size)
		{
			if (((*lst_a)->index >> i) & 1)
				ps_ra(lst_a, conf);
			else
				ps_pb(lst_a, lst_b, conf);
			j++;
		}
		while (*lst_b)
			ps_pa(lst_a, lst_b, conf);
		i++;
	}
}

void	sort_simple(t_ps_lst **lst_a, t_ps_lst **lst_b,
			t_config *conf, int size)
{
	int	min_index;
	int	moves;

	while (size > 3)
	{
		min_index = get_minmax_index(*lst_a, 0);
		if (min_index <= (size / 2))
		{
			while (min_index--)
				ps_ra(lst_a, conf);
		}
		else
		{
			moves = size - min_index;
			while (moves--)
				ps_rra(lst_a, conf);
		}
		ps_pb(lst_a, lst_b, conf);
		size--;
	}
	sort_three(lst_a, conf);
	while (*lst_b)
		ps_pa(lst_a, lst_b, conf);
}

void	sort_three(t_ps_lst **lst_a, t_config *conf)
{
	if ((*lst_a)->index > (*lst_a)->next->index
		&& (*lst_a)->index > (*lst_a)->next->next->index)
		ps_ra(lst_a, conf);
	else if ((*lst_a)->next->index > (*lst_a)->index
		&& (*lst_a)->next->index > (*lst_a)->next->next->index)
		ps_rra(lst_a, conf);
	if ((*lst_a)->index > (*lst_a)->next->index)
		ps_sa(lst_a, conf);
}

void	sort_size(t_ps_lst **a, t_ps_lst **b, t_config *conf, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(a, conf, size);
	else if (size == 3)
		sort_three(a, conf);
	else if (size == 5)
		sort_five(a, b, conf);
}
