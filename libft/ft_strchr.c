/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:28:18 by mbrunett          #+#    #+#             */
/*   Updated: 2023/02/28 11:30:45 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char) c)
		{
			return ((char *) s + i);
		}
	}
	if (s[i] == c)
	{
		return ((char *) s + i);
	}
	return (0);
}
