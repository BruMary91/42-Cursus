/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:16:19 by mbrunett          #+#    #+#             */
/*   Updated: 2023/02/28 11:04:16 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		t;
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		if (n <= 9)
		{
			c = n + '0';
			write(fd, &c, 1);
		}
		else
		{
			t = (n % 10) + '0';
			n = n / 10;
			ft_putnbr_fd(n, fd);
			write(fd, &t, 1);
		}
	}
}
