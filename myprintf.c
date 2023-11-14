#include "main.h"


/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++; // Move to the character after '%'

            // Handle conversion specifiers
            switch (*format)
            {
            case 'c':
                count += write_char(args);
                break;
            case 's':
                count += write_str(args);
                break;
            case '%':
                write(1, "%", 1);
                count++;
                break;
            default:
                write(1, "%", 1);
                write(1, format, 1);
                count += 2;
            }
        }

        format++;
    }

    va_end(args);

    return count;
}

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
