/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:32:13 by solee2            #+#    #+#             */
/*   Updated: 2023/04/29 17:35:46 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signum, siginfo_t *siginfo, void *context)
{
	static int	bit = 0;
	static int	temp;

	(void)context;
	if (signum == SIGUSR1)
		temp |= 0;
	else if (signum == SIGUSR2)
		temp |= 1;
	if (bit < 7)
		temp = temp << 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (char)temp);
		bit = 0;
		temp = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_server;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: Wrong Number of Arguments\n");
		exit(1);
	}
	ft_printf("SERVER PID: %d\n", getpid());
	sig_server.sa_sigaction = sighandler;
	sigemptyset(&sig_server.sa_mask);
	sig_server.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_server, NULL);
	sigaction(SIGUSR2, &sig_server, NULL);
	while (1)
		;
	return (0);
}
