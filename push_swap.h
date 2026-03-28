/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:29:45 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/03/28 16:29:51 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct push_swap
{
	int					content;
	int					index;
	struct push_swap	*next;
}	t_ps_lst;

typedef struct ps_t_config
{
	int		algoritma;
	int		benchmark;
	double	disorder;
	int		is_checker;
	int		pb;
	int		pa;
	int		sa;
	int		sb;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
}	t_config;

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

t_ps_lst	*ps_lstnew(int content);
t_ps_lst	*ps_lstlast(t_ps_lst *lst);
t_ps_lst	*lst_to_index(t_ps_lst *lst_a, int size);
long		ps_atol(const char *str);
char		**ft_split(char const *s, char c);
int			lst_dup(t_ps_lst *lst, int a);
int			is_numeric(char *num);
int			ps_lstsize(t_ps_lst *lst);
int			get_minmax_index(t_ps_lst *lst, int min_max);
void		ps_parser(char *av, t_ps_lst **lsthead);
void		ps_lstadd_back(t_ps_lst **lst, t_ps_lst *new);
void		ps_lstadd_front(t_ps_lst **lst, t_ps_lst *new);
void		ps_lstclear(t_ps_lst **lst);
void		ps_error(t_ps_lst **lsthead, char **arr);
void		ps_parser(char *av, t_ps_lst **list);
void		ps_flag(int ac, char **av, t_ps_lst **lst_a, t_config *conf);
void		sort_three(t_ps_lst **a, t_config *conf);
void		sort_simple(t_ps_lst **a, t_ps_lst **b, t_config *conf, int size);
void		sort_medium(t_ps_lst **a, t_ps_lst **b, t_config *conf, int size);
void		sort_complex(t_ps_lst **a, t_ps_lst **b, t_config *conf, int size);
void		sort_benchmark(t_config *conf, int total);

void		ps_pa(t_ps_lst **a, t_ps_lst **b, t_config *conf);
void		ps_pb(t_ps_lst **a, t_ps_lst **b, t_config *conf);
void		ps_sa(t_ps_lst **a, t_config *conf);
void		ps_sb(t_ps_lst **b, t_config *conf);
void		ps_ra(t_ps_lst **a, t_config *conf);
void		ps_rb(t_ps_lst **b, t_config *conf);
void		ps_rra(t_ps_lst **a, t_config *conf);
void		ps_rrb(t_ps_lst **b, t_config *conf);

#endif