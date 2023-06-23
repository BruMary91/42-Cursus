/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:19:43 by mbrunett          #+#    #+#             */
/*   Updated: 2023/06/22 10:38:38 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenght(int nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr <= 0)
		i = i + 1;
	while (nbr && ++i)
		nbr /= base;
	return (i);
}

int	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_print_str("-2147483648");
	}
	else if (nbr < 0)
	{
		ft_putchar(45);
		ft_putnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + 48);
	}
	return (lenght(nbr, 10));
}

int	u_lenght(long long nbr, int base)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i = i + 1;
	while (nbr && ++i)
		nbr /= base;
	return (i);
}

int	ft_putunbr(unsigned int nbr)
{
	if (nbr == 4294967295)
	{
		ft_print_str("4294967295");
	}
	else if (nbr >= 10)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + 48);
	}
	return (u_lenght(nbr, 10));
}
