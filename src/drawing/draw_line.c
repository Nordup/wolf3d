#include "render.h"

int		draw_line(Uint32 *img, t_pnt win_map, t_pnt pnt, float alp, float dis, Uint32 clr) {
	float	k = tan(alp);
	float	b = pnt.y - k * pnt.x;
	float	delta = cos(alp) * dis;

	float	x = pnt.x;
	float	y;
	float	plus;

	if (delta >= 0)
		while (x < pnt.x + delta) {
			y = k * x + b;
			draw_point(img, win_map, newpnt(x, y), clr);
			x += 1/win_map.x;
		}
	else
		while (x > pnt.x + delta) {
			y = k * x + b;
			draw_point(img, win_map, newpnt(x, y), clr);
			x -= 1/win_map.x;
		}

	delta = sin(alp) * dis;
	y = pnt.y;

	if (delta >= 0)
		while (y < pnt.y + delta) {
			x = (y - b) / k;
			draw_point(img, win_map, newpnt(x, y), clr);
			y += 1/win_map.y;
		}
	else
		while (y > pnt.y + delta) {
			x = (y - b) / k;
			draw_point(img, win_map, newpnt(x, y), clr);
			y -= 1/win_map.y;
		}
	return 0;
}