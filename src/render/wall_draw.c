/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:29:00 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:29:04 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		wall_draw(Uint32 *img, t_wall *wall, int column)
{
	int		sky_size;
	int		wall_size;
	int		y;

	sky_size = (WIN_H - wall->size) / 2;
	wall_size = wall->size;
	y = 0;
	// fill sky
	while (y < sky_size)
	{
		img[y * WIN_W + column] = BLUE;
		y++;
	}
	// fill wall
	while (y < WIN_H && wall_size > 0)
	{
		wall_size--;
		img[y * WIN_W + column] = wall->tex[wall_size];
		y++;
	}
	// fill floor
	while (y < WIN_H)
	{
		img[y * WIN_W + column] = FLOOR;
		y++;
	}
	return (0);
}
