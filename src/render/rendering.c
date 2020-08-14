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
	int		i = 0;
	float	alp = p->alp - (FOV/2) * RD;

	while (i < WIN_W) {
		// find distance to wall
		t_rcasting rcast = ray_casting(wrld->map, p->pnt, in_two_pi(alp));
		rcast.dis *= cos(in_two_pi(p->alp - alp)); // fish aye fixing
		wall_draw(img, rcast, i);
		alp += WALL_STEP;
		i++;
	}
	return 0;
}