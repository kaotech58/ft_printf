#include "ft_printf.h"

/*  Main function only for testing*/
int main (void)
{
    char    *ptr = "something";
    char    *ptr2 = "stuff";
    ft_printf("%d%d%u%d%d%p%p", -4, 2, 10, -3, -2147483648, ptr, ptr2);
    printf("\n");
    ft_printf("%d", -4);
    printf("\n");
    ft_printf("%d", 2);
    printf("\n");
    ft_printf("%u", 10);
    printf("\n");
    ft_printf("%d", -3);
    printf("\n");
    ft_printf("%d", -2147483648);
    printf("\n");
    ft_printf("%p", ptr);
    printf("\n");
    ft_printf("%p", ptr2);
    printf("\n");
    return (0);
}

/*  when ft_printf gets to "conversion(format[i], &args, &formatLen, &i);" it then moves here to see what to
    do with the next character.*/
static void conversion(char value, va_list *args, int *len, int *i)
{
    if (value == 'd' || value == 'i')
            ft_putnbr_fd(va_arg(*args, int), len);
        else if (value == 'u')
            ft_unsigned_int(va_arg(*args, unsigned int), len);
        else if (value == 'p')
            ft_pointer(va_arg(*args, size_t), len);
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

    formatLen = strlen(format);
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
//        else if (format[i] == ' ')
//            i++;
//            i++;
        else
        {
            ft_putchar_fd((char)format[i], &formatLen);
            i++;
        }
    }
    va_end(args);
    return (formatLen);
}
