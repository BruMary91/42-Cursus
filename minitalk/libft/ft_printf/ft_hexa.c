/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:44:52 by mbrunett          #+#    #+#             */
/*   Updated: 2023/06/23 12:05:38 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int nbr, const char type)
{
	char	c;

	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16, type);
		ft_print_hex(nbr % 16, type);
	}
	else
	{
		if (nbr <= 9)
			c = nbr + '0';
		else
		{
			if (type == 'x')
				c = nbr - 10 + 'a';
			if (type == 'X')
				c = nbr - 10 + 'A';
		}
		ft_putchar(c);
	}
}

int	hex_lenght(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

int	puthexnbr(unsigned int nbr, const char type)
{
	if (nbr == 0)
		return (ft_putchar('0'));
	else
		ft_print_hex(nbr, type);
	return (hex_lenght(nbr));
}
