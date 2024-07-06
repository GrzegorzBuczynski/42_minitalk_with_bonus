/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:54:19 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/12 17:26:47 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexl(unsigned long int n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 16)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_hexl(n / 16);
		return (count + print_hexl(n % 16));
	}
}
