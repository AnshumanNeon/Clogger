#include <stdarg.h>
#include <stdio.h>

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
		}
		else
		{
			putchar(*format);
		}
		format++;
	}

	va_end(args);
}
