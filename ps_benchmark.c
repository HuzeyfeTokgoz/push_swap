/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:56:49 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/04/15 00:14:37 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

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

static int	count_ops(t_config *conf)
{
	int	total;

	total = conf->sa + conf->sb + conf->pa + conf->pb + conf->ra + conf->rb
		+ conf->rra + conf->rrb + conf->rr + conf->rrr + conf->ss;
	return (total);
}

static void	print_strategy(t_config *conf)
{
	if (conf->algoritma == SIMPLE)
		write(2, "Simple / O(n2)\n", 15);
	else if (conf->algoritma == MEDIUM)
		write(2, "Medium / O(n*sqrt(n))\n", 22);
	else if (conf->algoritma == COMPLEX)
		write(2, "Complex / O(n log n)\n", 21);
	else if (conf->algoritma == ADAPTIVE)
	{
		write(2, "Adaptive / ", 11);
		if (conf->disorder < 0.2)
			write(2, "O(n2)\n", 6);
		else if (conf->disorder < 0.5)
			write(2, "O(n*sqrt(n))\n", 13);
		else
			write(2, "O(n log n)\n", 11);
	}
}

void	sort_benchmark(t_config *conf)
{
	int	total;

	total = count_ops(conf);
	print_bench_disorder(conf->disorder);
	write(2, "[bench] strategy: ", 18);
	print_strategy(conf);
	print_bench_row("total_ops", total);
	print_bench_row("sa", conf->sa);
	print_bench_row("sb", conf->sb);
	print_bench_row("pa", conf->pa);
	print_bench_row("pb", conf->pb);
	print_bench_row("ra", conf->ra);
	print_bench_row("rb", conf->rb);
	print_bench_row("rra", conf->rra);
	print_bench_row("rrb", conf->rrb);
	print_bench_row("rr", conf->rr);
	print_bench_row("rrr", conf->rrr);
	print_bench_row("ss", conf->ss);
}
