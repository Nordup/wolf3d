#include "wolf3d.h"

int		main(void) {
	t_sdl	*sdl;
	t_wrld	*world;

	// initialize all we need
	ft_putendl("Initializing...");
	//sdl = init_sdl();
	world = init_world();

	// main rendering part
	ft_putendl("Start Game");
	//game(sdl, world);
	
	// clean all
	ft_putendl("Cleaning...");
	free_world(world);
	quit_sdl(sdl);
	return 0;
}