/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:25:34 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:25:36 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define READ_BUFF 100

void	print_map_list(t_wrld *world)
{
	t_map	*tmp;

	tmp = world->map;
	ft_putendl("Choose one of:");
	while (1)
	{
		ft_putstr("\t");
		ft_putendl(tmp->name);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	ft_putstr("Your choice is: ");
}

t_map	*change_map(t_wrld *world, t_map *map)
{
	t_map	*tmp;
	char	line[READ_BUFF];

	print_map_list(world);
	read(0, &line, READ_BUFF);
	tmp = world->map;
	while (1)
	{
		if (ft_strnequ(tmp->name, line, ft_strlen(tmp->name)))
		{
			ft_putstr("Changed to ");
			ft_putendl(tmp->name);
			ft_putendl("");
			return (tmp);
		}
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	ft_putstr("Cannot find\n\n");
	return (map);
}

void	present_picture(t_sdl *sdl)
{
	SDL_UpdateTexture(sdl->tex, NULL, sdl->image, sizeof(Uint32) * WIN_W);
	SDL_RenderClear(sdl->ren);
	SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL);
	SDL_RenderPresent(sdl->ren);
}

int		game(t_sdl *sdl, t_wrld *world)
{
	SDL_Event	e;
	t_bool		quit;
	t_map		*map;

	quit = FALSE;
	map = world->map;
	while (!quit)
	{
		rendering(sdl->image, world, map);
		present_picture(sdl);
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = TRUE;
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
				quit = TRUE;
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_m)
				map = change_map(world, map);
			else
				movement(map, &e);
		}
	}
	return (0);
}
