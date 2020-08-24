#include "wolf3d.h"

int		movement(t_wrld *world, SDL_Event *e) {
	t_prsn	*pn = world->prsn;
	t_map	*m = world->map;

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_RIGHT]) {
		pn->alp += PI / 70;
		if (pn->alp >= PI2)
			pn->alp = 0;
	}
	if (state[SDL_SCANCODE_LEFT]) {
		pn->alp -= PI / 70;
		if (pn->alp < 0)
			pn->alp = PI2 - RD;
	}
	if (state[SDL_SCANCODE_UP]) {
		// update step
		update_step(pn);
		// if we don't have wall in the face
		if (ray_casting(m, pn->pnt, pn->alp).dis > STEP) {
			
			// move forward
			pn->pnt.x += pn->step.x;
			pn->pnt.y += pn->step.y;
		}
	}
	if (state[SDL_SCANCODE_DOWN]) {
		// update step
		update_step(pn);
		// if we don't have wall in the back
		if (ray_casting(m, pn->pnt, in_two_pi(pn->alp + PI)).dis > STEP) {

			// move back
			pn->pnt.x -= pn->step.x;
			pn->pnt.y -= pn->step.y;
		}
	}

	return 0;
}