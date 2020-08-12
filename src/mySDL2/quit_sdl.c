#include "mySDL2.h"

int		quit_sdl(t_sdl *sdl) {
	SDL_DestroyTexture(sdl->tex);
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}