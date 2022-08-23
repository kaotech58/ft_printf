/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teiffe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:26 by teiffe            #+#    #+#             */
/*   Updated: 2022/08/23 12:21:57 by teiffe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h> //To use variadic functions
# include <string.h>  //to use strings

void	ft_putnbr_fd(int n, int *format_len);
void	ft_unsigned_int(unsigned int u, int *format_len);
void	ft_putchar_fd(char c, int *format_len);
void	ft_hex(unsigned int x, int *format_len, char selector);
void	ft_string(char *args, int *format_len);
char	ft_base_character(char selector, int *format_len);
int		ft_printf(const char *format, ...);

#endif
