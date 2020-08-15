#include "world.h"
#include "wolf3d.h"

t_tex	*init_tex(void) {
	int		size = WIN_H + 1;
	t_tex *tex = (t_tex*)malloc(sizeof(t_tex));
	tex->clmn = (Uint32*)malloc(sizeof(Uint32) * size);
	tex->clmn_size = size;
	return tex;
}