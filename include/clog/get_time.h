#include <time.h>

tm* get_time()
{
    time_t rawtime = time(0);
    struct tm *info = localtime(&rawtime);
    return info;
}
