#include "world.h"

int		create_box(t_map *map) {
	int		w = 8;
	int		h = 8;
	int		b[8][8] = {
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1}
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