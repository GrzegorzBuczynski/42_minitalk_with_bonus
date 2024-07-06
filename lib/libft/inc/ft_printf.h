/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:02:46 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/26 02:02:49 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *imput, ...);
int	print_char(int c);
int	print_string(char *str);
int	print_digit(long n, int base);
int	print_hexl(unsigned long int n);
int	print_hexu(unsigned long int n);
int	print_pointer(void *prt);
int	print_unsigned(unsigned int n);

#endif
