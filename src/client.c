/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:01:13 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/07/07 00:34:08 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	set_sighandler(int to_set, void (*handler)(int));
void	handle_sigusr1(int sig);
void	handle_sigusr2(int sig);

t_client_state g_state;

int main(int ac, char *av[])
{
	pid_t pid;

	g_state.ack_received = 0;
	if(ac !=3)
	{
		ft_putendl_fd("Invalid number of parameters", STDERR_FILENO);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if(!pid || kill(pid, 0) == -1)
	{
		ft_putendl_fd("Server PID invalid", STDERR_FILENO);
		exit(2);
	}
	set_sighandler(SIGUSR1, handle_sigusr1);
	g_state.send_next = 0;
	send_int(pid, getpid(), 1);
	send_int(pid, ft_strlen(av[2]), 0);
	send_data_with_signals(pid, av[2], ft_strlen(av[2]));
}

void	set_sighandler(int to_set, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(to_set, &sa, NULL);
}

void	handle_sigusr1(int sig)
{
	(void)sig;
	g_state.send_next = 1;
}

void	handle_sigusr2(int sig)
{
	(void)sig;
	g_state.ack_received = 1;
	ft_putendl_fd("Server acknowlegge recived!", STDOUT_FILENO);
}
