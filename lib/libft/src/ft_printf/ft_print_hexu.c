/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexuu.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:53:17 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/12 17:26:56 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexu(unsigned long int n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_hexu(n / 16);
		return (count + print_hexu(n % 16));
	}
}
