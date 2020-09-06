/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:25:25 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:32:11 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_world(t_wrld *world)
{
	if (world->map == NULL)
		return (1);
	return (0);
}

int		main(void)
{
	t_sdl	*sdl;
	t_wrld	*world;

	ft_putendl("Initializing...");
	sdl = init_sdl();
	world = init_world();
	if (check_world(world) != 0)
		return (-1);
	ft_putendl("Enjoying the game...");
	game(sdl, world);
	ft_putendl("Cleaning...");
	free_world(world);
	quit_sdl(sdl);
	return (0);
}
