/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:28:32 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:28:37 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float		dis(t_pnt a, t_pnt b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

t_rcasting	ret(int cardinal_point, t_pnt cast_pnt, t_pnt per_pnt, int type)
{
	t_rcasting	ret;

	ret.dis = dis(cast_pnt, per_pnt);
	ret.cardinal_point = cardinal_point;
	ret.type = type;
	ret.cast_pnt = cast_pnt;
	return (ret);
}

t_rcasting	ray_casting(t_map *map, t_pnt pnt, float alp)
{
	t_rcasting hor;
	t_rcasting ver;

	hor = horizontal(map, pnt, alp);
	ver = vertical(map, pnt, alp);
	return ((hor.dis < ver.dis) ? hor : ver);
}
