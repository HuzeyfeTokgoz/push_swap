/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:19:23 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/28 02:40:19 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(ps_lst **lst_a)
{
    if ((*lst_a)->content > (*lst_a)->next->content &&
		(*lst_a)->content > (*lst_a)->next->next->content)
        ps_ra(lst_a, 1);
    else if ((*lst_a)->next->content > (*lst_a)->content &&
			(*lst_a)->next->content > (*lst_a)->next->next->content)
        ps_rra(lst_a, 1);
    if ((*lst_a)->content > (*lst_a)->next->content)
        ps_sa(lst_a, 1);
}

void	push_target(ps_lst **lst_a, ps_lst **lst_b, int *target, int *flag)
{
	ps_pp(lst_a, lst_b, 1);
	if (*flag == 1)
	{
		ps_sa(lst_a, 1);
		*flag = 0;
		*target -= 2;
	}
	else
		(*target)--;
}

static void	to_index(int size, ps_lst **temp, ps_lst *lst_a, int *arr)
{
	int i;

	(*temp) = lst_a;
	while (*temp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == (*temp)->content)
			{
				(*temp)->content = i;
				break ;
			}
			i++;
		}
		(*temp) = (*temp)->next;
	}
}

static int	*buble_sort(int size, int *arr)
{
	int	i;
	int tmp;
	int j;

	i = 1;
	while (i < size)
    {
		j = 0;
		while (j < size - i)
        {
			if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
			j++;
        }
		i++;
    }
	return (arr);
}

ps_lst	*lst_to_index(ps_lst *lst_a)
{	
	int		size;
	int		i;
	int		*arr;
	ps_lst	*temp;

	i = 0;
	size = ps_lstsize(lst_a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	temp = lst_a;
	while (temp)
	{
		arr[i++] = temp->content;
		temp = temp->next;
	}
	arr = buble_sort(size, arr);
	to_index(size, &temp, lst_a, arr);
	free(arr);
	return (lst_a);
}
