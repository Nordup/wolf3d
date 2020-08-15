#include "world.h"
#include "wolf3d.h"

t_tex	*init_tex(void) {
	t_tex *tex = (t_tex*)malloc(sizeof(t_tex));
	tex->clmn = (Uint32*)malloc(sizeof(Uint32) * (WIN_H + 1));
	return tex;
}