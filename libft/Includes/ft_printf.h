/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:43:14 by amonier           #+#    #+#             */
/*   Updated: 2023/05/02 22:15:53 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
// # include <io.h>

# define HEXA "0123456789abcdef0123456789ABCDEF"
# define BASE_10 "0123456789"

//int				ft_strlen(char *str);
unsigned int	ft_putnbr_base(unsigned int n, int c, int *length);

int				ft_putnbr(int n, int *length);

int				ft_print_ptr(unsigned long long ptr);
int				ft_putnbr_base_ptr(unsigned long long ptr, int *length);

int				ft_putnbr_u(unsigned int n, int *length);

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_conversion(va_list ptr, char c);
int				ft_putstr(char *str);

#endif
