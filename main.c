#include "main.h"

int main(void)
{
    int len;

    len = _printf("This is a character: %c\n", 'A');
    _printf("Length: %d\n", len);

    len = _printf("This is a string: %s\n", "Hello, world!");
    _printf("Length: %d\n", len);

    len = _printf("This is a percent sign: %%\n");
    _printf("Length: %d\n", len);

    return (0);
}
