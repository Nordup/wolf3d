/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 10:19:34 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/13 10:19:37 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int			define_vertical_fields1(t_pnt *a, t_pnt *dlta, t_pnt pnt, float alp)
{
	if (alp < PI_2 || alp > PI3_2)
	{
		a->x = (int)pnt.x + 1;
		dlta->x = 1;
		a->y = pnt.y + (a->x - pnt.x) * tan(alp);
		dlta->y = tan(alp);
		return (West);
	}
	else
	{
		a->x = (int)pnt.x - EPS;
		dlta->x = -1;
		a->y = pnt.y + (a->x - pnt.x) * tan(alp);
		dlta->y = -tan(alp);
		return (East);
	}
}

void		define_vertical_fields2(t_pnt *a, t_map *map, t_pnt pnt, float alp)
{
	if (alp == PI_2)
	{
		a->y = map->h;
		a->x = pnt.x;
	}
	else if (alp == PI3_2)
	{
		a->y = -1;
		a->x = pnt.x;
	}
}

t_rcasting	vertical(t_map *map, t_pnt pnt, float alp)
{
	t_pnt	a;
	t_pnt	dlta;
	int		cardinal_point;
	int		type;

	type = 0;
	cardinal_point = define_vertical_fields1(&a, &dlta, pnt, alp);
	define_vertical_fields2(&a, map, pnt, alp);
	while (a.x >= 0 && a.x < map->w)
	{
		if (a.y >= 0 && a.y < map->h)
		{
			type = map->box[(int)a.y][(int)a.x];
			if (type != 0)
				break ;
			else
			{
				a.x += dlta.x;
				a.y += dlta.y;
			}
		}
		else
			break ;
	}
	return (ret(cardinal_point, a, pnt, type));
}
