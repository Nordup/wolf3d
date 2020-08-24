#include "world.h"
#include "wolf3d.h"

int		create_box(t_map *map) {
	int		w = 10;
	int		h = 10;
	int		b[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,3,0,1},
		{1,0,0,0,0,0,0,4,0,1},
		{1,0,0,2,0,0,0,5,0,1},
		{1,0,0,2,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,1},
		{1,0,0,0,0,0,10,0,0,1},
		{1,0,0,0,0,0,10,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,1}
	};
	/*
	int		b[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,1,0,1,0,1},
		{1,0,0,1,0,1,0,1,0,1},
		{1,0,1,1,1,0,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,0},
		{1,1,1,1,1,1,1,1,1,1}
	};*/
	int		x = 0;
	int		y = 0;

	map->w = w;
	map->h = h;
	map->box = (int**)malloc(sizeof(int*) * h);
	while (y < h) {
		map->box[y] = (int*)malloc(sizeof(int) * w);
		while (x < w) {
			map->box[y][x] = b[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

t_map	*init_map(void) {
	t_map	*map;
	t_pnt	win_map;

	map = (t_map*)malloc(sizeof(t_map));
	create_box(map);
	win_map.x = WIN_W / map->w;
	win_map.y = WIN_H / map->h;
	map->win_map = win_map;
	return (map);
}

t_prsn	*init_person(void) {
	t_prsn	*prsn;

	prsn = (t_prsn*)malloc(sizeof(t_prsn));
	prsn->pnt = newpnt(5,5);
	prsn->alp = PI_2;
	return prsn;
}