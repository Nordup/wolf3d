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
		 // fish aye fixing
		rcast.dis *= cos(in_two_pi(p->alp - alp));
		// find the wall size
		wrld->wall->size = WALL_SIZE / rcast.dis;
		set_wall_texture(wrld, rcast);
		if (wrld->wall->size >= WIN_H)
			wrld->wall->size = WIN_H - 1;
		wall_draw(img, wrld->wall, i);
		alp += (FOV * RD) / WIN_W;
		i++;
	}
	return 0;
}