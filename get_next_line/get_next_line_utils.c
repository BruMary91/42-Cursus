/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:22:13 by mbrunett          #+#    #+#             */
/*   Updated: 2023/05/24 09:41:06 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char *copy, char *s)
{
	size_t	i;
	size_t	j;
	char	*n;

	if (!copy)
	{
		copy = (char *)malloc(1 * sizeof(char));
		copy[0] = '\0';
	}
	if (!copy || !s)
		return (NULL);
	n = malloc(sizeof(char) * ((ft_strlen(copy) + ft_strlen(s)) + 1));
	if (!n)
		return (NULL);
	i = -1;
	j = 0;
	if (copy)
		while (copy[++i] != '\0')
			n[i] = copy[i];
	while (s[j] != '\0')
		n[i++] = s[j++];
	n[ft_strlen(copy) + ft_strlen(s)] = '\0';
	free(copy);
	return (n);
}
