/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:29:45 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/24 20:01:57 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct push_swap
{
	int					content;
	struct push_swap	*next;
}	ps_lst;

typedef	struct ps_config
{
	int	algoritma;
	int	benchmark;
}	config;

#define ADAPTIVE 0
#define SIMPLE 1
#define MEDIUM 2
#define COMPLEX 3

#include <stdlib.h>

char	**ft_split(char const *s, char c);
void	ps_parser(char *av, ps_lst **lsthead);
void	ps_lstadd_back(ps_lst **lst, ps_lst *new);
void	ps_lstadd_front(ps_lst **lst, ps_lst *new);
void	ps_lstclear(ps_lst **lst);
void	error(ps_lst **lsthead, char **arr);
ps_lst	*ps_lstnew(int content);
ps_lst	*ps_lstlast(ps_lst *lst);
int		lst_dup(ps_lst *lst, int a);
int		is_numeric(char *num);
int		ps_lstsize(ps_lst *lst);
long	ps_atol(const char *str);
int		get_minmax_index(ps_lst *lst, int min_max);


void	sort_three(ps_lst **a);
void	sort_simple(ps_lst **a, ps_lst **b);
void	sort_medium(ps_lst **a, ps_lst **b);
void	sort_complex(ps_lst **a, ps_lst **b);
void	sort_benchmark(ps_lst **a, ps_lst **b);

void	ps_pp(ps_lst **a, ps_lst **b, int papb);
void	ps_sa(ps_lst **a, int print_flg);
void	ps_sb(ps_lst **b, int print_flg);
void	ps_ss(ps_lst **a, ps_lst **b);
void	ps_ra(ps_lst **a, int print_flg);
void	ps_rb(ps_lst **b, int print_flg);
void	ps_rr(ps_lst **a, ps_lst **b);
void	ps_rra(ps_lst **a, int print_flg);
void	ps_rrb(ps_lst **b, int print_flg);


