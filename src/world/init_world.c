#include "world.h"
#include "wolf3d.h"

t_wrld	*init_world(void) {
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->tex = init_tex();
	world->map = init_map();
	world->prsn = init_person();
	return world;
}