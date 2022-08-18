#include "ft_printf.h"

/*  Converts the int to the correct ascii and sends it to ft_putchar_fd*/
void	ft_putnbr_fd(int n, int *formatLen)
{
	unsigned int	nbr;

	nbr = n;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*formatLen) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', formatLen);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, formatLen);
	}
	ft_putchar_fd((nbr % 10) + '0', formatLen);
}

/*  Converts the unsigned int to the correct ascii and sends it to ft_putchar_fd*/
void	ft_unsigned_int(unsigned int u, int *formatLen)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, formatLen);
	ft_putchar_fd(u % 10 + '0', formatLen);
}

void	ft_pointer(size_t pointer, int *formatLen)
{
	char	string[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*formatLen) += 2;
	if (!pointer)
	{
		ft_putchar_fd('0', formatLen);
		return ;
	}
	while (pointer)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_fd(string[i], formatLen);
	}
}
