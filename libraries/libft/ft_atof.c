#include "libft.h"

double    ft_atof(char const *s)
{
    int     i_w;
    int     i_f;
    int     whole;
    int     fract;

    i_f = 0;
    fract = 0;
    i_w = ft_count_atoi(s, &whole);
    if (s[i_w] == '.')
    {
        i_f = ft_count_atoi(s + i_w + 1, &fract);
    }
    return whole + (double)fract / ft_pow(10, i_f - 1);
}
