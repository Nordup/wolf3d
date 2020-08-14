#include "render.h"

int			wall_draw(Uint32 *img, t_rcasting rcast,  int column) {
	int		wall_size = WALL_SIZE / rcast.dis;
	int		sky_size = (WIN_H - wall_size) / 2;
	int		y = 0;
	Uint32	clr = WALL_CLR;
	if (rcast.hor_ver)
		clr -= 0x111111;

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