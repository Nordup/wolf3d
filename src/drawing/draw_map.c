#include "render.h"

int		fill_square(Uint32 *img, t_pnt a, t_pnt b, Uint32 clr) {
	int		ax = a.x;
	int		ay = a.y;
	int		bx = b.x;
	int		by = b.y;

	while (ay < by) {
		while (ax < bx) {
			img[ay * WIN_W + ax] = clr;
			ax++;
		}
		ax = a.x;
		ay++;
	}

}

int		draw_map(Uint32 *img, t_map *map) {
	int		x;
	int		y;
	Uint32	clr;
	int		w;
	int		h;

	x = 0;
	y = 0;
	w = map->win_map.x;
	h = map->win_map.y;
	//printf("%d\n", map->box[0][0]);
	while (y < map->h) {
		while (x < map->w) {
			if (map->box[y][x] == 0)
				clr = BLACK;
			else
				clr = WHITE;
			// one grid from x*w, y*h to (x+1)*w, (y+1)*h
			fill_square(img, newpnt(x*w, y*h), newpnt(x*w + w, y*h + h), clr);
			x++;
		}
		x = 0;
		y++;
	}
	return 0;
}