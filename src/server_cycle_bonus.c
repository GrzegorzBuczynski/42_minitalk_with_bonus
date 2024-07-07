/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cycle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:29:42 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/07/07 18:20:09 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void					read_data(void *data, size_t size);
void					inform_client(void);
void					acknowledge(void);
void					validate_client_pid(void);

extern t_server_state	g_server_state;

void	run_cycle(void)
{
	g_server_state.client_pid_ready = 0;
	g_server_state.client_pid = 0;
	read_data(&g_server_state.client_pid, sizeof(g_server_state.client_pid));
	validate_client_pid();
	g_server_state.total_byts = 0;
	read_data(&g_server_state.total_byts, sizeof(g_server_state.total_byts));
	g_server_state.str = malloc(sizeof(char) * (g_server_state.total_byts + 1));
	g_server_state.str[g_server_state.total_byts] = 0;
	read_data(g_server_state.str, g_server_state.total_byts);
	ft_putendl_fd(g_server_state.str, STDOUT_FILENO);
	free(g_server_state.str);
	acknowledge();
}

void	read_data(void *data, size_t size)
{
	g_server_state.i = 0;
	g_server_state.ptr = data;
	while (g_server_state.i < BYTE_SIZE * size)
	{
		g_server_state.is_waiting = 1;
		if (g_server_state.client_pid_ready)
			inform_client();
		while (g_server_state.is_waiting)
			usleep(10);
	}
}

void	inform_client(void)
{
	if (kill(g_server_state.client_pid, SIGUSR1) == -1)
	{
		ft_putendl_fd("Communication failed!", STDERR_FILENO);
		exit(1);
	}
}

void	acknowledge(void)
{
	if (kill(g_server_state.client_pid, SIGUSR2) == -1)
		ft_putendl_fd("Acknowledge failed!", STDERR_FILENO);
}

void	validate_client_pid(void)
{
	if (kill(g_server_state.client_pid, 0) == -1)
	{
		ft_putendl_fd("Client PID invalid", STDERR_FILENO);
		exit(2);
	}
	g_server_state.client_pid_ready = 1;
}
