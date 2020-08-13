#ifndef DISPLAY_H
# define DISPLAY_H

#ifdef __APPLE__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

# define WIN_W 1200
# define WIN_H 900
# define WIN_SIZE WIN_H * WIN_W


typedef struct	s_sdl
{
	SDL_Renderer	*ren;
	SDL_Window		*win;
	SDL_Surface		*surface;
	SDL_Texture		*tex;
	Uint32			*image;
}				t_sdl;

int		quit(char *s);
int		quit_sdl(t_sdl *sdl);
t_sdl*	init_sdl(void);

# endif