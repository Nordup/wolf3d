#include "render.h"

float	dis(t_pnt a, t_pnt b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

t_tcasting	ret(float dis, t_bool hor_ver, int wall_type) {
	t_tcasting	ret;
	ret.dis = dis;
	ret.hor_ver = hor_ver;
	ret.wall_type = wall_type;
	return ret;
}

t_tcasting	horizontal(t_map *map, t_pnt pnt, float alp) {
	t_pnt	A;
	t_pnt	dlta;
	int		wall_type = 0;

	// CHECKING HORIZONTAL INTERSECTIONS
	// in x,y coor system
	if (alp < PI) { // facing up
		A.y = (int)pnt.y + 1;
		dlta.y = 1;
		A.x = pnt.x + (A.y - pnt.y) / tan(alp);
		dlta.x = 1 / tan(alp);
	}
	else {
		A.y = (int)pnt.y - 0.0001;
		dlta.y = -1;
		A.x = pnt.x + (A.y - pnt.y) / tan(alp);
		dlta.x = -1 / tan(alp);
	}

	if (alp == PI) {
		A.y=pnt.y; A.x=-1;
	} else if (alp == 0) {
		A.y=pnt.y; A.x=map->w;
	}

	while (A.y >= 0 && A.y < map->h) {
		if (A.x >= 0 && A.x < map->w)
			if (map->box[(int)A.y][(int)A.x] != 0) {
				wall_type = map->box[(int)A.y][(int)A.x];
				break ;
			}
			else {
				A.y += dlta.y;
				A.x += dlta.x;
			}
		else
			break ;
	}
	return ret(dis(pnt, A), TRUE, wall_type);
}

t_tcasting	vertical(t_map *map, t_pnt pnt, float alp) {
	t_pnt	A;
	t_pnt	dlta;
	int		wall_type = 0;
	
	// CHECKING VERTICAL INTERSECTIONS
	if (alp < PI_2 || alp > PI3_2) { // facing right
		A.x = (int)pnt.x + 1;
		dlta.x = 1;
		A.y = pnt.y + (A.x - pnt.x) * tan(alp);
		dlta.y = tan(alp);
	}
	else {
		A.x = (int)pnt.x - 0.0001;
		dlta.x = -1;
		A.y = pnt.y + (A.x - pnt.x) * tan(alp);
		dlta.y = -tan(alp);
	}

	if (alp == PI_2) {
		A.y=map->h; A.x=pnt.x;
	} else if (alp == PI3_2) {
		A.y=-1; A.x=pnt.x;
	}

	while (A.x >= 0 && A.x < map->w) {
		if (A.y >= 0 && A.y < map->h)
			if (map->box[(int)A.y][(int)A.x] != 0) {
				wall_type = map->box[(int)A.y][(int)A.x];
				break ;
			}
			else {
				A.x += dlta.x;
				A.y += dlta.y;
			}
		else
			break ;
	}
	return ret(dis(pnt, A), FALSE, wall_type);
}

t_tcasting	ray_casting(t_map *map, t_pnt pnt, float alp) {
	t_tcasting hor = horizontal(map, pnt, alp);
	t_tcasting ver = vertical(map, pnt, alp);

	//return less value
	return (hor.dis < ver.dis) ? hor : ver;
}