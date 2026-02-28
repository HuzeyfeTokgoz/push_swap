/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:41:38 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/28 02:49:59 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decimal_to_binary(ps_lst *lst)
{
	if ((lst->content % 2) == 0)
		return (0);
	return (1);
}

int max_bits(ps_lst *lst)
{
	int max_bits;

	max_bits = 0;
	if (lst->content / 2)

}