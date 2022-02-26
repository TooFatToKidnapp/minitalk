/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:22:33 by aabdou            #+#    #+#             */
/*   Updated: 2022/02/18 20:25:22 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *nothing)
{
	(void) nothing;
	static int client_pid;
	static int i;
	static int c;

	if (client_pid != info->si_pid && i != 0)
	{
		i = 0;
		c = 0;
	}
	c = c << 1 | (signal - 30);
	i++;
	if (i == 8)
	{
		if( c == 0)
		{
			kill(info->si_pid, SIGUSR1);
		}	
			write(1, &c, 1);	
		c = 0;
		i = 0;
	}
	client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID :\t");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
