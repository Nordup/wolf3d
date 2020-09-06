/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:25:39 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:25:41 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_up(t_map *map)
{
	t_prsn		*pn;

	pn = &map->prsn;
	update_step(pn);
	if (ray_casting(map, pn->pnt, pn->alp).dis > STEP)
	{
		pn->pnt.x += pn->step.x;
		pn->pnt.y += pn->step.y;
	}
}

void	move_down(t_map *map)
{
	t_prsn		*pn;

	pn = &map->prsn;
	update_step(pn);
	if (ray_casting(map, pn->pnt, in_two_pi(pn->alp + PI)).dis > STEP)
	{
		pn->pnt.x -= pn->step.x;
		pn->pnt.y -= pn->step.y;
	}
}

int		movement(t_map *map, SDL_Event *e)
{
	t_prsn		*pn;
	const Uint8	*state;

	pn = &map->prsn;
	state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_RIGHT])
	{
		pn->alp += PI / 70;
		if (pn->alp >= PI2)
			pn->alp = 0;
	}
	if (state[SDL_SCANCODE_LEFT])
	{
		pn->alp -= PI / 70;
		if (pn->alp < 0)
			pn->alp = PI2 - RD;
	}
	if (state[SDL_SCANCODE_UP])
		move_up(map);
	if (state[SDL_SCANCODE_DOWN])
		move_down(map);
	return (0);
}
