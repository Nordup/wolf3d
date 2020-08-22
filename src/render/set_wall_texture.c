#include "render.h"

int		set_wall_texture(t_wrld *wrld, t_rcasting rc) {
	Uint32	color[4] = {WHITE, BLACK, RED, GREEN};

	Uint32	clr = color[rc.cardinal_point];
	int		i = 0;
	while (i < wrld->wall->size) {
		wrld->wall->tex[i] = clr;
		i++;
	}
	return 0;
}