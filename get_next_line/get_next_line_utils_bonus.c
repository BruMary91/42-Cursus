/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:08:04 by mbrunett          #+#    #+#             */
/*   Updated: 2023/05/29 13:00:20 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

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

char	*ft_strjoin(char *file, char *s)
{
	size_t	i;
	size_t	j;
	char	*n;

	if (!file)
	{
		file = (char *)malloc(1 * sizeof(char));
		file[0] = '\0';
	}
	if (!file || !s)
		return (NULL);
	n = malloc(sizeof(char) * (ft_strlen(file) + ft_strlen(s)) + 1);
	if (!n)
		return (NULL);
	i = -1;
	j = 0;
	if (file)
		while (file[++i] != '\0')
			n[i] = file[i];
	while (s[j] != '\0')
		n[i++] = s[j++];
	n[ft_strlen(file) + ft_strlen(s)] = '\0';
	free(file);
	return (n);
}
