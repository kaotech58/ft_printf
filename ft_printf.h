#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h> //To use the write function
#include <stdarg.h> //To use variadic functions
#include <string.h>  //To use strings

int     ft_printf(const char *format, ...);
void	ft_putnbr_fd(int n, int *formatLen);
void	ft_unsigned_int(unsigned int u, int *formatLen);
void	ft_putchar_fd(char c, int *formatLen);
void	ft_hex(unsigned int x, int *formatLen, char selector);

#endif
