/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teiffe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:36:10 by teiffe            #+#    #+#             */
/*   Updated: 2022/08/31 11:36:16 by teiffe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int *format_len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*format_len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', format_len);
		ft_putnbr_fd(n * -1, format_len);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, format_len);
		ft_putchar_fd(n % 10 + '0', format_len);
	}
}

void	ft_unsigned_int(unsigned int u, int *format_len)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, format_len);
	ft_putchar_fd(u % 10 + '0', format_len);
}

char	*ft_base_character(char selector, int *format_len)
{
	char	*base_character;

	if (selector == 'X')
		base_character = "0123456789ABCDEF";
	else if (selector == 'x')
		base_character = "0123456789abcdef";
	else
	{
		base_character = "0123456789abcdef";
		write(1, "0x", 2);
		(*format_len) += 2;
	}
	return (base_character);
}

void	ft_hex(size_t x, int *format_len, char selector)
{
	char	string[25];
	int		i;
	char	*base_character;

	i = 0;
	base_character = ft_base_character(selector, format_len);
	if (!x)
	{
		ft_putchar_fd('0', format_len);
		return ;
	}
	while (x)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_fd(string[i], format_len);
	}
}
