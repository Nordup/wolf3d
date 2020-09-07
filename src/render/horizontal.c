#include "render.h"

t_rcasting	horizontal(t_map *map, t_pnt pnt, float alp)
{
	t_pnt	A;
	t_pnt	dlta;
	int		cardinal_point;
	int		type;

	type = 0;
	if (alp < PI)
	{
		A.y = (int)pnt.y + 1;
		dlta.y = 1;
		A.x = pnt.x + (A.y - pnt.y) / tan(alp);
		dlta.x = 1 / tan(alp);
		cardinal_point = North;
	}
	else
	{
		A.y = (int)pnt.y - EPS;
		dlta.y = -1;
		A.x = pnt.x + (A.y - pnt.y) / tan(alp);
		dlta.x = -1 / tan(alp);
		cardinal_point = South;
	}
	if (alp == PI)
	{
		A.y = pnt.y;
		A.x = -1;
	}
	else if (alp == 0)
	{
		A.y = pnt.y;
		A.x = map->w;
	}
	while (A.y >= 0 && A.y < map->h)
	{
		if (A.x >= 0 && A.x < map->w)
		{
			type = map->box[(int)A.y][(int)A.x];
			if (type != 0)
				break ;
			else
				{
				A.y += dlta.y;
				A.x += dlta.x;
			}
		}
		else
			break ;
	}
	return (ret(cardinal_point, A, pnt, type));
}
