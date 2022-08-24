
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h> //To use variadic functions
#include <string.h>  //to use strings

int     ft_printf(const char *format, ...);
void	ft_putnbr_fd(int n, int *formatLen);
void	ft_unsigned_int(unsigned int u, int *formatLen);
void	ft_putchar_fd(char c, int *formatLen);
void	ft_hex(size_t x, int *formatLen, char selector);
void    ft_string(char *args, int *formatLen);
char	*ft_base_character(char selector, int *formatLen);

#endif
