#include <stdarg.h>

#define MAX_ARGS 30

void* get_arg_list(va_list args)
{
	void* arr = malloc(MAX_ARGS * sizeof(*void));
	n = 0
	
	int i = 0;
	void* arg = va_arg(args, void*);

	while(arg != NULL)
	{
		arr[n] = arg;
	}
}
