#include "render.h"

/** 1 - right; 0 - left
 * */
int		right_or_left(float alp) {
	if (alp < PI_2 || alp > PI3_2)
		return 1;
	else
		return 0;
}

float	ray_casting(t_map *map, t_pnt pnt, float alp) {
	float	hor;
	float	ver;
	t_pnt	A;
	t_pnt	dlta;

	// CHECKING HORIZONTAL INTERSECTIONS
	// in x,y coor system
	if (alp < PI && alp > 0) { // facing up
		A.y = (int)pnt.y + 1;
		dlta.y = 1;
		A.x = pnt.x + (A.y - pnt.y) / tan(alp);
		dlta.x = 1 / tan(alp);
	}
	else if (alp > PI && alp < PI2) {
		A.y = (int)pnt.y - 0.00001;
		dlta.y = -1;
		A.x = pnt.x + (pnt.y - A.y) / tan(alp);
		dlta.x = 1 / tan(alp);
	} // good

	while (A.y >= 0 && A.y < map->h) {
		if (A.x >= 0 && A.x < map->w)
			if (map->box[(int)A.y][(int)A.x] == 1) // if box
				break ;
			else {
				A.y += dlta.y;
				A.x += dlta.x;
			}
		else
			break ;
	}
	hor = sqrt(pow(pnt.x - A.x, 2) + pow(pnt.y - A.y, 2));
	
	// CHECKING VERTICAL INTERSECTIONS
	if ((alp < PI_2 && alp > 0) || (alp > PI3_2 && alp < PI2)) { // facing right
		A.x = (int)pnt.x + 1;
		dlta.x = 1;
		A.y = pnt.y + (A.x - pnt.x) * tan(alp);
		dlta.y = tan(alp);
	}
	else {
		A.x = (int)pnt.x - 0.00001;
		dlta.x = -1;
		A.y = pnt.y + (pnt.x - A.x) * tan(alp);
		dlta.y = tan(alp);
	} // good

	while (A.x >= 0 && A.x < map->w) {
		if (A.y >= 0 && A.y < map->h)
			if (map->box[(int)A.y][(int)A.x] == 1) // if box
				break ;
			else {
				A.x += dlta.x;
				A.y += dlta.y;
			}
		else
			break ;
	}
	ver = sqrt(pow(pnt.x - A.x, 2) + pow(pnt.y - A.y, 2));

	//return less value
	if (hor < ver)
		return hor;
	else
		return ver;
}