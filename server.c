/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:52:57 by msodor            #+#    #+#             */
/*   Updated: 2023/01/20 17:01:24 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_count = 7;

void	signal_handler(int sig, siginfo_t *info, void *cntx)
{
	static int	old_pid;
	static char	c;
	int			client_pid;

	(void)cntx;
	client_pid = info->si_pid;
	if (client_pid != old_pid)
	{
		old_pid = client_pid;
		g_count = 7;
	}
	if (sig == SIGUSR2)
		c = c | (1 << g_count--);
	else
		g_count--;
	if (g_count == -1)
	{
		ft_printf("%c", c);
		c = 0;
		g_count = 7;
	}
}

int	main(void)
{
	struct sigaction	siga;
	int					pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	siga.sa_sigaction = signal_handler;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
}
