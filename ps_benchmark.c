/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:56:49 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/25 23:36:13 by hutokgoz         ###   ########.fr       */
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

void	sort_benchmark(t_config *conf, int total)
{
	total = conf->sa + conf->sb + conf->pa + conf->pb + conf->ra + conf->rb
		+ conf->rra + conf->rrb;
	print_bench_disorder(conf->disorder);
	write(2, "[bench] strategy: ", 18);
	if (conf->algoritma == SIMPLE)
		write(2, "Simple\n", 7);
	else if (conf->algoritma == MEDIUM)
		write(2, "Medium\n", 7);
	else if (conf->algoritma == COMPLEX)
		write(2, "Complex\n", 8);
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
	print_bench_row("rr", 0);
	print_bench_row("rrr", 0);
	print_bench_row("ss", 0);
}
