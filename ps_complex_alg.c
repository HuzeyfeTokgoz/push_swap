/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:05:15 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/28 16:11:58 by hutokgoz         ###   ########.fr       */
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
