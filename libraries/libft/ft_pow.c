#include "libft.h"

int     ft_pow(int x, int y)
{
    int     i;
    int     result;

    i = 0;
    result = x;
    while (i < y)
    {
        result *= x;
        i++;
    }
    return result;
}