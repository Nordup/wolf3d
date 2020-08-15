#include "render.h"

int		wall_draw(Uint32 *img, Uint32 *tex, int wall_size,  int column) {
	int		sky_size = (WIN_H - wall_size) / 2;
	int		y = 0;

	// fill sky
	while (y < sky_size) {
		img[y * WIN_W + column] = BLUE;
		y++;
	}
	// fill wall
	while (y < WIN_H && wall_size > 0) {
		wall_size--;
		img[y * WIN_W + column] = tex[wall_size];
		y++;
	}
	// fill floor
	while (y < WIN_H) {
		img[y * WIN_W + column] = FLOOR;
		y++;
	}
	return 0;
}