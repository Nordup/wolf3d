#include "wolf3d.h"

int		check_world(t_wrld *world) {
	if (world->map == NULL)
		return 1;
	return 0;
}

int		main(void)
{
	t_sdl	*sdl;
	t_wrld	*world;

	// initialize all we need
	ft_putendl("Initializing...");
	sdl = init_sdl();
	world = init_world();
	if (check_world(world) != 0)
		return -1;

	// main rendering part
	ft_putendl("Enjoying the game...");
	game(sdl, world);
	
	// clean all
	ft_putendl("Cleaning...");
	free_world(world);
	quit_sdl(sdl);
	return 0;
}