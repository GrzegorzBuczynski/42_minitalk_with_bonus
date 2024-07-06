/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:45:47 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/03/01 20:46:09 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* int	main(void)
{
	write(1, "ft_toupper('a'): ", 17);
	write(1, &ft_toupper('a'), 1);
	write(1, "\n", 1);
	write(1, "ft_toupper('A'): ", 17);
	write(1, &ft_toupper('A'), 1);
	write(1, "\n", 1);
	write(1, "ft_toupper('z'): ", 17);
	write(1, &ft_toupper('z'), 1);
	write(1, "\n", 1);
	write(1, "ft_toupper('Z'): ", 17);
	write(1, &ft_toupper('Z'), 1);
	write(1, "\n", 1);
	write(1, "ft_toupper('0'): ", 17);
	write(1, &ft_toupper('0'), 1);
	write(1, "\n", 1);
	write(1, "ft_toupper('9'): ", 17);
	write(1, &ft_toupper('9'), 1);
	write(1, "\n", 1);
	return (0);
} */