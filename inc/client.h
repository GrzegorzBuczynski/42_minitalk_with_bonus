/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:00:51 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/07/07 00:29:38 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# ifndef USLEEP_N
# define USLEEP_N 1000
# endif

# include "common.h"

typedef struct s_client_state
{
	int ack_received;
	int send_next;
}	t_client_state;

void	send_int(pid_t receiver, int n, int with_sleep);
void	send_data_with_sleep(pid_t reciver, char *data, size_t n_bytes);
void	send_data_with_signals(pid_t receiver, char *data, size_t n_bytes);

#endif