#include "ft_printf.h"

/* prints to the screen with the write function*/
void	ft_putchar_fd(char c, int *formatLen)
{
    write(1, &c, 1);
	(*formatLen)++;
}
