#include "wolf3d.h"

int		main(int argc, char**argv)
{
	t_sdl	*sdl;
	t_wrld	*world;

	// initialize all we need
	ft_putendl("Initializing...");
	sdl = init_sdl();
	world = init_world(argv[1]);

	// main rendering part
	ft_putendl("Enjoying the game...");
	game(sdl, world);
	
	// clean all
	ft_putendl("Cleaning...");
	free_world(world);
	quit_sdl(sdl);
	return 0;
}