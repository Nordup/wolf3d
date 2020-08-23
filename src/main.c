#include "wolf3d.h"

int		main(void) {
	t_sdl	*sdl;
	t_wrld	*world;

	// initialize all we need
	ft_putendl("Initializing...");
	world = init_world();
	sdl = init_sdl();

	// main rendering part
	ft_putendl("Enjoying the game...");
	game(sdl, world);
	
	// clean all
	ft_putendl("Cleaning...");
	free_world(world);
	quit_sdl(sdl);
	return 0;
}