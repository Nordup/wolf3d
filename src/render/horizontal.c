/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 10:18:57 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/13 10:18:59 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int			define_horizontal_fields1(t_pnt *a, t_pnt *dlta,
				t_pnt pnt, float alp)
{
	if (alp < PI)
	{
		a->y = (int)pnt.y + 1;
		dlta->y = 1;
		a->x = pnt.x + (a->y - pnt.y) / tan(alp);
		dlta->x = 1 / tan(alp);
		return (North);
	}
	else
	{
		a->y = (int)pnt.y - EPS;
		dlta->y = -1;
		a->x = pnt.x + (a->y - pnt.y) / tan(alp);
		dlta->x = -1 / tan(alp);
		return (South);
	}
}

void		define_horizontal_fields2(t_pnt *a, t_map *map,
				t_pnt pnt, float alp)
{
	if (alp == PI)
	{
		a->y = pnt.y;
		a->x = -1;
	}
	else if (alp == 0)
	{
		a->y = pnt.y;
		a->x = map->w;
	}
}

t_rcasting	horizontal(t_map *map, t_pnt pnt, float alp)
{
	t_pnt	a;
	t_pnt	dlta;
	int		cardinal_point;
	int		type;

	type = 0;
	cardinal_point = define_horizontal_fields1(&a, &dlta, pnt, alp);
	define_horizontal_fields2(&a, map, pnt, alp);
	while (a.y >= 0 && a.y < map->h)
	{
		if (a.x >= 0 && a.x < map->w)
		{
			type = map->box[(int)a.y][(int)a.x];
			if (type != 0)
				break ;
			else
			{
				a.y += dlta.y;
				a.x += dlta.x;
			}
		}
		else
			break ;
	}
	return (ret(cardinal_point, a, pnt, type));
}
