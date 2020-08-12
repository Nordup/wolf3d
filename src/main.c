#include "wolf3d.h"

int		main(void) {
	t_sdl	*sdl;
	Uint32	*image;

	sdl = init_sdl();
	image = (Uint32*)malloc(sizeof(Uint32) * WIN_SIZE);// window size
	quit_sdl(sdl);
	return 0;
}