/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:05:15 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/26 00:12:58 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_ps_lst **lst_a, t_ps_lst **lst_b,
			t_config *conf, int size)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
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
