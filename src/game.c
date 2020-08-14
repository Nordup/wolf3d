#include "wolf3d.h"

int		game(t_sdl *sdl, t_wrld *world) {
	SDL_Event	e;
	t_bool		quit;

	quit = FALSE;
	while (!quit)
	{
		// render new image
		rendering(sdl->image, world);
		// update window picture
		SDL_UpdateTexture(sdl->tex, NULL, sdl->image, sizeof(Uint32) * WIN_W);
		SDL_RenderClear(sdl->ren);
		SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL);
		SDL_RenderPresent(sdl->ren); // put to window

		// get event
		while(SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) // red button
				quit = TRUE;
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) // Esc
 				   quit = TRUE;
			else
				movement(world, &e);
			//printf("%d\n", e.type);
		}
	}
	return 0;
}