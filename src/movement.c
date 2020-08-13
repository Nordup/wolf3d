#include "wolf3d.h"

int		movement(t_wrld *wd, SDL_Event *e) {
	t_prsn	*pn;

	pn = wd->prsn;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_RIGHT]) {
		pn->alp += PI / 30;
	}
	if (state[SDL_SCANCODE_LEFT]) {
		pn->alp -= PI / 30;
	}
	if (state[SDL_SCANCODE_UP]) {
		pn->pnt.x += pn->delta.x; // move to dx
		pn->pnt.y += pn->delta.y; // move to dy
	}
	if (state[SDL_SCANCODE_DOWN]) {
		pn->pnt.x -= pn->delta.x;
		pn->pnt.y -= pn->delta.y;
	}
	SDL_PumpEvents();

	pn->delta.x = cos(pn->alp) * STEP;
	pn->delta.y = sin(pn->alp) * STEP;
	return 0;
}