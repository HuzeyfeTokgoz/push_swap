/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:29:45 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/21 02:27:26 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct push_swap
{
	int					content;
	struct push_swap	*next;
}	ps_lst;


void	ps_parser(int ac, char *av, ps_lst **lsthead);
char	**ft_split(char const *s, char c);
void	ps_lstadd_back(ps_lst **lst, ps_lst *new);
ps_lst	*ps_lstnew(int content);
ps_lst	*ps_lstlast(ps_lst *lst);


