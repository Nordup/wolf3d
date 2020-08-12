#include "wolf3d.h"

int		main(void) {
	t_sdl	*sdl;

	// initialize all we need int sdl2
	sdl = init_sdl();
	// main rendering part
	rendering_loop(sdl);
	// clean sdl before quit
	quit_sdl(sdl);
	return 0;
}