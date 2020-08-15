#include "render.h"

int		set_wall_texture(t_wrld *wrld, t_rcasting rc, int size) {
	Uint32	color[4] = {WHITE, BLACK, RED, GREEN};

	Uint32	clr = color[rc.cardinal_point];
	int		i = 0;
	while (i < size && i < wrld->tex->clmn_size) {
		wrld->tex->clmn[i] = clr;
		i++;
	}
	return 0;
}