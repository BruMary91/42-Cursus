/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:13:54 by mbrunett          #+#    #+#             */
/*   Updated: 2023/05/30 10:11:53 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *copy)
{
	char	*buffer;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(copy, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		copy = ft_strjoin(copy, buffer);
	}
	free(buffer);
	return (copy);
}

char	*get_line(char *copy)
{
	int		i;
	char	*line;

	i = 0;
	if (!copy[i])
		return (NULL);
	while (copy[i] && copy[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (copy[i] && copy[i] != '\n')
	{
		line[i] = copy[i];
		i++;
	}
	if (copy[i] == '\n')
	{
		line[i] = copy[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_rest_of_file(char *copy)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (copy[i] && copy[i] != '\n')
		i++;
	if (!copy[i])
	{
		free(copy);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(copy) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (copy[i])
		str[j++] = copy[i++];
	str[j] = '\0';
	free(copy);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*copy;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	copy = ft_read_file(fd, copy);
	if (!copy)
		return (NULL);
	line = get_line(copy);
	copy = ft_rest_of_file(copy);
	return (line);
}
