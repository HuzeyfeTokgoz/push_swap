/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medium_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:19:23 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/04/01 21:32:12 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_minmax_index(t_ps_lst *lst, int min_max)
{
	t_ps_lst	*temp;
	int			lst_index;
	int			best_index;

	best_index = 0;
	lst_index = 0;
	temp = lst;
	while (lst && lst->next)
	{
		lst_index++;
		if (temp->index < lst->next->index && min_max == 0)
			lst = lst->next;
		else if (temp->index > lst->next->index && min_max == 1)
			lst = lst->next;
		else
		{
			best_index = lst_index;
			temp = lst->next;
			lst = lst->next;
		}
	}
	return (best_index);
}

static void	push_target(t_ps_lst **lst_a, int *target, int *flag,
	t_config *conf)
{
	if (*flag == 1)
	{
		ps_sa(lst_a, conf);
		*flag = 0;
		*target -= 2;
	}
	else
		(*target)--;
}

static void	sort_push_a(t_ps_lst **lst_a, t_ps_lst **lst_b, t_config *conf)
{
	int	target;
	int	flag;

	flag = 0;
	target = ps_lstsize(*lst_b) - 1;
	while (*lst_b)
	{
		if ((*lst_b)->index == target)
		{
			ps_pa(lst_a, lst_b, conf);
			push_target(lst_a, &target, &flag, conf);
		}
		else if ((*lst_b)->index == target - 1)
		{
			ps_pa(lst_a, lst_b, conf);
			flag = 1;
		}
		else
		{
			if (get_minmax_index(*lst_b, 1) <= (ps_lstsize(*lst_b) / 2))
				ps_rb(lst_b, conf);
			else
				ps_rrb(lst_b, conf);
		}
	}
}

static void	sort_push_b(t_ps_lst **lst_a, t_ps_lst **lst_b, int chunk_size,
		t_config *conf)
{
	int	size;
	int	limit;

	size = 0;
	limit = chunk_size;
	while (*lst_a)
	{
		if ((*lst_a)->index <= limit)
		{
			ps_pb(lst_a, lst_b, conf);
			size++;
			if ((*lst_b)->index < limit - (chunk_size / 2))
				ps_rb(lst_b, conf);
			if (limit == size)
				limit += chunk_size;
		}
		else
			ps_ra(lst_a, conf);
	}
}

void	sort_medium(t_ps_lst **lst_a, t_ps_lst **lst_b,
			t_config *conf, int size)
{
	int	chunk_size;

	chunk_size = 0;
	if (size <= 100)
		chunk_size = 25;
	else
		chunk_size = 60;
	if (chunk_size != 0)
	{
		sort_push_b(lst_a, lst_b, chunk_size, conf);
		sort_push_a(lst_a, lst_b, conf);
	}
}
