#include "render.h"

t_pnt	newpnt(float x, float y) {
	t_pnt	pnt;

	pnt.x = x;
	pnt.y = y;
	return pnt;
}

int		draw_point(Uint32 *img, t_pnt win_map, t_pnt pnt, Uint32 clr) {
	img[(int)(win_map.x * pnt.x) + (int)(win_map.y * pnt.y) * WIN_W] = clr; // short
/*	int		scr_x;
	int		scr_y;

	scr_x = win_map.x * pnt.x;
	scr_y = win_map.y * pnt.y;
	img[scr_x + scr_y * WIN_W] = clr;*/
	return 0;
}