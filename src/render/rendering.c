#include "render.h"

int		rendering(Uint32 *img, t_wrld *wrld) {
	t_prsn	*p = wrld->prsn;
	t_map	*m = wrld->map;

	draw_map(img, m);

	// find distance to wall
	float dis = ray_casting(m, p->pnt, p->alp);
	draw_line(img, m->win_map, p->pnt, p->alp, dis, GREEN);
	return 0;
}