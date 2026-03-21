/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 01:31:33 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/21 17:43:07 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"
#include "ft_libft/libft.h"
#include <unistd.h>

int	is_sorted(ps_lst *lst_a)
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

void	target_checker(char *line, ps_lst **lst_a, ps_lst **lst_b, config *conf)
{
	if (ft_strncmp(line, "pb\n", 2) == 0)
		ps_pb(lst_a, lst_b, conf);
	else if (ft_strncmp(line, "ra\n", 2) == 0)
		ps_ra(lst_a, conf);
	else if (ft_strncmp(line, "rb\n", 2) == 0) 
		ps_rb(lst_b, conf);
	// else if (ft_strncmp(line, "rr\n", 3) == 0)
	// 	ps_rr(lst_a, lst_b, conf);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		ps_rra(lst_a, conf);
	else if (ft_strncmp(line, "rrb\n", 3) == 0)
		ps_rrb(lst_b, conf);
	// else if (ft_strncmp(line, "rrr\n", 4) == 0)
	// 	ps_rrr(lst_a, lst_b, conf);
	else
	{
		free(line);
		ps_lstclear(lst_b);
		ps_error(lst_a, NULL);
	}
}

void	ps_checker(ps_lst **lst_a, ps_lst **lst_b, config *conf)
{
    char *line;

    while ((line = get_next_line(0)))
    {
		if (ft_strncmp(line, "sa\n", 2) == 0)
			ps_sa(lst_a, conf);
		else if (ft_strncmp(line, "sb\n", 2) == 0)
			ps_sb(lst_b, conf);
		// else if (ft_strncmp(line, "ss\n", 2) == 0)
		// 	ps_ss(lst_a, lst_b, conf);
		else if (ft_strncmp(line, "pa\n", 2) == 0)
			ps_pa(lst_a, lst_b, conf);
		else
			target_checker(line, lst_a, lst_b, conf);
        free(line);
    }
	if (*lst_b == NULL && is_sorted(*lst_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int main(int ac, char **av)
{
	ps_lst	*lst_a;
	ps_lst	*lst_b;
	config	conf;

	lst_a = NULL;
	lst_b = NULL;
	ft_memset(&conf, 0, sizeof(config));
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
