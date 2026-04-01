/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 20:18:15 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/04/01 21:57:58 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_rr(t_ps_lst **a, t_ps_lst **b, t_config *conf)
{
	conf->not_write = 1;
	ps_ra(a, conf);
	ps_rb(b, conf);
	if (conf)
		conf->rb++;
	if (conf && conf->is_checker == 0)
		write(1, "rr\n", 3);
	conf->not_write = 0;
}

void	ps_rrr(t_ps_lst **a, t_ps_lst **b, t_config *conf)
{
	conf->not_write = 1;
	ps_rra(a, conf);
	ps_rrb(b, conf);
	if (conf)
		conf->rb++;
	if (conf && conf->is_checker == 0)
		write(1, "rrr\n", 4);
	conf->not_write = 0;
}

void	ps_ss(t_ps_lst **a, t_ps_lst **b, t_config *conf)
{
	conf->not_write = 1;
	ps_sa(a, conf);
	ps_sb(b, conf);
	if (conf)
		conf->rb++;
	if (conf && conf->is_checker == 0)
		write(1, "ss\n", 3);
	conf->not_write = 0;
}

void	sort_two(t_ps_lst **lst_a, t_config *conf, int size)
{
	if (size == 2)
	{
		if ((*lst_a)->content > (*lst_a)->next->content)
			ps_sa(lst_a, conf);
	}
}

void	sort_five(t_ps_lst **a, t_ps_lst **b, t_config *conf)
{
	int	size;
	int	index;

	size = 5;
	while (size > 3)
	{
		index = get_minmax_index(*a, 0);
		if (index <= size / 2)
		{
			while (index--)
				ps_ra(a, conf);
		}
		else
		{
			index = size - index;
			while (index--)
				ps_rra(a, conf);
		}
		ps_pb(a, b, conf);
		size--;
	}
	sort_three(a, conf);
	ps_pa(a, b, conf);
	ps_pa(a, b, conf);
}
