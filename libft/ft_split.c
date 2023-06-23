/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:26:23 by mbrunett          #+#    #+#             */
/*   Updated: 2023/03/04 14:50:10 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_word_lenght(char const *str, int *j, char c)
{
	int		i;
	char	*temp;

	if (!str)
		return (NULL);
	i = 0;
	while (str[*j] && str[*j] == c)
		(*j)++;
	while (str[*j] && str[*j] != c)
	{
		i++;
		(*j)++;
	}
	temp = malloc((sizeof(char) * i) + 1);
	*j = *j - i;
	i = 0;
	while (str[*j] && str[*j] != c)
	{
		temp[i++] = str[*j];
		(*j)++;
	}
	temp[i] = 0;
	(*j)--;
	return (temp);
}

int	word_counter(char const *str, char c)
{
	int	i;
	int	flag;
	int	counter;

	counter = 0;
	i = -1;
	flag = 1;
	while (str[++i])
	{
		if (str[i] != c && flag)
		{
			flag = 0;
			counter++;
		}
		else if (str[i] == c)
			flag = 1;
	}
	return (counter);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		words;
	char	**strs;

	if (!str)
		return (0);
	j = 0;
	words = word_counter(str, c);
	strs = malloc((words + 1) * sizeof(char *));
	if (!strs)
		return (0);
	i = -1;
	while (++i < words)
	{
		strs[i] = get_word_lenght(str, &j, c);
		j++;
	}
	strs[words] = 0;
	return (strs);
}
