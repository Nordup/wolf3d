#include "wolf3d.h"

int		main(int argc, char**argv)
{
	t_sdl	*sdl;
	t_wrld	*world;
	int		fd;

	if (argc != 2)
		game_over(1);
//	if (!ft_strequ(ft_strstr(argv[1], ".fdf"), ".fdf"))
//		game_over(5);
	if (!(fd = ft_open_read(argv[1])))
		game_over(2);
	close(fd);

	// initialize all we need
	ft_putendl("Initializing...");
	sdl = init_sdl();
	world = init_world();

	// main rendering part
	ft_putendl("Start Game");
	game(sdl, world);
	
	// clean all
	ft_putendl("Cleaning...");
	free_world(world);
	quit_sdl(sdl);
	return 0;
}