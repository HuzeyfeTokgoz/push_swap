/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:24:20 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/14 04:08:54 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include "ft_libft/libft.h"

void	sort_simple(ps_lst **lst_a, ps_lst **lst_b, config *conf)
{
	int size;
	int	min_index;
	int moves;
	
	size = ps_lstsize(*lst_a);
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
			while(moves--)
				ps_rra(lst_a, conf);
		}	
		ps_pb(lst_a, lst_b, conf);
		size--;
	}
	sort_three(lst_a, conf);
	while (*lst_b)
		ps_pa(lst_a, lst_b, conf);
}

void	sort_push_a(ps_lst **lst_a, ps_lst **lst_b, config *conf)
{
	int target;
	int flag;

	flag = 0;
	target = ps_lstsize(*lst_b) - 1;
	while (*lst_b)
	{
		if ((*lst_b)->index == target)
			push_target(lst_a, lst_b, &target, &flag, conf);
		else if ((*lst_b)->index == target - 1)
		{
			ps_pa(lst_a, lst_b, conf);
			flag = 1;
		}
		else
		{
			if (get_minmax_index(*lst_b, 1) <= (ps_lstsize(*lst_b) / 2))
				ps_rb(lst_b, conf);
			else
				ps_rrb(lst_b, conf);
		}
	}	
}

void	sort_push_b(ps_lst **lst_a, ps_lst **lst_b, int chunk_size, config *conf)
{
	int size;
	int limit;
	
	size = 0;
	limit = chunk_size;
	while (*lst_a)
	{
		if ((*lst_a)->index <= limit)
		{
			ps_pb(lst_a, lst_b, conf);
			size++;
			if ((*lst_b)->index < limit - (chunk_size / 2))
				ps_rb(lst_b, conf);
			if (limit == size)
				limit += chunk_size;
		}
		else
			ps_ra(lst_a, conf);
	}
}	

void	sort_medium(ps_lst **lst_a, ps_lst **lst_b, config *conf)
{
	int size;
	int chunk_size;

	size = ps_lstsize(*lst_a);
	if (size <= 100)
		chunk_size = 25;
	else
		chunk_size = 60;
	sort_push_b(lst_a, lst_b, chunk_size, conf);
	sort_push_a(lst_a, lst_b, conf);
}

void	sort_complex(ps_lst **lst_a, ps_lst **lst_b, config *conf)	
{
	int size;

	size = ps_lstsize(*lst_a);
	quick_pb(lst_a, lst_b, size, conf);
}

static void	print_bench_row(char *label, int count)
{
	write(2, "[bench] ", 8);
	ft_putstr_fd(label, 2);
	write(2, ": ", 2);
	ft_putnbr_fd(count, 2);
	write(2, "\n", 1);
}

static void	print_bench_disorder(double disorder)
{
	int	int_part;
	int	double_part;

	int_part = (int)(disorder * 100);
	double_part = (int)(disorder * 10000) % 100;
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd(int_part, 2);
	write(2, ".", 1);
	if (double_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(double_part, 2);
	write(2, "%\n", 2);
}

void	sort_benchmark(config *conf)
{
	int	total;

	total = conf->sa + conf->sb + conf->pa + conf->pb \
			+ conf->ra + conf->rb + conf->rra + conf->rrb;
	print_bench_disorder(conf->disorder);
	write(2, "[bench] strategy: ", 18);
	if (conf->algoritma == SIMPLE)
		write(2, "Simple (O(n^2))\n", 16);
	else if (conf->algoritma == MEDIUM)
		write(2, "Medium (O(n*sqrt(n)))\n", 22);
	else if (conf->algoritma == COMPLEX)
		write(2, "Complex (O(n log n))\n", 21);
	else
		write(2, "Adaptive\n", 9);
	print_bench_row("total_ops", total);
	print_bench_row("sa", conf->sa);
	print_bench_row("sb", conf->sb);
	print_bench_row("pa", conf->pa);
	print_bench_row("pb", conf->pb);
	print_bench_row("ra", conf->ra);
	print_bench_row("rb", conf->rb);
	print_bench_row("rra", conf->rra);
	print_bench_row("rrb", conf->rrb);
}
