/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:58:27 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/21 02:37:33 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libft/libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	ps_parser(int ac, char *av, ps_lst **lsthead)
{
	(void)ac;
	int	i = 1;
	long a;
	char **arr = NULL;
	ps_lst	*temp;

	arr = ft_split(av, ' ');
	i = 0;
	while (arr[i])
	{
		a = ft_atoi(arr[i]);
		if (!(INT_MIN <= a && a <= INT_MAX) || a == 0)
			return ;
		temp = ps_lstnew(a);
		ps_lstadd_back(lsthead, temp);
		i++;
	}
}

int main(int ac, char **av)
{
	int	i;

	i = 1;
	ps_lst *lsthead;
	lsthead = NULL;
	while (ac > i)
	{
		ps_parser(ac, av[i], &lsthead);
		i++;
	}
	if (lsthead == NULL)
		printf("nul\n");
	
	printf("%d\n", (int)lsthead->content);
	lsthead = lsthead->next;
	printf("%d\n", (int)lsthead->content);
	lsthead = lsthead->next;
	printf("%d\n", (int)lsthead->content);
	lsthead = lsthead->next;
	printf("%d\n", (int)lsthead->content);
	lsthead = lsthead->next;


	
}