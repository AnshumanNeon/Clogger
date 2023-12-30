#include <stdarg.h>
#include <stdio.h>
#include "./checkType.h"

void print(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	
	while(*format)
	{
		if(*format == '{')
		{
			format++;
			if(*format == '}')
			{
				printf("%s", va_arg(args, char*));
			}
            if(*format == ':')
            {
                format++;
                print_by_type(args, format);
            }
		}
		else
		{
			putchar(*format);
		}
		format++;
	}

	va_end(args);
}

void print_by_type(va_list args, const char* format)
{
    if(*format == 'd' || is_long(format) || is_short(format) || *format == 'f')
    {
        format++;
        if(*format == '}')
        {
            print_num(args);
        }
    }
    if(*format == 's')
    {
        format++;
        if(*format == '}')
        {
            print_char(args);
        }
    }
}

int is_long(const char* format)
{
    return ( *format = 'l' && *(format + 1) == 'd' );
}

int is_short(const char* format)
{
    return ( *format == 'h' && *(format + 1) == 'i' );
}

void print_char(va_list args)
{
    printf("%s", va_args(args, char*));
}

void print_num(va_list args)
{
    printf("%ld", va_args(args, long));
}
