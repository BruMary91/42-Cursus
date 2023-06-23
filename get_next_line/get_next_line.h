/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:55:46 by mbrunett          #+#    #+#             */
/*   Updated: 2023/05/30 10:16:22 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char		*ft_strchr(char *s, int c);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *copy, char *s);
char		*ft_read_file(int fd, char *copy);
char		*get_line(char *copy);
char		*ft_rest_of_file(char *copy);
char		*get_next_line(int fd);

#endif
