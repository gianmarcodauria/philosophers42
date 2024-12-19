#include "philo_struct.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
    int res;
    int sign;

    sign = 1;
    res = 0;
    while ((*str >= '\t' && *str <= '\r') || *str == ' ')
        ++str;
    while (ft_isdigit(*str))
    {
        res = res * 10;
        res += (*str++ - '0');
    }
    return (sign * res);
}

int atoi_for_check(const char *str)
{
    int res;

    res = 0;
    while ((*str >= '\t' && *str <= '\r') || *str == ' ')
        ++str;
    if (*str == '+' || *str == '-')
    {
        if (*(str++) == '-')
        {
            write(1, "ERROR number is negative\n", 25);
            return (1);
        }
    }
    while (ft_isdigit(*str))
    {
        res = res * 10;
        res += (*str++ - '0');
    }
    return (0);
}

int checks(int argc, char **argv)
{
    if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
	{
		printf("ERROR nphilo is wrong");
		return (1);
	}
	else if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0)
	{
		printf("ERROR time is wrong");
		return (1);
	}
	else if (argc == 6)
	{
        if (ft_atoi(argv[5]) <= 0)
		    return (printf("ERROR wrong eat counter"), 1);
	}
    
	return (0);
}
