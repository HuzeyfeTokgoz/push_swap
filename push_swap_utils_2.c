/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:56:11 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/24 04:27:56 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_dup(ps_lst *lst, int a)
{
	while (lst != NULL)
	{
		if (lst->content == a)
			return (-1);
		lst = lst->next;
	}
	return (1);
}

int	is_numeric(char *str)
{
	int i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (-1);
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

int	ps_lstsize(ps_lst *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

long	ps_atol(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}

ps_lst	*get_minmax_index(ps_lst **lst, int	min_max)
{
	ps_lst *value;

	value = 0;
	if (min_max == 1)
	{
		while ((*lst)->next)
		{
			if ((*lst)->content > (*lst)->next->content)
				value = *lst;
			lst = (*lst)->next;
		}		
	}
	if (min_max == 0)
	{
		while ((*lst)->next)
		{
			if ((*lst)->content < (*lst)->next->content)
				value = *lst;
			lst = (*lst)->next;
		}
	}
	return (value);
}
