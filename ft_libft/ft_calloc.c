/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:13:20 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/01/26 15:09:51 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	total;

	if (nmemb && size > (size_t)-1 / nmemb)
		return (NULL);
	total = nmemb * size;
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, total);
	return (str);
}
