#include "render.h"

int			wall_draw(Uint32 *img, float dist, t_bool hor_ver, int wall_type,  int column) {
	int		wall_size = WALL_SIZE / dist;
	int		sky_size = (WIN_H - wall_size) / 2;
	int		y = 0;
	Uint32	clr = WALL_CLR;
	if (hor_ver)
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