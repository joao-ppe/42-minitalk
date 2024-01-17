/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:06:56 by joao-ppe          #+#    #+#             */
/*   Updated: 2024/01/17 12:45:20 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	signal_handler(int signal_value)
{
	static int				bit;
	static unsigned char	c;

	if (signal_value == SIGUSR1)
		c |= (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Incorrect input. Please type: './server'.\n");
		return (1);
	}
	ft_printf("PID: %d\n", getpid());
	ft_printf("Waiting for client message...\n");
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
	return (0);
}
