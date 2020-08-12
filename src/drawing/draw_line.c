#include "render.h"

int		draw_line(Uint32 *img, t_pnt win_map, t_pnt pnt, float alp, float dis, Uint32 clr) {
	float	b = pnt.y - tan(alp) * pnt.x;
	float	k = tan(alp);
	float	dx = cos(alp) * dis;
	float	x = pnt.x;
	float	y;
	while (x < pnt.x + dx) {
		y = k * x + b;
		draw_point(img, win_map, newpnt(x, y), clr);
		x += 1/win_map.x;
	}
	return 0;
}