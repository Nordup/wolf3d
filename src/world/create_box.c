#include "world.h"

int		create_box(t_map *map) {
	int		w = 10;
	int		h = 10;
	int		b[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,1,0,1,0,1},
		{1,0,0,1,0,1,0,1,0,1},
		{1,0,1,1,1,0,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,0,1}
	};
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
}