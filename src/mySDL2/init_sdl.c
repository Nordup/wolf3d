#include "mySDL2.h"

t_sdl*	init_sdl(void)
{
	t_sdl			*sdl;
	Uint32			ren_flags;

	sdl = (t_sdl*)malloc(sizeof(t_sdl));
	sdl->image = (Uint32*)malloc(sizeof(Uint32) * WIN_SIZE);// window size
	ren_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		quit("SDL_Init Error");
	if (!(sdl->win =SDL_CreateWindow("WOLF3D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN)))
		quit("SDL_CreateWindow Error");
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1, ren_flags)))
	{
		SDL_DestroyWindow(sdl->win);
		quit("SDL_CreateRenderer Error");
	}
	if (!(sdl->tex = SDL_CreateTexture(sdl->ren, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIN_W, WIN_H)))
	{
		SDL_DestroyWindow(sdl->win);
		quit("SDL_CreateTexture Error");
	}
	return sdl;
}