#include "world.h"
#include "wolf3d.h"

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
	prsn->pnt = newpnt(4, 6);
	prsn->alp = PI_2;
	return prsn;
}

t_wrld	*init_world(void) {
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->map = init_map();
	world->prsn = init_person();
	return world;
}