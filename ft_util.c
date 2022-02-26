/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:57:53 by aabdou            #+#    #+#             */
/*   Updated: 2022/02/19 22:57:57 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int ft_putchar(char c )
{
    write(1, &c, 1);
    return 1;
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}