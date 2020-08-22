#include "world.h"
#include "wolf3d.h"

void	set_wall_size(t_wrld *wrld, float size) {
	if (size >= WIN_H)
		size = WIN_H - 1;
	wrld->wall->size = size;
}

t_wall	*init_wall(void) {
	int		size = WIN_H + 1;
	t_wall *wall = (t_wall*)malloc(sizeof(t_wall));
	wall->tex = (Uint32*)malloc(sizeof(Uint32) * size);
	wall->size = size;
	return wall;
}

t_wrld	*init_world(void) {
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->wall = init_wall();
	world->map = init_map();
	world->prsn = init_person();
	return world;
}