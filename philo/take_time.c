#include "philo_struct.h"

size_t taketime()
{
    struct timeval str;
    size_t  rest;
    gettimeofday(&str, NULL);
    rest = (str.tv_sec * 1000) + (str.tv_usec / 1000);
    return (rest);
}
