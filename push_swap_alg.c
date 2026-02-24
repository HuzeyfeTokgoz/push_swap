/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:24:20 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/24 04:07:14 by hutokgoz         ###   ########.fr       */
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
	(void)lst_a;
	(void)lst_b;
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