/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:54:24 by aabdou            #+#    #+#             */
/*   Updated: 2022/02/19 22:54:29 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


int		ft_atoi(const char	*str);
int		ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

#endif