/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:22:50 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/12 15:59:10 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_special(char specifier, va_list arguments_list)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(arguments_list, int));
	else if (specifier == 's')
		count += print_string(va_arg(arguments_list, char *));
	else if (specifier == 'p')
		count += print_pointer(va_arg(arguments_list, unsigned long long *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(arguments_list, int)), 10);
	else if (specifier == 'u')
		count += print_unsigned(va_arg(arguments_list, unsigned int));
	else if (specifier == 'x')
		count += print_hexl((long)(va_arg(arguments_list, unsigned int)));
	else if (specifier == 'X')
		count += print_hexu((long)(va_arg(arguments_list, unsigned int)));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *last_known_pointer, ...)
{
	va_list	arguments_list;
	int		count;

	va_start(arguments_list, last_known_pointer);
	count = 0;
	while (*last_known_pointer)
	{
		if (*last_known_pointer == '%')
		{
			if (ft_strchr("cspdiuxX", *(++last_known_pointer)))
				count += print_special(*(last_known_pointer), arguments_list);
			else
				count += write(1, last_known_pointer, 1);
		}
		else
			count += write(1, last_known_pointer, 1);
		++last_known_pointer;
	}
	va_end(arguments_list);
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	print(" NULL %s NULL ", NULL);
// 	// int count;
// 	// count = ft_printf("tekst %s\n", "string");
// 	// ft_printf("chars written = %d\n", count);
// 	// ft_printf("tekst %p\n", &count);
// 	// printf("tekst %p\n", &count);
// 	// printf("tekst %u\n", INT32_MAX);
// 	// printf("tekst %d\n", INT32_MAX);
// }