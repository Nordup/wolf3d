#include "render.h"

int		rendering(Uint32 *img, t_wrld *wrld) {
	t_prsn	*p = wrld->prsn;
	t_map	*m = wrld->map;
	float	alp = p->alp;
	float	dis = 0.5;

	draw_map(img, m);
	// raycasting
	alp -= (FOV/2) * R_IN_D;
	float	alp2 = alp + FOV * R_IN_D;
	while (alp < alp2) {
		// find distance to wall
		dis = ray_casting(m, p->pnt, alp);
		draw_line(img, m->win_map, p->pnt, alp, dis, GREEN);
		alp += R_IN_D;
	}
	return 0;
}