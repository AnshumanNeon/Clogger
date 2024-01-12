#include "./types.h" 

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
    printf("\n");
	va_end(args);
}
