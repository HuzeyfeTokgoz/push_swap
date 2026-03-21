/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:29:45 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/21 15:57:57 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct push_swap
{
	int					content;
	int					index;
	struct push_swap	*next;
}	ps_lst;

typedef	struct ps_config
{
	int	algoritma;
	int	benchmark;
	double disorder;
	int is_checker;
	int pb;
	int pa;
	int sa;
	int sb;
	int ra;
	int rra;
	int rb;
	int rrb;
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
void	ps_error(ps_lst **lsthead, char **arr);
ps_lst	*ps_lstnew(int content);
ps_lst	*ps_lstlast(ps_lst *lst);
ps_lst	*lst_to_index(ps_lst *lst_a);
int		lst_dup(ps_lst *lst, int a);
int		is_numeric(char *num);
int		ps_lstsize(ps_lst *lst);
int		get_minmax_index(ps_lst *lst, int min_max);
long	ps_atol(const char *str);
void	push_target(ps_lst **lst_a, ps_lst **lst_b, int *target, int *flag, config *conf);
void	quick_pb(ps_lst **lst_a, ps_lst **lst_b, int size, config *conf);
void	quick_pa(ps_lst **lst_a, ps_lst **lst_b, int size, config *conf);
double	ps_disorder(ps_lst *lst_a);
void	sort_benchmark(config *conf);

void	sort_three(ps_lst **a, config *conf);
void	sort_simple(ps_lst **a, ps_lst **b, config *conf);
void	sort_medium(ps_lst **a, ps_lst **b, config *conf);
void	sort_complex(ps_lst **a, ps_lst **b, config *conf);
void	sort_benchmark(config *conf);

void	ps_pa(ps_lst **a, ps_lst **b, config *conf);
void	ps_pb(ps_lst **a, ps_lst **b, config *conf);
void	ps_sa(ps_lst **a, config *conf);
void	ps_sb(ps_lst **b, config *conf);
void	ps_ra(ps_lst **a, config *conf);
void	ps_rb(ps_lst **b, config *conf);
void	ps_rra(ps_lst **a, config *conf);
void	ps_rrb(ps_lst **b, config *conf);


