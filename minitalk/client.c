/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:14:08 by mbrunett          #+#    #+#             */
/*   Updated: 2023/07/21 15:29:12 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm_message(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Il messaggio é stato ricevuto!\n");
	else
		ft_printf("Il messaggio é stato ricevuto!\n");
}

void	bit_handler(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	string_to_server(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		signal(SIGUSR1, confirm_message);
		signal(SIGUSR2, confirm_message);
		bit_handler(str[i], pid);
		i++;
	}
	bit_handler('\n', pid);
	bit_handler('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("ERRORE: Il numero dei parametri é errato.\n");
		exit (1);
	}
	pid = ft_atoi(argv[1]);
	if (argv[2][0] == '\0')
	{
		ft_printf("Attenzione: La stringa è vuota!\n");
		exit(1);
	}
	string_to_server(pid, argv[2]);
	return (0);
}
