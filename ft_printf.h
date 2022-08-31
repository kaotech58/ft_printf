/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teiffe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:47:47 by teiffe            #+#    #+#             */
/*   Updated: 2022/08/31 11:47:51 by teiffe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>

void	ft_putnbr_fd(int n, int *format_len);
void	ft_unsigned_int(unsigned int u, int *format_len);
void	ft_putchar_fd(char c, int *format_len);
void	ft_hex(size_t x, int *format_len, char selector);
void	ft_string(char *args, int *format_len);
int		ft_printf(const char *format, ...);
char	*ft_base_character(char selector, int *format_len);

#endif
