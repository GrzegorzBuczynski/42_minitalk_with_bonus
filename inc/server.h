/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:45:09 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/07/06 17:45:26 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "common.h"

typedef struct s_server_state
{
	int		total_byts;
	char	*str;
	pid_t	client_pid;
	int		client_pid_ready;
	size_t	i;
	char	*ptr;
	int		is_waiting;
}			t_server_state;

void		run_cycle(void);

#endif
