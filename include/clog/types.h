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

int get_type(const char* format)                           
{
    if(*format == 'd' || is_long(format) || is_short(format) || *format == 'f')
    {
        if(is_long(format) || is_short(format))
        {
            return 2;
        }
        else
        {
            return 1;
        } 
    }                                                                          
    if(*format == 's')                                                         
    {           
        return 0;
    }
    else
    {
        return -1;
    }
}
