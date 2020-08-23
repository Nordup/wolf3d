#include "wolf3d.h"

int		main(int argc, char**argv)
{
	t_sdl	*sdl;
	t_wrld	*world;
	int		**map;

	if (argc != 2)
		game_over(1);
	map = read_map(argv[1]);
	printf("%d %d \n", map[0][0], map[0][1]);
	int i = 1;
	while (i < map[0][0])
	{
		int j = 0;
		while (j < map[0][1])
		{
			printf("%d ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
//	if (!map)
//		printf("map is NULL");
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