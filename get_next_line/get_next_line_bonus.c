/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:07:33 by mbrunett          #+#    #+#             */
/*   Updated: 2023/05/29 13:03:12 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_file(int fd, char *file)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(file, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		file = ft_strjoin(file, buffer);
	}
	free(buffer);
	return (file);
}

char	*get_line(char *file)
{
	int		i;
	char	*line;

	i = 0;
	if (!file[i])
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
	{
		line[i] = file[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_rest_of_file(char *file)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(file) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (file[i])
		rest[j++] = file[i++];
	rest[j] = '\0';
	free(file);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*file[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	file[fd] = ft_read_file(fd, file[fd]);
	if (!file[fd])
		return (NULL);
	line = get_line(file[fd]);
	file[fd] = ft_rest_of_file(file[fd]);
	return (line);
}
