#include "wolf3d.h"

int		rendering_loop(t_sdl *sdl) {
	SDL_Event	e;
	t_bool		quit;

	quit = FALSE;
	while (!quit)
	{
		// render new image
		raycasting(sdl->image);
		// update window picture
		SDL_UpdateTexture(sdl->tex, NULL, sdl->image, sizeof(Uint32) * WIN_W);
		SDL_RenderClear(sdl->ren);
		SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL);
		SDL_RenderPresent(sdl->ren);

		// get event
		while(SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = TRUE;
		}
	}
	return 0;
}