#include "render.h"

int		rendering(Uint32 *img, t_wrld *wrld) {
	static Uint32	color = 0;
	int				i;

	i = 0;
	color++;
	while (i < WIN_SIZE) {
		img[i] = color;
		i++;
	}
}