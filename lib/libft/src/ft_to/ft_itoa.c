/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:09:49 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/03/17 11:33:11 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*convert_to_str(int n, char *ptr, size_t digits)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		ptr[i] = '-';
		i++;
		if (n == -2147483648)
		{
			ptr[i] = '2';
			i++;
			n = 147483648;
		}
		else
			n = -n;
	}
	ptr[digits] = '\0';
	while (digits > i)
	{
		digits--;
		ptr[digits] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	digits;

	digits = ft_count_digits(n);
	ptr = malloc(digits + 1);
	if (!ptr)
		return (NULL);
	return (convert_to_str(n, ptr, digits));
}
