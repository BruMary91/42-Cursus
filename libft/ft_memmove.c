/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:24 by mbrunett          #+#    #+#             */
/*   Updated: 2023/02/28 12:25:41 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	n;

	d = (char *)dst;
	s = (char *)src;
	n = 0;
	if (!dst && !src)
		return (0);
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		while (n < len)
		{
			d[n] = s[n];
			n++;
		}
	}
	return (dst);
}
