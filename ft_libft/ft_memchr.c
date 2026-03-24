/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:30:07 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/01/28 19:09:19 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;

	if (!s)
		return (NULL);
	chr = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == chr)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
