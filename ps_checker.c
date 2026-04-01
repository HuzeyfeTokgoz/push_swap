/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 01:31:33 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/04/01 21:52:41 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "push_swap.h"
#include <unistd.h>

static int	is_sorted(t_ps_lst *lst_a)
{
	while (lst_a && lst_a->next)
	{
		if (lst_a->content < lst_a->next->content)
			lst_a = lst_a->next;
		else
			return (0);
	}
	return (1);
}

static void	target_checker(char *line, t_ps_lst **lst_a, t_ps_lst **lst_b,
			t_config *conf)
{
	if (ft_strncmp(line, "pb", 2) == 0)
		ps_pb(lst_a, lst_b, conf);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ps_ra(lst_a, conf);
	else if (ft_strncmp(line, "rb", 2) == 0)
		ps_rb(lst_b, conf);
	else if (ft_strncmp(line, "rra", 3) == 0)
		ps_rra(lst_a, conf);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		ps_rrb(lst_b, conf);
	else if (ft_strncmp(line, "rr", 2) == 0)
		ps_rr(lst_a, lst_b, conf);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		ps_rrr(lst_a, lst_b, conf);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ps_ss(lst_a, lst_b, conf);
	else
	{
		free(line);
		ps_lstclear(lst_b);
		ps_error(lst_a, NULL);
	}
}

static void	ps_checker(t_ps_lst **lst_a, t_ps_lst **lst_b, t_config *conf)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, "sa", 2) == 0)
			ps_sa(lst_a, conf);
		else if (ft_strncmp(line, "sb", 2) == 0)
			ps_sb(lst_b, conf);
		else if (ft_strncmp(line, "pa", 2) == 0)
			ps_pa(lst_a, lst_b, conf);
		else
			target_checker(line, lst_a, lst_b, conf);
		free(line);
		line = get_next_line(0);
	}
	if (*lst_b == NULL && is_sorted(*lst_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_ps_lst	*lst_a;
	t_ps_lst	*lst_b;
	t_config	conf;

	lst_a = NULL;
	lst_b = NULL;
	ft_memset(&conf, 0, sizeof(t_config));
	conf.is_checker = 1;
	if (ac < 2)
		return (0);
	ps_flag(ac, av, &lst_a, &conf);
	if (!lst_a)
		return (0);
	ps_checker(&lst_a, &lst_b, &conf);
	ps_lstclear(&lst_a);
	ps_lstclear(&lst_b);
}
