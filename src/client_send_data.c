/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:10:05 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/07/07 17:30:01 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern t_client_state	g_client_state;

void	send_int(__pid_t reciver, int n, int with_sleep)
{
	if (with_sleep)
		send_data_with_sleep(reciver, (char *)&n, sizeof(int));
	else
		send_data_with_signals(reciver, (char *)&n, sizeof(int));
}

void	send_data_with_sleep(pid_t reciver, char *data, size_t size)
{
	size_t	bytes_done;
	int		i;

	bytes_done = 0;
	while (bytes_done < size)
	{
		i = 0;
		while (i < BYTE_SIZE)
		{
			if ((*data >> (BYTE_SIZE - i - 1)) & 1)
				kill(reciver, SIGUSR2);
			else
				kill(reciver, SIGUSR1);
			i++;
			usleep(USLEEP_N);
		}
		data++;
		bytes_done++;
	}
}

void	send_data_with_signals(__pid_t reciver, char *data, size_t size)
{
	size_t	bytes_done;
	int		i;

	bytes_done = 0;
	while (bytes_done < size)
	{
		i = 0;
		while (i < BYTE_SIZE)
		{
			while (!g_client_state.send_next)
				usleep(10);
			g_client_state.send_next = 0;
			if ((*data >> (BYTE_SIZE - i - 1)) & 1)
				kill(reciver, SIGUSR2);
			else
				kill(reciver, SIGUSR1);
			i++;
		}
		data++;
		bytes_done++;
	}
}
