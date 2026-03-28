/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_to_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:24:20 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/28 16:16:53 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	to_index(int size, t_ps_lst *lst_a, int *arr)
{
	int			i;
	t_ps_lst	*temp;

	temp = lst_a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == temp->content)
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

static int	*bubble_sort(int size, int *arr)
{
	int	i;
	int	tmp;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

t_ps_lst	*lst_to_index(t_ps_lst *lst_a, int size)
{
	int			i;
	int			*arr;
	t_ps_lst	*temp;

	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	temp = lst_a;
	while (temp)
	{
		arr[i++] = temp->content;
		temp = temp->next;
	}
	arr = bubble_sort(size, arr);
	to_index(size, lst_a, arr);
	free(arr);
	return (lst_a);
}
