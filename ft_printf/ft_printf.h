/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:59:21 by mbrunett          #+#    #+#             */
/*   Updated: 2023/06/26 10:24:48 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

int		printf_flag(va_list args, const char type);
int		ft_printf(const char *str, ...);

int		ft_putchar(int c);
int		ft_print_str(char *str);

int		lenght(int nbr, int base);
int		ft_putnbr(int nbr);
int		u_lenght(long long nbr, int base);
int		ft_putunbr(unsigned int nbr);

int		hex_lenght(unsigned int nbr);
void	ft_print_hex(unsigned int nbr, const char type);
int		puthexnbr(unsigned int nbr, const char type);

int		ft_ptr_lenght(unsigned long long ptr);
void	ft_print_ptr(unsigned long long ptr);
int		ft_putptr(unsigned long long ptr);

#endif
