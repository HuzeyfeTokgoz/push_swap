/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:29:45 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/23 02:00:42 by hutokgoz         ###   ########.fr       */
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

void	ps_parser(char *av, ps_lst **lsthead);
char	**ft_split(char const *s, char c);
void	ps_lstadd_back(ps_lst **lst, ps_lst *new);
void	ps_lstadd_front(ps_lst **lst, ps_lst *new);
void	ps_lstclear(ps_lst **lst);
ps_lst	*ps_lstnew(int content);
ps_lst	*ps_lstlast(ps_lst *lst);
void	error(ps_lst **lsthead, char **arr);
int		lst_dup(ps_lst *lst, int a);
int		is_numeric(char *num);
int		ps_lstsize(ps_lst *lst);


