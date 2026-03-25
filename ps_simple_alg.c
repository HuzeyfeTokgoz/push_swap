/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:24:20 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/25 23:54:08 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_ps_lst **lst_a, t_ps_lst **lst_b,
			t_config *conf, int size)
{
	int	min_index;
	int	moves;

	while (size > 3)
	{
		min_index = get_minmax_index(*lst_a, 0);
		if (min_index <= (size / 2))
		{
			while (min_index--)
				ps_ra(lst_a, conf);
		}
		else
		{
			moves = size - min_index;
			while (moves--)
				ps_rra(lst_a, conf);
		}
		ps_pb(lst_a, lst_b, conf);
		size--;
	}
	sort_three(lst_a, conf);
	while (*lst_b)
		ps_pa(lst_a, lst_b, conf);
}

void	sort_three(t_ps_lst **lst_a, t_config *conf)
{
	if ((*lst_a)->index > (*lst_a)->next->index
		&& (*lst_a)->index > (*lst_a)->next->next->index)
		ps_ra(lst_a, conf);
	else if ((*lst_a)->next->index > (*lst_a)->index
		&& (*lst_a)->next->index > (*lst_a)->next->next->index)
		ps_rra(lst_a, conf);
	if ((*lst_a)->index > (*lst_a)->next->index)
		ps_sa(lst_a, conf);
}

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
