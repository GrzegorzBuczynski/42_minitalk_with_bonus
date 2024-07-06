/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:52:17 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/26 02:00:53 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	int		count;

	count = 0;
	if (n < 10)
	{
		return (print_char(0 + n));
	}
	else
	{
		count = print_digit(n / 10, 10);
		return (count + print_digit(n % 10, 10));
	}
}
