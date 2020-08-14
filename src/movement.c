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
		if (pn->alp < 0)
			pn->alp = PI2 - PI / 160;
	}
	if (state[SDL_SCANCODE_UP]) {
		pn->delta.x = cos(pn->alp) * STEP;
		pn->delta.y = sin(pn->alp) * STEP;
		// if we don't have wall in the face
		if (ray_casting(m, pn->pnt, pn->alp).dis > 0.1) {
			pn->pnt.x += pn->delta.x; // move to dx
			pn->pnt.y += pn->delta.y; // move to dy
		}
	}
	if (state[SDL_SCANCODE_DOWN]) {
		pn->delta.x = cos(pn->alp) * STEP;
		pn->delta.y = sin(pn->alp) * STEP;
		// if we don't have wall in the back
		if (ray_casting(m, pn->pnt, in_two_pi(pn->alp + PI)).dis > 0.1) {
			pn->pnt.x -= pn->delta.x;
			pn->pnt.y -= pn->delta.y;
		}
	}

	return 0;
}