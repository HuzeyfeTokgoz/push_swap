/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:41:38 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/05 08:02:35 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_bits(ps_lst *lst)
{
	int max_num;
	int	max_bit;

	max_bit = 0;
	max_num = ps_lstsize(lst) - 1;
	if (max_num < 0)
		return (0);
	while (max_num != 0)
	{
		max_num = max_num >> 1;
		max_bit++;
	}
	return (max_bit);
}
