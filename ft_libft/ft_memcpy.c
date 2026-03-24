/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:21:45 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/01/28 22:33:47 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*srcs;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	srcs = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		dst[i] = srcs[i];
		i++;
	}
	return (dst);
}
