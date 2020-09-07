#include "render.h"

t_rcasting	vertical(t_map *map, t_pnt pnt, float alp)
{
	t_pnt	A;
	t_pnt	dlta;
	int		cardinal_point;
	int		type;

	type = 0;
	if (alp < PI_2 || alp > PI3_2)
	{
		A.x = (int)pnt.x + 1;
		dlta.x = 1;
		A.y = pnt.y + (A.x - pnt.x) * tan(alp);
		dlta.y = tan(alp);
		cardinal_point = West;
	}
	else
	{
		A.x = (int)pnt.x - EPS;
		dlta.x = -1;
		A.y = pnt.y + (A.x - pnt.x) * tan(alp);
		dlta.y = -tan(alp);
		cardinal_point = East;
	}
	if (alp == PI_2)
	{
		A.y = map->h;
		A.x = pnt.x;
	}
	else if (alp == PI3_2)
	{
		A.y = -1;
		A.x = pnt.x;
	}
	while (A.x >= 0 && A.x < map->w)
	{
		if (A.y >= 0 && A.y < map->h)
		{
			type = map->box[(int)A.y][(int)A.x];
			if (type != 0)
				break ;
			else
			{
				A.x += dlta.x;
				A.y += dlta.y;
			}
		}
		else
			break ;
	}
	return (ret(cardinal_point, A, pnt, type));
}
