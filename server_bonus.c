/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:46:49 by msodor            #+#    #+#             */
/*   Updated: 2023/01/13 18:45:21 by msodor           ###   ########.fr       */
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
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
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
	siga.sa_sigaction = &signal_handler;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
}
