#include "render.h"

t_bool	wrong_input(t_pnt pnt) {
	if (pnt.x < 0 || pnt.x >= WIN_W)
		return TRUE;
	if (pnt.y < 0 || pnt.y >= WIN_H)
		return TRUE;
	return FALSE;
}

int		draw_line(Uint32 *img, t_pnt win_map, t_pnt pnt, float alp, float dis, Uint32 clr) {
	// translate to window coordinates
	pnt.x *= win_map.x;
	pnt.y *= win_map.y;
	dis *= sqrt(win_map.x * win_map.x + win_map.y * win_map.y);
	if (wrong_input(pnt))
		return -1;

	// find k and b; y=kx+b
	float	k = tan(alp);
	float	b = pnt.y - k * pnt.x;

	// find delta_x
	int		x2 = cos(alp) * dis + pnt.x;
	int		x1 = pnt.x;
	int		y2;
	int		y1;
	if (x2 < 0)
		x2 = 0;
	else if (x2 >= WIN_W)
		x2 = WIN_W - 1;

	if (x2 >= x1)
		while (x1 < x2) {
			y1 = k * x1 + b;
			if (y1 >= 0 && y1 < WIN_H)
				img[x1 + y1 * WIN_W] = clr;
			x1++;
		}
	else
		while (x1 > x2) {
			y1 = k * x1 + b;
			if (y1 >= 0 && y1 < WIN_H)
				img[x1 + y1 * WIN_W] = clr;
			x1--;
		}

	// find delta_y
	y2 = sin(alp) * dis + pnt.y;
	y1 = pnt.y;
	if (y2 < 0)
		y2 = 0;
	else if (y2 >= WIN_H)
		y2 = WIN_H - 1;

	if (y2 >= y1)
		while (y1 < y2) {
			x1 = (y1 - b) / k;
			if (x1 >= 0 && x1 < WIN_H)
				img[x1 + y1 * WIN_W] = clr;
			y1++;
		}
	else
		while (y1 > y2) {
			x1 = (y1 - b) / k;
			if (x1 >= 0 && x1 < WIN_H)
				img[x1 + y1 * WIN_W] = clr;
			y1--;
		}
	return 0;
}