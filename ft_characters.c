#include "ft_printf.h"

/* prints to the screen with the write function*/
void	ft_putchar_fd(char c, int *formatLen)
{
    write(1, &c, 1);
	(*formatLen)++;
}

void    ft_string(char *args, int *formatLen)
{
    int i;

    i = 0;

    if (!args)
    {
        ft_string("(null)", formatLen);
        //write(1, "(null)", 6);
        (*formatLen) += 6;
        return ;
    }
    while (args[i] != '\0')
    {
        ft_putchar_fd(args[i], formatLen);
        i++;
    }
}
