/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:24:20 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/24 20:41:53 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(ps_lst **lst_a)
{
    int ilk;
    int iki;
    int uc;

    ilk = (*lst_a)->content;
    iki = (*lst_a)->next->content;
    uc = (*lst_a)->next->next->content;

    if (ilk > iki && ilk > uc)
        ps_ra(lst_a, 1);
    else if (iki > ilk && iki > uc)
        ps_rra(lst_a, 1);

    ilk = (*lst_a)->content;
    iki = (*lst_a)->next->content;

    if (ilk > iki)
        ps_sa(lst_a, 1);
}

void sort_simple(ps_lst **lst_a, ps_lst **lst_b) // simple min/max
{
	int size;
	int	min_index;
	int moves;
	
	moves = 0;
	size = ps_lstsize(*lst_a);
	while (size != 3)
	{
		min_index = get_minmax_index(*lst_a, 0);
		if (min_index < (size / 2))
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

void sort_medium(ps_lst **lst_a, ps_lst **lst_b) // chunk-based
{

	(void)lst_a;
	(void)lst_b;
}

void sort_complex(ps_lst **lst_a, ps_lst **lst_b) // quick-sort
{
	(void)lst_a;
	(void)lst_b;

}

void sort_benchmark(ps_lst **lst_a, ps_lst **lst_b)
{

	(void)lst_a;
	(void)lst_b;
}