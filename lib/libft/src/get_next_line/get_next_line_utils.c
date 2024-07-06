/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:09:08 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/07/06 22:35:58 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *buff, char *temp)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!temp)
		return (0);
	if (!buff)
	{
		buff = malloc(sizeof(char));
		buff[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(temp) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (buff && buff[++i] != '\0')
		str[i] = buff[i];
	while (temp && temp[j] != '\0')
		str[i++] = temp[j++];
	str[i] = '\0';
	free(buff);
	return (str);
}
