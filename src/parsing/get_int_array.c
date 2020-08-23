#include "wolf3d.h"

int		*get_int_array(char *line, int size) {
	int		*array;
	int		number;
	int		i;
	int		n;

	i = 0;
	n = 0;
	number = 0;
	array = (int*)malloc(sizeof(int) * size);
	while (n < size) {
		i += ft_count_atoi(line + i, &number);
		array[n] = number;
		n++;
	}
	return array;
}