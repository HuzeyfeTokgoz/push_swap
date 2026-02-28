/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:58:27 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/27 23:51:09 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include "ft_libft/libft.h"

void	ps_parser(char *av, ps_lst **list)
{
	int		i;
	long	a;
	char	**arr;
	ps_lst	*temp;

	arr = ft_split(av, ' ');
	i = 0;
	while (arr[i])
	{
		if (is_numeric(arr[i]) == -1)
			ps_error(list, arr);
		a = ps_atol(arr[i]);
		if (!(INT_MIN <= a && a <= INT_MAX) || (lst_dup(*list, a) == -1))
			ps_error(list, arr);
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
	int		lst_disorder;
	int 	total_pairs;
	double	disorder_value;
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
	disorder_value = (double)lst_disorder / (double)total_pairs;
	return (disorder_value);
}

void	ps_router(double ps_disorder, ps_lst **lst_a, ps_lst **lst_b, config conf)
{
	int size;

	size = ps_lstsize(*lst_a);
	if (size == 3 && conf.algoritma == ADAPTIVE)
		sort_three(lst_a);
	else if (conf.algoritma == ADAPTIVE)
	{
		if (ps_disorder < 0.2)
			sort_simple(lst_a, lst_b);
		else if (ps_disorder < 0.5)
			sort_medium(lst_a, lst_b);
		else if (ps_disorder >= 0.5)
			sort_complex(lst_a, lst_b);
	}
	else if (conf.algoritma == SIMPLE)
		sort_simple(lst_a, lst_b);
	else if (conf.algoritma == MEDIUM)
		sort_medium(lst_a, lst_b);
	else if (conf.algoritma == COMPLEX)
		sort_complex(lst_a, lst_b);
	if (conf.benchmark == 1)
		sort_benchmark(lst_a, lst_b);
}

int main(int ac, char **av)
{
	ps_lst	*lst_a;
	ps_lst	*lst_b;
	config	conf;
	double	lst_disorder;
	int		size;

	lst_a = NULL;
	lst_b = NULL;
	conf.benchmark = 0;
	conf.algoritma = ADAPTIVE;
	ps_flag(ac, av, &lst_a, &conf);
	size = ps_lstsize(lst_a);
	if (!lst_a || ps_disorder(lst_a) == 0.0)
		return (0);
	if (conf.algoritma == ADAPTIVE && (size == 0 || size == 1))
		return (0);
	if (size == 2)
	{
		if ((*lst_a).content > (*lst_a).next->content)
			ps_sa(&lst_a, 1);
		return (0);
	}
	lst_disorder = ps_disorder(lst_a);
	ps_router(lst_disorder, &lst_a, &lst_b, conf);
}
