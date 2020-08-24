#include "libft.h"

int		ft_count_atoi(char const *s, int *number)
{
	int		i;
	int		log;
	int		n;

	i = 0;
	n = 0;
	log = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			log = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	*number = n * log;
	return i;
}