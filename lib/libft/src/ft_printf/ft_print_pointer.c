/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:52:49 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/12 17:29:05 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *prt)
{
	int	len;

	len = 0;
	if (!prt)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += print_hexl((unsigned long int)prt);
	return (len);
}
