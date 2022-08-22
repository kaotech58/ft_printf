#include "ft_printf.h"

/*  Converts the int to the correct ascii and sends it to ft_putchar_fd*/
void	ft_putnbr_fd(int n, int *formatLen)
{
	unsigned int	nbr;

	nbr = n;

	if (nbr == -2147483648)
	{
	    ft_string("-2147483648", formatLen);
		//write(1, "-2147483648", 11);
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

void	ft_hex(unsigned int x, int *formatLen, char selector)
{
	char	string[25];
    int		i;
	char	*base_character;

	if (selector == 'X')
		base_character = "0123456789ABCDEF";
	else if (selector == 'x')
		base_character = "0123456789abcdef";
    else
    {
        base_character = "0123456789abcdef";
        ft_string("0x", formatLen);
        //write(1, "0x", 2);
        (*formatLen) += 2;
    }
	i = 0;
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
		ft_putchar_fd(string[i], formatLen);
}
