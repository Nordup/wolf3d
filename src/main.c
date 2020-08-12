#include "wolf3d.h"

int		main(void) {
	t_sdl	*sdl;

	sdl = init_sdl();
	rendering_loop(sdl);
	quit_sdl(sdl);
	return 0;
}