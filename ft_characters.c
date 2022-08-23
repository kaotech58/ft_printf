/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teiffe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:35:09 by teiffe            #+#    #+#             */
/*   Updated: 2022/08/23 11:37:49 by teiffe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int *format_len)
{
	write(1, &c, 1);
	(*format_len)++;
}

void	ft_string(char *args, int *format_len)
{
	int	i;

	i = 0;
	if (!args)
	{
		ft_string("(null)", format_len);
		(*format_len) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchar_fd(args[i], format_len);
		i++;
	}
}
