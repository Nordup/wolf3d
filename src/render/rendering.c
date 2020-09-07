/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:28:43 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:28:47 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float	in_two_pi(float alp)
{
	if (alp > PI2)
		alp = alp - PI2;
	else if (alp < 0)
		alp = alp + PI2;
	return (alp);
}

int		rendering(Uint32 *img, t_wrld *wrld, t_map *map)
{
	int			i;
	float		alp;
	t_rcasting	rcast;

	alp = map->prsn.alp - (FOV / 2) * RD;
	i = 0;
	while (i < WIN_W)
	{
		rcast = ray_casting(map, map->prsn.pnt, in_two_pi(alp));
		rcast.dis *= cos(in_two_pi(map->prsn.alp - alp));
		wrld->wall->size = WALL_SIZE / rcast.dis;
		set_wall_texture(wrld, rcast);
		if (wrld->wall->size >= WIN_H)
			wrld->wall->size = WIN_H - 1;
		wall_draw(img, wrld->wall, i);
		alp += (FOV * RD) / WIN_W;
		i++;
	}
	return (0);
}
