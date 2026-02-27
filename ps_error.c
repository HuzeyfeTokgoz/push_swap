/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:15:40 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/25 23:12:04 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_error(ps_lst **lsthead, char **arr)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	if (lsthead)
		ps_lstclear(lsthead);
	exit(1);
}