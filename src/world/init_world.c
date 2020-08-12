#include "world.h"

t_map	*init_map(void) {
	t_map	*map;
	t_pnt	win_map;

	map = (t_map*)malloc(sizeof(t_map));
	create_box(map);
	win_map.x = WIN_W / map->w;
	win_map.y = WIN_H / map->h;
	map->win_map = win_map;
	return map;
}

t_prsn	*init_person(void) {
	t_prsn	*prsn;

	prsn = (t_prsn*)malloc(sizeof(t_prsn));
	prsn->pnt = newpnt(3.5, 3.5);
	prsn->alp = PI / 4;

	prsn->alp = -prsn->alp;
	prsn->delta.x = cos(prsn->alp) * STEP;
	prsn->delta.y = sin(prsn->alp) * STEP;
	return prsn;
}

t_wrld	*init_world(void) {
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->map = init_map();
	world->prsn = init_person();
	return world;
}