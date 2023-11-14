#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int write_char(va_list args);
int write_str(va_list args);

#endif /* MAIN_H */
