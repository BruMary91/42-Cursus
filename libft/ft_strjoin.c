/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:06:07 by mbrunett          #+#    #+#             */
/*   Updated: 2023/02/28 12:48:10 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1 || !s2)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		new[j++] = s1[i];
	i = -1;
	while (s2[++i])
		new[j++] = s2[i];
	new[j] = 0;
	return (new);
}
