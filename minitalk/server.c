/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:24:13 by mbrunett          #+#    #+#             */
/*   Updated: 2023/07/21 14:16:41 by mbrunett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *unused)
{
	static int	bit;
	static int	bit_on_output;

	(void) unused;
	if (signal == SIGUSR1)
		bit_on_output |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (bit_on_output == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", bit_on_output);
		bit = 0;
		bit_on_output = 0;
	}
}

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Il mio PID é: %d\n", pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("ERRORE: Ci sono troppi parametri in ingresso.\n");
		exit (1);
	}
	print_pid();
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
