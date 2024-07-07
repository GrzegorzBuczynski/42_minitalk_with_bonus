/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:29:47 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/07/07 18:16:07 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			set_sighandler(int to_set, void (*f)(int), int to_mask);
void			handle_sigusr(int sig);

t_server_state	g_server_state;

int	main(void)
{
	set_sighandler(SIGUSR1, handle_sigusr, SIGUSR2);
	set_sighandler(SIGUSR2, handle_sigusr, SIGUSR1);
	ft_printf("PID: %d\n", getpid());
	while (1)
		run_cycle();
	return (0);
}

void	set_sighandler(int to_set, void (*handler)(int), int to_mask)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, to_mask);
	sigaction(to_set, &sa, NULL);
}

void	handle_sigusr(int sig)
{
	(void)sig;
	if (!(g_server_state.i % BYTE_SIZE) && g_server_state.i > 0)
		g_server_state.ptr++;
	*g_server_state.ptr = *g_server_state.ptr << 1;
	g_server_state.i++;
	g_server_state.is_waiting = 0;
	if (sig == SIGUSR2)
		*g_server_state.ptr |= 1;
}
