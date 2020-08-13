#include "render.h"

int		wall_draw(Uint32 *img, float dist, int column, Uint32 clr) {
	int		wall_size = WALL_SIZE / dist;
	int		sky_size = (WIN_H - wall_size) / 2;
	int		y = 0;

	while (y < sky_size) {
		img[y * WIN_W + column] = BLUE;
		y++;
	}
	while (y < WIN_H) {
		wall_size--;
		img[y * WIN_W + column] = clr;
		if (wall_size <= 0)
			clr = FLOOR;
		y++;
	}
	return 0;
}