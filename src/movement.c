#include "wolf3d.h"

int		movement(t_wrld *wd, SDL_KeyCode key) {
	t_prsn	*pn;

	pn = wd->prsn;
	if (key == SDLK_RIGHT) {
		pn->alp += PI / 45;
	}
	else if (key == SDLK_LEFT) {
		pn->alp -= PI / 45;
	}
	else if (key == SDLK_UP) {
		pn->pnt.x += pn->delta.x; // move to dx
		pn->pnt.y += pn->delta.y; // move to dy
	}
	else if (key == SDLK_DOWN) {
		pn->pnt.x -= pn->delta.x;
		pn->pnt.y -= pn->delta.y;
	}


	pn->delta.x = cos(pn->alp) * STEP;
	pn->delta.y = sin(pn->alp) * STEP;
}