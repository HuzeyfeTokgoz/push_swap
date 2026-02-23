/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:58:27 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/23 02:47:11 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libft/libft.h"
#include <limits.h>
#include <stdio.h>

void	ps_parser(char *av, ps_lst **list)
{
	int	i;
	long a;
	char **arr = NULL;
	ps_lst	*temp;

	arr = ft_split(av, ' ');
	i = 0;
	while (arr[i])
	{
		if (is_numeric(arr[i]) == -1)
			error(list, arr);
		a = ft_atoi(arr[i]);
		if (!(INT_MIN <= a && a <= INT_MAX) || (lst_dup(*list, a) == -1))
			error(list, arr);
		temp = ps_lstnew(a);
		ps_lstadd_back(list, temp);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);	
}

void	ps_flag(int ac, char **av, ps_lst **lst_a, config *conf)
{
	int	i;

	i = 1;
	while (ac > i && av[i])
	{
		if (ft_strncmp(av[i], "--bench", 8) == 0)
			conf->benchmark = 1;
		else if (ft_strncmp(av[i], "--simple", 9) == 0)
			conf->algoritma = SIMPLE;
		else if (ft_strncmp(av[i], "--medium", 9) == 0)
			conf->algoritma = MEDIUM;
		else if (ft_strncmp(av[i], "--complex", 10) == 0)
			conf->algoritma = COMPLEX;
		else if (ft_strncmp(av[i], "--adaptive", 11) == 0)
			conf->algoritma = ADAPTIVE;
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			continue ;
		}
		ps_parser(av[i], lst_a);
		i++;
	}
}

double	ps_disorder(ps_lst *lst_a)
{
	int	lst_disorder;
	int total_pairs;
	ps_lst	*temp;

	total_pairs = 0;
	lst_disorder = 0;
	temp = NULL;
	while (lst_a && lst_a->next)
	{
		temp = lst_a->next;
		while (temp)
		{
			total_pairs++;
			if (lst_a->content > temp->content)
				lst_disorder++;
			temp = temp->next;
		}
		lst_a = lst_a->next;
	}
	if (lst_disorder == 0 && total_pairs == 0)
		return (0.0);
	return ((double)lst_disorder / (double)total_pairs);
}

int main(int ac, char **av)
{
	ps_lst *lst_a;
	config conf;
	double lst_disorder;

	lst_a = NULL;
	conf.benchmark = 0;
	conf.algoritma = ADAPTIVE;

	ps_flag(ac, av, &lst_a, &conf);
	lst_disorder = ps_disorder(lst_a);
//	if (!lst_a)
//		error(lst_a);
		


	printf("Algoritma: %d, Bench: %d\n", conf.algoritma, conf.benchmark);
	printf("%d\n", lst_a->next->content);
	printf("%f", lst_disorder);
}
