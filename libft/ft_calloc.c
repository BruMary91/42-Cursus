/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:18:44 by mbrunett          #+#    #+#             */
/*   Updated: 2023/03/02 15:57:30 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	if ((count == SIZE_MAX) || (size == SIZE_MAX))
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	ft_bzero(str, count * size);
	return (str);
}
