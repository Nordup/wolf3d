#include "render.h"

int		rendering(Uint32 *img, t_wrld *wrld) {
	t_prsn	*p = wrld->prsn;
	t_map	*m = wrld->map;

	draw_map(img, m);
	draw_point(img, m->win_map, p->pnt, RED);
	draw_line(img, m->win_map, p->pnt, p->alp, 0.3, GREEN);
	return 0;
}