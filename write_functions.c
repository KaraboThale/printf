#include "main.h"

/**
 * write_char - Write a character to stdout
 * @args: va_list containing the character to be printed
 *
 * Return: Number of characters printed
 */
int write_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    return 1;
}

/**
 * write_str - Write a string to stdout
 * @args: va_list containing the string to be printed
 *
 * Return: Number of characters printed
 */
int write_str(va_list args)
{
    char *str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";

    int len = 0;
    while (str[len])
    {
        write(1, &str[len], 1);
        len++;
    }

    return len;
}
