/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:47:21 by msodor            #+#    #+#             */
/*   Updated: 2023/01/10 10:24:37 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	mini_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	msg_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("message resived secsefully.");
}

int	main(int ac, char *av[])
{
	int		pid;
	int		count;
	int		i;
	int		len;

	if (ac != 3)
		return (1);
	signal(SIGUSR1, msg_handler);
	pid = mini_atoi(av[1]);
	i = 0;
	len = ft_strlen(&av[2][i]) + 1;
	while (i < len)
	{
		count = 7;
		while (count >= 0)
		{
			if (av[2][i] & 1 << count--)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(150);
		}
		i++;
	}
	return (0);
}
