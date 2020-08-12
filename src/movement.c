#include "wolf3d.h"

int		movement(t_wrld *wd, SDL_KeyCode key) {
	if (key == SDLK_RIGHT)
		wd->prsn->alp -= PI / 45;
	else if (key == SDLK_LEFT)
		wd->prsn->alp += PI / 45;
}