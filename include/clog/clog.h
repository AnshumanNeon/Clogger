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
        int type = get_type(format);
      	format++;
      	if(type > 1)
      	{
      		format++;
      	}
      	if(*format == '}')
      	{
      		if(type > 0)
      		{
      			printf("%ld", va_arg(args, long));
      		}
      		else
      		{
      			printf("%s", va_arg(args, char*));
      		}
      	}
      	else
      	{
      		printf("ERROR! please close the brackets immediately after specifying the type.");
      	}
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
