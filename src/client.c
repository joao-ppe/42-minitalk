/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:06:59 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/16 13:30:34 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_string(int pid, int c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (((c >> bits) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bits++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc != 3)
	{
		write(1, "Wrong syntax: './client> <server_pid> <message>'.\n", 51);
		return (1);
	}
	else
	{
		i = -1;
		server_pid = ft_atoi(argv[1]);
		while (argv[2][++i])
			send_string(server_pid, argv[2][i]);
		send_string(server_pid, '\n');
	}
	return (0);
}
