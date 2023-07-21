/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:53:54 by mbrunett          #+#    #+#             */
/*   Updated: 2023/06/26 10:25:02 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_flag(va_list args, const char type)
{
	int	len;

	len = 0;
	if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (type == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (type == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		len += puthexnbr(va_arg(args, unsigned int), type);
	else if (type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += printf_flag(args, str[i]);
			i++;
		}
		if (!str[i])
			return (len);
		if (str[i] != '%')
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
