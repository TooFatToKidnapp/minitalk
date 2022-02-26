/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:27:08 by aabdou            #+#    #+#             */
/*   Updated: 2022/02/26 22:22:45 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (c >> i & 1) + SIGUSR1);
		usleep(300);
		i--;
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "\033[0;32m", 7);
		write(1, "Server: message received\n", 25);
	}	
	exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*string;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(1, "\033[0;31m", 7);
		write(2, "not enough arguments\n", 21);
		return (0);
	}
	string = av[2];
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, sig_handler);
	while (string[i])
	{
		send_char(string[i], pid);
		i++;
	}
	send_char(0, pid);
}
