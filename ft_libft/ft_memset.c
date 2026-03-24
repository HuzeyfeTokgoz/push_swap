/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:51:51 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/01/23 14:48:05 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;

	if (!s)
		return (s);
	i = 0;
	k = (unsigned char *)s;
	while (n > i)
	{
		k[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
