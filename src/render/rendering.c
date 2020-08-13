#include "render.h"

float	in_two_pi(float alp) {
	if (alp > PI2)
		alp = alp - PI2;
	else if (alp < 0)
		alp = alp + PI2;
	return alp;
}

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
		dis = ray_casting(m, p->pnt, in_two_pi(alp));
		draw_line(img, m->win_map, p->pnt, alp, dis, GREEN);
		alp += R_IN_D;
	}
	return 0;
}