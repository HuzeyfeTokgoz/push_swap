/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:15:40 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/21 23:07:59 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(ps_lst **lsthead, char **arr)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	ps_lstclear(lsthead);
	exit(1);
}