#include "wolf3d.h"

int		movement(t_wrld *wd, SDL_Event *e) {
	t_prsn	*pn = wd->prsn;
	t_map	*m = wd->map;

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_RIGHT]) {
		pn->alp += PI / 30;
		if (pn->alp >= PI2)
			pn->alp = 0;
	}
	if (state[SDL_SCANCODE_LEFT]) {
		pn->alp -= PI / 30;
		if (pn->alp <= 0)
			pn->alp = PI2;
	}
	if (state[SDL_SCANCODE_UP]) {
		pn->pnt.x += pn->delta.x; // move to dx
		pn->pnt.y += pn->delta.y; // move to dy
		if (pn->pnt.x < 0)
			pn->pnt.x = m->w;
		if (pn->pnt.x > m->w)
			pn->pnt.x = 0;
		if (pn->pnt.y < 0)
			pn->pnt.y = m->h;
		if (pn->pnt.y > m->h)
			pn->pnt.y = 0;
	}
	if (state[SDL_SCANCODE_DOWN]) {
		pn->pnt.x -= pn->delta.x;
		pn->pnt.y -= pn->delta.y;
		if (pn->pnt.x < 0)
			pn->pnt.x = m->w;
		if (pn->pnt.x > m->w)
			pn->pnt.x = 0;
		if (pn->pnt.y < 0)
			pn->pnt.y = m->h;
		if (pn->pnt.y > m->h)
			pn->pnt.y = 0;
	}

	pn->delta.x = cos(pn->alp) * STEP;
	pn->delta.y = sin(pn->alp) * STEP;
	return 0;
}