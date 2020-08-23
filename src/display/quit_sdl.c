#include "display.h"
#include "libft.h"

int		quit_sdl(t_sdl *sdl) {
	if (sdl) {
		if (sdl->image)
			free(sdl->image);
		SDL_DestroyTexture(sdl->tex);
		SDL_DestroyRenderer(sdl->ren);
		SDL_DestroyWindow(sdl->win);
		free(sdl);
	}
	SDL_Quit();
}

/**
 * printf("%s: %s\n", s, SDL_GetError());
 * */
int		quit(char *s) {
	ft_putstr(s);
	ft_putstr(": ");
	ft_putstr(SDL_GetError());
	ft_putendl("");
	SDL_Quit();
	exit(1);
}