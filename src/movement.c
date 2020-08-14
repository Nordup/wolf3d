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
		// update step
		update_step(pn);
		// if we don't have wall in the face
		if (ray_casting(m, pn->pnt, pn->alp).dis > STEP) {
			pn->pnt.x += pn->step.x; // move to dx
			pn->pnt.y += pn->step.y; // move to dy
		}
	}
	if (state[SDL_SCANCODE_DOWN]) {
		// update step
		update_step(pn);
		// if we don't have wall in the back
		if (ray_casting(m, pn->pnt, in_two_pi(pn->alp + PI)).dis > STEP) {
			pn->pnt.x -= pn->step.x;
			pn->pnt.y -= pn->step.y;
		}
	}

	return 0;
}