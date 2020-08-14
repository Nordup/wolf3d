#include "render.h"

int		wall_draw(Uint32 *img, t_rcasting rcast,  int column) {
	int		wall_size = WALL_SIZE / rcast.dis;
	int		sky_size = (WIN_H - wall_size) / 2;
	int		y = 0;
	// define WALL_CLR
	Uint32	clr = WALL_CLR;
	if (rcast.hor_ver)
		clr -= 0x111111;

	// fill sky
	while (y < sky_size) {
		img[y * WIN_W + column] = BLUE;
		y++;
	}
	// fill wall
	while (y < WIN_H && wall_size > 0) {
		img[y * WIN_W + column] = clr;
		wall_size--;
		y++;
	}
	// fill floor
	while (y < WIN_H) {
		img[y * WIN_W + column] = FLOOR;
		y++;
	}
	return 0;
}