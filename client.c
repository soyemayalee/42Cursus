/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:32:06 by solee2            #+#    #+#             */
/*   Updated: 2023/04/29 17:13:31 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	g_boolean;

void	signal_final(int signum)
{
	if (signum == SIGUSR1)
		g_boolean = 0;
	else
		g_boolean = 1;
}

void	cli_sighandler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signum == SIGUSR1)
		g_boolean = 0;
	else if (signum == SIGUSR2)
		g_boolean = 1;
}

void	signal_processor(int pid, unsigned char input)
{
	int	bit;
	int	temp;

	bit = 0;
	while (bit < 8)
	{
		if (bit == 0)
			g_boolean = 0;
		temp = input >> (7 - bit) & 1;
		if (temp == 0)
			kill(pid, SIGUSR1);
		else if (temp == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	str_processor(int pid, char *input)
{
	int		length;
	int		index;

	g_boolean = 1;
	if (input == NULL)
		exit(1);
	length = ft_strlen(input);
	index = 0;
	while (index < length && g_boolean == 1)
	{
		g_boolean = 0;
		signal_processor(pid, input[index]);
		signal(SIGUSR2, signal_final);
		while (g_boolean == 0)
			pause();
		index++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_client;
	pid_t				pid;
	char				*input;

	if (argc != 3)
	{
		ft_printf("Wrong Number of Arguments\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 4194304)
	{
		ft_printf("PID Number is Invalid\n");
		return (1);
	}
	input = ft_strjoin(argv[2], "\n");
	sig_client.sa_sigaction = cli_sighandler;
	sigemptyset(&sig_client.sa_mask);
	sig_client.sa_flags = 0;
	sigaction(SIGUSR1, &sig_client, NULL);
	sigaction(SIGUSR2, &sig_client, NULL);
	str_processor(pid, input);
	free(input);
	return (0);
}
