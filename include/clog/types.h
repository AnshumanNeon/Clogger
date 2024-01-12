#include <stdarg.h>
#include <stdio.h>
                                                                               
int is_long(const char* format)                                                
{                                                                              
    return ( *format == 'l' && *(format + 1) == 'd' );                          
}                                                                              
                                                                               
int is_short(const char* format)                                               
{                                                                              
    return ( *format == 'h' && *(format + 1) == 'i' );                         
}                                                                              

void print_by_type(va_list args, const char* format)                           
{                                                                              
    if(*format == 'd' || is_long(format) || is_short(format) || *format == 'f')
    {                                                                          
        format++;                                                              
        if(*format == '}')                                                     
        {                                                                      
            printf("%ld", va_arg(args, long));                                                   
        }                                                                      
    }                                                                          
    if(*format == 's')                                                         
    {                                                                          
        format++;                                                              
        if(*format == '}')                                                     
        {
            printf("%s", va_arg(args, char*));                                                  
        }                                                                      
    }
}                                                                              
