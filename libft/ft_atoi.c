/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:32:29 by mbrunett          #+#    #+#             */
/*   Updated: 2023/02/28 10:52:56 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	nb;
	int	y;

	x = 0;
	nb = 0;
	y = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == 45 || str[x] == 43)
	{
		if (str[x] == 45)
			y = y * -1;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		nb = nb * 10 + (str[x] - 48);
		x++;
	}
	return (nb * y);
}
