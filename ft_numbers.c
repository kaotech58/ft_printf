#include "ft_printf.h"

/*  Converts the int to the correct ascii and sends it to ft_putchar_fd*/
void	ft_putnbr_fd(int n, int *formatLen)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*formatLen) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', formatLen);
		ft_putnbr_fd(n * -1, formatLen);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, formatLen);
		ft_putchar_fd(n % 10 + '0', formatLen);
	}
}

void	ft_unsigned_int(unsigned int u, int *formatLen)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, formatLen);
	ft_putchar_fd(u % 10 + '0', formatLen);
}

char	*ft_base_character(char selector, int *formatLen)
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
		(*formatLen) += 2;
	}
	return (base_character);
}

void	ft_hex(size_t x, int *formatLen, char selector)
{
	char	string[25];
	int	i;
	char	*base_character;

	i = 0;
	base_character = ft_base_character(selector, formatLen);
	if (x == 0)
	{
		ft_putchar_fd('0', formatLen);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_fd(string[i], formatLen);
	}
}
