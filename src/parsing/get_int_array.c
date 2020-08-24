#include "wolf3d.h"

int		get_rgb(int r, int g, int b) {
	return ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
}

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

int		*get_clr_array(char *line, int size) {
	int		*clr;
	int		*array;
	int		i;

	i = 0;
	array = get_int_array(line, size * 3);
	clr = (int*)malloc(sizeof(int) * size);
	while (i < size) {
		clr[i] = get_rgb(array[i * 3], array[i * 3 + 1], array[i * 3 + 2]);
		i++;
	}
	free(array);
	return clr;	
}