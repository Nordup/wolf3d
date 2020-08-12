#include "raycasting.h"

int		raycasting(Uint32 *img) {
	static Uint32	color = 0;
	int				i;

	i = 0;
	color++;
	while (i < WIN_SIZE) {
		img[i] = color;
		i++;
	}
}