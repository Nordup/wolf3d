#include "world.h"

t_map	*init_map(void) {
	t_map	*map;
	int		ibox[6][9] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	map = (t_map*)malloc(sizeof(t_map));
	map->w = 9;
	map->h = 6;
	map->box = ibox;
	return map;
}

t_prsn	*init_person(void) {
	t_prsn	*prsn;

	prsn = (t_prsn*)malloc(sizeof(t_prsn));
	prsn->px = 3.5;
	prsn->px = 3.5;
	prsn->dir = PI / 4;
	return prsn;
}

t_wrld	*init_world(void) {
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->map = init_map();
	world->prsn = init_person();
	return world;
}