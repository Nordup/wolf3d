#include "render.h"

t_wall_type	*find_wall_type(t_wall_type *wtype, int type) {
	if (wtype)
		while (1) {
			if (wtype->type = type)
				return wtype;
			if (wtype->next != NULL)
				wtype = wtype->next;
			else
				break;
		}
	return 	NULL;
}

t_texture	*cardinal_tex(t_wall_type *wtype, int c_point) {
	if (c_point == North)
		return wtype->north;
	else if (c_point == South)
		return wtype->south;
	else if (c_point == East)
		return wtype->east;
	else
		return wtype->west;
}

int		get_width(t_rcasting rc) {
	return 0;
}

int		get_color(t_texture *tex, int w, int i, int size) {
	return tex->clr[w][i];
}

int		set_wall_texture(t_wrld *wrld, t_rcasting rc) {
	int		type = wrld->map->box[(int)rc.cast_pnt.y][(int)rc.cast_pnt.x];
	t_wall_type	*wtype = find_wall_type(wrld->type, type);
	t_texture	*tex = cardinal_tex(wtype, rc.cardinal_point);
	int		w = get_width(rc);

	int		i = 0;
	if (tex == NULL)
		while (i < wrld->wall->size) {
			wrld->wall->tex[i] = BLACK;
			i++;
		}
	else
		while (i < wrld->wall->size) {
			wrld->wall->tex[i] = get_color(tex, w, i, wrld->wall->size);
			i++;
		}
	return 0;
}