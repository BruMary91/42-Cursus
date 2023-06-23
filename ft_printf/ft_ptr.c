/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:59:24 by mbrunett          #+#    #+#             */
/*   Updated: 2023/06/23 11:45:57 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16);
		ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr > 9)
			ft_putchar((ptr - 10 + 'a'));
		else
			ft_putchar((ptr + 48));
	}
}

int	ft_ptr_lenght(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_putptr(uintptr_t ptr)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	if (ptr != 0)
		ft_print_ptr(ptr);
	return (ft_ptr_lenght(ptr) + 2);
}
