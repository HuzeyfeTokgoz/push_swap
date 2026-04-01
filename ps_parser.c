/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 03:27:22 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/04/01 21:56:56 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft/libft.h"
#include "push_swap.h"
#include <limits.h>

void	ps_parser(char *av, t_ps_lst **list)
{
	int			i;
	long		a;
	char		**arr;
	t_ps_lst	*temp;

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

void	ps_flag(int ac, char **av, t_ps_lst **lst_a, t_config *conf)
{
	int	i;
	int	flags_done;

	i = 1;
	flags_done = 0;
	while (ac > i && av[i])
	{
		if (!flags_done && ft_strncmp(av[i], "--bench", 8) == 0)
			conf->benchmark = 1;
		else if (!flags_done && ft_strncmp(av[i], "--simple", 9) == 0)
			conf->algoritma = SIMPLE;
		else if (!flags_done && ft_strncmp(av[i], "--medium", 9) == 0)
			conf->algoritma = MEDIUM;
		else if (!flags_done && ft_strncmp(av[i], "--complex", 10) == 0)
			conf->algoritma = COMPLEX;
		else if (!flags_done && ft_strncmp(av[i], "--adaptive", 11) == 0)
			conf->algoritma = ADAPTIVE;
		else
		{
			flags_done = 1;
			ps_parser(av[i], lst_a);
		}
		i++;
	}
}
