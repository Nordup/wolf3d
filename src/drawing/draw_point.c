#include "render.h"

t_pnt	newpnt(float x, float y) {
	t_pnt	pnt;

	pnt.x = x;
	pnt.y = y;
	return pnt;
}

int		draw_point(Uint32 *img, t_pnt win_map, t_pnt pnt, Uint32 clr) {
	int		x = win_map.x * pnt.x;
	int		y = win_map.y * pnt.y;

	if (x < 0 || x >= WIN_W)
		return -1;
	if (y < 0 || y >= WIN_H)
		return -1;
	img[x + y * WIN_W] = clr; // short
	return 0;
}