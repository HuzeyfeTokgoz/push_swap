/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 03:27:22 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/21 17:42:53 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libft/libft.h"
#include <limits.h>


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
		if (ft_strncmp(av[i], "--simple", 9) == 0)
			conf->algoritma = SIMPLE;
		if (ft_strncmp(av[i], "--medium", 9) == 0)
			conf->algoritma = MEDIUM;
		if (ft_strncmp(av[i], "--complex", 10) == 0)
			conf->algoritma = COMPLEX;
		if (ft_strncmp(av[i], "--adaptive", 11) == 0)
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