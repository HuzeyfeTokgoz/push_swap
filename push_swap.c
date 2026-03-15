/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:58:27 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/15 03:58:44 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "ft_libft/libft.h"

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
			if (lst_a->index > temp->index)
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

void	ps_router(ps_lst **lst_a, ps_lst **lst_b, config *conf)
{
	int		size;
	double	disorder;

	disorder = conf->disorder;
	size = ps_lstsize(*lst_a);
	if (size == 3 && conf->algoritma == ADAPTIVE)
		sort_three(lst_a, conf);
	else if (conf->algoritma == ADAPTIVE)
	{
		if (disorder < 0.2)
			sort_simple(lst_a, lst_b, conf);
		else if (disorder < 0.5)
			sort_medium(lst_a, lst_b, conf);
		else if (disorder >= 0.5)
			sort_complex(lst_a, lst_b, conf);
	}
	else if (conf->algoritma == SIMPLE)
		sort_simple(lst_a, lst_b, conf);
	else if (conf->algoritma == MEDIUM)
		sort_medium(lst_a, lst_b, conf);
	else if (conf->algoritma == COMPLEX)
		sort_complex(lst_a, lst_b, conf);
	if (conf->benchmark == 1)
		sort_benchmark(conf);
}

int main(int ac, char **av)
{
	ps_lst	*lst_a;
	ps_lst	*lst_b;
	config	conf;
	int		size;

	lst_a = NULL;
	lst_b = NULL;
	ft_memset(&conf, 0, sizeof(config));
	conf.benchmark = 0;
	conf.algoritma = ADAPTIVE;
	ps_flag(ac, av, &lst_a, &conf);
	if (!lst_a)
		return (0);
	size = ps_lstsize(lst_a);
	lst_a = lst_to_index(lst_a);
	conf.disorder = ps_disorder(lst_a);
	if ((conf.algoritma == ADAPTIVE && (size == 0 || size == 1)) || (conf.disorder == 0.0))
		return (0);
	if (size == 2)
	{
		if ((*lst_a).index > (*lst_a).next->index)
			ps_sa(&lst_a, &conf);
		return (0);
	}
	ps_router(&lst_a, &lst_b, &conf);
}
