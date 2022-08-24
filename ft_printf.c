#include "ft_printf.h"

/*  Main function only for testing*/
/*int main (void)
{
    int test1 = 42;

    int *ptr = &test1;

    unsigned int    xs = 42424242;

    char string1[12] = "hello there";
    char string2;
    char f = 'F';
    char t = 't';

    printf("Not: %d\n", -4);
    ft_printf("Me!: %d", -4);
    printf("\n");
    printf("Not: %i\n", 2);
    ft_printf("Me!: %i", 2);
    printf("\n");
    printf("Not: %u\n", 10);
    ft_printf("Me!: %u", 10);
    printf("\n");
    printf("Not: %p\n", &ptr);
    ft_printf("Me!: %p", &ptr);
    printf("\n");
    printf("Not: %d\n", *ptr);
    ft_printf("Me!: %d", *ptr);
    printf("\n");
    printf("Not: %u\n", xs);
    ft_printf("Me!: %u", xs);
    printf("\n");
    printf("Not: %x\n", xs);
    ft_printf("Me!: %x", xs);
    printf("\n");
    printf("Not: %X\n", xs);
    ft_printf("Me!: %X", xs);
    printf("\n");
    printf("Not: %s\n", string1);
    ft_printf("Me!: %s", string1);
    printf("\n");
    printf("Not: %s\n", string2);
    ft_printf("Me!: %s", string2);
    printf("\n");
    printf("Not: %c\n", f);
    ft_printf("Me!: %c", f);
    printf("\n");
    printf("Not: %c\n", t);
    ft_printf("Me!: %c", t);
    printf("\n");
    printf("Not: %%\n");
    ft_printf("Me!: %%");
    printf("\n");

    return (0);
}*/

/*  when ft_printf gets to "conversion(format[i], &args, &formatLen, &i);" it then moves here to see what to
    do with the next character.*/
static void conversion(char value, va_list *args, int *len, int *i)
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

/*  The variadic function that makes the magic happen, denoted by the use of the elipses ...
    create an int formatLen that gets initiated with the value of format string length so we
    know how long it is
    create an int i to use as a counter to iterate through the format pointer
    create the va_list called args allows us to create a variable list that we can then call one at a time
    create our entries in the list, first we tell it what list to access, in this case it is called args
    and then we give it the last argument before the elipses in the ft_printf function and that's format
    Now we start the while loop and set the condition to keep going so long as the value of format
    at the index is not equal to a null terminator
    If it finds a % it then jumps to the conversion function to see what to do next
    If it doesn't find a conversion to make it then uses the ft_putchar_fd to print the character to screen
    Use va_end to end your access to the argument list
    Function returns the value of formatLen*/
int ft_printf(const char *format, ...)
{
    int formatLen;
    int i;

    formatLen = 0;
    i = 0;

    va_list args;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            conversion(format[i], &args, &formatLen, &i);
            i++;
        }
        else
        {
            ft_putchar_fd((char)format[i], &formatLen);
            i++;
        }
    }
    va_end(args);
    return (formatLen);
}
