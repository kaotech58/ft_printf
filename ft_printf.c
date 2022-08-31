/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teiffe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:46:47 by teiffe            #+#    #+#             */
/*   Updated: 2022/08/31 11:46:52 by teiffe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conversion(char value, va_list *args, int *len, int *i)
{
	if (value == 'd' || value == 'i')
		ft_putnbr_fd(va_arg(*args, int), len);
	else if (value == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (value == 'p')
		ft_hex(va_arg(*args, size_t), len, 'p');
	else if (value == 'x')
		ft_hex(va_arg(*args, unsigned int), len, 'x');
	else if (value == 'X')
		ft_hex(va_arg(*args, unsigned int), len, 'X');
	else if (value == 's')
		ft_string(va_arg(*args, char *), len);
	else if (value == 'c')
		ft_putchar_fd(va_arg(*args, int), len);
	else if (value == '%')
		ft_putchar_fd('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	int		format_len;
	int		i;
	va_list	args;

	format_len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			conversion(format[i], &args, &format_len, &i);
			i++;
		}
		else
		{
			ft_putchar_fd((char)format[i], &format_len);
			i++;
		}
	}
	va_end(args);
	return (format_len);
}
